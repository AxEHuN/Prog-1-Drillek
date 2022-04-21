#include "../GUI/std_lib_facilities.h"

using namespace std;

template<typename T, typename U>
void print(const map<T,U> &m)
{
	cout << "MAP: "<< endl;
	cout << "---------------------------------------" << endl;

	for (const auto& i : m) cout << i.first << " -  " << i.second << endl;
	cout << "---------------------------------------" << endl << endl;
}

void read(map<string, int>& mp, int size){
	cout << endl;
	string str="";
	int i = 0;
	cout << "Add meg az adatokat [string-int] :" << endl;
	while (mp.size() < size)
	{
		cin >> str >> i;
		mp.insert(make_pair(str, i));
	}

}

int summ(map<string, int> &mp)
{
	int total = 0;
	for (const auto & p : mp)
	{
		total+=p.second;
	}
	return total;
}
int main()
{
	map<string, int> mp;
	//Random generált szavak
	mp["harmony"]=1;
	mp["competition"]=2;
	mp["harsh"]=3;
	mp["check"]=4;
	mp["celebration"]=5;
	mp["emotion"]=6;
	mp["bill"]=7;
	mp["discount"]=8;
	mp["bathtub"]=9;
	mp["shot"]=10;

	print(mp);
	cout << "Erase Map" << endl;
	mp.erase(mp.begin(), mp.end());

	print(mp);
	int sz;
	cout << "Méret: " ; cin >> sz;
	read(mp, sz);
	print(mp);

	int sum = summ(mp);
	cout <<"Integer Sum of map: "<< sum << endl;

	map<int, string> mis;
	for (const auto &i : mp)
		mis[i.second] = i.first;
	print(mis);
}