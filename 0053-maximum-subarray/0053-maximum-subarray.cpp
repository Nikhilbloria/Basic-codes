class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        //             if(n==1){
        //     return nums;
        // }
        int maxi = nums[0];
        int current = nums[0];
        for(int i=1;i<n;i++){
             current = max(nums[i],current+nums[i]);
             maxi = max(maxi,current);
        }return maxi;
    }
};