path1 = './input.in';
file1 = open(path1, 'r');
contents1=file1.readlines()
starts = []
for i in range(len(contents1)):
    tstr = contents1[i].strip().split();
    if len(tstr) == 1:
        starts.append(i);

print(starts)
