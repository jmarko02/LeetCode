#include<string>
#include<vector>
enum class VehicleSize{Motor, Compact, Large};

class ParkingSpot;
class Vehicle{
protected:
    VehicleSize vehicle_size;
    std::vector<ParkingSpot*> parking_spots;
    std::string licensePlate;        
public:
    Vehicle(VehicleSize vehicle_size, const std::string& licensePlate):vehicle_size(vehicle_size), licensePlate(licensePlate){}
    virtual ~Vehicle() = default;

    VehicleSize getVehicleSize() const {return vehicle_size;}
    virtual bool canFitInSpot(const ParkingSpot& spot ) const = 0;
    virtual int spotsNeeded() const = 0;
    void clearSpots();
    void parkInSpot(ParkingSpot* spot) {parking_spots.push_back(spot);}

};
void Vehicle::clearSpots(){
    
    for(ParkingSpot* spot : parking_spots){
        //spot->removeVehicle();
    }
    parking_spots.clear();
}

class Motorcycle : public Vehicle {
    Motorcycle(const std::string& licensePlate) : Vehicle(VehicleSize::Motor, licensePlate){}
    bool canFitInSpot(const ParkingSpot& spot) const override;
    int spotsNeeded() const override {return 1;}
};
bool Motorcycle::canFitInSpot(const ParkingSpot& spot) const { return true; }

class Car: public Vehicle{
public:
    Car(const std::string licensePlate): Vehicle(VehicleSize::Compact, licensePlate){}
    int spotsNeeded() const override { return 1;}
    bool canFitInSpot(const ParkingSpot& spot) const override;

};
bool Car::canFitInSpot(const ParkingSpot& spot) const {
    return spot.getSize() >= getVehicleSize();
}

class Bus:public Vehicle{
    Bus(const std::string licensePlate): Vehicle(VehicleSize::Large, licensePlate){}
    int spotsNeeded() const override { return 5;}
    bool canFitInSpot(const ParkingSpot& spot) const override;
};
bool Bus::canFitInSpot(const ParkingSpot& spot) const {
    return spot.getSize() == VehicleSize::Large;
}

class ParkingSlot {
private:
    VehicleSize size;
    int row;
    int level;
    int positionInRow;
    Vehicle* vehicle;
public:
    ParkingSlot(int row, int level, int positionInRow):row(row), level(level), positionInRow(positionInRow), available(true), vehicle(nullptr){}
    bool isAvailable() const { return vehicle == nullptr;}
    void parkVehicle(Vehicle* vehicle);
    void removeVehicle(Vehicle* vehicle);
    bool canFitVehicle(Vehicle* vehicle);

    int getRow() const { return row;}
    int getLevel() const { return level;}
    int positionInRow() const {return positionInRow;}
    VehicleSize getSize() const {return size;}
};

class Level{
private:
    std::vector<ParkingSlot*> parkingSlots;
    int rows;
    int slotsPerRow;
    int floor;
public:
    Level(int floor,int rows, int slotsPerRow);
    ~Level(){
        for(ParkingSpot* spot: parkingSlots) delete spot;
    }
    std::vector<ParkingSlot*> findAvailableSpots(const Vehicle& vehicle);
    void parkStartingAtSpot(int spot, Vehicle* vehicle);
    void parkVehicle(Vehicle* vehicle);

    //getters
};
class ParkingLot{
private:
    std::vector<Level*> levels;
    
public:
    ParkingLot(int numLevels, int rows, int spotsPerRow){
        for(int i = 0; i < numLevels; i++){
            levels.push_back(new Level(i, rows, spotsPerRow));
        }
    }
    bool parkVehicle(Vehicle* vehicle);
    ~ParkingLot(){
        for(Level* l : levels) delete l;
    }

}

