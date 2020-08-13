#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int BurstBallon(vector<int>& nums) {
        int n=nums.size();
        
        if(n==0)
            return 0;
        
        int res[n][n];
        memset(res,0,n*n*sizeof(int));
        
        int left,right;
        int l_val,r_val;
        
        for(int len=1;len<=n;len++)
        {
            for(int j=0;j<=n-len;j++)
            {
                int i=j+len-1;
                 /* this block is used to calculate all the values 
                  from j to j+len-1 such that a max can be found to  put in result array. */
                  for(int k=j;k<=i;k++)
                {
                    l_val=0;r_val=0;
                    left=1;right=1;
                    
                    if(j!=0)
                    {
                     left=nums[j-1];   
                    }
                    if(i!=n-1)
                    {
                        right=nums[i+1];
                    }
                    
                    if(k!=j)
                    {
                        l_val=res[j][k-1];
                    }
                    if(k!=i)
                    {
                        r_val=res[k+1][i];
                    }
                    
                    res[j][i]=max(l_val+r_val+left*nums[k]*right,res[j][i]);
                }
            }
        }
        return res[0][n-1];
    }
    
};

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,a;
        cin>>n;

        vector<int> A(n,0);

        for(int i=0;i<n;i++)
        {
            cin>>a;
            A.push_back(a);
        }

        Solution obj;

        cout<<obj.BurstBallon(A)<<endl;

    }
}