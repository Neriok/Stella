#pragma once

enum Error
{
	OK,
	// Generic
	FAILED,
	UNAVAILABLE,
	OUT_OF_RANGE,
	OUT_OF_MEMORY,
	// Data
	INVALID_DATA,
	INVALID_PARAMER,
	// File
	FILE_NOT_FOUND,
	FILE_BAD_DRIVE,
	FILE_BAD_PATH,
	FILE_NO_PERMISSION,
	FILE_ALREADY_IN_USE,
	FILE_CANT_OPEN,
	FILE_CANT_WRITE,
	FILE_CANT_READ,
	FILE_CANT_CREATE,
	FILE_CORRUPT,
	FILE_MISSING,
	FILE_MISSING_DEPENDENCES,
	FILE_UNRECOGNIZED,
	FILE_EOF,
	// Database
	DATABASE_CONNECTION_ERROR,
	DATABASE_NOT_FOUND,
	DATABASE_BAD_DRIVE,
	DATABASE_BAD_PATH,
	DATABASE_NO_PERMISSION,
	DATABASE_ALREADY_IN_USE,
	DATABASE_CANT_OPEN,
	DATABASE_CANT_WRITE,
	DATABASE_CANT_READ,
	DATABASE_CANT_CREATE,
	DATABASE_CORRUPT,
	DATABASE_MISSING,
	DATABASE_MISSING_DEPENDENCES,
	DATABASE_UNRECOGNIZED,
	DATABASE_QUERY_FAILED
};


#define ERR_OUT_OF_RANGE(index, size) \
	if(index < 0 || index >= size)    \
    {								  \
		return;					      \
	}								  \


#define ERR_OUT_OF_RANGE_RETURN(index, size, ret) \
	if(index < 0 || index >= size)				  \
    {								              \
		return ret;								  \
	}											  \

#define ERR_NULL_ARGUMENT(param)      \
	if (param == NULL)                \
    {								  \
		return;					      \
	}								  \

#define ERR_NULL_ARGUMENT_RETURN(param, ret)    \
	if(param == NULL)                           \
    {								            \
		return ret;					            \
	}	                                        \



#define ERR_FAIL_COND_V(m_cond, m_retval)                                                                                            \
	{                                                                                                                                \
		if (m_cond) {                                                                                                                \
			/*_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition ' " _STR(m_cond) " ' is true. returned: " _STR(m_retval));*/ \
			return m_retval;                                                                                                         \
		} else                                                                                                                       \
			bool error_exists = false;                                                                                              \
	}

