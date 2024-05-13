//ID - 208768978
//GMAIL - michibinyamin@gmail.com

// If this HPP file was defined, then it prevents it from being defind twice.
// If it was not defined then it definds it. 
// Can also use pragme1
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
using namespace std;
namespace ariel {
class Graph {
    vector<vector<int>> adjMatrix;
public:
    Graph();  // Constructor
    // Function to load the graph from a given input
    void loadGraph(const vector<vector<int>>& inputMatrix);
    
    // Function to print the graph's adjacency matrix
    void printGraph() const;


    // Function to access the adjacency matrix
    const vector<vector<int>>& getg() const;


    // Arothmatic operators

    // operator+ 
    Graph operator+(const Graph& other) const;

    // operator+ unary
    Graph operator+() const;

    // operator-
    Graph operator-(const Graph& other) const;

    // operator- unary
    Graph operator-() const;

    // operator+=
    Graph& operator+=(const Graph& other);

    // operator-=
    Graph& operator-=(const Graph& other);

    // operator++
    Graph& operator++();

    // operator--
    Graph& operator--();

    // operator* with a skalar
    Graph operator*(int skalar) const;

    // operator*= with a skalar
    Graph& operator*=(int skalar);

    // operator* with another matrix
    Graph operator*(const Graph& other) const;

    // operator*= with another matrix
    Graph& operator*=(const Graph& other);




   // Comparisson operators

    // operator>
    bool operator>(const Graph& other) const;

    // operator>=
    bool operator>=(const Graph& other) const;

    // operator<
    bool operator<(const Graph& other) const;

    // operator<=
    bool operator<=(const Graph& other) const;

    // operator==
    bool operator==(const Graph& other) const;

    // operator!=
    bool operator!=(const Graph& other) const;

};

// Declaration of the << operator overload, it does not belong to the class
    ostream& operator<<(ostream& os, const Graph& graph);
}
#endif