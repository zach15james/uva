#include <bits/stdc++.h>
using namespace std;

int main()
{
    
    int T; // test cases
    scanf("%d", &T);

    vector<pair<int,int>> results;
    results.reserve(T);

    // solve
    for(int i = 0; i < T; i++)
    {
        int N;
        scanf("%d", &N); // take in number of walls 
        
        //printf("CASE %d, N = %d\n", i, N);
        if(N == 1)
        { 
            int eat_value; scanf("%d", &eat_value);
            pair<int,int> zero; zero.first = 0; zero.second = 0;
            results.push_back({0, 0});
        }
        else 
        {
            pair<int,int> answer;

            vector<int> heights(N);

            // read in all the heights
            for(int j = 0; j < N; j++)
            {
                int value;
                scanf("%d", &value);
                heights.at(j) = value;
            }

            for(int k = 0; k+1 < N; k++)
            {
                //printf("Part k = %d, heights.at(k = %d), heights.at(k+1 = %d)\n", k, heights.at(k), heights.at(k+1));
                if(heights.at(k) > heights.at(k + 1)) { answer.second++; } //high
                
                if(heights.at(k) < heights.at(k+1)) { answer.first++; }
            }

            results.push_back(answer);
        }
        
    }

    // output 
    for(int i = 0; i < T; i++)
    {
        printf("Case %d: %d %d\n", i+1, results[i].first, results[i].second);
    }

    return 0;
}