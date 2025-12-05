class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr;
        int total = 0;
        int st =0;
        for(int i=0;i<n;i++){
            total += nums[i];
        }
        for(int i=0;i<n;i++){
            int store = (nums[i]+st)-(total-nums[i]);
            st += nums[i];
            total -= nums[i];
            if(store%2==0){
                arr.push_back(store);
            }else{
                return 0;
            }
        }
        return arr.size()-1;
    }
};