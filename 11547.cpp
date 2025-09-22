#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // comment out before submitting!!
    //freopen("input.txt", "r", stdin);

    int t; // number of cases
    cin >> t; // get number of cases in

    char results[t];

    for(int i = 0; i < t; i++)
    {
        int n;
        cin >> n;
        int ans = (((((n * 567) / 9) + 7492) * 235) / 47) - 498;
        //printf("ans: %d\n", ans);
        string ans_rep = to_string(ans);

        // approach idea: binary, 2s complement representation ie checking the bits, convert to string or access as a sub-array, or a modulus trick
        results[i] = ans_rep[ans_rep.size() - 2];
    }

    for(char r : results) cout << r << "\n";


    return 0;

}