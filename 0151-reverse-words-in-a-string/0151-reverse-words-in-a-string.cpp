class Solution {
public:
    string reverseWords(string s) {
        string t;
        string ans = "";
        int i = 0;
        int n = s.length();
        
        while (i<n) {
            while(i<n && s[i] == ' ') {
                i++;
            }
            if(i>=n){
                break;
            }
            while(i<n && s[i] != ' ') {
                t.push_back(s[i]);
                i++;
            }
            if(ans.length() == 0){
                ans = t;
            } else{
                ans = t + " " + ans ;
            }
            
            t = "";
        }
        return ans;
    }
};