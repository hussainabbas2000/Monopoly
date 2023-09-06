#include<iostream>
using namespace std;
#include <cstring>
#include<time.h>
#include<Windows.h>

class box {
	int position;//position of box from 1 to 40
	char* name; //full name of box;
	char symbol;
public:
	box() {
		position = 0;
		name = nullptr;
		symbol = '\0';
	}
	box(const char* iname, int ipos, char s) {
		name = new char[strlen(iname) + 1];
		for (int i = 0; i < strlen(iname); i++) {
			name[i] = iname[i];
		}
		position = ipos;
		symbol = s;
	}
	box(const box& obj) {
		name = new char[strlen(obj.name) + 1];
		for (int i = 0; i < strlen(obj.name); i++) {
			name[i] = obj.name[i];
		}
		position = obj.position;
		symbol = obj.symbol;
	}
	char getSymbol() {
		return symbol;
	}
	void SetSymbol(char x) {
		symbol = x;
	}
	void initialiseSymbol() {
		symbol = '\0';
	}
	int getPosition() {
		return position;
	}
	char* getName() {
		return name;
	}
};
class property : public box {
	char* propertyname; //name of property
	float price;//price of the property
	float rent;//rent that is to be taken for that property
	char playersymbol;//will be used to connect players class to property
	bool mortaged; //check if its mortage
public:
	/*default*/
	property() {
		propertyname = nullptr;
		price = 0.0;
		rent = 0.0;
		playersymbol = '\0';
		mortaged = false;
	}
	/* parametrized*/
	property(const char* ipname, const char* iname, int iposition, float iprice, float irent, char iplayersymbol) : box(iname, iposition, iplayersymbol) {
		price = iprice;
		rent = irent;
		playersymbol = iplayersymbol;
		propertyname = new char[strlen(ipname) + 1];
		for (int i = 0; i < strlen(ipname); i++) {
			propertyname[i] = ipname[i];
		}
		propertyname[strlen(ipname)] = '\0';
	}
	/* copy*/
	property(const property& obj) {
		price = obj.price;
		rent = obj.rent;
		playersymbol = obj.playersymbol;
		propertyname = new char[strlen(obj.propertyname) + 1];
		for (int i = 0; i < strlen(obj.propertyname); i++) {
			propertyname[i] = obj.propertyname[i];
		}
		propertyname[strlen(obj.propertyname)] = '\0';
	}
	~property() {
		delete[]propertyname;
		propertyname = nullptr;
	}
	/*if property is to be made property*/
	void makemortage() {
		mortaged = true;
	}
	/* if player is to be assigned to a property*/
	void assignsymbol(char isymbol) {
		playersymbol = isymbol;
	}
	void initialiseSymbol() {
		playersymbol = '\0';
	}
	void printpropertyinfo() {
		cout << "Property name : " << propertyname << endl;
		cout << "Property price : " << price << endl;
		cout << "Property rent : " << rent << endl;
		cout << "Property owned by : " << playersymbol << endl;
		cout << "Property status : " << endl;
		if (mortaged == 0) {
			cout << "Not mortaged" << endl;
		}
		else {
			cout << "Mortaged" << endl;
		}
	}
	char* getpropertyname() {
		return propertyname;
	}
	float getprice() {
		return price;
	}
	float getrent() {
		return rent;
	}
	char getplayersymbol() {
		return playersymbol;
	}
	bool getmortaged() {
		return mortaged;
	}
};
class player
{
	char symbol;//symbol of the player
	char* name;//name of the player
	int position;//position on the board relative to 40
	float funds;//how many funds in total does the player have
	/*array of properties
	number of properties*/
	bool gameover;
	int propertyowned;
	int hotelowned;
	bool getoutofJail;
public:
	/* default constructor*/
	player() {
		symbol = '\0';
		name = nullptr;
		position = 0;
		funds = 0.0;
		gameover = false;
		propertyowned = 0;
		getoutofJail = 0;
		hotelowned = 0;
	}
	/* parametrized constructor*/
	player(char isymbol, const char* iname, int iposition, float ifunds, int ipropertyowned, bool x, int h) {
		symbol = isymbol;
		name = new char[strlen(iname) + 1];
		for (int i = 0; i < strlen(iname); i++) {
			name[i] = iname[i];
		}
		name[strlen(iname)] = '\0';
		position = iposition;
		funds = ifunds;
		propertyowned = ipropertyowned;
		getoutofJail = x;
		hotelowned = h;
	}
	/* copy constructor*/
	player(player& obj) {
		symbol = obj.symbol;
		name = new char[strlen(obj.name) + 1];
		for (int i = 0; i < strlen(obj.name); i++) {
			name[i] = obj.name[i];
		}
		hotelowned = obj.hotelowned;
		name[strlen(obj.name)] = '\0';
		position = obj.position;
		funds = obj.funds;
		propertyowned = obj.propertyowned;
		getoutofJail = obj.getoutofJail;
	}
	/* used to output*/
	friend ostream& operator <<(ostream& out, player& obj) {
		out << "Player your info as follows " << endl;
		out << "Your name is " << obj.name << endl;
		out << "Your symbol is " << obj.symbol << endl;
		out << "Your position on the board currently is " << obj.position << endl;
		out << "Your amount of funds right now are " << obj.funds << endl;
		out << "Your total no.of properties:" << obj.propertyowned << endl;
		return out;
	}
	int gethotelOwned() {
		return hotelowned;
	}
	void incrementHotelOwned() {
		hotelowned++;
	}
	void decrementHotelOwned() {
		hotelowned--;
	}
	void setGetoutOfJail(bool x) {
		getoutofJail = x;
	}
	bool returnGetoutofJail() {
		return getoutofJail;
	}
	void incrementpropertyowned() {
		propertyowned++;
	}
	void decrementPropertyOwned() {
		propertyowned--;
	}
	int getpropertyOwned() {
		return propertyowned;
	}
	void setSymbol(char x) {
		symbol = x;
	}
	char getSymbol() {
		return symbol;
	}
	/* if funds are to be added from the main*/
	void addfund(float add) {
		funds = funds + add;
	}
	/*if funds are to be subtracted from the main*/
	void subtractfund(float subtract) {
		funds = funds - subtract;
	}
	/* To Set Position On board after Roll of a Dice*/
	void setposition(int a)
	{
		position = position + a;
		if (position >= 40)
		{
			position = position % 10;
		}
	}
	/*To Set Postion at specific index*/
	void specific(int b)
	{

		position = 0;
		position = b;
	}
	int getposition()
	{
		return position;
	}
	void setcash(float x) {
		this->funds = x;
	}
	float getcash() {
		return funds;
	}
	/* destructor*/
	~player() {
		cout << "~Player was called" << endl;
		delete[]name;
		name = nullptr;
	}
};
class community : public box
{
public:
	community(const char* iname, int iposition) :box(iname, iposition, '\0') {
	}

};
void drawnchest(player& obj, int c)
{
	if (c == 1)
	{
		cout << "Advance to Go and Collect 500 PK " << endl;

		obj.specific(0);
		obj.addfund(400);
	}
	if (c == 2)
	{
		cout << "Bank will pay you 200 PKR " << endl;
		obj.addfund(200);
	}
	if (c == 3)
	{
		cout << "Pay Doctor Fee 200 PKR ";
		obj.subtractfund(200);
	}
	if (c == 4)
	{
		cout << "From Sale you got 50 PKR " << endl;
		obj.addfund(50);
	}
	if (c == 5)
	{
		cout << "Income Tax refund collect 150 PKR " << endl;
		obj.addfund(150);
	}
	if (c == 6)
	{
		cout << "Your health insurance matures collect 200 PKR " << endl;
		obj.addfund(200);
	}
	if (c == 7)
	{
		cout << "Pay donation to Hospital 100 PKR " << endl;
		obj.subtractfund(100);
	}
	if (c == 8)
	{
		cout << "Pay Student tax of 200 PKR " << endl;
		obj.subtractfund(200);
	}
	if (c == 9)
	{
		cout << "Collect 50 PKR for your services " << endl;
		obj.addfund(50);
	}
	if (c == 10)
	{
		cout << "You won prize money of 300 PKR " << endl;
		obj.addfund(300);
	}
	if (c == 11)
	{
		cout << "Pay water bill of 50 PKR " << endl;
		obj.subtractfund(50);
	}
	if (c == 12)
	{
		cout << "Pay electricity bill of 80 PKR " << endl;
		obj.subtractfund(80);
	}
	if (c == 13)
	{
		cout << "Pay internet bill 50 PKR " << endl;
		obj.subtractfund(50);
	}
}
class chance : public box
{
public:
	chance(const char* iname, int iposition) :box(iname, iposition, '\0') {
	};
};
int drawnchance(player& abj, int d, int& pos)    // d for random no to select a card//  a  means total no of players, b means current player index on array
{
	int select = 0;
	if (d == 1)
	{
		cout << "Advance to Go and Collect 500 PKR " << endl;
		abj.setposition(0);
		abj.addfund(500);
		select = 1;
	}
	if (d == 2)
	{
		cout << "Advance to DHA A " << endl;
		abj.setposition(26);
		select = 2;
	}
	if (d == 3)
	{
		select = 3;
		cout << "Advance token to nearest utility.If owned by someone, pay to owner 5X the amount shown on dice or buy it" << endl;
		int nearestutility = abj.getposition();
		for (int i = 0; i >= 0; i++) {
			if (nearestutility == 12 || nearestutility == 28 || nearestutility == 37 || nearestutility == 39) {
				break;
			}
			nearestutility++;
			if (nearestutility > 40) {
				nearestutility = 0;
			}
		}
		abj.setposition(nearestutility);
		pos = nearestutility;
	}
	if (d == 4)
	{
		select = 4;
		cout << "Advance token to nearest Station.If unowned by from Bank.If owned, pay to owner the double amount" << endl;
		int neareststation = abj.getposition();
		for (int i = 0; i >= 0; i++) {
			if (neareststation == 5 || neareststation == 15 || neareststation == 25 || neareststation == 35) {
				break;
			}
			neareststation++;
			if (neareststation > 40) {
				neareststation = 0;
			}
		}
		abj.setposition(neareststation);
		pos = neareststation;
	}

	if (d == 5)
	{
		select = 5;
		cout << "Advance to Model Town 1. If you pass Go collect 300 PKR " << endl;
		if (abj.getposition() >= 17)
		{
			abj.addfund(300);
			abj.setposition(16);
			pos = 16;
		}
		else
		{
			abj.setposition(16);
			pos = 16;
		}
	}
	if (d == 6)
	{
		select = 6;
		cout << "Bank pay you 100 PKR " << endl;
		abj.addfund(100);
	}
	if (d == 7)
	{
		cout << "Get out of Jail. May be kept until needed or sold for 500 PKR " << endl; //player's attribute getoutofjail(bool)
		select = 7;
	}
	if (d == 8)
	{
		select = 8;
		cout << "Go back 4 blocks " << endl;
		abj.setposition(abj.getposition() - 4);
		if (abj.getposition() < 0)
		{
			abj.setposition(abj.getposition() + 40);
		}
		pos = abj.getposition();
	}
	if (d == 9)
	{
		select = 9;
		cout << "Make repair on your property. For each house pay 50 PKR For each hotel pay 100 PKR " << endl;

	}
	if (d == 10)
	{
		cout << "Pay small Tax of 25 PKR " << endl;
		abj.subtractfund(25);
		select = 10;
	}
	return select;

}

