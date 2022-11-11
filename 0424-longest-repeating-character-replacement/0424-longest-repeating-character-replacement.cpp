class Solution {
public:
    int characterReplacement(string s, int k) {

        unordered_map<char,int> mp;
        int mx_length = 0;
        int mx_char_len = 0;
        char mx_char;
        
        int l = 0, r = 0;
        int n = s.length();
        
        while ( l<n && r<n ) {
            mp[s[r]]++;
            if (mp[s[r]] > mx_char_len) {
               mx_char_len = mp[s[r]];
               mx_char = s[r];
            }
            
            while (l<r && r-l+1-mx_char_len > k) {
                if (s[l] == mx_char) {
                    mx_char_len--;
                }
                mp[s[l]]--;
                l++;
            }
             mx_length = max(mx_length, r-l+1);
            
            // cout<<mx_char<<" "<<mx_char_len<<" "<<mx_length<<endl;
            r++;
        }
        mp.clear();
        l = n-1; r = n-1;
        while ( l>=0 && r>=0 ) {
            mp[s[r]]++;
            if (mp[s[r]] > mx_char_len) {
               mx_char_len = mp[s[r]];
               mx_char = s[r];
            }
            
            while (l>r && l-r+1-mx_char_len > k) {
                if (s[l] == mx_char) {
                    mx_char_len--;
                }
                mp[s[l]]--;
                l--;
            }
             mx_length = max(mx_length, l-r+1);
            
            // cout<<mx_char<<" "<<mx_char_len<<" "<<mx_length<<endl;
            r--;
        }
        
        return mx_length;
    }
    
};