import multiprocessing
import time
import sys

def daemon():
  p = multiprocessing.current_process()
  print('Starting:', p.name, p.pid)
  sys.stdout.flush()
  time.sleep(2)
  print('Exiting :', p.name, p.pid)
  sys.stdout.flush()

def non_daemon():
  p = multiprocessing.current_process()
  print('Starting:', p.name, p.pid)
  sys.stdout.flush()
  print('Exiting :', p.name, p.pid)
  sys.stdout.flush()

if __name__ == '__main__':
  d = multiprocessing.Process(
    name='daemon',
    target=daemon,
  )
  d.daemon = True
    
  nd = multiprocessing.Process(
    name='non-daemon',
    target=non_daemon,
  )
  nd.daemon = False
        
  d.start()
  time.sleep(1)
  nd.start()

  #To wait for a process to finish, we use join
#  d.join()
#  nd.join()

  #We can also provide a timeout
#  d.join(1)
#  print('d.is_alive()', d.is_alive())
#  nd.join()
