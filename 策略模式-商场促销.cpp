#include <iostream>
#include <string>
#include <sstream>
// 用简单工厂实现
class CashSuper {// 抽象类
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
		if ("正长收费" == type) {
			cs = new CashNomal();
		}
		else if ("满300返100" == type) {
			cs = new CashReturn("300", "100");
		}
		else if ("打八折" == type) {
			cs = new CashRebate("0.8");
		}
		return cs;
	}
};

int main() {
	CashSuper *csuper = CashFactory::createCashAccept("打八折");
	auto money = 300;
	auto totalPrice = csuper->acceptCash(money);
	std::cout << totalPrice;
	return 0;
}