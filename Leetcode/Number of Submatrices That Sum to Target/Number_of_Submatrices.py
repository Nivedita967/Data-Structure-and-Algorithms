
# Python program for Number of Submatrices That Sum to Target
def numSubmatrixSumTarget(self, matrix, k):
      #Finding rows and columns length
        rows = len(matrix)
        columns = len(matrix[0])

        co = 0
        #Storing prefix sum for each index along row
        for i in range(columns):
            columnsum = [0] * rows
            for j in range(i, columns):
                ht = collections.defaultdict(int)
                rowsum = 0
                ht[0] = 1

                #We can now simply use the prefix sum of each row to calculate 
                #the matrix sum between the "start" column and "end" column
                for r in range(rows):
                    columnsum[r] += matrix[r][j]
                    rowsum += columnsum[r]
                    co += ht[rowsum-k]
                    ht[rowsum] += 1
                    
        return co

matrix = input('Enter number of posts')
k = input('Enter number of colours')
print(numSubmatrixSumTarget(matrix,k))

