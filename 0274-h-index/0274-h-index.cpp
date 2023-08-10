class Solution {
public:
    int hIndex(vector<int>& citations) {
        // sort(citations.begin(),citations.end());
        // int n = citations.size();
//         int low = 0, high = n-1;
        
//         while(low<=high){
//             int mid = low+(high-low)/2;
//             if(citations[mid] == (n-mid)){
//                 return citations[mid];
//             } else if(citations[mid]>(n-mid)){
//                 high = mid-1;
//             } else{
//                 low = mid + 1;
//             }
//         }
//         return n-low;
        
        int n = citations.size();
        vector<int> count(n+1,0);
        
        for(int i:citations){
            count[min(n,i)]++;
        }
        
        int h = n;
        for(int s=count[n];h>s;s+=count[h]){
            h--;
        }
        return h;
    }
};