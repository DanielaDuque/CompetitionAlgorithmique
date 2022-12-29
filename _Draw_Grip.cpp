//
// Created by daniela on 22/11/22.
//

#include <iostream>
#include <math.h>



using namespace std;

int main() {
    int N; cin >> N;
    int path[N][N];
    int max[N][N];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            path[i][j] = -1;
            cin >> max[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == 0 && j == 0) path[i][j] = 1;
            else if(i == 0) {
                path[i][j] = path[i][j-1];
            }
            else if(j==0){
                path[i][j] = path[i-1][j];
            }
            else{
                int mod = path[i][j-1] + path[i-1][j];
                path[i][j] = mod;
            }

        }
    }
    // Giving answer;

    int sol = path[N-1][N-1];
    cout << sol << endl;
    return 0;
}