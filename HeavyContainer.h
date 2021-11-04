#include <string>

#include "Container.h"

using std::string;

class HeavyContainer : private Container {
    private:
        float ExplosiveCapacity;

    public:
        HeavyContainer(int IdCode, float Capacity, float ExplosiveCapacity);
        void SetHeavyContainer(float explosiveCapacity);
        float GetExplosiveCapacity();
        string ToString();
};