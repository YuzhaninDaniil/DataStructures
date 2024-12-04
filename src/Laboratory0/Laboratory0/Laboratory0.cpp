#include <iostream>

using namespace std;

struct Person
{
	string FirstName;
	string LastName;
	int Age;

	void WritePerson(Person person)
	{
		cout << "Age is " << person.Age << endl;
		cout << "FirstName is " << person.FirstName << endl;
		cout << "LastName is " << person.LastName;
	}
};



int main()
{
	Person person;
	person.Age = 19;
	person.FirstName = "Daniil";
	person.LastName = "Danvarg";

	person.WritePerson(person);

}



