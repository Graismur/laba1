#include "Order.hpp"

Order::Order(const std::string number_payer, const std::string number_getter, int sum):
number_payer(number_payer), number_getter(number_getter),sum(sum){ std::cout << "\n����������� Order\n";}
Order::Order(const Order& o):number_payer(o.number_payer), number_getter(o.number_getter),sum(o.sum){ std::cout << "\n����������� ����������� Order\n";}
Order::~Order(){}
/*������� � ������� ��� number_payer*/
std::string& Order::NumberPayer() {return number_payer; }
/*������� � ������� ��� number_getter*/
std::string& Order::NumberGetter() {return number_getter; }
/*������� � ������� ��� sum*/
int& Order::Sum(){return sum; }

std::istream& operator >>(std::istream& in, Order& o){
	if(!(in >> o.number_payer >> o.number_getter >> o.sum)){//���� ������������ ����, �������� ����������
		throw Exception("������������ ����");
	}
	return in;
}
std::ostream& operator <<(std::ostream& out, const Order& o){
	out << "\n��������� ���� �����������������: " << o.number_payer
		 << "\n��������� ���� ����������: " << o.number_getter
		 << "\n�����: " <<o.sum;
    return out;
}

Order& Order::operator =(const Order& o){
	number_payer = o.number_payer;
	number_getter = o.number_getter;
	sum = o.sum;
	return *this;
}
