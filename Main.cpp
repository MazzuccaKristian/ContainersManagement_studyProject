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
                ShowPort();
                break;

            case 2:
                AddNewContainer();
                break;
        }
    }
    return 0;
}

void ShowMainMenu(){
    cout << "MAIN MENU" << endl;
    cout << "1) Show port's detail;" << endl;
    cout << "2) Add new container;" << endl;
    cout << "0) Exit." << endl;
    cout << "Enter your choice: ";
}

void ShowPort(){
    ifstream port (PORT);
    if(port.is_open()){
        string line;
        while(getline(port, line)){
            cout << line << endl;
        }
        cout << endl;
    }else{
        perror("Can't open file");
    }
}

void AddNewContainer(){
    int id;
    float capacity;
    ofstream port;
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter max capacity: ";
    cin >> capacity;
    Container newContainer(id, capacity);
    port.open(PORT, ofstream::app);
    if(port.is_open()){
        port << newContainer.ToString() << endl;
    }else{
        perror("Can't open file");
    }
}