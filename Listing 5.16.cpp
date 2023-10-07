//Listing 5.16


#include<bits/stdc++.h>
using namespace std;

class Matrix
 {
  	private:

	int rows; int cols;

	int **ptr;

	public:

		Matrix (int, int );
		Matrix (Matrix &);

		~Matrix ();



	friend istream & operator >> ( istream &, Matrix &);

	friend ostream & operator << (ostream &, Matrix &);
 



	Matrix operator + (Matrix & );

	Matrix operator - (Matrix & );
	Matrix operator * (Matrix & );
	Matrix operator = (Matrix & );
 //	Matrix& operator=(const Matrix& other);
 	
void transpose (Matrix &);
};


//definition of parameterized constructor

 Matrix::Matrix (int m, int n)
{

	rows =m;

	cols =n;

	ptr= new int* [m];

	for (int i=0; i<m; i++) 
{
ptr [i]= new int[n];

	}
}


//definition of the copy constructor

Matrix::Matrix (Matrix &m)
{
rows = m.rows;

cols= m.cols;

 ptr = new int* [rows] ;

for (int i = 0; i < rows; i++ )

	ptr[i]= new int[cols];

for (int i = 0; i < rows; i++)
	 for (int j=0; j < cols; j++)

			ptr[i][j]=m.ptr[i][j]; 
}
// definition of friend function to overload >> operator

istream & operator >>(istream &din, Matrix &mat)
{
for (int i = 0; i < mat.rows; i++)
 { for (int j=0; j < mat.cols; j++)
  { din>> mat.ptr[i][j];
}
}

return din;
}
// definition of friend function to overload <<< operator
 ostream & operator << (ostream &dout, Matrix &mat)
 {
   for (int i = 0; i < mat.rows; i++) {

		for (int j = 0; j< mat.cols; j++) {

	dout << setw(5)<< mat.ptr[i][j];
}
dout << endl;
}
return dout;
}
//member function to add two matrices
Matrix Matrix::operator + (Matrix &mat) 
{

	Matrix temp (rows, cols);

	for (int i = 0; i < rows; i++) {

	for (int j=0; j < cols; j++) {

	temp.ptr[i][j]= ptr[i][j] + mat.ptr[i][j];
}
}
return temp;
}
// member function to subtract one matrix from another
 Matrix Matrix:: operator  - (Matrix &mat)
 {
 	Matrix temp (rows,cols);
 	for(int i=0; i< rows; i++)
	  { for (int j=0; i< cols; j++) 
		  { temp.ptr[i][j] =ptr[i][j] -mat.ptr[i][j];
}
}
return temp;
}
//member function to multiply two matrices

 Matrix Matrix::operator * (Matrix &mat)
{

Matrix temp (rows, cols);
 int i, j, k, tt;

for (i=0; i < rows; i++)
 { for (i=0; i < cols; j++)
  {
   tt = 0;

	for (k = 0; k < rows; k++)
	 { tt += ptr[i] [k] * mat.ptr[k][j];
}
temp.ptr[i][j] = tt;
}
}
	return temp;
}

 Matrix Matrix::operator =  (Matrix &m)
 //Matrix& Matrix::operator=(const Matrix& other) {

 {
 for (int i = 0; i < rows; i++) {

	for (int j=0; j<cols; j++) {

		ptr[i][j]= m.ptr[i][j];
	}
}
return *this;
}
//member function to find the transpose of a matrix 
//Matrix& Matrix::transpose =(const Matrix& m)
void Matrix::transpose (Matrix &m)
{
	int i, j;

	for (i=0; i <rows; i++) {

		for(j=0; j <cols; j++){
	
			ptr[j][i] = m.ptr[i][j];

		}
	}
}

//definition of destructor 

Matrix :: ~Matrix()
{

	for (int i = 0; i < rows; i++) {

	delete ptr[i]; 
}
	delete ptr;
}

int main()	
	//main prgm
{

	int m, n, p, q;


cout<<"Enter size of matrix A as m n; ";
cin>>m>>n;
cout << "Enter size of matrix B as p q: ";
 cin >> p >> q;





Matrix A(m, n), B(p,q), C(n,m);

	cout << "Enter" << m*n << "elements of matrix A row-wise" << endl;
	cin >> A;

	cout << "Enter" << p*q << " elements of matrix B row-wise" << endl;
	cin>> B;

	C.transpose (A);

	cout << "Transpose (A)" << endl;
	cout << C; 
	
	if (m == p && n == q )
	 {

		C= A+B;
		cout << endl << "A + B" <<endl<< endl;
		cout << C; 
		
		
		C = A-B;
		cout <<endl<< "A - B" << endl<< endl;
		cout << C;

} else {

	cout <<endl<< "Addition & Difference is not feasible" << endl << endl;
}

if ( n == p )
 { 
 	Matrix D (m,q);

	D = A * B;

	cout <<endl<< "A*B" << endl << endl;
	 cout << D;
	  } else
	   { 
	   cout <<endl<< "Product AxB is not feasible" <<endl<< endl;
	}
	return 0;
}
}
}



