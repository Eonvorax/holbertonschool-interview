#!/usr/bin/python3
"""
Changes come from within
"""


def makeChange(coins, total):
    """
    Given a pile of coins of different values, determine the fewest number
    of coins needed to meet a given amount total.
    - If total is 0 or less, return 0
    - If total cannot be met by any number of coins you have, return -1

    Returns:
        int: fewest number of coins needed to meet total
    """
    if total <= 0:
        return 0

    # Initialize dp array with infinity for all values except dp[0] which is 0
    dp = [float('inf')] * (total + 1)
    dp[0] = 0

    # For each coin, update the dp array for all possible amounts
    for coin in coins:
        for i in range(coin, total + 1):
            # updated with the smallest amount of coins
            dp[i] = min(dp[i], dp[i - coin] + 1)

    # If dp[total] is still infinity, the total cannot be made
    if dp[total] == float('inf'):
        return -1

    return dp[total]
