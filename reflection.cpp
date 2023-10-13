#include <iostream>
#include <cassert>
#include <vector>

enum type
{
	none_type = 0,
	int_type,
	float_type,
	char_type,
	bool_type,
};

struct Variable
{
	const char *name = 0;
	void *data = 0;
	int type = 0;

	void assign(double number);
	double read();

};

void Variable::assign(double number)
{

	switch (type)
	{
	case int_type:
	*((int *)data) = number;

	break;
	case float_type:
	*((float *)data) = number;

	break;
	case char_type:
	*((char *)data) = number;


	break;
	case bool_type:
	*((bool *)data) = number;


	default:
	assert(0);
	break;
	}

}

double Variable::read()
{

	switch (type)
	{
	case int_type:
	return *((int *)data);

	break;
	case float_type:
	return *((float *)data);

	break;
	case char_type:
	return *((char *)data);


	break;
	case bool_type:
	return *((bool *)data);


	default:
	assert(0);
	break;
	}

	return 0;
}

std::vector<Variable> variables;


//int test = 2;
//variables.push_back({"test", &test, int_type});

#define DECLARE(TYPE, NAME, VALUE) TYPE NAME = VALUE; \
variables.push_back({ # NAME, & NAME, TYPE ## _type})

int main()
{

	DECLARE(int, test, 2);
	DECLARE(float, test2, 1.7);

	std::cout << "Variables:\n\n";

	for (auto &v : variables)
	{
		std::cout << v.name << " = " << v.read() << "\n";
	}


	std::cin.get();
	return 0;
}
