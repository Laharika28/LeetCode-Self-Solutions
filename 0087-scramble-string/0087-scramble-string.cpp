class Solution {
public:
    unordered_map<string,bool> mp;
   
    bool solve(string a ,string b)
    {
        int n=a.size();
        if(a.size()==0 && b.size()==0)
        {
            return true;
        }
        if(a.compare(b) == 0)
        {
            return true;
        }
     

        if(a.length()<=1 || b.length()<=1)
        {
            return false;
        }
       
        string key=a;
        key.push_back(' ');
        key.append(b);
       
        if(mp.find(key) != mp.end())
        {
            return mp[key];
        }
       
        bool flag=false;
       
        for(int i=1;i<=n-1;i++)
        {
            bool case1 = (solve(a.substr(0,i) , b.substr(n-i,i))) && (solve(a.substr(i,n-i),b.substr(0,n-i)));
           
            bool case2= (solve(a.substr(0,i),b.substr(0,i))) && (solve(a.substr(i,n-i) , b.substr(i,n-i)));
           
            if(case1 || case2)
            {
                flag=true;
            }
        }
        mp[key]=flag;
        return flag;
    }
   
   
   
    bool isScramble(string s1, string s2) {
        if(s1.size()!=s2.size()){
            return false;
        }
        bool ans;        
        ans=solve(s1,s2);
        return ans;
       
       
       
    }
};