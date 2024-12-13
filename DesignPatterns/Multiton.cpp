/*
Implement the Multiton design pattern to allow access to an arbitrary number of instances, where access is done via the instance's name.
*/

#include<string>
#include<unordered_map>
class Multiton{
public:

    static Multiton& getInstance(std::string& name){
        if(instances.find(name) == instances.end()){
            instances.emplace(name,Multiton(name));
        } 
        return instances[name];
    }
    Multiton(const Multiton& ) = delete;
    Multiton& operator=(const Multiton&)=delete;

protected:

    explicit Multiton(const std::string name) : name(name){}

private:

    std::string name;
    static std::unordered_map<std::string,Multiton> instances;
};