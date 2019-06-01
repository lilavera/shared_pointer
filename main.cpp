#include <iostream>
using namespace std;
template <typename T>
class Temp
{
	int TEMP;
	public:
		//конструктор
		Temp(){TEMP=25;}
		//функция показа на экран
		void TempFunction(){
			cout<<"TEMP = "<<TEMP<<"\n\n";
		}
		//функция установки значения
		void TempSet(int T){
			TEMP=T;
		}
};

class SmartPointer
{
	// Инкапсулированный указатель
	Temp*ptr;
	//счётчик копий
	int count_copy;

public:
	//конструктор
	SmartPointer (Temp*p=NULL){
		//записываем 0 при создании копий нет
		count_copy=0;
		ptr=p;
	}
	// конструктор копирования
	SmartPointer (const SmartPointer&obj){
		//создается копия - увеличиваем счётчик
		ptr=obj.ptr;
		count_copy++;

		cout<<"\n~Copy an Object\n";
	}

	SmartPointer ( SmartPointer &&obj)

	{

	  /*  ptr=obj.ptr;
	    obj.ptr=nullptr;*/

	    cout<<"\n~Move an Object\n";
	}

	//перегрузка оператора равно
	SmartPointer operator=(const SmartPointer&obj){
		//создается копия - увеличиваем счётчик
		ptr=obj.ptr;

		count_copy++;
		//возвращаем сам объект для ситуации a=b=c
		return *this;


	}



	SmartPointer operator =(SmartPointer&&obj)

	{
	    if(&obj==this)


	}


	  return *this;


	  }

	// уничтожение объекта
	~SmartPointer(){
		//если объект есть и копий нет
		if(ptr!=NULL&&count_copy==0){
			cout<<"\n~Delete Object\n";
			//уничтожаем объект
			delete[]ptr;
		}
		//в противном случае(уничтожается копия)
		else{
			//уменьшаем счётчик
			count_copy--;
			cout<<"\n~Delete Copy\n";
		}

	}
	//перегрузка селектора
	Temp* operator->(){
		return ptr;
	}

};
 main(){
	//создаем объект
	Temp*main_ptr=new Temp;
	//инициализируем этим объектом умный указатель
	SmartPointer PTR(main_ptr);
	//проверяем работу умного указателя
	PTR->TempSet(100);
	PTR->TempFunction();
	// создаем копию (работа конструктора копирования)
	SmartPointer PTR2=PTR;
	PTR = move(PTR2);
}
