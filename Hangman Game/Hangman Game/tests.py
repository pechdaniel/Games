import unittest
from controller import *
class TestRepo(unittest.TestCase):
    def testAdd(self):
        a=Repository()
        a.add('was ist das caine gras')
        self.assertEqual(a.get(0),'was ist das caine gras')
    def testGet(self):
        a=Repository()
        a.add('lol')
        b=a.get(0)
        self.assertEqual(b,'lol')
    def testGetAll(self):
        a=Repository()
        a.add('making it')
        b=a.getAll()
        self.assertEqual(b,['making it'])
class TestController(unittest.TestCase):
    def testAdd(self):
        a=Controller()
        a.add('lol')
        self.assertEqual(a.get(0),'lol')
    def testPickRandomSentence(self):
        a=Controller()
        a.add('lol')
        b=a.pickRandomSentence()
        self.assertEqual(b,'lol')
    def testGameOver(self):
        a=Controller()
        a.add('lol')
        b=a.GameOver()
        self.assertEqual(b,1)
    def testUndCount(self):
        a=Controller()
        a.add('lol')
        b=a.pickRandomSentence()
        c=a.UndCount()
        self.assertEqual(c,1)
a=TestRepo()
a.testAdd()
a.testGet()
a.testGetAll()
b=TestController()
b.testGameOver()
b.testAdd()
b.testPickRandomSentence()
b.testUndCount()