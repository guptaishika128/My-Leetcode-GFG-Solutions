class Solution {
public:
    int solution(vector<string>& words, vector<int>& freq, vector<int>& score , int idx){
        
        if(idx == words.size()){
            return 0;
        }
        
        // If word says no
        int sno = 0 + solution(words,freq,score,idx+1);
        
        // If words says yes
        int scoreword = 0;
        bool flag = true;
        string word = words[idx];
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            
            if(freq[ch-'a'] == 0){
                flag = false;
            }
            freq[ch-'a']--;
            scoreword += score[ch - 'a'];
        }
        int syes = 0;
        if(flag){
            syes = scoreword + solution(words,freq,score,idx+1);
        }
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            freq[ch-'a']++;
        }
        return max(syes,sno);
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
       vector<int>freq(26,0);
        for(int i=0;i<letters.size();i++){
            freq[letters[i]-'a']++;
        }
        return solution(words,freq,score,0);
    }
};