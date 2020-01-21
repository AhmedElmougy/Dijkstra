#include<iostream>

#include<vector>
#include "vertex.h"
#include "graph.h"
#include "priorityqueue.h"
#include "dijkstra.h"


using namespace std;




int main(void)
{
    //initialize graph with 50 vertices and 20% density and 1-10 distance range
    Graph G(10, 20, 10);

    //output Graph
    cout << "Graph:"<< endl << G << endl;
    //output number of vertices
    cout << "Number of vertices is : " << G.GetVeticesNumber(G) << endl;
    //output number of edges
    cout << "Number of Edges is    : " << G.GetEdgesNumber(G)   << endl << endl;

    Vertex v1(5,0,0);
    //run algorithm
    ShortestPath Dijkstra(G,v1);


    //path showing each vertex from starting point to that vertex
    cout << "Final shortest path for each node" << endl;
    cout << Dijkstra << endl;


    //output average path length
    cout << "Average path length : "   << endl ;
    cout << Dijkstra.CalculateAveragePathLength(Dijkstra,G) << endl;




    return 0;
}

