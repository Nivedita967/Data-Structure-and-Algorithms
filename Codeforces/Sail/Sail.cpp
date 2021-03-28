#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    //declaration
   int t, sx, sy, ex, ey, time(-1);
    string wind;

    //input
    cin >> t >> sx >> sy >> ex >> ey >> wind;

    //loop for finding the earliest time 
    for (int i = 0; i < t; ++i)
    {
        switch (wind[i])
        {
         //if wind blows them to east    
        case 'E':
            if (sx < ex)
            {
                sx += 1;
            }
            break;
         //if wind blows them to south   
        case 'S':
            if (sy > ey)
            {
                sy -= 1;
            }
            break;
         //if wind blows them to west   
        case 'W':
            if (sx > ex)
            {
                sx -= 1;
            }
            break;
        //if wind blows them to north    
        case 'N':
            if (sy < ey)
            {
                sy += 1;
            }
            break;
        default:
            break;
        }
        //if it is stopped by an anchor
        if (sx == ex && sy == ey)
        {
            time = i + 1;
            break;
        }
    }

    //printing output
    cout << time << endl;
    return 0;
}