#include <iostream>
#include <thread>

/*
Multiprocessing:
Each process has only 1 thread running in multiprocessing model 
All process communicate with each other through the regular interprocess 
communication channel eg files, pipes, message, queues etc
*/

/*
Multithreading:
One process contains 2 or more threads All threads communicate with each other 
through shared memory 

ADV: A thread is usually faster to start than a process, while process needs OS 
to dedicate internal resources to manage process, so slow and complicated. 
Thread is lightweight. 
A thread has low overhead- OS needs to provide protection so one process won't 
step on another eg Shared memory a lot faster than ICC -> better performance. 
DIS: Difficult to implement, fiddly 
Cannot run on distributed systems - shared memory - can be converted to run 
on distributed system if no shared memory used
*/

void myFunc()
{
    std::cout << "Hello, World!" << std::endl;
}

int main()
{
    // myFunc();
    std::thread t1(myFunc); // t1 starts running

    // t1.join(); // main thread waits for t1 to finish
    t1.detach(); // cut connection between main thread and t1
    // t1 will run freely (daemon thread)
    // main thread will almost always finish before t1 so nothing will be printed
    // probabilistic, not deterministic, only prints very rarely in this case
    // setting up thread very quick, but not negligible comapred to main = return 0
    // std::cout resource if shared main should keep alive
    // join or detach can only happen once - join after detach = crash
    if(t1.joinable()) // to avoid crash, still won't join
    {
        t1.join();
    }

    try {
        t1.join();
    } catch(std::system_error e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}