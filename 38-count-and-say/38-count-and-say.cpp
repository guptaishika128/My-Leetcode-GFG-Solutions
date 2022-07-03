class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        if(n==2){
            return "11";
        }
        
        string prev = "11";
        for(int i=3;i<=n;i++){
            int cnt = 1;
            string temp = "";
            
            prev += '$';
            int len = prev.length();
            
            for(int j=1;j<len;j++){
                if(prev[j]!=prev[j-1]){
                    temp += cnt + '0';
                    temp += prev[j-1];
                    cnt = 1;
                } 
                else cnt++;
            }
            prev = temp;
        }
        return prev;
    }
};