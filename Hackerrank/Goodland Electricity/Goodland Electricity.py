"""
Goodland is a country with a number of evenly spaced cities along a line. 
The distance between adjacent cities is 1 unit. There is an energy infrastructure project planning meeting, 
and the government needs to know the fewest number of power plants needed to provide electricity to the entire list of cities.
 Determine that number. If it cannot be done, return -1.


 You are given a list of city data. Cities that may contain a power plant have been labeled 1. Others not suitable for building a plant are 
 labeled 0. Given a distribution range of k, find the lowest number of plants that must be built such that all cities are served. 
 The distribution range limits supply to cities where distance is less than k.

"""
def pylons(k, arr):
    # Lenght of the city data array
    l_arr = len(arr)
    start = 0
    last_pylon = -1

    #  Minimize this total pylons
    total_pylons = 0
    # Calculate the distribution range
    while(start < l_arr):
        furthest = min(start+k-1, l_arr-1)

        for i in range(furthest, last_pylon, -1):
            # If the city can contain the powerplant
            if arr[i]:
                total_pylons += 1
                # start for the next pylon
                start = i+k
                # last index where pylon was located
                last_pylon = i
                break
            # If the index of the leftmost tower is not < k, then one or more of the leftmost cities will never be able to have electricity. Hence return -1
            else:
                return -1

    return total_pylons