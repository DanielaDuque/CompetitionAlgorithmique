#include <iostream>
#include <algorithm>
#include <limits.h>


using namespace std;
int arr[1000][1000];
int N, M;

int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1};


void dfs(int x, int y ){
    arr[x][y] = 1;
    for(int i = 0; i < 4; i ++){
        int nx = x + h[i];
        int ny = y + v[i];
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0){
            dfs(nx, ny);
        }
    }
}

int main() {
    std::cin >> N;
    std::cin >> M;

    int count = 0;
    for(int i = 0; i < N ; i ++){
        for (int j = 0; j < M; ++j) {
            char c;
            std::cin >> c;
            if (c == '#'){
                arr[i][j] = 1;
            } else {
                arr[i][j] = 0;
            }
        }
    }
    
    for(int i = 0; i < N ; i ++){
        for (int j = 0; j < M; ++j) {
            if(arr[i][j] == 0){
                dfs(i, j);
                count ++;
            }
        }
    }

    cout << count << endl;          
    return 0;    
}