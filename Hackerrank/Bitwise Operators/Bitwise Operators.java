import java.util.*;
public void BitOperators(int n, int k){
int  c = 0;
int d = 0;
int e = 0;
int b = n;
// c d and e will store and or and xor results repectively.
// iterate the loop

for(int a = 0 ; a < n ;a++){
    b = n;
    // iterate from end i.e b = n
    while (b > a){
        if (a&b<k && a&b>c){
            c = a&b;
        }
        if (a|b<k && a|b>d){
            d = a|b;
        }
        if (a|b<k && a|b>d){
            d = a|b;
        }
        if (a^b<k && a^b>e){
            e = a^b;
        }
        b = b -1;

    }
    
   
}
System.out.println(c);
System.out.println(d);
System.out.println(e);
}
   