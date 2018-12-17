#pragma once
#include "Order.hpp"

//массив с динамическим добавлением и удалением элементов
template<typename T>
class Array{
private:
	T *data;
	unsigned _size;
public:
	Array();
	~Array();
	void Add(const T & sign);//добавление в конец массива
	T & operator[](unsigned index);//получение элемента по индексу
	unsigned Size();//размер
	void Remove(unsigned index);//удаление
	void Clear();//очищаение массива
	void Sort(bool (*cmp)(T& a, T& b));//сортировка
	void PrintBy(const std::string& value, bool (*cmp)(T& a, const std::string& b));//поиск
};

template<typename T>
void Array<T>::PrintBy(const std::string& value, bool (*cmp)(T& a, const std::string& b)){
	bool flag = true;
   for(int i = 0; i < _size; ++i){
		if(cmp(data[i], value)){
		   cout << data[i] << '\n'; 
		   flag = !flag;
		}
   }
   if(flag) std::cout << "Пусто";
}

template<typename T>
void Array<T>::Sort(bool (*cmp)( T& a, T& b)){
    int i, n = _size;
	do {
	int nn = 0;
	for (i = 1; i < n; ++i)
		if (cmp(data[i-1], data[i])) {
		T tmp = data[i-1];
		data[i-1] = data[i];
		data[i] = data[i-1];
		nn = i;
		}
	n = nn;
	} while (n);
}

 template<typename T>
Array<T>::Array():data(nullptr), _size(0){ cout << "\nконструктор Array";}
 template<typename T>
Array<T>::~Array(){ delete[] data; cout << "\nдеструктор Array"; }

template<typename T>
void Array<T>::Add(const T & sign){//добавление в конец массива
	T *temp;//буфер
	try{//обрабатываем исключение
	   temp = new T[_size + 1];
	}
	catch(...){
		throw Exception("Ошибка выделения памяти");
	}
	//копируем в буфер
	for(unsigned i = 0; i < _size; ++i){
		temp[i] = data[i];
	}
	temp[_size] = sign;
	//копируем в поле
	delete[] data;
	data = temp;
	++_size;
}

template<typename T>
T & Array<T>::operator[](unsigned index){//получение элемента по индексу
	 if(index >= _size){
		throw Exception("Индекс вне границ массива");
	 }
	 return data[index];
}

template<typename T>
void Array<T>::Remove(unsigned index){//удаление элемента
	if(index >= _size){
		throw Exception("Индекс вне границ массива");
	}
	T *temp;//буфер
	try{//обрабатываем исключение
	   temp = new T[_size + 1];
	}
	catch(...){
		throw Exception("Ошибка выделения памяти");
	}
	//копируем в буфер, ропуская не нужный
	for(unsigned i = 0; i < _size; ++i){
		if(i != index){
			temp[i] = data[i];
		}
	}
	//копируем в поле
	delete[] data;
	data = temp;
	--_size;
}
template<typename T>
unsigned Array<T>::Size(){ return _size; }

template<typename T>
void Array<T>::Clear(){
	_size = 0;
	delete[] data;
	data = nullptr;
}