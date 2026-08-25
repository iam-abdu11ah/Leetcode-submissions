class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;

        while(l<=r){
            int m=(l+r)/2;
            if(nums[m]==target) return m;
            else if(nums[m] < target){
                l=m+1;
            }else{
                r=m-1;
            }
        }

        return -1;
    }
};


/*
0   1   2   3   4   5
-1  0   2   4   6   8
l       m           r
            l       r
                m
                
*/