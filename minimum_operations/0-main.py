#!/usr/bin/python3
"""
Main file for testing
"""

minOperations = __import__('0-minoperations').minOperations

n = 0
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 1
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 4
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 12
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 9
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 11
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 47
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 256
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))

n = 10001
print("Min # of operations to reach {} char: {}".format(n, minOperations(n)))
