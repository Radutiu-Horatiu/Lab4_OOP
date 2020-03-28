#include "Repository.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

Repository::Repository()
{

}

Repository::~Repository()
{

}

bool Repository::add_medication(string N, double C, bool okay)
{
	bool ok = false; //kein vorhandenes Produkt
	int saver_i = 0;
	int saver_q = 0;

	for (int i = 0; i != meds.size(); ++i)
	{
		if ((meds[i].get_name() == N) && (meds[i].get_concentration() == C)) // Prufen ob es ein vorhandenes Produkt eingegeben wurde oder nicht
		{
			ok = true; // vorhandenes Produkt

			cout << "Sie wollen ein schon vorhandenes Produkt hinzufügen...\n";
			cout << "Geben sie bitte die gewunschte Menge die sie zu den akutelle Menge addieren wollen:\n";

			int QQQ;
			cin >> QQQ;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> QQQ;
			}
			saver_q = QQQ;
			saver_i = i;

			meds[i].add_to_quantity(QQQ);
			cout << "Fertig!\n";

		}
	}

	if (ok == false) // Kein vorhandenes Produkt eingegeben
	{
		cout << "Neues Produkt ist zu addieren...\n";
		cout << "Geben sie bitte die gewunschte Menge die sie eingeben wollen:\n";

		int Quan;
		cin >> Quan;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> Quan;
		}

		cout << "Geben sie bitte die gewunschte Preis fur die Meds:\n";
		double Pri;
		cin >> Pri;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> Pri;
		}

		Medicine NeuMed;
		NeuMed.set_name(N);
		NeuMed.set_concentration(C);
		NeuMed.set_quantity(Quan);
		NeuMed.set_price(Pri);
		meds.push_back(NeuMed);

		cout << "Addieren!\n";
		cout << "Loading ... (0%)\n";
		cout << "Loading ... (25%)\n";
		cout << "Loading ... (50%)\n";
		cout << "Loading ... (75%)\n";
		cout << "Loading ... (100%)\n";
		cout << "Fertig!\n";
	}

	if (okay == true)//Not reusing the function for redo or undo
	{
		cout << "Redo or Undo?\n1 - Redo\n2 - Undo\n3(oder irgend eine Zahl) - Nichts\n";

		int nr = 69;

		cin >> nr;
		while (std::cin.fail()) {
			std::cout << "Error" << std::endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> nr;
		}

		if (nr == 1) //Redo
		{
			cout << "Sie haben Redo gewahlt. Sie werden jetzt ihr letztes Wunsch nocheinmal machen.\n";

			if (ok == true) //Vorhandenes Produkt
			{
				cout << "\nuai\n";
				saver_q = -saver_q;
				meds[saver_i].add_to_quantity(saver_q);
				return false;
			}
			else if (ok == false) //Neues Produkt
			{
				delete_medication(N, C, false);
				return false;
			}
		}
		else if (nr == 2) //Undo
		{
			cout << "Sie haben Undo gewahlt. Ihr letztes Wahl wurde geloscht.\n";

			if (ok == true) //Vorhandenes Produkt
			{
				saver_q = -saver_q;
				meds[saver_i].add_to_quantity(saver_q);
				return true;
			}
			else if (ok == false) //Neues Produkt
			{
				delete_medication(N, C, false);
			}
		}

		return true;

	}

	return true;

}

bool Repository::delete_medication(string N, double C, bool okay)
{
	if (meds.empty() == false)
	{
		bool ok = false; // Produkt nicht gefunden.

		int i = 0;
		while (i != meds.size())
		{
			bool okok = false;
			if ((meds[i].get_name() == N) && (meds[i].get_concentration() == C)) // Suchen fur Produkt
			{
				ok = true; // Produkt gefunden

				cout << "Produkt die sie loschen wollen wurde gefunden!\n";

				cout << "Loschen!\n";

				if (i == 0)
				{
					okok = true;
					meds.erase(meds.begin());
				}
				else
				{
					okok = true;
					meds.erase(meds.begin() + i);
				}


				cout << "Loading ... (0%)\n";
				cout << "Loading ... (25%)\n";
				cout << "Loading ... (50%)\n";
				cout << "Loading ... (75%)\n";
				cout << "Loading ... (100%)\n";
				cout << "Fertig!\n";

			}

			if (okok != true)
				i++;
			else
				break;
		}

		if (ok == false)
		{
			cout << "Produkt nicht gefunden!\n";
			return true;
		}

		if (okay == true)//Not reusing the function for redo or undo
		{
			cout << "Redo or Undo?\n1 - Redo\n2 - Undo\n3(oder irgend eine Zahl) - Nichts\n";

			int nr = 69;

			cin >> nr;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> nr;
			}

			if (nr == 1)//Redo
			{
				cout << "Sie haben Redo gewahlt. Sie werden jetzt ihr letztes Wunsch nocheinmal machen.\n";

				add_medication(N, C, false);
				return false;

			}
			else if (nr == 2)//Undo
			{
				cout << "Sie haben Undo gewahlt. Ihr letztes Wahl wurde geloscht.\n";
				add_medication(N, C, false);
				return true;
			}

			return true;
		}

		return true;
	}
	else
		cout << "Container ist leer!\n";
	

}

