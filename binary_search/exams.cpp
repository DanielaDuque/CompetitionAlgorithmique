#include <iostream>
#include <vector>

using namespace std;

int solve_exams(int N, int M, int d[], int a[]){
    int count = 0;
    // This is a funtion that returns true if it is possible to do the exams in the given number of days
    auto possible = [&](int nb_days) {
        vector<int> positions(N);
        for (int i = 0; i < nb_days; ++i) {
            positions[d[i]] = i;
        }
        positions[0] = -1;

        int prep = 0;
        int nb_exams = 0;
        for (int i = 0; i < nb_days; ++i) {
            if (positions[d[i]] == i) {
                ++nb_exams;

                if (prep < a[d[i]])  return false;
                prep -= a[d[i]];
            }else{
                ++prep;
            }
        }
        return nb_exams == M;
    };

    // Binary search

    int l = 1;
    int r = N;  
    int res = -1;
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (possible(m)) {
            res = m;
            r = m -1;
        } else {
            l = m + 1;
        }

    }
    return res;
}

int main(){
    int N, M; cin >> N >> M;
    int d[N]; // exams days
    for (int i = 0; i < N; ++i) {
        cin >> d[i];
    }
    int a[M+1]; // preparation days
    for (int i = 1; i <= M; ++i) {
        cin >> a[i];
    }


    cout << solve_exams(N, M, d, a) << endl;
    return 0;
}