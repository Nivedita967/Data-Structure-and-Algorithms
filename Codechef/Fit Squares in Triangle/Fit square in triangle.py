import math
for _ in range(int(raw_input())):
 squares=0
 base=int(raw_input())
 while base>2:
	 squares+=math.floor((base-2)/2)
	 base = base-2
 print int(squares)