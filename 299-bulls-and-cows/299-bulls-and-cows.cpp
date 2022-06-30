class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> smap(10,0);
        vector<int> gmap(10,0);
        
        int bulls = 0;
        int cows = 0;
        
        if(guess.length()!=secret.length() || secret.length()==0){
            return "0A0B";
        }
        
        for(int i=0;i<secret.length();i++){
            
            if(secret[i] == guess[i]){
                bulls++;
            } else{
                smap[secret[i]-'0']++;
                gmap[guess[i]-'0']++;
            }
        }
        
        for (int i = 0; i < smap.size(); ++i) {
            cows += min(smap[i], gmap[i]);
        }
        
         return to_string(bulls) + 'A' + to_string(cows) + 'B';
        
    }
};