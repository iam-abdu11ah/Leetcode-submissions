class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        for(int i=0; i<nums.size(); i++){
            int n1 = nums[i];
            int n2 = target-n1;
            if(lookup.find(n2) != lookup.end()){
                return {lookup[n2], i};
            }
            lookup[nums[i]] = i;
        }
        return {};
    }
};
