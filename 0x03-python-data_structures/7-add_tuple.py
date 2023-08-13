#!/usr/bin/python3

def add_tuple(tuple_a=(), tuple_b=()):
    a = tuple_a + (0, 0)  # Ensure tuple_a has at least 2 elements
    b = tuple_b + (0, 0)  # Ensure tuple_b has at least 2 elements

    result = (tuple_a[0] + tuple_b[0], tuple_a[1] + tuple_b[1])
    return result

