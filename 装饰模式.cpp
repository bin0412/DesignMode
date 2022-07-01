#include <iostream>
#include <string>
using namespace std;


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

int main() {
	ConcreteComponent* c = new ConcreteComponent();
	ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
	ConcreteDecoratorB* d2 = new ConcreteDecoratorB();

	d1->SetComponent(c);
	d2->SetComponent(d1);
	d2->Operation();
	d1->Operation();

	return 0;
}