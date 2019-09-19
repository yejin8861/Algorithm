#!/bin/python3

import math
import os
import random
import re
import sys


# Complete the minimumBribes function below.
def minimumBribes(q):
    for i in reversed(range(len(q))):
        if q[i] > q[i-1]:
            q[i-1], q[i] = q[i], q[i-1] # swap
            

    # print(answer)

if __name__ == '__main__':
    t = int(input())

    for t_itr in range(t):
        n = int(input())

        q = list(map(int, input().rstrip().split()))

        minimumBribes(q)
