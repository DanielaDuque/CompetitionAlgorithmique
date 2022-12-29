#include <iostream>
using namespace std;

int main(){
//Scanner sc = new Scanner(System.in);
        int N; cin >> N;
        int Q;  cin >> Q;
        int sequence[N][N];
        int NN = N+1;
        int numbers[NN][NN];

        for (int i = 0; i < NN; i++) {
            numbers[i][0] = 0;
            numbers[0][i] = 0;
        }
        for (int i = 0; i < N; i++) {
            for (int j = 0; j<N; j++){
                char aux ; cin >> aux;
                if(aux =='.') sequence[i][j] = 0;  else sequence[i][j] = 1;
                numbers[i+1][j+1] = numbers[i+1][j] + numbers[i][j+1] - numbers[i][j] + sequence[i][j];
            }
        }

        for (int i = 0; i < Q; i++) {
            int y1; cin>> y1;
            int x1; cin>> x1;
            int y2; cin>> y2;
            int x2; cin>> x2;
            int sum = numbers[y2][x2] - numbers[y1-1][x2] - numbers[y2][x1-1];
            cout <<  sum << endl;
        }
        return 0;
}