#include <iostream>
using namespace std;
class Matrix
{
    private:
        int grid[3][3];
    public:
        Matrix()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i][j] = 0;
                }
            }
        }
        Matrix(int (&cp)[3][3])
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i][j] = cp[i][j];
                }
            }
        }
        void dispMatrix()
        {
            for (int i = 0; i < 3; i++)
            {
                cout << endl;
                for (int j = 0; j < 3; j++)
                {
                    cout << grid[i][j] << " ";
                }
            }
        }
        int gelem(int i, int j)
        {
            return grid[i][j];
        }
        Matrix operator ++()
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i][j]++;
                }
            }
            return *this;
        }
        void operator +=(Matrix &op2)
        {
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i][j] += op2.gelem(i, j);
                }
            }
        }
        void operator *=(Matrix &op2)
        {
            int prod[3][3];
            
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    prod[i][j] = 0;
                        
                    for (int k = 0; k < 3; k++)
                    {
                        prod[i][j] += grid[i][k] * op2.gelem(k, j);
                    }
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    grid[i][j] = prod[i][j];
                }
            }
        }
};
int main()
{
    int arr[3][3] = {{1, 2, 3}, {1, 2, 3}, {1, 2, 3}};
    
    Matrix m1(arr), m2(arr);
    (++m1).dispMatrix();
    
    cout << endl << endl;
    m1 += m2;
    m1.dispMatrix();
    cout << endl << endl;
    m1 *= m2;
    m1.dispMatrix();
    cout << endl;
    return 0;
}