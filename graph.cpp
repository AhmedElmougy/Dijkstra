#include <iostream>
#include<cstdlib>
#include<ctime>
#include "vertex.h"
#include "graph.h"
#include <vector>


using namespace std;


    //=================================================//
    //Class constructors
    //=================================================//

    //graph default constructor
    //=================================================//
    Graph::Graph():VerticesNumber(0),EdgesNumber(0),EdgeDensity(20),DistanceRange(10){}


    //graph complete arguments constructor
    //==========================================================================//
    Graph::Graph(int Copy_VerticesNumber, int Copy_EdgeDensity, int Copy_DistanceRange)
    {
        //============================================//
        //initialize class parameters
        //============================================//
        VerticesNumber = Copy_VerticesNumber;
        EdgesNumber    = 0;
        EdgeDensity    = Copy_EdgeDensity;
        DistanceRange  = Copy_DistanceRange;
        //resize list array with new number of vertices
        GraphVertexArrayList.resize(VerticesNumber);
        //============================================//

        //seed rand() function with current time
        srand(time(0));

        //create graph with random vertices edges and distances
        for(int i = 0 ; i < VerticesNumber ; i++)
        {
            for(int j = 0 ; j < VerticesNumber ; j++)
            {
                //density check
                if( ( ( rand() % 100 ) < EdgeDensity ) && ( i != j ) )
                {
                    //generate random distances
                    int weight = (rand() % DistanceRange) + 1;
                    //generate 2 vertices and add them to graph
                    Vertex Vertex1( i+1,j+1,weight ),Vertex2( j+1,i+1,weight );
                    GraphVertexArrayList[i].push_back(Vertex1);
                    GraphVertexArrayList[j].push_back(Vertex2);
                    EdgesNumber++;
                }
            }//end of j for

        }//end of i for

    }//end of graph Vertices Number, EdgeDensity arguments constructor

    //graph Vertices Number argument constructor
    //=================================================//
    Graph::Graph(int Copy_VerticesNumber)
    {
        //============================================//
        //initialize class parameters
        //============================================//
        VerticesNumber = Copy_VerticesNumber;
        EdgesNumber    = 0;
        EdgeDensity    = 20;
        DistanceRange  = 10;
        //resize list array with new number of vertices
        GraphVertexArrayList.resize(VerticesNumber);
        //============================================//

        //seed rand() function with current time
        srand(time(0));

        //create graph with random vertices edges and distances
        for(int i = 0 ; i < VerticesNumber ; i++)
        {
            for(int j = 0 ; j < VerticesNumber ; j++)
            {
                //density check
                if( ( ( rand() % 100 ) < EdgeDensity ) && ( i != j ) )
                {
                    //generate random distances
                    int weight = (rand() % DistanceRange) + 1;
                    //generate 2 vertices and add them to graph
                    Vertex Vertex1( i,j,weight ),Vertex2( j,i,weight );
                    GraphVertexArrayList[i].push_back(Vertex1);
                    GraphVertexArrayList[j].push_back(Vertex2);
                    EdgesNumber++;
                }
            }//end of j for

        }//end of i for

    }//end of graph VerticesNumber argument constructor


    //graph VerticesNumber, EdgeDensity arguments constructor
    //=========================================================//
    Graph::Graph(int Copy_VerticesNumber, int Copy_EdgeDensity)
    {
        //============================================//
        //initialize class parameters
        //============================================//
        VerticesNumber = Copy_VerticesNumber;
        EdgesNumber    = 0;
        EdgeDensity    = Copy_EdgeDensity;
        DistanceRange  = 10;
        //resize list array with new number of vertices
        GraphVertexArrayList.resize(VerticesNumber);
        //============================================//

        //seed rand() function with current time
        srand(time(0));

        //create graph with random vertices edges and distances
        for(int i = 0 ; i < VerticesNumber ; i++)
        {
            for(int j = 0 ; j < VerticesNumber ; j++)
            {
                //t check
                if( ( ( rand() % 100 ) < EdgeDensity ) && ( i != j ) )
                {
                    //generate random distances
                    int weight = (rand() % DistanceRange) + 1 ;
                    //generate 2 vertices and add them to graph
                    Vertex Vertex1( i,j,weight ),Vertex2( j,i,weight );
                    GraphVertexArrayList[i].push_back(Vertex1);
                    GraphVertexArrayList[j].push_back(Vertex2);
                    EdgesNumber++;
                }
            }//end of j for

        }//end of i for

    }//end of graph VerticesNumber, EdgeDensity arguments constructor
    //========================================================================//




    //========================================================================//
    //Class Methods
    //========================================================================//


    //========================================================================//
    // Get vertex position in the Graph Method
    //========================================================================//
    // Prototype   : int GetVertexPosition(Graph &Copy_Graph, Vertex &Copy_Vertex);
    // Description : a Method that returns vertex vector position in the graph
    // Arguments   : Graph,vertex
    // Return      : int vertex position
    int Graph::GetVertexPosition(Graph &Copy_Graph, Vertex &Copy_Vertex)
    {
        //loop Graph to find Vertex vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vector found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex.VertexName )
            {
                //return value of vector index
                return i;
            }
        }//end of for loop
        //if not found return 65000
        return 65000;

    }//end of GetVertexPosition() Method


    //========================================================================//
    // Add Graph Vertex Method
    //========================================================================//
    // Prototype   : void AddVertex(Graph &Copy_Graph, Vertex &Copy_Vertex);
    // Description : a Method that adds a vertex to the graph
    // Arguments   : Graph , Vertex1 , Vertex2
    // Return      : void
    void Graph::AddVertex(Graph &Copy_Graph, Vertex &Copy_Vertex)
    {
        //initialize vertex does not exists flag status
        int VertexDoesNotExist = 1;
        vector<Vertex> VertexVector;
        //loop Vertices list and check if already exists
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++ )
        {
            //if already exists
            if(Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex.VertexName )
            {
               //flag exists and break loop
               VertexDoesNotExist = 0;
               break;
            }
        }//end of for loop

        //if Vertex does not exists
        if(VertexDoesNotExist)
        {
            //add vertex and increment vertices number variable
            Copy_Graph.VerticesNumber++;
            //add vertex to graph
            VertexVector.push_back(Copy_Vertex);
            Copy_Graph.GraphVertexArrayList.push_back(VertexVector);

        }//end of if statement

    }//end of AddVertex() Method


    //========================================================================//
    // Get number of vertices of the Graph Method
    //========================================================================//
    // Prototype   : int GetVeticesNumber(Graph &Copy_Graph);
    // Description : a Method that returns number of vertices in the graph
    // Arguments   : Graph
    // Return      : int vertices number
    int Graph::GetVeticesNumber(Graph &Copy_Graph)
    {
        //return vertices number
        return Copy_Graph.VerticesNumber;
    }

    //========================================================================//
    // Get number of edges of the Graph Method
    //========================================================================//
    // Prototype   : int GetEdgesNumber(Graph &Copy_Graph);
    // Description : a Method that returns number of Edges in the graph
    // Arguments   : Graph
    // Return      : int vertices number
    int Graph::GetEdgesNumber(Graph &Copy_Graph)
    {
        //return number of edges
        return Copy_Graph.EdgesNumber;
    }

    //========================================================================//
    // Edge Check Method
    //========================================================================//
    // Prototype   : bool CheckEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1, Vertex &Copy_Vertex2);
    // Description : a Method that Check if there is an edge between two vertices in the Graph
    // Arguments   : Graph, Vertex1, Vertex2
    // Return      : bool Edge check status
    bool Graph::CheckEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1, Vertex &Copy_Vertex2)
    {
        //loop Graph to find Vertex1 vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vertex1 vector found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex1.VertexName )
            {
                //loop vector1 vector
                for(int j = 0 ; j < Copy_Graph.GraphVertexArrayList[i].size() ; j++)
                {
                    //check if there is an edge
                    if( ( Copy_Graph.GraphVertexArrayList[i][j].ConnectedVertexName == Copy_Vertex2.VertexName ) && ( Copy_Graph.GraphVertexArrayList[i][j].ConnectedVertexWeight != 0 ) )
                    {
                        //return edge found
                        return true;
                    }
                }
            }
            //break loop
            break;

        }//end of for loop

        //return no edge
        return false;
    }

    //========================================================================//
    // Get Neighbor Vertices Method
    //========================================================================//
    // Prototype   : vector<Vertex> GeNeighborVertices(Graph &Copy_Graph, Vertex &Copy_Vertex);
    // Description : a Method that returns vector containing list of all neighboring vertices to the inputed vertex
    // Arguments   : Graph, Vertex
    // Return      : Vertex vector of neighboring vertices
    vector<Vertex> Graph::GetNeighborVertices(Graph &Copy_Graph, Vertex &Copy_Vertex)
    {
        vector<Vertex> V;
        //loop Vertices list and to find vector of required vertex
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++ )
        {
            //if vector found
            if(Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex.VertexName )
            {
                //loop connected vertices
                for(int j = 0 ; j < Copy_Graph.GraphVertexArrayList[i].size() ; j++ )
                {
                    //if Neighbor exists
                    if(Copy_Graph.GraphVertexArrayList[i][j].ConnectedVertexWeight != 0 )
                    {
                        //add vertex to V vector
                        V.push_back( Copy_Graph.GraphVertexArrayList[i][j] );

                    }//end of if statement

                }//end of connected vertices for loop

            }//end of vector check if statement


        }//end of vertices list for loop

        //if there is no connected vertices found
        if( 0 == V.size() )
        {
            //return default vertex value
            V.push_back( (0,0,0) );

        }//end of if statement

        //return vector
        return V;

    }//end of GeNeighborVertices() method


    //==========================================================================================//
    // Add Graph Edge Method
    //===========================================================================================//
    // Prototype   : void AddEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2);
    // Description : a Method that adds an edge between two vertices in a graph
    //               and determine the distance between them
    // Arguments   : Graph , Vertex1 , Vertex2
    // Return      : void
    void Graph::AddEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2, int Copy_Distance)
    {
        //Edge already exists status flag
        int EdgeDoseNotExist = 1;
        //Vertex1 index in graph vector
        int Vertex1Index = 0;
        //Vertex1 index in graph vector
        int Vertex2Index = 0;

        //loop Graph to find Vertex1 vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vertex1 index found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex1.VertexName )
            {
                Vertex1Index = i;
                break;
            }
        }//end of for loop

        //loop Graph to find Vertex2 vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vertex2 index found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex2.VertexName )
            {
                Vertex2Index = i;
                break;
            }
        }//end of for loop

        for(int j = 0 ; j < Copy_Graph.GraphVertexArrayList[Vertex1Index].size() ; j++)
        {
            //if already connected
            if( (Copy_Graph.GraphVertexArrayList[Vertex1Index][j].VertexName == Copy_Vertex2.VertexName) && (Copy_Graph.GraphVertexArrayList[Vertex1Index][j].ConnectedVertexWeight != 0) )
            {
                //flag Edge exists
                EdgeDoseNotExist = 0;
                break;
            }
        }
        //if Edge does not exists
        if(EdgeDoseNotExist)
        {
            //add edge:
            Copy_Graph.EdgesNumber++;
            //connect two vertices
            Copy_Vertex1.ConnectedVertexName = Copy_Vertex2.VertexName;
            Copy_Vertex2.ConnectedVertexName = Copy_Vertex1.VertexName;
            //add Edge Distance
            Copy_Vertex1.ConnectedVertexWeight = Copy_Distance;
            Copy_Vertex2.ConnectedVertexWeight = Copy_Distance;

            //Add two vertices to Graph

            Copy_Graph.GraphVertexArrayList[Vertex1Index].push_back(Copy_Vertex1);
            Copy_Graph.GraphVertexArrayList[Vertex2Index].push_back(Copy_Vertex2);

        }//end of if statement

    }//end of AddEdge() Method




    //==========================================================================================//
    // Delete Graph Edge Method
    //===========================================================================================//
    // Prototype   : void DeleteEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2);
    // Description : a Method that deletes an edge between two vertices in a graph
    // Arguments   : Graph , Vertex1 , Vertex2
    // Return      : void
    void Graph::DeleteEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2)
    {
        //Edge already exists status flag
        int EdgeExists   = 0;

        //vector1 index in graph vector
        int Vector1Index = 0;
        //vector2 index in graph vector
        int Vector2Index = 0;
        //Vertex1 index in Vertex vector
        int Vertex1Index = 0;
        //Vertex1 index in Vertex vector
        int Vertex2Index = 0;

        //loop Graph to find Vertex1 vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vertex1 index found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex1.VertexName )
            {
                Vector1Index = i;
                break;
            }
        }//end of for loop

        //loop Graph to find Vertex2 vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vertex2 index found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex2.VertexName )
            {
                Vector2Index = i;
                break;
            }
        }//end of for loop

        //loop vertex1 vector
        for(int j = 0 ; j < Copy_Graph.GraphVertexArrayList[Vector1Index].size() ; j++)
        {
            //find vertex1 index and check if edge exists with vertex2
            if( (Copy_Graph.GraphVertexArrayList[Vector1Index][j].ConnectedVertexName == Copy_Vertex2.VertexName) && (Copy_Graph.GraphVertexArrayList[Vector1Index][j].ConnectedVertexWeight != 0) )
            {
                //flag Edge exists
                EdgeExists   = 1;
                //return Vertex1 Index in vector
                Vertex1Index = j;
                break;

            }//end of if statement

        }//end of for loop

        //if Edge  exists
        if(EdgeExists)
        {
            //loop graph vector to find vertex2 vector
            for(int j = 0 ; j < Copy_Graph.GraphVertexArrayList[Vector2Index].size() ; j++)
            {
                //find vertex2 index
                if( (Copy_Graph.GraphVertexArrayList[Vector2Index][j].VertexName == Copy_Vertex2.VertexName) && (Copy_Graph.GraphVertexArrayList[Vector2Index][j].ConnectedVertexWeight != 0) )
                {
                    //return Vertex2 Index in vector
                    Vertex2Index = j;
                    break;

                }//end of if statement

            }//end of graph vector for loop

            //delete edge:
            Copy_Graph.EdgesNumber--;
            //delete connected parameters in two vertices
            Copy_Vertex1.ConnectedVertexName = 0;
            Copy_Vertex2.ConnectedVertexName = 0;
            //delete Edge Distance in two vertices
            Copy_Vertex1.ConnectedVertexWeight = 0;
            Copy_Vertex2.ConnectedVertexWeight = 0;

            //delete two vertices edges in Graph
            Copy_Graph.GraphVertexArrayList[Vector1Index].erase( Copy_Graph.GraphVertexArrayList[Vector1Index].begin()+ Vertex1Index );
            Copy_Graph.GraphVertexArrayList[Vector2Index].erase( Copy_Graph.GraphVertexArrayList[Vector2Index].begin()+ Vertex2Index );

        }//end of if statement

    }//end of AddEdge() Method


    //========================================================================//
    // Get Vertex Value in the Graph Method
    //========================================================================//
    // Prototype   : int GetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex);
    // Description : a Method that returns Vertex value
    // Arguments   : Graph, Vertex
    // Return      : int vertex value
    int Graph::GetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex)
    {
        //loop Graph to find Vertex vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex.VertexName )
            {
                //return vertex value
                return Copy_Graph.GraphVertexArrayList[i][0].VertexValue;
            }
        }//end of for loop

        //if vertex not found return 65000
        return 6500;

    }//end of GetVertexValue() Method

    //========================================================================//
    // Set Vertex Value in the Graph Method
    //========================================================================//
    // Prototype   : void SetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex, int Copy_VertexValue);
    // Description : a Method that Sets Vertex value
    // Arguments   : Graph, Vertex, Vertex value
    // Return      : void
    void Graph::SetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex, int Copy_VertexValue)
    {
        //loop Graph to find Vertex vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vertex vector found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex.VertexName )
            {
                //set vertex value
                Copy_Vertex.VertexValue = Copy_VertexValue;
                Copy_Graph.GraphVertexArrayList[i][0].VertexValue = Copy_VertexValue;
            }//end of if statement

        }//end of for loop

    }// end of SetVertexValue() Method

    //========================================================================//
    // Get Edge Value Method
    //========================================================================//
    // Prototype   : int SetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex, int Copy_VertexValue);
    // Description : a Method that Sets Vertex value
    // Arguments   : Graph, Vertex, Vertex value
    // Return      : void
    int Graph::GetEdgeValue(Graph &Copy_Graph,Vertex &Copy_Vertex1,Vertex &Copy_Vertex2)
    {
        //loop Graph to find Vertex1 vector
        for(int i = 0 ; i < Copy_Graph.GraphVertexArrayList.size() ; i++)
        {
            //if vertex1 vector found
            if( Copy_Graph.GraphVertexArrayList[i][0].VertexName == Copy_Vertex1.VertexName )
            {
                //loop Graph to find Vertex2
                for(int j = 0 ; j < Copy_Graph.GraphVertexArrayList[i].size() ; j++)
                {
                    //if vertex1 vector found
                    if( ( Copy_Graph.GraphVertexArrayList[i][j].ConnectedVertexName == Copy_Vertex2.VertexName ) && ( Copy_Graph.GraphVertexArrayList[i][j].ConnectedVertexWeight != 0 ) )
                    {
                        //return Edge value between Vertex1 and Vertex2
                        return Copy_Graph.GraphVertexArrayList[i][j].ConnectedVertexWeight;

                    }//end of vertex if statement

                }//end of i for loop

            }//end of vector if statement

        }//end of for loop

        //if edge not found return 6500
        return 65000;

    }// end of SetVertexValue() Method


//Graph class << operator overload (Output stream of graph class)
ostream& operator << (ostream &out, const Graph &G)
{
    for(int i =0 ; i< G.GraphVertexArrayList.size() ; i++)
    {
        for(int j =0 ; j< G.GraphVertexArrayList[i].size() ; j++)
        {
                out << G.GraphVertexArrayList[i][j].VertexName << "-" << G.GraphVertexArrayList[i][j].ConnectedVertexWeight << "->" << G.GraphVertexArrayList[i][j].ConnectedVertexName << " ";
        }
        out << endl << endl;
    }
    return out;
}
