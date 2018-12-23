from UI import *
from controller import *
from repository import *
r=PickleRepository("make1.txt")
c=Controller(r)
ui=UI(c)
ui.start()