__author__ = 'zhengwei'
class LRUCache:

    # @param capacity, an integer
    def __init__(self, capacity):
        self.__cacheContainer = {}
        self.__capacity = capacity
        self.__lruList = []
    # @return an integer
    def get(self, key):
        if key in self.__cacheContainer:
            self.updateItem(key)
            return self.__cacheContainer.get(key)
        return -1

    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def set(self, key, value):
        self.updateItem(key)
        self.__cacheContainer[key] = value


    def updateItem(self, updatedKey):
        if updatedKey not in self.__cacheContainer:
            if len(self.__lruList) >= self.__capacity:
                self.__cacheContainer.pop(self.__lruList[0])
                self.__lruList.pop(0)
            self.__lruList.append(updatedKey)
        else:
            for key in self.__lruList:
                if key == updatedKey:
                    self.__lruList.remove(key)
                    self.__lruList.append(key)


cache = LRUCache(10)
print cache.get(10)
cache.set(10, 1000)
print cache.get(1)
