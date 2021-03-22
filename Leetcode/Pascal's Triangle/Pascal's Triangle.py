class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        pascal = []

        for i in range(numRows):
            if i == 0:
                array = [i + 1] #start the array by inserting the first array
                pascal.append(array)  #append array to result list
            else:
                array = [0] + array + [0]
                array = [sum(array[i:i+2]) for i in range(len(array)-1)] #list comprehension to sum and create array
                pascal.append(array) 
        return pascal