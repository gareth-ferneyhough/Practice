#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <tuple>

using namespace std;

typedef pair<int, int> point;

class Board
{
public:
    Board() : num_rows(0), num_cols(0)
    {
    }        
    
    void setup_board(vector<string> board)
    {
        num_rows = board.size();
        num_cols = board[0].size();

        static_board.resize(num_rows);
        for(size_t i = 0; i < board.size(); ++i)
        {
            static_board[i].resize(num_cols);
            istringstream ss(board[i]);
            char c;            
            int j = 0;
            while(ss >> c)
            {
                if(c == 'A')
                {
                    player_a_start = make_pair<int, int>(i, j);
                    static_board[i][j] = '.';
                }
                else if(c == 'B')
                {
                    player_b_start = make_pair<int, int>(i, j);
                    static_board[i][j] = '.';
                }
                else static_board[i][j] = c;
                j++;
            }
        }
    }

    bool is_board_state_valid(point player_a, point player_b)
    {
        // check bounds
        if(player_a.first < 0 || player_a.first >= num_rows) return false;
        if(player_a.second < 0 || player_a.second >= num_cols) return false;
        if(player_b.first < 0 || player_b.first >= num_rows) return false;
        if(player_b.second < 0 || player_b.second >= num_cols) return false;

        if(static_board[player_a.first][player_a.second] == 'X') return false;
        if(static_board[player_b.first][player_b.second] == 'X') return false;
        if(player_a == player_b) return false;
        return true;
    }

    point player_a_start;
    point player_b_start;

private:    
    int num_rows;
    int num_cols;
    vector<vector<char>> static_board;
};

struct Node
{
    Node() {}
    Node(point player_a_pos, point player_b_pos)
    {
        this->player_a_pos = player_a_pos;
        this->player_b_pos = player_b_pos;
    }
    bool operator==(const Node& other)
    {
        return 
            other.player_a_pos == player_a_pos && 
            other.player_b_pos == player_b_pos;
    }
    bool operator<(const Node& other) const
    {        
        return tie(player_a_pos, player_b_pos) < tie(other.player_a_pos, other.player_b_pos);
    }
    point player_a_pos;
    point player_b_pos;
    vector<Node> previous;
};

class PathFinding
{
public: 
    int minTurns(vector<string> initial_board)
    {
        board.setup_board(initial_board);
        Node start(board.player_a_start, board.player_b_start);
        Node end(start.player_b_pos, start.player_a_pos);

        // BFS
        int num_turns = 0;
        queue<Node> q;
        set<Node> visited;

        visited.insert(start);

        q.push(start);
        while(q.size() > 0)
        {
            num_turns++;
            Node n = q.front();
            q.pop();            

            vector<Node> neighbors = get_next_valid_nodes(n);
            for(auto it = neighbors.begin(); it != neighbors.end(); ++it)
            {
                if(visited.count(*it) != 0) continue;                
                if(*it == end)
                {
                    it->previous.insert(it->previous.end(), n.previous.begin(), n.previous.end());
                    it->previous.push_back(n);
                    return it->previous.size();
                }
                it->previous.insert(it->previous.end(), n.previous.begin(), n.previous.end());
                it->previous.push_back(n);
                
                q.push(*it);
                visited.insert(*it);
            }            
        }
        return -1;
    }

private:
    Board board;

    vector<Node> get_next_valid_nodes(Node current_position)
    {
        vector<Node> valid_nodes;
        vector<point> player_a_moves;
        vector<point> player_b_moves;
        for(int i = -1; i <= 1; ++i)
        {
            for(int j = -1; j <= 1; ++j)
            {
                player_a_moves.push_back(make_pair<int, int>(
                    current_position.player_a_pos.first + i, 
                    current_position.player_a_pos.second + j));

                player_b_moves.push_back(make_pair<int, int>(
                    current_position.player_b_pos.first + i, 
                    current_position.player_b_pos.second + j));
            }
        }

        for(auto it_a = player_a_moves.begin(); it_a != player_a_moves.end(); ++it_a)
        {
            for(auto it_b = player_b_moves.begin(); it_b != player_b_moves.end(); ++it_b)
            {                
                // prevent a and b from swapping places
                if(*it_a == current_position.player_b_pos && 
                    *it_b == current_position.player_a_pos) continue; 

                if(board.is_board_state_valid(*it_a, *it_b))
                {
                    valid_nodes.push_back(Node(*it_a, *it_b));
                }
            }
        }
        return valid_nodes;
    }
};