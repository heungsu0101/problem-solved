/*
    #백준14464 소가 길을 건너간 이유 4(G1)
        - 그리디 문제
        - 정렬해서 문제해결하면 됨
        - multiset vs vector, array
            - multiset은 삽입, 삭제, 검색 등이 O(log n)의 시간복잡도 걸림
            - vector, array 등 선형적인 자료구조는 경우에 따라 다름
            - 해당 문제는 erase하는 과정이 있는데 이 부분에서 선형적인 자료구조를 사용할 경우 O(n)의 시간복잡도가 걸리므로
              multiset을 사용하여 보다 더 효율적으로 문제를 해결할 수 있음
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m, ans;
multiset<int> c;
vector<pair<int, int>> v;
bool cmp(const pair<int, int> a, const pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}
int main (void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        c.insert(tmp);
    }
    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < m; i++) {
        auto iter = c.lower_bound(v[i].second);
        if (iter != c.end() && *iter <= v[i].first) {
            c.erase(iter);
            ans++;
        }
    }
    cout << ans;
    return 0;
}