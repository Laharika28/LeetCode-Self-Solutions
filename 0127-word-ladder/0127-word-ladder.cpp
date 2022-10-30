class Solution {
public:
    int ladderLength(string startWord, string targetWord, vector<string>& words) {
         unordered_set<string> s(words.begin(), words.end());
        queue<string> q;
        q.push(startWord);
        int cnt = 1;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                string word = q.front();
                q.pop();
                if (word == targetWord) {
                    return cnt;
                }
                s.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (s.find(word) != s.end()) {
                            q.push(word);
                            s.erase(word);
                        }
                     }
                    word[j] = c;
                }
            }
            cnt++;
        }
        return 0;
    }
};