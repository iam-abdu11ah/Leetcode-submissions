class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> lookupTable;
        for(auto val : nums){
            if(lookupTable.find(val) != lookupTable.end()) return true;
            else lookupTable.insert(val);
        }
        return false;
    }
};