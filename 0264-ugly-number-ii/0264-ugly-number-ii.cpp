class Solution {
public:

    int nthUglyNumber(int n) {
        if(n<=0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        
        vector<int> k(n);
        k[0] = 1;
        int cnt2 = 0, cnt3 = 0,cnt5 = 0;
        
        for(int i=1;i<n;i++){
            k[i] = min(k[cnt2]*2,min(k[cnt3]*3,k[cnt5]*5));
            if(k[i] == k[cnt2]*2) cnt2++;
            if(k[i] == k[cnt3]*3) cnt3++;
            if(k[i] == k[cnt5]*5) cnt5++;
        }
       return k[n-1];
    }
};