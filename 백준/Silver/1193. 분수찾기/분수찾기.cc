#include <iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    int line = 1;
    int sum = 0;

    while (sum < X) {
        sum += line;
        line++;
    }

    line--;  
    int prevSum = sum - line;   
    int pos = X - prevSum;      

    int numerator, denominator;

    if (line % 2 == 0) {  
        numerator = pos;
        denominator = line - pos + 1;
    } else {  
        numerator = line - pos + 1;
        denominator = pos;
    }

    cout << numerator << "/" << denominator << endl;

    return 0;
}