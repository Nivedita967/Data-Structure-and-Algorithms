class Solution {
    public int countVowelStrings(int n) {
        //We will solve this question using induction
        //If we have a string of length k, then for string of length k+1,
        //we can add a before every string, e before the strings that start with e and so on
        //So lets start by initialising all of them as 1.
        int a=1, e=1,i=1,o=1,u=1;
        //Now while n>1, we will add each of them to the string of length k
        while(n>1){
            a= a+e+i+o+u; //It can be added to all strings
                // a->aa, e->ae, i->ai, o->ao, u->au
            e= e+i+o+u; //It can be added to strings starting with e or greater
                //e-> ee, i->ei, o->eo, u->eu
            i= i+o+u; //It can be added to strings starting with i or greater
                //i-> ii, o->io, u->iu
            o= o+u;//It can be added to strings starting with o or greater
                //o->oo, u->ou
            u= u;// u->uu
            n--; //Decreasing n
        }
        //Returning the final answer
        return a+e+i+o+u;
    }
}
