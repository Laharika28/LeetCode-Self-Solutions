class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        vector<int> v;
        int i=0;
        while(i<k)
        {
            int mx=INT_MIN;
            for(int i=0;i<gifts.size();i++)
            {
              mx=max(mx,gifts[i]);
            }     
            for(int i=0;i<gifts.size();i++)
            {
                if(mx == gifts[i])
                {
                    gifts[i] = floor(pow(gifts[i],0.5));
                    break;
                }
                
            }
            i++;
        }
        long long int sum=0;
        for(int i=0;i<gifts.size();i++)
        {
            sum = sum + gifts[i];
        }
        return sum;
       
        
    }
};