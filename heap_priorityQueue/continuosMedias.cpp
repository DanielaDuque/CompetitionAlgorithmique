#include <iostream>
#include <queue>
#include <limits>
#include <math.h>

using namespace std;

int main(){

    int test; cin >> test;

    for(int i = 0; i < test; i ++){
        int n; cin >> n;
        // cout << "---------" << endl;
        // cout << "Case #" << i + 1 << ": " << endl;
        priority_queue<int, vector<int>, greater<int>> maxHeap; maxHeap.push(numeric_limits<int>::max());
        priority_queue<int> minHeap; minHeap.push(numeric_limits<int>::min());

        int sum = 0;
        int median = 0;
        for (int j = 0; j < n; ++j) {
            int a; cin >> a;
            int left = minHeap.top();
            int right = maxHeap.top();

            if (minHeap.size() <= maxHeap.size()) {
                if (a <= right) minHeap.push(a);
                else {
                    minHeap.push(maxHeap.top());
                    maxHeap.pop();
                    maxHeap.push(a);
                }
            } else {
                if (a >= left) maxHeap.push(a);
                else {
                    maxHeap.push(minHeap.top());
                    minHeap.pop();
                    minHeap.push(a);
                }
            }

            if(maxHeap.size() == minHeap.size()) {
                median = (maxHeap.top() + minHeap.top()) / 2;
            } else if (maxHeap.size() > minHeap.size()) {
                median = maxHeap.top();
            } else {
                median = minHeap.top();
            }
            sum += median;
        }
        cout << sum << endl;
    }

    return 0;
}
