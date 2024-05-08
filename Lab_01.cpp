#include <iostream>
#include <string>

struct Node {
    std::string name;
    int age;
    double salary;
    Node* next;
};

void addNodeToBeginning(Node*& head, std::string name, int age, double salary) {
    Node* newNode = new Node{ name, age, salary, head };
    head = newNode;
}

void addNodeToEnd(Node*& head, std::string name, int age, double salary) {
    Node* newNode = new Node{ name, age, salary, nullptr };
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void addNodeAfter(Node* head, std::string name, int age, double salary, std::string targetName) {
    Node* current = head;
    while (current != nullptr && current->name != targetName) {
        current = current->next;
    }
    if (current != nullptr) {
        Node* newNode = new Node{ name, age, salary, current->next };
        current->next = newNode;
    }
    else {
        std::cout << "Element with name " << targetName << " not found in the list." << std::endl;
    }
}

void addNodeBefore(Node*& head, std::string name, int age, double salary, std::string targetName) {
    if (head->name == targetName) {
        addNodeToBeginning(head, name, age, salary);
    }
    else {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->name != targetName) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            Node* newNode = new Node{ name, age, salary, current };
            prev->next = newNode;
        }
        else {
            std::cout << "Element with name " << targetName << " not found in the list." << std::endl;
        }
    }
}

void deleteNode(Node*& head, std::string targetName) {
    if (head->name == targetName) {
        Node* deleteNode = head;
        head = head->next;
        delete deleteNode;
    }
    else {
        Node* current = head;
        Node* prev = nullptr;
        while (current != nullptr && current->name != targetName) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            prev->next = current->next;
            delete current;
        }
        else {
            std::cout << "Element with name " << targetName << " not found in the list." << std::endl;
        }
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        std::cout << "Name: " << current->name << " | Age: " << current->age << " | Salary: " << current->salary << std::endl;
        current = current->next;
    }
}

int main() {
    Node* head = nullptr;

    addNodeToEnd(head, "Josh", 25, 50000);
    addNodeToBeginning(head, "Bob", 30, 60000);
    addNodeToEnd(head, "Cristi", 35, 70000);

    std::cout << "List after initial additions:" << std::endl;
    printList(head);

    addNodeAfter(head, "Adam", 40, 80000, "Bob");
    addNodeBefore(head, "Eve", 20, 40000, "Cristi");

    std::cout << "List after additional insertions:" << std::endl;
    printList(head);

    deleteNode(head, "Bob");

    std::cout << "List after deletion of element 'Bob':" << std::endl;
    printList(head);

    return 0;
}
