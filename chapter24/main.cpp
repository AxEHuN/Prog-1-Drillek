#include "../GUI/std_lib_facilities.h"
#include "Matrix.h"
#include "MatrixIO.h"
#include <complex>


void my_sqrt()
{
    int val;
    cin >> val;
    if (val < 0)
        std::cout << "No square root\n";
    else
       cout << "Square of " << val << " is " <<sqrt(val) << '\n';
}

int main()
{
	cout << "Sizeof Variables: "<< endl;
	cout << "Char: " << sizeof(char) << endl <<
			"Short: "<< sizeof(short) << endl <<
			"Int: " << sizeof(int) << endl <<
			"Long: " << sizeof(long) << endl <<
			"Float: " << sizeof(float) << endl <<
			"Double: " << sizeof(double) << endl <<
			"Int*: " << sizeof(int*) << endl <<
			"Double*: " << sizeof(double*) << endl << endl;

	Numeric_lib::Matrix<int> a(10);
    Numeric_lib::Matrix<int> b(100);
    Numeric_lib::Matrix<double> c(10);
    Numeric_lib::Matrix<int,2> d(10,10);
    Numeric_lib::Matrix<int,3> e(10,10,10);

    cout << "Sizeof matrix: " << endl
              << "Matrix<int>(10): " << sizeof(a) << endl
              << "Matrix<int>(100): " << sizeof(b) << endl
              << "Matrix<double>(10): " << sizeof(c) << endl
              << "Matrix<int,2>(10,10): " << sizeof(d) << endl
              << "Matrix<int,3>(10,10,10): " << sizeof(e) << endl << endl;

    cout << "Number of elements:" << endl
              << "Matrix<int>(10): " << a.size() << endl
              << "Matrix<int>(100): " << b.size() << endl
              << "Matrix<double>(10): " << c.size() << endl
              << "Matrix<int,2>(10,10): " << d.size() << endl
              << "Matrix<int,3>(10,10,10): " << e.size() << endl << endl;
              cout << "Give numbers: " << endl;
        for(int i =0;i<3;i++) my_sqrt();          

  /* std::cout << "Enter 10 floats:\n";
    const int sz = 10;

    Numeric_lib::Matrix<double> md(sz);
    for (int i = 0; i < sz; ++i) cin >> md[i];*/

	//cout << md << endl;

 cout << "[m,n] : ";
    int m, n;
    cin >> m >> n;
    cout << endl;

    Numeric_lib::Matrix<double,2> mult_table(m,n);

    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            mult_table(i,j) = i == 0 || j == 0 ? i + j : i * j;

    for (int i = 0; i < mult_table.dim1(); ++i) {
        for (int j = 0; j < mult_table.dim2(); ++j)
        cout << std::setw(5) << mult_table(i,j);
        cout << '\n';
    }

   /* cout << "Enter 10 complex numbers:\n";
    Numeric_lib::Matrix<std::complex<double>> mcd (10);
    for (int i = 0; i < mcd.size(); ++i) {
        cin >> mcd[i];
    }

       cout << "Total: "
              << std::accumulate(mcd.data(), mcd.data() + mcd.size(),
                 std::complex<double>{})
              << '\n'; */


     cout << "Enter 6 ints for a 2x3 Matrix:\n";
    Numeric_lib::Matrix<int,2> mm (2,3);
    for (int i = 0; i < mm.dim1(); ++i)
        for (int j = 0; j < mm.dim2(); ++j)
          cin >> mm[i][j];

    cout << mm << '\n';
}