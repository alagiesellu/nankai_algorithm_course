#include <iostream>
#include<vector>
//#include<math>
//#include <bits/stdc++.h>

using namespace std;
// Number of Eggs Must be less or Equal to the Number of floors:
int eggDrop(int n, int k) {
       // vector <vector<int>> dp (k+1, vector<int> (n+1,0));
       int dp[n + 1][k + 1];
        
        for(int i=1; i<k+1; i++){
            
            for(int j = 1; j<n+1; j++){
                
                if(i==1) 
                dp[i][j] = j;

                else if(j==1) 
                dp[i][j] = 1;
                
                else{
                    int mr = j; //from current
                    int lr = 1; //fron begining
                    int temp = 0; //temporary variable
                    int minn = 32767; //set a value maximum 
                    while(lr<=mr)
                    {
                        int mid = (lr+mr)/2;
                        int left = dp[i-1][mid-1]; 
                        int right= dp[i][j-mid];
                        
                        temp = 1 + max(left,right);
                       
                        if(left<right) 
                        lr = mid+1;
                        else mr = mid-1;
                        minn = min(minn, temp);

                    }
                    dp[i][j] = minn;
                }
            }
        }
        return dp[k][n];
    }
int main()
{
    int n, k;
    cout << "Enter the number of Eggs: = ";
    cin >> k;
    cout << "Enter the number of Floor: = ";
    cin >> n;
    int a = k;
    int y = eggDrop(n, k);
    cout << "The number of attempts to find pivot floor is:=" << y;
    /*if (y <= a)
    {
        cout << "The number of attempts to find pivot floor is:=" << y;
    }
    else
    {
        cout << "The number of eggs is not sufficient to perform the attempts";
        cout << "\nrequired attempt to find the pivot floor is  = " << y;
    }*/
}