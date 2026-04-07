#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Music Class
class Music {
private:
	string title;
	string artist;
	string album;
	int year;

public:
	Music(string title, string artist, string album, int year) {
		this->title = title;
		this->artist = artist;
		this->album = album;
		this->year = year;
	}

	string getTitle() { return title; }
	string getArtist() { return artist; }
	string getAlbum() { return album; }
	int getYear() { return year; }

};

//Music Streaming Service Class
class MusicStreamingService {
private:
	string serviceName;
	vector<Music> musicList;

public:
	MusicStreamingService(string name) {
		this->serviceName = name;
	}

	//음악 추가 기능
	void addMusic(string title, string artist, string album, int year) {
		Music newMusic(title, artist, album, year);
		musicList.push_back(newMusic);
		cout << "\"" << title << "\" by \"" << artist << "\" is added to " << serviceName << endl;
	}

	//제목으로 음악 찾기
	Music* searchByTitle(string title) {
		for (int i = 0; i < musicList.size(); i++) {
			if (musicList[i].getTitle() == title) {
				return &musicList[i];
			}
		}
		return NULL;
	}

	//가수로 음악 찾기
	vector<Music*> searchByArtist(string artist) {
		vector<Music*> result;
		for (int i = 0; i < musicList.size(); i++) {
			//artist와 musicList에 있는 artist가 같으면 result에 추가
			if (musicList[i].getArtist() == artist) {
				result.push_back(&musicList[i]);
			}
		}
		return result;
	}

};