#include <iostream>
#include<fstream>
#include <string>
using namespace std;

struct order {
	char customer_ID;
	string food_Item[50];
	string pizza_extras[56];
	int food_item_quantity[50];
	float item_Price[50];
}orders[10];

struct Adress {
	string zone;
	int buildingN;
	string street_name;
	int floorN;
	int appartmentN;
};
struct Customer {
	char ID[11], phone[11];
	string name;
	string email;
	Adress adress;
	string password;
	order order1;
}customer;
struct pizza
{
	string name[2][8] = { {"MARGARITA","NAPOLITANA","CAPRICCIOSA","MUSHROOM","ROMANA","PEPPERONI","VEGETERIANA","FRUTTI DI MARE"},{ "SMALL","MEDIUM","LARGE" } };
	int price[2][24] = { { 1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8 },{ 65,75,85,55,60,65,70,75,80,60,75,90,70,75,80,70,75,80,40,55,70,70,75,80 } };
};
struct extra
{
	string name[6] = { "CHEESE","MUSHROM","SALAD","TOMATO SAUCE","OLIVES","VEGETABLES" };
	int ID[6] = { 1,2,3,4,5,6 };
	float price[6] = { 10,15,10,5,5,10 };
};
struct drink
{
	string name[5] = { "WATER","PEPSI","FANTA","TEA","COFFEE" };
	int ID[5] = { 1,2,3,4,5 };
	float price[5] = { 10,15,15,20,30 };
};
struct dessert
{
	string name[5] = { "TIRAMISU","CANNOLI","TARTUFO","CROSTATA","ZEPPOLE" };
	int ID[5] = { 1,2,3,4,5 };
	float price[5] = { 25,30,40,25,35 };
};
pizza p[50];
extra e[50];
drink d[50];
dessert des[50];

float Total = 0.0;
int  order_counter = 0, food_counter = 0;

bool CreateAccount() {
	ofstream account;
	cout << "Enter Full Name: ";
	cin.ignore(); // the user entered c/C then enter
	getline(cin, customer.name);
	cout << "Enter your number: ";
	cin >> customer.phone;
	cout << "Enter your ID: ";
	cin >> customer.ID;
	cout << "Enter email: ";
	cin >> customer.email;
	account.open("data" + customer.email + ".txt");
	account << customer.email << endl;
	cin.ignore();
	cout << "Enter a password: ";
	cin >> customer.password;
	account << customer.password << endl;
	account << customer.name << endl;
	account << customer.phone << endl;
	account << customer.ID << endl;
	cout << "Created Account Successfuly\n";
	cout << "Now enter your zone of delivery: ";
	cin.ignore();
	getline(cin, customer.adress.zone);
	cout << "Enter your building number: ";
	cin >> customer.adress.buildingN;
	cin.ignore();
	cout << "Enter street name: ";
	getline(cin, customer.adress.street_name);
	cout << "Enter floor number: ";
	cin.ignore();
	cin >> customer.adress.floorN;
	cout << "Enter appartment number: ";
	cin >> customer.adress.appartmentN;
	account << customer.adress.zone << endl;
	account << customer.adress.buildingN << endl;
	account << customer.adress.street_name << endl;
	account << customer.adress.floorN << endl;
	account << customer.adress.appartmentN << endl;
	account.close();
	return true;


}
void ResetPass() {
	fstream acc;
	acc.open("data" + customer.email + ".txt", ios::trunc);
	cout << "Enter new password: ";
	cin >> customer.password;
	acc << customer.email << endl;
	acc << customer.password;
	acc.close();
}
bool LogIn()
{
	string email2, pass1, pass2;
	cout << "Enter email: ";
	cin >> customer.email;
	ifstream account;
	account.open("data" + customer.email + ".txt");
	account >> email2;
	if (customer.email == email2) {
		cout << "Enter password: ";
		cin >> pass1;
		account >> pass2;
		if (pass1 == pass2) {
			cout << "Logged In successfully\n";
			return true;
		}

		else {
			cout << "Incorrect password\n";
			cout << "Press F if you forgot your password, T to try again: ";
			char c;
			cin >> c;
			switch (c) {
			case 'F':
			case 'f':
				ResetPass();
				break;
			case 'T':
			case 't':
				cout << "Enter password: ";
				cin >> pass1;
				if (pass1 == pass2) {
					cout << "Logged In successfully\n";
					return true;
				}
				else {
					cout << "Number of trials passed. Please try again later\n";
					system("pause");
					return false;
				}
				break;
			default:
				cout << "Invalid Input\n";
				return false;
			}

		}

	}
	else {
		cout << "Email not registered\n";
		char ch;
		cout << "Press C to create account, T to try again: ";
		cin >> ch;
		switch (ch) {
		case 'C':
		case 'c':
			CreateAccount();
			break;
		case 't':
		case 'T':
			return false;
			break;
		default:
			cout << "Invalid Input";
			return false;
		}

	}
	account.close();
}

