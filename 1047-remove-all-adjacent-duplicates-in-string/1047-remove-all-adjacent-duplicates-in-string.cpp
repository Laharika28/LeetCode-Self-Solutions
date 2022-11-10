

class Solution {
public:
    string removeDuplicates(string s) {
        
        string t = s;
        reverse(t.begin(),t.end());
        
        if(s.compare(t) == 0 && s.size()%2 == 0) {
            return "";
        }
    
        if(s.length() < 2) {
            return s;
        }
    
        bool flag = false;
        for (int i=0;i<s.length()-1;i++) {
            if (s[i] == s[i+1]) {
                s.erase(i,2);
                flag = true;
                break;
            }
        }
        if(flag) {
           return removeDuplicates(s); 
        }
        return s;
    }
};