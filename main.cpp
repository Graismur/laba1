#include "Order.hpp"
#include <iostream>
#include "Array.h"

using namespace std;

bool ccmp(Order& a, Order& b){//���������� ��� ����������
		return a.NumberPayer() > b.NumberPayer();
}
bool fcmp(Order& a, const std::string& b){//���������� ��� ����������
		return a.NumberPayer() == b;
}

int main(){
	setlocale(LC_ALL, "");
	int cnt = 8; //���������� ������
	Order tmp;
	Array<Order> data;
	int checker;
	//����
	while(true){
		cout << "\n1. ����\n2. �����\n";
		if(!(cin >> checker)){//���� ������������ ����, �� ���������� ��
		 continue;
		}  
		if(checker == 1){
			//��������� ������ � �������
			cout << "[� �����������] [� ����������] [�����]\n";
			for(int i =0; i < cnt; ++i){
				try{
					cin >> tmp;
					data.Add(tmp);
				}	  //������������ ����������
				catch(const Exception& e){
					cout << "\n" << e.what() << "\n";
					--i;//���������� i ����� ��� ���������� �����
				}
			}
			data.Sort(ccmp);
		}	
		else if(checker == 2){
			cout << "������� �����: ";
			string val;
			cin >> val;
			data.PrintBy(val, fcmp);
		}
	}

}
