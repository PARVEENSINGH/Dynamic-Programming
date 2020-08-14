#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        
        unordered_map<int ,int> map={{0,-1}};
        int sum=0;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            if(k)
                sum%=k;
            if(map.find(sum)!=map.end() && (i-map[sum])>1)
                return true;
            if(map.find(sum)==map.end())
                map[sum]=i;       
        }
        return false;
    }
};