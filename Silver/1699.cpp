/*
    #백준1699 제곱수의 합(S2)
        - dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int INF = 987654321;
int n, dp[100005];
int main(void) {
    fill(dp, dp + 100005, INF);
    cin >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) {
            dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
    }
    cout << dp[n];
    return 0;
}