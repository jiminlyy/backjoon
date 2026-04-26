#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> T(N + 1);
    vector<int> P(N + 1);
    vector<int> dp(N + 2, 0);

    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    for (int i = N; i >= 1; i--) {
        int nextDay = i + T[i];

        // 상담을 퇴사 전까지 끝낼 수 있는 경우
        if (nextDay <= N + 1) {
            dp[i] = max(P[i] + dp[nextDay], dp[i + 1]);
        }
        // 상담을 못 하는 경우
        else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << '\n';

    return 0;
}