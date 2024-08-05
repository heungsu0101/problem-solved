/*
    #백준2096 내려가기(G5)
        - dp문제
        - 이 문제의 경우 메모리제한이 4MB이므로 2차원 dp로 문제를 해결하면 메모리 초과가 발생함
        - i행마다 입력을 받을 떄 마다 tmp배열을 선언하여 i-1행에 대한 dp배열의 값을 저장하여 문제를 해결 할 수 있음
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int max_n = 100005;
const int INF = 987654321;
int n, dp1[3], dp2[3];
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    fill(dp2, dp2 + 3, INF);
    cin >> n;
    for (int i = 0; i < 3; i++) {
        int a; cin >> a;
        dp1[i] = a; dp2[i] = a;
    }
    for (int i = 1; i < n; i++) {
        int tmp1[3], tmp2[3];
        for (int j = 0; j < 3; j++) {
            tmp1[j] = dp1[j]; tmp2[j] = dp2[j];
        }
        int a, b, c; cin >> a >> b >> c;
        dp1[0] = a + max(tmp1[0], tmp1[1]);
        dp1[1] = b + max({tmp1[0], tmp1[1], tmp1[2]});
        dp1[2] = c + max(tmp1[1], tmp1[2]);
        dp2[0] = a + min(tmp2[0], tmp2[1]);
        dp2[1] = b + min({tmp2[0], tmp2[1], tmp2[2]});
        dp2[2] = c + min(tmp2[1], tmp2[2]);
    }
    cout << max({dp1[0], dp1[1], dp1[2]}) << " " << min({dp2[0], dp2[1], dp2[2]}) << "\n";
    return 0;
}