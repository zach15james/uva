#include <bits/stdc++.h>
using namespace std;


int main()
{
    int N;
    std::vector<int> results;
    //results.reserve(75);

    // Emoogle Balance = number of times Emoogle is supposed to give a treat according to the book (99) - # times he has actually given the treat 

    // solution
    while(scanf("%d", &N) == 1 && N != 0) // end case 
    {
        int v; int supposed = 0; int actual = 0;
        for(int i = 0; i < N; i++)
        {
            scanf("%d", &v);
            if(v == 0) { actual++; } else { supposed++; }
        }
        
        results.push_back(supposed - actual);

    }

    // output 
    int iter = 1;
    for(int r : results)
    {
        printf("Case %d: %d\n", iter++, r);
    }


    return 0;
}