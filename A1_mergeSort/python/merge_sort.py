# Merge sort in python (My own code)
# To run, type "python merge_sort.py"
# Parameters are hard-coded

def merge(left_part, right_part):
    left_i = 0
    right_i = 0
    result = []

    # Compare the numbers from each array to put in the result array
    while left_i < len(left_part) and right_i < len(right_part):
        if left_part[left_i] <= right_part[right_i]:
            result.append(left_part[left_i])
            left_i += 1
        else:
            result.append(right_part[right_i])
            right_i += 1

    # If there is still numbers left in the subarrays
    if left_i < len(left_part):
        result.extend(left_part[left_i:])
    if right_i < len(right_part):
        result.extend(right_part[right_i:])

    return result

def merge_sort(arr):
    # we keep dividing the array until the length of the subarray is 1
    if len(arr) <= 1:
        return arr

    middle_i = len(arr) // 2
    left = arr[:middle_i]
    right = arr[middle_i:]

    # Call recursively the subarrays with merge_sort function
    left = merge_sort(left)
    right = merge_sort(right)

    return merge(left, right)

# main program
given_arr = [170, 45, 75, -90, -802, 24, 2, 66]
print("Original array:", given_arr)
print("Sorted array:", merge_sort(given_arr))