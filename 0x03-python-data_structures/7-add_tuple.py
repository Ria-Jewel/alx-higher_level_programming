#!/usr/bin/python3

def add_tuple(tuple_a=(), tuple_b=()):
    a = tuple_a + (0, 0)  # Ensure tuple_a has at least 2 elements
    b = tuple_b + (0, 0)  # Ensure tuple_b has at least 2 elements

    result = (a[0] + b[0], a[1] + b[1])
    return result

