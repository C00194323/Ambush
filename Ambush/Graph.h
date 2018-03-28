#ifndef GRAPH_H
#define GRAPH_H

#include <list>
#include <queue>
#include <vector>
#include <limits>
#include "NodeSearchCostComparer.h"

using namespace std;

template <class NodeType, class ArcType> class GraphArc;
template <class NodeType, class ArcType> class GraphNode;

// ----------------------------------------------------------------
//  Name:           Graph
//  Description:    This is the graph class, it contains all the
//                  nodes.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
class Graph {
private:

    // typedef the classes to make our lives easier.
    typedef GraphArc<NodeType, ArcType> Arc;
    typedef GraphNode<NodeType, ArcType> Node;

// ----------------------------------------------------------------
//  Description:    A container of all the nodes in the graph.
// ----------------------------------------------------------------

	std::vector<Node *> m_nodes;


public:           
    // Constructor and destructor functions
    Graph( int size );
    ~Graph();

    // Accessors
    Node * nodeIndex(int index) const {
		return m_nodes.at(index);
    }

    // Public member functions.
    bool addNode( NodeType data, int index );
    void removeNode( int index );
    bool addArc( int from, int to, ArcType weight );	
    void removeArc( int from, int to );
    Arc* getArc( int from, int to );        
    void clearMarks();
    void depthFirst( Node* pNode, void (*pProcess)(Node*) );
    void breadthFirst( Node* pNode, void (*pProcess)(Node*) );
	void adaptedbreadthFirst(Node* pNode, void(*pProcess)(Node*),Node* targetNode);
	void ucs(Node* pStart, Node* pDest, void(*pVisitFunc)(Node*), std::vector<Node *>& path);
	void aStar(Node* pStart, Node* pDest, void(*pProcess)(Node*),std::vector<Node *>& path);
};

// ----------------------------------------------------------------
//  Name:           Graph
//  Description:    Constructor, this constructs an empty graph
//  Arguments:      The maximum number of nodes.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
Graph<NodeType, ArcType>::Graph( int maxNodes ) : m_nodes( maxNodes, nullptr) 
{  
}

// ----------------------------------------------------------------
//  Name:           ~Graph
//  Description:    destructor, This deletes every node
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
Graph<NodeType, ArcType>::~Graph() {
   for( int index = 0; index < m_nodes.size(); index++ ) {
        if( m_nodes[index] != nullptr ) {
			delete m_nodes.at(index);
        }
   }
}

// ----------------------------------------------------------------
//  Name:           addNode
//  Description:    This adds a node at a given index in the graph.
//  Arguments:      The first parameter is the data to store in the node.
//                  The second parameter is the index to store the node.
//  Return Value:   true if successful
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
bool Graph<NodeType, ArcType>::addNode( NodeType data, int index ) {
   bool nodeNotPresent = false;
   // find out if a node does not exist at that index.
   if ( nullptr == m_nodes.at(index) ) {
      nodeNotPresent = true;
      // create a new node, put the data in it, and unmark it.
	  m_nodes.at(index) = new Node;
	  m_nodes.at(index)->setData(data);
	  m_nodes.at(index)->setMarked(false);
    }
        
    return nodeNotPresent;
}

// ----------------------------------------------------------------
//  Name:           removeNode
//  Description:    This removes a node from the graph
//  Arguments:      The index of the node to return.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::removeNode( int index ) {
     // Only proceed if node does exist.
     if( nullptr != m_nodes.at(index) ) {
         // now find every arc that points to the node that
         // is being removed and remove it.        
         Arc* arc;

         // loop through every node
         for( int node = 0; node < m_nodes.size(); node++ ) {
              // if the node is valid...
              if( nullptr != m_nodes.at(node) ) {
                  // see if the node has an arc pointing to the current node.
                  arc = m_nodes.at(node)->getArc(m_nodes.at(index) );
              }
              // if it has an arc pointing to the current node, then
              // remove the arc.
              if( arc != 0 ) {
                  removeArc( node, index );
              }
         }
        

        // now that every arc pointing to the current node has been removed,
        // the node can be deleted.
        delete m_nodes.at(index);
		m_nodes.at(index) = nullptr;       
    }
}

