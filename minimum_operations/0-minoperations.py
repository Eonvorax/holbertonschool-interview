#!/usr/bin/python3
"""
Minimum operations
"""


def minOperations(n):
    """
    Calculate the minimum number of copy/paste operations to reach exactly
    n 'H' characters, starting from a single 'H' in the text editor.

    Return:
    - The minimal number of operations to reach n 'H' characters, or 0 if n
    can't be reached this way (meaning: n < 1).
    """
    clipboard = 0  # the number of 'H' characters currently in the clipboard
    text = 1  # the number of 'H' characters currently in the text editor
    op_count = 0  # the number of operations done ("Copy All" or "Paste")

    # While we haven't reached n 'H' characters
    while text < n:
        # If n is divisible by text
        if n % text == 0:
            # Copy all text to clipboard
            clipboard = text
            op_count += 1
        # Paste the content of the clipboard
        text += clipboard
        op_count += 1

    return op_count
