# Word-Ladder
Originally done for UNSW COMP6771 Assignment 1

A program to build word ladders leveraging the C++ standard containers `std::vector`, `std::queue`, and `std::set` to complete this task.

A word ladder is a connection from one word to another word formed by changing one letter at a time with the constraint that at each step the sequence of letters still forms a valid word. For example, here is a word ladder connecting "code" to "data":
```
code -> cade -> cate -> date -> data
```
The program will ask the user to enter a start and a destination word, and then it should find a word ladder between them if one exists. By using an algorithm known as breadth-first search, you are guaranteed to find the shortest such sequence.
