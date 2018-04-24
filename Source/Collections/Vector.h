#pragma once
#include "Memory.h"
#include "Error.h"

namespace Stella::Collections
{
	template <class T>
	class Vector
	{
		// ----------------------------------------------------------------------
		// -- Variables
		// ----------------------------------------------------------------------

	private:

		T* pointer;

		// ----------------------------------------------------------------------
		// -- Constructors & destructors
		// ----------------------------------------------------------------------

	public:

		Vector()
		{
			pointer = NULL;
		}

		Vector(const Vector<T>& other)
		{
			pointer = NULL;
			CopyFrom(other);
		}

		~Vector()
		{
			Unreference(pointer);
		}

		// ----------------------------------------------------------------------
		// -- Methods
		// ----------------------------------------------------------------------

	public:

		Boolean IsEmpty() const
		{
			return pointer == 0;
		}

		Size GetSize() const
		{
			Size* size = GetSizePointer();
			return size ? *size : 0;

			/*if (size)
			{
				return *size;
			}
			else
			{
				return 0;
			}*/
		}

		// ----------

		void Add(const T& element)
		{
			Error error = Resize(GetSize() + 1);

			if (error != Error::OK)
			{
				return;
			}

			pointer[GetSize() - 1] = element;
		}

		Error Remove()
		{
			return Remove(GetSize() - 1);
		}

		Error Remove(Int32 index)
		{
			ERR_OUT_OF_RANGE_RETURN(index, this->GetSize(), Error::OUT_OF_RANGE);

			for (Int32 i = index; i < GetSize(); i++)
			{
				pointer[i] = pointer[i + 1];
			}

			Resize(GetSize() - 1);
		}

		// ----------

		Error Resize(Size size)
		{
			if (size == GetSize())
			{
				return Error::OK;
			}

			if (size == 0)
			{
				Unreference(pointer);
				pointer = NULL;
				return Error::OK;
			}

			Size alloc_size;
			GetAllocSizeChecked(size, &alloc_size);

			if (size > GetSize())
			{
				if (GetSize() == 0)
				{
					Size* new_pointer = (Size*)Memory::StaticAllocation(alloc_size, true);

					if (!new_pointer)
					{
						return Error::OUT_OF_MEMORY;
					}

					pointer = (T*)new_pointer;

					*(GetSizePointer()) = 0;
				}
				else
				{
					void* new_pointer = (T*)Memory::StaticReallocation(pointer, alloc_size, true);

					if (!new_pointer)
					{
						return Error::OUT_OF_MEMORY;
					}

					pointer = (T*)(new_pointer);
				}

				T* elements = pointer;

				for (Size i = *GetSizePointer(); i < size; i++)
				{
					MemoryNewConstructor(&elements[i], T);
				}

				*GetSizePointer() = size;
			}
			else
			{
				for (Size i = size; i < *GetSizePointer(); i++)
				{
					((T*)(&(pointer[i])))->~T();
				}

				void* new_pointer = (T*)Memory::StaticReallocation(pointer, alloc_size, true);

				if (!new_pointer)
				{
					return Error::OUT_OF_MEMORY;
				}

				*GetSizePointer() = size;
			}

			return Error::OK;
		}

		// ----------

		T* Begin()
		{
			if (!pointer)
			{
				return NULL;
			}

			return pointer;
		}

		const T* Begin() const
		{
			if (!pointer)
			{
				return NULL;
			}

			return pointer;
		}

		// ----------

		T* End()
		{
			if (!pointer)
			{
				return NULL;
			}

			return pointer + GetSize() - 1;
		}

		const T* End() const
		{
			if (!pointer)
			{
				return NULL;
			}

			return pointer + GetSize() - 1;
		}

		// ----------

		T& Front()
		{
			if (!pointer)
			{
				return *((T*)0);
			}

			return pointer[0];
		}

