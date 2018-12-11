#pragma once

enum Flag_ZERO
{
	ZERO
};

enum Flag_SEQUENCE
{
	SEQUENCE
};

class Matrix
{
public:
	unsigned int size;
	float **data;

	Matrix(unsigned int _size, Flag_ZERO zeroFlag):
		size(_size)
	{
		data = new float*[size];
		data[0] = new float[size * size];

		for (unsigned int i = 0; i < size; ++i)
		{
			data[i] = data[0] + size * i;
			for (unsigned int j = 0; j < size; ++j)
				data[i][j] = 0.f;
		}
	}

	Matrix(unsigned int _size, Flag_SEQUENCE sequenceFlag) :
		size(_size)
	{
		data = new float*[size];
		data[0] = new float[size * size];

		for (unsigned int i = 0; i < size; ++i)
		{
			data[i] = data[0] + size * i;
			for (unsigned int j = 0; j < size; ++j)
				data[i][j] = static_cast<float>(i * size + j + 1);
		}
	}

	~Matrix()
	{
		delete[] data[0];
		delete[] data;
	}
};
