#include <bits/stdc++.h>
using namespace std;


int main()
{

    int T; scanf("%d", &T);
    vector<int> results(T);
    for(int t = 0; t < T; t++)
    {
        int n; scanf("%d", &n);
        vector<int> totals(n);
        for(int i = 0; i < n; i++)
        {
            char buf[16];

            if(scanf("%s", buf) == 1) // actually is a string ... 
            {
                if(strcmp(buf, "LEFT") == 0) { totals[i] = -1; /*printf("left, n:%d\n", n);*/ }
                else if(strcmp(buf, "RIGHT") == 0) { totals[i] = 1; /*printf("right, n:%d\n", n);*/ }
                else if(strcmp(buf, "SAME") == 0)
                {
                    char as[5]; // as + ' ' + '\n' + '\0'
                    int index; scanf("%s %d", as, &index);
                    totals[i] = totals[index - 1];  
                    //printf("same, index %d: %d\n", index, totals[index-1]); 
                }
                else { printf("read error\n"); }

            } else { printf("bad read\n"); }
            
        }
        
        //printf("Totals are: ");
        int total = 0;
        for(int to : totals) { total += to; /*printf("%d\n", to);*/ }
        results[t] = total; //printf("total: %d\n", total);
    }

    for(int r : results) { printf("%d\n", r); }

    return 0;
}