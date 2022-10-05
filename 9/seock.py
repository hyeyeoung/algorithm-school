from asyncio.windows_events import NULL
from operator import index, indexOf

r=open("9/1.inp",'r')
w=open("9/1.out",'w')
line=r.readline().rsplit()
line=list(map(int,line))

n=line[0]
m=line[1]
grid=[]
for i in range(n):
    line=r.readline().rstrip().split()
    line=list(map(int,line))
    grid.append(line)


np=[]
dp= [[0 for i in range(m)] for j in range(n)]
pp= [[0 for i in range(m)] for j in range(n)]
dp[0][0]=grid[0][0]
for i in range(1,m,1):
    if grid[0][i-1] == -1:
        grid[0][i] = -1
for i in range(1,n,1):
    if grid[i-1][0]==-1:
        grid[i][0]=-1
for i in range(1,n,1):
    for j in range(1,m,1):
        if grid[i-1][j]==-1 & grid[i][j-1]==-1:
            grid[i][j]=-1
if grid[n-1][m-1]==-1:
    w.write("No path.")
else:
    for i in range(n):     
        for j in range(m):              
            if i==0:
                dp[0][j]=dp[0][j-1]+grid[0][j]

            elif j==0:
                dp[i][0]=dp[i-1][0]+grid[i][0]
                 
            else:            
                if grid[i][j] != -1:
                    if grid[i][j-1]==-1:
                        dp[i][j]=dp[i-1][j]+grid[i][j]

                    elif grid[i-1][j]==-1:
                        dp[i][j]=dp[i][j-1]+grid[i][j]
                    else:             
                        dp[i][j]=min(dp[i-1][j],dp[i][j-1])+grid[i][j]

    w.write(str(dp[-1][-1])+"\n")

pp[n-1][m-1] = 1

for i in range(n-1,0,-1):    
    for j in range(m-1,0,-1):
        if pp[i][j] == 1:
            if i ==0& j ==0:
                pp[i][j] = 1
            elif i == 0 & j != 0:
                pp[i][j-1] = 1
            elif i != 0 & j ==0:
                pp[i-1][j] = 1
            else:
                if dp[i-1][j] == dp[i][j-1]:
                    pp[i-1][j] = 1
                elif dp[i][j]-grid[i][j] == dp[i-1][j]:
                    pp[i-1][j] = 1
                elif dp[i][j] - grid[i][j] == dp[i][j-1]:
                    pp[i][j-1] =1 
    for i in range(n):
        for j in range(m):
            if pp[i][j] == 1:
                w.write("("+str(i)+" "+str(j)+")\n")

