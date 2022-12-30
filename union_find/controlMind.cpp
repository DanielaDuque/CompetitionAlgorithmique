#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Class Union Find
class union_find {
    private:
    vector<int> id; // id[i] = parent of i
    vector<int> sz; // sz[i] = number of objects in subtree rooted at i
    int count; // number of components
    public:
        union_find(int N) : id(N, 0), sz(N, 1) {
            count = N;
            for (int i = 0; i < N; i++) {
                id[i] = i;
            }
        }

        int nb_components() {
            return count;
        }

        int size_set(int i) {
            return sz[find_set(i)];
        }

        int find_set(int i) {
            return (id[i] == i) ? i : (id[i] = find_set(id[i]));
        }

        bool connected(int i, int j) {
         return find_set(i) == find_set(j);
        }

        void union_set(int p, int q) {
            int i = find_set(p);
            int j = find_set(q);
            if (i == j) return;
            // make smaller root point to larger one
            if (sz[i] < sz[j]) { 
                id[i] = j; sz[j] += sz[i]; 
            }
            else { 
                id[j] = i; sz[i] += sz[j]; 
            }
            count--;
        }
};

int main(){
    int N; cin >> N;
    union_find elem(500001);

    int count = 0;

    for(int i = 0; i < N; i ++){
        int M; cin >> M;
        int recipe[M];
        set<int> s;
        for (int j = 0; j < M; ++j) {
            int ingredient; cin >> ingredient;
            s.insert(elem.find_set(ingredient));
            recipe[j] = ingredient;
        }
        int total = 0; // The total number of ingredients in the different cauldrons
        for (int i : s) {
            total += elem.size_set(i);
        }
        if (total == M) {
            count ++;
            for(int j = 0; j < M; j ++){
                elem.union_set(recipe[0], recipe[j]);
            }
        }

    }
    cout << count << endl;
    return 0;
}