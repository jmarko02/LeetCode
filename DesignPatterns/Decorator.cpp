/*
Dynamically adds responsibilities to an object.
A flexible alternative to inheritance for extending functionality.
Represents a component that wraps a base component and inherits the interface of the component it wraps.
The decorator forwards client requests to the wrapped component and can perform additional actions.
*/
#include<string>
#include<iostream>
class ICoffee {
public:
    virtual int price() const = 0;
    virtual std::string description() const = 0;

    virtual ~ICoffee() = default;
protected:
    ICoffee() = default;
};

class BlendCoffee : public ICoffee{
public:
    int price() const override {
        return blend_price;
    }
    std::string description() const override {
        return "Blend Coffee ";
    }
private:
    static const int blend_price = 80;
};

class SingleOriginCoffee : public ICoffee {
public:
    int price() const override {
        return single_origin_price;
    }
    std::string description() const override {
        return "Single Origin Coffee ";
    }
private:
    static const int single_origin_price = 100;
};

class CoffeeAdition : public ICoffee {
    
    ICoffee* coffee;

public:
    
    CoffeeAdition(ICoffee* coffee) : coffee(coffee) {}

    int price() const override {
        return coffee->price();
    }
    std::string description() const override {
        return coffee->description();
    }
};

class SugarCoffee : public CoffeeAdition {
    static const int sugar_price = 0;
public:
    SugarCoffee(ICoffee* coffee) : CoffeeAdition(coffee) {}

    int price() const override {
        return CoffeeAdition::price() + sugar_price;    
    }
    
    std::string description() const override {
        return CoffeeAdition::description() + "with Sugar";
    }
};

class MilkCoffee : public CoffeeAdition{
    static const int milk_price = 50;
public:

    MilkCoffee(ICoffee* coffee):CoffeeAdition(coffee){}
    
    int price() const override {
        return CoffeeAdition::price() + milk_price;
    }

    std::string description() const override {
        return CoffeeAdition::description() + "with Milk ";
    }
};

class ChocolateCoffee: public CoffeeAdition{
private:
    static const int chocolate_price = 100;
public:
    ChocolateCoffee(ICoffee* coffee) : CoffeeAdition(coffee){}

    int price() const override {
        return CoffeeAdition::price() + chocolate_price;
    }

    std::string description() const override {
        return CoffeeAdition::description() + "with chocolate";
    }
};

int main(){
    ICoffee* coffee = new ChocolateCoffee(new MilkCoffee(new SingleOriginCoffee()));
    std::cout << "Coffee price is: " << coffee->price() << std::endl;
    std::cout << "Coffee description is "<< coffee->description() << std::endl;
}