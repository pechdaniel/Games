from controller import *
class UI:
    def __init__(self,controller=Controller()):
        self.__c=controller
        self.__start=False
    def menu(self):
        pass
    def readSentence(self):
        repeat=True
        x=None
        while repeat==True:
            repeat=False
            x=input("Enter the sentence:")
            y=x
            y=y.split()
            for i in range(len(y)):
                if len(y[i])<3:
                    print("The sentence contains at least one word with less than 3 letters! Try again!")
                    repeat=True
            if len(y)<1:
                print('The sentence does not contain any words!')
                repeat=True
        return x
    def start(self):
        print("The game doesn't start until you type 'start'.")
        while self.__start==False:
            print('Enter the sentence to or start the game (start)')
            x=self.readSentence()
            if x=='start':
                self.__start=True
            else:
                self.__c.add(x)
        sharp=self.__c.pickRandomSentence()
        while self.__start==True:
            print(self.__c)
            again=True
            y=''
            while again==True:
                again=False
                y=input('Enter the letter:')
                if len(y)!=1:
                    print("Invalid input!")
                    again=True
            self.__c.Verify(y)
            a=self.__c.GameOver()
            if a==0:
                print("TRY AGAIN!")
                break
            b=self.__c.UndCount()
            if b==0:
                print("YOU WON!")
                break

