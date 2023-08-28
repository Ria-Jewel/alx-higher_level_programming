#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    """
    Divides two lists element by element and handles exceptions.
    
    Args:
        my_list_1 (list): The first list.
        my_list_2 (list): The second list.
        list_length (int): The number of elements to divide.
        
    Returns:
        A new list of length list_length containing all the divisions.
    """
    new_list = []  # Initialize an empty list to store the results of division.
    
    for i in range(0, list_length):
        try:
            div = my_list_1[i] / my_list_2[i]  # Try to perform division, and handle exceptions.
        except TypeError:
            print("wrong type")
            div = 0
        except ZeroDivisionError:
            print("division by 0")
            div = 0
        except IndexError:
            print("out of range")
            div = 0
        finally:
            new_list.append(div)  # Append the result (or 0 if an exception occurred) to the new list.
    
    return new_list  # Return the new list containing the divisions.

