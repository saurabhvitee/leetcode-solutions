class Solution(object):
    def twoSum(self, nums, target):
        dict = {}
        for i in range(len(nums)):
            if nums[i] in dict:
                return dict[nums[i]],i
            else:
                dict[target - nums[i]] = i
        