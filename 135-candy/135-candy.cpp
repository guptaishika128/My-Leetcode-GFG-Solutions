class Solution {
public:
    int candy(vector<int>& ratings) {
       /* int n = ratings.size();
        vector<int> res(n,1);
        
        if(ratings[0]>ratings[1]){
            res[0]++;
        }
        for(int i=1;i<n-1;i++){
            if(ratings[i-1]<ratings[i] || ratings[i]>ratings[i+1]){
                res[i]++;
            }
        }
        if(ratings[n-1]>ratings[n-2]){
            res[n-1]++;
        }
        int sum = 0;
        for(int i=0;i<n;i++){
            sum += res[i];
        }
        return sum;
        */ int n = ratings.size();
    
    vector<int> left(n,1);
    vector<int> right(n,1);
    
    
    for(int i=1;i<n;i++)
    {
        if(ratings[i] > ratings[i-1])
        {
            left[i] = left[i-1]+1;
        }
           
    }
    
    for(int i=n-2;i>=0;i--)
    {
        if(ratings[i] > ratings[i+1])
        {
            right[i] = right[i+1]+1;
  
        }
    }
    
    int total = 0;
    
    for(int i=0;i<n;i++)
    {
        total += max(left[i],right[i]);
    }
    
         return total;
    }
    
};