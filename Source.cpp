#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <string.h>
using namespace std;

char slova[6] = { 'A','D','F','G', 'V', 'X' };

char matrica[6][6] = { 
	{'B', '2', 'E', '5', 'R', 'L'},
	{'I', '9', 'N', 'A', '1', 'C'},
	{'3', 'D', '4', 'F', '6', 'G'},
	{'7', 'H', '8', 'J', '0', 'K'},
	{'M', 'O', 'P', 'Q', 'S', 'T'},
	{'U', 'V', 'W', 'X', 'Y', 'Z'} 
};

void pretvoriUCaps(string& unos) {
	char c = ' ';
	string s = "";
	for (int i = 0; i < unos.length(); i++) {
		c = toupper(unos[i]);
		s.push_back(c);
	}
	unos = s;
}

string enkriptovanTekst = "";

bool traziKombinaciju(char unos) {
	
	char slovo1 = ' ';
	char slovo2 = ' ';

	for (int j = 0; j < 6; j++)
	{
		for (int k = 0; k < 6; k++)
		{
			if (matrica[j][k] == unos)
			{
				slovo1 = slova[j];
				slovo2 = slova[k];
				enkriptovanTekst.push_back(slovo1);
				enkriptovanTekst.push_back(slovo2);
				return true;
			}
		}
	}
	return false;
}

string Enkripcija(string unos) {

	if (unos.length() != 0)
	{	
		pretvoriUCaps(unos);
		for (int i = 0; i < unos.length(); i++)
		{
			if (traziKombinaciju(unos[i]))
				continue;
		}
		return enkriptovanTekst;
	}
	else
		return "Niste nista unijeli";
}

string Dekripcija(string unos) {
	string dektriptovanTekst = "";
	int index1 = 0, index2 = 0;
	bool pronadjenoPrvoSlovo = false, pronadjenoDrugoSlovo = false;

	if (unos.length() != 0) {

		pretvoriUCaps(unos);

		for (int i = 0; i < unos.length() - 1; i += 2)
		{
			char slovo1 = unos[i];
			char slovo2 = unos[i + 1];

			for (int j = 0; j < 6; j++)
			{
				if (slova[j] == slovo1) {
					index1 = j;
					pronadjenoPrvoSlovo = true;
				}
				if (slova[j] == slovo2) {
					index2 = j;
					pronadjenoDrugoSlovo = true;
				}
				if (pronadjenoPrvoSlovo && pronadjenoDrugoSlovo) {
					dektriptovanTekst.push_back(matrica[index1][index2]);
					pronadjenoPrvoSlovo = false;
					pronadjenoDrugoSlovo = false;
					break;
				}
			}
		}
		return dektriptovanTekst;
	}
	else
		return "Niste nista napisali";
}

int main() {

	char izbor = ' ', odg=' ';
	string unos = "";   
	
	do {
		cout << "Zelite li uraditi enkripciju (E ili e) ili dekripciju (D ili d)? ";
		cin >> izbor;
		cin.ignore();

		if (izbor == 'E' || izbor == 'e') {

			cout << "Unesite string za enkripciju: " << endl;		
			getline(cin, unos);

			unos.erase(remove(unos.begin(), unos.end(), ' '), unos.end());

			cout << endl;
			cout << Enkripcija(unos) << endl;
		}
		else if (izbor == 'D' || izbor == 'd') {

			cout << "Unesite string za dekripciju: " << endl;
			getline(cin, unos);

			unos.erase(remove(unos.begin(), unos.end(), ' '), unos.end());

			cout << endl;
			cout << Dekripcija(unos) << endl;
		}
		cout << "Zelite li ponovo? (d/n) ";
		cin >> odg;
	} while (odg=='d');


	//enkripcija   //JANUARY 191917
	
	//dekripcija     //GGDGD FXADG AVXVD VDDDV DDDVG A



	return 0;
}
