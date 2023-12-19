#include<iostream>

using namespace std;

#define true 1
#define false 0

class OtraClase
{
	bool privateVar; //Acceso privado por defecto
	
	public: //Miembros públicos
	void setPrivateVar(bool newval); //Método Set
	bool getPrivateVar(void); //Método Get
};

void OtraClase::setPrivateVar(bool newval)
{
	privateVar = newval;
}

bool OtraClase::getPrivateVar(void)
{
	return privateVar;
}

int main()
{
	OtraClase obj;
	
	obj.setPrivateVar(true);
	cout<<obj.getPrivateVar()<<endl; //true
	obj.setPrivateVar(false);
	cout<<obj.getPrivateVar()<<endl; //false
		
	return 0;
}