#pragma once
#include <vector>
#include "Medikament.h"

using namespace std;

class Repository
{
private:

	vector <Medicine> meds;

public:

	Repository();

	~Repository();

	/// <summary>	Adds a medication in the medicine container. </summary>
	///
	/// <remarks>	Horatiu, 4/13/2020. 
	/// 
	/// 			If the medicine with the same name and concentration is already there, quantity and price will be changed.
	/// 									
	/// </remarks>
	///
	/// <param name="name">				The name of new medication. </param>
	/// <param name="concentration">	The concentration of new medication. </param>
	/// <param name="price">			The price of new medication. </param>
	/// <param name="quantity">			The quantity of new medication. </param>
	///
	/// <returns>	A Medicine. </returns>
	
	Medicine add_medication(string name, double concentration, double price, int quantity);

	/// <summary>	Deletes the medication that matches the given string and concentration. </summary>
	///
	/// <remarks>	Horatiu, 4/13/2020. </remarks>
	///
	/// <param name="name">				The name of medication. </param>
	/// <param name="concentration">	The concentration of medication. </param>
	///
	/// <returns>	The deleted medication. </returns>
	
	Medicine delete_medication(string name, double concentration);

	/// <summary>	Updates the medication with the given name and concentration. </summary>
	///
	/// <remarks>	Horatiu, 4/13/2020. </remarks>
	///
	/// <param name="name">				The name of medication. </param>
	/// <param name="concentration">	The concentration of medication. </param>
	/// <param name="price">			The new price of medication. </param>
	///
	/// <returns>	The Medicine with the updated price. </returns>
	
	Medicine update_medication(string name, double concentration, double price);

	/// <summary>	Return the element with the specified name and concentration </summary>
	///
	/// <remarks>	Horatiu, 4/13/2020. </remarks>
	///
	/// <param name="name">				The name of medication. </param>
	/// <param name="concentration">	The concentration of medication. </param>
	///
	/// <returns>	The medicine. </returns>
	
	Medicine get_element(string name, double concentration);

	bool search_medication_by_name(string StringToLookFor);

	bool search_medication_by_quantity(int SearchedQuantity);

	bool group_medication_by_price();

	//write and read are for storing medication in the specified filename
	void write_file(vector <Medicine> v, string filename);

	void read_file(vector <Medicine>& v, string filename);

	//returns the container for the medicine
	vector<Medicine>& meds_getter() {return meds;}
};

