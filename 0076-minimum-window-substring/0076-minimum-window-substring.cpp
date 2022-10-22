class Solution {
public:
    string minWindow(string s, string t) {
        int l1=s.length(),l2=t.length();
        string ans="";
        if(l2>l1){
            return ans;
        }
        
        
        int length=l1+1;
        unordered_map<char,int> mp1,mp2;
        unordered_map<char,int> :: iterator it2;
        
        for(int i=0;i<l2;i++){
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
    
        int i=l2-1,j=0;
        while(i<l1){
            bool flag = true;
            for(it2=mp2.begin();it2!=mp2.end();it2++){
                if (mp1.find(it2->first) == mp1.end()) {
                    flag=false;
                } else if (mp1[it2->first] < it2->second){
                    flag=false;                
                }
            }
             
            if(flag){
                bool flag1 = true;
                while(flag1){
                   if(length > i-j+1){
                        length = i-j+1;
                        ans = s.substr(j,i-j+1);
                    }
                    mp1[s[j]]--;
                    j++;
                    for(it2=mp2.begin();it2!=mp2.end();it2++){
                        if (mp1.find(it2->first) == mp1.end()) {
                            flag1=false;
                        } else if (mp1[it2->first] < it2->second){
                            flag1=false;                
                        }
                    } 
                }
            }
            
            i++;
            mp1[s[i]]++;
        }
        return ans;
    }
};