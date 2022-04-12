#include "../GUI/std_lib_facilities.h"
using namespace std;
template<typename T>
void my_cout (const T& tt,const string& s)
{
	cout << s << endl;
	for (auto& elem : tt) cout << elem <<  " ";
		cout << endl;
}

template<typename T>
void increase(T& t, int num) {for (auto& elem : t)elem+=num;}

template<typename Iter1, typename Iter2>
Iter2 my_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (Iter1 i = f1; i!=e1;i++) *f2++ = *i;
		return f2;
}


int main()
{
	const int s = 10;
	int t[s] = {0,1,2,3,4,5,6,7,8,9};
	vector<int> vi;
	list<int> li;

	for (int i=0;i<s;i++) vi.push_back(i);
	for (int i=0;i<s;i++) li.push_back(i);

	cout << "Tömb: " << endl;
	for (auto elem : t) cout << elem << " ";
	cout << endl;
	cout << "Vector: " << endl;
	for (auto elem : vi) cout << elem << " ";
	cout << endl;
	cout << "Lista: " << endl;
	for (auto elem : li) cout << elem << " ";
	cout << endl;
	

	//Manuálisan.
	for (int i=0;i<s;i++) t[i]+=2;
	for (int i=0;i<s;i++) vi[i]+=3;
	for (auto& elem : li) elem+=5;
	cout << endl;
	cout << "Tömb: " << endl;
	for (auto elem : t) cout << elem << " ";
	cout << endl;
	cout << "Vector: " << endl;
	for (auto elem : vi) cout << elem << " ";
	cout << endl;
	cout << "Lista: " << endl;
	for (auto elem : li) cout << elem << " ";
	cout << endl;
	
	int *t2 = t;
	vector<int> vi2 = vi;
	list<int> li2 = li;

	cout << "------------------------------- " << endl;
	//Fügvény
	my_cout(t, "Tömb: ");
	my_cout(vi, "Vector: ");
	my_cout(li, "Lista: ");

	increase(t, 2);
	increase(vi, 3);
	increase(li, 5);
	cout << endl;

	my_cout(t, "Tömb[i]+2: ");
	my_cout(vi, "Vector[i]+3: ");
	my_cout(li, "Lista[i]+5: ");
	cout << "------------------------------- " << endl;

	my_copy(vi2.begin(), vi2.end(),li2.begin());
	my_cout(li2, "Vector-->Lista: ");
	my_copy(li2.begin(), li2.end(),vi2.begin());
	my_cout(vi2, "Lista-->Vector: ");
	cout << "Keresett elem = 3!" << endl;
	vector<int>::iterator pos;
	pos = find(vi2.begin(), vi2.end(),3);
	if (pos != vi2.end()) cout << "Pozició: " << distance(vi2.begin(), pos) << endl;
	else cout << "Nincs ilyen elem!" << endl;

	/*vector<int>::iterator pos2;
	pos2 = find(li2.begin(), li2.end(),27);
	if (pos2 != li2.end()) cout << "Pozició: " << distance(li2.begin(), pos2) << endl;
	else cout << "Nincs ilyen elem!" << endl;*/


	
}