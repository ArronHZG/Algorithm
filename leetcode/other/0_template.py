from typing import List
import unittest

class Solution:
    def sum(self,input:List[int])->int:
        sum = 0
        for item in input:
            sum+=item
        return sum


class TestDict(unittest.TestCase):
    def test_fun(self):
        input = [1,2]
        output = 3
        answer = Solution().sum(input)
        self.assertEqual(output, answer)

if __name__ == '__main__':
    unittest.main()
