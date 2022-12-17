class Solution {
public:
    int evalRPN(vector<string>& tokens) {
       stack<long long int> s;
        int n = tokens.size();
       for (int i=0;i<n;i++) {
           string v = tokens[i];
           if (v=="-" || v=="*" || v=="+" || v=="/") {
               long long int a = s.top();
               s.pop();
               long long int b = s.top();
               s.pop();
               if (v=="-") {
                   s.push(b-a);
               } else if (v=="+") {
                   s.push(b+a);
               } else if (v=="*") {
                   s.push(b*a);
               } else {
                   s.push(b/a);
               }
           } else {
               s.push(stoi(v));
           }
       }
        return s.top();
    }
};