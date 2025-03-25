#include <iostream>
#include <string>
using namespace std;

// Creez clasa Animal,clasa principala din care fac mostenirea
class Animal {
protected:
    string nume;
    int varsta;
public:
    //Creez un constructor
    Animal(string nume, int varsta) {
        this->nume = nume;
        this->varsta = varsta;
    }
    //Creez metoda de afisare a animalelor,folosesc "virtual void" ca sa poata fi supracris de alte clase ce folosesc "void ... override"
    virtual void afisare_detalii() {
        cout << "Nume: " << nume << ", Varsta: " << varsta << " ani" << endl;
    }
    //Creez un destructor pentru eliberarea memoriei
    virtual ~Animal() {
        cout << "Destructor apelat pentru: " << nume << endl;
    }

};

// Clasa mostenita, cu numele Pasare, din clasa animal
class Pasare : public Animal {
private:
    float lungimea_aripilor;
    int durata_viata;
public:
    //Creez un constructor pentru tipul de animal pasare
    Pasare(string nume, int varsta, float lungimea_aripilor, int durata_viata)
        : Animal(nume, varsta), lungimea_aripilor(lungimea_aripilor), durata_viata(durata_viata) {}

    //Creez un void pentru afisarea detaliile caruia ii atribui "override",pentru a suprascrie metoda de mai susm,cea de baza,adaugand date specifice pasarilor
    void afisare_detalii() override {
        cout << "Pasare - Nume: " << nume << ", Varsta: " << varsta << " ani, "
            << "Lungimea aripilor: " << lungimea_aripilor << " cm, Durata de viata: "
            << durata_viata << " ani" << endl;
    }
};

// Clasa dmostenita, cu numele Caine, din clasa animal
class Caine : public Animal {
private:
    string rasa;
    string tip_caine;
public:
    //Creez un constructor pentru tipul de animal caine
    Caine(string nume, int varsta, string rasa, string tip_caine)
        : Animal(nume, varsta), rasa(rasa), tip_caine(tip_caine) {}

    //Creez un void pentru afisarea detaliile caruia ii atribui "override",pentru a suprascrie metoda de mai sus,cea de baza,adaugand date specifice cainilor
    void afisare_detalii() override {
        cout << "Caine - Nume: " << nume << ", Varsta: " << varsta << " ani, "
            << "Rasa: " << rasa << ", Tip: " << tip_caine << endl;
    }
};

int main() {
    int n;
    cout << "Introduceti numarul de animale: "; cin >> n;
    Animal** animale = new Animal * [n];

    for (int i = 0; i < n; i++) {
        //Adauf o variabila pe nume tip care va lua valorile 1 si 2 in functie de ce aleg sa adaug,pasare sau caine
        int tip;
        cout << "Alegeti tipul animalului (1 - Pasare, 2 - Caine): "; cin >> tip;

        string nume;
        int varsta;
        cout << "Introduceti numele: "; cin >> nume;
        cout << "Introduceti varsta: "; cin >> varsta;

        //Daca tip=1 atunci se vor adauga date specfice pasarilor si se va apela constructorul pasare
        if (tip == 1) {
            float lungimea_aripilor;
            int durata_viata;
            cout << "Introduceti lungimea aripilor (cm): "; cin >> lungimea_aripilor;
            cout << "Introduceti durata de viata (ani): "; cin >> durata_viata;
            animale[i] = new Pasare(nume, varsta, lungimea_aripilor, durata_viata);
        }
        //Daca tip=2 atunci se vor adauga date specfice cainilor si se va apela constructorul caine
        else if (tip == 2) {
            string rasa, tip_caine;
            cout << "Introduceti rasa cainelui: "; cin >> rasa;
            cout << "Introduceti tipul cainelui: "; cin >> tip_caine;
            animale[i] = new Caine(nume, varsta, rasa, tip_caine);
        }
    }

    cout << "\nAnimalele introduse in gradina zoologica:\n";
    for (int i = 0; i < n; i++) {
        animale[i]->afisare_detalii();
    }

    return 0;
}   