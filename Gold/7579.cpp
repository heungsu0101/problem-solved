/*
    #백준7579 앱(G3)
        - dp 냅색문제
        - 일단 문제를 보면 냅색문제인건 알겠는데, 일반적인 냅색문제처럼 풀고자 한다면 막히는 부분이 두가지가 있음
            1. 시간복잡도 초과
                - 시간복잡도가 O(n * m)이므로 너무나도 큰 시간이 걸림
            2. dp 배열 값 할당문제
                - dp 배열에 값을 할당하고자 하는데, min값을 넣어줘야하는데 이 부분 역시 문제가 생김
        - 위의 문제점들이 있을 때 dp배열에 답(비용)을 넣는 것이 아닌 확보할 수 있는 메모리 값의 최댓값을 넣고
          답을 구할 때 dp[n][비용]을 for문을 돌려 해당 dp값이 m보다 클 경우, 답으로 출력하면 됨.
        - 이와 같이 일반적인 냅색문제와 다르게, 역발상을 통해 무조건 dp에 최적해를 담아야한다는 고정관념을 깰 수 있는 문제라고 생각됨.
*/
#include <iostream>
#include <algorithm>

using namespace std;

int n, m, a[101], c[101], dp[101][10001], sum;
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
        sum += c[i];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = sum; j >= 0; j--) {
            if (j - c[i] >= 0) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - c[i]] + a[i]);
            } else dp[i][j] = dp[i - 1][j];
        }
    }
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i] >= m) {
            cout << i << "\n";
            break;
        }
    }
}