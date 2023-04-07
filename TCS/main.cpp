#include <iostream>
#include <string>
#include "Date.h"
using namespace std;

#define MAX_OWNED_CARS 3
#define MIN_MAX_SPEED 40 // in (km/h)
#define MAX_FINES_NUMBER 100
#define MAX_DRIVER_CAPACITY 3000
#define MAX_CARS_NUMBER MAX_OWNED_CARS * MAX_DRIVER_CAPACITY

// current license iterator -> tells how many registered driver in the system
// used to index the new registered driver

unsigned int current_license;

// constructing a date datatype to hold the day, month and year
// using short int as the big range of the int data type is not needed
// and unsigned as none of the members ( day, month nor year ) can be negative

struct date
{
	unsigned short int day = 0,
		month = 0,
		year = 0;
};

// constructing a model datatype to hold the car model which consists of the
// the manufacturer name and the model name
// using string to store both of them as it can hold whatever characters
// they are consisted of, whether they're numbers or from the Latin alphabetical

struct model
{
	string manufacturer = "",
		model_name = "";
};

// constructing a fine datatype to hold the fine information, its value, the street
// in which it was committed and its date and whether its paid or not
// using float for the value as it the speed could be a floating point value so the
// fine value can be as well
// using string for the street name as it can hold a whole sentence representing the street name
// using the date datatype to store the date of the fine
// using a bool type to store whether the fine is paid or not

struct fine
{
	float value = 0.0;
	string street_name = "";
	date fine_date;
	bool paid = false;
};

// constructing a car datatype to hold the car information, the owner of the car name,
// the car plate, the production year, the total amount of fines in the car history, and
// an array to hold and keep track of these fines, and model datatype to hold the car model
// and the current amount of unpaid fines.
// using string for the owner name as it can hold their whole name
// using unsigned int for the car plate, production year, current fine number and the current 
// amount of unpaid fines as they all can not be negative and they fit right in the integer datatype range.
// using array of fine datatype to store the car fines, and a model datatype to store the car model

struct car
{
	string car_owner = "";
	unsigned int car_plate = 0, production_year = 0,
		current_fine_number = 0, car_unpaid_fines_number = 0;
	fine recoreded_fines[MAX_FINES_NUMBER];
	model car_model;
}stored_cars[MAX_CARS_NUMBER];

// constructing a driver datatype to hold the driver information, their name,
// their license number, their birth date, the number of owned cars
// using unsigned int for the license number and the number of owned cars neither of 
// both can be negative and they fit right in the integer datatype range
// using string for the owner name as it can hold their whole name
// using the date datatype to store the driver's birth date

struct driver
{
	unsigned int license_number = 0,
		owned_cars_number = 0;
	string name = "";
	date birth_date;
}stored_drivers[MAX_DRIVER_CAPACITY];

// @param char last_choice the last choice that the user can enter
// @return returns char - a valid response within the possible offered range
// takes the user choice and checks whether it is in the valid range or
// not, if it is not, it asks the user for a valid response.

char get_choice(char);

// @param unsigned int year - the year to check whether it's leap or not
// @return bool - returns whether the year is leap or not
// it checks whether the year is leap or not

bool leap_year(unsigned int);

// @param unsigned int license - user input license
// @return returns bool - whether the license exist or not
// checks whether the license is a valid one or not

bool valid_license(unsigned int);

// @param unsigned int car_plate - user input car_plate
// @return returns bool - whether the car plate exist or not
// checks whether the car plate is a valid one or not

bool valid_car_plate(unsigned int);

// @param unsigned int day - user input day
// @param unsigned int month_end - user input month total days
// @return returns bool - whether the day is within the month range or not
// checks whether the day is a valid one or not

bool valid_day(unsigned int, unsigned int);

// @param date - user input date
// @return returns bool - whether the date is valid or not
// checks whether the date is a valid one or not

bool valid_date(date);

// @param string - user input owner_name
// @return returns bool - whether the owner name exists or not
// checks whether the owner name is a valid one or not, if 
// it is valid, it shows his car/s info then return true, if it is not,
// it tells the user that is not existed and return false

bool car_search_name(string);

// @param unsigned int - user input car_plate
// @return returns bool - whether the car plate exists or not
// checks whether the car palte is a valid one or not, if 
// it is valid, it shows the car info then return true, if it is not,
// it tells the user that is not existed and return false

void car_search(unsigned int);

