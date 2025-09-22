#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    vector<bool> results(t);

    for(int i = 0; i < t; i++)
    {
        int L, W, H;
        scanf("%d %d %d", &L, &W, &H);
        results[i] = (L <= 20 && W <= 20 && H <= 20); // boolean expression - hope it works 
    }

    for(int i = 0; i < t; i++)
    {
        printf("Case %d: %s\n", i + 1, ((results[i]) ? "good" : "bad"));
    }

    return 0;
}