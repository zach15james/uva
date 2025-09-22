#include <bits/stdc++.h>
using namespace std;

int main()
{
    // fast io 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // number of test cases 
    scanf("%d", &T); // take in number of cases 
    int TC = T;

    vector<int> results;

    // do math
    while(T--) // for number of test cases....
    {
        int N, K, P; scanf("%d %d %d", &N,&K,&P);
        int value = (K + P) % N;
        if(value == 0) value = N; // edge case 
        results.push_back(value);
    }

    //output results
    for(int i = 0; i < TC; ++i)
    {
        printf("Case %d: %d\n", i+1, results.at(i));
    }

}