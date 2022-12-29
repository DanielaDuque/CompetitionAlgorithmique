#include    <iostream>
#include    <vector>
#include    <math.h>
#include    <algorithm>

using namespace std;

int combinationCoint(int N, int X, vector<int> coins){ 
    constexpr int M = 1e9 + 7;
    vector<int> dp(X + 1);
    dp[0] = 1;
    for (int i = 0; i < X; ++i) {
        for (int j = 0; j < N; ++j) {
            int v = coins[j] + i;
            if ( v > X) continue;
            dp[v] += dp[i];
            if (dp[v] >= M) dp[v] -= M;
        }
    }

    return dp[X];
}

int main() {

    int N; cin >> N;
    int X; cin >> X;

    vector<int> coins(N);
    for (int i = 0; i < N; ++i) {
        cin >> coins[i];
    }   

    cout<< combinationCoint(N, X, coins) << endl;

    return 0;
}