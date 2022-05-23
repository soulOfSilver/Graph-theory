#ifndef UNWEIGHTED_GRAPHS
#define UNWEIGHTED_GRAPHS

#include "Vector.hpp"
#include <iostream>

template <typename LABEL>
class UnweightedGraphs
{
private:
    struct node
    {
        LABEL label;

        node() : label() {}

        explicit node(const LABEL &l) : label(l) {}

        explicit node(const node &other)
        {
            label = other.label;
        }

        ~node() {}

        node &operator=(const node &other)
        {
            label = other.label;
            return *this;
        }

        LABEL getLabel(){
            return label;
        }
    };

    struct edge
    {
        node *startingNode, *endingNode;

        edge() : startingNode(nullptr), endingNode(nullptr) {}

        edge(const node &sn, const node &en) : startingNode(sn), endingNode(sn) {}

        explicit edge(const edge &other)
        {
            startingNode = other.startingNode;
            endingNode = other.endingNode;
        }

        ~edge() {}

        edge &operator=(const edge &other)
        {
            startingNode = other.startingNode;
            endingNode = other.endingNode;
            return *this;
        }
    };

public:
    typedef unsigned int cardinality_type;
    typedef bool unweighted_type;

    UnweightedGraphs() : _nodes(nullptr), _adjacencyMatrix(nullptr), _numberOfNodes(0) {}

    UnweightedGraphs(const UnweightedGraphs &other)
    {
        try
        {
            _nodes = new Vector<node>(other._numberOfNodes);
            *_adjacencyMatrix = new unweighted_type[other._numberOfNodes];
            for(cardinality_type i = 0; i < other._numberOfNodes; ++i){
                _adjacencyMatrix[i] = new unweighted_type[other._numberOfNodes];
            }

            for (cardinality_type i = 0; i < other._numberOfNodes; ++i)
            {
                _nodes[i] = other._nodes[i];
            }
            for (cardinality_type i = 0; i < other._numberOfNodes; ++i)
            {
                for (cardinality_type j = 0; j < other._numberOfNodes; ++j)
                {
                    _adjacencyMatrix[i][j] = other._adjacencyMatrix[i][j];
                }
            }
            _numberOfNodes = other._numberOfNodes;
        }
        catch (...)
        {
            clear(*this);
            throw;
        }
    }

    ~UnweightedGraphs()
    {
        clear(*this);
    }

    UnweightedGraphs &operator=(const UnweightedGraphs &other) const 
    {
        try
        {
            UnweightedGraphs tmp(other);
            return tmp;
        }
        catch (...)
        {
            return nullptr;
        }
    }

    node &operator[](const cardinality_type i) const
    {
        return _nodes[i];
    }

    void clear(UnweightedGraphs &graph)
    {
        delete graph._nodes;
        _nodes = nullptr;
        delete graph._adjacencyMatrix;
        _adjacencyMatrix = nullptr;
        graph._numberOfNodes = 0;
    }

    void addNode(LABEL &label){
        node newNode(label);
        if(!_nodes->alreadyExist(newNode)){
            _nodes->addElement(newNode);
        }
        else{
            std::cout << "Il nodo è già presente all'interno del grafo" << std::endl;
        }
    }

    cardinality_type getNumberOfNodes() const  {
        return _numberOfNodes;
    }

private:
    Vector<node> *_nodes;
    cardinality_type _numberOfNodes;
    unweighted_type **_adjacencyMatrix;
};

template <typename LABEL>
std::ostream &operator<<(std::ostream &os, const UnweightedGraphs<LABEL> &ug){
    for(unsigned int i = 0; i < ug.getNumberOfNodes(); ++i){
        os << ug[i].getLabel() << std::endl;
    }
    return os;
}

#endif