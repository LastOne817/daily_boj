t = int(input())
for i in range(t):
    line = input().split()
    c = line[0]
    if c == '1':
        n = int(line[1])
        p = q = 1
        base = 1
        while base <= n // 4:
            base *= 2
        while base > 0:
            if n & base != 0:
                p += q
            else:
                q += p
            base //= 2
        print('Case #%d: %d %d' % (i + 1, p, q))
    else:
        p = int(line[1])
        q = int(line[2])
        n = 0
        base = 1
        while p > 1 or q > 1:
            if p > q:
                n += base
                p -= q
            else:
                q -= p
            base *= 2
        n += base
        print('Case #%d: %d' % (i + 1, n))
