#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t; 
    cin >> t; 
    vector<char> results(t);

    for(int i = 0; i < t; ++i)
    {
        long long a,b;
        scanf("%lld %lld", &a, &b);
        if(a < b) { results.at(i) = '<'; }
        else if(a > b) { results.at(i) = '>'; }
        else { results.at(i) = '='; }
    }

    for(int i = 0; i < t; i++)
    {
        printf("%c\n", results[i]);
    }

    return 0;

};