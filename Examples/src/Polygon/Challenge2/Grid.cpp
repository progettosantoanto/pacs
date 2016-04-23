#include "Grid.hpp"
#include <string>

using namespace Geometry;
using namespace std;

Grid::Grid (ifstream & file) 
{
	//leggo la prima riga
	string str1, str2, aux;
	int tipo;
	unsigned int Npoly{0}, Nvert{0};
	getline (file,aux);
	stringstream ss {aux};
	getline (ss,str1,' ');
	Nvert = stoi(str1);
	getline (ss,str2,' ');
	Npoly = stoi(str2);
	Vect.reserve (Nvert);
	AbstractPol.reserve (Npoly);

	//leggo le altre righe
	for (unsigned int i=0; i<Nvert; i++)
	{
		getline (file, aux);
		stringstream ss (aux);
		getline (ss,str1,' ');
		getline (ss,str1,' ');
		getline (ss,str2,' ');
		Vect[i].set (stod(str1),stod(str2));
	}
	for (unsigned int i=0; i<Npoly; i++)
	{
		getline (file, aux);
		stringstream ss (aux);
		getline (ss,str1,' ');
		getline (ss,str2,' ');
		tipo = stoi(str2);
		Vertices vv;
		while (getline(ss,str1,' '))
		{
			vv.push_back ( Vect[stoi(str1)] );
		}
			if (tipo==0)
			{
				Triangle t(vv);
				//t.showMe();
				AbstractPol.push_back (make_shared<Triangle> (t));
			} else if (tipo==1)
			{
				Square s(vv);
				//s.showMe();
				AbstractPol.push_back (make_shared<Square> (s));
			} else {
				Polygon p(vv);
				//p.showMe();
				AbstractPol.push_back (make_shared<Polygon> (p));
			}
	}
}

void Grid::getArea()
{
	double area{0};
	for (auto i=0; i<AbstractPol.size(); i++)
	{
		area += AbstractPol[i]->area();
		//cout << i <<": x="<< Vect[i].x()<<" y=" << Vect[i].y() << endl;
	}
	cout << "Area: " << area << endl;
}