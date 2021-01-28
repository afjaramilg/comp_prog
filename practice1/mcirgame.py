def fact(n):
    acum = 1;
    for i in range(1, n+1):
        acum*=i;    
    return acum;
    
def catalan(n):
    factn = fact(n)*fact(n);
    print(int((fact(2*n))/(factn*(n+1))));
    

n = int(input());
while(n>-1):
    catalan(n);
    n = int(input());
        
        
        
        
