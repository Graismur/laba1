#include "Order.hpp"
#include <iostream>
#include "Array.h"

using namespace std;

bool ccmp(Order& a, Order& b){//компаратор для сортировки
		return a.NumberPayer() > b.NumberPayer();
}
bool fcmp(Order& a, const std::string& b){//компаратор для сортировки
		return a.NumberPayer() == b;
}

int main(){
	setlocale(LC_ALL, "");
	int cnt = 8; //количество счетов
	Order tmp;
	Array<Order> data;
	int checker;
	//меню
	while(true){
		cout << "\n1. Ввод\n2. Поиск\n";
		if(!(cin >> checker)){//если некорректный ввод, то пропускаем всё
		 continue;
		}  
		if(checker == 1){
			//считываем данные о поездах
			cout << "[№ плательщика] [№ получателя] [сумма]\n";
			for(int i =0; i < cnt; ++i){
				try{
					cin >> tmp;
					data.Add(tmp);
				}	  //обрабатываем исключение
				catch(const Exception& e){
					cout << "\n" << e.what() << "\n";
					--i;//откатываем i назад для повторного ввода
				}
			}
			data.Sort(ccmp);
		}	
		else if(checker == 2){
			cout << "Введите номер: ";
			string val;
			cin >> val;
			data.PrintBy(val, fcmp);
		}
	}

}
