#include <iostream>

using namespace std;

int main(){
    int line =0;
    int n;
    cin >> n;
    int sum =0;
    while(n>1){
        sum = sum +6;
        n = n -sum;
        line++;
    }
    line++;
    
    cout << line <<endl;
   
    
}