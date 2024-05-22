//ID - 208768978
//GMAIL - michibinyamin@gmail.com

#include "Graph.hpp"
#include "Algorithms.hpp"
using ariel::Algorithms;

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

int main()
{
    ariel::Graph g1;
    // 3x3 matrix that represents a connected graph.
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);    // Load the graph to the object.
    cout<<"graph g1 is : \n"<<g1<<endl;         // Should print the matrix of the graph: [0, 1, 0], [1, 0, 1], [0, 1, 0]


    ariel::Graph g2;
    // 3x3 matrix that represents a weighted connected graph.
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);                         // Load the graph to the object.
    cout<<"graph g2 is : \n"<<g2<<endl;

    ariel::Graph g3;
    g3 = g1 + g2;                                        // Add the two graphs together.
    cout<<"graph g1 + g2 is : \n"<<g3<<endl;             // Should print the matrix of the graph: [0, 2, 1], [2, 0, 3], [1, 3, 0]

    g1 *= -2;                                            // Multiply the graph by -2.
    cout<<"graph g1 times skalar -2 and store in g1: \n"<<g1<<endl;     // Should print the matrix of the graph: [0, -2, 0], [-2, 0, -2], [0, -2, 0]

    g1 /= -2;
    cout<<"graph g1 divided by skalar -2 is and store in g1: \n"<<g1<<endl;

    ariel::Graph g4 = g1 * g2;                              // Multiply the two graphs together.
    cout<<"graph g1 times graph g2 is : \n"<<g4<<endl;   // Should print the multiplication of the matrices of g1 and g2: [0, 0, 2], [1, 0, 1], [1, 0, 0]


    cout<< "The graphs now are:\ng1:\n"<<g1<<"\ng2:\n"<<g2;
    string t = "no";
    if (g1<g2)
    {
        t = "yes";
    }
    
    cout<< "is g1 smaller then g2? answer : " << t <<"\n";

    ariel::Graph g5;
    // 5x5 matrix that represents a connected graph.
    vector<vector<int>> big_graph = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(big_graph); // Load the graph to the object.
    try
    {
        ariel::Graph g6 = g5 * g1; // Multiply the two graphs together.
    }
    catch (const std::invalid_argument &e)
    {
        cout << e.what() << endl; // Should print "The number of columns in the first matrix must be equal to the number of rows in the second matrix."
    }
}
