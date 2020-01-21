#include <iostream>
#include <vector>
#include "vertex.h"
#include "graph.h"
#include "priorityqueue.h"
#include "dijkstra.h"


using namespace std;








//========================================================================//
// class constructors
//========================================================================//
ShortestPath::ShortestPath(Graph &Copy_Graph)
{
    //resize path vector
    PathVector.resize(Copy_Graph.VerticesNumber);

    //variable that holds current vertex index thats is being modified
    int CurrentNeighbourVertexPosition;
    //variable that holds new calculated vertex value
    int NewVertexValue;
    //variable that flag if an element exists in a queue or not
    bool ElementDoesNotExist ;

    // variable that stores current vertex that the algorithm is working on
    Vertex CurrentVertex;

    // Visited vertices queue
    PriorityQueue VisitedQueue;
    // Unvisited Vertices queue
    PriorityQueue UnvisitedQueue;
    // Neighbors vertices vector
    vector<Vertex> CurrentVertexNeighborsVector;

    //========================================================================//
    // Algorithm steps
    //========================================================================//

    //========================================================================//
    // 01 - Initialize graph vertices values
    //========================================================================//

    //initialize source vertex value with 0
    Copy_Graph.SetVertexValue(Copy_Graph,Copy_Graph.GraphVertexArrayList[0][0],0);

        //initialize vertices values
        //loop Graph Vertices and initialize their values with infinity (very high value)
        for(int i = 1 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            Copy_Graph.SetVertexValue(Copy_Graph,Copy_Graph.GraphVertexArrayList[i][0],65000);
        }


        //========================================================================//
        // 02 - Set starting point for algorithm
        //========================================================================//
        //insert starting vertex(source vertex)
        UnvisitedQueue.InsertQueueElement(UnvisitedQueue,Copy_Graph.GraphVertexArrayList[0][0]);

        //========================================================================//
        // 03 - loop until all graph vertices are visited
        //========================================================================//
        //while unvisited queue is not empty
        while( UnvisitedQueue.QueueSize(UnvisitedQueue)  != 0 )
        {

            //========================================================================//
            // 04 - Update current values
            //========================================================================//
            //make top vertex in unvisited queue is the current vertex
            CurrentVertex = UnvisitedQueue.TopQueueElement(UnvisitedQueue);

            //get current vertex neighbors vector
            CurrentVertexNeighborsVector = Copy_Graph.GetNeighborVertices(Copy_Graph,CurrentVertex);



            //========================================================================//
            // 05 - loop current vertex neighbors
            //========================================================================//
            //loop Current Vertex Neighbors Vector
            for(int i = 0 ; i < CurrentVertexNeighborsVector.size() ; i++)
            {
                //initialize flag with true
                ElementDoesNotExist = true;

                //update current connected vertex position in graph vector
                for(int j = 0; j < Copy_Graph.GraphVertexArrayList.size() ; j++)
                {
                    //if neighbors vector is found
                    if(Copy_Graph.GraphVertexArrayList[j][0].VertexName == CurrentVertexNeighborsVector[i].ConnectedVertexName)
                    {
                        //update current neighbor vertex position
                        CurrentNeighbourVertexPosition = j;
                        break;

                    }//end of if statement
                }//end of for loop

                //========================================================================//
                // 06 - add vertex to unvisited queue
                //========================================================================//
                //loop visited queue
                for (int j = 0 ; j < VisitedQueue.QueueSize(VisitedQueue) ; j++)
                {
                    //check if already visited
                    if(VisitedQueue.VertexQueue[j].VertexName ==  Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0].VertexName)
                    {
                        //if already visited flag it as exists in queue
                        ElementDoesNotExist = false;
                        break;

                    }//end of if statement

                }//end of for loop

                //if does not exist in queue
                if(ElementDoesNotExist)
                {
                    //insert current neighbor vertex
                    UnvisitedQueue.InsertQueueElement(UnvisitedQueue,Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0]);

                }//end of if statement

                //==========================================================================================//
                // 07 - Update current neighbor vertex value and previous vertex if shorter rout was found
                //==========================================================================================//
                //calculate new vertex value
                NewVertexValue =  Copy_Graph.GetVertexValue(Copy_Graph,CurrentVertex) + CurrentVertexNeighborsVector[i].ConnectedVertexWeight;

                //update Neighbors vertex value if new vertex value is smaller than current vertex value
                if( NewVertexValue < Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0].VertexValue )
                {
                    //update current neighbor vertex value
                    Copy_Graph.SetVertexValue(Copy_Graph,Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0],NewVertexValue);
                    //update current neighbor previous vertex name
                    Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0].PreviousVertex = CurrentVertex.VertexName;

                }//end of neighbor vertex check

            }//end of Current Vertex Neighbors Vector loop


            //========================================================================//
            // 08 - Move to new vertex to explore
            //========================================================================//

            //add current vertex to visited queue
            VisitedQueue.InsertQueueElement(VisitedQueue,CurrentVertex);
            //remove current vertex from unvisited queue and add it to visited queue
            UnvisitedQueue.RemoveTopQueueElement(UnvisitedQueue);



        }//end of while loop


        Vertex PathVertex;


        //loop visited vertices
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            PathVertex = Copy_Graph.GraphVertexArrayList[i][0];
            //update path vector with path vertices along with distances
            do
            {
                //insert path vertex to path vector
                PathVector[i].insert(PathVector[i].begin(),PathVertex) ;
                //update previous vertex value and path vertex
                for (int j = 0 ; j < Copy_Graph.GraphVertexArrayList.size() ; j++)
                {
                    if( Copy_Graph.GraphVertexArrayList[j][0].VertexName == PathVertex.PreviousVertex)
                    {
                        PathVertex = Copy_Graph.GraphVertexArrayList[j][0];
                        break;

                    }//end of if

                }//end of for

            }while( PathVertex.PreviousVertex != Copy_Graph.GraphVertexArrayList[0][0].PreviousVertex);
            //end of while

        }//end of for

}//end of ShortestPath constructor


