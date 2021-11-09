class Ship {
    private:
        int Id, MaxContainers;
        bool Explosive, Refrigerator;

    public:
        Ship(int id, int maxContainers, bool explosive, bool refrigerator);
        void SetShip(int id, int maxContainers, bool explosives, bool refrigerator);
        int GetId();
        int GetMaxContainers();
        bool GetExplosive();
        bool GetRefrigerator();
};