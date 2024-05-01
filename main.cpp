#include <iostream>
#include <string>

struct Link {
    std::string value;
    Link* succ;
    Link* prev;

    Link(const std::string& val, Link* p = nullptr, Link* s = nullptr) : value{val}, prev{p}, succ{s} {}
};

class LinkedList {
private:
    Link* head;
    Link* tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {};

    ~LinkedList() {
        Link* current = head;

        while (current != nullptr) {
            Link* next = current->succ;
            delete current;
            current = next;
        }
    }

    void insert(const std::string& val);
    double userVal(double x);
    double output(Link* node, double y);

};


void LinkedList::insert(const std::string& val) {
    Link* newNode = new Link{val};

    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    }

    else {
        tail->succ = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

double LinkedList::userVal(double x) {
    return output(head, x);
}

double LinkedList::output(Link* node, double y) {
    if(node == nullptr) {
        return y;
    }

    return output(node->succ, y/2);
}

int main() {
    LinkedList norse_gods;
    norse_gods.insert("Freyja");
    norse_gods.insert("Odin");
    norse_gods.insert("Thor");
    norse_gods.insert("Loki");

    std::cout << "Enter the initial value: ";
    double userInput;
    std::cin >> userInput;

    double value = norse_gods.userVal(userInput);

    std::cout << "Output: " << value << std::endl;

    return 0;
}
