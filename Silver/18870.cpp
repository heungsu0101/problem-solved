#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> v;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    vector<int> v2;
    v2 = v;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    for (int i = 0; i < n; i++) {
        auto p = lower_bound(v2.begin(), v2.end(), v[i]);
        cout << p - v2.begin() << " ";
    }
    return 0;
}