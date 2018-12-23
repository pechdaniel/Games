import random
class Plane:
    def __init__(self,head,tail):
        self.__head=head
        self.__tail=tail
        self.__lines=None
        self.__columns=None
        l = []
        if head[0]<tail[0]:
            for i in range(4):
                l.append([])
            for i in range(4):
                for j in range(5):
                    l[i].append(0)
            for i in range(4):
                for j in range(5):
                    if i==0 and j==2:
                        l[i][j]=1
                    elif i==1 and (j==0 or j==1 or j==3 or j==4):
                        l[i][j]=4
                    elif j==2 and (i==1 or i==2 or i==3):
                        l[i][j]=2
                    elif i==3 and (j==1 or j==3):
                        l[i][j]=3
                    else:
                        l[i][j]=0
            lst=[]
            lst.append(head[0])
            lst.append(head[1]-2)
            if lst[0]<0 or lst[0]>4 or lst[1]<0 or lst[1]>3:
                lst=[]
                lst.append(-1)
                lst.append(-1)
            self.__corner=lst
            self.__lines=4
            self.__columns=5
        elif head[0]>tail[0]:
            for i in range(4):
                l.append([])
            for i in range(4):
                for j in range(5):
                    l[i].append(0)
            for i in range(4):
                for j in range(5):
                    if i == 3 and j == 2:
                        l[i][j] = 1
                    elif i == 2 and (j == 0 or j == 1 or j == 3 or j == 4):
                        l[i][j] = 4
                    elif j == 2 and (i == 1 or i == 2 or i == 0):
                        l[i][j] = 2
                    elif i == 0 and (j == 1 or j == 3):
                        l[i][j] = 3
                    else:
                        l[i][j] = 0
            lst = []
            lst.append(tail[0])
            lst.append(tail[1] - 2)
            if lst[0]<0 or lst[0]>4 or lst[1]<0 or lst[1]>3:
                lst=[]
                lst.append(-1)
                lst.append(-1)
            self.__corner = lst
            self.__lines=4
            self.__columns=5
        elif head[1]<tail[1]:
            for i in range(5):
                l.append([])
            for i in range(5):
                for j in range(4):
                    l[i].append(0)
            for i in range(5):
                for j in range(4):
                    if j==0 and i==2:
                        l[i][j]=1
                    elif j==1 and (i==0 or i==1 or i==3 or i==4):
                        l[i][j]=4
                    elif i==2 and (j==1 or j==2 or j==3):
                        l[i][j]=2
                    elif j==3 and (i==1 or i==3):
                        l[i][j]=3
            lst = []
            lst.append(head[0]-2)
            lst.append(head[1])
            if lst[0]<0 or lst[0]>3 or lst[1]<0 or lst[1]>4:
                lst=[]
                lst.append(-1)
                lst.append(-1)
            self.__corner = lst
            self.__lines=5
            self.__columns=4
        elif head[1]>tail[1]:
            for i in range(5):
                l.append([])
            for i in range(5):
                for j in range(4):
                    l[i].append(0)
            for i in range(5):
                for j in range(4):
                    if j == 3 and i == 2:
                        l[i][j] = 1
                    elif j == 2 and (i == 0 or i == 1 or i == 3 or i == 4):
                        l[i][j] = 4
                    elif i == 2 and (j == 1 or j == 2 or j == 0):
                        l[i][j] = 2
                    elif j == 0 and (i == 1 or i == 3):
                        l[i][j] = 3
            lst = []
            lst.append(tail[0] - 2)
            lst.append(tail[1])
            if lst[0]<0 or lst[0]>3 or lst[1]<0 or lst[1]>4:
                lst=[]
                lst.append(-1)
                lst.append(-1)
            self.__corner = lst
            self.__lines=5
            self.__columns=4
        self.__form=l[:]

    def getAll(self):
        return self.__form
    def getHeadLine(self):
        return self.__head[0]
    def getHeadColumn(self):
        return self.__head[1]
    def getTailLine(self):
        return self.__tail[0]
    def getTailColumn(self):
        return self.__tail[1]
    def get(self,i,j):
        return self.__form[i][j]
    def getCorner(self):
        return self.__corner
    def getLines(self):
        return self.__lines
    def getColumns(self):
        return self.__columns


