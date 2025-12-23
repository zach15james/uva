#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> results;  
  char line[1002];
  while(fgets(line, 1002, stdin))
  {
    vector<pair<stack<char>, bool>> stacks;  // stacks[i].first = stack<char>; stacks[i].second = bool ( last-one-differrent, all initialized to false, as 0 elment is intiialized) 
    int s = 0; bool
    stacks[0].push_back(line[0]);  // original case to not have to deal with empty start special case 
    for(int i = 1; i < 1000; i++)
    {
      char c = line[i]; char p;
      if(c <= 'A' || c >= 'Z') break; // exit loop, as input is through
      else
      {
        // NO PREV DIFF
        if(stacks[s].second == false)
        {
          if(stacks[s].first.top() != c) { stacks[s].second = true; }
          stacks[s].first.push(c); 
        }
        else // was previous difference
        {
          // no current difference
          if(stacks[s].first.top() == c) { stacks[s].first.push(c); stacks[s].second = false; }
          else // is a difference
          { 
            // check other previous indexes, add there if possible, else pop the previous element, add it to a new stack (iterate s), then add current element on top of that element
            p = stacks[s].first.top();
            stacks[s].first.pop(); 
            stacks[s].second = false; // fixing this 
            stacks[++s].push(p);
            stacks[++s].push(c); 
            stacks[s].second = true; 
          }
        }







        
      }
    }

    results.push_back(stacks.size());
  }

  for(int r = 0; r < results.size(); r++)
  { printf("Case %d: %d\n", r + 1, results[r]); }

  return 0;
}
