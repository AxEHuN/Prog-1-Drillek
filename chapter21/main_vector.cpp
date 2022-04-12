#include "../GUI/std_lib_facilities.h"
using namespace std;
struct Item {
	string name;
	int iid;
	double value;
};
	ostream& operator<<(ostream& os, const Item it)
	{
		return os << it.name << '\t' << it.iid << '\t' << it.value;

	}

	istream &operator>>(istream& is, Item& it)
	{
		string a;
		int b;
		double c;
		is >> a >> b >> c;
		Item it2 {a, b, c};
		it = it2;
		return is;
	}

	struct cmp_by_name{
		bool operator()(const Item& a, const Item& b){return a.name < b.name;}
	};
	struct cmp_by_iid{
		bool operator()(const Item& a, const Item& b){return a.iid < b.iid;}
	};
	


int main()
{
	string fname ="data.txt";
	ifstream ifs (fname);
	if (!ifs) throw runtime_error("A file nem olvashato: " + fname);

	vector<Item> it;
	for (Item it2;ifs >> it2;) it.push_back(it2);
	cout << "Adatok: " << endl;
	for (auto x : it) cout << x << endl;
	cout << "Sort by name: " << endl;
	for (auto x : it) cout << x << endl;
	sort(it.begin(), it.end(), cmp_by_name());
	cout << "Sort by id: " << endl;
	sort(it.begin(), it.end(), cmp_by_name());




}


