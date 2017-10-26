#!/usr/bin/python
import random
import sys

orig_stdout = sys.stdout
f = open('data.txt', 'w')
sys.stdout = f

for i in range(1000000):
    print(random.randint(0, 1000001))

sys.stdout = orig_stdout
f.close()
