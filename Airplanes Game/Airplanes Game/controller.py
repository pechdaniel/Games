import random
class MatrixController:
    def __init__(self,repo):
        self.__c=0
        self.__next = []
        self.__next.append(-1)
        self.__next.append(-1)
        self.__data = []
        self.__data.append(None)
        self.__data.append(None)
        self.__data.append(None)
        self.__data.append(None)
        self.__now=0
        self.__head = []
        self.__try = -1
        self.__inconv=False
        self.__round=0

        self.__blindRepo=repo.getBlind()
        self.__randomRepo=repo.getRandomMatrix()
        self.__planeRepo=repo.getPlaneMatrix()
        self.__repo=repo
        self.__pr=[]
        self.__pos=[]
        self.__pos.append(-1)
        self.__pos.append(-1)
        self.__value=True
        self.__counter=1
        self.__found=False
        self.__max=None
        l=[]
        for i in range(8):
            l.append(0)
        for i in range(8):
            self.__pr.append(l[:])
    def __str__(self):
        print('\n')
        print('                     Player vs Computer\n')
        s='1   '
        print('   ','A ','B ','C ','D ','E ','F ','G ','H ','        ','A ','B ','C ','D ','E ','F ','G ','H \n')
        k=1
        for i in range(8):
            k=k+1
            for j in range(8):
                if self.__planeRepo.get(i,j)==0:
                    s = s + '_' + '  '
                else:
                    s=s+str(self.__planeRepo.get(i,j))+'  '
            s=s+'     '+str(k-1)+'   '
            for j in range(8):
                if self.__blindRepo[i][j]==-1:
                    s = s + str(self.__blindRepo[i][j]) + ' '
                elif self.__blindRepo[i][j]==0:
                    s = s + '_' + '  '
                else:
                    s=s+str(self.__blindRepo[i][j])+'  '
            if k<=8:
                s=s+'\n'+str(k)+'   '
        s=s+'\n'
        return s
    def printRandom(self):
        s = '1   '
        print('   ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H','\n')
        k = 1
        for i in range(8):
            k = k + 1
            for j in range(8):
                if self.__randomRepo[i][j]==0:
                    s = s + '_' + ' '
                else:
                    s = s + str(self.__randomRepo[i][j]) + ' '
            if k <= 8:
                s = s + '\n' + str(k) + '   '
        return s
    def getRandom(self):
        return self.__randomRepo
    def blindHeadShot(self):
        k = 0
        for i in range(8):
            for j in range(8):
                if self.__blindRepo[i][j] == 1:
                    k += 1
        return k
    def playerHeadShot(self):
        k = 0
        for i in range(8):
            for j in range(8):
                if self.__pr[i][j] == 1:
                    k += 1
        return k
    def isHit(self,i,j):
        lst=self.__repo.converter(i,j)
        l=lst[0]
        c=lst[1]
        if self.__blindRepo[l][c]==0:
            if self.__randomRepo[l][c]==1 and self.__blindRepo[l][c]==0:
                self.__blindRepo[l][c]=1
                return 1
            elif self.__randomRepo[l][c]==0:
                self.__blindRepo[l][c]=-1
                return -1
            else:
                self.__blindRepo[l][c]=2
                return 2
        else:
            return 3

    def GameOver(self,playerMatrixHeadCount,blindMatrixHeadCount):
        if playerMatrixHeadCount==2:
            print("Jarvis has won this match!\nYou'll get him next time.")
            return -1
        elif blindMatrixHeadCount==2:
            print('You have won this match!')
            return 1
        return 0
    def converter(self,i,j):
        '''
        converts j into a number
        :param i:
        :param j:
        :return:
        '''
        lst=[]
        lst.append(None)
        lst.append(None)
        if j=='A' or j=='a':
            lst[1]=0
        elif j=='B' or j=='b':
            lst[1]=1
        elif j=='C' or j=='c':
            lst[1]=2
        elif j=='D' or j=='d':
            lst[1]=3
        elif j=='E' or j=='e':
            lst[1]=4
        elif j=='F' or j=='f':
            lst[1]=5
        elif j=='G' or j=='g':
            lst[1]=6
        elif j=='H' or j=='h':
            lst[1]=7
        lst[0]=i-1
        return lst

    def found(self,i,j,pos):
        if pos=='up':
            self.__pr[i + 1][j] = 2
            self.__pr[i + 1][j - 2] = 2
            self.__pr[i + 1][j + 2] = 2
            self.__pr[i + 1][j + 1] = 2
            self.__pr[i + 1][j - 1] = 2
            self.__pr[i + 2][j] = 2
            self.__pr[i + 3][j] = 2
            self.__pr[i + 3][j - 1] = 2
            self.__pr[i + 3][j + 1] = 2
        elif pos=='down':
            self.__pr[i - 1][j] = 2
            self.__pr[i - 1][j - 2] = 2
            self.__pr[i - 1][j + 2] = 2
            self.__pr[i - 1][j + 1] = 2
            self.__pr[i - 1][j - 1] = 2
            self.__pr[i - 2][j] = 2
            self.__pr[i - 3][j] = 2
            self.__pr[i - 3][j - 1] = 2
            self.__pr[i - 3][j + 1] = 2
        elif pos=='right':
            self.__pr[i][j-1]=2
            self.__pr[i-2][j-1]=2
            self.__pr[i-1][j-1]=2
            self.__pr[i+1][j-1]=2
            self.__pr[i+2][j-1]=2
            self.__pr[i][j-2]=2
            self.__pr[i][j-3]=2
            self.__pr[i-1][j-3]=2
            self.__pr[i+1][j-3]=2
        elif pos=='left':
            self.__pr[i][j+1]=2
            self.__pr[i-2][j+1]=2
            self.__pr[i-1][j+1]=2
            self.__pr[i+1][j+1]=2
            self.__pr[i+2][j+1]=2
            self.__pr[i][j+2]=2
            self.__pr[i][j+3]=2
            self.__pr[i-1][j+3]=2
            self.__pr[i+1][j+3]=2

    def AIW(self):
        if self.__found==False:
            self.__c = 0
            self.__next = []
            self.__next.append(-1)
            self.__next.append(-1)
            self.__data = []
            self.__data.append(None)
            self.__data.append(None)
            self.__data.append(None)
            self.__data.append(None)
            self.__now = 0
            self.__head = []
            self.__try = -1
            self.__inconv = False
            self.__round = 0
        self.__round += 1
        do=True
        if self.__found==False:
            repeat=True
            while repeat==True:
                repeat=False
                if self.__round<=10:
                    h1=random.randint(2,5)
                    h2=random.randint(2,5)
                    if self.__planeRepo.get(h1,h2)==1:
                        print('Computer head shot!')
                        self.__pr[h1][h2]=1
                        self.__planeRepo.set(h1,h2,'x')
                    elif self.__planeRepo.get(h1,h2)==0:
                        print('Computer miss!')
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pr[h1][h2] =-1
                    elif self.__planeRepo.get(h1,h2)=='x':
                        repeat=True
                    else:
                        print('Computer hit!')
                        self.__pr[h1][h2]=2
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pos[0]=h1
                        self.__pos[1]=h2
                        do=False
                        self.__found=True
                elif self.__round>10 and self.__round<=17:
                    h1 = random.randint(1, 6)
                    h2 = random.randint(1, 6)
                    if self.__planeRepo.get(h1, h2) == 1:
                        print('Computer head shot!')
                        self.__pr[h1][h2] = 1
                        self.__planeRepo.set(h1, h2, 'x')
                    elif self.__planeRepo.get(h1, h2) == 0:
                        print('Computer miss!')
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pr[h1][h2] = -1
                    elif self.__planeRepo.get(h1, h2) == 'x':
                        repeat = True
                    else:
                        print('Computer hit!')
                        self.__pr[h1][h2] = 2
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pos[0] = h1
                        self.__pos[1] = h2
                        do=False
                        self.__found=True
                elif self.__round>17:
                    h1 = random.randint(0, 7)
                    h2 = random.randint(0, 7)
                    if self.__planeRepo.get(h1, h2) == 1:
                        print('Computer head shot!')
                        self.__pr[h1][h2] = 1
                        self.__planeRepo.set(h1, h2, 'x')
                    elif self.__planeRepo.get(h1, h2) == 0:
                        print('Computer miss!')
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pr[h1][h2] = -1
                    elif self.__planeRepo.get(h1, h2) == 'x':
                        repeat = True
                    else:
                        print('Computer hit!')
                        self.__pr[h1][h2] = 2
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pos[0] = h1
                        self.__pos[1] = h2
                        do=False
                        self.__found=True

        if do==True and self.__found==True:
            i=self.__pos[0]
            j=self.__pos[1]
            self.__c+=1
            repeat=True
            while repeat==True and self.__c<=4 and self.__found==True:
                repeat=False
                if self.__c==1:
                    self.__next[0]=i-2
                    self.__next[1]=j
                elif self.__c==2:
                    self.__next[0]=i
                    self.__next[1]=j+2
                elif self.__c==3:
                    self.__next[0]=i+2
                    self.__next[1]=j
                elif self.__c==4:
                    self.__next[0]=i
                    self.__next[1]=j-2
                if self.__next[0]<0 or self.__next[0]>7 or self.__next[1]<0 or self.__next[1]>7:
                    self.__c+=1
                    self.__data[self.__c-1]=0
                    repeat=True
                else:
                    h1=self.__next[0]
                    h2=self.__next[1]
                    if self.__planeRepo.get(h1, h2) == 1:
                        print('Computer head shot!')
                        self.__pr[h1][h2] = 1
                        self.__found=False
                        self.__planeRepo.set(h1, h2, 'x')
                    elif self.__planeRepo.get(h1, h2) == 0:
                        print('Computer miss!')
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pr[h1][h2] = -1
                        self.__data[self.__c - 1] = 0
                    elif self.__planeRepo.get(h1, h2) == 'x':
                        self.__c+=1
                        self.__data[self.__c - 1] = 0
                        repeat = True
                    else:
                        print('Computer hit!')
                        self.__pr[h1][h2] = 2
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__data[self.__c - 1] = 1
                    if self.__c==4:
                        if self.__data[0] == 0 and self.__data[1] == 1 and self.__data[2] == 0 and self.__data[3] == 0:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 1)
                            t1.append(j + 2)

                            t2.append(i)
                            t2.append(j + 3)

                            t3.append(i + 1)
                            t3.append(j + 2)

                            t4.append(-1)
                            t4.append(-1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 0 and self.__data[1] == 1 and self.__data[2] == 1 and self.__data[
                            3] == 0:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 1)
                            t1.append(j + 1)

                            t2.append(i + 1)
                            t2.append(j + 3)

                            t3.append(i + 3)
                            t3.append(j + 1)

                            t4.append(i + 1)
                            t4.append(j - 1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 0 and self.__data[1] == 1 and self.__data[2] == 1 and self.__data[
                            3] == 1:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 1)
                            t1.append(j)

                            t2.append(-1)
                            t2.append(-1)

                            t3.append(-1)
                            t3.append(-1)

                            t4.append(-1)
                            t4.append(-1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 0 and self.__data[1] == 0 and self.__data[2] == 1 and self.__data[
                            3] == 1:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 1)
                            t1.append(j - 1)

                            t2.append(i + 1)
                            t2.append(j + 1)

                            t3.append(i + 3)
                            t3.append(j - 1)

                            t4.append(i + 1)
                            t4.append(j - 3)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 0 and self.__data[1] == 0 and self.__data[2] == 0 and self.__data[
                            3] == 1:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 1)
                            t1.append(j - 2)

                            t2.append(-1)
                            t2.append(-1)

                            t3.append(i + 1)
                            t3.append(j - 2)

                            t4.append(i)
                            t4.append(j - 3)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 1 and self.__data[1] == 1 and self.__data[2] == 0 and self.__data[
                            3] == 0:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 3)
                            t1.append(j + 1)

                            t2.append(i - 1)
                            t2.append(j + 3)

                            t3.append(i + 1)
                            t3.append(j + 1)

                            t4.append(i - 1)
                            t4.append(j - 1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 1 and self.__data[1] == 0 and self.__data[2] == 0 and self.__data[
                            3] == 0:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 3)
                            t1.append(j)

                            t2.append(i - 2)
                            t2.append(j + 1)

                            t3.append(-1)
                            t3.append(-1)

                            t4.append(i - 2)
                            t4.append(j - 1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 1 and self.__data[1] == 0 and self.__data[2] == 0 and self.__data[
                            3] == 1:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(i - 3)
                            t1.append(j - 1)

                            t2.append(i - 1)
                            t2.append(j + 1)

                            t3.append(i + 1)
                            t3.append(j - 1)

                            t4.append(i - 1)
                            t4.append(j - 3)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 0 and self.__data[1] == 0 and self.__data[2] == 1 and self.__data[
                            3] == 0:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(-1)
                            t1.append(-1)

                            t2.append(i + 2)
                            t2.append(j + 1)

                            t3.append(i + 3)
                            t3.append(j)

                            t4.append(i + 2)
                            t4.append(j - 1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 1 and self.__data[1] == 0 and self.__data[2] == 1 and self.__data[
                            3] == 1:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(-1)
                            t1.append(-1)

                            t2.append(i)
                            t2.append(j + 1)

                            t3.append(-1)
                            t3.append(-1)

                            t4.append(-1)
                            t4.append(-1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 1 and self.__data[1] == 1 and self.__data[2] == 0 and self.__data[
                            3] == 1:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(-1)
                            t1.append(-1)

                            t2.append(-1)
                            t2.append(-1)

                            t3.append(i + 1)
                            t3.append(j)

                            t4.append(-1)
                            t4.append(-1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        elif self.__data[0] == 1 and self.__data[1] == 1 and self.__data[2] == 1 and self.__data[
                            3] == 0:
                            t1 = []
                            t2 = []
                            t3 = []
                            t4 = []
                            t1.append(-1)
                            t1.append(-1)

                            t2.append(-1)
                            t2.append(-1)

                            t3.append(-1)
                            t3.append(-1)

                            t4.append(i)
                            t4.append(j - 1)

                            self.__head.append(t1)
                            self.__head.append(t2)
                            self.__head.append(t3)
                            self.__head.append(t4)
                        else:
                            self.__found = False
            repeat=True
            while repeat==True and self.__c>4 and self.__found==True:
                repeat=False
                self.__try+=1
                if self.__found==True and self.__try<=3:
                    h1 = self.__head[self.__try][0]
                    h2 = self.__head[self.__try][1]
                    if self.__planeRepo.get(h1, h2) == 1:
                        print('Computer head shot!')
                        self.__pr[h1][h2] = 1
                        self.found(h1,h2,self.__try)
                        self.__found = False
                        self.__planeRepo.set(h1, h2, 'x')
                    elif self.__planeRepo.get(h1, h2) == 0:
                        print('Computer miss!')
                        self.__planeRepo.set(h1, h2, 'x')
                        self.__pr[h1][h2] = -1
                    elif self.__planeRepo.get(h1, h2) == 'x':
                        repeat = True
                    else:
                        print('Computer hit!')
                        self.__pr[h1][h2] = 2
                        self.__planeRepo.set(h1, h2, 'x')
                else:
                    self.__found=False


    def AI1(self):
        self.__value=True
        while self.__value==True:
            self.__value=False
            i=random.randint(0,7)
            j=random.randint(0,7)
            if (i==0 and j==0) or (i==0 and j==7) or (i==7 and j==0) or (i==7 and j==7) or (i==1 and j==0) or (i==1 and j==1) or (i==0 and j==1)\
                or (i==6 and j==1) or (i==6 and j==0) or (i==7 and j==1) or (i==6 and j==7) or (i==6 and j==6) or (i==7 and j==6)\
                or (i==1 and j==7) or (i==1 and j==6) or (i==0 and j==6):
                self.__value=True
            if self.__planeRepo.get(i,j)!='x' and self.__value==False:
                if self.__planeRepo.get(i,j)==1:
                    self.__pr[i][j]=1
                    self.__planeRepo.set(i,j,'x')
                    return 1
                elif self.__planeRepo.get(i,j)==0:
                    self.__planeRepo.set(i,j,'x')
                    return -1
                else:
                    self.__planeRepo.set(i,j,'x')
                    return 2
            else:
                self.__value=True