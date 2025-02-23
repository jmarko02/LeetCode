
#include <memory>
#include <string>

using namespace std;

class ICoffee 
{
    public:
     ICoffee(string _) {}
};

class SingleOriginCoffee: public ICoffee {
    public:
    SingleOriginCoffee(string _): ICoffee(_) {}
};


// Traditional way with raw pointers
void someFunction() {
    ICoffee* coffee = new SingleOriginCoffee("Ethiopia");
    // ... do something ...
    delete coffee;  // Must remember to delete!
    
    // Problems that can happen:
    // 1. Forget to delete (memory leak)
    // 2. Exception occurs before delete (memory leak)
    // 3. Delete twice (crash)
    // 4. Use after delete (undefined behavior)
}

void someFunction() {
    std::unique_ptr<ICoffee> coffee = 
        std::make_unique<SingleOriginCoffee>("Ethiopia");
    // No need to delete! It's automatic when coffee goes out of scope
}

// unique_ptr ensures ONLY ONE owner of the pointer
void example() {
    // Create a unique_ptr
    std::unique_ptr<ICoffee> coffee1 = 
        std::make_unique<SingleOriginCoffee>("Ethiopia");
    
    // Cannot copy a unique_ptr (this won't compile):
    // std::unique_ptr<ICoffee> coffee2 = coffee1;  // ERROR!
    
    // Can only move ownership:
    std::unique_ptr<ICoffee> coffee2 = std::move(coffee1);
    // Now coffee1 is null, coffee2 owns the object
}

// Creating:
auto coffee = std::make_unique<SingleOriginCoffee>("Ethiopia");

// Passing to function:
void processCoffe(std::unique_ptr<ICoffee> coffee) {
    // Function takes ownership
}

void doProcess() {
    processCoffe(std::move(coffee));  // Must move, can't copy
}
// As class member:
class CoffeeShop {
private:
    std::unique_ptr<ICoffee> todaysSpecial;
public:
    CoffeeShop(std::unique_ptr<ICoffee> special) 
        : todaysSpecial(std::move(special)) {}
};

void benefits() {
    // 1. Automatic cleanup
    {
        auto coffee = std::make_unique<SingleOriginCoffee>("Ethiopia");
    } // coffee is automatically deleted here

    // 2. Exception safety
    // void riskyFunction() {
    //     auto coffee = std::make_unique<SingleOriginCoffee>("Ethiopia");
    //     throw std::runtime_error("Something went wrong!");
    //     // coffee still gets deleted!
    // }

    // 3. Clear ownership semantics
    auto coffee1 = std::make_unique<SingleOriginCoffee>("Ethiopia");
    // auto coffee2 = coffee1;  // Won't compile - can't have two owners
    auto coffee2 = std::move(coffee1);  // Ownership transferred
}

// shared_ptr - multiple owners allowed
std::shared_ptr<ICoffee> coffee1 = 
    std::make_shared<SingleOriginCoffee>("Ethiopia");
std::shared_ptr<ICoffee> coffee2 = coffee1;  // Both own it

// weak_ptr - doesn't own, just observes shared_ptr
std::weak_ptr<ICoffee> weakCoffee = coffee1;