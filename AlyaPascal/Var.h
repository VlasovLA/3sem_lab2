#pragma once
#include <string>

enum Type
{
	_int, _double, _bool, _string, const_int, const_double, const_bool, const_string, count
};

class Var
{
public:
	static Var* Assign(std::string v);
	Type type;
};

class _Int : Var
{
public:
	int value;
	_Int(int v)
	{
		value = v;
		type = _int;
	}
	_Int()
	{
		value = 0;
		type = _int;
	}
	explicit operator int() const
	{
		return value;
	}
	explicit operator double() const
	{
		return value;
	}
	explicit operator bool() const
	{
		if (value != 0)
			return true;
		return false;
	}
};

class _Double : Var
{
public:
	double value;
	_Double(double v)
	{
		value = v;
		type = _double;
	}
	_Double()
	{
		value = .0;
		type = _double;
	}
	explicit operator double() const
	{
		return value;
	}
};

class _Bool : Var
{
public:
	bool value;
	_Bool(bool v)
	{
		value = v;
		type = _bool;
	}
	_Bool()
	{
		value = false;
		type = _bool;
	}
	explicit operator bool() const
	{
		return value;
	}
	explicit operator int() const
	{
		if (value)
			return 1;
		return 0;
	}
};

class _String : Var
{
public:
	std::string value;
	_String(std::string v)
	{
		value = v;
		type = _string;
	}
	_String()
	{
		value = ' ';
		type = _string;
	}
	explicit operator std::string() const
	{
		return value;
	}
};

Var* Var::Assign(std::string v)
{
	if (v[0] == '\'')
	{
		v.erase(0, 1);
		int f = 0;
		if (((f = v.find("'", f)) != std::string::npos) && (v[f] == v.back()))
		{
			v.erase(f, 1);
		}
		else
		{
			throw "what a twist!";
		}

		_String* temp = new _String(v);
		return (Var*)temp;
	}

	if (v == "false")
	{
		_Bool* temp = new _Bool(false);
		return (Var*)temp;
	}
	if (v == "true")
	{
		_Bool* temp = new _Bool(true);
		return (Var*)temp;
	}

	try
	{
		if (v.find('.', 1) != -1)
		{
			_Double* temp = new _Double(stod(v));
			return (Var*)temp;
		}

		_Int* temp = new _Int(stoi(v));
		return (Var*)temp;
	}
	catch(int)
	{
		throw "what a twist!";
	}
}