bool Repository::update_medication(string N, double C, bool okay)
{
	if (meds.empty() == false)
	{
		bool ok = false; //Produkt nicht gefunden

		string saver_n;
		double saver_con = 0.0;
		double saver_p = 0.0;
		int saver_q = 0;

		int saver_in = 0;
		int saver_icon = 0;
		int saver_ip = 0;
		int saver_iq = 0;

		bool ok_n = false;
		bool ok_con = false;
		bool ok_p = false;
		bool ok_q = false;



		for (int i = 0; i != meds.size(); ++i)
		{
			if ((meds[i].get_name() == N) && (meds[i].get_concentration() == C)) // Prufen ob es ein vorhandenes Produkt eingegeben wurde oder nicht
			{
				ok = true; // vorhandenes Produkt

				cout << "Was wollen sie verarbeiten?\n";

				cout << "\n1 - Name verandern\n2 - Koncentration verandern\n3 - Preis verandern\n4 - Menge verandern\n";

				int opt = 69;

				while (opt != 0)
				{
					cin >> opt;
					while (std::cin.fail()) {
						std::cout << "Error" << std::endl;
						std::cin.clear();
						std::cin.ignore(256, '\n');
						std::cin >> opt;
					}

					if (opt == 1)
					{
						ok_n = true;
						cout << "Geben sie die neue Name: \n";
						string NN;
						cin >> NN;
						while (std::cin.fail()) {
							std::cout << "Error" << std::endl;
							std::cin.clear();
							std::cin.ignore(256, '\n');
							std::cin >> NN;
						}

						saver_n = meds[i].get_name();
						saver_in = i;
						meds[i].set_name(NN);
						cout << "Verandert!\n";
					}

					else if (opt == 2)
					{
						ok_con = true;
						cout << "Geben sie die neue Koncentration: \n";
						double KK;
						cin >> KK;
						while (std::cin.fail()) {
							std::cout << "Error" << std::endl;
							std::cin.clear();
							std::cin.ignore(256, '\n');
							std::cin >> KK;
						}

						saver_con = meds[i].get_concentration();
						saver_icon = i;
						meds[i].set_concentration(KK);
						cout << "Verandert!\n";
					}

					else if (opt == 3)
					{
						ok_p = true;
						cout << "Geben sie die neue Preis: \n";
						double PP;
						cin >> PP;
						while (std::cin.fail()) {
							std::cout << "Error" << std::endl;
							std::cin.clear();
							std::cin.ignore(256, '\n');
							std::cin >> PP;
						}

						saver_p = meds[i].get_price();
						saver_ip = i;
						meds[i].set_price(PP);
						cout << "Verandert!\n";
					}

					else if (opt == 4)
					{
						ok_q = true;
						cout << "Geben sie die neue Menge: \n";
						int MM;
						cin >> MM;
						while (std::cin.fail()) {
							std::cout << "Error" << std::endl;
							std::cin.clear();
							std::cin.ignore(256, '\n');
							std::cin >> MM;
						}

						saver_q = meds[i].get_quantity();
						saver_iq = i;
						meds[i].set_quantity(MM);
						cout << "Verandert!\n";
					}

					else if (opt == 0)
						return true;

					else
					{
						cout << "Unmogliche wahl! Range = [0, 4]\n";
					}

					cout << "\n1 - Name verandern\n2 - Koncentration verandern\n3 - Preis verandern\n4 - Menge verandern\n";
				}

			}
		}

		if (ok == false) //Kein vorhandenes Produkt gegeben
		{
			/*
			cout << "Sie haben ein nicht vorhandenes Produkt gegeben.\n";
			cout << "Wollen sie die eingegebene Produkt hineinfugen ?\n";
			cout << "\n1 - Ja!\n2 - Nein!\n";

			int opt = 69;

			cin >> opt;

			while (opt != 2)
			{
				if (opt == 1)
					add_medication(N, C, false);
				else if (opt == 2)
					cout << "Okay! Tschus!\n";
				else
					cout << "Unmogliche Wahl!\n Bitte 1 oder 2 wahlen...\n";
			}
			*/

			cout << "Kein Update moglich. Eingegebene Information nicht gefunden!\n";
			return true;
		}


		if (okay == true) //Not reusing the function for redo or undo
		{
			cout << "Redo or Undo?\n1 - Redo\n2 - Undo\n3(oder irgend eine Zahl) - Nichts\n";

			int nr = 69;

			cin >> nr;
			while (std::cin.fail()) {
				std::cout << "Error" << std::endl;
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cin >> nr;
			}

			if (nr == 1)
			{
				bool redo = false;

				if (ok_n == true)
				{
					redo = true;
					meds[saver_in].set_name(saver_n);
				}

				if (ok_con == true)
				{
					redo = true;
					meds[saver_icon].set_concentration(saver_con);
				}
				if (ok_p == true)
				{
					redo = true;
					meds[saver_ip].set_price(saver_p);
				}
				if (ok_q == true)
				{
					redo = true;
					meds[saver_iq].set_quantity(saver_q);
				}

				if (redo == true)
				{
					update_medication(N, C, false);
				}

				return true;
			}
			else if (nr == 2)
			{
				if (ok_n == true)
				{
					meds[saver_in].set_name(saver_n);
				}

				if (ok_con == true)
				{
					meds[saver_icon].set_concentration(saver_con);
				}
				if (ok_p == true)
				{
					meds[saver_ip].set_price(saver_p);
				}
				if (ok_q == true)
				{
					meds[saver_iq].set_quantity(saver_q);
				}

				return true;
			}


			return true;
		}

		return true;
	}
	else
	cout << "Container ist leer!\n";
	
}

