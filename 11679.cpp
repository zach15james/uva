#include <bits/stdc++.h>
using namespace std;


int main()
{
    
    vector<bool> results;

    int B, N; // {1,...,B} banks, # total debentures
    while(scanf("%d %d", &B, &N) && !(B == 0 && N == 0))
    {
        //printf("read: B(%d), N(%d)\n", B, N);
        vector<long> reserves; // how many reserves does each bank have?
        for(int i = 0; i < B; i++)
        {
            long r; scanf("%ld", &r);
            reserves.push_back(r);
        }

        int D, C; // debtor bank, creditor bank (1<=D<=B)
        long V; // debenture value 
        //vector<tuple<int,int,long>> debentures; // not needed in naive approach
        for(int i = 0; i < N; i++)
        {
            scanf("%d %d %ld", &D, &C, &V);

            // following approach is to just add them and then see what balances there are at the end... the issue is that if certain banks don't have it, then that causes the others to fail... so trying naive approach: 

            reserves.at(D-1) -= V; // pay out debt
            reserves.at(C - 1) += V; // paid back debt
        }
        

        char solv = 0; 
        for(int i = 0; i < B; i++)
        {
            if(reserves.at(i) >= 0) { solv++; }
        }

        if(solv == B) { results.push_back(true); }
        else { results.push_back(false); }

    }

    for( bool r : results)
    {
        if(r) { printf("S\n"); }
        else {printf("N\n"); }
    }

    return 0;
}