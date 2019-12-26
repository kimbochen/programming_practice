#!/usr/bin/env python
# coding: utf-8

import numpy as np

def p(x, mu):
    m = mu.shape[0]
    k = 1 / (1 * (2 * np.pi)**(3/2))
    sum_exp = 0
    
    for i in range(m):
        exp = -0.5 * ((x - mu[i])**2)
        sum_exp += np.exp(exp)
    
    return k * sum_exp

x1 = np.array([2.1, 3.3, 2.7, 0.5, 1.5])
x2 = np.array([0.2, 1.0, 1.2, 5.3, 4.7])
x3 = np.array([3.0, 2.9, 3.4, 0.0, 0.5])
x = np.array([1.4, 3.3, 3.0])

p_c1 = p(x[0], x1[:3]) * p(x[1], x2[:3]) * p(x[2], x3[:3])

p_c2 = p(x[0], x1[3:]) * p(x[1], x2[3:]) * p(x[2], x3[3:])

print(f"That {p_c1} > {p_c2} is {p_c1 > p_c2}.")
