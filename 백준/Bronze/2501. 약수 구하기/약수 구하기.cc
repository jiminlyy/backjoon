#include <iostream>

using namespace std;

int main(){
    int n,f;
    cin >> n>>f;
    int count =0;
    int number = 0;
    for (int i = 1; i<=n; i++){
        if(n%i == 0){
            count++;
            if(count == f){
                number = i;
            }
        }
        else{
            continue;
        }
    }
    cout << number << endl;
}