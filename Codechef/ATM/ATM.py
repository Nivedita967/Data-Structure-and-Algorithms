# reading withdrawal amount and account balance
x,y=map(float,input().split())

# this will check if account balance is less than the withdrawal amount or 
# withdrawal amount is multiple of 5 and print the current account balance
if(x+0.5>=y or x%5!=0 or y<=0):

  # printing the result upto two decimals
	print("%.2f"%y)

# otherwise transaction will take place and print updated account balance
else:
	y=y-x-0.50
  
  # printing the result upto two decimals
	print("%.2f"%y)
