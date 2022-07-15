// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int isdivisible7(string num){
        //complete the function here
        int hasil=0;
       for(int i=0;i<num.size();i++)
       {
           string s=to_string(hasil)+num[i];
           hasil=stoi(s)%7;        
       }
       return hasil==0?1:0;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isdivisible7(s) << endl;
    }
    return 0;
}  // } Driver Code Ends