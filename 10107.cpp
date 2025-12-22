#include <bits/stdc++.h>


using namespace std;


int main()
{
  vector<long long> results;

  // NAIVE ARRAY - RESORT EVERY TIME - SOLUTION
  //vector<long long> saved;
  long long n = 0; 
  //if(scanf("%lld", &n) != EOF) { results.push_back(n); saved.push_back(n); }
  //else { for(int r : results) { printf("%d\n", r); return 0; } }
  //if(scanf("%lld", &n) != EOF) { saved.push_back(n); results.push_back((saved[0] + n) / 2); }
  //else { for(int r : results) { printf("%d\n", r);  return 0; } }
  
  //// now executed algorithm after base edge cases are handled 
  //while(scanf("%lld", &n) != EOF)
  //{
    //saved.push_back(n); // save the value 
    //sort(saved.begin(), saved.end()); // naive approach
    //printf("\nsaved arr: ");
    //printf("[ "); for(long long s : saved) { printf("%lld ", s); } printf(" ]\n");
    ///int s = saved.size();
    //if(s % 2 == 0)
    //{ // even
    //  int r = (saved[(s/2) - 1] + saved[s/2]) / 2;
    //  results.push_back(floor(r));
    //}
    //else 
    //{ // odd
    //  results.push_back(saved[(s-1)/2]);
    //}
    // PRIORITY QUEUE (ADT) SOLUTION (w/ heap DS) via std::priority_queue DS
    //printf("curent midpoint: %lld\n", results[results.size() - 1]);
    //printf("[ "); for(long long m : results) { printf("%lld ", m); } printf(" ]\n");
  //}

  priority_queue<long long> less; // max-heap default ( for lower half)
  // syntax: priority_queue<type, conatiner, comparator> name;
  priority_queue<long long, vector<long long>, greater<long long>> great; // min-heap (for upper half) 
  
  // first 2 values 
  //if(scanf("%lld", &n) != EOF) { small.push(n); saved.push_back(n); }

  while(scanf("%lld", &n) != EOF)
  {

    // add 
    less.push(n);
    great.push(less.top());
    less.pop();

    // rebalance
    if(less.size() < great.size())
    {
      less.push(great.top());
      great.pop();
    }

    // get median
    if(less.size() > great.size()) { results.push_back(less.top()); }
    else { results.push_back((less.top() + great.top()) / 2); }

  }

  for(long long r : results) { printf("%lld\n", r); } 
  return 0;
}
