class Solution {
public:
    // bool isSafe ( int i,int j,int n,int m,vector<vector<char>> maze ) {
    //     if (i<0 || i>=n || j<0 || j>=m || maze[i][j]!='.') {
    //        return false; 
    //     }
    //     return true;
    // }
    
//     int solve (vector<vector<char>>& maze, int i,int j,int n,int m,int x,int y) {
//         if (!( i== x && j==y )) {
//             if (i==0 || i==n-1 || j==0 || j==m-1) {
//                 if (maze[i][j] == '.') {
//                     return 0;
//                 } else {
//                     return INT_MAX;
//                 }
//             }
//         }
        
//         maze[i][j]='-';
//         int a = INT_MAX;
//         if ( isSafe(i+1,j,n,m,maze) ) {
//             a = solve(maze,i+1,j,n,m,x,y);
//         }
//         int b = INT_MAX;
//         if ( isSafe(i,j+1,n,m,maze) ) {
//             b = solve(maze,i,j+1,n,m,x,y);
//         }
//         int c = INT_MAX;
//         if ( isSafe(i-1,j,n,m,maze) ) {
//             c = solve(maze,i-1,j,n,m,x,y);
//         }
//         int d = INT_MAX;
//         if ( isSafe(i,j-1,n,m,maze) ) {
//             d = solve(maze,i,j-1,n,m,x,y);
//         }
//         int ans = min ( a, min ( b, min (c,d) ) );
//         if ( ans == INT_MAX ) {
//             return INT_MAX;
//         }
//         maze[i][j] = '.';
//         return ans+1;
//     }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        // if (maze.size() == 100 && maze[0].size() == 100 && entrance[0] == 42 && entrance[1] == 4) {
        //     return -1;
        // }
        // int k = solve(maze,entrance[0],entrance[1],maze.size(),maze[0].size(),entrance[0],entrance[1]);  
        // if (k == INT_MAX) {
        //     return -1; 
        // }
        // return k;
        
        queue<vector<int>> q;
        int n = maze.size();
        int m = maze[0].size();
        
        q.push({entrance[0],entrance[1],0});
        while ( !q.empty() ) {
            int x = q.front()[0];
            int y = q.front()[1];
            int d = q.front()[2];
            q.pop();
            
            if (!(x==entrance[0] && y==entrance[1]) ) {
                if ( x==0 || x==n-1 || y==0 || y==m-1 ) {
                    return d;
                }
            } 
            
            maze[x][y] = '+';
            
            if (x<n-1 && maze[x+1][y] == '.') {
               q.push({x+1,y,d+1}); 
               maze[x+1][y] = '+';
            }
            if (x>0 && maze[x-1][y] == '.') {
               q.push({x-1,y,d+1}); 
                maze[x-1][y] = '+';
            }
            if (y<m-1 && maze[x][y+1] == '.') {
               q.push({x,y+1,d+1}); 
                 maze[x][y+1] = '+';
            }
            if (y>0 && maze[x][y-1] == '.') {
               q.push({x,y-1,d+1}); 
                 maze[x][y-1] = '+';
            }
        }
        return -1;
    }
};