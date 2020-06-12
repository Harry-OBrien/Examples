class Person:

  name = ""
  age = 0
  height = 0
  weight = 0

  def __init__(self, name, age, height, weight):
    self.name = name
    self.age = age
    self.height = height
    self.weight = weight

  def speak(self, speech):
    print(self.name + " says: \"" + speech + "\"")
