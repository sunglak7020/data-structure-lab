#include "Rectangle.h"
#include "Pet.h"
#include "Music.h"

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

	printf("===========================\n");

	//음악 스트리밍 서비스
	MusicStreamingService myService("Melon");
	//새로운 음악 추가
	myService.addMusic("Jump", "Blackpink", "JumpAlbum", 2025);
	myService.addMusic("Swim", "BTS", "ARIRANG", 2026);
	myService.addMusic("BANG BANG", "IVE", "REVIVE", 2026);
	myService.addMusic("404", "KiiKii", "Delulu", 2026);

	//검색 해보기
	string music_title;
	cout << "Enter the Music Title: ";
	cin >> music_title;
	Music* result = myService.searchByTitle(music_title);
	if (result != NULL) {
		cout << "Found: " << result->getTitle() << endl;
	}
	else {
		cout << "not Found" << endl;
	}

	return 0;
}