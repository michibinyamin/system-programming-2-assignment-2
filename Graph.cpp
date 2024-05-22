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

    // Function to get the number of edges
    const int Graph::get_num_edges() const {
        int count = 0;
        for (const auto& row : adjMatrix) {
            for (int value : row) {
                if (value != 0)
                {
                    count++;
                }
            
            }
        }
        return count;
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
                new_matrix[i][j] = +this->getg()[i][j];        // make value positive and add to new matrix(does not make a diffarence)
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

    
    bool iscontains(const Graph& g1, const Graph& g2){
        // Check if the sizes are possible for being containd
        if (g1.getg().size() <= g2.getg().size())
        {
            return false;
        }
        for (size_t i = 0; i < g2.getg().size(); i++) {
            for (size_t j = 0; j < g2.getg().size(); j++) {
                // Check that there is not a edge which exists in other but not in this
                if(g2.getg()[i][j] != 0 && g1.getg()[i][j] == 0){
                    return false;
                }
            }
        }
        // Check that they are not the same graph
        return true;
    }

    // operator>
    bool Graph::operator>(const Graph& other) const{
        // Check if other is containd in this graph
        if(iscontains(*this, other)){
            return true;
        }
        else if(iscontains(other, *this)){
            return false;
        }

        // If both are not containd in each other then check if this has more edges
        if (this->get_num_edges() > other.get_num_edges())
        {
            return true;
        }
        else if (this->get_num_edges() == other.get_num_edges())
        {
            // Check if this has more vertecies then other
            if (this->getg().size() > other.getg().size())
            {
                return true;
            }
        }
        // If none of the above happend then the other graph is bigger or they are equal, return false
        return false;
    }

    // operator>=
    bool Graph::operator>=(const Graph& other) const{
        return !(*this<other);
    }

    // operator<
    bool Graph::operator<(const Graph& other) const{
        // Check if this is containd in other graph
        if(iscontains(other, *this)){
            return true;
        }
        else if(iscontains(*this, other)){
            return false;
        }

        // If both are not containd in each other then check if this has more edges
        if (this->get_num_edges() < other.get_num_edges())
        {
            return true;
        }
        else if (this->get_num_edges() == other.get_num_edges())
        {
            // Check if this has more vertecies then other
            if (this->getg().size() < other.getg().size())
            {
                return true;
            }
        }
        // If none of the above happend then the other graph is bigger or they are equal, return false
        return false;
    }

    // operator<=
    bool Graph::operator<=(const Graph& other) const{
        return !(*this>other);
    }

    // operator==
    bool Graph::operator==(const Graph& other) const{
        // First option - they are the same
        if(this->getg().size() == other.getg().size()){
            bool equel = true;
            for (size_t i = 0; i < other.getg().size(); i++)
            {
                for (size_t j = 0; j < other.getg().size(); j++)
                {
                    if (this -> getg()[i][j] != other.getg()[i][j])
                    {
                        equel = false;
                    }
                }
            }
            if (equel)
            {
                return true;
            }
        }
        // If they are not equel check if both are not bigger then the other
        if (!(*this > other) && !(*this < other))
        {
            return true;
        }
        // If both dont happen then return false
        return false;
    }

    // operator!=
    bool Graph::operator!=(const Graph& other) const{
        return !(*this == other);
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


