class Solution {
public:
    int lastRemaining(int n) {
        if(n==1){
            return 1;
        }
        bool isLeft = true;
        int head = 1, step = 1;
        while(n>1){
            if(isLeft || n&1){
                head += step;
            }
            step *= 2;
            n /= 2;
            isLeft = !isLeft;
        }
        return head;
    }
};