class residential :public property {
	char block;
	int  house;
	int  shops;
	bool hotel;
	float payrent;

	/* Utilities*/
	bool gas;
	bool wifi;
	bool electricity;
public:
	residential() :property()
	{
		block = '\0';
		house = 0;
		shops = 0;
		hotel = 0;
		payrent = 0;
		gas = 0;
		electricity = 0;
		wifi = 0;

	}
	residential(char iblock, int ihouse, int ishops, bool ihotels, int ipayrent, bool igas, bool iwifi, bool ielectricity, const char* pname, const char* iname, int iposition, float price, float rent, char symbol) :property(pname, iname, iposition, price, rent, symbol)
	{

		block = iblock;
		house = ihouse;
		shops = ishops;
		hotel = ihotels;
		payrent = ipayrent;
		gas = igas;
		wifi = iwifi;
		electricity = ielectricity;
	}
	residential(residential& s) :property(s) {
		shops = s.shops;
		gas = s.gas;
		electricity = s.electricity;
		block = s.block;
		house = s.house;
		hotel = s.hotel;
		wifi = s.wifi;
		payrent = s.payrent;
	}
	bool getwifi() {
		return wifi;
	}
	bool getelectricity() {
		return electricity;
	}
	bool getgas() {
		return gas;
	}
	float getpayrent() {
		return payrent;
	}
	char getblock() {
		return block;
	}
	int gethouse() {
		return house;
	}
	int getshops() {
		return shops;
	}
	bool gethotel() {
		return hotel;
	}
	void upgrade(player& x) {
		cout << "Build a property(1) or Add Utility(2) " << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			if (house == 0) {
				/* building first time*/
				house++;
				payrent = payrent + (getrent() / 100) * 30;
				x.setcash(x.getcash() - 100);
			}
			else {
				if (house == 3) {
					shops++;
					payrent = payrent + 2 * payrent;
					x.setcash(x.getcash() - 300);
				}
				if (shops == 2) {
					hotel = 1;
					payrent = payrent + (payrent / 100) * 20;
					x.setcash(x.getcash() - 300);
				}
				if (house < 3) {
					house++;
					payrent = payrent + (payrent / 100) * 30;
					x.setcash(x.getcash() - 100);
				}
			}
		}
		if (select == 2) {
			cout << "Which utility ? " << endl;
			cout << "1. GAS " << endl;
			cout << "2. Electricity " << endl;
			cout << "3. WiFi " << endl;
			int which = 0;
			cin >> which;
			if (which == 1) {
				if (!gas) {
					gas = 1;
					payrent = payrent + (payrent / 100) * 20;
					x.setcash(x.getcash() - 50);
				}
				if (gas) {
					cout << "Already added " << endl;
				}

			}
			if (which == 2) {
				if (!electricity) {
					electricity = 1;
					payrent = payrent + (payrent / 100) * 20;
					x.setcash(x.getcash() - 50);
				}
				if (electricity) {
					cout << "Already added " << endl;
				}
			}
			if (which == 3) {
				if (!wifi) {
					wifi = 1;
					payrent = payrent + (payrent / 100) * 10;
					x.setcash(x.getcash() - 30);
				}
				if (wifi) {
					cout << "Already added " << endl;
				}
			}

		}

	}
};
class taxes : public box
{
	float amount; //amount of tax to be withdrawn
public:
	taxes() {
		amount = 0;
	}
	taxes(float iamount, int iposition, const char* iname) :box(iname, iposition, '\0')
	{
		amount = iamount;
	}
};
class extra : public box
{
	bool startbox;
	bool jailbox;
	bool parkingbox;
	bool setjailbox;
public:
	extra()
	{
		startbox = false;
		jailbox = false;
		parkingbox = false;
		setjailbox = false;
	}
	extra(int iposition, bool istartbox, bool ijailbox, const char* iname, bool iparkingbox, bool isetjailbox) : box(iname, iposition, '\0')
	{
		startbox = istartbox;
		jailbox = ijailbox;
		parkingbox = iparkingbox;
		setjailbox = isetjailbox;
	}
};
//Index checking functions:
int checkproIndex(int x) {
	int y;
	if (x == 5) {
		y = 0;
	}
	else if (x == 12) {
		y = 1;
	}
	else if (x == 15) {
		y = 2;
	}
	else if (x == 25) {
		y = 3;
	}
	else if (x == 28) {
		y = 4;
	}
	else if (x == 35) {
		y = 5;
	}
	else if (x == 37) {
		y = 6;
	}
	else if (x == 39) {
		y = 7;
	}
	return y;
}
int checkResPos(int x) {
	int y;
	if (x == 1) {
		y = 0;
	}
	else if (x == 3) {
		y = 1;
	}
	else if (x == 6) {
		y = 2;
	}
	else if (x == 8) {
		y = 3;
	}
	else if (x == 9) {
		y = 4;
	}
	else if (x == 11) {
		y = 5;
	}
	else if (x == 13) {
		y = 6;
	}
	else if (x == 14) {
		y = 7;
	}
	else if (x == 16) {
		y = 8;
	}
	else if (x == 18) {
		y = 9;
	}
	else if (x == 19) {
		y = 10;
	}
	else if (x == 21) {
		y = 11;
	}
	else if (x == 23) {
		y = 12;
	}
	else if (x == 24) {
		y = 13;
	}
	else if (x == 26) {
		y = 14;
	}
	else if (x == 27) {
		y = 15;
	}
	else if (x == 29) {
		y = 16;
	}
	else if (x == 31) {
		y = 17;
	}
	else if (x == 32) {
		y = 18;
	}
	else if (x == 34) {
		y = 19;
	}
	return y;
}
int checkExtrasPos(int x) {
	int y;
	if (x == 0) {
		y = 0;
	}
	else if (x == 10) {
		y = 1;
	}
	else if (x == 20) {
		y = 2;
	}
	else if (x == 30) {
		y = 3;
	}
	return y;
}
int checkTaxPos(int x) {
	int y;
	if (x == 4) {
		y = 0;
	}
	else if (x == 38) {
		y = 1;
	}
	return y;
}
int checkCommunityPos(int x) {
	int y;
	if (x == 2) {
		y = 0;
	}
	else if (x == 17) {
		y = 1;
	}
	else if (x == 33) {
		y = 2;
	}
	return y;
}
int checkChancePos(int x) {
	int y;
	if (x == 7) {
		y = 0;
	}
	else if (x == 22) {
		y = 1;
	}
	else if (x == 36) {
		y = 2;
	}

	return y;
}

