t = int(input())
for i in range(t):
    n = int(input())
    if n % 2 != 0:
        ans1 = (n * n + 1) * n // 2
        ans2 = n * n + (n - 1) * (n - 1) * n // 2
        mid  = (1 + (n - 1) // 2 * (n + 1))
        print(int((ans1 + ans2 - mid) % 1000000007))
    else:
        ans1 = (n * n + 1) * n // 2
        ans2 = n * n + (n - 1) * (n - 1) * n // 2
        print(int((ans1 + ans2) % 1000000007))