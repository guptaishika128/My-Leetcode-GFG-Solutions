class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start] == -1){
            return false;
        }
        
        if(arr[start] == 0){
            return true;
        }
        
        int leftJump = start-arr[start];
        int rightJump = start+arr[start];
        
        arr[start] = -1;
        
        return (rightJump<arr.size() && canReach(arr,rightJump)) || (leftJump>=0 && canReach(arr,leftJump));
    }
};