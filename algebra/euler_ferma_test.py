import fractions

def phi(n):
    amount = 0
    for k in range(1, n + 1):
        if fractions.gcd(n, k) == 1:
            amount += 1
    return amount

def ET(n):
    def pred(a):
        return pow(a, (n - 1) // 2, n) in [n - 1, 1]
    return [x for x in range(1, n) if pred(x)]

def FT(n):
    def pred(a):
        return pow(a, n - 1, n) == 1
    return [x for x in range(1, n) if pred(x)]

if __name__=='__main__':
    # for n in range(3, 5000, 2):
    #     if len(ET(n)) * 8 == phi(n):
    #         if len(ET(2*n + 3)) * 15 == phi(2*n + 3):
    #             print(n)
    #             break
    print(ET(2047))
