from typing import List

class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        def binarySearch(arr, x):
            s, e = 0, len(arr)-1            
            while s <= e:
                m = (s + e) // 2
                if arr[m] == x:
                    return m
                elif arr[m] < x:
                    s = m + 1
                else:
                    e = m - 1
            return s
    
        i = binarySearch(arr, x)
        a, b = i - 1, i
        n = len(arr)

        while k > 0:
            if a < 0 or (b < n and abs(x - arr[a]) > abs(arr[b] - x)):
                b += 1
            else:
                a -= 1
            k -= 1

        a += 1

        return arr[a:b]





if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'findClosestElements')
