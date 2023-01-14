class Solution {
    char parent[26];
    void make_parent () {
        for (int i=0;i<26;i++) {
            parent[i] = i + 'a';
        }
    }
    
    char find_parent (char c) {
        if (parent[c-'a'] == c) {
            return c;
        }
        return parent[c-'a'] = find_parent(parent[c-'a']);
    }
    
    void union_set(char c1,char c2) {
        int u = find_parent(c1)-'a';
        int v = find_parent(c2)-'a';
        parent[max(u,v)] = min(u,v) + 'a';
    }
    
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();
        make_parent();
        for (int i=0;i<n;i++) {
            union_set(s1[i],s2[i]);
        }
        for (int i=0;i<baseStr.size();i++) {
            baseStr[i] = find_parent(baseStr[i]);
        }
        return baseStr;
    }
};