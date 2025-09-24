#include <bits/stdc++.h>
using namespace std;


int recursive_summation(int n)
{
    if(n <= 9) return n; // recursive exit condition
    int sum = 0; // REMEMBER TO INIT !!! (avoiding undefined behavior...)
    while(n > 0)
    {
        sum += n % 10; // adds rightmost/last digit
        n /= 10; // gets rid of rightmost/last digit 
    }
    
    return recursive_summation(sum);
}

int main()
{
    // only alphabets from z-z and A-Z will participate in the calculation
    // a=1,b=2,...,z=26, A=1,...,Z=26

    // so take the sum of the numbers, ie 2+3+26 = 31 => 3+1=4
    char s_a[32]; // each name holds not more than 25 characters
    char s_b[32];
    unsigned int p,q;
    vector<double> results;

    while(fgets(s_a, sizeof s_a, stdin) && fgets(s_b, sizeof s_b, stdin))
    {
        int score_a = 0; int score_b = 0;
        for(int i = 0; s_a[i] != '\0'; i++)
        {
            p = static_cast<unsigned char>(tolower(s_a[i]));
            if(p >= 'a' && p <= 'z') { score_a += p - 'a' + 1; }
            
        }
        for(int i = 0; s_b[i] != '\0'; i++)
        {
            q = static_cast<unsigned char>(tolower(s_b[i]));
            if(q >= 'a' && q <= 'z') { score_b += q - 'a' + 1; }
        }
        
        // deal with summed score now
        int numerator = recursive_summation(score_a);
        int denominator = recursive_summation(score_b);

        double result = 0.0;
        if(numerator == 0 && denominator == 0) { result = 0.0; }
        else
        {
            int low = min(numerator, denominator); int high = max(numerator, denominator);
            result = (static_cast<double>(low) / static_cast<double>(high)) * 100;
        }

        // note: '%d' for int, '%f' for double
        //printf("S_a := %d, S_b := %d, & a/b = result = %f\n", numerator, denominator, result);

        results.push_back(result);
    }

    for(double r : results)
    {
        printf("%.2f %%\n", r);
    }

    return 0;
}

