class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int M = 1e9 + 7;
        int n = nums.size();

        unordered_map<long long, long long> leftFreq, rightFreq;

        // Step 1: Put everything in rightFreq
        for (int i = 0; i < n; i++) {
            rightFreq[nums[i]]++;
        }

        long long answer = 0;

        // Step 2: Process each index j
        for (int j = 0; j < n; j++) {

            long long val = nums[j];

            // Remove nums[j] from right side (j cannot be k)
            rightFreq[val]--;

            long long target = val * 2;

            long long countLeft  = leftFreq[target];   // nums[i] == 2 * nums[j]
            long long countRight = rightFreq[target];  // nums[k] == 2 * nums[j]

            answer = (answer + (countLeft * countRight) % M) % M;

            // Add nums[j] to the left side (usable as i)
            leftFreq[val]++;
        }

        return answer;
    }
};