void Repository::search_medication_by_name(string Z)
{
	if (meds.empty() == false)
	{
		if (Z.empty())
		{
			cout << "Eingegebene Zeichenkette ist leer! Diese sind alle Produkte die enthalten sind:\n";

			std::sort(meds.begin(), meds.end());

			cout << " -------------------------------------------\n";

			for (int i = 0; i != meds.size(); ++i)
			{
				cout << "Name: " << meds[i].get_name() << "\nKoncentration: " << meds[i].get_concentration() << "\nPreis: " << meds[i].get_price() << "\nMenge: " << meds[i].get_quantity() << endl;
				cout << " -------------------------------------------\n";
			}
			cout << "\n";
			cout << "Fertig!\n";

			cout << " -------------------------------------------\n";
		}
		else
		{
			cout << " -------------------------------------------\n";
			for (int i = 0; i != meds.size(); ++i)
			{

				std::size_t found = meds[i].get_name().find(Z);
				if (found != std::string::npos)
				{
					cout << "Name: " << meds[i].get_name() << "\nKoncentration: " << meds[i].get_concentration() << "\nPreis: " << meds[i].get_price() << "\nMenge: " << meds[i].get_quantity() << endl;
					cout << " -------------------------------------------\n";
				}
			}
			cout << "\n";
			cout << "Fertig!\n";

			cout << " -------------------------------------------\n";
		}
	}
	else
		cout << "Container ist leer!\n";
	

}

void Repository::search_medication_by_quantity(int QQQQ)
{
	if (meds.empty() == false)
	{
		cout << " -------------------------------------------\n";
		for (int i = 0; i != meds.size(); ++i)
		{
			if (meds[i].get_quantity() < QQQQ)
			{
				cout << "Name: " << meds[i].get_name() << "\nKoncentration: " << meds[i].get_concentration() << "\nPreis: " << meds[i].get_price()
					<< "\nMenge: " << meds[i].get_quantity() << endl;

				cout << " -------------------------------------------\n";
			}
		}

		cout << "Fertig!\n";
		cout << " -------------------------------------------\n";
	}
	else
		cout << "Container ist leer!\n";

}


void Repository::group_meds_by_price()
{
	
	if (meds.empty() == false)
	{
		for (int i = 0; i != meds.size() - 1; ++i)
			for (int j = i + 1; j != meds.size(); ++j)
				if (meds[i].get_price() > meds[j].get_price())
				{
					Medicine aux = meds[i];
					meds[i] = meds[j];
					meds[j] = aux;
				}

		cout << " -------------------------------------------\n";
		for (int i = 0; i != meds.size(); ++i)
		{
			cout << "Name: " << meds[i].get_name() << "\nPreis: " << meds[i].get_price() << endl;
			cout << " -------------------------------------------\n";
		}
		cout << "Fertig!\n";
		cout << " -------------------------------------------\n";
	}
	else
		cout << "Container ist leer!\n";


}

