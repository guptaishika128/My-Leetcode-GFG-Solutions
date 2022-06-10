class Solution {
public:
    int countOne(int n){
        int count = 0;
        while(n>0){
            int rem = n%2;
            n=n/2;
            if(rem==1){
            count++;
            }
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i=0;i<=n;i++){
            int a = countOne(i);
            res.push_back(a);
        }
        return res;
    }
};