void searchFor(string searchWord) {
	ifstream cin("food menu.txt");
	string line;
	string category = "";
	bool found = false;
	for (int i = 0; i < searchWord.size(); i++)
		searchWord[i] = toupper(searchWord[i]);
	while (true) {
		getline(cin, line);
		if (line == "")
			break;
		string cat = ":";
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == cat[0])
				category = line;
			int originali = i, j = 0;
			for (; j < searchWord.size(); j++) {
				if (line[i] != searchWord[j])
					break;
				else
					i++;
			}
			if (j == searchWord.size()) {
				found = true;
				cout << category;
				cout << line << endl;
				break;
			}
			else i = originali;

		}

	}
	if (!found)
		cout << "Not found..";
}

void display_menu()
{
	cout << "\n\t\t\t                ------------------------------------- \n";
	cout << "\t\t\t                              PIZZA MENU \n";
	cout << "\t\t\t                  ------------------------------------- \n\n\n";
	cout << "\t ***********************************\n\n";
	cout << "     pizza \t\t small \t\t medium \t large \n\n";
	cout << " 1. MARGARITA  \t\t 65 L.E  \t 75 L.E  \t 85 L.E \n ";
	cout << "2. NAPOLITANA  \t 55 L.E  \t 60 L.E  \t 65 L.E \n ";
	cout << "3. CAPRICCIOSA \t 70 L.E  \t 75 L.E  \t 80 L.E \n ";
	cout << "4. MUSHROOM \t\t 60 L.E  \t 75 L.E  \t 90 L.E \n ";
	cout << "5. ROMANA \t\t 70 L.E  \t 75 L.E  \t 80 L.E \n ";
	cout << "6. PEPPERONI \t\t 70 L.E  \t 75 L.E  \t 80 L.E \n ";
	cout << "7. VEGETERIANA \t 40 L.E  \t 55 L.E  \t 70 L.E \n ";
	cout << "8. FRUTTI DI MARE \t 70 L.E  \t 75 L.E  \t 80 L.E \n\n\n";
	cout << "\t ***********************************\n\n\n";

	cout << "\t\t\t                  ------------------------------------- \n";
	cout << "\t\t\t                           EXTRA TOPPING MENU \n";
	cout << "\t\t\t                  ------------------------------------- \n\n\n";
	cout << "\t ***********************************\n\n";
	cout << "   extra \t \t  price \n\n";
	cout << " 1. CHEESE \t\t 10 L.E\n";
	cout << " 2. MUSHROOM \t\t 15 L.E\n";
	cout << " 3. SALAD \t\t 10 L.E\n";
	cout << " 4. TOMATO SAUCE \t 5 L.E\n";
	cout << " 5. OLIVES \t\t 5 L.E\n";
	cout << " 6. VEGETABLE \t\t 10 L.E\n\n\n";
	cout << "\t ***********************************\n\n\n";
	system("pause");
	cout << "\t\t\t                  ------------------------------------- \n";
	cout << "\t\t\t                              DESSERT MENU \n";
	cout << "\t\t\t                  ------------------------------------- \n\n\n";
	cout << "  Dessert \t Price \n\n";
	cout << " 1.TIRAMISU \t 25 L.E\n";
	cout << " 2.CANNOLI \t 30 L.E\n";
	cout << " 3.TARTUFO \t 40 L.E\n";
	cout << " 4.CROSTATA \t 25 L.E\n";
	cout << " 5.ZEPPOLE \t 35 L.E\n\n\n";
	cout << "\t ***********************************\n\n\n";
	system("pause");
	cout << "\t\t\t                  ------------------------------------- \n";
	cout << "\t\t\t                              DRINKS MENU \n";
	cout << "\t\t\t                  ------------------------------------- \n\n\n";
	cout << "  Drinks \t Price\n\n";
	cout << " 1. WATER \t 10 L.E\n";
	cout << " 2. PEPSI \t 15 L.E\n";
	cout << " 3. FANTA \t 15 L.E\n";
	cout << " 4. TEA \t 20 L.E\n";
	cout << " 5. COFFEE \t 30 L.E\n\n\n";
	cout << "\t ***********************************\n\n\n";
	cout << "Order above 200 and GET 5% OFF!\nOrder above 600 and GET 10% OFF!\nOrder above 900 and GET 15% OFF!\n\n\n";
}

