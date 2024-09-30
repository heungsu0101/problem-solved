/*
    #백준2225 합분해(G5)
        - dp문제
        - dp[k][n] = k개의 정수를 이용해서 합이 n인 경우의 수(순열)
        - dp[i][j] = dp[i - 1][0] + dp[i - 1][1] + ... + dp[i - 1][j] = dp[i - 1][j] + dp[i][j - 1];
            - ex) dp[3][3] = {(2개를 이용해서 합이 0) + 3} + {(2개를 이용해서 합이 1) + 2} + {(2개를 이용해서 합이 2) + 1}
                            + {(2개를 이용해서 합이 3) + 0}
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int mod = 1000000000;
int_fast32_t dp[202][202], n, k;
int main(void) {
    cin >> n >> k;
    for (int i = 0; i <= n; i++) {
        dp[1][i] = 1;
    }
    for (int i = 2; i <= k; i++) {
        dp[i][0] = 1;
    }
    for (int i = 2; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
        }
    }
    cout << dp[k][n];

    return 0;
}