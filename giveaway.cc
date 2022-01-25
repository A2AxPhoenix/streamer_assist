#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include "unistd.h"
#include "Viewer.h"
#include "Prize.h"
using namespace std;

void reset_state() { // They goofed so we gotta fix input
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void bad_input(string s = "INVALID INPUT!") { // Use this for custom error handling. TODO: Fix to use exceptions (try, catch, throw)
	cout << s << endl;
}

int main() {
	vector<Prize> prize_db;
	vector<Viewer> viewer_db;

	const int MAX_FAILS = 5; // 5 Chances
	int failCounter = 0; // Tracks bad input attempts
	enum CHOICES { IMPORT = 1, CREATE, VIEW, ADD, MODIFY, SEARCH, DELETE, EXECUTE,  QUIT };
	enum DB_TYPES { VIEWER = 1, PRIZE, OTHER, BACK };
	cout << "Welcome to GRS Assister 3000!" << endl;
	usleep(2'000'000); // Sleep for 2 seconds
	int choice = 0;
	while (true) {
		cout << "Please enter a choice:\n1) Import a database\n2) Create a database\n3) View a database\n4) Add to a database\n5) Modify a database\n6) Search a database\n7) Delete a database\n8) Get a Winner\n9) Quit\n";
		cin >> choice;
		if (choice < IMPORT || choice > QUIT || !cin) { // Sanity checking
			if (failCounter == MAX_FAILS) { // They were dumb
				bad_input("You've exceeded max attempts to choose from menu.\nQuitting now...");
				usleep(1'000'000);
				exit(EXIT_FAILURE);
			}
			else { // Give them a chance to not be dumb
				usleep(500'000);
				system("clear");
				bad_input("BAD INPUT! Please enter a choice from the menu.");
				failCounter++;
				usleep(500'000);
				reset_state();
				continue;
			}
		}
		if (choice == IMPORT) {
			failCounter = 0;
			int vorp = 0; // vorp = Acronym for Viewer OR Prize
			while (true) {
				cout << "Is this a 1) Viewer database, 2) Prize database, 3) Other database, or 4) Go Back to Main Menu\n";
				cin >> vorp; 
				if (!cin || vorp > BACK || vorp < VIEWER) {
					if (failCounter == MAX_FAILS) { 
						bad_input("You've exceeded max attempts to choose from menu.\nQuitting now...");
						usleep(1'000'000);
						exit(EXIT_FAILURE);
					}
					else {
						usleep(500'000);
						system("clear");
						bad_input("BAD INPUT! Please enter a choice from the menu.");
						failCounter++;
						usleep(500'000);
						reset_state();
					}
				}
				if (vorp == VIEWER) { 
					cout << "Please enter the Viewer Database you'd like to read from:" << endl;
					string filename;
					cin >> filename;
					ifstream ins(filename);
					if (!ins) bad_input("Couldn't load file "s + filename);
					while (ins) {
						Viewer v;

						string viewerCharacteristics;
						getline(ins, viewerCharacteristics);
						stringstream readIn(viewerCharacteristics);
						int tIndex = 0;
						readIn >> tIndex;
						if (!ins) break;
						cout << "tIndex is: " << tIndex << endl;
						string tName;
						readIn >> tName;
						if (!ins) break;
						cout << "tName is: " << tName << endl;
						int tAge = 0;
						readIn >> tAge;
						if (!ins) break;
						cout << "tAge is: " << tAge << endl;
						string tPreferredContact;
						readIn >> tPreferredContact;
						if (!ins) break;
						cout << "tPreferredContact is: " << tPreferredContact << endl;
						string tSocialMedia;
						readIn >> tSocialMedia;
						if (!ins) break;
						cout << "tSocialMedia is: " << tSocialMedia << endl;
						int tTotalFollows = 0;
						readIn >> tTotalFollows;
						if (!ins) break;
						cout << "tTotalFollows is: " << tTotalFollows << endl;
						int tCorrectAnswers = 0;
						readIn >> tCorrectAnswers;
						if (!ins) break;
						cout << "tCorrectAnswers is: " << tCorrectAnswers << endl;
						v.set_ID(tIndex);
						v.set_gamertag(tName);
						v.set_age(tAge);
						v.set_preferredContact(tPreferredContact);
						v.set_defaultSocialMedia(tSocialMedia);
						v.set_totalFollows(tTotalFollows);
						v.set_entries(tCorrectAnswers + tTotalFollows);

						viewer_db.push_back(v);
					}	
				}
				else if (vorp == PRIZE) {}
				else if (vorp == OTHER) {
					cout << "Coming soon..." << endl;
					continue;
				}
				else if (vorp == BACK) {
					cout << "Returning to main menu." << endl;
					usleep(1'000'000);
					break;
				}
			}
		}  // TODO: Import stuff
		else if (choice == CREATE) {} // TODO: Create stuff
		else if (choice == VIEW) {
			failCounter = 0;
			int vorp = 0; // vorp = Acronym for Viewer OR Prize
			while (true) {
				cout << "Would you like to view the 1) Viewer database, 2) Prize database, 3) Other database, or 4) Go Back to Main Menu\n";
				cin >> vorp; 
				if (!cin || vorp > BACK || vorp < VIEWER) {
					if (failCounter == MAX_FAILS) { 
						bad_input("You've exceeded max attempts to choose from menu.\nQuitting now...");
						usleep(1'000'000);
						exit(EXIT_FAILURE);
					}
					else {
						usleep(500'000);
						system("clear");
						bad_input("BAD INPUT! Please enter a choice from the menu.");
						failCounter++;
						usleep(500'000);
						reset_state();
					}
				}
				if (vorp == VIEWER) {
					cout << "Outputting Viewer Database: " << endl;
					for (Viewer &v : viewer_db) cout << v << endl;
				}
			}
		} // TODO: View stuff
		else if (choice == ADD) {} // TODO: Add stuff
		else if (choice == MODIFY) {} // TODO: Modify stuff
		else if (choice == SEARCH) {} // TODO: Search Stuff
		else if (choice == DELETE) {} // TODO: Delete Stuff
		else if (choice == EXECUTE) {} // TODO: Run the ranomizer
		else {
			cout << "Thank you for using GRS Assister 3000!" << endl;
			usleep(2'000'000);
			cout << "Quitting..." << endl;
			usleep(1'000'000);
			exit(EXIT_SUCCESS);
		}
	}
}
