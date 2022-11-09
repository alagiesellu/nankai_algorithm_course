#include <iostream>
//#include<math>
//#include <bits/stdc++.h>

using namespace std;

int max(int a, int b)
{
   return(a>b)? a:b;
}

int eggDrop(int n, int k)
{
    int dp [n+1][k+1];
    
    for (int i =0; i<n; i++)
    {
        dp[i][1]=i; //for only one egg
    }
    
    for (int j =0; j<k; j++)
    {
        dp[1][j]=1; //for a one floor
    }
    for(int i =2; i<n+1; i++)
    { //floor
        for(int j = 2; j<k+1; j++)
        { //egg
           // if(j>=i)
            //{
            //dp[i][j]= dp[i] [j-1];
            //}
            //else
            //{
                int mini = INT_MAX;

                for(int x = 1; x<=j; x++) //fordward backward calculation
                {
                    int eggbroken = dp[x-1][j-1];
                    int eggsurvive= dp[i-x][j];
 
 res= max(eggbroken, eggsurvive)+1;
                    
                    if(res < mini)
                    {
                   mini = res;
                    }
                //}
                dp[i][j]=mini;
            }
            
        }
    }
    cout<<dp[n][k]<<"\n";
    return dp[n][k];
}

int main()
{
int n, k ;
cin >>  n;
cin >> k ;
int x = eggDrop(n, k);
cout<< "The number of attempts to find pivot floor is:=" << x;
}