#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Elephant
{
    int w, iq, index;
    Elephant() {}
    bool operator<(const Elephant& e) const{
        return w < e.w;
    }
};
int main(){
    int w, iq;
    int cont = 0;
    vector<Elephant> elephants(1000,Elephant());

    // while (cin >> w >> iq){
    while(cont < 9){
        cin >> w >> iq;
        elephants[cont].w = w; elephants[cont].iq = iq; elephants[cont].index = cont +1;
        cont ++;
    }

    cout << "------------------" << endl;
    elephants.resize(cont);
    sort(elephants.begin(), elephants.end());

    int tallest = 0;
    vector<int> lis(cont,1);
    vector<int> prev(cont,-1);
    
    int ans = 1, index = 0;
    for (int i = 1; i < (int)elephants.size(); ++i) {
        int best_index = -1;
        for (int j = 0; j < i; ++j) {
            if (elephants[j].w != elephants[i].w &&
                elephants[j].iq > elephants[i].iq && 1 + lis[j] > lis[i]) {
                lis[i] = 1 + lis[j];
                best_index = j;
            }
        }
        prev[i] = best_index;
        if (lis[i] > ans) {
            ans = lis[i];
            index = i;
        }
    }

    stack<int> s;
    s.push(elephants[index].index);
    while (prev[index] != -1) {
        index = prev[index];
        s.push(elephants[index].index);

    }
    cout << ans << endl;
    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }  
    
    return 0;
}