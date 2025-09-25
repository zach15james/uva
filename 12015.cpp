#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; scanf("%d", &T);

    vector<vector<string>> results(T);
    
    for(int i = 0; i < T; i++)
    {
        int max_value = 0;
        vector<pair<string, int>> current_pages;

        for(int j = 0; j < 10; j++) // 10 sites
        {
            char url_buf[101]; // holds each line 
            int value;
            scanf(" %100s %d", url_buf, &value);

            current_pages.emplace_back(url_buf, value);

            if(value > max_value)
            { max_value = value; } 
        }

        for(const auto& p : current_pages)
        {
            if(p.second == max_value) { results[i].push_back(p.first); }
        }

    }

    for(int i = 0; i < T; i++)
    {
        printf("Case #%d:\n", i+1);

        for(const string& url : results[i])
        {
            printf("%s\n", url.c_str()); 
        }
    }

    return 0;

}