// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
     string str = "";
     string tmp="";
    for (int i  = 0 ; i<S.length(); i++){
     if(S[i] == '.'){
         tmp = "." + tmp;
         str = tmp + str;
         tmp = "";
     }
     else{
         tmp += S[i];
     }
     
     
    }
    if(tmp.size()!=0){
        str = tmp + str;
    }
    return str;
    } 
};

// { Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}  // } Driver Code Ends