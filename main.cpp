// Mae Schweller
// COMSCI 210
// Lab 23
#include <iostream>
#include <fstream>
#include <iomanip>
#include <set>
#include "Goat.h"
using namespace std;

const int SZ_NAMES = 200, SZ_COLORS = 25, MAX_AGE = 20;
const string MENU = "*** GOAT MANAGER 3001 ***\n[1] Add a goat\n[2] Delete a goat\n[3] List goats\n[4] Quit\nChoice --> ";

int select_goat(set<Goat> trip);
void delete_goat(set<Goat> &trip);
void add_goat(list<Goat> &trip, string [], string []);
void display_trip(list<Goat> trip);
int main_menu();

int select_goat(set<Goat> trip) {
    int count = 1;
    int selection;
    cout << endl << endl;
    cout << "*** Current Goats ***\n";
    for (Goat goat : trip) {
        cout << "[" << count << "] " << goat.get_name() << "(" << goat.get_age()
        << ", " << goat.get_color() << ")\n";
        count ++;
    }
    cout << endl;
    cout << "enter the index of the goat you would like to modify -> ";
    cin >> selection;
    return selection - 1; // subtracting 1 to ensure number returned is the index
                          // rather than the number displayed
}

void delete_goat(list<Goat> &trip) {
    int goatIndex = select_goat(trip);
    trip.erase(goatIndex);
}

void add_goat(list<Goat> &trip, string names[], string colors[]) {
    string name = names[rand() % (SZ_NAMES + 1)];
    string color = colors[rand() % (SZ_COLORS + 1)];
    int age = rand() % (MAX_AGE + 1);
    Goat newGoat(name, age, color);
    trip.push_back(newGoat);
}

void display_trip(list<Goat> trip) {
    int count = 1;
    cout << endl;
    cout << "*** Current Goats ***\n";
    for (Goat goat : trip) {
        cout << "[" << count << "] " << goat.get_name() << "(" << goat.get_age()
        << ", " << goat.get_color() << ")\n";
        ++count;
    }
    cout << endl;
}

int main_menu() {
    int input;
    cout << MENU;
    cin >> input;
    return input;
}

int main() {
    srand(time(0));
    bool again;

    // read & populate arrays for names and colors
    ifstream fin("names.txt");
    string names[SZ_NAMES];
    int i = 0;
    while (fin >> names[i++]);
    fin.close();
    ifstream fin1("colors.txt");
    string colors[SZ_COLORS];
    i = 0;
    while (fin1 >> colors[i++]);
    fin1.close();

    list<Goat> Goats;

    int input = main_menu();
    while (input != 4) {
        switch(input) {
            case 1:
                add_goat(Goats, names, colors);
                display_trip(Goats);
                break;
            case 2:
                delete_goat(Goats);
                display_trip(Goats);
                break;
            case 3:
                display_trip(Goats);
                break;
            default:
                cout << "Invalid choice, try again\n";
        }
        input = main_menu();
    }
    cout << "Thank you for using Goat Manager 3001!\n";

    return 0;
}

