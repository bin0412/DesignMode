#include <iostream>
#include <string>
#include <sstream>
/******************* �򵥹��� Begin ********************/

//class CashSuper {// ������
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
//		if ("�����շ�" == type) {
//			cs = new CashNomal();
//		}
//		else if ("��300��100" == type) {
//			cs = new CashReturn("300", "100");
//		}
//		else if ("�����" == type) {
//			cs = new CashRebate("0.8");
//		}
//		return cs;
//	}
//};

/******************* �򵥹��� End ********************/

/******************* ����ģʽ Begin ********************/

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

/******************* ����ģʽ End ********************/

/******************* ����ģʽ - �̳�ϵͳʵ�� Begin ********************/

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

/******************* ����ģʽ - �̳�ϵͳʵ�� End ********************/



/******************* ����ģʽ��ϼ򵥹��� - �̳�ϵͳʵ�� Begin ********************/

class CashContext { // ��ԭ����Ҫ�ڿͻ���ʵ�ֵĴ���ŵ��˹��캯���� : ע���봿����ģʽ���������
public:
	CashSuper* cs = nullptr;
	CashContext(std::string type) {
		CashSuper* csuper{ nullptr };
		if ("�����շ�" == type) {
			csuper = new CashNormal();
		}
		else if ("��300��100" == type) {
			csuper = new CashReturn(300, 100);
		}
		else if("��8��" == type) {
			csuper = new CashRebate(0.8);
		}
		cs = csuper;
	}
	double GetResult(double money) {
		return cs->acceptCash(money);
	}
};

/******************* ����ģʽ��ϼ򵥹��� - �̳�ϵͳʵ�� Begin ********************/



int main() {
	/******************* �򵥹��� Begin *******************/

	/*CashSuper *csuper = CashFactory::createCashAccept("�����");
	auto money = 300;
	auto totalPrice = csuper->acceptCash(money);
	std::cout << totalPrice << std::endl;*/

	/******************* �򵥹��� End *******************/

	/******************* ����ģʽ Begin *******************/

	//Context* context;
	//context = new Context(new ConcreteStrategyA());
	//context->ContextInterface();

	//context = new Context(new ConcreteStrategyB());
	//context->ContextInterface();

	//context = new Context(new ConcreteStrategyC());
	//context->ContextInterface();

	/******************* ����ģʽ End *******************/


	/******************* ����ģʽӦ�� Begin *******************/

	//CashContext* cashContext = nullptr;
	//std::string promotion = "��300��100";
	//if ("�����շ�" == promotion) {
	//	cashContext = new CashContext(new CashNormal());
	//}
	//else if ("��300��100" == promotion) {
	//	cashContext = new CashContext(new CashReturn(300, 100));
	//}
	//else if("��8��" == promotion) {
	//	cashContext = new CashContext(new CashRebate(0.8));
	//}

	//std::cout << cashContext->GetResult(800);
	/******************* ����ģʽӦ�� End *******************/



	/******************* ����ģʽ���򵥹���Ӧ�� Begin *******************/

	CashContext* cashContext = new CashContext("��300��100");
	double money = 800;
	std::cout << cashContext->GetResult(money) << std::endl;
	/******************* ����ģʽ���򵥹���Ӧ�� End *******************/
	return 0;
}