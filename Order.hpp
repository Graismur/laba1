#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class Order{
	std::string number_payer;//расчётный счёт налогоплательщика
	std::string number_getter;//расчётный счёт получателя
	int sum;//перечисляемая сумма
public:
	Order(const std::string number_payer = "", const std::string number_getter = "", int sum = 0);
	Order(const Order& o);
	~Order();
	/*геттеры и сеттеры для number_payer*/
	std::string& NumberPayer();
	/*геттеры и сеттеры для number_getter*/
	std::string& NumberGetter();
	/*геттеры и сеттеры для sum*/
	int& Sum();
	/*операторы ввода и вывода*/
	friend std::istream& operator >>(std::istream& in, Order& o);
	friend std::ostream& operator <<(std::ostream& out, const Order& o);
	Order& operator =(const Order& o);//опиратор присваивания
	
};