ShortestPath::ShortestPath(Graph &Copy_Graph, Vertex &Copy_Vertex)
{
    int SourceVertexIndex;
    //resize path vector
    PathVector.resize(Copy_Graph.VerticesNumber);

    //variable that holds current vertex index thats is being modified
    int CurrentNeighbourVertexPosition;
    //variable that holds new calculated vertex value
    int NewVertexValue;
    //variable that flag if an element exists in a queue or not
    bool ElementDoesNotExist ;

    // variable that stores current vertex that the algorithm is working on
    Vertex CurrentVertex;

    // Visited vertices queue
    PriorityQueue VisitedQueue;
    // Unvisited Vertices queue
    PriorityQueue UnvisitedQueue;
    // Neighbors vertices vector
    vector<Vertex> CurrentVertexNeighborsVector;

    //========================================================================//
    // Algorithm steps
    //========================================================================//

    //========================================================================//
    // 01 - Initialize graph vertices values
    //========================================================================//

    //set source vertex
    SourceVertexIndex = Copy_Graph.GetVertexPosition(Copy_Graph,Copy_Vertex);



    //initialize vertices values
    //loop Graph Vertices and initialize their values with infinity (very high value)
    for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
    {
        Copy_Graph.SetVertexValue(Copy_Graph,Copy_Graph.GraphVertexArrayList[i][0],65000);
    }


    //initialize source vertex value with 0
    Copy_Graph.SetVertexValue(Copy_Graph,Copy_Graph.GraphVertexArrayList[SourceVertexIndex][0],0);

    //========================================================================//
    // 02 - Set starting point for algorithm
    //========================================================================//
    //insert starting vertex(source vertex)
    UnvisitedQueue.InsertQueueElement(UnvisitedQueue,Copy_Graph.GraphVertexArrayList[SourceVertexIndex][0]);

    //========================================================================//
    // 03 - loop until all graph vertices are visited
    //========================================================================//
    //while unvisited queue is not empty
    while( UnvisitedQueue.QueueSize(UnvisitedQueue)  != 0 )
    {

        //========================================================================//
        // 04 - Update current values
        //========================================================================//
        //make top vertex in unvisited queue is the current vertex
        CurrentVertex = UnvisitedQueue.TopQueueElement(UnvisitedQueue);

        //get current vertex neighbors vector
        CurrentVertexNeighborsVector = Copy_Graph.GetNeighborVertices(Copy_Graph,CurrentVertex);



        //========================================================================//
        // 05 - loop current vertex neighbors
        //========================================================================//
        //loop Current Vertex Neighbors Vector
        for(int i = 0 ; i < CurrentVertexNeighborsVector.size() ; i++)
        {
            //initialize flag with true
            ElementDoesNotExist = true;

            //update current connected vertex position in graph vector
            for(int j = 0; j < Copy_Graph.GraphVertexArrayList.size() ; j++)
            {
                //if neighbors vector is found
                if(Copy_Graph.GraphVertexArrayList[j][0].VertexName == CurrentVertexNeighborsVector[i].ConnectedVertexName)
                {
                    //update current neighbor vertex position
                    CurrentNeighbourVertexPosition = j;
                    break;

                }//end of if statement
            }//end of for loop

            //========================================================================//
            // 06 - add vertex to unvisited queue
            //========================================================================//
            //loop visited queue
            for (int j = 0 ; j < VisitedQueue.QueueSize(VisitedQueue) ; j++)
            {
                //check if already visited
                if(VisitedQueue.VertexQueue[j].VertexName ==  Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0].VertexName)
                {
                    //if already visited flag it as exists in queue
                    ElementDoesNotExist = false;
                    break;

                }//end of if statement

            }//end of for loop

            //if does not exist in queue
            if(ElementDoesNotExist)
            {
                //insert current neighbor vertex
                UnvisitedQueue.InsertQueueElement(UnvisitedQueue,Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0]);

            }//end of if statement

            //==========================================================================================//
            // 07 - Update current neighbor vertex value and previous vertex if shorter rout was found
            //==========================================================================================//
            //calculate new vertex value
            NewVertexValue =  Copy_Graph.GetVertexValue(Copy_Graph,CurrentVertex) + CurrentVertexNeighborsVector[i].ConnectedVertexWeight;

            //update Neighbors vertex value if new vertex value is smaller than current vertex value
            if( NewVertexValue < Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0].VertexValue )
            {
                //update current neighbor vertex value
                Copy_Graph.SetVertexValue(Copy_Graph,Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0],NewVertexValue);
                //update current neighbor previous vertex name
                Copy_Graph.GraphVertexArrayList[CurrentNeighbourVertexPosition][0].PreviousVertex = CurrentVertex.VertexName;

            }//end of neighbor vertex check

        }//end of Current Vertex Neighbors Vector loop


        //========================================================================//
        // 08 - Move to new vertex to explore
        //========================================================================//

        //add current vertex to visited queue
        VisitedQueue.InsertQueueElement(VisitedQueue,CurrentVertex);
        //remove current vertex from unvisited queue and add it to visited queue
        UnvisitedQueue.RemoveTopQueueElement(UnvisitedQueue);



    }//end of while loop


    Vertex PathVertex;


    //loop visited vertices
    for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
    {
        PathVertex = Copy_Graph.GraphVertexArrayList[i][0];
        //update path vector with path vertices along with distances
        do
        {
            //insert path vertex to path vector
            PathVector[i].insert(PathVector[i].begin(),PathVertex) ;
            //update previous vertex value and path vertex
            for (int j = 0 ; j < Copy_Graph.GraphVertexArrayList.size() ; j++)
            {
                if( Copy_Graph.GraphVertexArrayList[j][0].VertexName == PathVertex.PreviousVertex)
                {
                    PathVertex = Copy_Graph.GraphVertexArrayList[j][0];
                    break;

                }//end of if

            }//end of for

        }while( PathVertex.PreviousVertex != Copy_Graph.GraphVertexArrayList[SourceVertexIndex][0].PreviousVertex);
            //end of while

    }//end of for

}//end of ShortestPath constructor





    //========================================================================//
    // Vertices List
    //========================================================================//
    // Prototype   : vector<Vertex> VerticesList(Graph &Copy_Graph);
    // Description : a Method to return Vertices List in graph
    // Arguments   : Graph
    // Return      : Vertices list of type vector<Vertex>
    vector<Vertex> ShortestPath::VerticesList(Graph &Copy_Graph)
    {
        vector<Vertex> VerticesVector;

        //loop graph vectors
        for(int i =0 ; i< Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            VerticesVector.push_back(Copy_Graph.GraphVertexArrayList[i][0]);

        }//end of vector for loop

        //return graph vertices vector
        return VerticesVector;

    }// end of QueueSize() Method


    //========================================================================//
    // Find Shortest Path between two vertices
    //========================================================================//
    // Prototype   : vector<Vertex> FindShortestPath(ShortestPath &Copy_ShortestPath, Vertex Copy_Vertex1, Vertex Copy_Vertex2);
    // Description : a Method to return vector containing shortest vertices path from vertex1 to vertex2
    // Arguments   : Graph,vertex1,vertex2
    // Return      : shortest path vertices vector of type vector<Vertex>
    vector<Vertex> ShortestPath::FindShortestPath(ShortestPath &Copy_ShortestPath, Vertex &Copy_Vertex)
    {
        vector<Vertex> ShortestPathVector;

        //loop path vector vectors

        for(int i =0 ; i< Copy_ShortestPath.PathVector.size() ; i++)
        {
            //if vertex1 vector found
            if( Copy_ShortestPath.PathVector[i][0].VertexName == Copy_Vertex.VertexName )
            {
                //loop vertices vector
                for(int j =0 ; j< Copy_ShortestPath.PathVector[i].size() ; j++)
                {
                    //copy calculated shortest path vector to local vector to return it
                    ShortestPathVector.push_back(Copy_ShortestPath.PathVector[i][j]);
                }//end of vertices vector loop

            }//end of vertex1 check
            break;

        }//end of vector for loop

        //return shortest path vertices vector
        return ShortestPathVector;

    }// end of FindShortestPath() Method

    //========================================================================//
    // Calculate average path length
    //========================================================================//
    // Prototype   : float CalculateAveragePathLength(ShortestPath &Copy_ShortestPath,Graph &Copy_Graph);
    // Description : a Method to return graph average path length
    // Arguments   : ShortestPath,Graph
    // Return      : float average path length
    float ShortestPath::CalculateAveragePathLength(ShortestPath &Copy_ShortestPath,Graph &Copy_Graph)
    {
        //total path distances
        float PathSum = 0.0;
        //loop path vector
        for(int i =0 ; i< Copy_ShortestPath.PathVector.size() ; i++)
        {
            //accumulate path distance
            PathSum += Copy_ShortestPath.PathVector[i][Copy_ShortestPath.PathVector[i].size()-1].VertexValue;

        }//end of for loop

        //calculate path length average
        Copy_ShortestPath.AveragePathlength = PathSum / Copy_Graph.VerticesNumber;
        //return average
        return Copy_ShortestPath.AveragePathlength;

    }//end of


//output stream of shortest path type
ostream& operator << (ostream &out, const ShortestPath &Copy_ShortestPath)
{
    for(int i =0 ; i< Copy_ShortestPath.PathVector.size() ; i++)
    {
        for (int j = 0 ; j < Copy_ShortestPath.PathVector[i].size() ; j++)
        {
            out << Copy_ShortestPath.PathVector[i][j].PreviousVertex << "-" << Copy_ShortestPath.PathVector[i][j].VertexValue << "->" << Copy_ShortestPath.PathVector[i][j].VertexName << " " ;
        }
        out << endl;
    }
    return out;
}


