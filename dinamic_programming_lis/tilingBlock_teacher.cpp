#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Block
{
    int l, m;
    Block() {}
    bool operator<(const Block& b) const{
        return l < b.l || (l == b.l && m < b.m);
    }

    bool operator()(const Block& b1, const Block& b2) const{
        return b1.m <= b2.m;
    }
};
int main(){
    int N;
    while (cin >> N, N)
    {
        vector<Block> blocks(N, Block());
        for (int i = 0; i < N; ++i) cin >> blocks[i].l >> blocks[i].m;

        sort(blocks.begin(), blocks.end());

        int tallest = 0;
        vector<Block> lis(N,Block());
        
        for (int i = 0; i < N; ++i) {
            int pos = lower_bound(lis.begin(), lis.begin() + tallest,
            blocks[i],Block()) - lis.begin();
            lis[pos] = blocks[i];
            tallest = max(tallest, pos + 1);
        }
            cout << tallest << endl;
        }

    cout << "*" << endl;
    
    return 0;
}