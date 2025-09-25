#include <bits/stdc++.h>
using namespace std;


unsigned long long recurse(unsigned long long n)
{
    // exit case
    if(n <= 9) { return n; }

    // stuff
    unsigned long long result = 0;

    while(n != 0)
    {
        result += n % 10; // get last digit
        n /= 10; // remove the last digit
    }

    // recurse
    return recurse(result);

}

int main()
{

    // f(n) = 1+2+3+4+5+6+7+8+9+2 = 47
    // f(f(n)) = 4 + 7 = 11
    // f(f(f(n))) = 1 + 1 = 2
    //Therefore, g(1234567892) = 2.

    vector<unsigned long long> ints;
    unsigned long long integer;

    while(scanf("%lld", &integer) == 1 && integer != 0)
    {
        ints.push_back(integer);
    }

    for(unsigned long long i : ints)
    {
        printf("%lld\n", recurse(i));
    }


    return 0;
}