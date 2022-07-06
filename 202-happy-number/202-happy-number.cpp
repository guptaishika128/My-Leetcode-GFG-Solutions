class Solution {
public:
    int digitSquareSum(int n){
        int sum =0 , temp;
        while(n){
            temp=n%10;
            sum += temp*temp;
            n/=10;
        }
        return sum;
    }
    
    
    bool isHappy(int n) {
     /*   unordered_map<int,int> mp;
        
        while(n!=1){
            if(mp[n]==0){
                mp[n]++;
            } else{
                return false;
            }
             int sum = 0;
            while(n!=0){
                sum += pow(n%10,2);
                n /= 10;
            }
            n= sum;
    }
    return true;
    */
    int slow, fast;
    slow = fast = n;
    do {
        slow = digitSquareSum(slow);
        fast = digitSquareSum(fast);
        fast = digitSquareSum(fast);
    } while(slow != fast);
    if (slow == 1) return 1;
    else return 0;
        
        
    }
};