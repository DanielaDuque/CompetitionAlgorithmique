//
// Created by daniela on 08/11/22.
//
#include <iostream>
#include <math.h>

using namespace std;

int main() {
    int N; cin >> N;
    int path[N][N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {

            // Reading Value
            char aux; cin >> aux;

            // Counting paths;
            if(aux == '*') path[i][j] = 0;
            else  {
                if (i == 0 && j == 0) path[i][j] = 1;
                else if(i == 0) {
                    path[i][j] = path[i][j-1];
                }
                else if(j==0){
                    path[i][j] = path[i-1][j];
                }
                else{
                    int mod = path[i][j-1] + path[i-1][j];
                    if( mod < 1000000007) path[i][j] = mod;
                    else path[i][j] = mod - 1000000007;
                }
            }
        }
    }
    // Giving answer;

    int sol = path[N-1][N-1];
    cout << sol << endl;
    return 0;
}