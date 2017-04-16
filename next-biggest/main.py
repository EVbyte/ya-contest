from itertools import permutations as per

n = input()
ps = [int(''.join(p)) for p in per(str(n))]
b = filter(lambda x: x > n, ps)
print(sorted(b)[0] if b else -1)