int myorder()
{
	int pizza_choice, dessert_choice, drink_choice, extra_choice, size, l;
	char ans = 'y';
	char category;
	float totalprice = 0;
	cout << "\nOrder above 200 and GET 5% OFF!\nOrder above 600 and GET 10% OFF!\nOrder above 900 and GET 15% OFF!";
	cout << "\n\t\t\t\t\t\tPlease enter your order \n";

	do
	{
		int i = 0;
		cout << "\t\t\t\t***********************************************";
		cout << "\n\t\t\t\t\t\tEnter the number of the category:\n\t\t\t\t\t\t1.Pizza\n\t\t\t\t\t\t2.Desserts\n\t\t\t\t\t\t3.Drinks\n";
		cout << "\t\t\t\t*********************************************\n";
		cout << "Enter the category (press 0 to exit): ";
		cin >> category;
		if (category == '0')
			break;
		switch (category)
		{
		case '1':
			cout << "\t\t\t                  ------------------------------------- \n";
			cout << "\t\t\t                              PIZZA MENU \n";
			cout << "\t\t\t                  ------------------------------------- \n\n\n";
			cout << "\t ***********************************\n\n";
			cout << "     pizza \t\t small \t\t medium \t large \n\n";
			cout << " 1. MARGARITA  \t\t 65 L.E  \t 75 L.E  \t 85 L.E \n ";
			cout << "2. NAPOLITANA  \t 55 L.E  \t 60 L.E  \t 65 L.E \n ";
			cout << "3. CAPRICCIOSA \t 70 L.E  \t 75 L.E  \t 80 L.E \n ";
			cout << "4. MUSHROOM \t\t 60 L.E  \t 75 L.E  \t 90 L.E \n ";
			cout << "5. ROMANA \t\t 70 L.E  \t 75 L.E  \t 80 L.E \n ";
			cout << "6. PEPPERONI \t\t 70 L.E  \t 75 L.E  \t 80 L.E \n ";
			cout << "7. VEGETERIANA \t 40 L.E  \t 55 L.E  \t 70 L.E \n ";
			cout << "8. FRUTTI DI MARE \t 70 L.E  \t 75 L.E  \t 80 L.E \n\n\n";
			cout << "\t ***********************************\n\n";
			cout << "   extra \t \t  price \n\n";
			cout << " 1. CHEESE \t\t 10 L.E\n";
			cout << " 2. MUSHROOM \t\t 15 L.E\n";
			cout << " 3. SALAD \t\t 10 L.E\n";
			cout << " 4. TOMATO SAUCE \t 5 L.E\n";
			cout << " 5. OLIVES \t\t 5 L.E\n";
			cout << " 6. VEGETABLE \t\t 10 L.E\n\n\n";
			cout << "Press 0 if you don't want any extra\n";
			cout << "\t ***********************************\n\n";
			cout << "\nPress 0 to end\n";
			while (true)
			{
				cout << "\nPizza number: ";
				cin >> pizza_choice;

				if (pizza_choice == 0)
					break;
				else if (pizza_choice > 8 || pizza_choice < 1)
				{
					cout << "Invalid choice! Please try again.\n";
					continue;
				}
				cout << "Pizza size(1 --> 3): ";
				cin >> size;
				if (size > 3 || size < 1)
				{
					cout << "Invalid choice! Please try again.\n";
					continue;
				}

				cout << "Extra number: ";
				cin >> extra_choice;
				if (extra_choice > 6 || extra_choice < 0)
				{
					cout << "Invalid choice! Please try again.\n";
					continue;
				}

				cout << "Quantity: ";
				cin >> orders[order_counter].food_item_quantity[food_counter];



				if (extra_choice == 0)
				{
					orders[order_counter].food_Item[food_counter] = p[i].name[0][pizza_choice - 1] + " " + p[i].name[1][size - 1];
					cout << orders[order_counter].food_item_quantity[food_counter] << "x " << p[i].name[0][pizza_choice - 1] << " " << p[i].name[1][size - 1] << endl;
				}
				else
				{
					orders[order_counter].food_Item[food_counter] = p[i].name[0][pizza_choice - 1] + " " + p[i].name[1][size - 1] + " with extra " + e[i].name[extra_choice - 1];
					cout << orders[order_counter].food_item_quantity[food_counter] << "x " << p[i].name[0][pizza_choice - 1] << " " << p[i].name[1][size - 1] << " with extra " << e[i].name[extra_choice - 1] << endl;
				}

				for (int j = 0; j < 24; j++)
				{
					if (pizza_choice == p[i].price[0][j])
					{
						l = (p[i].price[1][j + (size - 1)] + e[i].price[extra_choice - 1]) * orders[order_counter].food_item_quantity[food_counter];
						break;
					}
				}
				orders[order_counter].item_Price[food_counter] = l;
				cout << "--Price:" << l << " L.E" << endl;
				totalprice += l;

				i++;
				food_counter++;
			}
			break;

		case '2':
			cout << "\t ***********************************\n\n\n";
			cout << "  Dessert \t Price \n\n";
			cout << " 1.TIRAMISU \t 25 L.E\n";
			cout << " 2.CANNOLI \t 30 L.E\n";
			cout << " 3.TARTUFO \t 40 L.E\n";
			cout << " 4.CROSTATA \t 25 L.E\n";
			cout << " 5.ZEPPOLE \t 35 L.E\n\n\n";
			cout << "\t ***********************************\n\n";
			cout << "\nPress 0 to end\n";
			while (true)
			{

				cout << "\nDessert number: ";
				cin >> dessert_choice;

				if (dessert_choice == 0)
					break;
				else if (dessert_choice > 5 || dessert_choice < 1)
				{
					cout << "Invalid choice! Please try again.\n";
					continue;
				}

				cout << "Quantity: ";
				cin >> orders[order_counter].food_item_quantity[food_counter];

				cout << orders[order_counter].food_item_quantity[food_counter] << "x " << des[i].name[dessert_choice - 1];
				cout << "\n--Price: " << des[i].price[dessert_choice - 1] * orders[order_counter].food_item_quantity[food_counter] << " L.E";
				totalprice += des[i].price[dessert_choice - 1] * orders[order_counter].food_item_quantity[food_counter];

				orders[order_counter].food_Item[food_counter] = des[i].name[dessert_choice - 1];
				orders[order_counter].item_Price[food_counter] = des[i].price[dessert_choice - 1] * orders[order_counter].food_item_quantity[food_counter];
				i++;
				food_counter++;
			}
			break;

		case '3':
			cout << "\t ***********************************\n\n\n";
			cout << "  Drinks \t Price\n\n";
			cout << " 1. WATER \t 10 L.E\n";
			cout << " 2. PEPSI \t 15 L.E\n";
			cout << " 3. FANTA \t 15 L.E\n";
			cout << " 4. TEA \t 20 L.E\n";
			cout << " 5. COFFEE \t 30 L.E\n\n\n";
			cout << "\t ***********************************\n\n";
			cout << "\nPress 0 to end\n";
			while (true)
			{

				cout << "\nDrink number: ";
				cin >> drink_choice;


				if (drink_choice == 0)
					break;
				else if (drink_choice > 5 || drink_choice < 1)
				{
					cout << "Invalid choice! Please try again.\n";
					continue;
				}

				cout << "Quantity: ";
				cin >> orders[order_counter].food_item_quantity[food_counter];

				cout << orders[order_counter].food_item_quantity[food_counter] << "x " << d[i].name[drink_choice - 1];
				cout << "\n--Price: " << d[i].price[drink_choice - 1] * orders[order_counter].food_item_quantity[food_counter] << " L.E";
				totalprice += d[i].price[drink_choice - 1] * orders[order_counter].food_item_quantity[food_counter];

				orders[order_counter].food_Item[food_counter] = d[i].name[drink_choice - 1];
				orders[order_counter].item_Price[food_counter] = d[i].price[drink_choice - 1] * orders[order_counter].food_item_quantity[food_counter];
				i++;
				food_counter++;
			}
			break;
		default:cout << "Invalid choice! Try again.";
			continue;
		}


		cout << "\nDo you want to add something to your order ?(y/n) : ";
		cin >> ans;
		cout << endl;
	} while (ans == 'y' || ans == 'Y');
	return totalprice;
}

