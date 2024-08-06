/*
    #백준11051 이항 계수 2(S2)
        - dp를 이용한 이항 계수 문제
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, dp[1003][1003];
int go(int n, int k) {
    if (n == k || k == 0) return 1;
    int &ret = dp[n][k];
    if (ret) return ret;
    return ret = (go(n - 1, k - 1) + go(n - 1, k)) % 10007;
}
int main(void) {
    cin >> n >> k;
    cout << go(n, k);
    return 0;
}