#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>

// a) Create a method factorizeNumber which returns a string containing a prime factorization of a number.
std::string factorizeNumber(int n) {
    if (n <= 1) return std::to_string(n) + ": " + std::to_string(n);
    std::string result = std::to_string(n) + ":";
    int temp = n;
    for (int i = 2; i * i <= temp; ++i) {
        while (temp % i == 0) {
            result += " " + std::to_string(i);
            temp /= i;
        }
    }
    if (temp > 1) {
        result += " " + std::to_string(temp);
    }
    return result;
}

// b) std::queue generatedNumbers
std::queue<int> generatedNumbers;
// e) Lock concurrent access with std::mutex and find a way for a thread to detect that it has finished execution.
std::mutex mtxGen;
std::condition_variable cvGen;
bool producerFinished = false; // Used to detect if the producer has finished execution

// c) std::queue printableNumbers
std::queue<std::string> printableNumbers;
// e) Lock concurrent access with std::mutex
std::mutex mtxPrint;
std::condition_variable cvPrint;
bool consumerFinished = false; // Used to detect if the consumer has finished execution

// b) Create a method called producer, which generates random numbers and puts them into a std::queue generatedNumbers.
void producer() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(2, 100000); 

    // e) The producer should find 10.000 random numbers and put them into the generatedNumbers queue.
    for(int i = 0; i < 10000; ++i) {
        int num = distr(gen);
        {
            // e) Lock concurrent access with std::mutex
            std::lock_guard<std::mutex> lock(mtxGen);
            generatedNumbers.push(num);
        }
        cvGen.notify_one();
    }
    
    {
        std::lock_guard<std::mutex> lock(mtxGen);
        // e) find a way for a thread to detect that it has finished execution.
        producerFinished = true;
    }
    cvGen.notify_all();
}

// c) Create a method called consumer, which takes the first element of the random numbers queue, 
// removes it from the queue and performs factorizeNumber on it.
void consumer() {
    while (true) {
        int num = 0;
        {
            std::unique_lock<std::mutex> lock(mtxGen); // e) Lock concurrent access with std::mutex
            cvGen.wait(lock, []{ return !generatedNumbers.empty() || producerFinished; });
            
            // e) Detect that producer has finished execution and queue is empty
            if (generatedNumbers.empty() && producerFinished) {
                break;
            }
            
            num = generatedNumbers.front();
            generatedNumbers.pop();
        }
        
        // c) performs factorizeNumber on it.
        std::string result = factorizeNumber(num);
        
        // c) The generated string with the prime factorization of a number should now be enqueued into a new std::queue printableNumbers.
        {
            std::lock_guard<std::mutex> lock(mtxPrint); // e) Lock concurrent access
            printableNumbers.push(result);
        }
        cvPrint.notify_one();
    }
    
    {
        std::lock_guard<std::mutex> lock(mtxPrint);
        // e) find a way for a thread to detect that it has finished execution.
        consumerFinished = true;
    }
    cvPrint.notify_all();
}

// d) Create a method called printer, which takes the first element of the printable numbers queue, 
// removes it from the queue and prints it via std::cout.
void printer() {
    while (true) {
        std::string result;
        {
            std::unique_lock<std::mutex> lock(mtxPrint); // e) Lock concurrent access
            cvPrint.wait(lock, []{ return !printableNumbers.empty() || consumerFinished; });
            
            // e) Detect that consumer has finished execution and queue is empty
            if (printableNumbers.empty() && consumerFinished) {
                break;
            }
            
            result = printableNumbers.front();
            printableNumbers.pop();
        }
        // d) prints it via std::cout
        std::cout << result << "\n";
    }
}

// e) Execute all three methods in threads.
int main() {
    std::thread t1(producer);
    std::thread t2(consumer);
    std::thread t3(printer);

    // e) Execute all three methods in threads
    t1.join();
    t2.join();
    t3.join();

    return 0;
}
