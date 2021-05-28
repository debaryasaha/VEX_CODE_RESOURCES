#include "vex.h"

using namespace vex;

// myThreadCallback is a callback function that can be registered to a thread. In
// this program, it is registered to 'myThread'.
int myThreadCallback() {
  int count = 0;
  while (true) {
    Brain.Screen.setCursor(1, 1);
    Brain.Screen.print("myThreadCallback has iterated %d times", count);
    count++;

    // You must sleep threads by using the 'this_thread::sleep_for(unit in
    // msec)' command to prevent this thread from using all of the CPU's
    // resources.
    this_thread::sleep_for(25);
  }
  // A threads's callback must return an int, even though the code will never
  // get here. You must return an int here. Threads can exit, but this one does not.
  return 0;
}

int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Declare and assign myThread's callback to 'myThreadCallback'.
  // The thread will start as soon as this command is called.
  thread myThread = thread(myThreadCallback);

  // Print from the main thread to show that it is running at the same time as
  // 'myThreadCallback'.
  int count = 0;
  while (true) {
    Brain.Screen.setCursor(2, 1);
    Brain.Screen.print("main has iterated %d times", count);
    count++;
    wait(25, msec);
  }
}
