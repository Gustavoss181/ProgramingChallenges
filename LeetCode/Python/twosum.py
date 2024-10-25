from pyparsing import List

def twoSum(nums: List[int], target: int) -> List[int]:
    map = {}
    for i in range(len(nums)):
        n = nums[i]
        print(map.get(n))
        if n in map.keys():
            return [map.get(n), i]
        map[target - n] = i

print(twoSum([2,7,11,15], 9))