// it takes the car_plate, car_speed, the street_speed_limit, the street name
// and the fine date from the officer and validate each one of them then
// calculates the fine value and store it in the car array of recoreded fines

void record_fine();

// it takes the license number from the user, validate it, then checks whether
// they own cars or not, if they do, it shows them the cars and their fines if existed
// then asks the user which fine he wants to pay for which car and update its status is paid

void pay_fine();

// it takes the license number from the user, validate it, then shows the total
// amount of unpaid fines for their cars

void show_total_fines();

// it takes the user name, birth date and validate it
// then it stores his data in the system and gives him a license number

void register_new_driver();

// it asks for the user license number, validate it, then checks whether he
// exceeded the maxiumum number of allowed cars, if he did, it tells them that
// they can't register a new car, if he didn't, it asks them for the new car
// info and validate it and give it a car plate

void register_new_car();

// it shows the driver them operator and let them choose one of them
// to go to, it validate his choice, if it's valid he go to do his operation

void driver_menu();

// it shows the search options and let the user choose one, it validate their choice
// if their choice is valid they can search by the way they've chosen

void car_search_menu();

// @return returns bool - whether user want to exit the program or not
// it shows the user his options then validate their choice, if it's valid
// a certain function gets called and a value returned

bool main_menu();

int main()
{
	while (true)
	{
		if (main_menu() == true)
		{
			system("cls");
			break;
		}
	}
	return 0;
}

char get_choice(char last_choice)
{
	char input_choice;
	while (1)
	{
		cin >> input_choice;
		if (input_choice >= '1' && input_choice <= last_choice)
		{
			return input_choice;
		}
		else
		{
			cout << "\n\tPlease Enter a valid response: ";
		}
	}
}

