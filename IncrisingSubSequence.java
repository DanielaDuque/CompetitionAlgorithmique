#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
    int N;
    std::cin>> N;
//    int* sequence = new int[N];
//    int* numbers = new int[N];
    vector<int> numbers(N, 1);
    vector<int> sequence(N, 1);
    int longestSubsequence = 0;

    for (int i = 0; i < N; i++) {
        std::cin >> sequence[i] ;
        numbers[i] = 1;
        for (int j = 0; j < i; j++) {
            if (sequence[j] < sequence[i]) {
                numbers[i] = std::max(numbers[i], numbers[j] + 1);
            }
        }
        longestSubsequence = std::max(longestSubsequence, numbers[i]);
    }
    std::cout << longestSubsequence;

    return 0;
}