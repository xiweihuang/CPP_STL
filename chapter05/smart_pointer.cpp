// #include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

void example1()
{
	shared_ptr<string> pNico(new string("nico"));
	shared_ptr<string> pJutta(new string("jutta"));

	(*pNico)[0] = 'N';
	pJutta->replace(0, 1, "J");

	vector<shared_ptr<string>> whoMadeCoffee;
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);
	whoMadeCoffee.push_back(pJutta);
	whoMadeCoffee.push_back(pNico);

	for (const auto &ptr : whoMadeCoffee) {
		// printf("%s\n", (*ptr).c_str());
		cout << *ptr << endl;
	}
	cout << endl;

	*pNico = "Nicolai";

	for (const auto &ptr : whoMadeCoffee) {
		// printf("%s\n", (*ptr).c_str());
		cout << *ptr << endl;
	}
	cout << endl;

	cout << "use_count: " << whoMadeCoffee[0].use_count() << endl;
	// cout << pJutta.use_count() << endl;  // 1 ?
}

void example2()
{
	// 定义一个deleter
	auto deleter = [](string *p){
		cout << "delete " << *p << endl;
		delete p;
	};
	
	shared_ptr<string> pNico(new string("nico"), deleter);
	pNico = nullptr;
	cout << "after nullptr..." << endl;
}

void example3()
{
	auto deleter = [](int* p){
		delete[] p;
	};
	shared_ptr<int> p1(new int[10], deleter);

	shared_ptr<int> p2(new int[10], default_delete<int[]>());

	unique_ptr<int, void(*)(int*)> p(new int[10], [](int* p){ delete[] p; });
}

int main()
{
	// example1();
	// example2();
	example3();
	return 0;

}