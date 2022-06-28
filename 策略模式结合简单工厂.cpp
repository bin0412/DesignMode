#include <iostream>
#include <string>
using namespace std;

class Strategy {
public:
	virtual void Algorithm() { }
private:

};

class ConcreteStrategyA : public Strategy {
public:
	void Algorithm() {
		cout << "Ëã·¨A" << endl;
	}
private:

};
class ConcreteStrategyB : public Strategy {
public:
	void Algorithm() {
		cout << "Ëã·¨B" << endl;
	}
private:

};
class ConcreteStrategyC : public Strategy {
public:
	void Algorithm() {
		cout << "Ëã·¨C" << endl;
	}
private:

};

class Context {
public:
	Strategy* strategy;
	Context(string type) {
		if (type._Equal("A")) {
			this->strategy = new ConcreteStrategyA();
		}
		else if (type._Equal("B")) {
			this->strategy = new ConcreteStrategyB();
		}
		else {
			this->strategy = new ConcreteStrategyC();
		}
	}
	void Algorithm() {
		strategy->Algorithm();
	}
private:


};



int main() {
	Context context("B");
	context.Algorithm();

	return 0;
}