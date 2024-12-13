
#include <vector>
#include <string>
#include <array>

class Character;

class Stats{
private:
    std::array<float,5> stats;
public:
    std::array<float,5> getStats() const { return stats;}
    Stats& operator+=(const Stats& other)
    {
        for(int i = 0; i < stats.size(); i++){
            stats[i] += other.stats[i];
        }
        return *this;
    }
    Stats& operator*=(const Stats& other)
    {
        for(int i = 0; i < stats.size(); i++){
            stats[i] *= other.stats[i];
        }
        return *this;
    }
    bool operator<(const Stats& other) const
    {
        for(int i = 0; i < stats.size(); i++){
            if(stats[i] < other.stats[i]) return true;
        }
        return false;
    }
};

class Check
{
    public:
    virtual bool operator()(const Character* c) const { return true;}
};

class ClassCheck: public Check
{
    CharacterClass classes;
    public:
    ClassCheck(CharacterClass classes): classes(classes) {}

    bool operator()(const Character* c) const override {return classes & c->getClass();}
};


class StatsCheck: public Check
{
    Stats stats;
    public:
    StatsCheck(Stats stats): stats(stats) {}

    bool operator()(const Character* c) const override {return !(stats < c->getStats());}
};

class Item {
private:
    ItemType type;
    Stats flatBoosts;
    Stats multiplicativeBoosts;
protected:
    std::vector<Check> requirements;

    template <int classes> bool classRequirement(const Character* c, const Item*)
    {
        return classes & c->getClass();
    }

public:
    Item(ItemType type): type(type){}
    ItemType getType() const {return type;}
    const Stats& getFlatBoosts() const { return flatBoosts;}
    const Stats& getMultiplicativeBoosts() const { return multiplicativeBoosts;}
    bool checkRequirements(const Character*) const;
};

bool Item::checkRequirements(const Character* c) const
{
    for (auto& req : requirements)
    {
        if (!req(c)) return false;
    }
    return true;
}

class Staff: public Item {
    Staff(): Item(ItemType::RIGHTHAND) {
        requirements.push_back(ClassCheck((CharacterClass)(WIZARD | DRUID)));
    }
};

class NameCheck: public Check
{
    std::string name;
    public:
    NameCheck(std::string name): name(name) {}

    bool operator()(const Character* c) const override { return name == c->getName(); }
};


extern bool isFriday();

class FridayCheck: public Check
{
    public:
    bool operator()(const Character* c) const override {return isFriday();}
};

class LudaKesa: public Item {
    LudaKesa(): Item(ItemType::LEFTHAND) {
        requirements.push_back(NameCheck("Pera"));
    }
};

class Character{
private:
    std::string name;
    std::array<Item* , 30> inventory; 
    std::array<Item*, 5> equipped;
    CharacterClass char_class;
    Stats stats;
    Stats baseStats;
    int level;

public:
    void equip(int from, int to);
    CharacterClass getClass() const {return char_class; }
    const std::string& getName() const { return name; }
    const Stats& getStats() const { return stats;}
};

void Character::equip(int from, int to){

    Item* toEquip = inventory[from];
    if (!toEquip->checkRequirements(this)) return;
    if(to != (int)inventory[from]->getType()) return;
    Item* tmp = equipped[to];
    equipped[to] = inventory[from];
    inventory[from] = tmp;
    
    stats = baseStats;
    for(const auto e : equipped){
        if (!e) continue;
        stats += e->getFlatBoosts();
    }
    
    for(const auto e : equipped){
        if (!e) continue;
        stats *= e->getMultiplicativeBoosts();
    }
}

enum class ItemType{
    HEAD, CHEST, RIGHTHAND, LEFTHAND, FOOT
};
enum CharacterClass{
    WIZARD = 1, BARBARIAN = 2, DRUID = 4, PALADIN = 8, NECROMANCER = 16
};
