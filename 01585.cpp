#include <bits/stdc++.h>
using namespace std;


int main()
{

    int T; scanf("%d", &T); getchar(); // eat the \n

    vector<int> results;

    for(int i = 0; i < T; i++)
    {
        int previous_count = 0;
        int sum = 0;
        char str[82];
        
        fgets(str, sizeof str, stdin); // read line

        for(int k = 0; str[k] != '\0'; k++)
        {
            if(str[k] == 'O')
            {
                sum += ++previous_count;
            } else if(str[k] == 'X') { previous_count = 0; }
        }

        results.push_back(sum);
        

    }

    for(int r : results) { printf("%d\n", r); }

    return 0;
}