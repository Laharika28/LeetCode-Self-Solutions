class Solution {
public:
    string greatestLetter(string s) {
        string s1;
        string s2;
       

        for(int i=0;i<s.size();i++)
        {
          if((int(s[i]) >= 97) && (int(s[i]) <= 122))
          {
              s1.push_back(s[i]);
          }
          else
          {
            s2.push_back(s[i]);
          }
        }
       
        string ans;
       
        for(int i=0;i<s1.size();i++)
        {
            char x = toupper(s1[i]);
            for(int j=0;j<s2.size();j++)
            {
                if(x == s2[j])
                ans.push_back(x);
            }
        }
       
        sort(ans.begin(),ans.end());
        string kk ="";
        if (ans.size()>0)
            kk.push_back(ans[ans.size()-1]);
        return kk;
       
       
       
    }
};
