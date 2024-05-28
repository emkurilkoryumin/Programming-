#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

struct Car {
    int id;
    std::string brand;
    std::string model;
    int year;
    int mileage;
};

std::vector<Car> loadDatabase(const std::string& filename) {
    std::vector<Car> cars;
    std::ifstream file(filename);
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            Car car;
            if (iss >> car.id >> car.brand >> car.model >> car.year >> car.mileage) {
                cars.push_back(car);
            }
        }
        file.close();
    }
    return cars;
}

void saveDatabase(const std::vector<Car>& cars, const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        for (const auto& car : cars) {
            file << car.id << " " << car.brand << " " << car.model << " "
                << car.year << " " << car.mileage << "\n";
        }
        file.close();
    }
}

void addCar(std::vector<Car>& cars) {
    Car car;
    std::cout << "Enter ID: ";
    std::cin >> car.id;
    std::cout << "Enter brand: ";
    std::cin >> car.brand;
    std::cout << "Enter model: ";
    std::cin >> car.model;
    std::cout << "Enter year: ";
    std::cin >> car.year;
    std::cout << "Enter mileage: ";
    std::cin >> car.mileage;
    cars.push_back(car);
}

void editCar(std::vector<Car>& cars) {
    int id;
    std::cout << "Enter the ID of the car to edit: ";
    std::cin >> id;
    for (auto& car : cars) {
        if (car.id == id) {
            std::cout << "Enter new brand: ";
            std::cin >> car.brand;
            std::cout << "Enter new model: ";
            std::cin >> car.model;
            std::cout << "Enter new year: ";
            std::cin >> car.year;
            std::cout << "Enter new mileage: ";
            std::cin >> car.mileage;
            return;
        }
    }
    std::cout << "Car with ID " << id << " not found.\n";
}

void deleteCar(std::vector<Car>& cars) {
    int id;
    std::cout << "Enter the ID of the car to delete: ";
    std::cin >> id;
    for (auto it = cars.begin(); it != cars.end(); ++it) {
        if (it->id == id) {
            cars.erase(it);
            std::cout << "Car deleted.\n";
            return;
        }
    }
    std::cout << "Car with ID " << id << " not found.\n";
}

void searchCar(const std::vector<Car>& cars) {
    int id;
    std::cout << "Enter the ID of the car to search: ";
    std::cin >> id;
    for (const auto& car : cars) {
        if (car.id == id) {
            std::cout << "ID: " << car.id << "\nBrand: " << car.brand << "\nModel: " << car.model
                << "\nYear: " << car.year << "\nMileage: " << car.mileage << "\n";
            return;
        }
    }
    std::cout << "Car with ID " << id << " not found.\n";
}

int main() {
    std::vector<Car> cars = loadDatabase("cars.txt");
    while (true) {
        std::cout << "1. Add car\n2. Edit car\n3. Delete car\n4. Search car\n5. Save and exit\n";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            addCar(cars);
        }
        else if (choice == 2) {
            editCar(cars);
        }
        else if (choice == 3) {
            deleteCar(cars);
        }
        else if (choice == 4) {
            searchCar(cars);
        }
        else if (choice == 5) {
            saveDatabase(cars, "cars.txt");
            break;
        }
        else {
            std::cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}
