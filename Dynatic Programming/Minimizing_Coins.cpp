#include <iostream>
#include <vector>
#include <climits>
using namespace std;
#define mod 1000000007
#define smallProblemUndefined 1000000000

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    vector<int> dp(k + 1, -1);
    dp[0] = 0;

    for (int &coin : coins) {
        cin >> coin;
    }

    for (int i = 1; i <= k; i++) {
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            int smallProblem = smallProblemUndefined;
            if (i - coins[j] >= 0) {
                smallProblem = dp[i - coins[j]] % mod;
            }
            ans = min((smallProblem + 1) % mod, ans);
        }
        dp[i] = ans;
    }

    cout << ((dp[k] >= smallProblemUndefined) ? -1 : dp[k]) << endl;

    return 0;
}