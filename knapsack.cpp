// knapsack.cpp
// given n items where the i-th item has value vi and weight wi, computes and prints the maximum possible total value of a selected subset of items whose total weight equals exactly W, and prints 0 if such subset of items does not exist. get its input from cin.The input is a sequence of positive integers in the order of   W n v1 w1 v2 w2 ... vn wn.
// ref: http://www.geeksforgeeks.org/dynamic-programming-set-10-0-1-knapsack-problem/


//core logic: in matrix k[n][w] %save first i item largest sum values with weight sum w
// if i == 0 or w == 0 initialize = 0;
// else if wt = w then K[i][w]=max(v[i-1],k[i-1][w]) %v[i-1] when first i-1 item cannot be weight w, else compare
//if wt<w, then concer if k[i-1][w-wt[i-1]] exist or not, if exist then compare include or exclude item i; if not exist, K[i][w]=K[i-1][w] (even if K[i-1][w] == 0,it make sense.
//if wt[i-1]>w then cannot include item i.

// test
// 3 4 1 1 1 2 2 1 2 2

// 3 4   1 1   1 2   2 1   2 2

//4

// 5 2 1 2 1 4
//0

//large number of points
//100000 50 70 60 50 84 5 70 35 61 58 38 52 52 33 13 76 79 74 78 85 100 84 6 65 25 66 18 43 17 80 58 32 21 66 91 38 2 47 68 11 35 73 85 48 4 100 17 51 38 1 44 92 91 80 97 38 10 54 85 7 21 9 41 8 14 27 23 8 3 45 16 24 58 39 80 38 98 15 83 3 18 36 28 84 71 87 23 47 57 15 9 72 33 91 56 79 8 32 39 72 85
//0
//large weights
//1000000 3 10000 100 10 1 1 1000
//execeed range
//100000 2 1 2 3 2
//0

//concer about recursion(when weight is larger than...) + overlap

#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>
using namespace std;

// A utility function that returns maximum of two integers
int max(int a, int b) { return (a > b)? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, int wt[], int val[], int n)
{
    int i, w;
    int K[n+1][W+1];
    for (i = 0; i <= n; i++)
    {
        for (w = 0; w <= W; w++)
        {
            if (i==0 || w==0)
            {
                K[i][w] = 0;
            
            }
            else
            {
                if(wt[i-1]==w)
                {
                    K[i][w] = max(val[i-1],K[i-1][w]);
                }
                if(wt[i-1]<w)
                {
                    if(K[i-1][w-wt[i-1]]>0)
                    {
                        K[i][w] = max(val[i-1]+K[i-1][w-wt[i-1]],K[i-1][w]);}
                    else
                    {K[i][w] = K[i-1][w];}
                }
                if(wt[i-1]>w)
                {
                    K[i][w] = K[i-1][w];
                }
                    
                
            }
        }
    }
    // Build table K[][] in bottom up manner
        return K[n][W];
}


int main() {
    int tok;
    vector<int> ve;
    while(cin>>tok)
    {
        ve.push_back(tok);
    }
    int nn = (ve.size()-2)/2;
    int v[nn];
    int w[nn];
    for (int i=0; i<nn; i++)
    {
        v[i] = ve[2*(i+1)];
      //  cout<<v[i]<<endl;
        w[i] = ve[2*(i+1)+1];
    }
    int W = ve[0];
    int n = ve[1];
    int sumw = 0;
    for (int i = 0; i < n; i++)
    {sumw += w[i];}
    if(sumw<W)
    {cout<<0;}
    else{cout<<knapSack(W, w, v, n);}
    //else
        //cout<<knapSack2(W, w, v, n); //if W is very large
    
    return 0;
}
