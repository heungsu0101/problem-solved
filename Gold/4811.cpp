/*
    #백준4811 알약
        - dp문제
        - 한개짜리를 꺼냈는지, 반개짜리를 꺼냈는지에 따라 top-down방식으로 문제를 해결할 수 있음
*/
#include <iostream>
#include <algorithm>

using namespace std;

long long n, dp[31][62];
long long go(int w, int h) {
    if (w == 0 && h == 0) return 1;
    long long &ret = dp[w][h];
    if (ret) return ret;
    if (w > 0) ret += go(w - 1, h + 1);
    if (h > 0) ret += go(w, h - 1);
    return ret;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << go(n, 0) << "\n";
    }

    return 0;
}