#include <bits/stdc++.h>
using namespace std;

int main()
{
    //printf("program started\n");
    int T; scanf("%d", &T); // [1,20)
    vector<int> results;
    //printf("T := %d\n", T);

    for(int i = 0; i < T; i++)
    {
        vector<int> scores; 
        int n; scanf("%d", &n); // [2,100000], # students in course
        //printf("n := %d\n", n);

        for(int j = 0; j < n; j++) // get their scores 
        { int s; scanf("%d", &s); scores.push_back(s); } 

        int best = scores[0]; int answer = INT_MIN;

        for(int k = 1; k < n; k++)
        {
            answer = max(answer, best - scores[k]);
            best = max(best, scores[k]);
        }

        results.push_back(answer);

        // attempt 2:
        /*
        pair<int,int> min; // <index,value>
        pair<int,int> max;
        min.first = 0; min.second = scores[0];
        max.first = 0; max.second = scores[0];

        for(int k = 1; k < n; k++)
        {
            if(min.second > scores[k]) { min.first = k; min.second = scores[k]; }
            if(max.second < scores[k]) { max.first = k; max.second = scores[k]; }

        }

        printf("min: (%d, %d), max: (%d, %d)\n", min.first, min.second, max.first, max.second);

        if(min.first < max.first) { results.push_back(min.second - max.second); }
        if(max.first < min.first) { results.push_back(max.second - min.second); }
        
        // attempt 1:
        auto [m_iterator, M_iterator] = minmax_element(scores.begin(), scores.end());

        int m_value = *m_iterator; int M_value = *M_iterator; 
        int m_index = distance(scores.begin(), m_iterator);
        int M_index = distance(scores.begin(), M_iterator);

        if(m_index < M_index) { results.push_back(m_value - M_value); } // m is senior to M
        else { results.push_back(M_value - m_value); } // M is senior to m
        */
    }

    for(int r : results)
    {
        printf("%d\n", r);
    }


    return 0;
}