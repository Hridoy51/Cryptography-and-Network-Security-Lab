
import random
def robin_miller(p):
    if(p==1):
        return False
    if(p==3):
        return True
    if(p%2==0):
        return False
    s = 0
    d = p-1
    while(d%2==0):
        d//=2
        s+=1
    k = 10
    for _ in range(k):
        a = random.randint(2,p-2)
        temp = pow(a,d,p)
        if(temp == 1 or temp == p-1):
            continue
        for _ in range(s-1):
            temp = pow(temp,2,p)
            if(temp == p-1):
                break
            else:
                return False
    return True   


def main():
    p = input("Enter a number")
    print("\n")
    p = int(p)
    ans = robin_miller(p)
    if(ans):
        print("The number is prime")
    else:
        print("The number is Not Prime")
if __name__ == "__main__":
    main()