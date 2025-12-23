#include <bits/stdc++.h>
using namespace std;


int main()
{
  vector<int> results;
  int n;
  while(scanf("%d", &n) != EOF)
  {// read in the dimension
    
    vector<pair<int, int>> corners; // weight, potency

    // reach in German bible
    //int m = 2 ** n; // # of corners
    int m = 1 << n;

    for(int i = 0; i < m; i++)
    {
      int weight; scanf("%d", &weight);
      corners.push_back({weight, 0}); // fill in poetncy later when i have all the info
    }

    //int z = 2 ** n;     
    // grab the potencies for all corners 
    for(int i = 0; i < m; i++) // iterate through each corner
    {
      int potency = 0; //corners[i].first;
      //unsinged int mask_i = i;
      for(int j = 0; j < n; j++) // sum up itself @ [0] then connected corners
      {
        int neighbor = i ^ (1 << j);
        // get permuted n at each position
        potency += corners[neighbor].first;
      }
      corners[i].second = potency;
    }
  
    // find max of 2 connected corners == using same conditions as potencies checks
    int max_potency = 0;
    for(int i = 0; i < m; i++)
    {
      for(int j = 0; j < n; j++)
      {
        int neighbor = i ^ (1 << j);
        int current_sum = corners[i].second + corners[neighbor].second;
        //if(corners[i].second + z > max_potency) { max_potency = corners[i].second * z > max_potency; } 
        if(current_sum > max_potency) { max_potency = current_sum; }
      }
    }  

    // n becomes max potencies sum
    results.push_back(max_potency);
  }

  for (int r : results) { printf("%d\n", r); }
  


  return 0;
}
