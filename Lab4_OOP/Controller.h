#pragma once
#include "Repository.h"
class Controller: public Repository
{
private:


public:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Default constructor of the Controller. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	Controller();



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Destructor of the Controller. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	~Controller();



	//Controller Options:

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Controller Function for Adding a Medicine to the Container. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void add_med();



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Controller Function for Deleting a Medicine from the Container. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void delete_med();



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Controller Function for Updating a Medicine from the Container. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void update_med();



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Controller Function for Searching Medications by their Name. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void search_med_name();



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Controller Function for Searching Medications by their Quantity. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void search_med_quantity();



	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Controller Function for Grouping Medications by their Price. </summary>
	///
	/// <remarks>	Pinko, 4/13/2020. </remarks>
	////////////////////////////////////////////////////////////////////////////////////////////////////
	void group_by_price();


};

////////////////////////////////////////////////////////////////////////////////////////////////////
// End of Controller.h
////////////////////////////////////////////////////////////////////////////////////////////////////

