//ID - 208768978
//GMAIL - michibinyamin@gmail.com

#include "Graph.hpp"
#include <vector>
#include <iostream>
using namespace std;

namespace ariel{

vector<vector<int>> adjMatrix;
    Graph::Graph(){}
    // Function to load the graph from a given input
    void Graph::loadGraph(const vector<vector<int>>& inputMatrix) {
        // Check if the matrix is square
        int rows = inputMatrix.size(); // Number of rows
        for (const auto& row : inputMatrix) {
            // If the length of any row doesnt match the number of rows
            if (row.size() != rows) {
                throw invalid_argument("Matrix must be square (n by n).");
            }
        }
        adjMatrix = inputMatrix;
    }

    // Function to print the graph's adjacency matrix
    void Graph::printGraph() const {
        for (const auto& row : adjMatrix) {
            for (int value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }

    // Function to return the graph's adjacency matrix as a string
    string Graph::stringGraph() const {
        string s = "";
        for (const auto& row : adjMatrix) {
            for (int value : row) {
                s += to_string(value) + " ";
            }
            s += "\n";
        }
        return s;
    }
    

    // Function to access the adjacency matrix
    const vector<vector<int>>& Graph::getg() const {
        return adjMatrix;
    }




    // Arothmatic operators



    // operator+ 
    Graph Graph::operator+(const Graph& other) const{

        // Throgh exeption if the matricies are not compatible
        if (other.getg().size() != this->getg().size())
        {
            throw invalid_argument("Matrices must be of the same size for addition.");
        }
        
        vector<vector<int>> other_matrix = other.getg();    // Get the other matrix
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {    
                new_matrix[i][j] = other_matrix[i][j] + this->getg()[i][j];   // Add up the values
            }
        }
        Graph newg;
        newg.loadGraph(new_matrix);
        return newg;
    }



    // operator-
    Graph Graph::operator-(const Graph& other) const{
        // Throgh exeption if the matricies are not compatible
        if (other.getg().size() != this->getg().size())
        {
            throw invalid_argument("Matrices must be of the same size for subtraction.");
        }
        
        vector<vector<int>> other_matrix = other.getg();    // Get the other matrix
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));
        
        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = this->getg()[i][j] - other_matrix[i][j];     // Add up the values
            }
        }

        Graph newg;
        newg.loadGraph(new_matrix);
        return newg;
    }



     // operator+=
    Graph& Graph::operator+=(const Graph& other){
        // Throgh exeption if the matricies are not compatible
        if (other.getg().size() != this->getg().size())
        {
            throw invalid_argument("Matrices must be of the same size for addition.");
        }
        vector<vector<int>> other_matrix = other.getg();    // Get the other matrix

        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> this_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                this_matrix[i][j] = this->getg()[i][j] + other_matrix[i][j];     // Add up the values
            }
        }

        // Load the result matrix into the current object
        this->loadGraph(this_matrix);
        return *this; // Return reference to current object
    }



    // operator-=
    Graph& Graph::operator-=(const Graph& other){
        // Throgh exeption if the matricies are not compatible
        if (other.getg().size() != this->getg().size())
        {
            throw invalid_argument("Matrices must be of the same size for addition.");
        }
        vector<vector<int>> other_matrix = other.getg();    // Get the other matrix

        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> this_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                this_matrix[i][j] = this->getg()[i][j] - other_matrix[i][j];     // subtrack the values
            }
        }

        // Load the result matrix into the current object
        this->loadGraph(this_matrix);
        return *this; // Return reference to current object
    }



    // operator+ unary
    Graph Graph::operator+() const{
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = +this->getg()[i][j];        // make value positive and add to new matrix
            }
        }

        Graph newg;
        newg.loadGraph(new_matrix);
        return newg;
    }



    // operator- unary
    Graph Graph::operator-() const{
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = -this->getg()[i][j];        // make value negative and add to new matrix
            }
        }

        Graph newg;
        newg.loadGraph(new_matrix);
        return newg;
    }

   

    // operator++
    Graph& Graph::operator++(){
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = this->getg()[i][j]+1;        // add value+1
            }
        }
        // Load the result matrix into the current object
        this->loadGraph(new_matrix);
        return *this; // Return reference to current object
    }



    // operator--
    Graph& Graph::operator--(){
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = this->getg()[i][j]-1;        // add value-1
            }
        }
        // Load the result matrix into the current object
        this->loadGraph(new_matrix);
        return *this; // Return reference to current object
    }   



    // operator* with a skalar
    Graph Graph::operator*(int skalar) const{
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = this->getg()[i][j]*skalar;        // times the value by a skalar
            }
        }
        Graph newg;
        newg.loadGraph(new_matrix);
        return newg;
    }



    // operator*= with a skalar
    Graph& Graph::operator*=(int skalar){
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = this->getg()[i][j]*skalar;        // times the value by a skalar
            }
        }
        // Load the result matrix into the current object
        this->loadGraph(new_matrix);
        return *this; // Return reference to current object
    }



    // operator/ with a skalar
    Graph Graph::operator/(int skalar) const{
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = this->getg()[i][j]/skalar;        // devide the value by a skalar
            }
        }
        Graph newg;
        newg.loadGraph(new_matrix);
        return newg;
    }



    // operator/= with a skalar
    Graph& Graph::operator/=(int skalar){
        int size = this->getg().size();                     // Store the matricies size for itarations
        // Initialize square matrix with size n x n
        vector<vector<int>> new_matrix(size, vector<int>(size));

        for (size_t i = 0; i < size; i++)
        {
            for (size_t j = 0; j < size; j++)
            {
                new_matrix[i][j] = this->getg()[i][j]/skalar;        // devide the value by a skalar
            }
        }
        // Load the result matrix into the current object
        this->loadGraph(new_matrix);
        return *this; // Return reference to current object
    }



    // operator* with another matrix
    Graph Graph::operator*(const Graph& other) const{
    // Get the adjacency matrices of both graphs
    vector<vector<int>> matrix1 = this->getg();
    vector<vector<int>> matrix2 = other.getg();

    // Check if the matrices are compatible for multiplication
    if (matrix1.size() != matrix2[0].size()) {
        throw invalid_argument("Matrices are not compatible for multiplication.");
    }

    // Result matrix will have dimensions (rows of matrix1) x (columns of matrix2)
    int rows = matrix1.size();
    int cols = matrix2[0].size();
    int common = matrix2.size();

    // Initialize the result matrix
    vector<vector<int>> new_matrix(rows, vector<int>(cols, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common; ++k) {
                new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Create a new graph and load it with the result matrix
    Graph newGraph;
    newGraph.loadGraph(new_matrix);
    return newGraph;
    }



    // operator*= with another matrix
    Graph& Graph::operator*=(const Graph& other){
    // Get the adjacency matrices of both graphs
    vector<vector<int>> matrix1 = this->getg();
    vector<vector<int>> matrix2 = other.getg();

    // Check if the matrices are compatible for multiplication
    if (matrix1.size() != matrix2[0].size()) {
        throw invalid_argument("Matrices are not compatible for multiplication.");
    }

    // Result matrix will have dimensions (rows of matrix1) x (columns of matrix2)
    int rows = matrix1.size();
    int cols = matrix2[0].size();
    int common = matrix2.size();

    // Initialize the result matrix
    vector<vector<int>> new_matrix(rows, vector<int>(cols, 0));

    // Perform matrix multiplication
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (int k = 0; k < common; ++k) {
                new_matrix[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Load the result matrix into the current object
    this->loadGraph(new_matrix);
    return *this; // Return reference to current object
    }
    


    // Comparisson operators



    // operator>
    bool Graph::operator>(const Graph& other) const{
        vector<vector<int>> matrix1 = this->getg();
        vector<vector<int>> matrix2 = other.getg();
        


        return true;
        
    }

    // operator>=
    bool Graph::operator>=(const Graph& other) const{
        return true;
    }

    // operator<
    bool Graph::operator<(const Graph& other) const{
        return true;
    }

    // operator<=
    bool Graph::operator<=(const Graph& other) const{
        return true;
    }

    // operator==
    bool Graph::operator==(const Graph& other) const{
        return true;
    }

    // operator!=
    bool Graph::operator!=(const Graph& other) const{
        return true;
    }

    // << operator overload, it does not belong to the class 
    ostream& operator<<(ostream& os, const Graph& graph){
        for (const auto& row : graph.getg()) {
            for (int value : row) {
               os << value << " ";
               
            }
        os << endl;
        }
        return os;
    }
}