// ----------------------------------------------------------------
//  Name:           addArd
//  Description:    Adds an arc from the first index to the 
//                  second index with the specified weight.
//  Arguments:      The first argument is the originating node index
//                  The second argument is the ending node index
//                  The third argument is the weight of the arc
//  Return Value:   true on success.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
bool Graph<NodeType, ArcType>::addArc( int from, int to, ArcType weight ) {
     bool proceed = true; 
     // make sure both nodes exist.
     if( nullptr == m_nodes.at(from) || nullptr == m_nodes.at(to) ) {
         proceed = false;
     }
        
     // if an arc already exists we should not proceed
     if( m_nodes.at(from)->getArc( m_nodes.at(to) ) != nullptr ) {
         proceed = false;
     }

     if (proceed == true) {
        // add the arc to the "from" node.
		 m_nodes.at(from)->addArc(m_nodes.at(to), weight );
     }
        
     return proceed;
}


// ----------------------------------------------------------------
//  Name:           removeArc
//  Description:    This removes the arc from the first index to the second index
//  Arguments:      The first parameter is the originating node index.
//                  The second parameter is the ending node index.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::removeArc( int from, int to ) {
     // Make sure that the node exists before trying to remove
     // an arc from it.
     bool nodeExists = true;
     if( nullptr == m_nodes.at(from) || nullptr == m_nodes.at(to) ) {
         nodeExists = false;
     }

     if (nodeExists == true) {
        // remove the arc.
		 m_nodes.at(from)->removeArc(m_nodes.at(to) );
     }
}


// ----------------------------------------------------------------
//  Name:           getArc
//  Description:    Gets a pointer to an arc from the first index
//                  to the second index.
//  Arguments:      The first parameter is the originating node index.
//                  The second parameter is the ending node index.
//  Return Value:   pointer to the arc, or 0 if it doesn't exist.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
GraphArc<NodeType, ArcType>* Graph<NodeType, ArcType>::getArc( int from, int to ) {
     Arc* arc = 0;
     // make sure the to and from nodes exist
     if( nullptr != m_nodes.at(from) && nullptr != m_nodes.at(to) ) {
         arc = m_nodes.at(from)->getArc(m_nodes.at(to) );
     }
                
     return arc;
}


// ----------------------------------------------------------------
//  Name:           clearMarks
//  Description:    This clears every mark on every node.
//  Arguments:      None.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::clearMarks() {
     for( int index = 0; index < m_nodes.size(); index++ ) {
          if( nullptr != m_nodes.at(index) ) {
			  m_nodes.at(index)->setMarked(false);
          }
     }
}


// ----------------------------------------------------------------
//  Name:           depthFirst
//  Description:    Performs a depth-first traversal on the specified 
//                  node.
//  Arguments:      The first argument is the starting node
//                  The second argument is the processing function.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::depthFirst( Node* node, void (*process)(Node*) ) {
     if( nullptr != node ) {
           // process the current node and mark it
           pProcess( node );
           node->setMarked(true);

           // go through each connecting node
           auto iter = node->arcList().begin();
           auto endIter = node->arcList().end();
        
		   for( ; iter != endIter; ++iter) {
			    // process the linked node if it isn't already marked.
                if ( (*iter).node()->marked() == false ) {
                   depthFirst( (*iter).node(), process);
                }            
           }
     }
}


// ----------------------------------------------------------------
//  Name:           breadthFirst
//  Description:    Performs a depth-first traversal the starting node
//                  specified as an input parameter.
//  Arguments:      The first parameter is the starting node
//                  The second parameter is the processing function.
//  Return Value:   None.
// ----------------------------------------------------------------
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::breadthFirst( Node* node, void (*process)(Node*) ) {
   if( nullptr != node ) {
	  queue<Node*> nodeQueue;        
	  // place the first node on the queue, and mark it.
      nodeQueue.push( node );
      node->setMarked(true);

      // loop through the queue while there are nodes in it.
      while( nodeQueue.size() != 0 ) {
         // process the node at the front of the queue.
         process( nodeQueue.front() );

         // add all of the child nodes that have not been 
         // marked into the queue
         auto iter = nodeQueue.front()->arcList().begin();
         auto endIter = nodeQueue.front()->arcList().end();
         
		 for( ; iter != endIter; iter++ ) {
              if ( (*iter).node()->marked() == false) {
				 // mark the node and add it to the queue.
                 (*iter).node()->setMarked(true);
                 nodeQueue.push( (*iter).node() );
              }
         }

         // dequeue the current node.
         nodeQueue.pop();
      }
   }  
}

