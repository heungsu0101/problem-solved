#include <iostream>
#include <algorithm>

using namespace std;

int a[101];
long long dp[101][23], n;
long long go(int idx, int sum) {
    if (sum < 0 || sum > 20) return 0;
    if (idx == n - 1) {
        if (sum == a[n - 1]) return 1;
        else return 0;
    }
    long long &ret = dp[idx][sum];
    if (ret != -1) return ret;
    ret = 0;
    ret += go(idx + 1, sum + a[idx]) + go(idx + 1, sum - a[idx]);
    return ret;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(&dp[0][0], &dp[0][0] + 101 * 23, -1);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << go(1, a[0]);
    return 0;
}