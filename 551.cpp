#include <bits/stdc++.h>
using namespace std;


// leveraging the tm library 
int main()
{
  //printf("it works"); 
  string line; vector<int> result; // 0 if correct (index 0 cannot have error), otherwise index value
  while(getline(cin, line))
  {
    stack<char> stack; bool errored = false; int last_special = -1; 

    // start of new case (line)
    for(int i = 0; i < line.size(); i++)
    { // iterating through the line
      char I = line[i]; 
      // starting cases 
      if(I == '{' || I == '[' || I == '<') { stack.push(I); }
      else if(I == '(')
      { 
        //last_special = i; 
        // ie so track (* *) by * and () by ( and ) 
        // if its '(*' then skip over the next one w/ an i++
        if(i < line.size() - 1 && line[i+1] == '*') { stack.push('*'); last_special = i; i++; } 
        else { stack.push(I); }
      } 
      // ending checks
      else if(I == '*')
      {
        // .at() is after than direct indexing
        // if EXISTS && is == ')' && 
        if(i+1 < line.size() && line.at(i+1) == ')' && !stack.empty() && stack.top() == '*')
        {
          // success ie keep going
          stack.pop(); i++;
        } else { result.push_back(i); errored = true; break; }

      }
      else if(I == ')')
      {
        if(stack.empty() || stack.top() != '(')
        {
          result.push_back( (!stack.empty() && stack.top() == '*' && last_special != -1) ? last_special : i );
        } else { stack.pop(); } // good, keep going
      }
      else if(I == '}')
      {
        if(stack.empty() || stack.top() != '{')
        {
          result.push_back(i); errored = true; break; 
        } else { stack.pop(); } // good, keep going
      }
      else if(I == ']')
      {
        if(stack.empty() || stack.top() != '[')
        {
          result.push_back(i); errored = true; break; 
        } else { stack.pop(); } // good, keep going
      }
      else if(I == '>')
      {
        if(stack.empty() || stack.top() != '<')
        {
          result.push_back(i); errored = true; break; 
        } else { stack.pop(); } // good, keep going
      }

      //if(!stack.empty()) { errored = true; } 
    }

    if(!errored)
    {
      if(stack.empty()) { result.push_back(0); }
      else { result.push_back(line.size()); }
    }

  }


  // print results
  for(int r : result)
  { 
    if(r == 0) { printf("YES\n"); }
    else { printf("NO %d\n", r+1); } // 0-based ---> 1-based indexing
  }
}

