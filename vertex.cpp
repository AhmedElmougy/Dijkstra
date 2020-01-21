#include <iostream>
#include <vector>

#include "vertex.h"

using namespace std;

    //=================================================//
    //Class constructors
    //=================================================//
    //default void constructor
    Vertex::Vertex(): VertexName(0), ConnectedVertexName(0), ConnectedVertexWeight(0), VertexValue(0), PreviousVertex(0){}




//Vertex Vector << operator overload (Output stream of Vertex vector)
ostream& operator << (ostream &out, const vector<Vertex> &V)
{
    for(int i =0 ; i< V.size() ; i++)
    {
        out << V[i].VertexName << "-" << V[i].ConnectedVertexWeight << "->" << V[i].ConnectedVertexName << " ";
    }
    return out;
}

//Vertex << operator overload (Output stream of Vertex type)
ostream& operator << (ostream &out, const Vertex &V)
{
    out << V.VertexName << "-" << V.ConnectedVertexWeight << "->" << V.ConnectedVertexName;
    return out;
}
