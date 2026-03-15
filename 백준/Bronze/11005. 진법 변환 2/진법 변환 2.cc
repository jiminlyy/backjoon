#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, b;
    cin >> n >> b;
    string result = "";

    while(n > 0){
        int r = n % b;

        if(r < 10)
            result = char('0' + r) + result;
        else
            result = char('A' + r - 10) + result;

        n /= b;
    }

    cout << result << endl;
}