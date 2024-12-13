/*
Define the skeleton of an algorithm, delegating specific steps to subclasses.
Allow subclasses to redefine certain steps of the algorithm without changing its structure.
Implement the invariant parts of the algorithm once, leaving the parts that may vary to the subclasses.
When common behavior among subclasses needs to be localized, this helps avoid code duplication.
*/
#include<iostream>
class BeverageMaker{
public:
    void makeBeverage(){
        heatWater();
        prepare();
        pour();
        addCondiments();
    }  
protected:
    void heatWater(){
        std::cout << "Heating" << std::endl;
    }
    
    void pour() {
        std::cout << "Pouring" << std::endl;
    }

    virtual void addCondiments() = 0;
    virtual void prepare() = 0;

    virtual ~BeverageMaker(){}
};

class CoffeeMaker : public BeverageMaker{
protected:
    void prepare() override {
        std::cout << "Preparing coffee" << std::endl;
    }
    void addCondiments() override {
        std::cout << "Adding to coffee" << std::endl;
    }
};

class TeaMaker : public BeverageMaker{
protected:
    void prepare() override {
        std::cout << "Preparing tea" << std::endl;
    }
    void addCondiments() override {
        std::cout << "Adding to tea" << std::endl;
    }
};

int main (){
    CoffeeMaker coffe;
    TeaMaker tea;

    std::cout << "LETS MAKE COFFEE" << std::endl;
    coffe.makeBeverage();

    std::cout << "LETS MAKE TEA" << std::endl;
    tea.makeBeverage();

    return 0;
}
