class Solution {
public:
    int solve(int n, vector<int>& dp) {
        // Base cases
        if (n <= 0) return 0;
        if (n == 1) return 1;
        if (n == 2) return 2;

        // If already computed, return the stored result
        if (dp[n] != -1) return dp[n];

        // Recursive calls to calculate the number of ways to climb
        return (dp[n] = solve(n - 2, dp) + solve(n - 1, dp));
    }

    int climbStairs(int n) {
        // Initialize the dp vector with -1
        vector<int> dp(n + 1, -1);
        // Call the recursive solve function
        return solve(n, dp);
    }
};
