class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> lookup;
        int i, n1, n2;
        vector<int> res;
        for(i=0; i<nums.size(); i++){
            n1 = nums[i];
            n2 = target-n1;
            if(lookup.find(n2) != lookup.end()){
                res.push_back(lookup[n2]);
                res.push_back(i);
            }
            lookup[nums[i]] = i;
        }
        return res;
    }
};
