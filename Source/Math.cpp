#include "Math.h"

namespace Stella
{
	// ----------------------------------------------------------------------
	// -- Irracional constants
	// ----------------------------------------------------------------------

	const Double Math::PI = 3.14159265358979323846;
	const Double Math::E = 2.71828182845904523536;

	// ----------------------------------------------------------------------
	// -- Trigonometric functions 
	// ----------------------------------------------------------------------

	Double Math::Sin(Double x)
	{
		return sin(x);
	}

	Double Math::Cos(Double x)
	{
		return cos(x);
	}

	Double Math::Tan(Double x)
	{
		return tan(x);
	}

	Double Math::Asin(Double x)
	{
		return asin(x);
	}

	Double Math::Acos(Double x)
	{
		return acos(x);
	}

	Double Math::Atan(Double x)
	{
		return atan(x);
	}

	Double Math::Atan2(Double y, Double x)
	{
		return atan2(y, x);
	}

	Double Math::Sinh(Double x)
	{
		return sinh(x);
	}

	Double Math::Cosh(Double x)
	{
		return cosh(x);
	}

	Double Math::Tanh(Double x)
	{
		return tanh(x);
	}

	Double Math::Asinh(Double x)
	{
		return asinh(x);
	}

	Double Math::Acosh(Double x)
	{
		return acosh(x);
	}

	Double Math::Atanh(Double x)
	{
		return atanh(x);
	}

	// ----------------------------------------------------------------------
	// -- Exponential, power and logarithmic functions
	// ----------------------------------------------------------------------

	Double Math::Exp(Double x)
	{
		return exp(x);
	}

	Double Math::Pow(Double x, Double y)
	{
		return pow(x, y);
	}

	Double Math::Sqrt(Double x)
	{
		return sqrt(x);
	}

	Double Math::Cbrt(Double x)
	{
		return cbrt(x);
	}

	Double Math::Log(Double x)
	{
		return log(x);
	}

	Double Math::Log(Double base, Double x)
	{
		return log(x) / log(base);
	}

	Double Math::Log2(Double x)
	{
		return log2(x);
	}

	Double Math::Log10(Double x)
	{
		return log10(x);
	}

	// ----------------------------------------------------------------------
	// -- Rounding and remainder functions
	// ----------------------------------------------------------------------

	Double Math::Ceil(Double x)
	{
		return ceil(x);
	}

	Double Math::Floor(Double x)
	{
		return floor(x);
	}

	Double Math::Round(Double x)
	{
		return round(x);
	}

	// ----------------------------------------------------------------------
	// -- Other functions
	// ----------------------------------------------------------------------

	Double Math::Abs(Double x)
	{
		return fabs(x);
	}

	Double Math::Max(Double x, Double y)
	{
		return x > y ? x : y;
	}

	Double Math::Min(Double x, Double y)
	{
		return x < y ? x : y;
	}

	Double Math::ToDegrees(Double radians)
	{
		return radians * 180.f / Math::PI;
	}

	Double Math::ToRadians(Double degrees)
	{
		return degrees * Math::PI / 180.f;
	}

	UInt32 Math::NearestPowerOf2(UInt32 x)
	{
		x--;
		x |= x >> 1;
		x |= x >> 2;
		x |= x >> 4;
		x |= x >> 8;
		x |= x >> 16;

		return x++;
	}
}


