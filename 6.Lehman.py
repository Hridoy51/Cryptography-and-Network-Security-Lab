import random
import math

# Lehmann primality test function
def lehman(x):
    t = 500  # Number of iterations
    n = t
    while n > 0:
        a = random.randint(2, x - 2)
        temp = pow(a, (x - 1) // 2, x)
        if temp != 1 and temp != x - 1:
            print("It is not a prime number.")
            return 0.0
        
        n -= 1
    return 1 - pow(0.5, t)

def main():
    random.seed()  # Initialize random seed
    x = int(input("Enter a number to check: "))
    ans = lehman(x)
    if ans != 0.0:
        print(f"The number is prime with a probability of {ans:.6f}")

if __name__ == "__main__":
    main()
