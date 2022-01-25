#ifndef PRIZE_H
#define PRIZE_H
#include "Viewer.h"
#include <iostream>
#include <stdexcept> // TODO: Throw exceptions for all contructors/setters that need them
#include <iomanip> // Set precision
using namespace std;

class Prize {
	private:
		long long ID;
		string name;
		double cost;
		bool available;
		Viewer winner; // The Winner is the Viewer's ID
	public:
		Prize();  // Default
		Prize(long long newID, string newName, double newCost); // Use this if have ID, Name, and Cost
		// Methods
		long long get_ID() const;
		string get_name() const;
		double get_cost() const;
		bool isAvailable() const;
		Viewer get_winner() const;
		void set_ID(long long newID);
		void set_name(string newName);
		void set_cost(int newCost);
		void set_availability(bool isAvailable);
		void set_winner(Viewer newWinner);
		// Operator Overloads
		bool operator<(const Prize &p) const;
		bool operator==(const Prize &p) const;
		friend ostream& operator<<(ostream& outs, const Prize &p);
		friend istream& operator>>(istream& ins, Prize &p);
		};
#endif