float cart(float Total)
{
	int num, deleted_quantity, Choice;
	char ans, choice, answer;
	bool found = false;
	do
	{

		cout << "\n\t\t\t\t\t\t\tYour CART: \n";
		cout << "\t\t\t\t\t---------------------------------------\n";
		if (Total == 0)
		{
			cout << "\t\t\t\t\tThe Cart Is Empty!\n";
			cout << "\t\t\t\t\t---------------------------------------\n";
		}
		else
		{
			for (int i = 0; i < food_counter; i++)
			{
				if (orders[order_counter].food_item_quantity[i] != 0)
				{
					cout << "\t\t\t\t\t";
					cout << i + 1 << ") " << orders[order_counter].food_item_quantity[i] << "x " << orders[order_counter].food_Item[i];
					cout << "\t--Price: " << orders[order_counter].item_Price[i] << " L.E" << endl;
				}
				else
					continue;
			}
			cout << "\n\t\t\t\t\tThe Total price is: " << Total << " L.E" << endl;
			cout << "\t\t\t\t-----------------------------------------------------";
		}

		cout << "\npress (a) to ADD or (d) to DELETE from the cart (e to exit): ";
		cin >> choice;
		if (choice == 'e' || choice == 'E')
			break;
		switch (choice)
		{
		case 'a':
		{

			Total += myorder();
			cout << "The new Total price is: " << Total << " L.E" << endl;
			cout << "-------------------------------------------\n";

			break;
		}
		case 'd':
		{
			cout << "\n\t\t\t\t\t\t\tYour CART: \n";
			cout << "\t\t\t\t\t---------------------------------------\n";
			for (int i = 0; i < food_counter; i++)
			{
				if (orders[order_counter].food_item_quantity[i] != 0)
				{
					cout << "\t\t\t\t\t";
					cout << i + 1 << ") " << orders[order_counter].food_item_quantity[i] << "x " << orders[order_counter].food_Item[i];
					cout << "\t--Price: " << orders[order_counter].item_Price[i] << " L.E" << endl;
				}
				else
					continue;
			}
			cout << "\n\t\t\t\t\tThe Total price is: " << Total << " L.E" << endl;
			cout << "\t\t\t\t-----------------------------------------------------";


			do
			{

				cout << "\nEnter the number of the order you want to remove: ";
				cin >> num;

				for (int i = 0; i < food_counter; i++)
				{
					if (num == (i + 1))
					{
						if (orders[order_counter].food_item_quantity[i] != 1)
						{
							cout << "\nenter the quantity you want to remove: ";
							cin >> deleted_quantity;
							Total -= (orders[order_counter].item_Price[i] / orders[order_counter].food_item_quantity[i]) * deleted_quantity;
							orders[order_counter].item_Price[i] -= (orders[order_counter].item_Price[i] / orders[order_counter].food_item_quantity[i]) * deleted_quantity;
							orders[order_counter].food_item_quantity[i] -= deleted_quantity;
							cout << endl << deleted_quantity << "x " << orders[order_counter].food_Item[i] << "\t Deleted\n";
							cout << "\nTHE new total price is: " << Total << " L.E" << endl;
							cout << "-------------------------------------------\n";
						}
						else
						{
							cout << endl << orders[order_counter].food_item_quantity[i] << "x " << orders[order_counter].food_Item[i] << "\t Deleted\n";
							Total -= orders[order_counter].item_Price[i];
							--orders[order_counter].food_item_quantity[i];
							cout << "\nTHE new total price is: " << Total << " L.E" << endl;
							cout << "-------------------------------------------\n";
						}
						found = true;
					}

				}
				if (found == false)
				{
					cout << "\nWrong number! please try again\n";
					cout << "\nDO you want to delete anything else? (y/n): ";
					cin >> answer;
					continue;
				}
				cout << "\nDO you want to delete anything else? (y/n): ";
				cin >> answer;
			} while (answer == 'y' || answer == 'Y');

			break;
		}

		default:cout << "\nInvalid Choice! please try again\n";
			cout << "\nDo You Want To Exit The Cart?(y/n)";
			cin >> ans;
			continue;
		}
		cout << "\nDo You Want To Exit The Cart?(y/n)";
		cin >> ans;
	} while (ans == 'n' || ans == 'N');

	return Total;
}

