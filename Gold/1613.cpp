/*
    #백준1613 역사(G3)
        - 플로이드 와샬 문제
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m, s, dist[402][402];

int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        dist[u][v] = -1;
        dist[v][u] = 1;
    }
    cin >> s;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (!dist[i][j]) {
                    if (dist[i][k] == 1 && dist[k][j] == 1) dist[i][j] = 1;
                    else if (dist[i][k] == -1 && dist[k][j] == -1) dist[i][j] = -1;
                }
            }
        }
    }
    while (s--) {
        int u, v; cin >> u >> v;
        cout << dist[u][v] << "\n";
    }
    return 0;
}