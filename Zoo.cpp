#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

class Animal
{

public:

    Animal(string name, int age, string activity, string residence)
        : name(name), age(age), activity(activity), residence(residence), info(" ") {}

    string getName()
    {
        return name;
    }

    void setName(string name)
    {
        name = name;
    }


    void Stand()
    {
        cout << name << " is standing" << endl;
    }


    void Lie()
    {
        cout << name << " is lying" << endl;
    }

    void Hunt()
    {
        cout << name << " is hunting" << endl;
    }

    void Feed()
    {
        cout << name << " is fed" << endl;
    }



    virtual void MakeSound()
    {
        cout << "" << endl;
    }

    virtual string Ability() {
        return "";
    }

    void setInfo(string info)
    {
        info = info;
    }

    void getInfo()
    {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Activity: " << activity << endl;
        cout << "Residence: " << residence << endl;
        cout << Ability() << endl;
        cout << endl;
    }


protected:
    string name;
    string info;
    string activity;
    string residence;
    double age;
};

class Zoo
{
private:
    vector<Animal*> animals;
public:

    void deleteAnimal(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals.erase(animals.begin() + i);
                break;
            }
        }

    }

    void addAnimal(Animal* animal)
    {
        animals.push_back(animal);
    }

    void feedAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->Feed();
        }
    }
    void MakeSoundSmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->MakeSound();
                break;
            }
        }
    }


    void HuntSmb(string name)
    {
        for (int i = 0; i < animals.size(); i++)
        {
            if (animals[i]->getName() == name)
            {
                animals[i]->Hunt();
                break;
            }
        }
    }
    void randompositionAll()
    {
        srand(time(0));
        int x;
        x = rand() % 3 + 1;

        if (x == 2)
        {
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->Lie();
            }
        }
        else
        {
            for (int i = 0; i < animals.size(); i++)
            {
                animals[i]->Stand();
            }
        }

    }
    void infoAll()
    {
        for (int i = 0; i < animals.size(); i++)
        {
            animals[i]->getInfo();
        }
    }
};

class Raven : public Animal
{
public:

    Raven(string name, int age, string activity, string residence, string superpower)
        : Animal(name, age, activity, residence), superpower(superpower) {}

    void fly()
    {
        cout << name << " is flying" << endl;
    }
    void MakeSound() override
    {
        cout << name << ": kar-kar!" << endl;
    }
    string Ability() override
    {
        return name + "'s ability is " + superpower;
    }

private:
    string superpower;
};

class Wolf : public Animal
{
public:

    Wolf(string name, int age, string activity, string residence, string superpower)
        : Animal(name, age, activity, residence), superpower(superpower) {}

    void howl()
    {
        cout << name << "is howling under the moon";
    }

    void MakeSound() override {
        cout << name << ": whoo-hoo!" << endl;
    }
    string Ability() override {
        return name + "'s ability is " + superpower;
    }


private:
    string superpower;
};

class Snake : public Animal {
public:
    Snake(string name, int age, string activity, string residence, string superpower)
        : Animal(name, age, activity, residence), superpower(superpower) {}

    void crawl()
    {
        cout << name << " is crawling" << endl;
    }
    void MakeSound() override {
        cout << name << "shhh-shhh " << endl;
    }
    string Ability() override {
        return name + "'s ability is " + superpower;
    }

private:
    string superpower;
    string tooth_length;
};

int main() {

    Zoo zoo;





    Raven a("Nevar", 5, "sitting in the nest", "Moskow", "flight");
    Wolf b("Flow", 4, "fightin for the leadership", "Siberia", "roar");
    Snake c("Ekans", 8, "sleepin", "The tropics", "poison");




    zoo.addAnimal(&a);
    zoo.addAnimal(&b);
    zoo.addAnimal(&c);


    zoo.feedAll();
    cout << "" << endl;
    zoo.randompositionAll();
    cout << "" << endl;
    zoo.infoAll();
    cout << "" << endl;

    zoo.HuntSmb("Ekans");
    zoo.MakeSoundSmb("Nevar");

    cout << "----------------------------------------------------------------" << endl;
    cout << endl;

    zoo.deleteAnimal("Nevar");

    zoo.feedAll();





    return 0;

}