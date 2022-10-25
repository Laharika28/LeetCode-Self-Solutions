class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s = "",t = "";
        for(int i=0;i<word1.size();i++){
            s = s + word1[i];
        }
        
        for(int i=0;i<word2.size();i++){
            t = t + word2[i];
        }
        
        if(s.compare(t)==0){
            return true;
        }
        return false;
    }
};