#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int m=coins.size();
        if(m==0 || amount==0)
            return 0;
        
        unsigned long long res[m+1][amount+1];
        memset(res,0,sizeof(res));
        
        for(int i=0;i<=m;i++)
            res[i][0]=0;
        
        for(int i=0;i<=amount;i++)
            res[0][i]=INT64_MAX-1;
        
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=amount;j++)
            {
                if(j<coins[i-1])
                    res[i][j]=res[i-1][j];
                else
                    res[i][j]=min(res[i-1][j],res[i][j-coins[i-1]]+1);
            }
        }
        
//         for(int i=0;i<=m;i++)
//         {
//             for(int j=0;j<=amount;j++)
//                 cout<<res[i][j]<<" ";
//             cout<<endl;
//         }
        
        unsigned long long  ans=res[m][amount];
        if(ans==(INT64_MAX-1))
            return -1;
        return res[m][amount];
    }
}; 