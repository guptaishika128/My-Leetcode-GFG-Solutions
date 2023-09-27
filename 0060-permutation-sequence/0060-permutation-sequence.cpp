class Solution {
public:
    string getPermutation(int n, int k) {
        int fact = 1;
        vector<int> numbers;
        // Assume n = 4 && k = 17
        for(int i=1;i<n;i++){
            fact = fact*i;  // fact = 1*2*3 = 3! = 6
            numbers.push_back(i); 
        }
        numbers.push_back(n); // numbers = [1 2 3 4]
        string ans = "";
        k--; // Converting to 0-based indexing k = 16
        
        while(true){
            ans = ans + to_string(numbers[k/fact]); // (k/fact = 2 , 2, 0 , 0) "3412"
            numbers.erase(numbers.begin() + k/fact); // numbers = []
            if(numbers.size() == 0){
                break; // Now break "3412"
            }
            k = k%fact; // k = 16%6 , 4%2 = 4 , 0 , 0
            fact = fact/numbers.size(); // fact = 6/3 = 2/2 = 1/1 = 1
        }
        return ans;
    }
};