bool valid_license(unsigned int license)
{
	// stored_drivers indexing is based in the driver's license number
	// for instance, a driver with license 3 will have their data stored at index 2
	// if the license is set to its intial value which ZERO then it's not valid
	// if the license number is equal to ZERO then it's not valid
	if (license > 0 && stored_drivers[license - 1].license_number == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool valid_car_plate(unsigned int car_plate)
{
	// stored_cars indexing is based in the car's plate number
	// for instance, a car with a plate number 3 will have its data stored at index 2
	// if the value stored in the car index is euqal to the value inputed by the user
	// then the car plate is valid
	// if the car plate number is equal to ZERO then it's not valid
	if (car_plate > 0 && stored_cars[car_plate - 1].car_plate == car_plate)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool car_search_name(string owner_name)
{
	unsigned int name_shows = 0;
	for (unsigned int i = 0; i < MAX_DRIVER_CAPACITY; i++)
	{
		if (owner_name == stored_drivers[i].name)
		{
			name_shows++;
			cout << "\n\t\t" << stored_drivers[i].name;
			if (stored_drivers[i].owned_cars_number == 0)
			{
				cout << " owns no cars!\n\n\t";
				system("pause");
			}
			else if (stored_drivers[i].owned_cars_number == 1)
			{
				cout << " owns one car\n";
				unsigned int car_plate = i * 3;
				cout << "\n\n\tmodel: " << stored_cars[car_plate].car_model.manufacturer
					<< ' ' << stored_cars[car_plate].car_model.model_name;
				cout << "\n\n\tproduction year: " << stored_cars[car_plate].production_year << "\n\n\t";
				system("pause");
			}
			else
			{
				cout << " owns " << stored_drivers[i].owned_cars_number << " cars\n";
				for (unsigned int car_iterator = 0; car_iterator < stored_drivers[i].owned_cars_number; car_iterator++)
				{
					unsigned int car_plate = ((i * 3)) + car_iterator;
					cout << "\n\n\tmodel: " << stored_cars[car_plate].car_model.manufacturer
						<< ' ' << stored_cars[car_plate].car_model.model_name;
					cout << "\n\n\tproduction year: " << stored_cars[car_plate].production_year << "\n\n";
					if (car_iterator + 1 == stored_drivers[i].owned_cars_number)
					{
						cout << "\n\t";
						system("pause");
					}
				}
			}
		}
	}
	if (name_shows > 0)
	{
		return true;
	}
	return false;
}

void car_search(unsigned int car_plate)
{
	cout << "\n\t" << stored_cars[car_plate - 1].car_owner << " owns this car";
	cout << "\n\n\tmodel: " << stored_cars[car_plate - 1].car_model.manufacturer
		<< ' ' << stored_cars[car_plate - 1].car_model.model_name;
	cout << "\n\n\tproduction year: " << stored_cars[car_plate - 1].production_year << "\n\n\t";
	system("pause");
}

void record_fine()
{
	system("cls");
	cout << "\n\n\tHello Officer!\n";
	unsigned int car_plate;
	float car_speed, road_max_speed;
	Date fine_date;
	string street_name;

	cout << "\n\n\tEnter car plate: ";
	cin >> car_plate;

	while (!valid_car_plate(car_plate))
	{
		cout << "\n\n\tcar plate does not exist\n\n";
		cout << "\t1- Enter another car plate\n\n";
		cout << "\t2- Main Menu\n\n\n";
		cout << "\tEnter your choice: ";
		char choice = get_choice('2');
		if (choice == '1')
		{
			cout << "\n\n\tPlease enter a valid car plate: ";
			cin >> car_plate;
		}
		else
		{
			return;
		}
	}

	cout << "\n\n\tEnter road maximum speed (km/h): ";
	cin >> road_max_speed;

	while (road_max_speed < MIN_MAX_SPEED)
	{
		cout << "\n\n\tPlease enter a valid road maximum speed (km/h): ";
		cin >> road_max_speed;
	}

	cout << "\n\n\tEnter car speed (km/h): ";
	cin >> car_speed;

	while (car_speed <= road_max_speed)
	{
		cout << "\n\n\tPlease enter a valid exceeding speed (km/h): ";
		cin >> car_speed;
	}

	cout << "\n\n\tEnter street name: ";
	cin.ignore();
	getline(cin, street_name);
	cout << "\n\n\tEnter the date of the fine\n\t(day - month - year) space separated: ";
	cin >> fine_date.m_day >> fine_date.m_month >> fine_date.m_year;


	while (!valid_date(fine_date))
	{
		cout << "\n\n\tPlease enter a valid date\n\t(day - month - year) space separated: ";
		cin >> fine_date.m_day >> fine_date.m_month >> fine_date.m_year;
	}

	unsigned int fine_number = stored_cars[car_plate - 1].current_fine_number;
	stored_cars[car_plate - 1].recoreded_fines[fine_number].fine_date = fine_date;
	stored_cars[car_plate - 1].recoreded_fines[fine_number].street_name = street_name;
	stored_cars[car_plate - 1].recoreded_fines[fine_number].value = 2 * (car_speed - road_max_speed);
	stored_cars[car_plate - 1].current_fine_number++;
	stored_cars[car_plate - 1].car_unpaid_fines_number++;

	cout << "\n\n\t";
	system("pause");
}

void pay_fine()
{
	system("cls");
	unsigned int license_number;
	cout << "\n\n\tEnter your license number: ";
	cin >> license_number;

	while (!valid_license(license_number))
	{
		cout << "\n\n\tlicense number does not exist\n\n";
		cout << "\t1- Enter another car plate\n\n";
		cout << "\t2- Main Menu\n\n\n";
		cout << "\tEnter your choice: ";
		char choice = get_choice('2');
		if (choice == '1')
		{
			cout << "\n\n\tPlease enter a valid license plate: ";
			cin >> license_number;
		}
		else
		{
			return;
		}
	}

	cout << "\n\n\tYou have";

	if (stored_drivers[license_number - 1].owned_cars_number == 0)
	{
		cout << " no cars, and no fines!\n\n\t";
		system("pause");
	}

	else if (stored_drivers[license_number - 1].owned_cars_number == 1)
	{
		cout << " one car";
		unsigned int car_index = ((license_number - 1) * 3);
		cout << "\n\n\t\tmodel: " << stored_cars[car_index].car_model.manufacturer
			<< ' ' << stored_cars[car_index].car_model.model_name;
		cout << "\n\n\t\tproduction year: " << stored_cars[car_index].production_year;

		if (stored_cars[car_index].car_unpaid_fines_number > 0)
		{
			cout << "\n\n\t\tThis car has fines: ";
			unsigned int unpaid_fines_number = 0;
			for (unsigned int fine_iterator = 0; fine_iterator < stored_cars[car_index].current_fine_number; fine_iterator++)
			{
				if (stored_cars[car_index].recoreded_fines[fine_iterator].value != 0.0)
				{
					if (stored_cars[car_index].recoreded_fines[fine_iterator].paid == false)
					{
						unpaid_fines_number++;
						cout << "\n\n\t\t" << unpaid_fines_number << "- Date: ";
						cout << stored_cars[car_index].recoreded_fines[fine_iterator].fine_date.day << ' ';
						cout << stored_cars[car_index].recoreded_fines[fine_iterator].fine_date.month << ' ';
						cout << stored_cars[car_index].recoreded_fines[fine_iterator].fine_date.year;
						cout << "\n\n\t\t   Street: " << stored_cars[car_index].recoreded_fines[fine_iterator].street_name;
						cout << "\n\n\t\t   Value: " << stored_cars[car_index].recoreded_fines[fine_iterator].value;
					}
					cout << "\n\n";
				}
			}

			cout << "\n\tChoose the number of fine you want to pay: ";
			char input_choice = get_choice(char('0' + unpaid_fines_number));
			unsigned int chosen_fine_number = int(input_choice) - int('1'), unpaid_fines_iterator = 0;

			for (unsigned int fine_iterator = 0; fine_iterator < stored_cars[car_index].current_fine_number; fine_iterator++)
			{
				if (stored_cars[car_index].recoreded_fines[fine_iterator].value != 0.0)
				{
					if (stored_cars[car_index].recoreded_fines[fine_iterator].paid == false)
					{
						if (chosen_fine_number == unpaid_fines_iterator)
						{
							stored_cars[car_index].recoreded_fines[fine_iterator].paid = true;
							stored_cars[car_index].car_unpaid_fines_number--;
							break;
						}
						unpaid_fines_iterator++;
					}
				}
			}

			cout << "\n\n\tFine number " << chosen_fine_number + 1 << " is paid\n";
		}
		else if (stored_cars[car_index].current_fine_number == 0)
		{
			cout << "\n\n\tThis car has no fines at all!";
		}
		else
		{
			cout << "\n\n\tThis car has no unpaid fines!";
		}

		cout << "\n\n\t";
		system("pause");
	}
	else
	{
		cout << ' ' << stored_drivers[license_number - 1].owned_cars_number << " cars";
		unsigned int unpaid_fines_number_total[MAX_OWNED_CARS];
		for (int fine_iterator = 0; fine_iterator < MAX_OWNED_CARS; fine_iterator++)
		{
			unpaid_fines_number_total[fine_iterator] = 0;
		}
		for (unsigned int car_iterator = 0; car_iterator < stored_drivers[license_number - 1].owned_cars_number; car_iterator++)
		{
			unsigned int car_index = ((license_number - 1) * 3) + car_iterator;
			cout << "\n\n\t" << car_iterator + 1 << "- model: "
				<< stored_cars[car_index].car_model.manufacturer
				<< ' ' << stored_cars[car_index].car_model.model_name;
			cout << "\n\n\t   production year: " << stored_cars[car_index].production_year;
			unsigned int unpaid_fines_number = 0;
			if (stored_cars[car_index].car_unpaid_fines_number > 0)
			{
				cout << "\n\n\t\tThis car has fines: ";
				for (unsigned int fine_iterator = 0; fine_iterator < stored_cars[car_index].current_fine_number; fine_iterator++)
				{
					if (stored_cars[car_index].recoreded_fines[fine_iterator].value != 0.0)
					{
						if (stored_cars[car_index].recoreded_fines[fine_iterator].paid == false)
						{
							unpaid_fines_number++;
							cout << "\n\n\t\t" << unpaid_fines_number << "-\n\n\t\tDate: ";
							cout << stored_cars[car_index].recoreded_fines[fine_iterator].fine_date.day << ' ';
							cout << stored_cars[car_index].recoreded_fines[fine_iterator].fine_date.month << ' ';
							cout << stored_cars[car_index].recoreded_fines[fine_iterator].fine_date.year;
							cout << "\n\n\t\tStreet: " << stored_cars[car_index].recoreded_fines[fine_iterator].street_name;
							cout << "\n\n\t\tValue: " << stored_cars[car_index].recoreded_fines[fine_iterator].value;
						}
						cout << "\n\n";
					}
				}
			}
			else if (stored_cars[car_index].current_fine_number == 0)
			{
				cout << "\n\n\tThis car has no unpaid fines!";
			}
			else
			{
				cout << "\n\n\tThis car has no unpaid fines!";
			}
			unpaid_fines_number_total[car_iterator] = unpaid_fines_number;
		}

		cout << "\n\tChoose the car you want to pay its fine: ";
		char car_choice = get_choice(char('0' + stored_drivers[license_number - 1].owned_cars_number));
		unsigned int chosen_car_number = (int(car_choice) - int('1')),
			chosen_car_index = (((license_number - 1) * 3) + (int(car_choice) - int('1')));

		if (stored_cars[chosen_car_index].car_unpaid_fines_number == 0)
		{
			cout << "\n\n\tThis car has no unpaid fines!";
			cout << "\n\n\t";
			system("pause");
			return;
		}

		cout << "\n\tChoose the number of fine you want to pay: ";
		char fine_choice = get_choice(char('0' + unpaid_fines_number_total[chosen_car_number]));
		unsigned int chosen_fine_number = int(fine_choice) - int('1'), unpaid_fines_iterator = 0;

		for (unsigned int fine_iterator = 0; fine_iterator < stored_cars[chosen_car_index].current_fine_number; fine_iterator++)
		{
			if (stored_cars[chosen_car_index].recoreded_fines[fine_iterator].value != 0.0)
			{
				if (stored_cars[chosen_car_index].recoreded_fines[fine_iterator].paid == false)
				{
					if (chosen_fine_number == unpaid_fines_iterator)
					{
						stored_cars[chosen_car_index].recoreded_fines[fine_iterator].paid = true;
						stored_cars[chosen_car_index].car_unpaid_fines_number--;
						break;
					}
					unpaid_fines_iterator++;
				}
			}
		}
		cout << "\n\n\tFine number " << chosen_fine_number + 1 << " is paid\n";
		cout << "\n\n\t";
		system("pause");
	}
}

void show_total_fines()
{
	system("cls");
	unsigned int license_number;
	float total_unpaid_fines = 0.0;
	cout << "\n\n\tEnter your license number: ";
	cin >> license_number;
	while (!valid_license(license_number))
	{
		cout << "\n\n\tlicense number does not exist\n\n";
		cout << "\t1- Enter another car plate\n\n";
		cout << "\t2- Main Menu\n\n\n";
		cout << "\tEnter your choice: ";
		char choice = get_choice('2');
		if (choice == '1')
		{
			cout << "\n\n\tPlease enter a valid license plate: ";
			cin >> license_number;
		}
		else
		{
			return;
		}
	}

	for (unsigned int car_iterator = 0; car_iterator < MAX_OWNED_CARS; car_iterator++)
	{
		for (unsigned int fine_iterator = 0; fine_iterator < MAX_FINES_NUMBER; fine_iterator++)
		{
			unsigned int car_index = (((license_number - 1) * 3) + car_iterator);
			if (stored_cars[car_index].recoreded_fines[fine_iterator].paid == false)
			{
				total_unpaid_fines += stored_cars[car_index].recoreded_fines[fine_iterator].value;
			}
		}
	}

	cout << "\n\n\tThe total amount of unpaid fines for your cars: ";
	cout << total_unpaid_fines << " \n\n\t";
	system("pause");
}

void register_new_driver()
{
	system("cls");
	string name;
	date birth_date;
	cout << "\n\n\tEnter your name: ";
	cin.ignore();
	getline(cin, name);
	cout << "\n\tEnter your birth date\n\n\t (day - month - year) space separated: ";
	cin >> birth_date.day >> birth_date.month >> birth_date.year;
	while (!valid_date(birth_date))
	{
		cout << "\n\n\tPlease enter a valid birth date!\n";
		cout << "\n\tEnter your birth date\n\n\t (day - month - year) space separated: ";
		cin >> birth_date.day >> birth_date.month >> birth_date.year;
	}
	stored_drivers[current_license].license_number = current_license + 1;
	stored_drivers[current_license].birth_date = birth_date;
	stored_drivers[current_license].name = name;
	current_license++;

	cout << "\n\n\tWelcome to the traffic contorl system " << name << " !\n\n";
	cout << "\tYour license number: " << current_license << " \n\n";
	cout << '\t';
	system("pause");
}

void register_new_car()
{
	system("cls");
	unsigned int license_number;
	cout << "\n\n\tEnter your license number: ";
	cin >> license_number;

	while (!valid_license(license_number))
	{
		cout << "\n\n\tlicense number does not exist\n\n";
		cout << "\t1- Enter another car plate\n\n";
		cout << "\t2- Main Menu\n\n\n";
		cout << "\tEnter your choice: ";
		char choice = get_choice('2');
		if (choice == '1')
		{
			cout << "\n\n\tPlease enter a valid license plate: ";
			cin >> license_number;
		}
		else
		{
			return;
		}
	}

	if (stored_drivers[license_number - 1].owned_cars_number == MAX_OWNED_CARS)
	{
		cout << "\n\n\tYou have reached the maxiumum number of owned cars!";
		cout << "\n\n\tYou can not register a new car!";
		cout << "\n\n\t";
		system("pause");
		return;
	}

	car new_car;
	cout << "\n\tEnter the manufacturer of the car: ";
	cin >> new_car.car_model.manufacturer;
	cout << "\n\tEnter the model of the car: ";
	cin >> new_car.car_model.model_name;
	cout << "\n\tEnter the production year of the car: ";
	cin >> new_car.production_year;
	while (new_car.production_year < 0)
	{
		cout << "\n\n\tEnter a valid production year: ";
		cin >> new_car.production_year;
	}
	new_car.car_owner = stored_drivers[license_number - 1].name;
	new_car.car_plate = (((license_number - 1) * 3) + stored_drivers[license_number - 1].owned_cars_number) + 1;
	stored_cars[new_car.car_plate - 1] = new_car;
	stored_drivers[license_number - 1].owned_cars_number++;

	cout << "\n\n\tWelcome back " << stored_drivers[license_number - 1].name << " !\n\n";
	cout << "\tYour new registered car plate: " << new_car.car_plate << " \n\n";
	cout << "\t\t\t\tmodel: " << new_car.car_model.manufacturer <<
		' ' << new_car.car_model.model_name << " \n\n";
	cout << "\t\t\t\tproduction year: " << new_car.production_year << " \n\n";
	cout << '\t';
	system("pause");
}

void driver_menu()
{
	system("cls");
	cout << "\n\n\tHello Driver!\n\n";
	cout << "\t1- Register new driver\n\n";
	cout << "\t2- Register new car\n\n";
	cout << "\t3- Show total unpaid fines\n\n";
	cout << "\t4- Pay fine\n\n\n";
	cout << "\tPlease choose your operation: ";
	char choice = get_choice('4');
	if (choice == '1')
	{
		register_new_driver();
	}
	else if (choice == '2')
	{
		register_new_car();
	}
	else if (choice == '3')
	{
		show_total_fines();
	}
	else if (choice == '4')
	{
		pay_fine();
	}
}

void car_search_menu()
{
	system("cls");
	cout << "\n\n\tHello!, How would you like to search?\n\n";
	cout << "\t1- By owner's name\n\n";
	cout << "\t2- By car plate\n\n";
	cout << "\n\tChoose (1 or 2): ";
	char choice = get_choice('2');

	if (choice == '1')
	{
		system("cls");
		string name;
		cout << "\n\n\tEnter owner's name: ";
		cin.ignore();
		getline(cin, name);
		while (!car_search_name(name))
		{
			cout << "\n\tThere is no such a car owner!\n\n";
			cout << "\t1- Enter another car owner name\n\n";
			cout << "\t2- Main Menu\n\n\n";
			cout << "\tEnter your choice: ";
			char choice = get_choice('2');
			if (choice == '1')
			{
				cout << "\n\n\tPlease enter an existing car owner name: ";
				getline(cin, name);;
			}
			else
			{
				return;
			}
		}
	}
	else if (choice == '2')
	{
		system("cls");
		unsigned int car_plate;
		cout << "\n\n\tEnter car plate: ";
		cin >> car_plate;
		while (!valid_car_plate(car_plate))
		{
			cout << "\n\n\tcar plate does not exist\n\n";
			cout << "\t1- Enter another car plate\n\n";
			cout << "\t2- Main Menu\n\n\n";
			cout << "\tEnter your choice: ";
			char choice = get_choice('2');
			if (choice == '1')
			{
				cout << "\n\n\tPlease enter a valid car plate: ";
				cin >> car_plate;
			}
			else
			{
				return;
			}
		}
		car_search(car_plate);
	}
}

bool main_menu()
{
	system("cls");
	cout << "\n\n\t1- Driver Options\n\n";
	cout << "\t2- Record fine (Officer ONLY)\n\n";
	cout << "\t3- Search for a car\n\n";
	cout << "\t4- Exit\n\n\n";
	cout << "\tThis is Traffic Contorl System, Enter your choice: ";

	char choice = get_choice('4');

	if (choice == '1')
	{
		driver_menu();
		return false;
	}
	else if (choice == '2')
	{
		record_fine();
		return false;
	}
	else if (choice == '3')
	{
		car_search_menu();
		return false;
	}
	else
	{
		return true;
	}
}