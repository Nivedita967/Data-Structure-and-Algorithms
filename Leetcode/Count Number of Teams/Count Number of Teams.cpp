#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numTeams(vector<int>& rating) 
    {
        //taking size of vector 
        int N=rating.size();
        
        //declaration of vectors
        vector<int> larger(N,0);
        vector<int> smaller(N,0);
        
        //loop for forming teams
        for( int i=0;i<N-1;i++)
        {   
            for( int j=i+1;j<N;j++)
            {
                //if(rating[i]<rating[j]) ~~this is for understanding the logic
                if(rating[i]>rating[j])
                {    larger[i]++; } 
                else 
                {    smaller[i]++; }
            }
        }
        int team=0;
        
        //loop for counting number of teams
        for( int i=0;i<N-2;i++)
        {  
            for(int j=i+1;j<N-1;j++)
            {
                 //if(rating[i]<rating[j]) ~~this is for understanding the logic
                if(rating[i]>rating[j])
                {   team +=larger[j]; }
                else
                {    team +=smaller[j];}  
            }
        }

        //returning team
        return team;
    }
};