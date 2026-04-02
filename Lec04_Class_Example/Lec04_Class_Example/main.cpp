#include "Rectangle.h"
#include "Pet.h"

using namespace std;
int main() {
	Rectangle rect1(4, 6);
	cout << "Rectangle 1: " << endl;
	//printf("Rectangle 1: \n");
	
	cout << "Area: " << rect1.getArea() << endl;
	//printf("Area: %lf\n", rect1.getArea());

	cout << "Perimeter: " << rect1.getPerimeter() << endl;
	cout << "Is Square? " << boolalpha << rect1.isSquare() << endl;
	printf("===========================\n");
	
	Pet myPet("Lucky", 5, "dog");
	cout << "My pet's name is " << myPet.getName() << endl;

	Puppy myPuppy("Kong", 3, "dog", "Puddle");
	cout << "My puppy is " << myPuppy.getBreed() << endl;

	myPet.infoPet();

	return 0;
}