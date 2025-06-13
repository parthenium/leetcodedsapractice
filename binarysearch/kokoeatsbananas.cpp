#include<iostream>
#include<bits\stdc++.h>
using namespace std;

class Solution{
    public:
        int minEatingspeed(vector<int> piles, int h){
            int l = 1;
            int r = *max_element(piles.begin(), piles.end());
            int res = r;

            while (l <= r){
                int k = (l + r) / 2;
                long long totalTime = 0;

                for(int pile : piles){
                    totalTime += ceil(static_cast<double> (pile) / k);
                }

                if (totalTime <= h){
                    res = k;
                    r = k - 1;
                }
                else{
                    l = k + 1;
                }
            }
            return res;
        }
};