void Checkout(float total)
{
	const int Delivery = 30;
	float payment;
	fstream orderhistory;
	orderhistory.open("orderhistory" + customer.email + ".txt", ios::app);
	cout << "\n\t\t\t\t\t\t\tYour Order Summary \n";
	cout << "\t\t\t\t\t-----------------------------------------\n";
	orderhistory << "****************************\n";
	for (int i = 0; i < food_counter; i++)
	{
		if (orders[order_counter].food_item_quantity[i] != 0)
		{
			cout << "\t\t\t\t\t";
			cout << i + 1 << ") " << orders[order_counter].food_item_quantity[i] << "x " << orders[order_counter].food_Item[i];
			cout << "\n\t\t\t\t\t--Price: " << orders[order_counter].item_Price[i] << " L.E" << endl;
			orderhistory << i + 1 << ") " << orders[order_counter].food_item_quantity[i] << "x " << orders[order_counter].food_Item[i] << "\n--Price: " << orders[order_counter].item_Price[i] << " L.E" << endl;
		}
		else
			continue;
	}

	cout << "\t\t\t\t\tSubtotal = " << total << " L.E" << endl;
	orderhistory << "Subtotal = " << total << " L.E" << endl;
	if (total > 200 && total < 600) {
		cout << "\nCongratulations! You've received 5% off for your order.";
		cout << "\n\t\t\t\t\tDiscount = " << total * 0.05 << " L.E" << endl;
		orderhistory << "Discount " << total * 0.05 << " L.E" << endl;
		total = total - total * 0.05;
	}
	else if (total > 600 && total < 900) {
		cout << "\nCongratulations! You've received 10% off for your order.";
		cout << "\n\t\t\t\t\tDiscount = " << total * 0.1 << " L.E" << endl;
		orderhistory << "Discount " << total * 0.1 << " L.E" << endl;
		total = total - total * 0.1;

	}
	else if (total > 900 && total < 1500) {
		cout << "\nCongratulations! You've received 15% off for your order.\n";
		cout << "\n\t\t\t\t\tDiscount = " << total * 0.15 << " L.E" << endl;
		orderhistory << "Discount " << total * 0.15 << " L.E" << endl;
		total = total - total * 0.15;

	}
	cout << "\t\t\t\t\tDelivery Cost= " << Delivery << " L.E";
	orderhistory << "Delivery = " << Delivery << " L.E" << endl;
	cout << "\n\t\t\t\t\tTotal= " << total + Delivery << " L.E";
	orderhistory << "Total Amount of Price = " << total + Delivery << " L.E" << endl;
	cout << "\n\t\t\t\t\tYour order will be delivered in 40 minutes.\n\n\n" << endl;
	orderhistory.close();

}

