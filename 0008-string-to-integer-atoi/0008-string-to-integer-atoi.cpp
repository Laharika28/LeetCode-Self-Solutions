class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0,sign=1;
        int n=s.length();
        bool isNo=false,isSign=false;
        for(int i=0;i<n;i++){
            
            if(s[i]>='0' && s[i]<='9'){
                isNo=true;
                ans= (ans*10) + (s[i]-'0');
                if(ans>=pow(2,31)){
                    break;
                }
            }else {
                if(isNo){
                    break;
                }else if(s[i]=='-' && !isSign){
                    sign = -1;
                    isSign=true;
                }else if(s[i]=='+' && !isSign){
                    sign = 1;
                    isSign=true;
                }else if(s[i]==' ' && !isSign){
                    continue;
                }else{
                    break;
                }
            }
        }
        ans = ans*sign;
        if(ans<pow(-2,31)){
            ans = pow(-2,31);
        }
        if(ans>pow(2,31)-1){
            ans = pow(2,31)-1;
        }
        return ans;
    }
};