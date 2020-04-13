#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab4_OOP/Repository.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(MedikamentClass)
	{
	public:
		
		TEST_METHOD(ConstructorTest)
		{
			auto med = new Medicine("Euthyrox", 100, 345.99, 0);
			Assert::AreEqual(100.0, med->get_concentration());
			Assert::AreEqual(345.99, med->get_price());
			Assert::AreEqual(0, med->get_quantity());
			Assert::AreEqual(string("Euthyrox"), med->get_name());
		}

	};

	TEST_CLASS(RepositoryClass)
	{
	public:

		TEST_METHOD(AddTest)
		{
			auto repo = new Repository;

			auto med = repo->add_medication("aspirina", 10, 10, 10);

			Assert::AreEqual(string("aspirina"),med.get_name());
			Assert::AreEqual(10.0, med.get_price());
			Assert::AreEqual(10 , med.get_quantity());
			Assert::AreEqual(10.0, med.get_concentration());
	
		}

		TEST_METHOD(DeleteTest)
		{
			auto repo = new Repository;

			Medicine m = repo->add_medication("bbb", 3, 3, 3);

			auto med = repo->delete_medication("bbb", 3);

			Assert::AreEqual(string("bbb"), med.get_name());
			Assert::AreEqual(3.0, med.get_concentration());
			Assert::AreEqual(3.0, med.get_price());
			Assert::AreEqual(3, med.get_quantity());

		}

		TEST_METHOD(UpdateTest)
		{
			auto repo = new Repository;

			Medicine m = repo->add_medication("bbb", 3, 3, 3);

			auto med = repo->update_medication("bbb", 3, 50);

			Assert::AreEqual(string("bbb"), med.get_name());
			Assert::AreEqual(3.0, med.get_concentration());
			Assert::AreEqual(3, med.get_quantity());
			Assert::AreEqual(50.0, med.get_price());

		}

		TEST_METHOD(SearchByName)
		{
	
			auto repo = new Repository;

			vector<Medicine> ReturnedMedicationsVector = repo->search_medication_by_name("aspirina");

			Assert::IsTrue(ReturnedMedicationsVector.empty());


			Medicine m1 = repo->add_medication("aspirina", 100, 19.99, 10);

			Medicine m2 = repo->add_medication("aspirina", 200, 21.99, 11);

			ReturnedMedicationsVector = repo->search_medication_by_name("aspirina");

			Assert::IsFalse(ReturnedMedicationsVector.empty());

			for (int i = 0; i < ReturnedMedicationsVector.size(); i++)
				Assert::AreEqual(string("aspirina"), ReturnedMedicationsVector[i].get_name());

		}

		TEST_METHOD(SearchByQuantity)
		{
			auto repo1 = new Repository;

			vector<Medicine> ReturnedMedicationsVector = repo1->search_medication_by_quantity(10);

			Assert::IsTrue(ReturnedMedicationsVector.empty());

			Medicine m1 = repo1->add_medication("aspirina", 100, 99.99, 9);

			Medicine m2 = repo1->add_medication("ibuprofen", 200, 89.99, 9);

			Medicine m3 = repo1->add_medication("nurofen", 300, 45.99, 11);

			ReturnedMedicationsVector = repo1->search_medication_by_quantity(10);

			Assert::IsFalse(ReturnedMedicationsVector.empty());

			for (int i = 0; i < ReturnedMedicationsVector.size(); i++)
				Assert::IsTrue(ReturnedMedicationsVector[i].get_quantity() < 10);
			
		}

		TEST_METHOD(GroupByPrice)
		{
			
			auto repo2 = new Repository;

			vector<Medicine> ReturnedMedicationsVector = repo2->group_medication_by_price();

			Assert::IsTrue(ReturnedMedicationsVector.empty());

			Medicine m1 = repo2->add_medication("paracetamol", 100, 10.99, 10);

			Medicine m2 = repo2->add_medication("aspirina", 200, 14.50, 30);

			Medicine m3 = repo2->add_medication("euthyrox", 100, 99.99, 62);

			Medicine m4 = repo2->add_medication("nurofen", 500, 35.99, 17);

			ReturnedMedicationsVector = repo2->group_medication_by_price();

			Assert::IsFalse(ReturnedMedicationsVector.empty());

			for (int i = 0; i < ReturnedMedicationsVector.size() - 1; i++)
				Assert::IsTrue(ReturnedMedicationsVector[i].get_price() <= ReturnedMedicationsVector[i+1].get_price());
			
		}

	};
}
