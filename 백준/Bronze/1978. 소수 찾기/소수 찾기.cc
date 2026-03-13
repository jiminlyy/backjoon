#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int count = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        int isPrime = 1;
        if(x == 1) isPrime = 0;

        for(int j = 2; j < x; j++){
            if(x % j == 0){
                isPrime = 0;
                break;
            }
        }

        if(isPrime) count++;
    }

    cout << count << endl;
    return 0;
}