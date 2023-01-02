class Solution {
public:
    bool detectCapitalUse(string word) {
        int l = word.size();
        char c1 = word[0];
        
        if (c1>='A' && c1<='Z') {
            char c2 = word[1];
            if (c2>='A' && c2<='Z') {
               for (int i=2;i<l;i++) {
                    if (!(word[i]>='A' && word[i]<='Z')) {
                        return false;
                    }
                } 
            } else {
                for (int i=2;i<l;i++) {
                    if (!(word[i]>='a' && word[i]<='z')) {
                        return false;
                    }
                }
            }
            
        } else if (c1>='a' && c1<='z') {
            for (int i=1;i<l;i++) {
                if (!(word[i]>='a' && word[i]<='z')) {
                    return false;
                }
            }
        }
        return true;
    }
};