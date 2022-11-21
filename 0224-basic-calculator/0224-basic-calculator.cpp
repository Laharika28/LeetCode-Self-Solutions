class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n = s.length();
        int i = 0;
        int val = 0;
        int ans = 0;
        int sign = 1;
        int t = 0;
        string temp = "";
        while ( i<n ) {
            if ( s[i] == '-' ) {
                sign = -1;
                i++;
            }
            while ( i<n && s[i] == ' ') {
               i++; 
            }
            while (i<n && s[i]>='0' && s[i]<='9' ) {
                temp.push_back(s[i]);
                i++;
            } 
            if ( temp != "" ) {
                t = stoi(temp);
                val = val + (sign * t);
                temp = "";
            }
            if ( i>=n ) {
                break;
            } 
            if ( s[i] =='-' ) {
                sign = -1;
                i++;
            } else if( s[i] == '+' ) {
                sign = 1;
                i++;
            }
            
            if ( s[i] == '(') {
                if ( i>0 ) {
                    st.push(val);
                    st.push(sign);
                }
                ans = ans + val;
                val = 0;
                sign = 1;
                i++;
            }
            
            if ( s[i] == ')' ) {
                if ( st.size() > 0 ) {
                    int sig = st.top();
                    st.pop();
                    int a = st.top();
                    st.pop();
                    val = ( a + (sig * val));
                }
                i++;
            }
            
        }
        return  val ;
    }
};