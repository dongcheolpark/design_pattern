#include <iostream>
#include <string>

using namespace std;

class product {
public:
	virtual void use(){};
};

class factory {
public:
	product* create(string owner) {
		product *p = createproduct(owner);
		return p;
	}
protected:
	virtual product* createproduct(string owner){return NULL;};
};

class bonuscard : public product {
private:
	const string USED_MSG = "의 추가카드를 사용합니다.";
	string owner;
public:
	bonuscard(string owner) {
		this->owner = owner;
	}
	void use() {
		cout<<owner<<USED_MSG<<endl;
	}
};

class creditcard : public product {
private:
	const string USED_MSG = "의 신용카드를 사용합니다.";
	string owner;
public:
	creditcard(string owner) {
		this->owner = owner;
	}
	void use() {
		cout<<owner<<USED_MSG<<endl;
	}
};

class cardfactory : public factory {
protected:
	product * createproduct(string owner) {
		return new bonuscard(owner);
	}
};

int main() {
	factory* f = new cardfactory();
	product * card1 = f->create("홍길동");
	product * card2 = f->create("홍길동2");
	card1->use();
	card2->use();
	delete card1,card2,f;
}