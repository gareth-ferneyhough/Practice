#pragma once

#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <stack>
#include <utility>
#include <algorithm>

using namespace std;

typedef pair<int, int> node;
bool graph[400][600];

class grafixMask
{
public:    
    vector<int> sortedAreas(vector<string> rectangles)
    {
        for(int i = 0; i < 400; ++i)
        {
            for(int j = 0; j < 600; ++j)
            {
                graph[i][j] = false;
            }
        }

        for(auto it = rectangles.begin(); it != rectangles.end(); ++it)
        {
            istringstream ss(*it);
            int y1, x1, y2, x2;
            ss >> y1 >> x1 >> y2 >> x2;
            for(int i = y1; i <= y2; ++i)
            {
                for(int j = x1; j <= x2; ++j)
                {
                    graph[i][j] = true;
                }
            }
        }

        vector<int> regions;
        for(int i = 0; i < 400; ++i)
        {
            for(int j = 0; j < 600; ++j)
            {
                if(graph[i][j]) continue;
                int current_region_size = 0;                
                stack<node> s;                    
                s.push(make_pair(i, j));
                while(s.size() > 0)
                {
                    node n = s.top();
                    s.pop();
                    if(n.first < 0 || n.first > 399 || n.second < 0 || n.second > 599) continue;
                    
                    if(!graph[n.first][n.second])                        
                    {                            
                        graph[n.first][n.second] = true;
                        s.push(make_pair(n.first, n.second + 1));
                        s.push(make_pair(n.first, n.second - 1));
                        s.push(make_pair(n.first + 1, n.second));
                        s.push(make_pair(n.first - 1, n.second));
                        current_region_size += 1;
                    }
                }
                regions.push_back(current_region_size);
            }
        }   
        sort(regions.begin(), regions.end());
        return regions;
    }
};

