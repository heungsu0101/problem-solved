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
    sort(v.begin(), v.end());
    for (int _v : v) cout << _v << "\n";
    return 0;
}