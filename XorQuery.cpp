#include <iostream>
using namespace std;

int main(){
//Scanner sc = new Scanner(System.in);
        int N; cin >> N;
        int Q;  cin >> Q;
        int sequence[N];
        int numbers[N+1];
        numbers[0] = 0;

        for (int i = 0; i < N; i++) {
            cin >> sequence[i];
            numbers[i+1] = numbers[i] ^ sequence[i];
        }

        for (int i = 0; i < Q; i++) {
            int lo; cin>> lo;
            int hi; cin>> hi;
            cout<< (numbers[lo-1]^numbers[hi]) << endl;
        }
        return 0;
}