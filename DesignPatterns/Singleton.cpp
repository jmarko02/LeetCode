class Singleton {
public:
    Singleton& getInstance(){
        static Singleton instance;
        return instance;
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
protected:
    
    Singleton(){}
};

//OR
class SingletonPointer{
public:
    static SingletonPointer* getInstance(){
        if(instance == nullptr){
            instance = new SingletonPointer();
        }
        return instance;
    }
protected:
    SingletonPointer() {}
private:
    static SingletonPointer* instance;
};

SingletonPointer* SingletonPointer::instance = nullptr;