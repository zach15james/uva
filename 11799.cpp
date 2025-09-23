#include <bits/stdc++.h>
using namespace std;


int main()
{
    int T; scanf("%d", &T); // number of test cases
    vector<int> results(T);
    results.reserve(T);

    for(int i = 0; i < T; i++)
    {
        int N; scanf("%d", &N); // number of students
        int max = 0;
        for(int j = 0; j < N; j++)
        { 
            int value; scanf("%d", &value); // get the value 
            if(value > max) { max = value; }
        }

        results.at(i) = max; // clown must go at least 1 faster than the fastest student
        
    }

    for(int i = 0; i < T; i++)
    {
        printf("Case %d: %d\n", i+1, results.at(i)); // change N to be the anser
    }

    return 0;
}