#include <vector>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
  int T; scanf("%d", &T);

  // Mile: 10cents/30secs
  // Juice: 15cents/60secs
  
  vector<pair<string, int>> results; // true: mile, false: juice; int: cost [of cheaper package]
  for(int t = 0; t < T; t++)
  {

    int mile_sum = 0, juice_sum = 0;
    // read in each call time
    int n; scanf("%d", &n); 
    
    // iterathe through each call 
    for(int c = 0; c < n; c++)
    { 
      int mq = 0, jq = 0;
      int seconds; scanf("%d", &seconds); // read minutes of this call
      //int jseconds = seconds;
      
      // do calculations immediately
      //while(seconds - 30 >= 1) { mq++; seconds-=30; }
      //while(jseconds - 60 >= 1) { jq++; jseconds-=60; }
      //if(seconds > 0) { mq++; }
      //if(jseconds > 0) { jq++; }

      //printf("mile: %d:%d, juice: %d:%d\n", mq, mr, jq, jr);
      //mile_sum += 10 * mq;
      mile_sum += ((seconds/30) + 1) * 10;
      juice_sum += ((seconds/60) + 1) * 15;
      //juice_sum += 15 * jq;
    }
    
    //printf("stats after run: [T=%d] mile_sum: %d, juice_sum: %d\n", T, mile_sum, juice_sum);

    // after computing total cost, set the minimum result
    if(mile_sum < juice_sum) { results.push_back({"Mile", mile_sum}); }
    else if(mile_sum > juice_sum) { results.push_back({"Juice", juice_sum}); }
    else { results.push_back({"Mile Juice", mile_sum}); }

  }

  for(int r = 0; r < T; r++)
  {
    printf("Case %d: %s %d\n", r+1, results[r].first.c_str(), results[r].second);
  }

  return 0;
}


