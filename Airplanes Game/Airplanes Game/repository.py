class MatrixRepository:
    def __init__(self, randomMatrix,planeMatrix):
        self.__randomData=randomMatrix.getMatrix()
        self.__blind=randomMatrix.getBlind()
        self.__planeData=planeMatrix
    def planeHit(self,i,j):
        '''
        Hit made by the player
        :param i:
        :param j:
        :return:
        '''
        if self.__randomData[i][j]==1:
            return 1
        elif self.__randomData[i][j]==0:
            return -1
        else:
            return 2
    def randomHit(self,i,j):
        '''
        Hit made by the computer
        :param i:
        :param j:
        :return:
        '''
        if self.__planeData[i][j]==1:
            return 1
        elif self.__planeData[i][j]==0:
            return -1
        else:
            return 2
    def setElement(self,i,j,elem):
        self.__planeData[i][j]=elem
    def getP(self,i,j):
        return self.__planeData[i][j]
    def getB(self,i,j):
        return self.__blind[i][j]
    def setBlindIndex(self,i,j,el):
        self.__blind[i][j]=el
    def getRandomMatrix(self):
        return self.__randomData
    def getBlind(self):
        return self.__blind
    def getPlaneMatrix(self):
        return self.__planeData
    def blindHeadShot(self):
        k=0
        for i in range(7):
            for j in range(7):
                if self.__blind[i][j]==1:
                    k+=1
        return k
    def playerHeadShot(self):
        k = 0
        for i in range(7):
            for j in range(7):
                if self.__planeData[i][j] == 1:
                    k += 1
        return k
    def __str__(self):
        print('                         Player vs Computer')
        s=' '
        print('A','B','C','D','E','F','G','H','   ','A','B','C','D','E','F','G','H')
        k=0
        for i in range(8):
            k=k+1
            for j in range(8):
                if self.__planeData[i][j]==0:
                    s=s+'_'
                else:
                    s=s+str(self.__planeData[i][j])+' '
            s=s+'   '
            for j in range(8):
                if self.__planeData[i][j]==0:
                    s=s+'_'
                else:
                    s=s+str(self.__blind[i][j])+' '
            s=s+'\n'+str(k)
        return s
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