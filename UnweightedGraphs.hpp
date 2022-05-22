#ifndef UNWEIGHTED_GRAPHS
#define UNWEIGHTED_GRAPHS

template <typename LABEL>
class UnweightedGraphs
{
public:
    typedef unsigned int cardinality_type;
    typedef bool unweighted_type;

    UnweightedGraphs() : _nodes(nullptr), _adjacencyMatrix(nullptr), _numberOfNodes(0) {}

    UnweightedGraphs(const UnweightedGraphs &other)
    {
        try
        {
            _nodes = new node[other._numberOfNodes];
            _adjacencyMatrix = new unweighted_type[other._numberOfNodes];

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

    UnweightedGraphs &operator=(const UnweightedGraphs &other)
    {
        try
        {
            UnweightedGraphs tmp(other);
            return tmp;
        }
        catch (...)
        {
            clear(tmp);
        }
    }

    clear(UnweightedGraphs &graph)
    {
        delete graph._nodes;
        delete graph._adjacencyMatrix;
        graph._numberOfNodes = 0;
    }

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

    struct weighted_edge
    {
        edge e;
        int weight;

        weighted_edge() : e(), weight(0) {}

        weighted_edge(const edge &e, const int w) : e(e), weight(w) {}

        weighted_edge(const weighted_edge &other)
        {
            e = other.e;
            weight = other.weight;
        }

        ~weighted_edge() {}

        weighted_edge &operator=(const weighted_edge &other)
        {
            e = other.e;
            weight = other.weight;
        }
    };

    node *_nodes;
    cardinality_type _numberOfNodes;
    unweighted_type **_adjacencyMatrix;
};

#endif