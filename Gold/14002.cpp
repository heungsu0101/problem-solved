/*
    #백준14002 가장 긴 증가하는 부분 수열 4(G4)
        - lis 문제
        - 이전 문제들과 같고 lis를 출력할 때, len를 기준으로 역추적하여 문제를 해결하면 됨.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;
int n, a[1003], lis[1003], pos[1003], len;
vector<int> ans;
void go() {
    for (int i = 0; i < n; i++) {
        int idx = lower_bound(lis, lis + len, a[i]) - lis;
        if (lis[idx] == INF) len++;
        lis[idx] = a[i];
        pos[i] = idx;
    }
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(lis, lis + 1003, INF);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    go();
    cout << len << "\n";
    int idx = n - 1;
    while (len > 0 && idx >= 0) {
        if (len - 1 == pos[idx]) {
            ans.push_back(a[idx]);
            len--;
        }
        idx--;
    }
    reverse(ans.begin(), ans.end());
    for (int it : ans) cout << it << " ";
    return 0;
}