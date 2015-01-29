#include <set>
#include <vector>
#include <stack>
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class Marketing
{
public:
    long howMany(vector<string> compete)
    {
        adjacency_list.resize(compete.size());
        vertex_colors.resize(compete.size());
        for(size_t i = 0; i < compete.size(); ++i)
        {
            istringstream ss(compete[i]);
            int num;
            while(ss >> num)
            {
                adjacency_list[i].push_back(num);
                adjacency_list[num].push_back(i);
            }
            vertex_colors[i] = -1;
        }

        int number_of_subgraphs = 0;
        for(size_t i = 0; i < vertex_colors.size(); ++i)
        {
            if(vertex_colors[i] != -1) continue;
            
            number_of_subgraphs++;
            // DFS
            stack<int> s;
            s.push(i);
            vertex_colors[i] = 0;
            set<int> visited;

            while(s.size() != 0)
            {
                int current = s.top();
                s.pop();
                if(visited.count(current) == 0)
                {
                    visited.insert(current);
                    int current_color = vertex_colors[current];
                    int expected_child_color = swapColor(current_color);
                    for(size_t child_idx = 0; child_idx < adjacency_list[current].size(); ++child_idx)
                    {
                        int child = adjacency_list[current][child_idx];
                        if(vertex_colors[child] == current_color)
                        {
                            return -1;
                        }
                        vertex_colors[child] = expected_child_color;
                        s.push(child);
                    }
                }
            }               
        }
        return (long)pow(double(2), number_of_subgraphs);
    }

private:
    set<int> vertices;
    vector<vector<int>> adjacency_list;
    vector<int> vertex_colors;    
    
    int swapColor(int color)
    {
        if(color == 0) return 1;
        return 0;
    }
};