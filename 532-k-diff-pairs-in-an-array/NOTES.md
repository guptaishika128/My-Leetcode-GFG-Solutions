TC - O(N)
SC- O(N)
unordered_map<int,int> mp;
for(int i: nums){
mp[i]++;
}
int count = 0 ;
for(auto it:mp){
if(k==0){
if(it.second>1){
count++;
}
}
else if(mp.find(it.first+k)!= mp.end()){
count++;
}
}
return count;