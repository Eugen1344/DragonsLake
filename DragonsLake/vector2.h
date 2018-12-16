#pragma once
#include <cmath>

template<class T>
class vector2
{
public:
	T x, y;

	vector2() : x(0), y(0)
	{
	}

	vector2(T x, T y) : x(x), y(y)
	{
	}

	T distance(const vector2<T> vec)
	{
		return sqrt((vec.x - x) * (vec.x - x) + (vec.y - y) * (vec.y - y));
	}

	vector2<T> normalized()
	{
		T len = length();
		if (len == 0)
			return *this;
		return *this / len;
	}

	T length()
	{
		return static_cast<T>(sqrt(x * x + y * y));
	}

	vector2<T> operator+(const vector2<T> op) const
	{
		return vector2<T>(x + op.x, y + op.y);
	}

	vector2<T> operator-(const vector2<T> op) const
	{
		return vector2<T>(x - op.x, y - op.y);
	}

	vector2<T>& operator+=(const vector2<T> op)
	{
		x += op.x;
		y += op.y;
		return *this;
	}

	vector2<T>& operator-=(const vector2<T> op)
	{
		x -= op.x;
		y -= op.y;
		return *this;
	}

	vector2<T> operator*(const T op) const
	{
		return vector2<T>(x * op, y * op);
	}

	vector2<T> operator/(const T op) const
	{
		return vector2<T>(x / op, y / op);
	}

	template<class F>
	explicit operator vector2<F>() const
	{
		return vector2<F>(static_cast<F>(x), static_cast<F>(y));
	}
};

typedef vector2<double> vec2;
typedef vector2<float> vec2f;