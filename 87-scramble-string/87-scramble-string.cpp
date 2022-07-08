    
    unordered_map<string,int> mp;

class Solution {
public:
    
    bool solve(string a,string b,int n){
        if(a.compare(b)==0){
            return true;
        }
        
        if(n<=1){
            return false;
        }
        
        string key = a + " " + b;
        
        if(mp.find(key)!=mp.end()){
            return mp[key];
        }
        
        bool flag=false;
        
        for(int k=1;k<=n-1;k++){
            if((solve(a.substr(0,k),b.substr(n-k,k),k) && solve(a.substr(k,n-k),b.substr(0,n-k),n-k)) ||
               (solve(a.substr(0,k),b.substr(0,k),k) && solve(a.substr(k,n-k),b.substr(k,n-k),n-k)) ){
                flag = true;
                break;
            }
        }
        
        return mp[key]=flag;
        
    }
    
    bool isScramble(string s1, string s2) {
        if(s1.length()!=s2.length()){
            return false;
        }
        if(s1=="" && s2==""){
            return true;
        }
        return solve(s1,s2,s1.length());
    }
};