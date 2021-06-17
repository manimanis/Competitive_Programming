from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        def toparenthesis(mask):
            return "".join([")","("][v] for v in mask)

        def decrement(mask):
            rs = len(mask)
            i = rs-1
            carry = -1
            while i >= 0 and carry < 0:
                mask[i] -= 1
                if mask[i] < 0:
                    mask[i] = 1
                else:
                    carry = 0
                i -= 1

        def isvalid(mask):
            s = 0
            for v in mask:
                if v == 1:
                    s += 1
                elif s > 0:
                    s -= 1
                else:
                    return False
            return s == 0            
        
        mask = [1 if i < n else 0 for i in range(2*n)]
        res = [toparenthesis(mask)]
        while True:
            decrement(mask)
            if mask[0] == 0:
                break
            if isvalid(mask):
                res.append(toparenthesis(mask))

        return res


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'generateParenthesis')
