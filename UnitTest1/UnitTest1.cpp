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

	};
}
