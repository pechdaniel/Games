from repository import *
import random
class Controller:
    def __init__(self,data=Repository()):
        self.__repo=data
        self.__void=None
        self.__all=None
        self.__hang='hangman'
        self.__count=1
    def add(self,stri):
        for i in range(len(self.__repo.getAll())):
            if self.__repo.get(i)==stri:
                return
        self.__repo.add(stri)
    def get(self,i):
        return self.__repo.get(i)
    def getAll(self):
        return self.__repo
    def pickRandomSentence(self):
        n=len(self.__repo.getAll())-1
        x=random.randint(0,n)
        lst=self.__repo.get(x)
        y=''
        y+=str(lst[0])
        letter=[]
        letter.append(lst[0])
        for i in range(1,len(lst)-1):
            if lst[i]==' ':
                a=lst[i-1]
                b=lst[i+1]
                letter.append(a)
                letter.append(b)
                y+=str(lst[i-1])+' '+str(lst[i+1])
                i+=1
            else:
                y+='_'
        y+=str(lst[len(lst)-1])
        letter.append(str(lst[len(lst)-1]))
        k=''
        for i in range(len(self.__repo.get(x))):
            w=-1
            for j in range(len(letter)):
                if self.__repo.get(x)[i]==letter[j]:
                    w=str(letter[j])
            if w!=-1:
                k+=w
            elif self.__repo.get(x)[i]==' ':
                k+=' '
            else:
                k+='_'
        self.__void=k
        self.__all=self.__repo.get(x)
        return self.__repo.get(x)
    def __str__(self):
        s='"'
        lst='"'
        for i in range(self.__count):
            lst+=str(self.__hang[i])
        lst+='"'
        for i in range(len(self.__void)):
            s+=str(self.__void[i])+' '
        s+='" - '
        s+=lst
        return s
    def GameOver(self):
        if self.__count==7:
            return 0
        return 1
    def UndCount(self):
        c=0
        for i in range(len(self.__void)):
            if self.__void[i]=='_':
                c+=1
        if c==0:
            return 0
        return 1
    def Verify(self,l):
        c=0
        make=''
        for i in range(len(self.__void)):
            if self.__all[i]==l:
                make+=str(l)
                c+=1
            else:
                make+=str(self.__void[i])
        if c==0:
            self.__count+=1
        self.__void=make