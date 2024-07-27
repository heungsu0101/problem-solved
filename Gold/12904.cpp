/*
    #백준12904 A와 B(G5)
        - 문자열 구현 문제
        - 단순히 A에 두가지 동작 중 하나를 하고자 한다면, 최악의 경우 2^1000이므로 말이 안됨
        - 이럴 때 역발상을 통해, A를 B로 만들려고 하지말고 B를 A로 만드는 것이 더 좋을 수 있음
        - 두 동작의 공통점은 마지막 행동에 문자 A 또는 B를 추가한다는 것임
        - 이로 인해 여러가지의 경우의 수가 발생하지 하고 그리디하게 문제를 해결할 수 있음
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string s, t;

int main(void) {
    cin >> s >> t;
    while (1) {
        if (s.size() == t.size()) {
            if (s == t) cout << "1\n";
            else cout << "0\n";
            break;
        }
        if (t[t.size() - 1] == 'A') {
            t.erase(t.size() - 1);
        } else {
            t.erase(t.size() - 1);
            reverse(t.begin(), t.end());
        }
    }
    return 0;
}