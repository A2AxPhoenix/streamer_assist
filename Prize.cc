#include "Prize.h"
using namespace std;
using P = Prize;

P::Prize() { // Default Constructor
	ID = 0;
	name = "prize";
	cost = 0;
	available = true;
}
P::Prize(long long newID, string newName, double newCost) { // Use this if have ID, Name, Cost
	ID = newID;
	name = newName;
	cost = newCost;
	available = true;
}
// Methods
long long P::get_ID() const { return ID; } // Key
string P::get_name() const { return name; }
double P::get_cost() const { return cost; }
bool P::isAvailable() const { return available; }
Viewer P::get_winner() const { return winner; }
void P::set_ID(long long newID) { ID = newID; }
void P::set_name(string newName) { name = newName; }
void P::set_cost(int newCost) { cost = newCost; }
void P::set_availability(bool isAvailable) { available = isAvailable; }
void P::set_winner(Viewer newWinner) { winner = newWinner; }
// Operator Overloads
bool P::operator<(const Prize &p) const {
	return ID < p.ID;
}
bool P::operator==(const Prize &p) const {
	if (name == p.name) return ID == p.ID; // If similar names, check IDs
	return name == p.name;
}
ostream& operator<<(ostream& outs, const Prize &p) {
	outs << "Outputting Prize..." << endl;
	outs << "ID: " << p.ID << endl;
	outs << "Name: " << p.name << endl;
	outs << "Cost: $" << setprecision(2) << p.cost << endl;
	outs << "Availabilitiy: " << boolalpha << p.available << endl;
	outs << "Winner: " << endl;
	outs << "\t ID: " << p.winner.get_ID() << endl;
	outs << "\t Gamertag: " << p.winner.get_gamertag() << endl;
	outs << "\t Age: " << p.winner.get_age() << endl;
	outs << "\t Preferred Contact: " << p.winner.get_preferredContact() << endl;
	return outs;
}
istream& operator>>(istream& ins, Prize &p) {
	ins >> p.ID >> p.name >> p.cost >> p.available;
	return ins;
}
