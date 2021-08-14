#include <iostream>
#include <string>

using namespace std;

class SearchStrategy {
public:
	virtual void search() {}
};

class SearchStrategyAll : public SearchStrategy {
	void search() {
		cout<<"SEARCH ALL"<<endl;
	}
};
class SearchStrategyImage : public SearchStrategy {
	void search() {
		cout<<"SEARCH Image"<<endl;
	}
};
class SearchStrategyNews : public SearchStrategy {
	void search() {
		cout<<"SEARCH News"<<endl;
	}
};
class SearchStrategyMaps : public SearchStrategy {
	void search() {
		cout<<"SEARCH Maps"<<endl;
	}
};

class myprogram {	
private:
	searchButton * searchbutton;
public:
	myprogram() {
		searchbutton = new searchButton(this);
	}

	void setModeAll() {
		searchbutton->setSearchStrategy(new SearchStrategyAll());
	}
	void setModeImage() {
		searchbutton->setSearchStrategy(new SearchStrategyImage());
	}
	void setModeMaps() {
		searchbutton->setSearchStrategy(new SearchStrategyMaps());
	}
	void setModeNews() {
		searchbutton->setSearchStrategy(new SearchStrategyNews());
	}

	void testProgram() {
		setModeAll();
		searchbutton->onClick();
		setModeImage();
		searchbutton->onClick();
		setModeMaps();
		searchbutton->onClick();
		setModeNews();
		searchbutton->onClick();
	}
};

class searchButton {
private:
	myprogram * Myprogram;
	SearchStrategy * searchstrategy;
public:
	searchButton(myprogram * _Myprogram) {
		searchstrategy = NULL;
		Myprogram = _Myprogram;
	}

	void setSearchStrategy(SearchStrategy * _searchstrategy) {
		if(searchstrategy != NULL) {
			delete searchstrategy;
		}
		searchstrategy = _searchstrategy;
	}

	void onClick() {
		searchstrategy->search();
	}

};

int main() {
	myprogram * myprog = new myprogram();
	myprog->testProgram();
}