// Adapted breadth First
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::adaptedbreadthFirst(Node* node, void(*process)(Node*), Node* targetNode) {
	if (nullptr != node) {
		queue<Node*> nodeQueue;
		// place the first node on the queue, and mark it.
		nodeQueue.push(node);
		node->setMarked(true);

		// loop through the queue while there are nodes in it.
		while (nodeQueue.size() != 0) {
			// process the node at the front of the queue.
			process(nodeQueue.front());

			// add all of the child nodes that have not been 
			// marked into the queue
			auto iter = nodeQueue.front()->arcList().begin();
			auto endIter = nodeQueue.front()->arcList().end();

			for (; iter != endIter; iter++) {
				if ((*iter).node()->marked() == false) {
					// mark the node and add it to the queue.
					(*iter).node()->setMarked(true);
					(*iter).node()->setPrevious(nodeQueue.front());
					nodeQueue.push((*iter).node());
				}
				if ((*iter).node() == targetNode)
				{
					Node* currentNode = (*iter).node();
					while (currentNode != node) {
						process(currentNode);
						currentNode = currentNode->previous();
					}
					process(currentNode);
					return;
				}
			}
			

			// dequeue the current node.
			nodeQueue.pop();
		}
	}
}
template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::ucs(Node* pStart, Node* pDest, void(*pVisitFunc)(Node*), std::vector<Node *>& path)
{
	int infin = std::numeric_limits<int>::max() - 10000;
	std::priority_queue < Node *, std::vector<Node *>, NodeSearchCostComparer > pq;


	
	for (int i = 0; i < m_nodes.size(); i++)
	{
		NodeType & data = m_nodes.at(i)->data();
		data.second = infin;
	}

	NodeType & data = pStart->data();
	data.second = 0;

	pq.push(pStart);
	pStart->setMarked(true);
	while ((!(pq.empty())) && (pq.top() != pDest))
	{
		auto & arclist = pq.top()->arcList();
		for (auto arc : arclist)
		{
			Node * c = arc.node();
			if ( c != pq.top()->previous() )
			{
				int estDist= arc.weight() + (pq.top()->data().second.first*0.9);
				int distC = arc.weight() + (pq.top()->data().second.second);
				if (distC < c->data().second)
				{
					c->data().second = distC;
					c->setPrevious(pq.top());
				}
				if (c->marked() != true)
				{
					pq.push(c);
					c->setMarked(true);
				}
			}
		}
		
		pq.pop();
	}
}

template<class NodeType, class ArcType>
void Graph<NodeType, ArcType>::aStar(Node* pStart, Node* pDest, void(*pProcess)(Node*), std::vector<Node *>& path)
{
	int infin = std::numeric_limits<int>::max() - 10000;
	std::priority_queue < Node *, std::vector<Node *>, NodeSearchCostComparer > pq;



	for (int i = 0; i < m_nodes.size(); i++)
	{
		NodeType & data = m_nodes.at(i)->data();
		data.second.second = infin;
	}

	NodeType & data = pStart->data();
	data.second.second = 0;

	pq.push(pStart);
	pStart->setMarked(true);
	while ((!(pq.empty())) && (pq.top() != pDest))
	{
		auto & arclist = pq.top()->arcList();
		for (auto arc : arclist)
		{
			Node * c = arc.node();
			if (c != pq.top()->previous())
			{
				
				int distC = arc.weight() + (pq.top()->data().second.second);
				int estDist = distC * 0.9;
				if (distC < c->data().second.second)
				{
					c->data().second.first = estDist;
					c->data().second.second = distC;
					c->setPrevious(pq.top());
				}
				if (c->marked() != true)
				{
					pq.push(c);
					c->setMarked(true);
				}
			}
		}

		pq.pop();
	}
}



#include "GraphNode.h"
#include "GraphArc.h"


#endif
