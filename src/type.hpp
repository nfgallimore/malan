#pragma once

#include <iosfwd>
#include <vector>

#include "printer.hpp"

class Name;

// Represents types in the programming language using 
// a virtual and discriminated union hybrid implementation
// to still support get_kind()

class Type
{
public:
	enum Kind
	{
		bool_type,
		int_type,
		ref_type,
		fun_type,
		float_type
	};

	// Returns the kind of the type.
	Kind get_kind() const { return m_kind; }

	// Prints a type
	virtual void print(Printer &p) const = 0;

	// Prints the name of class the memory addresses associated with the type
	virtual void debug(Printer &p) const = 0;

	// Prints the type as a symbolic expression
	virtual void to_sexpr(Printer &p) const = 0;

protected:
	// Constructs the type to have kind `k`.
	Type(Kind k) : m_kind(k) { }

private:
  	Kind m_kind;
};

// Represents the string `bool`.
class Bool_type : public Type
{
public:
	Bool_type()
		: Type(bool_type)
	{ }
	void print(Printer &p) const override;
	void debug(Printer &p) const override;
	void to_sexpr(Printer &p) const override;
};

// Represents the string `int`.
class Int_type : public Type
{
public:
	Int_type()
		: Type(int_type)
	{ }
	void print(Printer &p) const override;
	void debug(Printer &p) const override;
	void to_sexpr(Printer &p) const override;
};

// Represents the string `float`.
class Float_type : public Type
{
public:
	Float_type()
		: Type(float_type)
	{ }
	void print(Printer &p) const override;
	void debug(Printer &p) const override;
	void to_sexpr(Printer &p) const override;
};

// Represents strings of the form `ref t` where `t` is a type.
class Ref_type : public Type
{
public:
  	Ref_type(Type* t)
    	: Type(ref_type), m_ref(t)
  	{ }
	void print(Printer &p) const override;
	void debug(Printer &p) const override;
	void to_sexpr(Printer &p) const override;
	Type* get_ref_type() const { return m_ref; }

private:
  Type* m_ref;
};

// Represents strings of the form `func f:(x:int, y:int) -> bool`
// 	where `f` is the function name, 
// 	`x` is a parameter of type int, 
// 	`y` is a parameter of type int,
// 	and the func returns a bool.
class Fun_type : public Type
{
public:
    Fun_type(std::vector<Type*> params, Type* ret)
        : Type(fun_type), m_params(params), m_ret_type(ret)
    { }
    Fun_type(Type* ret)
        : Type(fun_type), m_params(0), m_ret_type(ret)
    { }
    void print(Printer &p) const override;
    void debug(Printer &p) const override;
    void to_sexpr(Printer &p) const override;
    std::vector<Type*> get_params() const { return m_params; }
    Type* get_return_type() const { return m_ret_type; }
    
private:
    std::vector<Type*> m_params;
    Type* m_ret_type;
};


// Operators

std::ostream& operator<<(std::ostream& os, Type const& t);


// Operations

/// Returns true when `a` and `b` denote the same type.
bool equal(Type const* a, Type const* b);
