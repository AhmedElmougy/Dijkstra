#ifndef __VERTEX_H__
#define __VERTEX_H__

#include<iostream>
#include<vector>
using namespace std;





// class that represents a graph vertex
// each vertex have :
// - Name
// - Connected Vertex Weight(Distance)
// - Value that will be used in path finding algorithm
// - Name of previous vertex
class Vertex
{
    public:

    //=================================================//
    //Class members
    //=================================================//
    int VertexName;
    int ConnectedVertexName;
    int ConnectedVertexWeight;
    int VertexValue;
    int PreviousVertex;

    //=================================================//
    //Class constructors
    //=================================================//
    //default void constructor
    Vertex();
    //complete arguments constructor
    //complete arguments constructor
    template<class T>
    Vertex(T VertexName,T ConnectedVertexName, T ConnectedVertexWeight,T VertexValue, T PreviousVertex): VertexName( static_cast<T>(VertexName) ),ConnectedVertexName( static_cast<T>(ConnectedVertexName) ),ConnectedVertexWeight( static_cast<T>(ConnectedVertexWeight) ),VertexValue( static_cast<T>(VertexValue) ), PreviousVertex( static_cast<T>(PreviousVertex) ){}
    //3 arguments constructor
    template<class T>
    Vertex(T VertexName,T ConnectedVertexName, T ConnectedVertexWeight): VertexName( static_cast<T>(VertexName) ),ConnectedVertexName( static_cast<T>(ConnectedVertexName) ),ConnectedVertexWeight( static_cast<T>(ConnectedVertexWeight) ),VertexValue( static_cast<T>(0) ), PreviousVertex( static_cast<T>(0) ) {}
    //VertexName argument constructor
    template<class T>
    Vertex(T VertexName): VertexName( static_cast<T>(VertexName) ), ConnectedVertexName( static_cast<T>(0) ),ConnectedVertexWeight( static_cast<T>(0) ),VertexValue( static_cast<T>(0)), PreviousVertex( static_cast<T>(0)) {}

};//end of Vertex class



//Vertex Vector << operator overload (Output stream of Vertex vector)
ostream& operator << (ostream &out, const vector<Vertex> &V);

//Vertex << operator overload (Output stream of Vertex type)
ostream& operator << (ostream &out, const Vertex &V);




#endif // __VERTEX_H__
