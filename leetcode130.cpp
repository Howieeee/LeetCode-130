class Solution {
public:
    vector<pair<int,int>> direction = {{-1,0},{1,0},{0,-1},{0,1}};
    
    bool is_vaild(int& row, int& col, int& m, int& n){
        // <=0 >=3 
        if(row <= 0 || row >= m-1 || col <= 0 || col >= n-1)
            return false;
        
        return true;
    }
    
    
    void solve(vector<vector<char>>& board) {
        int m = board.size() , n = board[0].size();
        //cout << m << " " << n << endl;
        
        queue<pair<int,int>> q;
        vector<pair<int,int>> visited;
        /*
          m*n
              0 1 2 m-1
            0 a a a a
            1 b b b b
            2 c c c c 
          n-1 d d d d
        */
        
         for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O'){
                q.push({i, 0});
                visited.push_back({i,0});
            }
            if (board[i][n - 1] == 'O'){
                q.push({i, n - 1});
                visited.push_back({i,n-1});
            }
        }

        //border 'O'
        for (int j = 1; j < n - 1; j++) {
            if (board[0][j] == 'O'){
                q.push({0, j});
                visited.push_back({0,j});
            }
            if (board[m - 1][j] == 'O'){
                q.push({m - 1, j});
                visited.push_back({m-1,j});
            }
        }
        
        
        
    
        
        while(!q.empty()){
            
            pair<int,int> cur = q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                int r = cur.first + direction[k].first;
                int c = cur.second + direction[k].second;
                
                if(is_vaild(r,c,m,n)){
                    if(board[r][c] == 'O'){
                        board[r][c] = 'X';
                        q.push({r,c});
                        visited.push_back({r,c});
                    }
                }
            }
            
        }
        
        
        vector<vector<char>> ans (m, vector<char>(n, 'X') ); 
        //cout << visited.size();
        for(auto index: visited){
            //cout << index.first << " " << index.second << endl;
            ans[index.first][index.second] = 'O';
           
        }
        
        board =ans;
        
    }
};
