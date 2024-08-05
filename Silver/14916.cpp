/*
    #백준14916 거스름돈(S5)
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, dp[100005];
int main(void) {
    cin >> n;
    dp[1] = -1; dp[2] = 1; dp[3] = -1; dp[4] = 2; dp[5] = 1; dp[6] = 3; dp[7] = 2; dp[8] = 4;
    for (int i = 9; i <= n; i++) dp[i] = dp[i - 5] + 1;
    cout << dp[n] << "\n";
    return 0;
}