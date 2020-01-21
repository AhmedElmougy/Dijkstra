#ifndef __GRAPH_H__
#define __GRAPH_H__

#include<vector>
using namespace std;





//class that represent a graph
class Graph
{
    public:

    //=================================================//
    //Class members
    //=================================================//
    //Number of vertices
    int VerticesNumber;
    //Number of Edges
    int EdgesNumber;
    //Density of Edge exists in the graph
    int EdgeDensity;
    //Range of distances exists inn the graph
    int DistanceRange;
    //Graph list Representation using vector class
    vector< vector<Vertex> > GraphVertexArrayList;
    //=================================================//

    //=================================================//
    //Class constructors
    //=================================================//

    //graph default constructor
    //=================================================//
    Graph();


    //graph complete arguments constructor
    //==========================================================================//
    Graph(int Copy_VerticesNumber, int Copy_EdgeDensity, int Copy_DistanceRange);

    //graph Vertices Number argument constructor
    //=================================================//
    Graph(int Copy_VerticesNumber);


    //graph VerticesNumber, EdgeDensity arguments constructor
    //=========================================================//
    Graph(int Copy_VerticesNumber, int Copy_EdgeDensity);
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
    int GetVertexPosition(Graph &Copy_Graph, Vertex &Copy_Vertex);


    //========================================================================//
    // Add Graph Vertex Method
    //========================================================================//
    // Prototype   : void AddVertex(Graph &Copy_Graph, Vertex &Copy_Vertex);
    // Description : a Method that adds a vertex to the graph
    // Arguments   : Graph , Vertex1 , Vertex2
    // Return      : void
    void AddVertex(Graph &Copy_Graph, Vertex &Copy_Vertex);


    //========================================================================//
    // Get number of vertices of the Graph Method
    //========================================================================//
    // Prototype   : int GetVeticesNumber(Graph &Copy_Graph);
    // Description : a Method that returns number of vertices in the graph
    // Arguments   : Graph
    // Return      : int vertices number
    int GetVeticesNumber(Graph &Copy_Graph);

    //========================================================================//
    // Get number of edges of the Graph Method
    //========================================================================//
    // Prototype   : int GetEdgesNumber(Graph &Copy_Graph);
    // Description : a Method that returns number of Edges in the graph
    // Arguments   : Graph
    // Return      : int vertices number
    int GetEdgesNumber(Graph &Copy_Graph);

    //========================================================================//
    // Edge Check Method
    //========================================================================//
    // Prototype   : bool CheckEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1, Vertex &Copy_Vertex2);
    // Description : a Method that Check if there is an edge between two vertices in the Graph
    // Arguments   : Graph, Vertex1, Vertex2
    // Return      : bool Edge check status
    bool CheckEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1, Vertex &Copy_Vertex2);

    //========================================================================//
    // Get Neighbor Vertices Method
    //========================================================================//
    // Prototype   : vector<Vertex> GeNeighborVertices(Graph &Copy_Graph, Vertex &Copy_Vertex);
    // Description : a Method that returns vector containing list of all neighboring vertices to the inputed vertex
    // Arguments   : Graph, Vertex
    // Return      : Vertex vector of neighboring vertices
    vector<Vertex> GetNeighborVertices(Graph &Copy_Graph, Vertex &Copy_Vertex);


    //==========================================================================================//
    // Add Graph Edge Method
    //===========================================================================================//
    // Prototype   : void AddEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2);
    // Description : a Method that adds an edge between two vertices in a graph
    //               and determine the distance between them
    // Arguments   : Graph , Vertex1 , Vertex2
    // Return      : void
    void AddEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2, int Copy_Distance);




    //==========================================================================================//
    // Delete Graph Edge Method
    //===========================================================================================//
    // Prototype   : void DeleteEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2);
    // Description : a Method that deletes an edge between two vertices in a graph
    // Arguments   : Graph , Vertex1 , Vertex2
    // Return      : void
    void DeleteEdge(Graph &Copy_Graph, Vertex &Copy_Vertex1 ,Vertex &Copy_Vertex2);


    //========================================================================//
    // Get Vertex Value in the Graph Method
    //========================================================================//
    // Prototype   : int GetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex);
    // Description : a Method that returns Vertex value
    // Arguments   : Graph, Vertex
    // Return      : int vertex value
    int GetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex);

    //========================================================================//
    // Set Vertex Value in the Graph Method
    //========================================================================//
    // Prototype   : void SetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex, int Copy_VertexValue);
    // Description : a Method that Sets Vertex value
    // Arguments   : Graph, Vertex, Vertex value
    // Return      : void
    void SetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex, int Copy_VertexValue);

    //========================================================================//
    // Get Edge Value Method
    //========================================================================//
    // Prototype   : int SetVertexValue(Graph &Copy_Graph,Vertex &Copy_Vertex, int Copy_VertexValue);
    // Description : a Method that Sets Vertex value
    // Arguments   : Graph, Vertex, Vertex value
    // Return      : void
    int GetEdgeValue(Graph &Copy_Graph,Vertex &Copy_Vertex1,Vertex &Copy_Vertex2);

};//end of class graph




//Graph class << operator overload (Output stream of graph class)
ostream& operator << (ostream &out, const Graph &G);



#endif // __GRAPH_H__
