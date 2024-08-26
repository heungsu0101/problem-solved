/*
    #백준3679 단순 다각형(P4)
        - convex hull 문제
        - ccw를 이용해 가장 왼쪽 아래의 점을 기준으로 반시계방향으로 정렬한 후 
          한 직선상에 있을 경우, 첫번째 점으로부터 가까운 순으로 정렬을 했으므로 
          마지막 점에서 첫번째 점으로 연결할 때의 예외처리를 해주면 됨
*/
#include <iostream>
#include <algorithm>
#include <vector>
#define piii pair<int, pair<int, int>>
#define x second.first
#define y second.second
using namespace std;

int t, n;
vector<piii> v(2003);
bool isCheck(piii a, piii b) {
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
int ccw(piii a, piii b, piii c) {
    return a.x * b.y + b.x * c.y + c.x * a.y - (b.x * a.y + c.x * b.y + a.x * c.y);
}
bool cmp(piii a, piii b) {
    int _ccw = ccw(v[0], a, b);
    if (_ccw) return _ccw > 0;
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        v[0].first = 0;
        cin >> v[0].x >> v[0].y;
        for (int i = 1; i < n; i++) {
            v[i].first = i;
            cin >> v[i].x >> v[i].y;
            if (!isCheck(v[0], v[i])) swap(v[0], v[i]);
        }
        sort(v.begin() + 1, v.begin() + n, cmp);
        int i = n - 1;
        while (!ccw(v[0], v[i - 1], v[i])) i--;
        reverse(v.begin() + i, v.begin() + n);
        for (int i = 0; i < n; i++) cout << v[i].first << " ";
        cout << "\n";
    }
    return 0;
}