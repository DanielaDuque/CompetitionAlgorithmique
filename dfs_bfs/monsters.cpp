
#include <iostream>
#include <map>
#include <queue>
#include <stack>

using namespace std;
typedef pair<int,int> pii;

pii operator-(const pii& p1, const pii& p2) {
    return {p1.first - p2.first, p1.second - p2.second};
}
pii operator+(const pii& p1, const pii& p2) {
    return {p1.first + p2.first, p1.second + p2.second};
}


#define x first
#define y second

map<pii, string> delta2string {{{-1, 0}, "U"}, {{1, 0}, "D"}, {{0, -1}, "L"}, {{0,1}, "R"}};

bool vis[1000][1000];
char c, par[1000][1000], ans[1000000];
int N, M, sx, sy, ex, ey, dist[1000][1000];
pii exitGoal = {-1, -1};

const int INF = 1e9;
queue<pii> q1, q2;
vector<pii> exits;

void bfsMoster (queue<pii>& q, vector<vector<int>>& m, map<pii, pii>& prev) {
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        for (auto delta : vector<pii>{{0,-1},{0,1},{-1,0},{1,0}}) {
            pii nxt = cur + delta;
            if (nxt.first >= 0 && nxt.first < N && nxt.second >= 0 && nxt.second < M &&
                !vis[nxt.first][nxt.second] && m[nxt.first][nxt.second] == INF) {
                q.push(nxt);
                m[nxt.first][nxt.second] = m[cur.first][cur.second] + 1;
                prev[nxt] = cur; // We keep track here from where we came
            }
        }
    }
};

void bfsUS (queue<pii>& q, vector<vector<int>>& us, map<pii, pii>& prev, vector<vector<int>>& monsters) {
    while (!q.empty()) {
        pii cur = q.front(); q.pop();
        if(cur.first== 0 || cur.first == N-1 || cur.second == 0 || cur.second == M-1){
            if (us[cur.first][cur.second] < monsters[cur.first][cur.second]) { 
                exitGoal = cur;
                break;
            }
        }
        for (auto delta : vector<pii>{{0,-1},{0,1},{-1,0},{1,0}}) {
            pii nxt = cur + delta;
            if (nxt.first >= 0 && nxt.first < N && nxt.second >= 0 && nxt.second < M &&
                !vis[nxt.first][nxt.second] && us[nxt.first][nxt.second] == INF) {
                q.push(nxt);
                us[nxt.first][nxt.second] = us[cur.first][cur.second] + 1;
                prev[nxt] = cur; // We keep track here from where we came
            }
        }
    }
};

int main(){
    cin >> N >> M;
    vector<vector<int>> monsters(N, vector<int>(M, INF));
    vector<vector<int>> us(N, vector<int>(M, INF));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> c;
            if(c == '#')  vis[i][j] = true;
            else if(c == 'A'){
                us[i][j] = 0;
                q2.emplace(i, j);
                sx = i; sy = j;
            }
            else if(c == 'M'){
                monsters[i][j] = 0;
                q1.emplace(i, j);
            }

            // If we are on the edge, we need to store the exit
            // if (i == 0 || j == 0 || i == N - 1 || j == M - 1) {
            //     if (c != '#') {
            //         exits.push_back({i, j});
            //     }
            // }
            
        }
    }

    map<pii, pii> prev1, prev2;
    bfsMoster(q1, monsters, prev1);
    bfsUS(q2, us, prev2, monsters);
    if(exitGoal.x != -1){
        cout << "YES\n";
        stack<string> path;
        pii cur = exitGoal;
        while (prev2.count(cur)) {
            pii nxt = prev2[cur];
            path.push(delta2string[cur - nxt]);
            cur = nxt;
        }
        cout << path.size() << '\n';
        while (!path.empty()) {
            cout << path.top();
            path.pop();
        }
        return 0;
    }
    // for (pii e : exits) {
    //     if (us[e.first][e.second] < monsters[e.first][e.second]) { // We can reach an exit faster than any monster
    //         cout << "YES\n";
    //         stack<string> path;
    //         pii cur = e;
    //         while (prev2.count(cur)) {
    //             pii nxt = prev2[cur];
    //             path.push(delta2string[cur - nxt]);
    //             cur = nxt;
    //         }
    //         cout << path.size() << '\n';
    //         while (!path.empty()) {
    //             cout << path.top();
    //             path.pop();
    //         }
    //         return 0;
    //     }
    // }
cout << "NO\n";
    return 0;
}