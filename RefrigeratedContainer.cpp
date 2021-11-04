#include "RefrigeratedContainer.h"

RefrigeratedContainer::RefrigeratedContainer(int IdCode, float Capacity, float ExplosiveCapacity, float RefrigeratorCapacity)
    : HeavyContainer::HeavyContainer(IdCode, Capacity, ExplosiveCapacity){
        SetRefrigeratedContainer(RefrigeratorCapacity);
}

void RefrigeratedContainer::SetRefrigeratedContainer(float refrigeratorCapacity){
    RefrigeratorCapacity = refrigeratorCapacity;
}

float RefrigeratedContainer::GetRefrigeratorCapacity(){
    return RefrigeratorCapacity;
}

string RefrigeratedContainer::ToString(){
    string line = HeavyContainer::ToString() + " RefrigeratorCapacity: " + std::to_string(this -> GetRefrigeratorCapacity());
    return line;
}