class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        // for(int i=0;i<s.size();i++){
        //     for(int j=0;j<t.size();j++){
        //         int x = i;
        //         int y = j;
        //         int temp = 0;
        //         while( x<s.size() && y<t.size() ){
        //             if(s[x]!=t[y]){
        //                 temp++;
        //             }
        //             if(temp==1){
        //                 ans += 1;
        //             }
        //             if(temp>=2){
        //                 break;
        //             }
        //             x++;
        //             y++;
        //         }
        //     }
        // }
        // return ans;
        int n = s.length();
        int m = t.length();
        
        vector<vector<int>> sameStr(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] == t[j-1]){
                    sameStr[i][j] = 1 + sameStr[i-1][j-1];
                }
            }
        }
        
        vector<vector<int>> diffStr(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1] != t[j-1]){
                    diffStr[i][j] = 1 + sameStr[i-1][j-1];
                }else{
                    diffStr[i][j] = diffStr[i-1][j-1];
                }
                ans += diffStr[i][j];
            }
        }
        return ans;
    }
};