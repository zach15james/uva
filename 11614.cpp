#include <bits/stdc++.h>
using namespace std;



int main()
{
    int T; scanf("%d", &T);
    vector<long long> results(T);

    for(int i = 0; i < T; i++)
    {
        long long n; scanf("%lld", &n);

        // try binary search and treat this as a root finding problem in a sense
        long long low = 0;
        long long high = 2000000000;
        long long answer = 0;

        while(low <= high)
        {
            long long middle = low + (high-low) / 2;

            long long warriors_needed = middle * (middle+1) / 2;

            if(warriors_needed <= n)
            {
                answer = middle;
                low = middle + 1;
            }
            else
            {
                high = middle - 1;
            }
            
        }

        /*
        long long k = n;
        while(((k * (k+1)) / 2) % k != 0)
        {
            k++;
        }
        */
        results[i] = answer;

    }

    for(int i = 0; i < T; i++)
    {
        printf("%lld\n", results[i]);
    }

    return 0;
}