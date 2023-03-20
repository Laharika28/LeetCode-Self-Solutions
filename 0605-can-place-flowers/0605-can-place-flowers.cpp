class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
     int m = flowerbed.size();
     if (n==0) return true;
     if (m==1 && flowerbed[0]==0 && n==1) return true;
     for (int i=0;i<m;i++) { 
         if (i==0) {
             if (flowerbed[i]==0 && flowerbed[i+1]==0) {
                n--;
                i++;
            }
         }else if (i==m-1) {
             if (flowerbed[i]==0 && flowerbed[i-1]==0) {
                n--;
                i++;
             }
         }else if (flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0) {
             n--;
             i++;
         }
     }
     if (n<=0) {
         return true;
     }
     return false;
    }
};