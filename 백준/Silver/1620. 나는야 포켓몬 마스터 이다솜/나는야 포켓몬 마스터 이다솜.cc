#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<string> pokemon(n + 1);
    unordered_map<string, int> dict;

    for (int i = 1; i <= n; i++) {
        cin >> pokemon[i];
        dict[pokemon[i]] = i;
    }

    for (int i = 0; i < m; i++) {
        string quiz;
        cin >> quiz;

        if (isdigit(quiz[0])) {
            int num = stoi(quiz);
            cout << pokemon[num] << '\n';
        } else {
            cout << dict[quiz] << '\n';
        }
    }

    return 0;
}