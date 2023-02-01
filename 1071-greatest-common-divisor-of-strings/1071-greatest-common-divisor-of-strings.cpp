class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
      /*  if(str2.length()>str1.length()){
            return gcdOfStrings(str2,str1);
        }
        else if(str1.find(str2)!=0){
            return "";
        }
        else if(str2 == ""){
            return str1;
        }
            return gcdOfStrings(str1.substr(str2.length()),str2);
            */

        return (str1+str2 == str2+str1) ? str1.substr(0,gcd(size(str1),size(str2))) : "";
    }
};