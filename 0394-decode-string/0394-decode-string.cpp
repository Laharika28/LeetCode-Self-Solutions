class Solution {
public:
    string decodeString(string s) {
        if(s.length()==0) {
            return s;
        }
        stack<string> st;
        string a;
        int i = 0, l =s.length();
        string val;
        while(i<l) {
            while ( i<l && (s[i] >= '0' && s[i] <='9')) {
                val.push_back(s[i]);
                i++;
            }
            if (val.length()>0) st.push(val);
            val="";
            if (s[i] == '[') i++;
            while ( i<l && (s[i] >= 'a' && s[i] <='z')) {
                val.push_back(s[i]);
                i++;
            }
            if (val.length()>0) st.push(val);
            val="";
            if (s[i] == ']') {
                string t="";
                while (st.top()[0]>='a' && st.top()[0]<='z') {
                    t = st.top() + t;
                    st.pop();
                }
                string decode = "";
                string p = st.top();
                int no = stoi(p);
                st.pop();
                while (no>0) {
                   decode = decode + t;
                    no--;
                }
                st.push(decode);
                i++;
            }
        }
        
        while (st.size()>1) {
            a = st.top();
            st.pop();
            val = st.top();
            st.pop();
            st.push (val + a);
        }
        return st.top();
    }
};