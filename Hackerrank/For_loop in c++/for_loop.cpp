/*

A for loop is a programming language statement which allows code to be repeatedly executed.

The syntax is

for ( <expression_1> ; <expression_2> ; <expression_3> )
    <statement>


 expression_1 is used for intializing variables which are generally used for controlling the terminating flag for the loop.
 expression_2 is used to check for the terminating condition. If this evaluates to false, then the loop is terminated.
 expression_3 is generally used to update the flags/variables.

 
A sample loop is

for(int i = 0; i < 10; i++) {
    ...
}

*/

#include <iostream>
using namespace std;
 
int main () {
   // for loop execution
   for( int a = 10; a < 20; a = a + 1 ) {
      cout << "value of a: " << a << endl;
   }
 
   return 0;
}

// Author: Shabi Kaushal (msbuddhu)