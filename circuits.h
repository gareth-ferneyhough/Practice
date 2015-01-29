#include <set>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class Circuits
{
public:
    int howLong(vector<string> connects, vector<string> costs)
    {        
        // allocate mem
        vector<vector<int>> edge_weights;
        size_t num_vertices = connects.size();
        edge_weights.resize(num_vertices);
        for(size_t i = 0; i < num_vertices; ++i)
        {
            edge_weights[i].resize(num_vertices);            
            for(size_t j = 0; j < num_vertices; ++j)
            {
                edge_weights[i][j] = -1;
            }
        }

        // make adj_matrix
        for(size_t i = 0; i < num_vertices; ++i)
        {
            istringstream connection_stream(connects[i]);
            istringstream cost_stream(costs[i]);
            int vertex;
            int cost;
            while(connection_stream >> vertex)
            {
                cost_stream >> cost;
                edge_weights[i][vertex] = cost;
            }
        }

        vector<int> sortedVertices = getTopSortedVertices(edge_weights);
        vector<int> longestPaths(edge_weights.size(), -1);
        for(auto it = sortedVertices.begin(); it != sortedVertices.end(); ++it)
        {
            longestPaths[*it] = getLongestPathToV(edge_weights, longestPaths, *it);
        }
        
        return *max_element(longestPaths.begin(), longestPaths.end());
    }
private:   
    int getLongestPathToV(vector<vector<int>> edge_weights, vector<int>longestPaths, int v)
    {
        if(!hasIncommingConnections(v, edge_weights)) return 0;
        vector<int> incommingConnections = getIncomingConnections(v, edge_weights);
        
        int longestPath = -1;
        for(auto it = incommingConnections.begin(); it != incommingConnections.end(); ++it)
        {
            if(longestPaths[*it] + edge_weights[*it][v] > longestPath)
            {
                longestPath = longestPaths[*it] + edge_weights[*it][v];
            }
        }
        return longestPath;
    }

    vector<int> getTopSortedVertices(vector<vector<int>> edge_weights)
    {
        // top-sort
        set<int> s;
        for(size_t i = 0; i < edge_weights.size(); ++i)
        {
            if(!hasIncommingConnections(i, edge_weights))
            {
                s.insert(i);
            }
        }

        vector<int> sorted;
        while(s.size() != 0)
        {
            int current = *s.begin();
            s.erase(s.begin());
            sorted.push_back(current);
            
            for(size_t i = 0; i < edge_weights.size(); ++i)
            {
                if(edge_weights[current][i] == -1) continue;
                edge_weights[current][i] = -1;
                if(!hasIncommingConnections(i, edge_weights))
                {
                    s.insert(i);
                }
            }
        }
        return sorted;
    }

    bool hasIncommingConnections(int v, vector<vector<int>> connections)
    {
        for(auto it = connections.begin(); it != connections.end(); ++it)
        {
            if((*it)[v] != -1) return true;
        }
        return false;
    }

    vector<int> getIncomingConnections(int v, vector<vector<int>> connections)
    {
        vector<int> result;
        for(size_t i = 0; i < connections.size(); ++i)
        {
            if(connections[i][v] != -1) result.push_back(i);
        }
        return result;
    }
};