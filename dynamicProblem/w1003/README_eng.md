# problem
- There is a function of Fibonacci(n). If we called the fibo(3), then it would call the fibo(2) and fibo(1). Besides, the fibo(2) will call fibo(1) and fibo(0). The second called fibo(2) will return 1 and exit. Also, the fibo(0) is going to return 0 and exit.

- Finally, the fibo(3) called the fibo(2) and fibo(1) while returning 2. In this time,
the 1 is called twice and 0 is once.

- Thus, we should calculate the number of calls of 1 and 0 when called fibo(N)s. 

# condition
- fibo(N), (N : natural number, 0 <= N <= 40)

# input
line1: 4
line2: 0
line3: 1
line4: 3
line5: 10

- line1 means the number of testing cases. Below that are the test case, N.

# output
1 0
0 1
1 2
34 55
