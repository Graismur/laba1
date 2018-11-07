#include "Order.hpp"

Order::Order(const std::string number_payer, const std::string number_getter, int sum):
number_payer(number_payer), number_getter(number_getter),sum(sum){ std::cout << "\nКонструктор Order\n";}
Order::Order(const Order& o):number_payer(o.number_payer), number_getter(o.number_getter),sum(o.sum){ std::cout << "\nКонструктор копирования Order\n";}
Order::~Order(){}
/*геттеры и сеттеры для number_payer*/
std::string& Order::NumberPayer() {return number_payer; }
/*геттеры и сеттеры для number_getter*/
std::string& Order::NumberGetter() {return number_getter; }
/*геттеры и сеттеры для sum*/
int& Order::Sum(){return sum; }

std::istream& operator >>(std::istream& in, Order& o){
	if(!(in >> o.number_payer >> o.number_getter >> o.sum)){//если некорректный ввод, выбиваем исключение
		throw Exception("Некорректный ввод");
	}
	return in;
}
std::ostream& operator <<(std::ostream& out, const Order& o){
	out << "\nРасчётный счёт налогоплательщика: " << o.number_payer
		 << "\nРасчётный счёт получателя: " << o.number_getter
		 << "\nСумма: " <<o.sum;
    return out;
}

Order& Order::operator =(const Order& o){
	number_payer = o.number_payer;
	number_getter = o.number_getter;
	sum = o.sum;
	return *this;
}
