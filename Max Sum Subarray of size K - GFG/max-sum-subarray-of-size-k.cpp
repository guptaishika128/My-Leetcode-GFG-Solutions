// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        // code here 
        if(K==0 || N==0){
            return 0;
        }
        
        long int max_sum = INT_MIN;
        long int start = 0 ,curr_sum = 0;
        
        for(int end = 0;end<N;end++){
            curr_sum += Arr[end];
        
            if(end-start+1 == K){
                max_sum = max(max_sum, curr_sum);
                curr_sum -= Arr[start];
                start++;
            }
    }
    return max_sum; 
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N,K;
        cin >> N >> K;;
        vector<int>Arr;
        for(int i=0;i<N;++i){
            int x;
            cin>>x;
            Arr.push_back(x);
        }
        Solution ob;
        cout << ob.maximumSumSubarray(K,Arr,N) << endl;
    }
    return 0; 
}   // } Driver Code Ends