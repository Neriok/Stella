#pragma once

#include "Typedef.h"
#include <math.h>

namespace Stella
{
	class Math
	{

	public:

		// ----------------------------------------------------------------------
		// -- Irracional constants
		// ----------------------------------------------------------------------   

		static const Double PI;
		static const Double E;

		// ----------------------------------------------------------------------
		// -- Trigonometric functions 
		// ----------------------------------------------------------------------	

		static Double Sin(Double x);
		static Double Cos(Double x);
		static Double Tan(Double x);
		static Double Asin(Double x);
		static Double Acos(Double x);
		static Double Atan(Double x);
		static Double Atan2(Double y, Double x);

		static Double Sinh(Double x);
		static Double Cosh(Double x);
		static Double Tanh(Double x);
		static Double Asinh(Double x);
		static Double Acosh(Double x);
		static Double Atanh(Double x);

		// ----------------------------------------------------------------------
		// -- Exponential, power and logarithmic functions
		// ----------------------------------------------------------------------

		static Double Exp(Double x);
		static Double Pow(Double x, Double y);
		static Double Sqrt(Double x);
		static Double Cbrt(Double x);
		static Double Log(Double x);
		static Double Log(Double base, Double x);
		static Double Log2(Double x);
		static Double Log10(Double x);

		// ----------------------------------------------------------------------
		// -- Rounding and remainder functions
		// ----------------------------------------------------------------------

		static Double Ceil(Double x);
		static Double Floor(Double x);
		static Double Round(Double x);

		// ----------------------------------------------------------------------
		// -- Other functions
		// ----------------------------------------------------------------------	

		static Double Abs(Double x);
		static Double Min(Double x, Double y);
		static Double Max(Double x, Double y);
		static Double ToDegrees(Double radians);
		static Double ToRadians(Double degrees);
		static UInt32 NearestPowerOf2(UInt32 x);

	};
}