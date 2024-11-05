def fibonacci_non_recursive(n):
    a, b = 0, 1
    print(a)
    
    for i in range(n-1):  # Adjusted to print n terms
        print(b)
        a, b = b, a + b

def fibonacci_recursive(n):
    if n<=1:
        return n
    return (fibonacci_recursive(n-1) + fibonacci_recursive(n-2))
n = 10
print("Non-Recursive Fibonacci series:")
fibonacci_non_recursive(n)
print("Recursive Fibonacci series:")

fibonacci_recursive(n)
for i in range(n):
    print(fibonacci_recursive(i))



