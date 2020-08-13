#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /* Print number of possible ways to make change for N cents.*/
 
 int  solve(int A[],int n,int sum)
{
   
    int res[n+1][sum+1],ans=0;

    for(int i=0;i<=n;i++)
    res[i][0]=1; 
    
    for(int i=0;i<=sum;i++)
    res[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
     
            if(j<A[i-1]) 
               res[i][j]=res[i-1][j];
            else
               res[i][j]=res[i-1][j]+res[i][j-A[i-1]];

        }
    }

    return res[n][sum];
}

int main()
    {
    
        int t;
        cin>>t;
        while(t--)
        {
           int n,sum;
           cin>>n;

           int A[n];
           for(int i=0;i<n;i++)
              cin>>A[i];

            cin>>sum;  

           cout<<solve(A,n,sum)<<endl;
        }
	return 0;
}