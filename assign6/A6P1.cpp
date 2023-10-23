#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout<<"enter number of racers :"<<endl;
    cin>>n;
    vector<vector<int>>dp(n,vector<int>(n,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            dp[i][j]=(j+1)*(dp[i-1][j-1]+dp[i-1][j]);

        }
    }
    int res=0;
    for(int i=0;i<n;i++)
    {
        res=res+dp[n-1][i];
    }
    cout<<"max ways:"<<res<<endl;
    cout<<"dp table"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }



}