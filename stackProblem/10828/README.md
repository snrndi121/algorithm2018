# problem
- This problem test you that you can use essential functions of stack. It sounds really simple.
  Just keep below condtions in your mind.  

# condition
- There are 5 commands actually used in stack.
	(1) push : a operation to push data into stack
	(2) pop : a operation to pop data from a stack. At the same time, you have to print the top.
			  If there is no item, then you should print -1.
	(3) size : a operation to show how many stack has items.
	(4) empty : a operation to print 1 or 0.	
			    If it is no empty, 0 and the other is 1.
	(5) top : a operation to print a top of stack. 
			  If there is no element, then print -1.

# Input
- the first line is the number of commands, N. (1 <= N <= 10,000)

# Ouput 
- Print a result for every commands.

# Sample
- input
14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top

- output
2
2
0
2
1
-1
0
1
-1
0
3 

