#!/usr/bin/python3
def add_tuple(tuple_a=(), tuple_b=()):
    new_tuple = ()
    tuple_1 = tuple_a + (0, 0)  # Ensure tuple_a has at least 2 elements
    tuple_2 = tuple_b + (0, 0)  # Ensure tuple_b has at least 2 elements

    new_tuple = (a[0] + b[0], a[1] + b[1])
    return new_tuple
