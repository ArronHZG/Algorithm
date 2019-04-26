from typing import List
import unittest


class Solution:
    # find a+b+c=0
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted( nums )
        output = []
        a_i = 0
        while a_i < len( nums ):
            b_s, c_s = set(), set()
            temp_output = []
            for c in nums[a_i + 1:]:
                b = -(nums[a_i] + c)
                if b in c_s and b not in b_s:
                    temp_output.append( [nums[a_i], b, c] )
                    b_s.add( b )
                c_s.add( c )
            a_i += 1
            while a_i < len( nums ) and nums[a_i-1] == nums[a_i]:
                a_i += 1
            output.extend( reversed( temp_output ) )
        return output


class TestDict( unittest.TestCase ):
    def test_fun(self):
        input = [-1, 0, 1, 2, -1, -4]
        output = [
            [-1, -1, 2], [-1, 0, 1]
        ]
        answer = Solution().threeSum( input )
        self.assertEqual( output, answer )

    def test_fun1(self):
        input = [3, 0, -2, -1, 1, 2]
        output = [[-2, -1, 3], [-2, 0, 2], [-1, 0, 1]]
        answer = Solution().threeSum( input )
        self.assertEqual( output, answer )

    def test_fun2(self):
        input = [-6, 3, 3, 3, 3, 3]
        output = [[-6, 3, 3]]
        answer = Solution().threeSum( input )
        self.assertEqual( output, answer )

    def test_fun3(self):
        input = [0, 0, 0, 0]
        output = [[0, 0, 0]]
        answer = Solution().threeSum( input )
        self.assertEqual( output, answer )


if __name__ == '__main__':
    unittest.main()
