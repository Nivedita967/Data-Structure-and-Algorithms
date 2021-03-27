#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool match(string s, string p,  bool& retry) 
    {
		//if both are empty
        if(s.empty() && p.empty())
        {
            return true;
        }
        
		if(!p.empty())
		{
			if(s.empty())
			{
                // if p just has *s remaining then it's ok
                if(p[0]=='*')
				{
					return match(s, p.substr(1), retry);
				}
			}
			else
			{
				if(p[0]=='*')
				{	
                    p=p.substr(1);
                    int cur=0;
                    int l=s.length();
                    string str=s;
                    
                    // try to match the string after this * (if any)
                    // with the earliest substring in s
					while(cur<=l)
					{	
                        if(cur>0)
                        {
                            str=str.substr(1);
                        }
				
						if(match(str,p, retry))
						{
                            return true;
						}
						else if(!retry)
						{
                            // no point in retrying as this * could successfully find the string
                            // present between this * and the next * but some other * down the road
                            // couldn't find a match for its corresponding string
                            return false;
						}
						
						cur++;
					}
					
                    // set retry to false so that the caller doesn't retry
                    // as it finds that the match failed for the string after
                    // some * down the road
					retry=false;
				}
				else
				{
					if(p[0]!='?' && s[0] != p[0])
					{
						return false;
					}
					
                    // current char in p and s matches so check for the rest
					return match(s.substr(1), p.substr(1), retry);
				}
			}
		}
		
        return false;		
    }
	
	bool isMatch(string s, string p)
	{
		bool retry=true;
        //calling match 
		return match(s,p, retry);
	}
};