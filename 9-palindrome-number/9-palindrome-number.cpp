class Solution {
public:
    bool isPalindrome(int x) {
        // Base Cases
        
        if(x<0 || (x!=0 && x%10==0)){
            return false;
        }
        
        int revertno = 0;
        
        while(x>revertno){
            revertno = revertno*10 + x%10;
            x/=10;
        }
        
        return x==revertno || (x==revertno/10);
    }
};