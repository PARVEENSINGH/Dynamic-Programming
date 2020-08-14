#include <iostream>
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
 /* Maximum contiguous subarray problem (Kadane's algorithm)*/
 
 int Kadane(int A[],int n)
{
   
   int res=INT_MIN;
   int track_pointer=0;

   for(int i=0;i<n;i++)
   {
       track_pointer+=A[i];
       
       res=max(res,track_pointer);
       if(track_pointer<0)
       track_pointer=0;
   }

 return res;
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
            cin>>A[i];
        

          
           cout<<Kadane(A,n)<<endl;
          
        }
	return 0;
}