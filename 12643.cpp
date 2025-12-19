#include <cstdio>
#include <vector>

using namespace std;

int main()
{
  int N, i, j; 
  vector<int> results;
  while(scanf("%d %d %d", &N, &i, &j) == 3)
  {
    int answer = 0;
    
    /*
    int m = j - i;

    for(int n = 0; n < N && m > 2; n++)
    {
      if(m % 2 == 0) { m/=2; }
      else { m = (m-1)/2 + 1; }
      answer++;
    }
    */

    i--; j--;
    while(i!=j) { i/=2; j/=2; answer++; }
    results.push_back(answer);
  }
  
  for(int r : results) { printf("%d\n", r); }

  return 0;
}
