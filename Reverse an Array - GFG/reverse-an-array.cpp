#include <iostream>
using namespace std;

int main() {
	//code
		int T;
	cin >> T;
	int n;
	
	while(T--){
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin >> arr[i];
	    }
	    int start = 0;
	    int end = n-1;
	    while(start<end){
	   int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
	    }
        for(int i=0;i<n;i++){
            cout << arr[i]<<" ";
        }
        cout << endl;
}
	return 0;
}