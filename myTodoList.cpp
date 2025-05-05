#include <iostream>
#include <string>
#include <map>
#include "myLinkedList.cpp"

class TDLM {
    private:
        std::map<std::string, LinkedList*> LS; //listStorage
        LinkedList* sel = nullptr;
    public:
        TDLM();
        ~TDLM();

        // First menu
        void cli();
        void addlist(std::string key);
        void getSelect(std::string key);
        void printStorage();

        // Second menu
        void selectCli();
};

TDLM::TDLM() {cli();};
TDLM::~TDLM() {for(const auto P:LS) {std::cout<<"deleting "<<P.first<<std::endl;delete P.second;}};

void TDLM::cli() {
    int opt;
    std::cout << "Welcome to my LinkedList program | by Amaan Zaidi\n"
              << "1. Create List\n"
              << "2. Select List\n"
              << "3. Show Lists (shows list of linked lists)\n"
              << "4. Quit\n"
              << ": ";
    std::cin >> opt;
    std::cout << std::endl;
    
    std::string optS;
    switch (opt) {
        case 1:
            std::cout << "Enter name of list: ";
            std::cin >> optS;
            addlist(optS);
            return cli();
            break;
        case 2:
            std::cout << "What list do you wanna modify: ";
            std::cin >> optS;
            getSelect(optS);
            if (sel == nullptr) {return cli();}
            return selectCli();
            break;
        case 3:
            printStorage();
            return cli();
            break;
        case 4:
            std::cout << "quitting\n";
            return;
            break;
        default:
            return cli();
            break;
    }
}

void TDLM::addlist(std::string key) {
    LinkedList* L = new LinkedList();
    LS[key] = L;
}

void TDLM::getSelect(std::string key) {
    for(const auto pair:LS) {
        if(pair.first == key) {
            sel = pair.second;
            return;
        }
    }
    sel = nullptr;
}

void TDLM::printStorage() {
    for (const auto pair:LS) {
        std::cout << pair.first << std::endl;
    }
}

void TDLM::selectCli() {
    int opt;
    std::cout << "Selected List | by Amaan Zaidi\n"
              << "1. Insert at end\n"
              << "2. Insert at position\n"
              << "3. Delete node\n"
              << "4. Traverse List\n"
              << "5. Exit\n"
              << ": ";
    std::cin >> opt;
    std::cout << std::endl;
    
    int pos;
    switch (opt) {
        case 1:
            std::cout << "What value would you like to insert?\n:";
            std::cin >> opt;
            std::cout << std::endl;
            sel->insertAtEnd(opt);
            return selectCli();
            break;
        case 2:
            std::cout << "Where would you like to insert?\n:";
            std::cin >> pos;
            std::cout << "\nWhat value would you like to insert?\n:";
            std::cin >> opt;
            sel->insertAtPosition(pos, opt);
            return selectCli();
            break;
        case 3:
            std::cout << "What value would you like to delete?\n:";
            std::cin >> opt;
            sel->deleteNode(opt);
            return selectCli();
            break;
        case 4:
            sel->traverseList();
            return selectCli();
            break;
        case 5:
            return cli();
        default:
            break;
    }
}