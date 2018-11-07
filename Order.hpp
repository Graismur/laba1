#pragma once
#include <string>
#include <iostream>
#include "Exception.hpp"

class Order{
	std::string number_payer;//��������� ���� �����������������
	std::string number_getter;//��������� ���� ����������
	int sum;//������������� �����
public:
	Order(const std::string number_payer = "", const std::string number_getter = "", int sum = 0);
	Order(const Order& o);
	~Order();
	/*������� � ������� ��� number_payer*/
	std::string& NumberPayer();
	/*������� � ������� ��� number_getter*/
	std::string& NumberGetter();
	/*������� � ������� ��� sum*/
	int& Sum();
	/*��������� ����� � ������*/
	friend std::istream& operator >>(std::istream& in, Order& o);
	friend std::ostream& operator <<(std::ostream& out, const Order& o);
	Order& operator =(const Order& o);//�������� ������������
	
};

