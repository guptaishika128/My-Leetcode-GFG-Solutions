class Solution {
public:
vector<int> binaryToDecimalVector(vector<string>& binaryVector) {
    vector<int> decimalVector;

    for (string& binaryString : binaryVector) {
        int decimalNumber = bitset<32>(binaryString).to_ulong(); // Assuming 32-bit integers
        decimalVector.push_back(decimalNumber);
    }

    return decimalVector;
}


vector<string> solve(int n){
    if(n==1){
        vector<string> bres;
        bres.push_back("0");
        bres.push_back("1");
        return bres;
    }
    
    vector<string> rres = solve(n-1);
    vector<string> mres;
    for(int i=0;i<rres.size();i++){
        string rstr = rres[i];
        mres.push_back("0"+rstr);
    }
    
    for(int i=rres.size()-1;i>=0;i--){
        string rstr = rres[i];
        mres.push_back("1"+rstr);
    }
    return mres;
}


    
    
    
    
    vector<int> grayCode(int n) {
        vector<string> res = solve(n);
        vector<int> decimalVector = binaryToDecimalVector(res);
        return decimalVector;
    }
};