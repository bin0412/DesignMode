#include <iostream>
#include <string>
class Operation;
class OperationAdd;
class OperationSub;
class OperationMul;
class OperationDiv;
class OperationFactory;

class Operation {
public:
	Operation() {

	}
	double getNumberA() const {
		return _numberA;
	}
	double getNumberB() const {
		return _numberB;
	}
	void setNumberA(double num) {
		_numberA = num;
	}
	void setNumberB(double num) {
		_numberB = num;
	}
	virtual double getResult() {
		std::cout << "Operation类" << __FUNCTION__ << std::endl;
		return 0;
	}
private:
	double _numberA = 0;
	double _numberB = 0;
};

class OperationAdd : public Operation {
public:
	double getResult() {
		return getNumberA() + getNumberB();
	}
};

class OperationSub : public Operation {
public:
	double getResult() {
		return getNumberA() - getNumberB();
	}
};

class OperationMul : public Operation {
public:
	double getResult() {
		return getNumberA() * getNumberB();
	}
};

class OperationDiv : public Operation {
public:
	double getResult() {
		double result = 0;
		if (getNumberB() == 0) {
			throw "除数不能为0";
		}
		return getNumberA() / getNumberB();
	}
};

class OperationFactory {
public:
	static Operation* createOperate(std::string operate) {
		Operation* oper = nullptr;
		if (operate == "+") {
			oper = dynamic_cast<Operation*>(new OperationAdd());
		}
		else if (operate == "-") {
			oper = dynamic_cast<Operation*>(new OperationSub());
		}
		else if (operate == "*") {
			oper = dynamic_cast<Operation*>(new OperationMul());
		}
		else if(operate == "/") {
			oper = dynamic_cast<Operation*>(new OperationDiv());
		}
		return oper;
	}
private:
};


int main() {
	Operation* oper;
	oper = OperationFactory::createOperate("+");
	oper->setNumberA(10);
	oper->setNumberB(20);
	std::cout << oper->getResult();
	return 0;
}