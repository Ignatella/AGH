#pragma once

#include <vector>
#include <iostream>
#include <random>

enum Nukleotyp
{
	A = 'A', // adeine
	G = 'G', // guanine
	C = 'C', // citozine
	T = 'T', // thymine
	U = 'U'	 // uracil
};

class RNA
{
private:
	std::vector<Nukleotyp> _v;

public:
	RNA(std::vector<Nukleotyp> v) : _v(v){};
	RNA(const RNA &rna) : _v(rna._v){};

	RNA *get_RNA() { return new RNA(*this); };

	RNA &mutate()
	{
		if (_v.size() == 0)
			return *this;

		auto n = _v[0];

		for (size_t i = 1; i < _v.size(); i++)
			_v[i - 1] = _v[i];

		_v[_v.size() - 1] = n;

		return *this;
	};

	friend std::ostream &operator<<(std::ostream &os, const RNA &rna)
	{
		for (auto &n : rna._v)
			os << (char)n << " ";

		if (rna._v.size() == 0)
			os << "0";

		os << std::endl;

		return os;
	};

	friend std::ostream &operator<<(std::ostream &os, RNA *rna)
	{
		os << *rna;

		return os;
	};
};
