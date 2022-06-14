class Solution {
public:
    string largestGoodInteger(string num) {
       string ans = "";
        int n = num.size();
        for(int i=n-1;i>=2;i--){
            if(num[i]==num[i-1] && num[i-1]==num[i-2])
            {
                string temp = {num[i],num[i-1],num[i-2]};
                ans = max(ans,temp);
            }    
        }
        return ans;
    }
};