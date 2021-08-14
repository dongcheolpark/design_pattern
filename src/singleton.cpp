#include <iostream>
#include <string>

using namespace std;

class Settings {
private:
	Settings() {}
	string text = "hello,world!";
public:
	static Settings * getSettings() {
		static Settings * instance = new Settings();
		return instance;
	}
	void setSettings(string str) {
		text = str;
	}
	void print_text() {
		cout<<text<<endl;
	}
};

class firstpage {
private:
	Settings * set = NULL;
public:
	firstpage() {
		set = Settings::getSettings();
	}
	void change_set_text() {
		set->print_text();
		set->setSettings("change text");
	}
};

class secondpage {
private:
	Settings * set = NULL;
public:
	secondpage() {
		set = Settings::getSettings();
	}
	void print() {
		set->print_text();
	}
};

int main() {
	firstpage a;
	secondpage b;
	a.change_set_text();
	b.print();
}
