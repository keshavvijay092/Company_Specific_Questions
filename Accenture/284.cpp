
#include <bits/stdc++.h>
using namespace std;
#define int long long

int dp[10][10][10][10][2];
int solve(int ind, int two, int four, int eight, int flag, string &s)
{
        if (ind == s.size())
        {
                if (two == four and eight == four and two != 0 and four != 0 and eight != 0)
                        return 1;
                else
                        return 0;
        }
        if (dp[ind][two][four][eight][flag] != -1)
                return dp[ind][two][four][eight][flag];
        int ans = 0;
        if (!flag)
        {
                for (int i = 0; i < s[ind] - '0'; i++)
                {
                        ans += solve(ind + 1, two + (i == 2), four + (i == 4), eight + (i == 8), 1, s);
                }
                ans += solve(ind + 1, two + ((s[ind] - '0') == 2), four + ((s[ind] - '0') == 4), eight + ((s[ind] - '0') == 8), 0, s);
        }
        else
        {
                for (int i = 0; i < 10; i++)
                {
                        ans += solve(ind + 1, two + (i == 2), four + (i == 4), eight + (i == 8), 1, s);
                }
        }
        return dp[ind][two][four][eight][flag] = ans;
}
int32_t main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n;
        cin >> n;
        memset(dp, -1, sizeof(dp));
        string s1 = to_string(n);
        cout << solve(0, 0, 0, 0, 0, s1) << endl;
        return 0;
}