from controller import *
from repository import *
from domain import *
class UI:
    def __init__(self):
        self.__matrix=None
    def readPlane(self):
        print("Enter the position of the head:")
        repeat = True
        while repeat == True:
            repeat = False
            i=int(input("Line:"))
            j=input("Column:")
            lst = []
            lst.append(None)
            lst.append(None)
            if j == 'A' or j == 'a':
                lst[1] = 0
            elif j == 'B' or j == 'b':
                lst[1] = 1
            elif j == 'C' or j == 'c':
                lst[1] = 2
            elif j == 'D' or j == 'd':
                lst[1] = 3
            elif j == 'E' or j == 'e':
                lst[1] = 4
            elif j == 'F' or j == 'f':
                lst[1] = 5
            elif j == 'G' or j == 'g':
                lst[1] = 6
            elif j == 'H' or j == 'h':
                lst[1] = 7
            else:
                print("Invalid input!")
                raise ValueError
            lst[0] = i - 1
            if i<1 or i>8:
                print("Invalid input!")
                raise ValueError
            z=input("Write how the plane is oriented (up, down, left, right):")
            if lst[0]<0 or lst[1]>7 or lst[0]>7 or lst[1]>7:
                repeat=True
                print("Invalid input!")
                raise ValueError
        t1=None
        t2=None
        repeat=True
        while repeat==True:
            repeat=False
            if z=='up':
                t1=lst[0]+3
                t2=lst[1]
            elif z=='down':
                t1=lst[0]-3
                t2=lst[1]
            elif z=='left':
                t1=lst[0]
                t2=lst[1]+3
            elif z=='right':
                t1=lst[0]
                t2=lst[1]-3
            else:
                repeat=True
                print("Invalid input!")
                raise ValueError
        lst1=[]
        lst1.append(t1)
        lst1.append(t2)
        plane=[]
        plane.append(lst)
        plane.append(lst1)
        return plane
    def zero(self):
        print('\n')
        print('                     Player vs Computer\n')
        s = '1   '
        print('   ', 'A ', 'B ', 'C ', 'D ', 'E ', 'F ', 'G ', 'H ', '        ', 'A ', 'B ', 'C ', 'D ', 'E ', 'F ', 'G ', 'H\n')
        k = 1
        for i in range(8):
            k = k + 1
            for j in range(8):
                s = s + '_' + '  '
            s = s + '     ' + str(k - 1) + '   '
            for j in range(8):
                s = s + '_' + '  '
            if k <= 8:
                s = s + '\n' + str(k) + '   '
        s=s+'\n'
        return s
    def start(self):
        do=True
        while do==True:
            difficulty=int(input("\nEnter the difficulty that you want to play (1 or 2):"))
            if difficulty ==1 or difficulty ==2:
                do=False
            else:
                print("Invalid difficulty!")
        print("\nLines are 1-8 and columns are A-H")
        print(self.zero())
        rand=[]
        repeat=True
        while repeat==True:
            repeat=False
            try:
                rand=[]
                rand = RandomPlanesMatrix()
            except ValueError:
                repeat=True
        repeat=True
        while repeat==True:
            repeat=False
            try:
                first = self.readPlane()
                second = self.readPlane()
                matrix=Matrix(first[0],first[1],second[0],second[1])
                repo=MatrixRepository(rand,matrix)
                controller=MatrixController(repo)
                self.__matrix=controller

            except ValueError:
                repeat=True
        while True:
            try:
                print(self.__matrix)
                hc1=self.__matrix.playerHeadShot()
                hc2=self.__matrix.blindHeadShot()
                print('Computer score:',hc1,' Player score:',hc2)
                if self.__matrix.GameOver(hc1,hc2)==-1 or self.__matrix.GameOver(hc1,hc2)==1:
                    print("Computer battlefield:\n")
                    print(self.__matrix.printRandom())
                    break
                print("Enter your strike (line, column):")
                line=int(input("Line:"))
                column=input("Column:")
                hit=self.__matrix.isHit(line,column)
                print('\n')
                if difficulty == 1:
                    randHit = self.__matrix.AI1()
                    if randHit == 1:
                        print("Computer head shot!")
                    elif randHit == -1:
                        print("Computer miss!")
                    else:
                        print('Computer hit!')
                elif difficulty == 2:
                    self.__matrix.AIW()
                if hit==1:
                    print("Head shot!")
                elif hit==2:
                    print("Hit!")
                elif hit==-1:
                    print("Miss!")
                else:
                    print('\n')
                    raise ValueError
                #hit1=self.__matrix.AI()
                #if hit1==-1:
                #    print("Computer miss!")
                #elif hit1==1:
                #    print("Computer head shot!")
                #else:
                #    print("Computer hit!")
            except ValueError:
                print("Already shot there!")