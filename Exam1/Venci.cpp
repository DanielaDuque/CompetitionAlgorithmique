//
// Created by daniela on 22/11/22.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int R, S, K;
    cin >> R >> S >> K;

    char max[R][S];
    int posible[R][S];
    int posX=0;
    int posY=0;
    int maxValue=0;
    int desX = K - 2;
    int dexY = K - 2;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            cin >> max[i][j];
            posible[i][j] = 0;
            if(max[i][j] == '*'){

                cout << i <<  " " << j << endl;
                int minI = std::max(0, i-dexY);
                int minJ = std::max(0,j-desX);
                for (int k = minI; k <= i -1; ++k) {
                    for (int l = minJ; l < j; ++l) {
                        posible[k][l]++;
                        if(posible[k][l] > maxValue) {
                            cout << "change " << endl;
                            posX = l;
                            posY = k;
                            maxValue = posible[k][l];
                        }
                    }
                }
            }
        }
    }

    for (int i = posX; i < K; ++i) {
        if(i == posX || i == K-1) {
            max[posY][i] = '+';
            max[posY+K-1][i] = '+';

        }
        else {
            max[posY][i] = '-';
            max[posY+K-1][i] = '-';
        }
    }
    for (int i = posY+1; i < K-1; ++i) {

            max[i][posX] = '|';
            max[i][posX+K-1] = '|';

    }
//    cout << posY << " " << posX<< endl;
//    cout << posible[posY][posX] << endl;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < S; ++j) {
            cout << max[i][j];
        }
        cout << endl;
    }
    return 0;
}