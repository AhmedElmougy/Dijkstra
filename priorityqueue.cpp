#include "vertex.h"
#include "priorityqueue.h"
#include <vector>

using namespace std;

    //========================================================================//
    // Class Methods
    //========================================================================//

    //========================================================================//
    // Insert Queue Element
    //========================================================================//
    // Prototype   : void InsertQueueElement(PriorityQueue &Copy_PriorityQueue, &Vertex Copy_QueueVertex);
    // Description : a Method to insert queue element
    // Arguments   : Priority Queue ,Queue Vertex
    // Return      : void
    void PriorityQueue::InsertQueueElement(PriorityQueue &Copy_PriorityQueue, Vertex &Copy_QueueVertex)
    {
        //variable that flag if the element already exist in queue
        int ElementDoesNotExist = true;

        //loop queue
        for (int i = 0 ; i < Copy_PriorityQueue.VertexQueue.size() ; i++)
        {
            //check if element already exists
            if(Copy_QueueVertex.VertexName == Copy_PriorityQueue.VertexQueue[i].VertexName)
            {
                //flag element already exists in queue
                ElementDoesNotExist = false;
                //break loop
                break;

            }//end of if statement

        }//end of queue loop

        //if element does not exits in queue
        if(ElementDoesNotExist)
        {
            //add element to queue
            Copy_PriorityQueue.VertexQueue.push_back(Copy_QueueVertex);

        }//end of if statement


    }// end of InsertQueueElement() Method


    //========================================================================//
    // Remove Top Queue Element
    //========================================================================//
    // Prototype   : void RemoveTopQueueElement(PriorityQueue &Copy_PriorityQueue);
    // Description : a Method to remove top queue element
    // Arguments   : Priority Queue
    // Return      : void
    void PriorityQueue::RemoveTopQueueElement(PriorityQueue &Copy_PriorityQueue)
    {
        //remove top of queue element
        Copy_PriorityQueue.VertexQueue.erase(Copy_PriorityQueue.VertexQueue.begin());

    }// end of RemoveTopQueueElement() Method




    //========================================================================//
    // Top Queue Element
    //========================================================================//
    // Prototype   : Vertex TopQueueElement(PriorityQueue &Copy_PriorityQueue, &Vertex Copy_QueueVertex);
    // Description : a Method to return Top queue Vertex
    // Arguments   : Priority Queue
    // Return      : Vertex top queue vertex
    Vertex PriorityQueue::TopQueueElement(PriorityQueue &Copy_PriorityQueue)
    {
        //return value of top of queue vertex
        return Copy_PriorityQueue.VertexQueue[0];

    }// end of TopQueueElement() Method

    //========================================================================//
    // Queue Size
    //========================================================================//
    // Prototype   : int QueueSize(PriorityQueue &Copy_PriorityQueue);
    // Description : a Method to return queue size
    // Arguments   : Priority Queue
    // Return      : int queue size
    int PriorityQueue::QueueSize(PriorityQueue &Copy_PriorityQueue)
    {
        //return the size of queue
        return Copy_PriorityQueue.VertexQueue.size();

    }// end of QueueSize() Method


