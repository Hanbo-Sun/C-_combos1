//
//  h3q3
//Suppose you are traveling in a country where currency is available only in coins of a number of different long integer values 0 < n1 < n2 < · · · < nk . You need to write a C++ program changeMoney (your C++ source code file must be named as changeMoney.cpp) which, given an long integer number N > 0, lists different ways that an amount of money of N can be provided in different combinations of coins. You may assume that all input arguments are positive long integer numbers and N is the first argument followed by n1,...,nk as the remaining arguments. You output is the total number of combinations. Example runs of valid input arguments are

// ref: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/

// 5 1 2
// 3

// 13 2
// 0

#include <iostream>
//#include <vector>
#include <cstdlib>
#include <cstring>

using namespace std;

long int count( long int S[], long int m, long int n )
{
    // table[i] will be storing the number of solutions for
    // value i. We need n+1 rows as the table is consturcted
    // in bottom up manner using the base case (n = 0)
    long int table[n+1];
    
    // Initialize all table values as 0
    memset(table, 0, sizeof(table));
    
    // Base case (If given value is 0)
    table[0] = 1;
    
    // Pick all coins one by one and update the table[] values
    // after the index greater than or equal to the value of the
    // picked coin
    for(long int i=0; i<m; i++)
        for(long int j=S[i]; j<=n; j++)
            table[j] += table[j-S[i]];
    
    return table[n];
}

// Driver program to test above function
int main(int argc, char* argv[])
{
    long int arr[argc-2];
    for (long int i=0;i<argc-2;i++)
    {
        arr[i] = (atoi(argv[i+2]));
    }
    long int m = sizeof(arr)/sizeof(arr[0]);
    long int n = atoi(argv[1]);
    int flag1 = 0;
    int flag2 = 0;
    if (n%10!=0)
        flag1 = 1;
    int j = 0;
    while (arr[j]%10 == 0 && j<argc-2) {
        ++j;
    }
    if (j>=argc-2)
        flag2 = 1;
    if (flag1==1 && flag2 ==1)
        cout<<"0";
    else
        cout<<count(arr, m, n);
    return 0;
}




