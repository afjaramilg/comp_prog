file_name1 = input("your ans? ")
file_name2 = input("true ans? ")

path1 = './'+file_name1;
path2 = './'+file_name2;

file1 = open(path1, 'r');
contents1=file1.readlines()
my_ans= set(contents1);


file2 = open(path2, 'r')
contents2=file2.readlines()
t_ans= set(contents2)


print("YOU dont have")
for i in t_ans - my_ans:
    print(i)

print('\n-----------------------------------\n')
print("YOU DO have")    
for i in my_ans - t_ans:
    print(i)
