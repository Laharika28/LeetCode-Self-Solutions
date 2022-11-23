class Solution {
    bool isValid ( set<char> &row,  set<char> &col,set<char> &block, char c ) {
        if (row.find(c) != row.end()) {
            return false;
        }
        if (col.find(c) != col.end()) {
            return false;
        }
        if (block.find(c) != block.end()) {
           return false; 
        }
        return true;
}
    
    int block_no ( int i,int j ) {
        if (i<3) {
            if (j<3) {
                return 0;
            } 
            return j<6 ? 1 : 2;
        } else if (i<6) {
            if (j<3) {
                return 3;
            } 
            return j<6 ? 4 : 5;
        }
        if (j<3) {
            return 6;
        } 
        return j<6 ? 7 : 8;
    }
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector< set<char> > row(9);
        vector< set<char> > col(9);
        vector< set<char> > block(9);
        
        for (int i=0;i<9;i++) {
            for (int j=0;j<9;j++) {
                if (board[i][j] != '.') {
                    int c = block_no(i,j);
                    if( ! isValid(row[i],col[j],block[c],board[i][j]) ) {
                        return false;
                    }
                    row[i].insert(board[i][j]);
                    col[j].insert(board[i][j]);
                    block[c].insert(board[i][j]);      
                }                            
            }
        }
                                                  
        return true;
    }
};