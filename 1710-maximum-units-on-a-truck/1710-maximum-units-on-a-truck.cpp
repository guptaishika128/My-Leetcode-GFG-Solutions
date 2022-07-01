class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
      sort(boxTypes.begin(), boxTypes.end(), [](auto& box1, auto& box2) {
            return box1[1] > box2[1];
        });
        
        int totalUnits = 0;
        for (auto& box : boxTypes) {
            if(truckSize <= 0) break;                    // keep choosing greedily till you run out of truckSize 
		    totalUnits += min(truckSize, box[0]) * box[1]; // add (no of box * units) in that box
		    truckSize -= box[0];
        }
        return totalUnits;  
    }
};