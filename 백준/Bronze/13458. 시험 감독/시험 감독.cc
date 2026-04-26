#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int B, C;
    cin >> B >> C;

    long long answer = 0;

    for (int i = 0; i < N; i++) {
        // 총감독관 1명은 무조건 필요
        answer++;

        // 총감독관이 감시하고 남은 학생 수
        A[i] -= B;

        // 남은 학생이 있으면 부감독관 배치
        if (A[i] > 0) {
            answer += A[i] / C;

            if (A[i] % C != 0) {
                answer++;
            }
        }
    }

    cout << answer << '\n';

    return 0;
}