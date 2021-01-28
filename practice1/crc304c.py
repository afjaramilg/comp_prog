#http://codeforces.com/contest/304/problem/C
matrix = []

def permsnorep(base, dest, size):
    if len(dest) == size:
        matrix.append(dest)
    else:
        for ch in range(0, len(base)):
          permsnorep(base[:ch] + base[ch + 1:], dest + base[ch], size)
