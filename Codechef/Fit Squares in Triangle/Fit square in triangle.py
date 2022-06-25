import math
for _ in range(int(raw_input())):
# Let consider the right angle isosceles triangle ABC with base 12. It has many layers of squares, each layer that may contain many squares,is'nt it
 squares=0
 base=int(raw_input())
 while base>2:#check for base whether is it less than two. when base is not two then no more square can be added to triangle.
	 squares+=math.floor((base-2)/2)
	 			# We have floor to avoid the decimal value 
				# We are reducing the base by 2 and divide by 2
	            # In single layer of a triangle,
	            # We minus 2, make sure we remove the part where we can't fit the square due to the slope in triangle
	            # Then we divide by two which caculate the number of square that can fit in that layer
	 base = base-2
	 			# Now we reduce the base by two, moving to above layer (like from bottom to top)
	            # And the loop continue till it reach the base equal to 2 where we can no more fit the square
 print int(squares)