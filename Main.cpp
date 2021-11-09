#include "Main.h"

int main(){
    bool isStillWorking = true;
    int userChoice;

    while(isStillWorking){
        ShowMainMenu();
        cin >> userChoice;
        switch(userChoice){
            case 0:
                cout << "Program ended. Please, wait..." << endl;
                isStillWorking = false;
                break;

            case 1:
                ShowContainers();
                break;

            case 2:
                AddNewContainer();
                break;

            case 3:
                AddNewHeavyContainer();
                break;

            case 4:
                AddNewRefrigeratedContainer();
                break;

            case 5:
                AddNewShip();
                break;

            case 6:
                PlanNewDelivery();
                break;

            //TODO: Implements ships. Implements load/unload logic.
        }
    }
    return 0;
}

void ShowMainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "1) Show containers in port;" << endl;
    cout << "2) Add new container;" << endl;
    cout << "3) Add new heavy container;" << endl;
    cout << "4) Add new refrigerated container;" << endl;
    cout << "5) Add new ship;" << endl;
    cout << "6) Plan new delivery;" << endl;
    cout << "0) Exit." << endl;
    cout << "Enter your choice: ";
}

void ShowContainers(){
    ifstream containers (CONTAINERS);
    if(containers.is_open()){
        string line;
        cout << endl;
        while(getline(containers, line)){
            cout << line << endl;
        }
        cout << endl;
    }else{
        perror("Can't open file");
    }
    containers.close();
}

void AddNewContainer(){
    int id;
    float capacity;
    ofstream containers;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max capacity: ";
    cin >> capacity;
    Container newContainer(id, capacity);
    containers.open(CONTAINERS, ofstream::app);
    if(containers.is_open()){
        containers << newContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
    containers.close();
}

void AddNewHeavyContainer(){
    ofstream containers;
    int id;
    float capacity, explCapacity;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max capacity: ";
    cin >> capacity;
    cout << "Enter max capacity (explosives): ";
    cin >> explCapacity;
    HeavyContainer newHeavyContainer(id, capacity, explCapacity);
    containers.open(CONTAINERS, ofstream::app);
    if(containers.is_open()){
        containers << newHeavyContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
    containers.close();
}

void AddNewRefrigeratedContainer(){
    ofstream containers;
    int id;
    float capacity, explCapacity, refrigCapacity;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max capacity: ";
    cin >> capacity;
    cout << "Enter max capacity (explosives): ";
    cin >> explCapacity;
    cout << "Enter max capacity (refrigerator): ";
    cin >> refrigCapacity;
    RefrigeratedContainer newRefrigeratedContainer(id, capacity, explCapacity, refrigCapacity);
    containers.open(CONTAINERS, ofstream::app);
    if(containers.is_open()){
        containers << newRefrigeratedContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
    containers.close();
}

void AddNewShip(){
    int id, maxContainers;
    bool explosive = false, refrigerator = false;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max containers: ";
    cin >> maxContainers;
    cout << "Can it ship explosives? [y/n]: ";
    cin.ignore();
    char temp1 = std::getchar();
    if(temp1 == 'y' || temp1 == 'Y'){
        explosive = true;
    }
    cin.ignore();
    cout << "Can it ship refrigerated containers? [y/n]: ";
    char temp2 = std::getchar();
    if(temp2 == 'y' || temp2 == 'Y'){
        refrigerator = true;
    }
    Ship newShip(id, maxContainers, explosive, refrigerator);
    SaveShip(&newShip);
}

void SaveShip(Ship* ship){
    ofstream ships;
    ships.open(SHIPS, ofstream::app);
    if(ships.is_open()){
        ships << ship -> ToString() << endl;
    }else{
        perror("Can't open file");
    }
    ships.close();
}

void PlanNewDelivery(){
    int shipId;
    cout << "Enter the id of the ship: ";
    cin >> shipId;
    if(CheckShip(shipId)){
        //TODO: select containers and load the ship.
    }else{
        cout << "This ship isn't available. Please, try again..." << endl;
    }
}

bool CheckShip(int id){
    bool check = false;
    ifstream ships (SHIPS);
    if(ships.is_open()){
        string key, value;
        while(ships >> key >> value){
            if(key.compare("ID:") && std::stoi(value) == id){
                check = true;
            }
        }
    }else{
        perror("Can't open file");
    }
    return check;
}