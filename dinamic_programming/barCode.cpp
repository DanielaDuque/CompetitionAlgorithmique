#include <iostream>
#include <cstring>
using namespace std;

/**
    matrixBarCode[i][j] stores the number of symbols that the ith bar ends at 
    the jth unit.

    matrixBarCode[bar][unit] = sum of matrixBarCode[bar - 1][unit - wide]
*/

// The maximum number of bars is 64.
long long matrixBarCode[64][64];

int main()
{
    int n, k, m;
    while (cin >> n >> k >> m)
    {
        // Assign 0 to the whole matrix


        memset(matrixBarCode, 0, sizeof matrixBarCode);
        // There is only 1 symbol that the 1st bar ends at any unit equal or less than n and m. 
        // Add one to all first line elements.
        for (int unit = 1; unit <= n && unit <= m; ++unit)
            matrixBarCode[1][unit] = 1;
        
        // Every matrixBarCode[bar][unit] can be reached by adding one bar of
        // at most m units wide.
        for (int bar = 2; bar <= k; ++bar)
            for (int unit = bar; unit <= n; ++unit)
                for (int wide = 1; wide <= m && unit > wide; ++wide)
                    matrixBarCode[bar][unit] += matrixBarCode[bar - 1][unit - wide];
        
        cout << matrixBarCode[k][n] << endl;
    }
    return 0;
}