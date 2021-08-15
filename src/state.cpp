#include <iostream>
#include <string>

using namespace std;

class ModeSwitch;


class modestate {
public:
	virtual void toggle(ModeSwitch * _modeswitch) {}
};

class ModeSwitch {
private:
	modestate * Modestate;
public:
	ModeSwitch() {
		Modestate = new modestate();
	}
	~ModeSwitch() {
		delete Modestate;
	}
	void setstate(modestate * _modestate) {
		delete Modestate;
		Modestate = _modestate;
	}
	void onSwitch() {
		Modestate->toggle(this);
	}
};

class ModeStateDark : public modestate {
public:
	void toggle(ModeSwitch *);
};

class ModeStateLight : public modestate {
public:
	void toggle(ModeSwitch *);
};

void ModeStateDark::toggle(ModeSwitch * _modeswitch) {
		cout<<"From Dark to Light"<<endl;
		_modeswitch->setstate(new ModeStateLight());
}

void ModeStateLight::toggle(ModeSwitch * _modeswitch) {
		cout<<"From Dark to Light"<<endl;
		_modeswitch->setstate(new ModeStateLight());
}

int main() {
	ModeSwitch * modeSwitch = new ModeSwitch();
	modeSwitch->onSwitch();
	modeSwitch->onSwitch();
	modeSwitch->onSwitch();
	modeSwitch->onSwitch();
	modeSwitch->onSwitch();
	modeSwitch->onSwitch();
}