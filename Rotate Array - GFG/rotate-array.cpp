#include <iostream>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T--){
	    int n;
	    cin>>n;
	    int d;
	    cin >> d;
	    int arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    for(int i=d;i<n;i++){
	        cout<<arr[i]<<" ";
	    }
	    for(int i=0;i<d;i++){
	        cout<<arr[i]<<" ";
	    }
	    cout << endl;
	}
}