class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        int x=0,y=0;
        for(int i=0;i<word1.size();i++){
            for(int j=0;j<word1[i].length();j++){
                if(y>=word2[x].length()){
                    x++;y=0;
                }
                if(x>=word2.size()){
                    return false;
                }
                if(word1[i][j] != word2[x][y]){
                    return false;
                }
                y++;
            }    
        }
        if(x<word2.size()-1 || (x<word2.size() && y<word2[x].length())){
            return false;
        }
        return true;
    }
};