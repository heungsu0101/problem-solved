#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, ans;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    for (pair<int, int> cur : v) {
        ans += cur.second;
        pq.push(cur.second);
        while (pq.size() > cur.first) {
            ans -= pq.top(); pq.pop();
        }
    }
    cout << ans << "\n";
}