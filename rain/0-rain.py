#!/usr/bin/python3
"""
Calculate square units of rainwater
"""


def rain(walls):
    """
    """
    total_water = 0
    prev_wall = 0
    width = 0
    for wall in walls:
        if wall != 0:
            total_water += min(prev_wall, wall) * width
            # TODO Create a fake wall value, then add the difference to the total
            # if wall < prev_wall and width > 0:
            #     # total_water += prev_wall - wall
            prev_wall = max(prev_wall, wall)
            width = 0
        else:
            # The water's width
            width += 1

    return total_water
