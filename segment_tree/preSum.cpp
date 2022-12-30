
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

class segment_tree
{
    struct node
    {
        long long sum = 0;
        long long lsum = 0;
        long long from = 0;
        long long to = -1;
        long long size() const
        {
            return to - from + 1;
        }
    };
    std::vector<node> heap;
    std::vector<long long> array;
    std::vector<long long> mp;
    long long heap_size;
    long long array_size;
    long long left(long long p) { return p << 1; }
    long long right(long long p) { return (p << 1) + 1; }
    bool contains(long long from1, long long to1, long long from2, long long to2)
    {
        return from1 <= from2 && to2 <= to1;
    }
    bool intersects(long long from1, long long to1, long long from2, long long to2)
    {
        return (from1 <= from2 && to1 >= from2) ||
            (from1 >= from2 && from1 <= to2);
    }

public:
    segment_tree(const std::vector<long long> &array)
    {
        this->array = array;
        array_size = array.size();
        heap_size = 2 * (1 << ((long long)log2(array.size()) + 1));
        heap.resize(heap_size);
        mp.resize(array_size);
        build(1, 0, array_size - 1);
    }
private:
    void build(long long heap_index, long long from, long long to)
    {
        node &n = heap[heap_index];
        n.from = from;
        n.to = to;
        if (from == to)
        {
            mp[from] = heap_index;
            n.sum = array[from];
            n.lsum = std::max(0LL,array[from]);
        }
        else
        {
            long long middle = from + (to - from) / 2;
            build(left(heap_index), from, middle);
            build(right(heap_index), middle + 1, to);
            n.sum = heap[left(heap_index)].sum + heap[right(heap_index)].sum;
            n.lsum = std::max(heap[left(heap_index)].lsum, heap[left(heap_index)].sum + heap[right(heap_index)].lsum);
        }
    }

public:
    long long get_sum(long long from, long long to)
    {
        return get_sum(1, from, to).first;
    }

private:
    pair<long long,long long> get_sum(long long heap_index, long long from, long long to)
    {
        node &n = heap[heap_index];
        if (contains(from, to, n.from, n.to))
        {
            return {n.lsum, n.sum};
        }
        if (intersects(from, to, n.from, n.to))
        {
            auto left_sum = get_sum(left(heap_index), from, to);
            auto right_sum = get_sum(right(heap_index), from, to);
            return {std::max(left_sum.first, left_sum.second + right_sum.first), left_sum.second + right_sum.second};
        }
        return {0,0};
    }
public:
    void update(long long heap_index, long long value)
    {
        long long index = mp[heap_index];
        node &n = heap[index];
        n.sum = value;
        n.lsum = std::max(0LL,value);
        
        index >>= 1;
        while (index)
        {
            node &nAux = heap[index];
            nAux.sum = heap[left(index)].sum + heap[right(index)].sum;
            nAux.lsum = std::max(heap[left(index)].lsum, heap[left(index)].sum + heap[right(index)].lsum);
            index >>= 1;
        }
    }
};
int main(){
    int N, Q; cin>>N>>Q;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin>>A[i];
    segment_tree st(A);
    for(int q = 0, t, a, b; q < Q; q++){
        cin>>t>>a>>b;
        if(t == 1)
            st.update(--a, b);
        else if(t == 2)
            cout<<st.get_sum(--a, --b)<<endl;
    }
}