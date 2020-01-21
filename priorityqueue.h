#ifndef __PRIORITYQUEUE_H__
#define __PRIORITYQUEUE_H__


// priority queue class
// this class represents a queue structure
class PriorityQueue
{
    public:

    //========================================================================//
    // Class members
    //========================================================================//

    //implement queue using vector of vertices
    vector<Vertex> VertexQueue;



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
    void InsertQueueElement(PriorityQueue &Copy_PriorityQueue, Vertex &Copy_QueueVertex);

    //========================================================================//
    // Remove Top Queue Element
    //========================================================================//
    // Prototype   : void RemoveTopQueueElement(PriorityQueue &Copy_PriorityQueue);
    // Description : a Method to remove top queue element
    // Arguments   : Priority Queue
    // Return      : void
    void RemoveTopQueueElement(PriorityQueue &Copy_PriorityQueue);

    //========================================================================//
    // Top Queue Element
    //========================================================================//
    // Prototype   : Vertex TopQueueElement(PriorityQueue &Copy_PriorityQueue, &Vertex Copy_QueueVertex);
    // Description : a Method to return Top queue Vertex
    // Arguments   : Priority Queue
    // Return      : Vertex top queue vertex
    Vertex TopQueueElement(PriorityQueue &Copy_PriorityQueue);

    //========================================================================//
    // Queue Size
    //========================================================================//
    // Prototype   : int QueueSize(PriorityQueue &Copy_PriorityQueue);
    // Description : a Method to return queue size
    // Arguments   : Priority Queue
    // Return      : int queue size
    int QueueSize(PriorityQueue &Copy_PriorityQueue);


};//end of priority queue class


#endif // __PRIORITYQUEUE_H__
