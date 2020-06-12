//
//  main.cpp
//  IteratingOverVectors
//
//  Created by Harry O'Brien on 24/04/2019.
//  Copyright © 2019 SociaDevLtd. All rights reserved.
//

#include <iostream>
#include <vector>

struct FuncCallbacks {
  FuncCallbacks(void (*_setupFunc)(void), void (*_loopFunc)(void)) :
  setupFunc(_setupFunc),
  loopFunc(_loopFunc)
  {}
  
  void setup(void) { (*setupFunc)(); }
  void loop(void) { (*loopFunc)(); }
  
private:
  void (*setupFunc)(void);
  void (*loopFunc)(void);
};

//Task, containing repetition rate
struct Task {
  Task() {}
  
  Task(FuncCallbacks* _cbk, std::string _name, uint16_t _maxTimeMicros, float _rateHz) :
  cbk(_cbk),
  name(_name),
  maxTimeMicros(_maxTimeMicros),
  rateHz(_rateHz)
  {}
  
  FuncCallbacks* cbk;
  std::string name;
  uint16_t maxTimeMicros;
  float rateHz;
};

std::vector<std::vector<Task*>> scheduledTasks;

void doofer(Task* t) {
  for(auto iter = scheduledTasks.begin(); iter != scheduledTasks.end(); iter++){
    if (t->rateHz == (*iter->begin())->rateHz){
      iter->push_back(t);
      return;
    }
  }
  
  std::vector<Task*> taskList;
  taskList.push_back(t);
  scheduledTasks.push_back(taskList);
}

void printTings() {
  for(auto iter = scheduledTasks.begin(); iter != scheduledTasks.end(); iter++){
    for(auto insideIter = iter->begin(); insideIter != iter->end(); insideIter++) {
      std::cout << (*insideIter)->rateHz << std::endl;
    }
  }
}

int main(int argc, const char * argv[]) {
  
  
  /** setup and that lot **/
  Task* t = new Task;
  t->rateHz = 10;
  
  Task *newTask1, *newTask2;
  
  newTask1 = new Task;
  newTask1->rateHz = 16;
  
  newTask2 = new Task;
  newTask2->rateHz = 10;
  
  std::vector<Task*> taskList;
  taskList.push_back(t);
  scheduledTasks.push_back(taskList);
  /***/
  
  doofer(newTask1);
  doofer(newTask2);
  doofer(newTask2);
  
  printTings();
  
  return 0;
}
