class Solution {
public:
    
    bool isValid(string t,unordered_set<char> s){
        for(int i=0;i<t.length();i++){
            if(s.find(t[i]) != s.end()){
                return false;
            }
            s.insert(t[i]);
        }
        return true;
    }
    
    int solve(vector<string>& arr,int n, unordered_set<char> s){
        if(n==0){
            return 0;
        }        
        if(isValid(arr[n-1],s)){
            int v1 = solve(arr,n-1,s);
            for(int i=0;i<arr[n-1].length();i++){
                s.insert(arr[n-1][i]);
            }
            int v2 = arr[n-1].length()+solve(arr,n-1,s);
            return max(v1,v2);
        }
        return solve(arr,n-1,s);
    }
    
    int maxLength(vector<string>& arr) {
        unordered_set<char> s;
        int n = arr.size();
        return solve(arr,n,s);
    }
};