#include <iostream>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

int binarySearch(int a, vector<int> arr, int size ) {
    int l = 0;
    int r = size - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] == a) {
            return m;
        } else if (arr[m] < a) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return l;
}

int main(){
    
    int N; cin >> N;
    vector<int> arr;
    arr.push_back(INT_MAX);

    for (int i = 0; i < N; ++i) {
        int n; cin >> n;
        int smallest = binarySearch(n+1, arr, arr.size());
        if (arr[smallest] > n) {
            arr[smallest] = n;
        } else {
            arr.push_back(n);
        }
    }
    cout << arr.size() << endl;
    return 0;
};