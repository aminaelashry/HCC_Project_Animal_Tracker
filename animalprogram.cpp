#include <iostream>
#include <string>

using namespace std;

//keeps count of animals
struct Animal
{
	string animalType;
	int animalAmount;
};

//function protoypes
void addAnimal(Animal[], int);
int searchAnimal(const Animal[], string, int);
void displayAnimal(const Animal[], int );

//enum for menu choices
enum {ADD=1, SEARCH, DISPLAY, EXIT, NOT_FOUND = -1};

int main()
{
	//store number of animals to survey
	int animalCount{ 0 };
	
	//prompt user for number of animals to track
	cout << "Enter the number of animals you are tracking:";
	cin >> animalCount;
	cin.ignore();
	
	//dynamically creating array
	Animal* animals = new Animal[animalCount];
	//initializing members
	for (int i{ 0 }; i < animalCount; i++) {
		animals[i].animalAmount = 0;
		animals[i].animalType = "none";
	}

	int menuChoice{ 0 };
	do
	{
		//displays menu
		cout << "\nANIMAL MENU" << endl;
		cout << "\t1. ADD ANIMAL" << endl
			<< "\t2. SEARCH ANIMALS" << endl
			<< "\t3. DISPLAY ANIMALS" << endl 
			<< "\t4. EXIT PROGRAM" << endl << endl;
		
		//prompts user for menu choice
		cout << "Enter the number of your menu choice:";
		cin >> menuChoice;

		string searchString{};
		int idx{ 0 };

		//switch statement for each option
		//using enum values declared above
		switch (menuChoice)
		{
			case ADD:
				//function call
				addAnimal(animals, animalCount);
				break;

			case SEARCH:
				cin.ignore();
				cout << "What animal are you looking for:";
				getline(cin, searchString);

				//function call
				idx = searchAnimal(animals, searchString, animalCount);

				//statement that take index value and determines
				//if the value was found
				if (idx == NOT_FOUND)
				{
					cout << "Animal not found in database." << endl << endl;
				}
				else
				{
					cout << "The animal " << animals[idx].animalType << " was found with a count of "
					<< animals[idx].animalAmount << endl << endl;
				}
				break;

			case DISPLAY:
				//function call
				displayAnimal(animals, animalCount);
				break;

			case EXIT:
				cout << "Thank you for using this program. See you soon." << endl << endl;
				break;

			default:
				cout << "Invalid choice. Try again.";
				break;
		}
	} while (menuChoice != EXIT);

	//deleting memory
	delete[] animals;
	animals = nullptr;

	system("pause");
	return 0;
}

//function definitions
void addAnimal(Animal animalsArr[], int size)
{
	cout << "Enter the total amount of animals you would like to enter:";
	cin >> size;
	if (size <= 0)
	{
		cout << "Invalid amount." << endl;
		cout << "Enter the total amount of animals you would like to enter:";
		cin >> size;
	}
	cin.ignore();
	
	//loops through the array and stores values in memory
	//for each input by the user
	for (int i{ 0 }; i < size; i++)
	{
		cout << "Enter the type of the animal you would like to enter:";
		getline(cin, animalsArr[i].animalType);
		//cin.ignore();

		cout << "Enter the amount of this type of animal you would like to enter:";
		cin >> animalsArr[i].animalAmount;

		if (animalsArr[i].animalAmount <= 0)
		{
			cout << "Invalid amount." << endl;
			cout << "Enter the amount of this type of animal you would like to enter:";
			cin >> animalsArr[i].animalAmount;
		}
		cin.ignore();
	}

}

int searchAnimal(const Animal animalsArr[], string srchStr, int size)
{
	//loops through array in order to find the string
	//returns value based on found or not
	for (int i{ 0 }; i < size; i++)
	{
		if (animalsArr[i].animalType == srchStr)
		{
			return i;
		}
		
	}
	return -1;
}

void displayAnimal(const Animal animalsArr[], int size)
{
	//loops through array and returns the type and amount
	for (int i{ 0 }; i < size; i++)
	{
		cout << "Animal " << (i+1) << ":" << animalsArr[i].animalType << endl;
		cout << "Amount of animal " << (i+1) << ":" << animalsArr[i].animalAmount << endl;
	}
}
