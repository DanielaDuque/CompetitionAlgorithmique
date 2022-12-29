#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int combinationCoint(int N, int X, vector<int> coins){ 
    constexpr int M = 1e9 + 7;
    vector<int> dp(X + 1);
    dp[0] = 1;
    for (int i = 0; i < N; ++i) {
         int v = coins[i];
        for (int j = v; j <= X; ++j) {
            dp[j] += dp[j - v];
            if (dp[j] >= M) dp[j] -= M;
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