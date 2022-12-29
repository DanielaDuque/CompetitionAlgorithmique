#include <iostream>

using namespace std;

bool solve(int n){
    n += 1;
    while (n % 2 == 0)
        n /= 2;
    return (n != 1);
}


int main(){

    int N; cin >> N;
    while (N != 0)
    {
        /* code */
        if (solve(N)) cout << "Alice" << endl;
        else cout << "Bob" << endl;

        cin >> N;
    }
    
    return 0;
}