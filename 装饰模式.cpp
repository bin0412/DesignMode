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
		cout << "�������Ĳ���" << endl;
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
		__super::Operation(); // ��������ԭComponent��Operation()�� ��ִ�б���Ĺ��ܣ���addedState���൱�ڶ�ԭComponent����������
		addedState = "New State";
		cout << "����װ�ζ���A�Ĳ���" << endl;
	}
private:
	string addedState;
};

class ConcreteDecoratorB : public Decorator {
public:
	void Operation() {
		__super::Operation();
		AddedBehavior();
		cout << "����װ�ζ���B�Ĳ���" << endl;
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