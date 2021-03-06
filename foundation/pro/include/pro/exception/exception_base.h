﻿/**
*  @file
*  @copyright defined in xmax/LICENSE
*/
#pragma once
#include <exception>
#include <pro/types/generictypes.hpp>

namespace pro
{
	#define BASE_EXCEPT(desc, src) throw Exception(desc, __FILE__, __LINE__)

	class Exception : public std::exception
	{
	public:
		enum ExceptionType
		{
			EXT_UNDEF_TYPE = 0,
			EXT_SERIALIZE_ERROR = 1,
			EXT_FORMAT_ERROR = 2,
			EXT_MEMORY_ERROR = 3,
			//EXT_FILE_READ_FALSE,
			//EXT_FILE_WRITE_FALSE,
			//EXT_FILE_NOT_FOUND,
			//EXT_ITEM_NOT_FOUND,
			//EXT_SYSTEM_ERROR,
			EXT_CUSTOM_BEGIN = 1000,
		};

		/** Default constructor.
        */

        Exception(const string& _description, const string& _source);
		Exception(const string& _description, const string& _source, const char* _file, long _line);
		Exception(const string& _description, const char* _file, long _line);
        /** Copy constructor.
        */
        Exception(const Exception& rhs);

		/// Needed for  compatibility with std::exception
		virtual ~Exception() throw();

        /** Assignment operator.
        */
        void operator = (const Exception& rhs);

        virtual const string& GetFullDescription() const;

        /** Gets the error code.
        */
        virtual int GetType(void) const throw();

        /** Gets the source function.
        */
        virtual const string &GetSource() const;

        /** Gets source file name.
        */
        virtual const string &GetFile() const;

        /** Gets line number.
        */
        virtual long GetLine() const;

		/** Returns a string with only the 'description' field of this exception. Use 
			GetFullDescriptionto get a full description of the error including line number,
			error number and what function threw the exception.
        */
		virtual const string &GetDescription(void) const;

		/// Override std::exception::what
		const char* what() const throw();

	protected:

		/** Advanced constructor.
        */
        Exception(int _type, const string& _description, const string& _source, const char* _tile, const char* _file, long _line);
		Exception(int _type, const string& _description, const char* _tile, const char* _file, long _line);
		long line_;
		int type_;
		string title_;
		string description_;
		string source_;
		string file_;
		mutable string full_desc_;
	};
}
