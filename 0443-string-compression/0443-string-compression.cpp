class Solution {
public:
    int compress(vector<char>& chars) {
        int current = 0;
        int n = chars.size();
        
        int cnt = 1;
        
        for(int i=0;i<n;i++){
            if(i<n-1 && chars[i] == chars[i+1]){
                cnt++;
            }
            else{
                chars[current++] = chars[i];
                if(cnt > 1){
                    for(auto c:to_string(cnt)){
                        chars[current++] = c;
                    }
                }
                cnt = 1;
            }
        }
        return current;
    }
};