#include <iostream>
#include <string>
#include <sstream>
// �ü򵥹���ʵ��
class CashSuper {// ������
public:
	virtual double acceptCash(double money) = 0;
};

class CashNomal : public CashSuper {
public:
	double acceptCash(double money) {
		return money;
	}
};

class CashRebate : public CashSuper {
public:
	CashRebate(std::string moneyRebate) {
		std::istringstream iss(moneyRebate);
		iss >> this->moneyRebate;
	}
	double acceptCash(double money) {
		return money * moneyRebate;
	}
private:
	double moneyRebate = 0.1;
};

class CashReturn : public CashSuper {
public:
	CashReturn(std::string moneyCondition, std::string moneyReturn) {
		std::stringstream ss(moneyCondition);
		ss >> this->moneyCondition;
		ss << moneyReturn;
		ss >> this->moneyReturn;
	}
	double acceptCash(double money) {
		double result = money;
		if (money >= moneyCondition) {
			result = money - floor(money / moneyCondition) * moneyReturn;
		}
		return result;
	}
private:
	double moneyCondition = 0.0;
	double moneyReturn = 0.0;
};
class CashFactory {
public:
	static CashSuper* createCashAccept(std::string type) {
		CashSuper* cs = nullptr;
		if ("�����շ�" == type) {
			cs = new CashNomal();
		}
		else if ("��300��100" == type) {
			cs = new CashReturn("300", "100");
		}
		else if ("�����" == type) {
			cs = new CashRebate("0.8");
		}
		return cs;
	}
};


class Strategy {
public:
	virtual void AlgorithmInterface() { }
};

class ConcreteStrategyA : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "�㷨Aʵ��" << std::endl;
	}
};

class ConcreteStrategyB : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "�㷨Bʵ��" << std::endl;
	}
};

class ConcreteStrategyC : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "�㷨Cʵ��" << std::endl;
	}
};

class Context {
public:
	Strategy* strategy = nullptr;
	Context(Strategy* strategy) { // ������Զ�����г�ʼ��
		this->strategy = strategy;
	}
	void ContextInterface() { // ���ݾ���Ĳ��Զ��󣬵������㷨�ķ���
		strategy->AlgorithmInterface();
	}
};

int main() {
	CashSuper *csuper = CashFactory::createCashAccept("�����");
	auto money = 300;
	auto totalPrice = csuper->acceptCash(money);
	std::cout << totalPrice << std::endl;

	Context* context;
	context = new Context(new ConcreteStrategyA());
	context->ContextInterface();

	context = new Context(new ConcreteStrategyB());
	context->ContextInterface();

	context = new Context(new ConcreteStrategyC());
	context->ContextInterface();

	return 0;
}