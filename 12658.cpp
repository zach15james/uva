#include <bits/stdc++.h>
using namespace std;


int main()
{

    int n; scanf("%d", &n); // number of characters to recognize 

    // .(start)*s.(end), get start-end pairs
    // get the indices w/ the first line

    char line[4 * n + 2]; 
    scanf("%s", line);

    vector<pair<int,int>> numbers(n); // (start, length)
    vector<int> values(n); // results vector
    //bool started = false;
    int length = 0; int number_idx = 0;
    // note: scanf doesn't include the \n character.. doesn't mean the buffer shouldn't have room for it, though
    for(int i = 0; line[i] != '\0'; i++)
    {
        if(line[i] == '.')
        {
            if(length > 0) // reached the end of the line 
            {
                numbers[number_idx++].second = length;
                length = 0; // reset     
            }
            else // reached right before start of new line
            {
                //numbers[number_idx].first = i+1; // update the number // no operatation is req until you see first one  
            }
        }


        if(line[i] == '*')
        { if(length == 0) { numbers[number_idx].first = i; } length++; }
    }

    if(length > 0) { numbers[number_idx].second = length; } // flush last run



    // eat the next 2 lines (redundant)
    scanf("%s", line);
    scanf("%s", line);
    for(int l = 0; line[l] != '\n' && line[l] != '\0'; l++)
    {
        line[l] = ' '; // resetting
    }

    // get the defining line
    scanf("%s", line);

    char last_line[4 * n + 2]; scanf("%s", last_line);
    // line[number_start_idx] == '*' --> 2
    // line[number_end_idx == number_start_idx + length] == '*' --> 2
    for(int i = 0; i < n; i++)
    {
        if(numbers[i].second == 1) { printf("%d", 1); }
        else if(line[numbers[i].first] == '*')
        {
            //printf("this is 2\n"); 
            printf("%d", 2);
        }
        else if(line[numbers[i].first] == '.')
        {
            //printf("this is 3\n"); 
            printf("%d", 3);
        }
        //else if(line[numbers[i].first + numbers[i].second - 1] == '*')
        //{ printf("%d", 3); }
    }
    putchar('\n'); // to be safe

    return 0;
}