void OrderHistory() {
	ifstream orderhistory("orderhistory" + customer.email + ".txt");
	string s;
	while (getline(orderhistory, s)) {
		cout << s << endl;
		if (s.empty())
			cout << "No previous orders.\n";
	}
	orderhistory.close();
}

void main() {
	char choice;
	char ch;
	bool isLoggedIn;

	// welcome msg
	cout << "\t\t\t           --------------------------------------------- \n";
	cout << "\t\t\t                     WELCOME TO PIZZA HOUSE  \n";
	cout << "\t\t\t           ---------------------------------------------- \n\n\n";

	// Create Acc OR log in
	while (true)
	{
		cout << "Press C to create account, L to log in\n";
		cin >> ch;
		switch (ch)
		{
		case 'C':
		case 'c':
			isLoggedIn = CreateAccount();
			break;
		case 'L':
		case 'l':
			isLoggedIn = LogIn();
			break;
		default:
			cout << "Invalid Input\n";
			continue;
		}

		if (isLoggedIn)
			break;
	}

	char n, ans;
	int ans1;

	//outer menu
	ifstream acc("data" + customer.email + ".txt");
	string s;
	for (int i = 1; i <= 3; i++) // customer name is stored in third line in file
		getline(acc, s);
	customer.name = s;
	cout << "\n\n\t\t\t\t Welcome " << customer.name << ",how can I help you ? " << endl;

	do {
		cout << "\t\t\t\t*********************************************";
		cout << "\n\t\t\t\t\t\tPress 1 to view menu \n\t\t\t\t\t\tPress 2 to search the menu\n\t\t\t\t\t\tPress 3 to make an order \n\t\t\t\t\t\tPress 4 to edit cart \n\t\t\t\t\t\tPress 5 to view previous orders\n\t\t\t\t\t\tPress 6 to Exit the Program" << endl;
		cout << "\t\t\t\t*********************************************\n";
		cin >> n;
		if (n == '6')
			break;

		string searchWord;
		switch (n) {
		case '1':
			display_menu();
			break;
		case '2':
			char answer;
			do {
				cout << "What do you want to search for? ";
				cin >> searchWord;
				searchFor(searchWord);
				cout << "Another search? (Y/N)" << endl;
				cin >> answer;
			} while (answer == 'Y' || answer == 'y');
			break;
		case '3':
		{
			order_counter++;
			food_counter = 0;
			Total = myorder();
			int a;
			if (Total != 0)
			{
				cout << "Press 1 to proceed to checkout or 2 to edit your cart: ";
				cin >> a;
				switch (a) {
				case 1:
					Checkout(Total);
					Total = 0;
					break;

				case 2:
					Total = cart(Total);
					cout << "\nPress 1 to proceed to checkout or 2 to return to the main menu : ";
					cin >> ans1;
					switch (ans1)
					{
					case 1:
						Checkout(Total);
						Total = 0;
						break;

					case 2:
						continue;
					}

					break;
				}
			}
			break;
		}
		case '4':
			if (Total == 0)
			{
				cout << "\t\t\t\t\t---------------------------------------\n";
				cout << "\t\t\t\t\tThe Cart Is Empty!\n";
				cout << "\t\t\t\t\t---------------------------------------\n";
				break;
			}
			Total = cart(Total);

			cout << "\nPress 1 to proceed to checkout or 2 to return to the main menu : ";
			cin >> ans1;
			switch (ans1)
			{
			case 1:
				Checkout(Total);
				Total = 0;
				break;
			}
			if (ans1 == 2)
				continue;

			break;

		case '5':
			OrderHistory();
			break;

		default:
			cout << "wrong number \n";
			continue;
		}
		cout << "\n\n";
		cout << "\nReturn to the main menu?(Y/N): ";
		cin >> ans;
	} while (ans == 'y' || ans == 'Y');
	cout << "\t\t\t           --------------------------------------------- \n\n";
	cout << "\t\t\t                   THANKS FOR CHOOSING PIZZA HOUSE!\n";
	cout << "\t\t\t           ---------------------------------------------- \n\n\n";
}