class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    int n = nums.size();
	list<int> ls;
	int j = 0 , i = 0; // i-> start ,  j->end
	
	while(j<n){
        while(!ls.empty() && ls.back()<nums[j]){
            ls.pop_back();
        }
        ls.push_back(nums[j]);
       
		if(j-i+1 < k){
			j++;
		}
		else if(j-i+1 == k){
			res.push_back(ls.front());
            if(ls.front() == nums[i])
                ls.pop_front();
			i++;
			j++;
		}
}
return res;
    }
};