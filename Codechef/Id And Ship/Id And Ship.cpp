#include <iostream>
using namespace std;


int main(void) 
{
    int t;
    cin>>t;
    for(int i = 0; i < t;i++)
    {   
        char n;
        cin>>n;
        if(n == 'B' || n == 'b')
        {
            printf("BattleShip\n");
            
        }
        if(n == 'C' || n == 'c')
        {
            printf("Cruiser\n");
        }
        if(n == 'D' || n == 'd')
        {
            printf("Destroyer\n");
        }
        if(n == 'F' || n == 'f')
        {
            printf("Frigate\n");
        }
        
    }
}


