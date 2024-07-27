/*
    #백준5670 휴대폰 자판(P4)
        - 문자열 trie 문제 
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

struct node{
    bool end = false;
    map<char, node> child;
};
void insert(node &nd, string s, int idx) {
    if (idx == s.size()) {
        nd.end = true; return;
    }
    if (!nd.child.count(s[idx])) nd.child[s[idx]] = node();
    insert(nd.child[s[idx]], s, idx + 1);
}
int dfs(node &nd, string s, int idx) {
    if (idx == s.size()) return 0;
    else if (idx == 0 || nd.child.size() > 1) return dfs(nd.child[s[idx]], s, idx + 1) + 1;
    else if (nd.end) return dfs(nd.child[s[idx]], s, idx + 1) + 1;
    else return dfs(nd.child[s[idx]], s, idx + 1);
}
int main(void) {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    while (cin >> n) {
        double ans = 0;
        node root;
        vector<string> v;
        for (int i = 0; i < n; i++) {  
            string s; cin >> s;
            v.push_back(s);
            insert(root, s, 0);
        }
        for (string _v : v) {
            ans += dfs(root, _v, 0);
        }
        cout << fixed;
        cout.precision(2);
        cout << ans / n << "\n";
    }
    return 0; 
}