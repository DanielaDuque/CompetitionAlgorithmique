#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int maxN = 1000;
const int INF = 0x3f3f3f3f;

int h[] = {1, -1, 0, 0};
int v[] = {0, 0, 1, -1};
int d[]= {'D', 'U', 'R', 'L'};
struct point { int x, y; };

int N, M, sx, sy;
bool vis[maxN][maxN];
char ans[maxN*maxN], c[maxN][maxN], p[maxN][maxN];
int d1[maxN][maxN], d2[maxN][maxN];
queue<point> Q;

point exitGoal ={-1, -1};

bool inbounds(int x, int y){
    return 0 <= x && x < N && 0 <= y && y < M;
}

void printsolution(int x, int y){
    int D = d2[x][y];
    // printf("YES\n%d\n", D);
    cout << "YES" << endl << D << endl;
    for(int i = D-1; i >= 0; i--){
        ans[i] = p[x][y];
        if(ans[i] == 'D')       x--;
        else if(ans[i] == 'U')  x++;
        else if(ans[i] == 'R')  y--;
        else if(ans[i] == 'L')  y++;
    }
    for(int i = 0; i < D; i++)
        // printf("%c", ans[i]);
        cout << ans[i];
    // printf("\n");
    cout << endl;
}

int main(){
    // scanf("%d %d", &N, &M);
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            // scanf(" %c", &c[i][j]);
            cin >> c[i][j];
            if(c[i][j] == '#')  vis[i][j] = true;
            else if(c[i][j] == 'M'){
                vis[i][j] = true;
                Q.push({i, j});
            } else if(c[i][j] == 'A'){
                sx = i; sy = j;
            }
        }
    }

    while(!Q.empty()){
        point P = Q.front(); Q.pop();
        for(int i = 0; i < 4; i++){
            int x = P.x + h[i];
            int y = P.y + v[i];
            if(inbounds(x, y) && !vis[x][y]){
                d1[x][y] = d1[P.x][P.y] + 1;
                vis[x][y] = true;
                Q.push({x, y});
            }
        }
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(!vis[i][j])  d1[i][j] = INF;
            vis[i][j] = (c[i][j] == '#');
        }
    }

    vis[sx][sy] = true;
    Q.push({sx, sy});
    while(!Q.empty()){
        point P = Q.front(); Q.pop();

        if(P.x== 0 || P.x == N-1 || P.y == 0 || P.y == M-1){
            if (d2[P.x][P.y] < d1[P.x][P.y]) { 
                exitGoal = P;
                break;
            }
        }
        for(int i = 0; i < 4; i++){
            int x = P.x + h[i];
            int y = P.y + v[i];
            if(inbounds(x, y) && !vis[x][y] && d2[P.x][P.y]+1 < d1[x][y]){
                p[x][y] = d[i];
                d2[x][y] = d2[P.x][P.y] + 1;
                vis[x][y] = true;
                Q.push({x, y});
            }
        }
    }

    if(exitGoal.x != -1)    printsolution(exitGoal.x, exitGoal.y);
    // else printf("NO\n");
    else cout << "NO" << endl;
    return 0;
}