//MOVEMENT FEATURES:
int rollDice() {
	int x = 0;
	srand(time(NULL));
	x = rand() % 6 + 1;
	return x;
}
int menu1() {
	cout << "1.Play game!" << endl;
	cout << "2.Quit!" << endl;
	int x;
	cin >> x;
	return x;
}
//int menu2(int x) {
//	int y;
//	int w;
//	int currentplayer = 1;
//	int choice = 0;
//	if (x == 1) {
//		cout << "Number of players?" << endl;
//		int p;
//		cin >> p;
//		player* pp;
//		pp = new player[p];
//		cout << "1. Start game" << endl;
//		cout << "2.End game" << endl;
//		cin >> w;
//		if (w == 1) {
//			while (choice != 3) {
//				cout << "For player number " << currentplayer << ":" << endl;
//				cout << "Select: 1. Roll dice" << endl;
//				cout << "2.Print details" << endl;
//				cout << "Or press 3 to Quit!" << endl;
//				cin >> choice;
//				if (choice == 1) {
//					int roll = 0;
//					roll = rollDice();
//
//					pp[currentplayer].setposition(pp->getposition() + roll);
//
//				}
//				else {
//					cout << "Cash:" << pp[currentplayer].getcash() << " Position: " << pp[currentplayer].getposition();
//					currentplayer--;
//				}
//				currentplayer++;
//				if (currentplayer > p) {
//					currentplayer = 1;
//				}
//			}
//
//		}
//		else {
//			cout << "Thank you for playing!" << endl;
//		}
//	}
//	else {
//		cout << "Thank you for playing!" << endl;
//	}
//	return 0;
//}


