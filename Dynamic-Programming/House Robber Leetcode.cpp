class Solution {
public:
    
    int dp[402];
    int solve(int index, int n, vector<int>&nums)
    {
            if( index >= n) return 0;

            if(dp[index] != -1) return dp[index];

            int takenCurrentValue = nums[index] + solve(index+2, n, nums);
            int notTakenCurrentValue = solve(index+1, n, nums);

            return dp[index] = max(takenCurrentValue , notTakenCurrentValue);
            
    }
    
    int rob(vector<int>& nums) {
        
        int sizeOfNums = nums.size();
        
        for(int i = 0;i<sizeOfNums;i++) dp[i] = -1;
        
        return solve(0, nums.size(), nums);
    }
};
