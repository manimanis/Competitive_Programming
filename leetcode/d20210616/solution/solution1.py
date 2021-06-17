from typing import List
import functools


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        
        @functools.lru_cache
        def generate(n: int) -> List[str]:
            if n == 0: return ['']
            if n == 1: return ['()']
            
            result = []
            for x in range(n):
                for l in generate(x):
                    for r in generate(n-1-x):
                        result.append("(" + l + ")" + r)
            
            return result
        
        return generate(n)


if __name__ == '__main__':
    import os
    import testcases.utils as utils
    testcases = utils.extract_testcases(__file__)
    utils.execute_tests(testcases, Solution, 'generateParenthesis',
                        prepare_out=lambda o: sorted(o),
                        prepare_res=lambda r: sorted(r))
