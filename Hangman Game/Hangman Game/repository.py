import pickle
class Repository:
    def __init__(self):
        self._data=[]
    def add(self,stri):
        self._data.append(stri)
    def get(self,i):
        if i >=0 and i<len(self._data):
            return self._data[i]
        return -1
    def getAll(self):
        return self._data

class PickleRepository(Repository):
    def __init__(self,fileName):
        Repository.__init__(self)
        self.__fileName=fileName
        self.__load()
    def add(self,el):
        Repository.add(self,el)
        self.__store()
    def __load(self):
        file=open(self.__fileName,"rb")
        try:
            self._data=pickle.load(file)
        except EOFError:
            self._data=[]
        except Exception as exc:
            raise exc
        finally:
            file.close()
    def __store(self):
        file=open(self.__fileName,"wb")
        pickle.dump(self._data, file)
        file.close()