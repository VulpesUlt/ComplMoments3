#include <iostream>
#include <list>
#include <vector>
#include <iomanip>

using namespace std;

// Task 1 =========================================================

void addAverage(list<double>& list)
{
	double result = 0;
	for (auto it : list)
	{
		result += it;
	}
	list.push_back(result/list.size());
}

// Task 2 =========================================================

class Matrix
{
public:
	Matrix() {};
	Matrix(uint32_t size)
	{
		matrix_m.reserve(size);
		matrix_m.assign(size, vector<double>(size));
	}
	Matrix(const Matrix& other) { matrix_m = other.matrix_m; }
	void operator= (const Matrix& other) { matrix_m = other.matrix_m; }
	
	Matrix(Matrix&& other) { matrix_m = move(other.matrix_m); }
	void operator= (Matrix&& other) {matrix_m = move(other.matrix_m); }

	~Matrix() {}
	
	void init()
	{
		for (int j = 0; j < matrix_m.size(); j++)
			for (int i = 0; i < matrix_m[j].size(); i++)
				matrix_m[j][i] = static_cast<double>(rand() % 100) / 10;
	}
	void print() const
	{
		for (auto it_line : matrix_m)
		{	
			for (auto it_col : it_line)
				cout << it_col << " ";
			cout << endl;
		}
	}

	double determinant() const
	{
		auto matrix = matrix_m;
		double det{ 1 };

		for (int iter = 0; iter < matrix.size() - 1; iter++)
			for (int i = iter + 1; i < matrix.size(); i++)
				for (int j = matrix[i].size() - 1; j > -1; j--)
					matrix[i][j] -= matrix[iter][j] * matrix[i][iter] / matrix[iter][iter];

		for (int i = 0; i < matrix.size(); i++)
			det *= matrix[i][i];
		return det;
	}

private:
	vector<vector<double>> matrix_m;

};

// Task 3 =========================================================

class MyIter
{
public:
	MyIter() { Ptr = nullptr; }
	MyIter(int& val) { Ptr = &val; }
	int operator*() { return *Ptr; }
	void operator=(int val) { *Ptr = val; }
	void operator++() { Ptr++; }
	void operator--() { Ptr--; }
	bool operator==(MyIter& other) { return *Ptr == *other; }
	bool operator!=(MyIter& other) { return *Ptr != *other; }
private:
	int* Ptr;
};

int main()
{
	// Task 1 =========================================================
	cout << "task 1" << endl;
	
	list<double> list{ 0.123f, 0.48956f, 0.894623123f, 0.84561 };
	
	for (auto it : list)
		cout << it << " ";
	cout << endl;

	addAverage(list);
	
	for (auto it : list)
		cout << it << " ";
	cout << endl;

	// Task 2 =========================================================
	cout << endl << "task 2" << endl;

	Matrix matrix(4);
	matrix.init();
	cout << " Determinant: " << matrix.determinant() << endl;

	// Task 3 =========================================================
	cout << endl << "task 3" << endl;

	int Arr[5] = { 0, 5, 7, 9, 10 };
	for (MyIter it1 : Arr)
		cout << *it1 << " ";
	cout << endl;

	return 0;
}