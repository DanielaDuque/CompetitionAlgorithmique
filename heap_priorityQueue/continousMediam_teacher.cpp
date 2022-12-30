#include <iostream>
#include <queue>
#include <climits>
#include <math.h>
#include <limits>
#include <math.h>
#include <vector>


using namespace std;

int solve_continuous_median(const vector<int>& A) {
    priority_queue<int> left_max_pq;
    priority_queue<int, vector<int>, greater<int>> right_min_pq;
    left_max_pq.push(numeric_limits<int>::min());
    right_min_pq.push(numeric_limits<int>::max());
    // The invariant is that the max element of the left heap is less than the min
    // and we keep a size difference between the two heaps of at most 1.
    // It is now easy to find the median, but the invariant must be preserved for each
    long long res = 0;
    for (int x : A) {
        int left = left_max_pq.top();
        int right = right_min_pq.top();
        if (left_max_pq.size() <= right_min_pq.size()) {
            if (x <= right) left_max_pq.push(x);
            else {
                left_max_pq.push(right_min_pq.top());
                right_min_pq.pop();
                right_min_pq.push(x);
            }
        } else {
            if (x >= left) right_min_pq.push(x);
            else {
                right_min_pq.push(left_max_pq.top());
                left_max_pq.pop();
                left_max_pq.push(x);
            }
        }

                    // cout << " minHeap: " << left_max_pq.top() << " maxHeap: " << right_min_pq.top() << endl << endl;

        if (right_min_pq.size() == left_max_pq.size()) {
            res += (left_max_pq.top() + right_min_pq.top()) / 2;
        } else {
            if (right_min_pq.size() < left_max_pq.size()) res += left_max_pq.top();
            else res += right_min_pq.top();
        }
    }
    return res;
}

int main(){
    int test; cin >> test;

    for(int i = 0; i < test; i ++){
        int n; cin >> n;
        vector<int> A;
        for (int j = 0; j < n; ++j) {
            int a; cin >> a;
            A.push_back(a);
        }
        cout << solve_continuous_median(A) << endl;

    }
    return 0;
}