#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // comment out before submitting!!
    //freopen("input.txt", "r", stdin);

    // get number of test cases 
    int t;
    cin >> t;

    int results[t];

    for(int i = 0; i < t; i++)
    {
        int n,m, min;
        cin >> n >> m; // n-rows, m-cols

        int min_n = (n-2 + 3 - 1) / 3;
        int min_m = (m-2 + 3 - 1) / 3;
        min = min_n * min_m;
        // one sonal beam s = 1 position w/ surrounding positions 

        results[i] = min; 
    }

    for(int r : results)
    {
        cout << r << "\n";
    }

}