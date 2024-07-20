#include <iostream>
#include <algorithm>

using namespace std;

int l, r, a[100005], n;
long long ans;
bool checked[100005];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    while (r < n) {
        if (!checked[a[r]]) {
            checked[a[r]] = true;
            r++;
        } else {
            ans += (r - l);
            checked[a[l]] = false;
            l++;
        }
    }
    ans += 1ll * (r - l) * (r - l + 1) / 2;
    cout << ans << "\n";
    return 0;
}