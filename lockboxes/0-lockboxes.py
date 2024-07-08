#!/usr/bin/python3

"""
Lockboxes
"""


def canUnlockAll(boxes):
    """
    You have a number `n` of locked boxes in front of you. Each box is
    numbered sequentially from `0` to `n - 1` and each box may contain
    keys to the other boxes. This method determines if all the boxes can
    be opened.

    `boxes` is a list of lists:
    - A key with the same number as a box opens that box
    - We assume all keys will be positive integers
    - There can be keys that do not have boxes
    - The first box `boxes[0]` is unlocked

    Returns:
    - `True` if all boxes can be opened, or `False` otherwise
    """
    # If there are no boxes or just box 0, then we can "open all boxes"
    if len(boxes) == 0 or len(boxes) == 1:
        return True

    # If there is no key in box 0, we can't open all boxes
    if len(boxes[0]) == 0:
        return False

    # We always "have the key" to box 0 (it's always unlocked)
    unique_keys = [0]

    # Iterate over each unique key we have, starting from 0
    i = 0
    while i in range(len(unique_keys)):
        # For each key in the opened box
        for key in boxes[unique_keys[i]]:
            # Add the key to our keys if it's new and could open a box
            if key not in unique_keys and key < len(boxes):
                unique_keys.append(key)
        i += 1

    # If we have the key for each box, we can open all boxes
    if len(unique_keys) == len(boxes):
        return True
    else:
        return False
