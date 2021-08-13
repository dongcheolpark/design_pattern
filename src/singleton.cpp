#include <iostream>
#include <string>

using namespace std;

class Settings {
private:
	Settings() {}
	static Settings * set;
	string text = "hello,world!";
public:
	static Settings * getSettings() {
		if(set == NULL) {
			set = new Settings();
		}
		return set;
	}
};

class firstpage {
private:
	Settings * set = NULL;
public:
	firstpage() {
	}
};

int main() {

}
