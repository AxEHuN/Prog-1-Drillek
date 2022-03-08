#include "std_lib_facilities.h"

struct Person{
public:
	Person () {};
	Person	(string fname, string lname, int age);

	string get_fname() const {return fname;} 
	string get_lname() const {return lname;} 
	int get_age(){return age;}

private:
	string fname="Default";
	string lname="Default";
	int age=0;
};

	Person::Person(string fname, string lname, int age) : fname{fname}, lname{lname}, age{age}
	{
		if (age>150 || age <0) error("Bad age");
		
		string fullname = fname+lname;
		for (int i=0;i<fullname.length();i++){
			if (fullname[i]==';' ||
				fullname[i]==':' ||
				fullname[i]=='"' ||
				fullname[i]== '\'' ||
				fullname[i]=='[' ||
				fullname[i]==']' ||
				fullname[i]=='*' ||
				fullname[i]=='&' ||
				fullname[i]=='^' ||
				fullname[i]=='%' ||
				fullname[i]=='$' ||
				fullname[i]=='#' ||
				fullname[i]=='@' ||
				fullname[i]=='!'
				) {error("Invalid character in name"); break;}
		}

	}

	// ki iratas
	ostream& operator<<(ostream& os, Person &p){
		return os << p.get_fname() << ' ' << p.get_lname() << '\t' << p.get_age();
	}
	//bekérés
	istream& operator>>(istream& is, Person &p){
		string a, b;
		int c;
		is >> a >> b >> c;
		p = Person(a,b,c);
		return is;
	}


int main()
{
	vector<Person> p;
	Person p2;

	cout << "Adja meg a szemelyek szamat: "; int sz=1; cin >> sz;

	for (int i = 0;i<sz;i++)
	{
		cin >> p2;
		p.push_back(p2);
	}

	for (Person p3 : p) cout << p3 << endl; 
		
return 0;
}