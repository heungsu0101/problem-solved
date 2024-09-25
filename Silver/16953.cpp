/*
    #백준16953 A->B (S2)
        - queue를 이용해 그리디하게 문제를 해결
*/
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long n, m;
queue<pair<long long, int>> q;

int main(void) {
    cin >> n >> m;
    q.push({n, 1});
    while (q.size()) {
        pair<long long, int> cur = q.front(); q.pop();
        if (cur.first == m) {
            cout << cur.second; return 0;
        }
        if (cur.first * 2 <= m) q.push({cur.first * 2, cur.second + 1});
        if (cur.first * 10 + 1 <= m) q.push({cur.first * 10 + 1, cur.second + 1}); 
    }
    cout << -1;
    return 0;
}