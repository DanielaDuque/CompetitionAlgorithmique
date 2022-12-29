#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;


int pos(vector<int> &v, int K){
    auto it = find(v.begin(), v.end(), K);
    int index = it - v.begin();
    v.at(it - v.begin()) = INT_MAX;
    return it - v.begin();
};

int main()
{
    int N;
    std::cin >> N;
    int X;
    std::cin >> X;

    vector<int> arr;
    vector<int> aux;


    for (int i = 0; i < N; ++i)
    {
        int n;
        std::cin >> n;
        arr.push_back(n);
        aux.push_back(n);
    }

    sort(arr.begin(), arr.end());
    int l, r;
    // cout << arr.size() << endl;
    /* Now fix the first element one by one and find the
       other two elements */

    for (int i = 0; i < N - 2; i++)
    {
        // To find the other two elements, start two index
        // variables from two corners of the array and move
        // them toward each other
        l = i +1 ; // index of the first element in the
        // remaining elements
        r = N - 1; // index of the last element
        // cout << l << " " << r << endl;
        while (l < r)
        { // cout << l << " " << r << endl;
            if (arr[i] + arr[l] + arr[r] == X)
            {
                // cout << i << " " << l << " " << r << endl;
                cout << pos(aux,arr[i])+1 << " " << pos(aux,arr[l])+1 << " " << pos(aux,arr[r])+1 << endl;
                return 0;
            }
            else if (arr[i] + arr[l] + arr[r] < X)
                l++;
            else // arr[i] + arr[l] + arr[r] > sum
                r--;
        }
    }
    // If we rearrch here, then no triplet warrs found

    cout << "IMPOSSIBLE" << endl;

    return 0;
}