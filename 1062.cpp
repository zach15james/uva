#include <bits/stdc++.h>
using namespace std;

int main()
{
  vector<int> results;  
  char line[1002];
  //int l = 1;
  while(fgets(line, 1002, stdin))
  {
    //printf("start of line %d\n", l); l++;

    line[strcspn(line,"\r\n")] = 0; // strip newline
    if(strcmp(line, "end") == 0) { break; } // end of input 
    // stacks[i].first = stack<char>; stacks[i].second = bool ( last-one-differrent, all initialized to false, as 0 elment is intiialized) 
    //vector<pair<stack<char>, bool>> stacks(line_length); // to be safe (could be optimized, but perfect is the enemy of good  
    //stack<char> st;
    vector<stack<char>> stacks;
    
    int line_length = strlen(line);
    int s = 0;  char c;
    if(line_length > 0) { stacks.emplace_back(); stacks[0].push(line[0]); } 
    
    //printf("[{%c}", c);
    // iterate through the line  
    for(int i = 1; i < line_length; i++)
    {
      c = line[i]; //printf("{%c}", c);

      bool placed = false;

      for(int j = 0; j < stacks.size(); j++)
      {
        if(c <= stacks[j].top())
        { 
          stacks[j].push(c);  // unecessary if == (need to uncomment IF check becomes <=)
          placed = true; break; 
        }
      }

      if(!placed) { stack<char> z; z.push(c); stacks.push_back(z); }
    }


    results.push_back(stacks.size()); // stacks needed ( or I guess I could do stacks.size()
  }

  for(int r = 0; r < results.size(); r++)
  { printf("Case %d: %d\n", r + 1, results[r]); }

  return 0;
}


