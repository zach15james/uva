#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

int bowl_volume(vector<char> bowl);

int main()
{
  int n; scanf("%d", &n);
  while(getchar() != '\n'); // pickup the \n  
  vector<long long> results;

  while(n--)
  {
    char line[10002];
    fgets(line, sizeof(line), stdin);

    stack<int> s; 
    // NOTE: stack.push(value); .pop() --> ; .top() -> element; .empty() -> bool
    long long total_water = 0;

    for(int i = 0; line[i] != '\0' && line[i] != '\n'; i++)
    {
      if(line[i] == '\\') { s.push(i); }
      else if(line[i] == '/' && !s.empty())
      {
        int left_index = s.top();
        s.pop();
        total_water += (i - left_index); 
      }
    }
    results.push_back(total_water);
  }


  for(long long r : results) printf("%lld\n", r);
  return 0;
}

