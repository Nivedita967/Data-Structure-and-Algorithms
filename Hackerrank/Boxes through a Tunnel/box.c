#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41
struct box
{
    /**
    * Define three fields of type int: length, width and height
    */
    int length;
    int width;
    int height;
}; 

typedef struct box box; //Define typedef 

int get_volume(box b) {
    /**
    * Return the volume of the box
    */
    return b.length * b.width * b.height; //Returing the result of multiplication of length,breadth and height
}

int is_lower_than_max_height(box b) {
    /**
    * Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
    */
    if(b.height<41) //Checking wheather it is less than 41
        return 1; // If so it will return true
    else
        return 0; // Else return false
}
int main()
{
	int n; //Declaring variable
	scanf("%d", &n); //asking user to enter how inputs does he going to give.
	box *boxes = malloc(n * sizeof(box)); //Alloacting memory to boxes.
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &boxes[i].length, &boxes[i].width, &boxes[i].height); //taking inputs of length,breadth and height
	}
	for (int i = 0; i < n; i++) {
		if (is_lower_than_max_height(boxes[i])) { //If the condition is true then it will print the result.
			printf("%d\n", get_volume(boxes[i]));
		}
	}
	return 0;
}
