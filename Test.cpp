//ID - 208768978
//GMAIL - michibinyamin@gmail.com

#include <sstream> // Include the <sstream> header for stringstream
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"

using namespace std;

TEST_CASE("Test graph addition and subtraction")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    // Operator+
    ariel::Graph g3 = g1 + g2;
    vector<vector<int>> expectedGraph = {
        {0, 2, 1},
        {2, 0, 3},
        {1, 3, 0}};
    ariel::Graph expected;
    expected.loadGraph(expectedGraph);
    CHECK(g3.stringGraph() == expected.stringGraph());

    // Operator-
    g3 = g1 - g2;         
    vector<vector<int>> expectedGraph2 = {
        {0, 0, -1},
        {0, 0, -1},
        {-1, -1, 0}};
    ariel::Graph expected2;
    expected2.loadGraph(expectedGraph2);
    CHECK(g3.stringGraph() == expected2.stringGraph());

    // Operator+=
    g1 += g2;              
    CHECK(g1.stringGraph() == expected.stringGraph());

    ariel::Graph g4;
    vector<vector<int>> expectedGraph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g4.loadGraph(expectedGraph3);

    // Operator-=
    g1 -= g2;              
    CHECK(g1.stringGraph() == g4.stringGraph());

    ariel::Graph g5;
    vector<vector<int>> expectedGraph4 = {
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}};
    g5.loadGraph(expectedGraph4);

    // operator++
    g2 = g1 + g5;
    ++g1;
    CHECK(g1.stringGraph() == g2.stringGraph());
    
    // operator--
    g2 = g1 - g5;
    --g1;
    CHECK(g1.stringGraph() == g2.stringGraph());

    // operator+ unary             
    g2 = +g1;
    CHECK(g1.stringGraph() == g2.stringGraph());

    // operator- unary             
    g2 = -g1;
    g1 *= -1;
    CHECK(g1.stringGraph() == g2.stringGraph());

}

TEST_CASE("Test graph multiplication")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);

    // Operator* with another matrix
    ariel::Graph g4 = g1 * g2;

    vector<vector<int>> expectedGraph = {
        {1, 0, 2},
        {1, 3, 1},
        {1, 0, 2}};

    ariel::Graph expected;
    expected.loadGraph(expectedGraph);
    CHECK(g4.stringGraph() == expected.stringGraph());

    // Operator*=
    g1 *= g2;
    CHECK(g4.stringGraph() == g1.stringGraph());

    // Operator* with skalar
    vector<vector<int>> expectedGraph2 = {
        {0, 2, 2},
        {2, 0, 4},
        {2, 4, 0}};
    ariel::Graph g5;
    expected.loadGraph(expectedGraph2);
    g5 = g2*2;
    CHECK(g5.stringGraph() == expected.stringGraph());

    g5 /= 2;

    // Operator*= with skalar
    g5 *= 2;
    CHECK(g5.stringGraph() == expected.stringGraph());

}

TEST_CASE("Compare operations")
{
    ariel::Graph g1;
    ariel::Graph g2;
    ariel::Graph g3;
    ariel::Graph g4;
    ariel::Graph g5;
    ariel::Graph g6;

    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g1.loadGraph(graph1);

    vector<vector<int>> graph2 = {
        {0, 1, 0, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 0},
        {0, 0, 0, 0}};
    g2.loadGraph(graph2);

    vector<vector<int>> graph3 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g3.loadGraph(graph3);

    vector<vector<int>> graph4 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g4.loadGraph(graph4);

    vector<vector<int>> graph5 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g5.loadGraph(graph5);

    vector<vector<int>> graph6 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}};
    g6.loadGraph(graph6);


    // operator>


    // operator>=


    // operator<


    // operator<=


    // operator==


    // operator!=


}


TEST_CASE("Cout operator"){
    // Operator<< 
    vector<vector<int>> Graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    ariel::Graph g1;
    g1.loadGraph(Graph);

    // Expected string representation of the matrix
    string expected_output = "1 2 3 \n4 5 6 \n7 8 9 \n";
    // Capture cout output
    stringstream buffer;
    streambuf* old_cout = std::cout.rdbuf(buffer.rdbuf());

    // Print the matrix
    cout << g1;

    // Restore cout
    cout.rdbuf(old_cout);

    // Get the printed output
    string actual_output = buffer.str();

    // Check if the actual output matches the expected output
    CHECK(actual_output == expected_output);
}


// A graph which is not squre will throgh an exeption in the loading stage, this was tested already in assignment 2,
// so i will check now the cases which two squre graphs with difarent sizes throgh exeptions.
TEST_CASE("Invalid operations")
{
    ariel::Graph g1;
    vector<vector<int>> graph = {
        {0, 1},
        {1, 0}};
    g1.loadGraph(graph);
    ariel::Graph g2;
    vector<vector<int>> weightedGraph = {
        {0, 1, 1},
        {1, 0, 2},
        {1, 2, 0}};
    g2.loadGraph(weightedGraph);
    ariel::Graph g5;
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g5.loadGraph(graph2);
    CHECK_THROWS(g5 * g1);
    CHECK_THROWS(g1 * g2);
    CHECK_THROWS(g1 *= g2);

    // Addition of two graphs with different dimensions
    ariel::Graph g6;
    vector<vector<int>> graph3 = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0},
        {0, 0, 1, 0, 1},
        {1, 0, 0, 1, 0}};
    g6.loadGraph(graph3);
    CHECK_THROWS(g1 + g6);
    CHECK_THROWS(g5 += g2);
    CHECK_THROWS(g5 - g2);
    CHECK_THROWS(g5 -= g2);
}

