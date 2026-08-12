class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> lookupTable;
        for(auto n : nums){
            if(lookupTable.count(n)>0) return true;
            lookupTable.insert(n);
        }
        return false;
    }
};