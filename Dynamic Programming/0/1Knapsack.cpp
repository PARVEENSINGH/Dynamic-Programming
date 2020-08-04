#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 ll solve(ll w[],ll val[],ll W,ll n)
{
    ll res[n+1][W+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
           if(i==0 || j==0)
           res[i][j]=0;

            else if(w[i-1]<=j)
           
               res[i][j]=max(val[i-1]+res[i-1][j-w[i-1]],res[i-1][j]);
            else

                res[i][j]=res[i-1][j];
        }
    }

    return res[n][W];
}

int main()
    {
    
        int t;
        cin>>t;
        while(t--)
        {
            ll n,W;
            cin>>n>>W;

            ll w[n],val[n];

            for(int i=0;i<n;i++)
            cin>>w[i];

            for(int i=0;i<n;i++)
            cin>>val[i];

            cout<<solve(w,val,W,n)<<endl;
        }
	return 0;
}