class Matrix(Plane):
    def __init__(self,head1,tail1,head2,tail2):
        l=[]
        self.__matrix=[]
        for i in range(8):
            l.append(0)
        matrix=[]
        for i in range(8):
            matrix.append(l[:])
        self.__matrix.append(matrix[:])
        Plane.__init__(self,head1,tail1)
        corner=Plane.getCorner(self)
        if corner[0]==-1 or corner[1]==-1:
            print("Plane 1 does not fit in the battlefield!")
            raise ValueError
        else:
            line=corner[0]
            column=corner[1]
            ll=Plane.getLines(self)
            lc=Plane.getColumns(self)
            for i in range(line,line+ll):
                for j in range(column,column+lc):
                    a=Plane.get(self,i-line,j-column)
                    if matrix[i][j]==0 and a!=0:
                        matrix[i][j]=a
                    elif matrix[i][j]!=0 and a!=0:
                        print("Planes are overlapping!")
                        raise ValueError
        Plane.__init__(self,head2,tail2)
        corner = Plane.getCorner(self)
        if corner[0] == -1 or corner[1] == -1:
            print("Plane 2 does not fit in the battlefield!")
            raise ValueError
        else:
            line = corner[0]
            column = corner[1]
            ll = Plane.getLines(self)
            lc = Plane.getColumns(self)
            mx=Plane.getAll(self)
            for i in range(line, line+ll):
                for j in range(column, column+lc):
                    a=mx[i-line][j-column]
                    if matrix[i][j] == 0 and a != 0:
                        matrix[i][j] = a
                    elif matrix[i][j] != 0 and a != 0:
                        print("Planes are overlapping!")
                        raise ValueError
        self.__matrix=matrix

    def get(self,i,j):
        return self.__matrix[i][j]
    def __str__(self):
        s1 = ''
        for i in range(8):
            for j in range(8):
                s1 = s1 + str(self.__matrix[i][j]) + ' '
            s1 = s1 + '\n'
        return s1
    def set(self,i,j,el):
        self.__matrix[i][j]=el


class RandomPlanesMatrix(Plane):
    def __init__(self):
        self.__count=0
        aux=[]
        matrix=[]
        self.__blind=[[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],
                      [0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0]]
        repeat=True
        while repeat==True:
            repeat=False
            if self.__count>30:
                self.__count=0
                raise ValueError
            l = []
            matrix=[]
            self.__matrix = []
            for i in range(8):
                l.append(0)
            for i in range(8):
                matrix.append(l[:])
            self.__matrix.append(matrix[:])
            hi=random.randint(0,7)
            hj=random.randint(0,7)
            head=[]
            head.append(hi)
            head.append(hj)
            z=random.randint(1,4)
            t1=None
            t2=None
            if z == 1:
                t1 = head[0] + 3
                t2 = head[1]
            elif z == 2:
                t1 = head[0] - 3
                t2 = head[1]
            elif z == 3:
                t1 = head[0]
                t2 = head[1] + 3
            elif z == 4:
                t1 = head[0]
                t2 = head[1] - 3
            tail=[]
            tail.append(t1)
            tail.append(t2)
            Plane.__init__(self, head, tail)
            corner = Plane.getCorner(self)
            if corner[0] == -1 or corner[1] == -1:
                repeat = True
                self.__count+=1
            else:
                line = corner[0]
                column = corner[1]
                ll = Plane.getLines(self)
                lc = Plane.getColumns(self)
                for i in range(line, ll+line):
                    for j in range(column, lc+column):
                        a = Plane.get(self, i-line, j-column)
                        if matrix[i][j] == 0 and a != 0:
                            matrix[i][j] = a
                        elif matrix[i][j] != 0 and a != 0:
                            repeat = True
                            self.__count+=1
            aux = matrix[:]
        repeat = True
        while repeat == True:
            repeat = False
            if self.__count>30:
                raise ValueError
            matrix=aux[:]
            hi = random.randint(0, 7)
            hj = random.randint(0, 7)
            head = []
            head.append(hi)
            head.append(hj)
            z = random.randint(1, 4)
            t1 = None
            t2 = None
            if z == 1:
                t1 = head[0] + 3
                t2 = head[1]
            elif z == 2:
                t1 = head[0] - 3
                t2 = head[1]
            elif z == 3:
                t1 = head[0]
                t2 = head[1] + 3
            elif z == 4:
                t1 = head[0]
                t2 = head[1] - 3
            tail = []
            tail.append(t1)
            tail.append(t2)
            Plane.__init__(self, head, tail)
            corner = Plane.getCorner(self)
            if corner[0] == -1 or corner[1] == -1:
                self.__count+=1
                repeat = True
            else:
                line = corner[0]
                column = corner[1]
                ll = Plane.getLines(self)
                lc = Plane.getColumns(self)
                mx = Plane.getAll(self)
                for i in range(line, ll+line):
                    for j in range(column, lc+column):
                        a = mx[i-line][j-column]
                        if matrix[i][j] != 0 and a != 0:
                            repeat = True
                            self.__count+=1
                        elif matrix[i][j] == 0 and a != 0:
                            matrix[i][j] = a
        c1=2
        c2=6
        c3=4
        c4=8
        for i in range(8):
            for j in range(8):
                if matrix[i][j]==1:
                    c1-=1
                elif matrix[i][j]==2:
                    c2-=1
                elif matrix[i][j]==3:
                    c3-=1
                elif matrix[i][j]==4:
                    c4-=1
        if c1!=0 or c2!=0 or c3!=0 or c4!=0:
            raise ValueError
        self.__matrix=matrix[:]

    def setBlind(self,i,j,el):
         self.__blind[i][j]=el
    def get(self,i,j):
        return self.__matrix[i][j]
    def getBlind(self):
        return self.__blind
    def getMatrix(self):
        return self.__matrix
    def __str__(self):
        s1=''
        for i in range(8):
            for j in range(8):
                s1=s1+str(self.__matrix[i][j])+' '
            s1=s1+'   '
            for j in range(8):
                s1 = s1 + str(self.__blind[i][j]) + ' '
            s1=s1+'\n'
        return s1