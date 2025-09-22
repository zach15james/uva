#include <bits/stdc++.h>
using namespace std;


// leveraging the tm library 
int main()
{
    tm time = {}; // key is to init type of 'tm' from <ctime>
    time.tm_year = 2013 - 1900;
    time.tm_mon = 5 - 1; // 0-indexed
    time.tm_mday = 29; // day of month 

    mktime(&time); // method that will automatically get the correct day

    // c character array (dynamically sized)
    const char* days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    const char* months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};


    //printf("SAMPLE OUTPUT: 'October 30, 2015 Friday'\n");
    printf("%s %02d, %04d %s\n", months[time.tm_mon], time.tm_mday, time.tm_year + 1900, days[time.tm_wday]);

}


// Messy Attempt: 
/*

pair<int, int> get_word_indices(string a, string b, vector<string> ordered_string_list)
{
    int A,B;
    for(int i = 0; i < ordered_string_list.size(); i++) // iterate through the list 
    {
        if(ordered_string_list.at(i) == a) { A = i; }
        if(ordered_string_list.at(i) == b) { B = i; }
    }

    return {A,B};
}

int main()
{
    // fast io 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // setup 
    vector<string> weekdays = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    vector<string> months = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    vector<int> month_days = {31, 28, 31, 30, 31, 30, 31, 30, 30, 31, 30, 31};
    // every 4 years (2024, 2028, &c) you have an extra leap day in February, i.e. month_days[1] = 29; 

    // GIVEN: "October 30, 2015 Friday
    int base_year = 2015; 
    int base_day = 4;
    string base_month = "October";

    // Estimate: 
    string predict_month = "May";
    int predict_day = 29;
    int predict_year = 2013;

    int days = 0;
    
    // first 
    if(predict_year < base_year)
    {
        pair<int, int> month_indices = get_word_indices(predict_month, base_month, months);
        
        // add rest of the first month
        days += month_days[month_indices.first] - base_day;

        // sum to the end of the predict_year
        for(int i = month_indices.first + 1; i < 12; i++)
        {
            days += month_days[i];
        }
        
        // add years 
        //for(int y = predict_year + 1; y < base_year; y++) { days += 365; }
        days += (365) * (base_year - predict_year - 1);
        

        for(int m = 0; m < month_indices.second; m++)
        {
            days += month_days[m];
        }
        
        // add remaining month gap
        days += predict_day;
           
        // add first year leap day if exisits
        if(month_indices.first <= 1)
        {
            if(predict_year % 4 == 0)
            {
                if(month_indices.first == 0) { days++; }
                if(month_indices.first == 1 && predict_day < 29) { days++; }
            }
        }

        // add intermeidate years
        for(int i = predict_year + 1; i < base_year; i++)
        {
            if(i % 4 == 0) { days++; }
        }


        // remaining part 
        if(base_year % 4 == 0)
        {
            if(month_indices.second > 1) { days++; }
        }
        
     

    }
    else if(base_year < predict_year)
    {
        pair<int, int> month_indices = get_word_indices(predict_month, base_month, months);
        
        // add rest of the first month
        days += month_days[month_indices.second] - predict_day;

        // sum to the end of the base_year
        for(int i = month_indices.second + 1; i < 12; i++)
        {
            days += month_days[i];
        }
        
        // add years 
        //for(int y = base_year + 1; y < predict_year; y++) { days += 365; }
        days += (365) * (predict_year - base_year - 1);
        

        for(int m = 0; m < month_indices.first; m++)
        {
            days += month_days[m];
        }
        
        // add remaining month gap
        days += base_day;
           
        // add first year leap day if exisits
        if(month_indices.second <= 1)
        {
            if(base_year % 4 == 0)
            {
                if(month_indices.second == 0) { days++; }
                if(month_indices.second == 1 && base_day < 29) { days++; }
            }
        }

        // add intermeidate years
        for(int i = base_year + 1; i < predict_year; i++)
        {
            if(i % 4 == 0) { days++; }
        }


        // remaining part 
        if(predict_year % 4 == 0)
        {
            if(month_indices.first > 1) { days++; }
        }


    }
    else // same year case 
    {

        // find the index of months
        pair<int, int> month_indices = get_word_indices(predict_month, base_month, months);
        
        if(month_indices.first < month_indices.second)
        {
            
        }        

        // add rest of the first month
        days += month_days[month_indices.first] - base_day;

        // sum to the end of the predict_year
        for(int i = month_indices.first + 1; i < 12; i++)
        {
            days += month_days[i];
        }
        
        // add years 
        //for(int y = predict_year + 1; y < base_year; y++) { days += 365; }
        days += (365) * (base_year - predict_year - 1);
        

        for(int m = 0; m < month_indices.second; m++)
        {
            days += month_days[m];
        }
        
        // add remaining month gap
        days += predict_day;
           
        // add first year leap day if exisits
        if(month_indices.first <= 1)
        {
            if(predict_year % 4 == 0)
            {
                if(month_indices.first == 0) { days++; }
                if(month_indices.first == 1 && predict_day < 29) { days++; }
            }
        }

        // add intermeidate years
        for(int i = predict_year + 1; i < base_year; i++)
        {
            if(i % 4 == 0) { days++; }
        }


        // remaining part 
        if(base_year % 4 == 0)
        {
            if(month_indices.second > 1) { days++; }
        }



        
    }




    int result_index = days % 7;
    string weekday = weekdays[result_index];

    printf("May 29, 2013 %s\n", weekday);

    return 0;
}

*/