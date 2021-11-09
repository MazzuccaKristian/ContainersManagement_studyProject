#include "Ship.h"

Ship::Ship(int id, int maxContainers, bool explosive, bool refrigerator){
    SetShip(id, maxContainers, explosive, refrigerator);
}

void Ship::SetShip(int id, int maxContainers, bool explosive, bool refrigerator){
    Id = id;
    MaxContainers = maxContainers;
    Explosive = explosive;
    Refrigerator = refrigerator;
}

int Ship::GetId(){
    return Id;
}

int Ship::GetMaxContainers(){
    return MaxContainers;
}

bool Ship::GetExplosive(){
    return Explosive;
}

bool Ship::GetRefrigerator(){
    return Refrigerator;
}