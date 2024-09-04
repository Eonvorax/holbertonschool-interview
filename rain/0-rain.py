#!/usr/bin/python3
"""
Calculate square units of rainwater
"""


def rain(walls):
    """
    Calculate the total amount of rainwater retained after it rains.
    """
    if not walls:
        return 0

    total_water = 0
    left = 0
    right = len(walls) - 1

    # Keep track of max height so far, on left and right
    left_max = walls[left]
    right_max = walls[right]

    # while we haven't crossed the whole structure
    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                # NOTE Current wall is shorter, calculating water trapped
                total_water += left_max - walls[left]
            # Move left pointer to the right
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                total_water += right_max - walls[right]
            # Move right pointer to the left
            right -= 1

    return total_water
