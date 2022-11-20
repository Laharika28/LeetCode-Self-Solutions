class Solution {
public:
    
    
    //   '1'-'0' 
    
    //    49 - 48 = 1
    
    
    string replaceDigits(string s) {
        
        string ans;
        
        for(int i=0;i<s.size();i++)
        {
            if(int(s[i])>=97 && int(s[i])<=122)
            {
                ans.push_back(s[i]);
            }
            else
            {
                char k;
                k = s[i-1] + (s[i] - '0');
                ans.push_back(k);
            }
            
            
        }
        return ans;
    }
};


