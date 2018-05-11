/*
Author: Jula Marius
Date: 11/5/18
Description:Define a class called Record that stores the data related to a melody (artist, title, duration). An
abstract class (Playlist) contains as private variable a pointer to an array of records. The
pointer is initialized in the constructor by a memory allocation process (the number of records
is defined by the user). The class contains accessor and mutator methods for each of a record’s
fields and an abstract method (pure virtual) that sorts the records array according to a criteria
coded in the received parameter (1=sorting by title, 2=sorting by artist, 3=sorting by duration).
The abstract method is implemented inside another class (PlaylistImplementation) that
inherits the Playlist class.
In the main() function, instantiate the PlaylistImplementation class and initialize and use all
the related data and methods.
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX 100
#include <iostream>
using namespace std;

class Record
{
public:
	char* artist;
	char* title;
	double duration;

public:
	Record()
	{
		artist = new char[50];
		title = new char[50];
	}
	~Record() {
		delete[] artist;
		delete[] title;
	}
	
};
class Playlist
{
public:
	int length;
	Record * records;
public:
	
	Playlist()
	{
		int newLength;
		cout << "\nEnter the array size:";
		cin >> newLength;
		records = new Record[newLength];
		length = newLength;
	}
	void setArtist(char*, int);
	void setTitle(char*, int);
	void setDuration(double, int);
	char* getArtist(int);
	char* getTitle(int);
	double getDuration(int);
	virtual void sort_array(int) = 0;
	~Playlist();
};

void Playlist::setArtist(char * text, int i)
{
	strcpy(records[i].artist, text);
}

void Playlist::setTitle(char *text, int i)
{
	strcpy(records[i].title, text);
}

void Playlist::setDuration(double n, int i)
{
	records[i].duration = n;
}

char * Playlist::getArtist(int i)
{
	return records[i].artist;
}

char * Playlist::getTitle(int i)
{
	return records[i].title;
}

double Playlist::getDuration(int i)
{
	return records[i].duration;
}

Playlist::~Playlist()
{
	delete[] records;
}

class PlaylistImplementation :public Playlist {
public:
	void sort_array(int);
};

void PlaylistImplementation::sort_array(int i)
{
	int j, k;
	Record aux;
	if (i == 1) {
		for (j = 0; j < this->length - 1; j++) {
			for (k = j + 1; k < this->length; k++) {
				if (strcmp(this->getTitle(j), this->getTitle(k))>0) {
					aux = *(records + j);
					*(records+ j) = *(records+ k);
					*(records + k) = aux;
				}
			}
		}
	}
	else if (i == 2) {
		for (j = 0; j < this->length - 1; j++) {
			for (k = j + 1; k < this->length; k++) {
				if (strcmp(this->getArtist(j), this->getArtist(k))>0) {
					aux = *(records + j);
					*(records + j) = *(records + k);
					*(records + k) = aux;
				}
			}
		}
	}
	else if (i == 3) {
		for (j = 0; j < this->length - 1; j++) {
			for (k = j + 1; k < this->length; k++) {
				if (this->getDuration(j) > this->getDuration(k)) {
					aux = *(records + j);
					*(records + j) = *(records + k);
					*(records + k) = aux;
				}
			}
		}
	}
}

int main() {
	PlaylistImplementation obj;
	int i, time, mode;
	char *text;
	text = new char[50];
	for (i = 0; i < obj.length; i++) {
		cout << "Enter title of the song: ";
		cin >> text;
		obj.setTitle(text, i);
		cout << "Enter name of the artist: ";
		cin >> text;
		obj.setArtist(text, i);
		cout << "Enter duration of the song: ";
		cin >> time;
		obj.setDuration(time, i);
	}
	cout << "\n Enter 1 to sort by title, 2 to sort by artist,3 to sort by duration: ";
	cin >> mode;
	obj.sort_array(mode);
	for (i = 0; i < obj.length; i++) {
		cout << obj.getTitle(i) << " " << obj.getArtist(i) << " " << obj.getDuration(i) << std::endl;
	}
	cin.ignore();
	cin.get();
	delete[] text;
}