#include<iostream>

using namespace std;

class MiClase
{
	public:
	void printMembers();
	friend class OtraClase; //Se usa la palabra friend y se nombra la clase amiga
	private:
	int a;
};

void MiClase::printMembers()
{
	cout<<"El valor de 'a' es: "<<a<<endl;
}

class OtraClase
{
	public:
	void metodoClaseAmiga(int x, MiClase& mc);
};

void OtraClase::metodoClaseAmiga(int x, MiClase& mc)
{
	mc.a = x; //Acceso a un miembro privado del objeto mc de la clase MiClase
}

int main()
{
	MiClase obj;
	OtraClase obj2;
	obj2.metodoClaseAmiga(10, obj);
	obj.printMembers();
	
	return 0;
}