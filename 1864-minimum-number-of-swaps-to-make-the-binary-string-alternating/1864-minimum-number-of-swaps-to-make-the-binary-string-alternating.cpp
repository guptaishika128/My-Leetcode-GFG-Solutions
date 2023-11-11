class Solution {
public:
    
    int minfill(string& s, char ch) {
        int count = 0;
        for(int i=0; i<s.size(); i+=2) {
            if(s[i] != ch) count++;
        }
        return count;
    }
    
    int minSwaps(string s) {
        int cntOne = count(s.begin(),s.end(),'1');
        int cntZero = count(s.begin(),s.end(),'0');
        if(abs(cntOne-cntZero)>1){
            return -1;
        }
        if(cntOne>cntZero){
            return minfill(s,'1');
        }
         if(cntZero>cntOne){
            return minfill(s,'0');
        }
        return min(minfill(s,'0'),minfill(s,'1'));
    }
};