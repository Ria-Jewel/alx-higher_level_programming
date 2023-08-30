#!/usr/bin/python3
class Node:
    def __init__(self, data, next_node=None):
        """Initializes a Node with data and an optional next_node.

        Args:
            data (int): The data value for the node.
            next_node (Node, optional): The next Node in the linked list (default is None).

        Raises:
            TypeError: If data is not an integer or if next_node is not None or a Node object.
        """
        self.data = data  # Initialize data using the setter method
        self.next_node = next_node  # Initialize next_node using the setter method

    @property
    def data(self):
        """Getter method to retrieve the data of the node."""
        return self.__data

    @data.setter
    def data(self, value):
        """Setter method to set the data of the node.

        Args:
            value (int): The data value to be assigned.

        Raises:
            TypeError: If value is not an integer.
        """
        if not isinstance(value, int):
            raise TypeError("data must be an integer")
        self.__data = value

    @property
    def next_node(self):
        """Getter method to retrieve the next_node of the node."""
        return self.__next_node

    @next_node.setter
    def next_node(self, value):
        """Setter method to set the next_node of the node.

        Args:
            value (Node or None): The next Node in the linked list.

        Raises:
            TypeError: If value is not None or a Node object.
        """
        if value is not None and not isinstance(value, Node):
            raise TypeError("next_node must be a Node object")
        self.__next_node = value


class SinglyLinkedList:
    def __init__(self):
        """Initializes an empty singly linked list."""
        self.head = None

    def sorted_insert(self, value):
        """Inserts a new Node into the correct sorted position in the list (increasing order).

        Args:
            value (int): The data value for the new Node.

        Raises:
            TypeError: If value is not an integer.
        """
        if not isinstance(value, int):
            raise TypeError("data must be an integer")

        new_node = Node(value)
        if self.head is None or value < self.head.data:
            new_node.next_node = self.head
            self.head = new_node
        else:
            current = self.head
            while current.next_node is not None and current.next_node.data < value:
                current = current.next_node
            new_node.next_node = current.next_node
            current.next_node = new_node

    def __str__(self):
        """Returns a string representation of the linked list."""
        result = ""
        current = self.head
        while current is not None:
            result += str(current.data) + "\n"
            current = current.next_node
        return result.rstrip("\n")  # Remove trailing newline if the list is empty


# Example usage:
if __name__ == "__main__":
    linked_list = SinglyLinkedList()
    linked_list.sorted_insert(5)
    linked_list.sorted_insert(2)
    linked_list.sorted_insert(8)
    linked_list.sorted_insert(1)

    print(linked_list)

