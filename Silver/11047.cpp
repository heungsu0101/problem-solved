/*
    #백준11047 동전0(S4)
        - 그리디 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, a[11], ans;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        while (k - a[i] >= 0) {
            k -= a[i];
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}