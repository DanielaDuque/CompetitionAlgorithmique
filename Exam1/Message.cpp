//
// Created by daniela on 22/11/22.
//
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        string message; cin >> message;
        int len = message.length();
        int maxSize = sqrt(len);
        int acm = 0;
        for (int j = maxSize -1; j >= 0; --j) {
            for (int k = 0; k < maxSize; ++k) {
                int pos = j + maxSize*k;
                if(acm >= len) return 0;
                else cout<<message[pos];
                acm++;
            }
        }
        cout << endl;
    }

    return 0;
}