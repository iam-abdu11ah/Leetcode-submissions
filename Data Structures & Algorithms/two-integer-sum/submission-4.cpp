class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> nums_with_idx;
        for(int i=0; i<nums.size(); i++){
            nums_with_idx.push_back({nums[i], i});
            //nums_with_idx.emplace_back(nums[i], i);
            //nums_with_idx.push_back(make_pair(nums[i], i));
        }
        sort(nums_with_idx.begin(), nums_with_idx.end());
        int i=0, j=nums_with_idx.size()-1;
        while(i<j){
            int n1 = nums_with_idx[i].first;
            int n2 = nums_with_idx[j].first;
            if(n1+n2==target) 
                return {min(nums_with_idx[i].second, nums_with_idx[j].second),
                        max(nums_with_idx[i].second, nums_with_idx[j].second)};
            else if(n1+n2>target)
                j--;
            else
                i++;
        }

        return {};
    }
};
