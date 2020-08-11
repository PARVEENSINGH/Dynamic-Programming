#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /* Longest Increasing Subsequence*/
int m,n;

 ll solve(ll A[] )
{
    int ans=0,prev=0;
    ll temp=A[0];

    for(int i=1;i<n;i++)
    {
        if(temp<=A[i])
        {
            prev++;
            temp=A[i];
        }
        // else
        // {
        //     ans=max(ans,prev);
        //     //prev=0;
        // }
        
    }

    return prev+1;
}

int main()
    {
    
        int t;
        cin>>t;
        while(t--)
        {
            cin>>n;

            ll A[n];

            for(int i=0;i<n;i++)
            cin>>A[i];

            cout<<solve(A)<<endl;
        }
	return 0;
}