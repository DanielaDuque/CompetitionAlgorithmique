#include <iostream>
#include <algorithm>
#include <limits.h>
#include <vector>


using namespace std;
int arr[1000][1000];
int N, M;
int posMin = -1;
int valueMin = 10000;
int longest = 10000;
int xA, yA, xB, yB;

int h[] = {1, -1, 0, 0}, v[] = {0, 0, 1, -1}, p[] = {'D', 'U', 'R', 'L'};

vector<string> paths;


void dfsAux(int x, int y, string path){
    arr[x][y] = 1;
    // cout<< path << " "  << x << " " << y<< endl;

    if (x == xB && y == yB){
        paths.push_back(path);
        arr[x][y] = 0;
        if (path.length() < valueMin){
            valueMin = path.length();
            posMin = paths.size() - 1;
            longest = path.length();
        }
        return;
    }
    for(int i = 0; i < 4; i ++){
        int nx = x + h[i];
        int ny = y + v[i];
        char c = p[i];
        if(path.length() > longest){
            arr[x][y] = 0;
            return;
        }
        if (nx >= 0 && nx < N && ny >= 0 && ny < M && arr[nx][ny] == 0){
            dfsAux(nx, ny, (path+c));
            arr[x][y] = 0;
        }
    }    
}

void dfs(int x, int y){
    dfsAux(x, y, "");
};

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
            if(c == 'A'){
                xA = i;
                yA = j;
            }
            if(c == 'B'){
                xB = i;
                yB = j;
            }
        }
    }
    // string path;
    dfs(xA, yA);

    // for(auto path : paths){  
    //     cout << path << endl;
    // }
    if(posMin == -1){
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << paths[posMin].length() << endl;
        cout << paths[posMin] << endl;
    }
    return 0;    
}