#include "../std_lib_facilities.h"

template<typename T>
struct s
	{
	private:
		T val;
	public:
		s(T t): val{t} {}

		s& operator=(const T& t) {val=t; return *this;}
		T& get();
		const T& get() const  {return val;};
		void set(T new_t) { val = new_t; }
	};

	template<typename T>
	void readv(T& vl) {cin >> vl;}

	template<typename T>
	T& s<T> :: get(){return val;}
	//const T& s<T> :: get() const {return val;}

	//kiiratas
	template<typename T>
	ostream& operator<<(ostream& os, vector<T>& v)
	{
		os << "[";
		int i=0;
		while(i<v.size())
		{
			os << v[i] << (i < v.size()-1 ? ", " : " ");
			i++;
		}
		os << "]" << endl;
		return os;
	}

	//bekeres
	template <typename T>
	istream& operator>>(istream& is, s<T>& v)
	{
		T vv;
		cin >> vv;
		if (!is) return is;
		v = vv;
		return is;
	}
	template<typename T> void read_val(T& v) {cin >> v;}

int main()
{
	s<int> in(420); cout << in.get() << endl;
	s<char> ch('*'); cout << ch.get() << endl;
	s<double> db(2.14);	cout << db.get() << endl;
	s<string> st("fortwenty"); cout << st.get() << endl;
	s<vector<int>> invc({421,422,423});
	vector<int> i = invc.get();
	for (auto x : i) cout << x << endl;
	cout <<"-----------------------" << endl;
	in.set(024);
	ch.set('/');
	db.set(4.20);
	st.set("rotációs kapa");
	i[0]=69;
	invc.set(i);

	cout << in.get() << endl;
	cout << ch.get() << endl;
	cout << db.get() << endl;
	cout << st.get() << endl;
	for (auto x : i) cout << x << endl;
	cout <<"-----------------------" << endl;
	
	in = 1;
	ch = '-';
	db=0.24;
	st="Vicc Elek";
	i[1]=35;
	invc=i;

	cout << in.get() << endl;
	cout << ch.get() << endl;
	cout << db.get() << endl;
	cout << st.get() << endl;
	for (auto x : i) cout << x << endl;
	cout <<"-----------------------" << endl;

	cout << in;

	return 0;
}