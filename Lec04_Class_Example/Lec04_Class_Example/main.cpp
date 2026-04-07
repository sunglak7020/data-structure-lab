#include "Rectangle.h"
#include "Pet.h"
#include "Music.h"

using namespace std;
int main() {

	//포인터 실습
	int a = 10;
	int* p;
	p = &a;
	cout << "a의 값: " << a << endl;
	cout << "a의 주소: " << &a << endl;
	cout << "p에 저장된 값(주소): " << p << endl;
	cout << "p에 저장된 주소에 저장된 값: " << *p << endl;
	*p = 20;
	cout << "a의 값: " << a << endl;
	cout << "a의 주소: " << &a << endl;
	cout << "p에 저장된 값(주소): " << p << endl;
	cout << "p에 저장된 주소에 저장된 값: " << *p << endl;
	cout << "=================================" << endl;

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
	myService.addMusic("DDuduDDudu", "Blackpink", "JumpAlbum", 2014);

	//제목으로 검색해보기
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

	//가수 이름으로 검색해보기
	string artist_name;
	cout << "Enter the artist name: ";
	cin >> artist_name;

	vector<Music*> artistResult = myService.searchByArtist(artist_name);
	if (artistResult.size() > 0) {
		cout << "Found" << artistResult.size() << "songs by" << artist_name << " : " << endl;
		for (int i = 0; i < artistResult.size(); i++) {
			cout << artistResult[i]->getTitle() << endl;
		}
	}
	else {
		cout << "Not Found" << endl;
	}


	return 0;
}