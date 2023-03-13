#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
public:
    Animal() {
        type = "Unknown";
        name = "Unknown";
        age = 0;
        abilities = 0;
    }
    Animal(string _type, string _name, int _age, int _abilities) {
        type = _type;
        name = _name;
        age = _age;
        abilities = _abilities;
    }
    Animal(const Animal& other) {
        type = other.type;
        name = other.name;
        age = other.age;
        abilities = other.abilities;
    }
    
    ~Animal() {}
    
    string getType() const{
        return type;
    }
    string getName() const{
        return name;
    }
    int getAge() const{
        return age;
    }
    int getAbilities() const{
        return abilities;
    }
    
    void printInfo() const {
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Abilities: " << abilities << endl;
    }

    
    void elder() {
        age++;
    }

    // Check if animal is alive (age < 10)
    bool isAlive() const {
        return age < 10;
    }

    // Check if animal can eat another animal
    bool canEat(const Animal& other) const {
        // Rules:
        // - Carnivores eat herbivores (abilities = 1)
        // - Herbivores don't eat anything
        // - Omnivores eat everything
        if (abilities == 2) {
            return true;
        } else if (abilities == 1 && other.abilities == 0) {
            return true;
        } else {
            return false;
        }
    }

private:
    string type;
    string name;
    int age;
    int abilities;
};

int main() {
    // seed random generator 
    srand(time(NULL));
    
    Animal** animals = new Animal*[100];
    for (int i = 0; i < 100; i++) {
        string type;
        switch (rand() % 3) {
            case 0:
                type = "Carnivore";
                break;
            case 1:
                type = "Herbivore";
                break;
            case 2:
                type = "Omnivore";
                break;
        }
        string name = "Animal" + to_string(i);
        int age = rand() % 10;
        int abilities = rand() % 3; // 0 = can't eat, 1 = herbivore, 2 = carnivore/omnivore

        // Create new animal and store it in array
        animals[i] = new Animal(type, name, age, abilities);
    }

    // Fight until only one animal is left
    int numAlive = 100;
    while (numAlive > 1) {
        // Find two alive animals to fight
        int index1 = rand() % 100;
        while (!animals[index1]->isAlive()) {
            index1 = rand() % 100;
        }
        int index2 = rand() % 100;
        while (!animals[index2]->isAlive() || index2 == index1) {
            index2 = rand() % 100;
        }

        // Make animals fight
        if (animals[index1] != NULL && animals[index2] != NULL && animals[index1]->canEat(*animals[index2])) {
            // Animal 1 eats animal 2
            cout << animals[index1]->getName() << " (" << animals[index1]->getType() << ") eats " << animals[index2]->getName() << " (" << animals[index2]->getType() << ")" << endl;
            delete animals[index2];
            animals[index2] = NULL;
            numAlive--;
        } else if ( animals[index1] != NULL && animals[index2] != NULL && animals[index2]->canEat(*animals[index1])) {
            // Animal 2 eats animal 1
            cout << animals[index2]->getName() << " (" << animals[index2]->getType() << ") eats " << animals[index1]->getName() << " (" << animals[index1]->getType() << ")" << endl;
            delete animals[index1];
            animals[index1] = NULL;
            numAlive--;
        } else {
            if (animals[index1] != NULL && animals[index2] != NULL ) {
                // Animals don't fight, they are too similar
                cout << animals[index1]->getName() << " (" << animals[index1]->getType() << ") and "
                     << animals[index2]->getName() << " (" << animals[index2]->getType() << ") are too similar to fight"
                     << endl;
            }
        }
        // Make surviving animals older
        for (int i = 0; i < 100; i++) {
            if (animals[i] != NULL && animals[i]->isAlive()) {
                animals[i]->elder();
            }
        }
    }
    
    cout << endl << "The winner is:" << endl;
    for (int i = 0; i < 100; i++) {
        if (animals[i] != NULL) {
            animals[i]->printInfo();
            break;
        }
    }
    for (int i = 0; i < 100; i++) {
        if (animals[i] != NULL) {
            delete animals[i];
        }
    }
    delete[] animals;

    return 0;
}
