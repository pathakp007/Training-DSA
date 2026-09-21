class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        int l = flowerbed.size();
        
         for(int i=0;i<l;i++){
            bool leftcheck = (i==0) || (flowerbed[i-1]==0);
            bool rightcheck = (i==l-1) || (flowerbed[i+1]==0);
            if(flowerbed[i]==0 && leftcheck && rightcheck)
            {
                flowerbed[i]=1;
                n--;
            }
        }
        return n<=0;
    }
};