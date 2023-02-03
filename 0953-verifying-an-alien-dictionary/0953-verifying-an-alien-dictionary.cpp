class Solution {
    unordered_map<char,int> mp;
    
    // static bool compare (string a, string b) {
    //     for (int i=0 ; i<min(a.length(),b.length()) ; i++) {
    //        if (a[i] == b[i]) {
    //            continue;
    //        }
    //        return mp[a[i]] < mp[b[i]];
    //     }
    //     return (a.size()<b.size()) ? true : false;
    // }
public:
    bool isAlienSorted(vector<string>& words, string order) {
        
        for (int i=0;i<order.size();i++) {
            mp[order[i]] = i;
        }
        
        for (int i=0;i<words.size()-1;i++) {
            string a = words[i];
            string b = words[i+1];
            bool flag = true;
            for (int l=0;l<min(a.length(),b.length());l++) {
                if (a[l] == b[l]) {
                    continue;
                }
                if (mp[a[l]] > mp[b[l]]) {
                    return false;
                }  else {
                    flag = false;
                    break;
                }
            }
            if (flag && a.size()>b.size()) {
                return false;
            } 
        }
        
        return true;
        
//          vector<string> temp = words;
//          sort(temp.begin(),temp.end(),compare);
        
//         if (words == temp) {
//             return true;
//         }
        
//         return false;
    }
};