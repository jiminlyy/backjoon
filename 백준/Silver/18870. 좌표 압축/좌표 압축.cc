#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >>n;
    
    vector<int> arr;
    for(int i =0; i<n; i++){
        int k;
        cin >>k;
        arr.push_back(k);
    }
    vector<int> sorted = arr;
    sort(sorted.begin(), sorted.end());
    sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());
    
        for (int i = 0; i < n; i++) {
        cout << lower_bound(sorted.begin(), sorted.end(), arr[i]) - sorted.begin() << " ";
    }
}