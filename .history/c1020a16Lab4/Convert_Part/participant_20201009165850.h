#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <iostream>
#include <string>
#include <vector>
#include "activity.h"
#include <cstring>
#include <iomanip>
using std::istream;
using std::ostream;
using std::vector;
using std::string;
using std::stod;
using std::stoi;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
const int MAX_LENGTH = 256;

class Participant {
public:

	Participant(){}; // Default constructor
	Participant(const Participant&);//Copy ctor

	//-----Set and Get private data functions-----
	void setFirstName(const char* f_name ){ strcpy (firstName, f_name);}
	const char* getFirstName() const {return firstName;}
	
	void setLastName(const char* l_name){ strcpy (lastName, l_name);}
	const char* getLastName() const {return lastName;}
	
	void setHeight(double h) { height = h;}
	double getHeight() const {return height;}
	
	void setActivity(Activity);
	Activity getActivity(int i) const { return activity[i]; }
	
	void setNumber_Entries(int number) { numberEntries = number;}
	int getNumber_Entries() const {return numberEntries;}
	 
	//-----Overload Operator Functions-----
	friend bool operator< (const Participant&, const Participant&); //Overloaded operator< that compares the first name concatenated to the last name of two participants
	friend bool operator== (const Participant&, const Participant&); // Overloaded operator== that compares the first name concatenated to the last name of two participants
	friend istream& operator>> ( istream&, Participant& );
    friend ostream& operator<<(ostream& out, const Participant&){return out;}; // Overloaded operator<< that print out 

	//-----Additional Functions-----
	Participant& readFile (string);
	void setTotalMiles();
	double getTotalMiles() const {return totalMiles;}

	 

private:
	char firstName[MAX_LENGTH]; // first name of participant 
	char lastName [MAX_LENGTH]; // last name of participant
	double height; // height in inches
	Activity activity[365]; // Array of 365 Activity objects
	int numberEntries; // Number of valid entries in array of Activity objects
    double totalMiles;
};

#endif