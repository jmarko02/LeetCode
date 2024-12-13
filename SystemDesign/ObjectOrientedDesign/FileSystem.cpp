#include<vector>
#include<string>
#include <chrono>
class Entry {
protected:
    Directory* parent;
    std::string name;
    std::chrono::steady_clock::time_point createdAt;
    std::chrono::steady_clock::time_point updatedAt;
    uint64_t lastAccess;
    Entry(std::string name, Directory* parent): name(name), parent(parent) {
        createdAt = std::chrono::steady_clock::now();
        //...
    }
    //getters and setters
    void changeName(std::string newName) {}

    bool del() {
        if(parent == nullptr){
            return false;
        }
        return parent->deleteEntry(this);
    }
    std::string getFullPath(){
        if(parent == nullptr) return name;
        else return parent->getFullPath() + "/" + name;
    }
    public:
    virtual int size() const = 0;

};
class Directory : public Entry {
    std::vector<Entry*> content;
    public:
    Directory(std::string name, Directory* parent) : Entry(name, parent) {
        content = std::vector<Entry*>();
    }
    std::vector<Entry*> getContents() const {return content;}
    bool deleteEntry(Entry* entry){
        auto it = std::find(content.begin(), content.end(), entry);
        if(it != content.end()) {
            content.erase(it);
            return true;
        }
        else return false;

    }
    void addEntry(Entry* entry){
        content.push_back(entry);
    }
    int size() const override {
        int size = 0;
        for(auto& c : content){
            size += c->size();
        }
        return size;
    }
    
};

class File : public Entry {
    std::string content;
    int size;
    File(std::string name, Directory* parent, int sz): Entry(name, parent) , size(sz) {}
    int size() const override { return size;}
    std::string getContent() const { return content;}
    void setContent(std::string ctn) { content = ctn;}

};