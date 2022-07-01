#include <iostream>
#include <string>
using namespace std;

/************************ װ��ģʽ ģ�� Begin ************************/
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
void test() {
	ConcreteComponent* c = new ConcreteComponent();
	ConcreteDecoratorA* d1 = new ConcreteDecoratorA();
	ConcreteDecoratorB* d2 = new ConcreteDecoratorB();

	d1->SetComponent(c);
	d2->SetComponent(d1);
	d2->Operation();
	d1->Operation();
}
/************************ װ��ģʽ ģ�� End ************************/


/************************ װ��ģʽ �������� Begin ************************/
class Person {
public:
	Person() {}
	Person(string name) {
		this->name = name;
	}
	virtual void Show() {
		cout << "װ���" << name << endl;
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
		cout << "��T�� ";
		__super::Show();
	}
};
class BigTrouser :public Finery {
public:
	void Show() {
		cout << "��� ";
		__super::Show();
	}
};

class Sneakers : public Finery {
public:
	void Show() {
		cout << "��Ь ";
		__super::Show();
	}
};

class BusinessSuit : public Finery {
public:
	void Show() {
		cout << "��װ ";
		__super::Show();
	}
};
class Necktie : public Finery {
public:
	void Show() {
		cout << "��� ";
		__super::Show();
	}
};
class LeatherShoes : public Finery {
public:
	void Show() {
		cout << "ƤЬ ";
		__super::Show();
	}
};

void test2() {
	Person* jb = new Person("����");
	cout << endl << "��һ��װ��: ";
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

