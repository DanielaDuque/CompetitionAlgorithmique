#include <iostream>
#include <vector>
#include <math.h>
#include <queue>

using namespace std;


int main(){
    int T; cin >> T;

    for(int t = 0; t < T; t++){
        int N; cin >> N;
        int M; cin >> M;

        // save the light the interruptor M can change
        int change[105];

        for (int i = 0; i < M; i++)
        {
            change[i] = 0;
            for (int j = 0; j < N; j++)
            {
                int a; cin >> a; 
                // bit operation to save the light j that the interruptor i can change
                // change[i] |= a << j;
                change[i] |= a << (N-j-1); }
        }
        queue<int> q;

        q.push((1<<N) -1);
        int step[65536] = {};

        // All the light on, one step
        step[(1<<N)-1] = 1;


        // step[0] all light  off
        while(!q.empty() && step[0] == 0){
            int state = q.front(); q.pop();
            for (size_t i = 0; i < M; i++)
            {
                int next = state ^ change[i];
                if(step[next] == 0){
                    step[next] = step[state] + 1;
                    q.push(next);
                }
            }
        }

        cout << "Case " << t+1 << ": ";
        if(step[0]==0){
            cout <<"IMPOSSIBLE" << endl;
        }else{
            // delete the first step to turn on all the light
            cout << step[0] -1 << endl;
        }
        
    }    
    return 0;
}