//
// Created by daniela on 24/10/22.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class segment_tree {
    struct node {
        int sum = 0;
        int from = 0;
        int to = -1;
        bool pending = false;
        int size() const {
            return to - from + 1;
        }
    };
    std::vector<node> heap;
    int heap_size;
    int left (int p) { return p << 1; }
    int right(int p) { return (p << 1) + 1; }
    bool contains(int from1, int to1, int from2, int to2) {
        return from1 <= from2 && to2 <= to1;
    }
    bool intersects(int from1, int to1, int from2, int to2) {
        return (from1 <= from2 && to1 >= from2) ||
               (from1 >= from2 && from1 <= to2);
    }
public:
    segment_tree(int n){
        heap_size = 2 * (1 << ((int)log2(n) + 1));
        heap.resize(heap_size);
        build(1, 0, n - 1);
    }

private:
    void build(int heap_index, int from, int to) {
        node& n = heap[heap_index];
        n.from = from;
        n.to = to;
        if(from != to){
            int middle = from + (to - from) / 2;
            build(left(heap_index), from, middle);
            build(right(heap_index), middle + 1, to);
        }
    }
public:
    int get_sum(int from, int to) {
        return get_sum(1, from, to);
    }
private:
    int get_sum(int heap_index, int from, int to) {
        node& n = heap[heap_index];
        if(!intersects(from,to,n.from, n.to)) return 0;
        if (contains(from, to, n.from, n.to)) {
            return n.sum;
        }
        propagate(heap_index);
        return  get_sum(left(heap_index), from, to) +
                get_sum(right(heap_index), from, to);

    }

public:
    void update(int from, int to) {
        update(1, from, to);
    }
private:
    void update(int heap_index, int from, int to) {
        node& n = heap[heap_index];
        if (contains(from, to, n.from, n.to)) {
            change(n);
        }
        else if (intersects(from, to, n.from, n.to)) {
            propagate(heap_index);
            update(left(heap_index), from, to);
            update(right(heap_index), from, to);
            n.sum = heap[left(heap_index)].sum + heap[right(heap_index)].sum;
        }
    }
    void propagate(int heap_index) {
        node& n = heap[heap_index];
        if (n.pending) {
            n.pending = false;
            change(heap[left(heap_index)]);
            change(heap[right(heap_index)]);
        }
    }
    void change(node& n) {
        n.pending = !n.pending;
        n.sum = n.size() - n.sum;
    }
};


int main(){
    int N;  cin >> N;
    int Q;  cin >> Q;
    // Creting the ST
//    int arr[N];
//    for (int i = 0; i < N; ++i) {
//        arr[i] = 0;
//    }
    segment_tree sg(N);
    for (int i = 0; i < Q; ++i) {
        int option; cin >> option;
        int li; cin>> li;
        int hi; cin >> hi;
        if(option == 0) {
            sg.update(li,hi);
        }
        else cout << sg.get_sum(li,hi)<<endl;
    }

}
