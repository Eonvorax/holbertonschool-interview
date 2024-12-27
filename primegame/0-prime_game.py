#!/usr/bin/python3
"""
Prime game
"""


def sieve_of_eratosthenes(n):
    """
    Generate all prime numbers up to n using the Sieve of Eratosthenes.

    Returns:
        A list of booleans where the index is the number and the value
        is True if the number is prime, False otherwise.
    """
    # Initialize a list of booleans representing numbers up to n
    primes = [True] * (n + 1)

    # NOTE 0 and 1 are not prime numbers
    primes[0], primes[1] = False, False

    for i in range(2, int(n ** 0.5) + 1):
        if primes[i]:
            for j in range(i * i, n + 1, i):
                primes[j] = False
    return primes


def isWinner(x, nums):
    """
    Maria and Ben are playing a game. Given a set of consecutive integers
    starting from 1 up to and including n, they take turns choosing a prime
    number in the set and removing that number and its multiples from the set.
    The player that removes the last prime number from the list is the winner.

    Args:
        x (int): the number of rounds to play.
        nums (list of ints): an array of n.

    Returns:
        - The name of the player that won the most rounds, or
        - None if the winner cannot be determined
    """
    if not nums or x < 1:
        return None

    score_maria = 0
    score_ben = 0

    # Prepare prime numbers up to the maximum possible n
    n = max(nums)
    primes = sieve_of_eratosthenes(n)

    # Precompute the number of primes up to each number
    prime_count = [0] * (n + 1)
    for i in range(1, n + 1):
        prime_count[i] = prime_count[i - 1] + (1 if primes[i] else 0)

    for num in nums:
        # Determine the total number of primes up to num
        total_primes = prime_count[num]

        # Maria scores if the number of primes is odd, Ben if it's even
        if total_primes % 2 == 1:
            score_maria += 1
        else:
            score_ben += 1

    if score_maria > score_ben:
        return "Maria"
    elif score_maria < score_ben:
        return "Ben"
    else:
        # No winner can be determined, return None
        return None
