#pragma once
#include <Typedef.h>

namespace Stella
{
	/*-----------------------------------------------------------------------
									   And
	-----------------------------------------------------------------------*/

	template <typename ... T> 
	struct And;

	template <bool TLeft, typename ... TRight>
	struct AndValue
	{
		enum { Value = And <TRight ...>::Value};
	};

	template <typename ... TRight>
	struct AndValue <false, TRight ...>
	{
		enum { Value = false };
	};

	template <typename TLeft, typename ... TRight>
	struct And<TLeft, TRight ...> : AndValue <TLeft::Value, TRight ...>
	{
	};

	template <>   
	struct And <> 
	{ 
		enum { Value = true }; 
	};

	/*-----------------------------------------------------------------------
									   Or
	-----------------------------------------------------------------------*/

	template <typename ... T>
	struct Or;

	template <bool TLeft, typename ... TRight>
	struct OrValue
	{
		enum { Value = Or<TRight ...>::Value };
	};

	template <typename ... TRight>
	struct OrValue <true, TRight ...>
	{
		enum { Value = true };
	};

	template <typename TLeft, typename ... TRight>
	struct Or <TLeft, TRight ...> : OrValue <TLeft::Value, TRight ...>
	{
	};

	template <>
	struct Or <>
	{
		enum { Value = false };
	};

	/*-----------------------------------------------------------------------
									   Not
	-----------------------------------------------------------------------*/

	template <typename T>
	struct Not
	{
		enum { Value = !T::Value };
	};

	/*-----------------------------------------------------------------------
	                                IsVoidType
	-----------------------------------------------------------------------*/

	template <typename T> struct IsVoidType                       { enum { Value = false }; };
	template <> struct           IsVoidType <void>  		      { enum { Value = true  }; };
	template <> struct           IsVoidType <const void>          { enum { Value = true  }; };
	template <> struct           IsVoidType <volatile void>       { enum { Value = true  }; };
	template <> struct           IsVoidType <const volatile void> { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                              IsBooleanType
	-----------------------------------------------------------------------*/

	template <typename T> struct IsBooleanType        { enum { Value = false }; };
	template <> struct           IsBooleanType <bool> { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                               IsCharType
	-----------------------------------------------------------------------*/

	template <typename T> struct IsCharType            { enum { Value = false }; };
	template <> struct           IsCharType <Char>     { enum { Value = true  }; };
	template <> struct           IsCharType <WideChar> { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                              IsNumericType
	-----------------------------------------------------------------------*/

	template <typename T> struct IsNumericType     { enum { Value = false }; };
	template <> struct IsNumericType <float>       { enum { Value = true  }; };
	template <> struct IsNumericType <double>      { enum { Value = true  }; };
	template <> struct IsNumericType <long double> { enum { Value = true  }; };
	template <> struct IsNumericType <UInt8>       { enum { Value = true  }; };
	template <> struct IsNumericType <UInt16>      { enum { Value = true  }; };
	template <> struct IsNumericType <UInt32>	   { enum { Value = true  }; };
	template <> struct IsNumericType <UInt64>      { enum { Value = true  }; };
	template <> struct IsNumericType <Int8>        { enum { Value = true  }; };
	template <> struct IsNumericType <Int16>       { enum { Value = true  }; };
	template <> struct IsNumericType <Int32>       { enum { Value = true  }; };
	template <> struct IsNumericType <Int64>       { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                                IsSameType
	-----------------------------------------------------------------------*/

	template <typename A, typename B> struct IsSameType       { enum { Value = false }; };
	template <typename T>             struct IsSameType<T, T> { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                                ChooseType
	-----------------------------------------------------------------------*/
	
	template <bool Condition, typename TConsecuent, typename TAlternative>
	struct ChooseType;

	template <typename TConsecuent, typename TAlternative>
	struct ChooseType <true, TConsecuent, TAlternative>
	{
		typedef TConsecuent Result;
	};

	template <typename TConsecuent, typename TAlternative>
	struct ChooseType <false, TConsecuent, TAlternative>
	{
		typedef TAlternative Result;
	};

	/*-----------------------------------------------------------------------
	                               IsPointerType
	-----------------------------------------------------------------------*/

	template <typename T> struct IsPointerType                     { enum { Value = false }; };

	template <typename T> struct IsPointerType <T*>                { enum { Value = true  }; };
	template <typename T> struct IsPointerType <const T*>          { enum { Value = true  }; };
	template <typename T> struct IsPointerType <volatile T*>       { enum { Value = true  }; };
	template <typename T> struct IsPointerType <const volatile T*> { enum { Value = true  }; };

	template <typename T> struct IsPointerType <const T>           { enum { Value = IsPointerType<T>::Value }; };
	template <typename T> struct IsPointerType <volatile T>        { enum { Value = IsPointerType<T>::Value }; };
	template <typename T> struct IsPointerType <const volatile T>  { enum { Value = IsPointerType<T>::Value }; };
	
	/*-----------------------------------------------------------------------
	                               IsReferenceType
	-----------------------------------------------------------------------*/

	template <typename T> struct IsReferenceType      { enum { Value = false }; };
	template <typename T> struct IsReferenceType<T&>  { enum { Value = true  }; };
	template <typename T> struct IsReferenceType<T&&> { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                            IsLValueReferenceType
	-----------------------------------------------------------------------*/

	template<typename T> struct IsLValueReferenceType     { enum { Value = false }; };
	template<typename T> struct IsLValueReferenceType<T&> { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                            IsRValueReferenceType
	-----------------------------------------------------------------------*/

	template<typename T> struct IsRValueReferenceType      { enum { Value = false }; };
	template<typename T> struct IsRValueReferenceType<T&&> { enum { Value = true  }; };

	/*-----------------------------------------------------------------------
	                               AddReference
	-----------------------------------------------------------------------*/

	template <typename T> struct AddReference        { typedef T& Type;   };
	template <>           struct AddReference <void> { typedef void Type; };

	/*-----------------------------------------------------------------------
	                              RemoveReference
	-----------------------------------------------------------------------*/

	template <typename T> struct RemoveReference      { typedef T Type; };
	template <typename T> struct RemoveReference<T&>  { typedef T Type; };
	template <typename T> struct RemoveReference<T&&> { typedef T Type; };

	/*-----------------------------------------------------------------------
	                              IsFunctionType
	-----------------------------------------------------------------------*/

	template <typename T> 
	struct IsFunctionType 
	{
		enum { Value = false }; 
	};
	
	template <typename TReturn, typename ... TParams>
	struct IsFunctionType <TReturn(TParams ...)>
	{ 
		enum { Value = true }; 
	};

	/*-----------------------------------------------------------------------
	                                IsEnumType
	-----------------------------------------------------------------------*/
	 
	template <typename T>
	struct IsEnumType
	{
		enum { Value = __is_enum(T) };
	};

	/*-----------------------------------------------------------------------
	                            IsZeroConstructType
	-----------------------------------------------------------------------*/

	template <typename T>
	struct IsZeroConstructType
	{
		enum { Value = Or<IsEnumType<T>, IsCharType<T>, IsNumericType<T>, IsPointerType<T>>::Value };
	};

}

//template <typename T> 
//__forceinline typename RemoveReference<T>::Type&& Move(T&& obj)
//{
//	typedef typename RemoveReference<T>::Type CastType;
//	return (CastType&&)obj;
//}
