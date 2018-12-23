import unittest


class Data:
    def __init__(self, data = []):
        self._data = data
        self._idx = 0

    def __iter__(self):
        return self

    def __next__(self):
        try:
            item = self._data[self._idx]
        except IndexError:
            raise StopIteration()
        self._idx += 1
        return item

    def __setitem__(self, key, value):
        self._data[key] = value

    def __delitem__(self, key):
        del self._data[key]

    def __len__(self):
        return len(self._data)

    def __getitem__(self, idx):
        return self._data[idx]

    def append(self, value):
        self._data.append(value)

def sort(myList, key = lambda x: x, reverse = False ):
    '''
    Gnome sort
    :return:
    '''
    pos = 0
    while pos < len(myList):
        if pos == 0 or key(myList[pos]) >= key(myList[pos - 1]):
            pos = pos + 1
        else:
            myList[pos], myList[pos - 1] = myList[pos - 1], myList[pos]
            pos = pos - 1
    if reverse == True:
        myList = reversed(myList)

    return myList

def filter(myList, condition):
    '''
    myList is an iterable data structure
    condition is a function
    :param myList:
    :param condition:
    :return:
    '''
    result = []
    for i in myList:
        if condition(i):
            result.append(i)
    return result

def test(item):
    if item % 2 == 0:
        return True
    return False

class TestData(unittest.TestCase):
    # def __init__(self):
    #     self.data = Data()
    #     for i in range(100):
    #         self.data.append(i)

    def test1(self):
        data = []

        for i in range(100):
            data.append(i)
        data = Data(data)

        j = 0
        for i in data:
            self.assertEqual(j,i)
            j += 1

    def test2(self):
        list = [2, 1, 4, 3, 16, 6, 100]
        sort(list,lambda x : x)
        for i in range (0,len(list)-1):
            self.assertLessEqual(list[i], list[i+1])

    def test3(self):
        data = Data()

        for i in range(100):
            data.append(i)
        result = filter(data, test)
        for i in result:
            if i % 2 == 1:
                self.assertEqual(True, False)

    def test4(self):
        data = Data([])
        data.append(1)
        self.assertEqual(len(data), 1)
        data[0] = 10
        self.assertEqual(data[0],10)
        del data[0]
        self.assertEqual(len(data),0)

if _name_ == '_main_':
    unittest.main()