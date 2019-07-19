#include <iostream>
#include <string>

using namespace std;

class Cpmv
{
public:
	struct Info
	{
		string qcode;
		string zcode;
	};
private:
	Info* pi;
public:
	Cpmv();
	Cpmv(string q, string z);
	Cpmv(const Cpmv& cp);
	Cpmv(Cpmv&& mv) noexcept;
	~Cpmv();
	Cpmv& operator=(const Cpmv& cp);
	Cpmv& operator=(Cpmv&& mv);
	Cpmv operator+(const Cpmv& obj) const;
	void Display() const;
};

Cpmv::Cpmv()
{
	pi = new Info;
}

Cpmv::Cpmv(string q, string z)
{
	pi = new Info;
	pi->qcode = q;
	pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv& cp)
{
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv::Cpmv(Cpmv&& mv) noexcept
{
	pi = mv.pi;
	mv.pi = nullptr;
}

Cpmv& Cpmv::operator=(const Cpmv& cp)
{
	if (this == &cp)
		return *this;
	delete pi;
	pi = new Info;
	pi->qcode = cp.pi->qcode;
	pi->zcode = cp.pi->zcode;
}

Cpmv& Cpmv::operator=(Cpmv&& mv)
{
	pi = mv.pi;
	mv.pi = nullptr;
	return *this;
}

Cpmv Cpmv::operator+(const Cpmv& obj) const
{
	return Cpmv(pi->qcode + obj.pi->qcode, pi->zcode + obj.pi->zcode);
}

void Cpmv::Display() const
{
	cout << "QCode: " << pi->qcode << endl;
	cout << "ZCode: " << pi->zcode << endl;
}

Cpmv::~Cpmv()
{
	delete pi;
}

int main()
{
	Cpmv a[2];//default constructor
	for (int i = 0; i < 2; ++i)
	{
		string qcode;
		string zcode;
		cout << "Enter Qcode " << i << ": ";
		cin >> qcode;
		cout << "Enter Zcode " << i << ": ";
		cin >> zcode;
		Cpmv temp(qcode, zcode);
		a[i] = move(temp);	//move assignment
	}
	for (auto& x : a)
		x.Display();
	Cpmv plus = a[0] + a[1];
	plus.Display();
}
