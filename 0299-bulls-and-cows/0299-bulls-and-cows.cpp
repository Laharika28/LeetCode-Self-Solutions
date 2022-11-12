class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char,int> mp;
        for (int i=0;i<secret.length();i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                guess[i] = '*';
            } else {
                mp[secret[i]]++;
            }
        }
        
        for (int i=0;i<guess.length();i++) {
            if (guess[i] == '*') {
                continue;
            }
            if (mp.find(guess[i]) != mp.end()) {
                cows++;
                mp[guess[i]]--;
                if (mp[guess[i]] == 0) {
                   mp.erase(guess[i]); 
                }
            }
        }
         
        string t = to_string(bulls) + "A" + to_string(cows) + "B";
        return t;
    }
};