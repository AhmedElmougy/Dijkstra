#ifndef __DIJKSTRA_H__
#define __DIJKSTRA_H__


//shortest path class it's used to find the shortest path between two vertices in the graph
class ShortestPath
{
    public:

    //========================================================================//
    // class members
    //========================================================================//

    //Vector of vectors of that holds a vertex type
    vector< vector <Vertex> > PathVector;
    float AveragePathlength;

    //========================================================================//
    // class constructors
    //========================================================================//
    ShortestPath(Graph &Copy_Graph);

    ShortestPath(Graph &Copy_Graph, Vertex &Copy_Vertex);


    //========================================================================//
    // Vertices List
    //========================================================================//
    // Prototype   : vector<Vertex> VerticesList(Graph &Copy_Graph);
    // Description : a Method to return Vertices List in graph
    // Arguments   : Graph
    // Return      : Vertices list of type vector<Vertex>
    vector<Vertex> VerticesList(Graph &Copy_Graph);

    //========================================================================//
    // Find Shortest Path between two vertices
    //========================================================================//
    // Prototype   : vector<Vertex> FindShortestPath(ShortestPath &Copy_ShortestPath, Vertex Copy_Vertex1, Vertex Copy_Vertex2);
    // Description : a Method to return vector containing shortest vertices path from vertex1 to vertex2
    // Arguments   : Graph,vertex1,vertex2
    // Return      : shortest path vertices vector of type vector<Vertex>
    vector<Vertex> FindShortestPath(ShortestPath &Copy_ShortestPath, Vertex &Copy_Vertex);

    //========================================================================//
    // Calculate average path length
    //========================================================================//
    // Prototype   : float CalculateAveragePathLength(ShortestPath &Copy_ShortestPath,Graph &Copy_Graph);
    // Description : a Method to return graph average path length
    // Arguments   : ShortestPath,Graph
    // Return      : float average path length
    float CalculateAveragePathLength(ShortestPath &Copy_ShortestPath,Graph &Copy_Graph);

};


//output stream of shortest path type
ostream& operator << (ostream &out, const ShortestPath &Copy_ShortestPath);

#endif // __DIJKSTRA_H__
