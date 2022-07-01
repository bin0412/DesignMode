#include <iostream>
#include <string>
using namespace std;

/************************ 装饰模式 模型 Begin ************************/
class Component {
public:
	virtual void Operation() {}
};

class ConcreteComponent : public Component {
public:
	void operation() {
		cout << "具体对象的操作" << endl;
	}
};

class Decorator : public Component {
public:
	void SetComponent(Component* component) {
		this->component = component;
	}
	void Operattion() {
		if (component != nullptr) {
			component->Operation();
		}
	}
protected:
	Component* component;
};

class ConcreteDecoratorA : public Decorator {
public:
	void Operation() {
		__super::Operation(); // 首先运行原Component的Operation()， 再执行本类的功能，如addedState，相当于对原Component进行了修饰
		addedState = "New State";
		cout << "具体装饰对象A的操作" << endl;
	}
private:
	string addedState;
};

class ConcreteDecoratorB : public Decorator {
public:
	void Operation() {
		__super::Operation();
		AddedBehavior();
		cout << "具体装饰对象B的操作" << endl;
	}

private:
	void AddedBehavior() {}
};
void test() {
	ConcreteComponent* c = new ConcreteComponent();
	ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
	ConcreteDecoratorB* d2 = new ConcreteDecoratorB();

	d1->SetComponent(c);
	d2->SetComponent(d1);
	d2->Operation();
	d1->Operation();
}
/************************ 装饰模式 模型 End ************************/


/************************ 装饰模式 穿搭例子 Begin ************************/
class Person {
public:
	Person() {}
	Person(string name) {
		this->name = name;
	}
	virtual void Show() {
		cout << "装扮的" << name << endl;
	}
private:
	string name;
};

class Finery : public Person {
public:
	void Decorate(Person* component) {
		this->component = component;
	}
	void Show() {
		if (component != nullptr) {
			component->Show();
		}
	}
protected:
	Person* component;
};

class TShirts :public Finery {
public:
	void Show() {
		cout << "大T恤 ";
		__super::Show();
	}
};
class BigTrouser :public Finery {
public:
	void Show() {
		cout << "垮裤 ";
		__super::Show();
	}
};

class Sneakers : public Finery {
public:
	void Show() {
		cout << "球鞋 ";
		__super::Show();
	}
};

class BusinessSuit : public Finery {
public:
	void Show() {
		cout << "西装 ";
		__super::Show();
	}
};
class Necktie : public Finery {
public:
	void Show() {
		cout << "领带 ";
		__super::Show();
	}
};
class LeatherShoes : public Finery {
public:
	void Show() {
		cout << "皮鞋 ";
		__super::Show();
	}
};

void test2() {
	Person* jb = new Person("蒋斌");
	cout << endl << "第一种装扮: ";
	Sneakers* pqx = new Sneakers();
	BigTrouser* kk = new BigTrouser();
	TShirts* dtx = new TShirts();

	pqx->Decorate(jb);
	kk->Decorate(pqx);
	dtx->Decorate(kk);
	dtx->Show();

}
int main() {
	test2();
	return 0;
}

