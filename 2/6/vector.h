#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <cstdint>
#include <initializer_list>
#include <vector>
#include <assert.h>

class Vector
{
public:
	Vector(std::uint32_t len)
		:mLen(len)
	{
		mData = new std::uint32_t[mLen](); // init with zeros
	}

	Vector(const std::initializer_list<std::uint32_t>& data)
		:Vector(data.size())
	{
		std::uint32_t i = 0;
		for (const std::uint32_t& element : data) {
			mData[i] = element;
			++i;
		}
	}

	Vector(std::uint32_t len, std::uint32_t* data)
		:mLen(len)
	{
		mData = new std::uint32_t[mLen];
		for (std::uint32_t i = 0; i < mLen; ++i) {
			mData[i] = data[i];
		}
	}

	~Vector()
	{
		delete[] mData;
	}

	Vector(const Vector& other)
	{
		mLen = other.mLen;

		delete[] mData;
		if (other.mData) {
			mData = new std::uint32_t[mLen];
			for (std::uint32_t i = 0; i < mLen; ++i) {
				mData[i] = other.mData[i];
			}
		}
		else {
			mData = new std::uint32_t[mLen]();
		}
	}

	Vector& operator=(const Vector& other) {
		if (this == &other) {
			return *this;
		}

		mLen = other.mLen;

		delete[] mData;
		if (other.mData) {
			mData = new std::uint32_t[mLen];
			for (std::uint32_t i = 0; i < mLen; ++i) {
				mData[i] = other.mData[i];
			}
		}
		else {
			mData = new std::uint32_t[mLen]();
		}
	}

	Vector& operator+=(const Vector& other) {
		assert(mLen == other.mLen);
		for (std::uint32_t i = 0; i < mLen; ++i) {
			mData[i] += other.mData[i];
		}
		return *this;
	}

	Vector& operator*=(std::uint32_t value) {
		for (std::uint32_t i = 0; i < mLen; ++i) {
			mData[i] *= value;
		}
		return *this;
	}

	friend Vector operator^(const Vector& v1, const Vector& v2) {
		assert(v1.mLen == v2.mLen);
		std::uint32_t* tempData = new std::uint32_t[v1.mLen];
		for (std::uint32_t i = 0; i < v1.mLen; ++i) {
			tempData[i] = v1.mData[i] * v2.mData[i];
		}
		Vector v3(v1.mLen, tempData);
		delete[] tempData;
		return v3;
	}

	friend Vector operator*(const Vector& other, const std::uint32_t value) {
		Vector copyVector(other);
		copyVector *= value;
		return copyVector;

	}

	friend Vector operator*(const std::uint32_t value, const Vector& other) {
		return other * value;
	}

	friend Vector& operator+(const Vector& v1, const Vector& v2) {
		assert(v1.mLen == v2.mLen);
		/*
		std::uint32_t* tempData = new std::uint32_t[v1.mLen];
		for (std::uint32_t i = 0; i < v1.mLen; ++i) {
			tempData[i] = v1.mData[i] + v2.mData[i];
		}
		Vector v3(v1.mLen, tempData);
		delete[] tempData;
		return v3;
		*/
		Vector v3(v1.mLen);
		v3 += v1;
		v3 += v2;
		return v3;
	}

	friend std::ostream& operator<< (std::ostream& out, const Vector& vector) {
		out << "Vector values:";
		for (std::uint32_t i = 0; i < vector.mLen; ++i) {
			out << " " << vector.mData[i];
		}
		out << std::endl;
		return out;
	}

private:
	std::uint32_t mLen;
	std::uint32_t* mData;
	
};

#endif // !VECTOR_H

