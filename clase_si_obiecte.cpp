#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string nume;
    int varsta;
    float medie;

public:
    Student(string nume_student, int varsta_student, float medie_student) {
        nume = nume_student;
        varsta = varsta_student;
        medie = medie_student;
        cout << "Constructorul a fost apelat pentru: " << nume << endl;
    }

    ~Student() {
        cout << "Destructorul a fost apelat pentru: " << nume << endl;
    }

    void afisare_informatii() {
        cout << "Nume: " << nume << ", Varsta: " << varsta << ", Medie: " << medie << endl;
    }

    float returneaza_media() const {
        return medie;
    }

    float getMedie() {
        return medie;
    }
};

void sortare_dupa_medie(Student** studenti, int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (studenti[j]->returneaza_media() > studenti[j + 1]->returneaza_media()) {
                Student* aux = studenti[j];
                studenti[j] = studenti[j + 1];
                studenti[j + 1] = aux;
            }
        }
    }
}

int main() {
    int i, n;
    cout << "Introduceti nr de studenti: ";
    cin >> n;

    Student** studenti = new Student * [n];
    float sumaMedii = 0.0;

    for (i = 0; i < n; i++) {
        string nume;
        int varsta;
        float medie;

        cout << "Introduceti numele studentului " << i + 1 << ": ";
        cin >> nume;
        cout << "Introduceti varsta studentului " << i + 1 << ": ";
        cin >> varsta;
        cout << "Introduceti media studentului " << i + 1 << ": ";
        cin >> medie;

        studenti[i] = new Student(nume, varsta, medie);
        sumaMedii += medie;
    }

    // Apelam functia de sortare
    sortare_dupa_medie(studenti, n);

    cout << "\nStudentii sortati dupa medie sunt: " << endl;
    for (i = 0; i < n; i++) {
        studenti[i]->afisare_informatii();
    }

    // Gasim studentul cu cea mai mare medie
    Student* student_max = studenti[n - 1]; // Ultimul student dupa sortare are cea mai mare medie

    cout << "\nStudentul cu cea mai mare medie este: " << endl;
    student_max->afisare_informatii();

    // Calculam si afisam media mediilor
    float mediaMediilor = sumaMedii / n;
    cout << "\nMedia mediilor studentilor este: " << mediaMediilor << endl;

    // Eliberam memoria
    for (i = 0; i < n; i++) {
        delete studenti[i];
    }
    delete[] studenti;

    return 0;
}
