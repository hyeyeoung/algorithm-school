def Divide(a, b, c): 
    dp = [] 
    if b != 1:
        for d in range(c, int(a / b) + 1):
            div = Divide(a - d, b - 1, d)
            for ls in div:
                dp.append([d] + ls)
    else: 
        dp.append([a])
    return dp
def P(n, m):
    result = Divide(n, m, 1)
    l = len(result)
    w.write(str(l)+'\n')

f=open("1.inp","r")
w=open("addingways.out","w")
data=f.read().rstrip().split()
data=list(map(int,data))
ndata=[]
for i in range(0,len(data),2):
    ndata.append(data[i:i+2])



for i in range(len(ndata)-1):
    P(ndata[i][0],ndata[i][1])

#     for j in range(3):
# print(ndata)


    


