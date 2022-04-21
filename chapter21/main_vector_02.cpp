#include "../GUI/std_lib_facilities.h"


template<typename T>
void print(const T& t, char sep = ' ')
{
	cout << "Vector: "<< endl;
	cout << "---------------------------------------" << endl;

    for (const auto a : t)
        std::cout << a << sep << endl;
    std::cout << '\n';
    cout << "---------------------------------------" << endl << endl;
}
class Less{
    double v;
public:
    Less(double dd) : v{dd} { }

    bool operator()(const double val) { return val < v; }
};

int main()
{

	string fname ="vectordata.txt";
	ifstream ifs (fname);
	if (!ifs) throw runtime_error("A file nem olvashato: " + fname);

	vector<double> vd;
	for (double i ;ifs>> i;) vd.push_back(i);

	print(vd);

	vector<int> vi(vd.size());

	copy(vd.begin(), vd.end(), vi.begin());

	print(vi);

	double sumvd=0.0;
	int sumvi=0;
	for (int i=0;i<vd.size();i++)
	{
		cout << vd[i] << " - " << vi[i] << endl;
		sumvd+=vd[i];
		sumvi+=vi[i];
	}

	cout << "Sum of Vd vector: " << sumvd << endl;
	cout << "Sum of Vi vector: " << sumvi << endl;
	cout << "Diffrence of vd and vi: " << sumvd-sumvi << endl;

	reverse(vd.begin(), vd.end());
	cout << endl;
	cout << "Reverse: "  << endl;
	print(vd);
	auto mean = sumvd/vd.size();
	cout << "Vd mean: " << sumvd/vd.size() << endl;

	vector<double> vd2 (vd.size());

	auto dd = copy_if(vd.begin(), vd.end(), vd2.begin(), Less(mean));
	vd2.resize(distance(vd2.begin(), dd));
	print (vd2);


}