class Bird:
    def __init__(self, name, age):
        self.__name = name # Encapsulation (private property)
        self._age = age; # Encapsulation (protected property)
        print(self.__name, "is born")
    
    def get_name(self):
        print(self.__name, "is a 'Bird'.")
    
    def fly(self):
        print(self.__name, "can fly.")

class Penguin(Bird): # Inheritance
    def __init__(self, name, age):
        super().__init__(name, age)
        print("New penguin is born.")
    
    def fly(self):
        print(self.__name, "cannot fly")
    
    def your_age(self):
        print(self._age, ", this is my age")
    
    def swim(self):
        print(self.__name, "can swim.")

jacky = Penguin("Jacky", 10)
jacky.get_name()
jacky.your_age()
jacky.swim()
jacky.fly()

# Abstraction
from abc import ABC, abstractmethod
class AbstractUser(ABC):
    def __init__(self):
        return
    
    @abstractmethod
    def get_full_name(self):
        pass
    
    @abstractmethod
    def introduce(self):
        pass