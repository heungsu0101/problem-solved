/*
    #백준11055 가장 큰 증가하는 부분 수열(S2)
        - dp문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1003], dp[1003], ans;
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) dp[i] = a[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) dp[i] = max(dp[i], dp[j] + a[i]);
        }
    }
    sort(dp, dp + n);
    cout << dp[n - 1] << "\n";
    return 0;
}