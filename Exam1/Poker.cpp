//
// Created by daniela on 22/11/22.
//
#include <iostream>
#include <math.h>
#include <string>

using namespace std;

int main() {
    int max[14];
    for (int i = 0; i < 14; i++){
        max[i] = 0;
    }

    int maxValue = 0;
    for (int i = 0; i < 5; i++){
        string message; cin >> message;
        char card = message[0];
        int pos = 0;
        if(card == 'A') pos = 1;
        else if(card == 'T') pos = 10;
        else if(card == 'J') pos = 11;
        else if(card == 'Q') pos = 12;
        else if(card == 'K') pos = 13;
        else pos = (int)card;

        max[pos] += 1;
        if(maxValue == 4) break;
        if(maxValue < max[pos]) maxValue = max[pos];
    }
    cout << maxValue<< endl;

    return 0;
}