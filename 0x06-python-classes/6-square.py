#!/usr/bin/python3
class Square:
    def __init__(self, size=0, position=(0, 0)):
        """Initializes a Square instance with optional size and position.

        Args:
            size (int, optional): The size of the square (default is 0).
            position (tuple, optional): The position of the square (default is (0, 0)).

        Raises:
            TypeError: If size is not an integer or if position is not a tuple of 2 positive integers.
            ValueError: If size is less than 0 or if position contains non-positive integers.
        """
        self.size = size  # Initialize size using the setter method
        self.position = position  # Initialize position using the setter method

    @property
    def size(self):
        """Getter method to retrieve the size of the square."""
        return self.__size

    @size.setter
    def size(self, value):
        """Setter method to set the size of the square.

        Args:
            value (int): The size value to be assigned.

        Raises:
            TypeError: If value is not an integer.
            ValueError: If value is less than 0.
        """
        if not isinstance(value, int):
            raise TypeError("size must be an integer")
        elif value < 0:
            raise ValueError("size must be >= 0")
        else:
            self.__size = value

    @property
    def position(self):
        """Getter method to retrieve the position of the square."""
        return self.__position

    @position.setter
    def position(self, value):
        """Setter method to set the position of the square.

        Args:
            value (tuple): A tuple of 2 positive integers representing the position.

        Raises:
            TypeError: If value is not a tuple of 2 positive integers.
            ValueError: If value contains non-positive integers.
        """
        if not isinstance(value, tuple) or len(value) != 2 or not all(isinstance(x, int) for x in value) or any(x < 0 for x in value):
            raise TypeError("position must be a tuple of 2 positive integers")
        else:
            self.__position = value

    def area(self):
        """Calculates and returns the area of the square."""
        return self.__size ** 2

    def my_print(self):
        """Prints the square with the character '#' using position."""
        if self.__size == 0:
            print()
        else:
            for _ in range(self.__position[1]):
                print()
            for _ in range(self.__size):
                print(" " * self.__position[0] + "#" * self.__size)

