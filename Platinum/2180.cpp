/*
    #백준2180 소방서의 고민(P5)
        - 그리디 문제
        - b / a의 값을 비교하여 정렬해야함
        - 기울기만 고려하여 정렬을 했을 경우, 반례가 생김
            ex) 100t + 100, 99t + 1이 있을 경우, 기울기만 고려하면 첫번째를 먼저 해결할 것이다.
                그럴 경우, 2번쨰를 해결할 때는 이미, t가 100인 상태이므로 값이 너무나 커진다.
                그 반대로 상수도 같이 고려할 경우, 두번째를 먼저 해결하면 답은 201로 최적해를 구할 수 있게 된다.
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    return b.first * a.second < a.first * b.second;
}
const int mod = 40000;
long long ans;
int n;
vector<pair<int, int>> v1;
vector<int> v2;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        if (b == 0) continue;
        else if (a == 0) {
            v2.push_back(b); continue;
        }
        v1.push_back({a, b});
    }
    sort(v1.begin(), v1.end(), cmp);
    for (pair<int, int> _v : v1) {
        ans += _v.first * ans + _v.second;
        ans %= mod;
    }
    for (int _v : v2) {
        ans += _v; ans %= mod;
    }
    cout << ans;
}