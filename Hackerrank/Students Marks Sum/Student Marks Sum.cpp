#include <bits/stdc++.h>

//Complete the following function.

int marks_summation(int* marks, int number_of_students, char gender) {
  //Write your code here.
    //First determine the gender and accordlingly set your start index.
    int i; //Start Index
    if (gender == 'b'){
        i=0;
    }
    else {
        i=1;
    }
    int sum =0; //Variable to store the sum of marks of boys/girls.
    for (int j=i;j< number_of_students;j+=2){
        sum+=marks[j];
    }
    return sum;
}

int main() {
    int number_of_students;
    char gender;
    int sum;
  
    scanf("%d", &number_of_students);
    int *marks = (int *) malloc(number_of_students * sizeof (int));
 
    for (int student = 0; student < number_of_students; student++) {
        scanf("%d", (marks + student));
    }
    
    scanf(" %c", &gender);
    sum = marks_summation(marks, number_of_students, gender);
    printf("%d", sum);
    free(marks);
 
    return 0;
}