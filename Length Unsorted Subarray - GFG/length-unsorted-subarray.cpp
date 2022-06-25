// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> printUnsorted(int arr[], int n) {
	    vector<int> ans;
	    
	    int start = 0;
	    int end = 0;
	    
	    for(start=0;start<n-1;start++){
	        if(arr[start]>arr[start+1]){
	            break;
	        }
	    }
	    
	    if(start==n-1){
	       ans.push_back(0);
	       ans.push_back(0);
	       return ans;
	    }
	    
	    for(end=n-1;end>0;end--){
	        if(arr[end-1]>arr[end]){
	            break;
	        }
	    }
	    
	    int maxi = arr[start];
	    int mini = arr[start];
	    
	    for(int i=start+1;i<=end;i++){
	        if(arr[i]>maxi){
	            maxi = arr[i];
	        } 
	        if(arr[i]<mini){
	            mini =arr[i];
	        }
	    }
	    
	    for(int i=0;i<start;i++){
	        if(arr[i]>mini){
	            start = i;
	        }
	    }
	    
	    for(int i=n-1;i>=end+1;i--){
	        if(arr[i]<maxi){
	            end = i;
	        }
	    }
	    
	    ans.push_back(start);
	    ans.push_back(end);
	    return ans;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.printUnsorted(arr, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
  // } Driver Code Ends