		const T& Front() const
		{
			if (!pointer)
			{
				return *((T*)0);
			}

			return pointer[0];
		}

		// ----------

		T& Back()
		{
			if (!pointer)
			{
				return *((T*)0);
			}

			return pointer[GetSize() - 1];
		}

		const T& Back() const
		{
			if (!pointer)
			{
				return *((T*)0);
			}

			return pointer[GetSize() - 1];
		}

		// ----------

		Error Insert(Int32 index, const T& element)
		{
			ERR_OUT_OF_RANGE_RETURN(index, GetSize() + 1, Error::OUT_OF_RANGE);

			Resize(GetSize() + 1);

			for (Int32 i = (GetSize() - 1); i > index; i--)
			{
				pointer[i] = pointer[i - 1];
			}

			pointer[index] = element;

			return OK;
		}

		// ----------

		void Sort();
		void Sort(int);

		// ----------

		void Invert()
		{
			T tmp;

			T* b = Begin();
			T* e = End();

			int count = 0;

			for (int i = 0; i < (GetSize() / 2); i++, b++, e--)
			{
				tmp = *b;

				*b = *e;
				*e = tmp;
			}
		}

		void Fill(const T& element)
		{
			for (Int32 i = 0; i < GetSize(); i++)
			{
				pointer[i] = element;
			}
		}

		void Clear()
		{
			Resize(0);
		}

	private:

		Size* GetSizePointer() const
		{
			if (!pointer)
			{
				return NULL;
			}
			return (reinterpret_cast<Size*>(pointer) - 1);
		}

		// ----------

		Size GetAllocSize(Size elements) const
		{
			return elements * sizeof(T) + sizeof(Size);
		}

		Boolean GetAllocSizeChecked(Size elements, Size* out) const
		{
			*out = GetAllocSize(elements);
			return true;
		}

		// ----------

		void CopyFrom(const Vector<T>& from)
		{
			if (pointer == from.pointer)
			{
				return;
			}

			Unreference(pointer);
			pointer = NULL;

			pointer = from.pointer;
		}

		// ----------

		void Unreference(void* ptr)
		{
			if (!ptr)
			{
				return;
			}

			Size* count = GetSizePointer();
			T* data = (T*)(count + 1);

			for (Size i = 0; i < *count; i++)
			{
				data[i].~T();
			}

			Memory::StaticFree(ptr, true);
		}		

		// ----------------------------------------------------------------------
		// -- Operators
		// ----------------------------------------------------------------------	

	public:

		void operator=(const Vector<T>& other)
		{
			CopyFrom(other);
		}

		// ----------

		T& operator[](Int32 index)
		{
			if (index > GetSize())
			{
				return *((T*)0);
			}

			return pointer[index];
		}

		const T& operator[](Int32 index) const
		{
			if (index > GetSize())
			{
				return *((T*)0);
			}

			return pointer[index];
		}

		// ----------

		Boolean operator==(Vector<T>& other)
		{
			if (this->GetSize() != other.GetSize())
			{
				return false;
			}

			for (Int32 i = 0; i < GetSize(); i++)
			{
				if (pointer[i] != other.pointer[i])
				{
					return false;
				}
			}
			return true;
		}

		Boolean operator!=(Vector<T>& other)
		{
			return !(operator==(other));
		}

		// ----------

		Boolean operator<(Vector<T>& other)
		{
			if (this->GetSize() < other.GetSize())
			{
				return true;
			}

			for (Int32 i = 0; i < GetSize(); i++)
			{
				if (this->pointer[i] < other.pointer[i]) return true;
				if (other.pointer[i] < this->pointer[i]) return false;
			}

			return false;
		}

		Boolean operator<=(Vector<T>& other)
		{
			return !(other < *this);
		}

		// ----------

		Boolean operator>(Vector<T>& other)
		{
			return (other < *this);
		}

		Boolean operator>=(Vector<T>& other)
		{
			return !(*this < other);
		}
	};
}