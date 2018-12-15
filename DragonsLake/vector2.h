#pragma once

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

	vector2<T> operator+(vector2<T> op)
	{
		return vector2<T>(x + op.x, y + op.y);
	}

	vector2<T> operator-(vector2<T> op)
	{
		return vector2<T>(x - op.x, y - op.y);
	}

	vector2<T> operator*(T op)
	{
		return vector2<T>(x * op, y * op);
	}

	vector2<T> operator/(T op)
	{
		return vector2<T>(x / op, y / op);
	}

	template<class F>
	operator vector2<F>() const
	{
		return vector2<F>((F)x, (F)y);
	}
};

typedef vector2<double> vec2;
typedef vector2<float> vec2f;