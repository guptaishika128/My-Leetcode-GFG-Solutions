// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
  const int num[13] ={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    const string sym[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    
    string convertToRoman(int n) {
        // code here
         string ans = "";
       
        
      int i=12;    
    while(n>0)
    {
      int div = n/num[i];
      n = n%num[i];
      while(div--)
      {
        ans += sym[i];
      }
      i--;
    }  
    return ans;
    }
};

// { Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		Solution ob;
    	cout << ob.convertToRoman(N) << endl;
	}
	return 0;
}  // } Driver Code Ends