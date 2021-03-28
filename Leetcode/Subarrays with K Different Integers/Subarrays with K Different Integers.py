#Problem:https://leetcode.com/problems/subarrays-with-k-different-integers/description/
class Solution:
    def subarraysWithKDistinct(self, A: 'List[int]', K: 'int') -> 'int':
        far, near, ans, maps = 0, 0, 0, {}
        
        # use hashmap to save the subarray
        # two flags, far and near
        # far means the farest pointer that the subarray has K elements
        # near means the nearest pointer that the subarrary has K elments
        for item in A:
            # add element in maps
            maps[item] = maps.get(item,0) + 1
            # if there are more than K elements in the array, delete the nearest one in the map, init the new flags
            if len(maps) >K:
                del maps[A[near]]
                near += 1
                far = near
            # if the length of array is K
            # use near - far to count the sub-arrays in this right flag(item)
            if len(maps) == K:
                while maps[A[near]] > 1:
                    maps[A[near]] -= 1
                    near += 1
                ans += near - far + 1
        return ans
