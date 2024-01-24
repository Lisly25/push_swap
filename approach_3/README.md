***PUSH_SWAP***

Push_swap is a project in the curriculum of Hive Helsinki. The goal of the project is to write a program that takes as an argument a list of integers, and returns a list of instructions of the so-called "push swap language" that could be used to rearrange the inputted list into ascending order. Efficiency was also a concern: the aim was to be able to use as few of the commands as possible.

***The push swap language***

There are two stacks at our disposal which can store (parts of our) data: stack A and stack B. The inputted list will initially be located on stack A. The instructions we can use to move our numbers:

1. sa (swap a): swaps the first two elements of stack A (unless stack A contains one or less elements)
2. sb (swap b): swaps the first two elemenst of stack B (unless stack B contains one or less elements)
3. ss (swap a and b): executes sa and sb
4. pa (push a): the first element of stack b is moved to the top of stack a (unless stack b is empty). What used to be the first element of stack a now becomes the second; what was the second becomes the third; and so forth.
5. pb (push b): the first element of stack a is moved to the top of stack b (unless stack a is empty). What used to be the first element of stack b now becomes the second; what was the second becomes the third; and so forth.
6. ra (rotate a): All elements in stack a are shifted up. The first element becomes the last one.
7. rb (rotate b): All elements in stack b are shifted up. The first element becomes the last one.
8. rr (rotate a and b): execute ra and rb at the same time
9. rra (reverse rotate a): All elements in stack a are shifted down. The last element becomes the first one.
10. rrb (reverse rotate b): All elements in stack b are shifted down. The last element becomes the first one.
11. rrr (reverse rotate a and b): execute rra and rrb at the same time

***How the program works***

I. The input

The integer numbers to be sorted can be entered as individual arguments, or in a single string separated by spaces. Thus, these two methods are equivalent:

./push_swap "3 2 1"

OR

./push_swap 3 2 1

Some restricitions apply:
- the numbers must be integers (32-bit systems' range, so between –2147483648 and 2147483647)
- every number can only occur once in the list
If these requirements are not met, the program returns "Error"

If the numbers are already sorted, or no arguments are given, the prompt will simply be given back.

***How to use***

1. Clone this repository

2. Navigate inside the repository

3. Run the command "make"

4. From now on, you can use the push_swap executable with you choice of arguments. For example:

./push_swap 4 5 1 2 3

***Additional information***

The goal of the project was not only to be able to sort a list of numbers into ascending order using only the available commands, but to do it with as few commands as possible. For the highest points, this limits were:

3 elements - maximum 2 instructions

5 elements - maximum 12 instructions

100 elements - maximum 700 instructions

500 elements - maximum 5500 instructions

This program is close to conforming to these requirements: for 500 elements, depending on the initial order, it sometimes uses over 5500 instructions (but still under 6000) - however, the average number of instructions is under 5500.

***THE CHECKER PROGRAM***

A bonus assignment was to create a checker program, that can read the given sorting instructions from the standard input, and determine if they'd result in the list being sorted (returns "OK") or not ("KO"). Additionally, it'd return "Error" if the inputted list of numbers is invalid, or an instruction was used that is not part of the push swap language. I made my version of this checker program: however, an incorrect sequence of instructions can result in a segmentation fault - this issue is yet to be corrected.

***How to use the checker program***

1. Clone the repository (if you haven't yet)

2. Navigate inside the repository

3. Run the command "make bonus"

4. From now on, you can use the push_swap executable in one of two ways:

	4/a: Pipe it after the push_swap executable. Be sure to give both the same arguments for the intended behaviour:

		./push.swap 4 5 1 2 3 | ./checker 4 5 1 2 3

	5/a: Run it without the pipe, and then you can specify the sequence of commands by typing them into the terminal (seprarted by pressing enter). When you've done inputting the instructions, press control + D (in linux/mac OS)

		./checker 4 5 1 2 3