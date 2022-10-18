class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int si=str1.size();
        int ki=str2.size();
        string ans;
        
        int t[si+1][ki+1];
        for(int i=0;i<si+1;i++)
        {
            for(int j=0;j<ki+1;j++)
            {
                t[i][j]=0;
            }
        }
        
        for(int i=1;i<si+1;i++)
        {
            for(int j=1;j<ki+1;j++)
            {
                if(str1[i-1]==str2[j-1])
                {
                    t[i][j]=1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j]=max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        
        
        int i=si;
        int j=ki;
        
        while(i>0 && j>0)
        {
            if(str1[i-1]==str2[j-1])
            {
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else
            {
                if(t[i][j-1] > t[i-1][j])
                {
                    ans.push_back(str2[j-1]);
                    j--;
                }
                else
                {
                    ans.push_back(str1[i-1]);
                    i--;
                }
            }
        }
        
        while(i>0)
        {
            ans.push_back(str1[i-1]);
            i--;
        }
        while(j>0)
        {
            ans.push_back(str2[j-1]);
            j--;
        }
        
        string fina;
        for(int i=ans.size()-1;i>=0;i--)
        {
            fina.push_back(ans[i]);
            
        }
        return fina;
       
    }
};