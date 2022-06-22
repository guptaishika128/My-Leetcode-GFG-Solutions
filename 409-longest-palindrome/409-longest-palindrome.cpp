class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> m;

 		for(int i = 0; i < s.size(); i++) {
 			m[s[i]]++;
 		}

 		int len = 0, diff = 0;
 		for(auto &x: m) {
 			if(x.second % 2 == 0) {
 				len += x.second;
 			} else {
 				len += (x.second -1);
 				diff++;
 			}
 		}
 		if(diff > 0) len++;
 		return len;
    }
};