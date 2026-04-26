#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> nums;
int op[4]; 
// op[0] = +
// op[1] = -
// op[2] = *
// op[3] = /

int maxAnswer = -1000000000;
int minAnswer = 1000000000;

void dfs(int index, int current) {
    // 숫자를 N개 모두 사용한 경우
    if (index == N) {
        maxAnswer = max(maxAnswer, current);
        minAnswer = min(minAnswer, current);
        return;
    }

    // 덧셈
    if (op[0] > 0) {
        op[0]--;
        dfs(index + 1, current + nums[index]);
        op[0]++;
    }

    // 뺄셈
    if (op[1] > 0) {
        op[1]--;
        dfs(index + 1, current - nums[index]);
        op[1]++;
    }

    // 곱셈
    if (op[2] > 0) {
        op[2]--;
        dfs(index + 1, current * nums[index]);
        op[2]++;
    }

    // 나눗셈
    if (op[3] > 0) {
        op[3]--;
        dfs(index + 1, current / nums[index]);
        op[3]++;
    }
}

int main() {
    cin >> N;

    nums.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    dfs(1, nums[0]);

    cout << maxAnswer << '\n';
    cout << minAnswer << '\n';

    return 0;
}