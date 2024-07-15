#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        bool flag = true;
        unordered_set<string> _set;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < n; i++) {
            string tmp = "";
            for (int j = 0; j < v[i].size() - 1; j++) {
                tmp += v[i][j];
                if (_set.find(tmp) != _set.end()) {
                    flag = false; break;
                }
            }
            if (!flag) break;
            else _set.insert(v[i]);
        }
        if (flag) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}