//MENUS:
void purchaseMenu(player& p, residential& y) {
	cout << "Buy this property? 1.Yes 2.No" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		y.assignsymbol(p.getSymbol());
		p.subtractfund(y.getprice());
	}

}
void purchaseMenu2(player& p, property& y) {
	cout << "Buy this property? 1.Yes 2.No" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		y.assignsymbol(p.getSymbol());
		p.subtractfund(y.getprice());
	}
}
void purchaseMenu3(player& p, player& p2, residential& y) {
	cout << "Property already owned by another player! 1. Buy it 2. Pay rent" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		y.assignsymbol(p.getSymbol());
		p.subtractfund(y.getprice() * 2);
		p2.addfund(y.getprice() * 2);
	}
	else {
		p.subtractfund(y.getpayrent());
		p2.addfund(y.getpayrent());
	}
}
void purchaseMenu4(player& p, player& p2, property& y) {
	cout << "Property already owned by another player! 1. Buy it 2. Pay rent" << endl;
	int x;
	cin >> x;
	if (x == 1) {
		y.assignsymbol(p.getSymbol());
		p.subtractfund(y.getprice() * 2);
		p2.addfund(y.getprice() * 2);
	}
	else {
		p.subtractfund(y.getrent());
		p2.addfund(y.getrent());
	}
}
void upgradeMenu(player& p, residential& y) {
	y.upgrade(p);
}

