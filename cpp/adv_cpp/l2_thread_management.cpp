#include <iostream>
#include <thread>
#include <string> 

void myFunc()
{
    std::cout << "Hello, World!" << std::endl;
}

class F {
    public:
        void operator()(std::string message)
        {
            for (int i = 0; i > -10; i--) {
                std::cout << "starting at t1 " << i << std::endl;
            }
            std::cout << "thread t1 says: " << message << std::endl;
        }
};

int main()
{
    std::string s = "I've got work tomorrow.";    
    // std::thread t1(myFunc);
    // std::thread t1(functor);
    // std::thread t1(F()); // t1 starts running (MOST VEXING SYNTAX)
    std::thread t1((F()), s); // another pair () to explicitely say is functor and pass as param
    // t1 has to be joined or detached before it goes out of scope
  
    // RAII approach
    // use a wrapper class that wraps around thread t1
    // wrapper w(t1)
    // when wrapper goes out of scope, automatically joins thread

    try {
        for (int i = 0; i < 10; i++) {
        std::cout << "message from main: " << i << std::endl;
    }

    } catch (...) { // ... means any type
        t1.join(); // guarantee t1 gets joined in case of exception
        throw; // rethrow exception
    }
    t1.join();

    

    return 0;
}