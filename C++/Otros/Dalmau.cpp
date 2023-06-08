#include <iostream>
#include <string>
using namespace std; 

double differences(double money, double price, string name) {
	double change = money - price; 
	if (money > price) {
		cout << "Plonk Plonk Plonk\nYou bought a " << name << "\nYour change is: " << change << endl;
	}
	else {
		cout << "you dont have enough money\nHere is your money: " << money << endl;
	}
	return 0;
}

int main() {
	int Choice,ChoiceSnack,ChoiceDrink; 
	double money; 
	cout << "Welcome to Dalmau vendning machine\nPlease make a selection" << endl; 
	cout << "1) Snacks" << endl;
	cout << "2) Drinks" << endl;
	cout << "3) Exit machine" << endl;
	cin >> Choice; 

	if (Choice == 1) { 

        string snackList[] = {"Snicker Bar", "Cliff Bar", "PopTarts", "SunChips", "Pretzel"};
        double snackPrice[] = {0.6, 0.9, 0.25, 1.2, 3.0};

		cout << "Snacks:" << endl;
        cout << "1) Snickers Bar - 0.6" << endl;
        cout << "2) Cliff Bars - 0.9" << endl;
        cout << "3) Pop-Tarts - 0.25" << endl;
        cout << "4) Sun Chips - 1.2" << endl;
        cout << "5) Pretzel - 3.0" << endl; 

        cin >> ChoiceSnack;

        cout << "You slected " << snackList[ChoiceSnack-1] << "\nInsert money: " << endl;
        cin >> money;

        differences(money,snackPrice[ChoiceSnack-1], snackList[ChoiceSnack-1]);
	}

	else if (Choice == 2) {
        string drinkList[] = {"Water", "Energy drink", "Vitamin Water", "Pepsi", "Fanta"};
        double drinkPrice[] = {1.0, 1.25, 1.50, 0.9, 0.9};

		cout << "Drinks:" << endl;
        cout << "1) Water . 1.0" << endl;
        cout << "2) Energy drink - 1.25" << endl;
        cout << "3) Vitamin water - 1.50" << endl;
        cout << "4) Pepsi - 0.9" << endl;
        cout << "5) Fanta - 0.9" << endl; 

		cin >> ChoiceDrink;

        cout << "You slected " << drinkList[ChoiceDrink-1] << "\nInsert money: " << endl;
        cin >> money;

        differences(money,drinkPrice[ChoiceDrink-1], drinkList[ChoiceDrink-1]);
	}

	else if (Choice == 3) {
		cout << "Thanks for buying" << endl;
	}

	else { 
		cout << "Invalid Input" << endl;
	}

	return 0;
}