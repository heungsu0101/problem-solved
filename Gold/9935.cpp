#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string s, p;
string ret;
int main(void) {
    cin >> s >> p;
    int p_size = p.size();
    for (int i = 0; i < s.size(); i++) {
        ret += s[i];
        if (ret.size() >= p_size && ret.substr(ret.size() - p_size, p_size) == p) {
            ret.erase(ret.size() - p_size, p_size);
        }
    }
    if (ret == "") cout << "FRULA\n";
    else cout << ret << "\n";
    return 0;
}