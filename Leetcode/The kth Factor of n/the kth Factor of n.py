
#Python program printing the kth factor of number
class Solution(object):
    def kthFactor(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: int
        """
        # l is empty list
        l=[]
        # Finding the factors of n and storing in l
        for i in range(1,n+1):
            if (n%i==0):
                l.append(i)
        # sorting the list l
        sorted(l)

        # checking if length of l is less than k
        if(len(l)<k):
            return -1;
        # return result
        return l[k-1]
    