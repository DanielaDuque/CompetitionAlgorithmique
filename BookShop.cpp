//
// Created by daniela on 08/11/22.
//
#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int N; cin >> N;
    int X; cin >> X;
    int price[N+1];
    int pages[N+1];
    int matrix[N+1][X+1];

    price[0]=0;
    pages[0] = 0;
    for (int i = 1; i < N+1; ++i) {
        cin >>price[i];
        matrix[i][0] = 0;
    }

    for (int i = 1; i < N+1; ++i) {
        cin >>pages[i];
    }

    // Calcule value optimal
    matrix[N][0] = 0;
    for (int i = 0; i < X + 1; ++i) {
        matrix[0][i] = 0;
    }

    for (int i = 1; i < N+1; ++i) {
        for (int j = 1; j < X+1; ++j) {
            // Special for the first line
            if(i == 1){
                if (price[i] > j) matrix[i][j] = 0;
                else{
                    matrix[i][j] = pages[i];
                }
            }
            // From second line to the end
            else{
                if (price[i] > j) matrix[i][j] = matrix[i-1][j];
                else{
                    matrix[i][j] = max(matrix[i-1][j], pages[i] + matrix[i-1][j-price[i]]);
                }
            }
        }
    }

    // Giving Answer
    cout << matrix[N][X] << endl;

    return 0;
}