mod = 1000000007

with open('input.txt') as f:
    N, K = [int(l) for l in f.readline().split()]
    A = [ int(l) for l in f.readline().split()]

A.sort()

prod = 1
if K % 2:
    prod *= A[-1]
    prod %= mod
    K -= 1
    A.pop()
if K > 1:
    lidx = 0
    ridx = 0
    if A[-1] > 0:
        while K > 1:
            K -= 2
            lprod = A[lidx] * A[lidx + 1]
            rprod = A[-1 - ridx] * A[-2 - ridx]
            if lprod > rprod:
                prod *= lprod
		prod %= mod
                lidx += 2
            else:
                prod *= rprod
		prod %= mod
                ridx += 2
    else:
        while K > 1:
            K -= 2
            prod *= (A[-1 - ridx] * A[-2 - ridx])
	    prod %= mod
            ridx += 2
            
print prod % mod
