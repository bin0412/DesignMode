#include <iostream>
#include <string>
#include <sstream>
/******************* 简单工厂 Begin ********************/

//class CashSuper {// 抽象类
//public:
//	virtual double acceptCash(double money) = 0;
//};
//
//class CashNomal : public CashSuper {
//public:
//	double acceptCash(double money) {
//		return money;
//	}
//};
//
//class CashRebate : public CashSuper {
//public:
//	CashRebate(std::string moneyRebate) {
//		std::istringstream iss(moneyRebate);
//		iss >> this->moneyRebate;
//	}
//	double acceptCash(double money) {
//		return money * moneyRebate;
//	}
//private:
//	double moneyRebate = 0.1;
//};
//
//class CashReturn : public CashSuper {
//public:
//	CashReturn(std::string moneyCondition, std::string moneyReturn) {
//		std::stringstream ss(moneyCondition);
//		ss >> this->moneyCondition;
//		ss << moneyReturn;
//		ss >> this->moneyReturn;
//	}
//	double acceptCash(double money) {
//		double result = money;
//		if (money >= moneyCondition) {
//			result = money - floor(money / moneyCondition) * moneyReturn;
//		}
//		return result;
//	}
//private:
//	double moneyCondition = 0.0;
//	double moneyReturn = 0.0;
//};
//class CashFactory {
//public:
//	static CashSuper* createCashAccept(std::string type) {
//		CashSuper* cs = nullptr;
//		if ("正长收费" == type) {
//			cs = new CashNomal();
//		}
//		else if ("满300返100" == type) {
//			cs = new CashReturn("300", "100");
//		}
//		else if ("打八折" == type) {
//			cs = new CashRebate("0.8");
//		}
//		return cs;
//	}
//};

/******************* 简单工厂 End ********************/

/******************* 策略模式 Begin ********************/

class Strategy {
public:
	virtual void AlgorithmInterface() { }
};

class ConcreteStrategyA : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "算法A实现" << std::endl;
	}
};

class ConcreteStrategyB : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "算法B实现" << std::endl;
	}
};

class ConcreteStrategyC : public Strategy {
public:
	void AlgorithmInterface() {
		std::cout << "算法C实现" << std::endl;
	}
};

class Context {
public:
	Strategy* strategy = nullptr;
	Context(Strategy* strategy) { // 传入策略对象进行初始化
		this->strategy = strategy;
	}
	void ContextInterface() { // 根据具体的策略对象，调用其算法的方法
		strategy->AlgorithmInterface();
	}
};

/******************* 策略模式 End ********************/

/******************* 策略模式 - 商场系统实现 Begin ********************/

class CashSuper {
public:
	virtual double acceptCash(double money) { return 0; }
};
class CashNormal : public CashSuper {
public:
	double acceptCash(double money) {
		return money;
	}
};

class CashRebate : public CashSuper {
public:
	double rebate;
	CashRebate(double rebate) {
		this->rebate = rebate;
	}
	double acceptCash(double money) { 
		return money * rebate;
	}
};

class CashReturn : public CashSuper {
public:
	double condition;
	double ret;
	CashReturn(double condition, double ret) {
		this->condition = condition;
		this->ret = ret;
	}
	double acceptCash(double money) { 
		auto result = money;
		if (result >= condition) {
			result = money - floor(money / condition) * ret;
		}
		return result;
	}
};

//class CashContext {
//public:
//	CashSuper* cs = nullptr;
//	CashContext(CashSuper* csuper) {
//		this->cs = csuper;
//	}
//	double GetResult(double money) {
//		return cs->acceptCash(money);
//	}
//};

/******************* 策略模式 - 商场系统实现 End ********************/



/******************* 策略模式结合简单工厂 - 商场系统实现 Begin ********************/

class CashContext { // 将原本需要在客户端实现的代码放到了构造函数中 : 注意与纯策略模式代码的区别
public:
	CashSuper* cs = nullptr;
	CashContext(std::string type) {
		CashSuper* csuper{ nullptr };
		if ("正常收费" == type) {
			csuper = new CashNormal();
		}
		else if ("满300返100" == type) {
			csuper = new CashReturn(300, 100);
		}
		else if("打8折" == type) {
			csuper = new CashRebate(0.8);
		}
		cs = csuper;
	}
	double GetResult(double money) {
		return cs->acceptCash(money);
	}
};

/******************* 策略模式结合简单工厂 - 商场系统实现 Begin ********************/



int main() {
	/******************* 简单工厂 Begin *******************/

	/*CashSuper *csuper = CashFactory::createCashAccept("打八折");
	auto money = 300;
	auto totalPrice = csuper->acceptCash(money);
	std::cout << totalPrice << std::endl;*/

	/******************* 简单工厂 End *******************/

	/******************* 策略模式 Begin *******************/

	//Context* context;
	//context = new Context(new ConcreteStrategyA());
	//context->ContextInterface();

	//context = new Context(new ConcreteStrategyB());
	//context->ContextInterface();

	//context = new Context(new ConcreteStrategyC());
	//context->ContextInterface();

	/******************* 策略模式 End *******************/


	/******************* 策略模式应用 Begin *******************/

	//CashContext* cashContext = nullptr;
	//std::string promotion = "满300返100";
	//if ("正常收费" == promotion) {
	//	cashContext = new CashContext(new CashNormal());
	//}
	//else if ("满300返100" == promotion) {
	//	cashContext = new CashContext(new CashReturn(300, 100));
	//}
	//else if("打8折" == promotion) {
	//	cashContext = new CashContext(new CashRebate(0.8));
	//}

	//std::cout << cashContext->GetResult(800);
	/******************* 策略模式应用 End *******************/



	/******************* 策略模式、简单工厂应用 Begin *******************/

	CashContext* cashContext = new CashContext("满300返100");
	double money = 800;
	std::cout << cashContext->GetResult(money) << std::endl;
	/******************* 策略模式、简单工厂应用 End *******************/
	return 0;
}