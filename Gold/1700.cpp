#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int INF = 987654321;
int n, k, a[102], checked[102], ans;
vector<int> v;
int main(void) {
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        int cur = a[i];
        if (checked[cur]) continue;
        if (v.size() == n) { // 콘센트 뽑아야할 때
            int pos, pos_dist = 0;
            for (int _v : v) {
                int _v_dist = INF;
                for (int j = i + 1; j < k; j++) {
                    if (_v == a[j]) {
                        _v_dist = j; break;
                    }
                }
                if (pos_dist < _v_dist) {
                    pos_dist = _v_dist;
                    pos = _v;
                }
            }
            checked[pos] = 0;
            v.erase(find(v.begin(), v.end(), pos));
            ans++;
        }
        v.push_back(cur); checked[cur] = 1;
    }
    cout << ans << "\n";
    return 0;
}