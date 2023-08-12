#include <iostream>

using namespace std;

class Matrix{
	private:
		int rows, cols;
		
		
	public:
		int arr[4][4];		
		void get()
		{
			cout << "Input number of rows and columns: ";
			cin >> rows >> cols; 
			cout << "Enter all the elements: ";
			for (int i=0;i<rows;i++)
			{
				for (int j=0; j<cols; j++)
				{
					cin >> arr[i][j];
					
				}
			}
		}
		
		void display()
		{
			for (int i=0; i<rows; i++)
			{
				for (int j=0; j<cols; j++)
				{
					cout << arr[i][j] << " " ;	
				}
				cout << endl;
			} 
		}
		
		friend void dot(Matrix m1, Matrix m2);
};

void dot(Matrix m1, Matrix m2)
{
	int *msum;
	msum=(int *)calloc(m1.rows*m1.cols, sizeof(int));

	for (int i=0;i<m1.rows;i++)
			{
				for (int j=0; j<m2.cols; j++)
				{
					msum[i+j]+= (m1.arr[i][j]) * (m2.arr[i][j]);
				}
			}
		
	cout << "Output: " << endl;
	for (int i=0; i<m1.rows;i++)
	{
		for (int j=0;j<m2.cols;j++)
		{
			cout << msum[i+j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	Matrix m1, m2;
	m1.get(); m2.get();
	cout << "First matrix: " << endl;
	m1.display();
	cout << "Second matrix: " << endl;
	m2.display();
	dot(m1, m2);
	return 0;
}
