#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<string> people;

    for (int i = 0; i < n; i++) {
        string name, state;
        cin >> name >> state;

        if (state == "enter") {
            people.insert(name);
        } else {
            people.erase(name);
        }
    }
    //set은 오름차순으로 저장되기 때문에 
    //사전 역순으로 출력해야하기때문에 reverse begin
    // auto는 컴퓨터가 it의 자료형을 자동으로 정하겠다는 뜻. 
    for (auto it = people.rbegin(); it != people.rend(); it++) {
        cout << *it << '\n';
        //it는 값 자체가 아니라 가리키는 위치
    }
}