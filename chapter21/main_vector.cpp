#include "../GUI/std_lib_facilities.h"
using namespace std;
struct Item {
	string name;
	int iid;
	double value;
};
	ostream& operator<<(ostream& os, const Item it)
	{
		os << it.name << '\t' << it.iid << '\t' << it.value;
		return os;

	}

	istream& operator>>(istream& is, Item& it)
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
	struct cmp_by_value_dec{
		bool operator()(const Item& a, const Item& b){return a.value > b.value;}
	};

	class cmp_by_name_val{
    string name;
public:
    cmp_by_name_val(const string& str) : name{str} { }
    bool operator()(const Item& i) const { return i.name == name; }
};

class cmp_by_iid_val {
    int iid;
public:
    cmp_by_iid_val(int id) : iid{id} { }
    bool operator()(const Item& i) const { return i.iid == iid; }
};

	class Smaller_than {
    double val;
public:
    Smaller_than(double vv) : val{vv} { }
    bool operator()(const Item& i) const { return i.value < val; }
};

template<typename T>
void print(const T& c, char sep = ' ')
{
    for (const auto& a : c)
        std::cout << a << sep;
    std::cout << '\n';
}
	


int main()
{
	string fname ="data.txt";
	ifstream ifs (fname);
	if (!ifs) throw runtime_error("A file nem olvashato: " + fname);

	vector<Item> it;
	list<Item> ls; copy(it.begin(), it.end(), ls.begin());

	for (Item it2;ifs >> it2;) it.push_back(it2);
	cout << "Adatok: " << endl;
	for (auto x : it) cout << x << endl;
	cout << endl;

	cout << "Sort by name: " << endl;
	sort(it.begin(), it.end(), cmp_by_name());
	print(it, '\n');
	cout << endl;

	cout << "Sort by id: " << endl;
	sort(it.begin(), it.end(), cmp_by_iid());
	print(it, '\n');
	cout << endl;

	cout << "Sort by value(decreasing): " << endl;
	sort(it.begin(), it.end(), cmp_by_value_dec());
	print(it, '\n');
	cout << endl;
	Item temp{"horse shoe", 99, 1.34};

	it.insert(find_if(it.begin(), it.end(), Smaller_than(temp.value)), temp);


    temp = Item{"Canon S400", 9988, 499.95};
    it.insert(find_if(it.begin(), it.end(), Smaller_than(temp.value)), temp);
    cout << "Item erase(Elek, Dsa):" << endl;
    it.erase(std::find_if(it.begin(), it.end(), cmp_by_name_val("Elek")));
    it.erase(std::find_if(it.begin(), it.end(), cmp_by_name_val("Dsa")));
    print(it, '\n');
    cout << endl;

    cout << "Item erase(4,5):" << endl;
    it.erase(std::find_if(it.begin(), it.end(), cmp_by_iid_val(4)));
    it.erase(std::find_if(it.begin(), it.end(), cmp_by_iid_val(5)));
    print(it, '\n');
    cout << endl;


    cout << "List: " << endl;
    print(ls, '\n');
    ls.sort([](const Item& a, const Item& b) { return a.name < b.name; });
    ls.sort([](const Item& a, const Item& b) { return a.iid < b.iid; });
    ls.sort([](const Item& a, const Item& b) { return a.value > b.value; });

 	return 0;
}


