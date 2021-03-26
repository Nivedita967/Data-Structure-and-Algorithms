
#Python program for Final Prices With a Special Discount in a Shop
class Solution:
    def finalPrices(self, prices: List[int]) -> List[int]:
        #find the length
        n = len(prices)
        for i in range(n - 1):
	        j = i
            #checking if j is less that length-1
	        while j < n - 1:
		        j += 1
                #Calculating the discount
		        if prices[j] <= prices[i]:
			        prices[i] -= prices[j]
			        break
        #Return answer
        return prices

        