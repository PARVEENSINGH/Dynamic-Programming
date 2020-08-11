#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /* Longest Common Subsequence*/
int m,n;

 ll solve(string a,string b)
{
    ll res[m+1][n+1],ans=0;
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
           if(i==0 || j==0)
           res[i][j]=0;

            else if(a[i-1]==b[j-1]) 
               res[i][j]=res[i-1][j-1]+1;
            else
                res[i][j]=max(res[i-1][j],res[i][j-1]);

        }
    }

    return res[m][n];
}

int main()
    {
    
        int t;
        cin>>t;
        while(t--)
        {
            cin>>m>>n;

            string a,b;
            cin>>a>>b;

            cout<<solve(a,b)<<endl;
        }
	return 0;
}