//CHECKING FUNCTION
bool checkTYPE(char** arr, const char* a, int pos) {
	bool found = true;
	for (int i = 0; arr[pos][i] != '\0'; i++) {
		if (arr[pos][i] != a[i]) {
			found = false;
			break;
		}
	}
	return found;
}

int main()
{
	residential** res;//an array of how many residential areas are there
	const int noofres = 20;//number of residential areas
	res = new residential * [noofres];

	res[0] = new residential('A', 0, 0, false, 0, false, false, false, "Johar Town", "jt-a", 1, 200.0, 80.0, '\0');
	res[1] = new residential('B', 0, 0, false, 0, false, false, false, "Johar Town", "jt-b", 3, 250.0, 90.0, '\0');
	res[2] = new residential('A', 0, 0, false, 0, false, false, false, "Iqbal Town", "it-a", 6, 250.0, 60.0, '\0');
	res[3] = new residential('B', 0, 0, false, 0, false, false, false, "Iqbal Town", "it-b", 8, 300.0, 70.0, '\0');
	res[4] = new residential('C', 0, 0, false, 0, false, false, false, "Iqbal Town", "it-c", 9, 400.0, 100.0, '\0');
	res[5] = new residential('A', 0, 0, false, 0, false, false, false, "Faisal Town", "ft-a", 11, 300.0, 100.0, '\0');
	res[6] = new residential('B', 0, 0, false, 0, false, false, false, "Faisal Town", "ft-b", 13, 400.0, 130.0, '\0');
	res[7] = new residential('C', 0, 0, false, 0, false, false, false, "Faisal Town", "ft-c", 14, 400.0, 130.0, '\0');
	res[8] = new residential('A', 0, 0, false, 0, false, false, false, "Model Town", "mt-a", 16, 800.0, 200.0, '\0');
	res[9] = new residential('B', 0, 0, false, 0, false, false, false, "Model Town", "mt-b", 18, 850.0, 200.0, '\0');
	res[10] = new residential('C', 0, 0, false, 0, false, false, false, "Model Town", "mt-c", 19, 2000.0, 500.0, '\0');
	res[11] = new residential('A', 0, 0, false, 0, false, false, false, "Gulberg", "gt-a", 21, 1000.0, 300.0, '\0');
	res[12] = new residential('B', 0, 0, false, 0, false, false, false, "Gulberg", "gt-b", 23, 1200.0, 350.0, '\0');
	res[13] = new residential('C', 0, 0, false, 0, false, false, false, "Gulberg", "gt-c", 24, 2500.0, 600.0, '\0');
	res[14] = new residential('A', 0, 0, false, 0, false, false, false, "DHA", "dt-a", 26, 2000.0, 500.0, '\0');
	res[15] = new residential('B', 0, 0, false, 0, false, false, false, "DHA", "dt-b", 27, 2000.0, 500.0, '\0');
	res[16] = new residential('Y', 0, 0, false, 0, false, false, false, "DHA", "dt-y", 29, 2500.0, 1000.0, '\0');
	res[17] = new residential('A', 0, 0, false, 0, false, false, false, "Bahria Town", "bt-a", 31, 2500.0, 800.0, '\0');
	res[18] = new residential('B', 0, 0, false, 0, false, false, false, "Bahria Town", "bt-b", 32, 3000.0, 900.0, '\0');
	res[19] = new residential('C', 0, 0, false, 0, false, false, false, "Bahria Town", "bt-c", 34, 3000.0, 1000.0, '\0');

	property** pro;
	pro = new property * [8];
	pro[0] = new property("Metro Station", "st-1", 5, 2000, 200, '\0');
	pro[1] = new property("Bus Station", "st-2", 15, 2000, 200, '\0');
	pro[2] = new property("Railway Station", "st-3", 24, 2500, 350, '\0');
	pro[3] = new property("Orange Station", "st-4", 34, 2500, 350, '\0');
	pro[4] = new property("Lesco", "ut-1", 12, 5000, 450, '\0');
	pro[5] = new property("Ptcl", "ut-2", 27, 8000, 500, '\0');
	pro[6] = new property("Wasa", "ut-3", 37, 4000, 400, '\0');
	pro[7] = new property("SuiGas", "ut-4", 39, 2500, 350, '\0');

	const int noofextras = 4;
	extra** extras = new extra * [noofextras];
	extras[0] = new extra(0, true, false, "GO!", false, false);
	extras[1] = new extra(10, false, true, "Jail", false, false);
	extras[2] = new extra(20, false, false, "Free Space", true, false);
	extras[3] = new extra(30, false, false, "GO to Jail", false, true);
	const int nooftax = 2;
	taxes** tax = new taxes * [2];
	tax[0] = new taxes(0.0, 4, "Land Tax");
	tax[1] = new taxes(0.0, 38, "Property Tax");

	chance** chan;
	chan = new chance * [3];
	chan[0] = new chance("Chance", 7);
	chan[1] = new chance("Chance", 22);
	chan[2] = new chance("Chance", 36);
	community** comm;
	comm = new community * [3];
	comm[0] = new community("Community chest", 2);
	comm[1] = new community("Community chest", 17);
	comm[2] = new community("Community chest", 33);


	const char** arr;
	arr = new const char* [40];
	for (int i = 0; i < 40; i++) {
		arr[i] = new char[11];
	}
	arr[0] = "extra";
	arr[1] = "residential";
	arr[2] = "community";
	arr[3] = "residential";
	arr[4] = "taxes";
	arr[5] = "property";
	arr[6] = "residential";
	arr[7] = "chance";
	arr[8] = "residential";
	arr[9] = "residential";
	arr[10] = "extra";
	arr[11] = "residential";
	arr[12] = "property";
	arr[13] = "residential";
	arr[14] = "residential";
	arr[15] = "property";
	arr[16] = "residential";
	arr[17] = "community";
	arr[18] = "residential";
	arr[19] = "residential";
	arr[20] = "extra";
	arr[21] = "residential";
	arr[22] = "chance";
	arr[23] = "residential";
	arr[24] = "residential";
	arr[25] = "property";
	arr[26] = "residential";
	arr[27] = "residential";
	arr[28] = "property";
	arr[29] = "residential";
	arr[30] = "extra";
	arr[31] = "residential";
	arr[32] = "residential";
	arr[33] = "community";
	arr[34] = "residential";
	arr[35] = "property";
	arr[36] = "chance";
	arr[37] = "property";
	arr[38] = "taxes";
	arr[39] = "property";
	int proIndex = 0;
	int communityIndex = 0;
	int chanceIndex = 0;
	int taxIndex = 0;
	int resIndex = 0;

	///* Only For Testing*/
	//int turns;
	//cout << "Input number of turns" << endl;
	//cin >> turns;
	//int number;
	//for (int i = 0; i < turns; i++)
	//{
	//    cout << "Input numberr" << endl;
	//    cin >> number;
	//    if (arr[number] == "residential")
	//    {
	//        cout << "I was in Resiential" << endl;
	//        for (int i = 0; i < 20; i++)
	//        {
	//            if (res[i][0].getPosition() == number)
	//            {
	//                res[i][0].printpropertyinfo();
	//            }
	//        }
	//    }
	//}

	for (int i = 0; i < 20; i++) {
		res[i]->initialiseSymbol();
	}
	for (int i = 0; i < 8; i++) {
		pro[i]->initialiseSymbol();
	}
	int c = menu1();
	if (c == 1) {
		cout << "Enter number of players:" << endl;
		int p;
		cin >> p;
		char s;
		while (p < 0 || p>4) {
			cout << "Max number of players is 5! Re enter:" << endl;
			cin >> p;
		}
		player* pp = new player[p];
		for (int i = 0; i < p; i++) {
			cout << "Enter symbol for player " << i + 1 << endl;
			cin >> s;
			pp[i].setSymbol(s);
		}
		int currentplayer = 1;
		int w;
		int choice = 0;
		cout << "1. Start game" << endl;
		cout << "2.End game" << endl;
		cin >> w;
		if (w == 1) {
			cout << "For player number " << currentplayer << ":" << endl;
			cout << "Select: 1. Roll dice" << endl;
			cout << "2.Print details" << endl;
			cout << "Or press 3 to Quit!" << endl;
			cin >> choice;
			while (choice != 3) {
				
				if (choice == 1) {
					int roll = 0;
					roll = rollDice();
					pp[currentplayer - 1].setposition(pp->getposition() + roll);
					if (pp[currentplayer - 1].getposition() >= 0) {
						cout << "Collect 500 from bank" << endl;
						pp[currentplayer - 1].addfund(500);
					}
					if (pp[currentplayer - 1].getposition() == 10) {
						if (pp[currentplayer - 1].returnGetoutofJail() == 1) {
							cout << "Get out of jail card used" << endl;
							pp[currentplayer - 1].setGetoutOfJail(0);
						}
						else {
							cout << "You went to jail pay 50$ fine" << endl;
							pp[currentplayer - 1].subtractfund(50);
						}
					}
					if (pp[currentplayer - 1].getposition() == 20) {
						cout << "Pay parking fine!" << endl;
						pp[currentplayer - 1].subtractfund(20);
					}
					if (pp[currentplayer - 1].getposition() == 30) {
						if (pp[currentplayer - 1].returnGetoutofJail() == 1) {
							cout << "Get out of jail card used" << endl;
							pp[currentplayer - 1].setGetoutOfJail(0);
						}
						else {
							cout << "You came to the GO TO JAIL TILE. You are now in jail Pay 50$ to escape" << endl;
							pp[currentplayer - 1].specific(10);
							pp[currentplayer - 1].subtractfund(50);
						}

					}
					if (pp[currentplayer - 1].getposition() == 4) {
						cout << "Pay Income tax!" << endl;
						pp[currentplayer].subtractfund(30);
					}
					if (pp[currentplayer - 1].getposition() == 38) {
						cout << "Pay Property tax!" << endl;
						pp[currentplayer - 1].subtractfund(30);
					}
					if (pp[currentplayer - 1].getposition() == 2 || pp[currentplayer - 1].getposition() == 17 || pp[currentplayer - 1].getposition() == 33) {
						cout << "Open a community chest!" << endl;
						srand(time(NULL));
						int r = rand() % 13 + 1;
						drawnchest(pp[currentplayer - 1], r);
					}
					if (pp[currentplayer - 1].getposition() == 7 || pp[currentplayer - 1].getposition() == 22 || pp[currentplayer - 1].getposition() == 36) {
						cout << "Flip a chance card!" << endl;
						srand(time(NULL));
						int r = rand() % 10 + 1;
						int pos = 0;
						int e = drawnchance(pp[currentplayer - 1], r, pos);
						if (e == 2) {
							resIndex = checkResPos(26);
							if (res[resIndex]->getSymbol() == '\0') {
								purchaseMenu(pp[currentplayer - 1], *res[resIndex]);
							}
							else if (res[resIndex]->getSymbol() == pp[currentplayer].getSymbol()) {
								cout << "Property owned by you. 1.Upgrade 2.Ignore" << endl;
								int x;
								cin >> x;
								if (x == 1) {
									upgradeMenu(pp[currentplayer - 1], *res[resIndex]);
								}
							}
							else {
								int secondplayer = 0;
								for (int i = 0; i < p; i++) {
									if (pp[i].getSymbol() == res[resIndex]->getSymbol()) {
										secondplayer = i;
										break;
									}
								}
								purchaseMenu3(pp[currentplayer - 1], pp[secondplayer], *res[resIndex]);
							}
						}
						else if (e == 3) {
							cout << "1. Pay the required amount! 2.Buy it" << endl;
							int x;
							cin >> x;
							if (x == 1) {
								pp[currentplayer - 1].subtractfund(roll * 5);
							}
							else {
								pos = checkproIndex(pos);
								if (pro[pos]->getSymbol() == '\0') {
									purchaseMenu2(pp[currentplayer - 1], *pro[pos]);
								}
								else if (pro[pos]->getSymbol() == pp[currentplayer - 1].getSymbol()) {
									cout << "You already own it" << endl;
								}
								else {
									int player2 = 0;
									for (int i = 0; i < p; i++) {
										if (pp[i].getSymbol() == pro[pos]->getSymbol()) {
											player2 = i;
											break;
										}
									}
									purchaseMenu4(pp[currentplayer - 1], pp[player2], *pro[pos]);
								}
							}
						}
						else if (e == 4) {
							pos = checkproIndex(pos);
							if (pro[pos]->getSymbol() == '\0') {
								cout << "1.Buy it?" << endl;
								int x = 0;
								cin >> x;
								if (x == 1) {
									purchaseMenu2(pp[currentplayer - 1], *pro[pos]);
								}
							}
							else if (pro[pos]->getSymbol() == pp[currentplayer - 1].getSymbol()) {
								cout << "You already own it" << endl;
							}
							else {
								int player2 = 0;
								for (int i = 0; i < p; i++) {
									if (pp[i].getSymbol() == pro[pos]->getSymbol()) {
										player2 = i;
										break;
									}
								}
								purchaseMenu4(pp[currentplayer - 1], pp[player2], *pro[pos]);
							}
						}
						else if (e == 5) {
							pos = checkResPos(pos);
							if (res[pos]->getSymbol() == '\0') {
								purchaseMenu(pp[currentplayer - 1], *res[pos]);
							}
							else if (res[pos]->getSymbol() == pp[currentplayer - 1].getSymbol()) {
								upgradeMenu(pp[currentplayer - 1], *res[pos]);
							}
							else {
								int player2 = 0;
								for (int i = 0; i < p; i++) {
									if (pp[i].getSymbol() == res[pos]->getSymbol()) {
										player2 = i;
										break;
									}
								}
								purchaseMenu4(pp[currentplayer - 1], pp[player2], *res[pos]);
							}
						}
						else if (e == 6) {
							cout << "Done!" << endl;
						}
						else if (e == 7) {
							cout << "1.Sell the card 2.Keep it" << endl;
							int x;
							cin >> x;
							if (x == 1) {
								pp[currentplayer - 1].addfund(500);
							}
							else {
								pp[currentplayer - 1].setGetoutOfJail(1);
							}
						}
						else if (e == 8) {
							cout << "done" << endl;
						}
						else if (e == 9) {
							pp[currentplayer - 1].subtractfund(pp[currentplayer - 1].gethotelOwned() * 100 + pp[currentplayer - 1].getpropertyOwned() * 50);
						}
						else {
							cout << "Done!" << endl;
						}
					}
					else if (pp[currentplayer - 1].getposition() == 5 || pp[currentplayer - 1].getposition() == 12 || pp[currentplayer - 1].getposition() == 15 || pp[currentplayer - 1].getposition() == 25 || pp[currentplayer - 1].getposition() == 28 || pp[currentplayer - 1].getposition() == 35 || pp[currentplayer - 1].getposition() == 37 || pp[currentplayer - 1].getposition() == 39) {
						int propIndex = 0;
						propIndex = checkproIndex(pp[currentplayer - 1].getposition());
						if (pro[propIndex]->getSymbol() == '\0') {
							purchaseMenu2(pp[currentplayer - 1], *pro[proIndex]);
						}
						else if (pro[propIndex]->getSymbol() == pp[currentplayer - 1].getSymbol()) {
							cout << "You already own it!" << endl;
						}
						else {
							int player2 = 0;
							for (int i = 0; i < p; i++) {
								if (pp[i].getSymbol() == pro[propIndex]->getSymbol()) {
									player2 = i;
									break;
								}
							}
							purchaseMenu4(pp[currentplayer - 1], pp[player2], *pro[propIndex]);
						}
					}
					else {
					int resIndex = 0;
					resIndex = checkResPos(pp[currentplayer-1].getposition());
					if (res[resIndex]->getSymbol()=='\0') {
						purchaseMenu(pp[currentplayer-1],*res[resIndex]);
					}
					else if (res[resIndex]->getSymbol()==pp[currentplayer-1].getSymbol()) {
						upgradeMenu(pp[currentplayer-1],*res[resIndex]);
					}
					else {
						int player2 = 0;
						for (int i = 0; i < p; i++) {
							if (pp[i].getSymbol() == res[resIndex]->getSymbol()) {
								player2 = i;
								break;
							}
						}
						purchaseMenu3(pp[currentplayer - 1], pp[player2], *res[resIndex]);
					}
                    }
				}
				else {
					cout << "Cash:" << pp[currentplayer - 1].getcash() << " Position: " << pp[currentplayer - 1].getposition();
					currentplayer--;
				}
				currentplayer++;
				if (currentplayer > p) {
					currentplayer = 1;
				}
				cout << "For player number " << currentplayer << ":" << endl;
				cout << "Select: 1. Roll dice" << endl;
				cout << "2.Print details" << endl;
				cout << "Or press 3 to Quit!" << endl;
				cin >> choice;
			}

		}
		else {
			cout << "Thank you for playing!" << endl;
		}
	}




}