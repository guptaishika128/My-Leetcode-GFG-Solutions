#include <bits/stdc++.h>
using namespace std;

string isValidOrNot(string &s){
    int zero  = 0;
	int one = 0;
	
	for(int i=0;i<s.length();i++){
	    if(s[i]=='0'){
	        zero++;
	    } else{
	        one++;
	    }
	    if(zero<one){
	        return "no";
	    }
	}
	return one==zero?"yes":"no";
}




int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin>>s;
	    cout << isValidOrNot(s) << endl;
	}
	return 0;
}