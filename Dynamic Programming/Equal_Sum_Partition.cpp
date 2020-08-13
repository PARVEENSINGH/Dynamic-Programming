#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /* Equal Subset Sum Problem*/
 
 string solve(int A[],int n,int sum)
{
   
    bool res[n+1][sum+1];
    string ans = "NO";

    /*It's included when the sum is possible using the
    single elemement only. But neither of it's preceeding 
    element can form.*/
    
    for(int i=0;i<=n;i++)
    res[i][0]=true; 
    
    for(int i=0;i<=sum;i++)
    res[0][i]=false;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
     
            if(A[i-1]>j) 
               res[i][j]=res[i-1][j];
            else
                res[i][j]=(res[i-1][j] || res[i-1][j-A[i-1]]);

        }
    }

    if(res[n][sum])
    return "YES";
    return "NO";
}

int main()
    {
    
        int t;
        cin>>t;
        while(t--)
        {
           int n,sum=0;
           cin>>n;

           int A[n];
           for(int i=0;i<n;i++)
           {
            cin>>A[i];
            sum+=A[i];
           }

           if(sum%2==0)
           cout<<solve(A,n,sum/2)<<endl;
           else 
           cout<<"NO"<<endl;
        }
	return 0;
}