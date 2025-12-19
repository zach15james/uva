#include <bits/stdc++.h>
using namespace std;


// void print_current_array(const vector<bool> &circle)
// {
//     printf("{ ");
//     for(int c : circle)
//     {
//         printf("%d, ", c);
//     }
//     printf("}\n");
// }

int main()
{

    vector<vector<pair<int,int>>> results;
    //vector<pair<int,int>> results;
    int N, k, m; 
    //int bigIter = 0;
    bool running = true; 
    while(running)
    {
        scanf("%d %d %d", &N, &k, &m);
        if(N == 0 && k == 0 && m == 0) { running = false; break; } 

        //printf("after scanf\n");

        vector<bool> circle(N); //fill(circle.begin(), circle.end(), 1);
        vector<pair<int,int>> result;

        int size = N;
        auto kiterator = circle.begin();
        auto miterator = circle.end() - 1;

        while(size)
        {
            //printf("after while size\n");
            // pass
            pair<int,int> selection;

            int ki = k; int mi = m;

           // print_current_array(circle);

            while(ki)
            {
                //printf("after while ki\n");

                if(*kiterator == 0) // good choice
                { ki--; }

                if(kiterator + 1 == circle.end())
                {
                    kiterator = circle.begin();
                } else { kiterator++; }
                //else // bad choice (already selected)
                //{ kiterator++; }

                //print_current_array(circle);

            }
            if(kiterator == circle.begin())
            {
                kiterator = circle.end() - 1; 
            } else { kiterator--; }

            //print_current_array(circle);


            while(mi)
            {
                //printf("after while mi\n");

                if(*miterator == 0) // good choice
                { mi--; }

                if(miterator == circle.begin())
                {
                    miterator = circle.end() - 1;
                } else { miterator--; }
                //else // bad choice (already selected)
                //{ kiterator++; }

                //print_current_array(circle);

            }
            if(miterator == circle.end() - 1)
            {
                miterator = circle.begin();
            } else { miterator++; }

            //print_current_array(circle);

            *kiterator = 1;
            *miterator = 1;

            if(kiterator == miterator)
            {
                selection.first = distance(circle.begin(), kiterator); 
                selection.second = -1;

                size--;
            }
            else
            {
                selection.first = distance(circle.begin(), kiterator);
                selection.second = distance(circle.begin(), miterator);

                size -= 2;
            }
            //selection.first = *--kiterator; // G test

            //printf("results.push_back about to happen!\n");
            //results[bigIter].push_back(selection);
            result.push_back(selection);
            //printf("results.push_back happened!\n");

        }

        results.push_back(result);
    
    }

    //printf("solving while loop done");

    //for(int z = 0; z < results.size(); z++)
    for( auto result : results)
    {
        for(int i = 0; i < result.size(); i++)
        { // iterate through pairs 
            // !NOTE! - had to adjust the output +1 as we did based on 0-indexing
            if(result[i].second == -1) { printf("%3d", result[i].first + 1); } // single case 
            else
            {
                printf("%3d%3d", result[i].first + 1, result[i].second + 1);
            }
            if(i != result.size() - 1) { printf(","); }
        }
        printf("\n");
    }

    return 0;
}