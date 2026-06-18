def maxAbsoluteSum(nums):
    max_sum = 0
    min_sum = 0
    curr_max = 0
    curr_min = 0
    
    for num in nums:
        curr_max = max(curr_max + num, num)
        max_sum = max(max_sum, curr_max)
        
        curr_min = min(curr_min + num, num)
        min_sum = min(min_sum, curr_min)
    
    return max(abs(max_sum), abs(min_sum))

# Example test cases
print(maxAbsoluteSum([1,-3,2,3,-4]))  # Output: 5
print(maxAbsoluteSum([2,-5,1,-4,3,-2]))  # Output: 8
