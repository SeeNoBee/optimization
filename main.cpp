#include "Matrix.h"
#include <iostream>
#include <omp.h>

using namespace std;

void mult(unsigned int size, const float** a, const float** b, float **result)
{
	#pragma omp parallel for
	for (unsigned int i = 0; i < size; ++i)
		for (unsigned int k = 0; k < size; ++k)
			#pragma ivdep
			for (unsigned int j = 0; j < size; ++j)
				result[i][j] += a[i][k] * b[k][j];
}

int main(int argc, char** argv)
{
	unsigned int size = 4000;
	if (argc > 1)
		size = atoi(argv[1]);

	Matrix a(size, SEQUENCE);
	Matrix b(size, SEQUENCE);
	Matrix result(size, ZERO);

	double time = omp_get_wtime();
	mult(size, a.data, b.data, result.data);
	time = omp_get_wtime() - time;
	cout << "time: " << time << endl;
	return 0;
}