/*
 * Tools verification_handle type test program
 *
 * Copyright (C) 2006-2021, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <common.h>
#include <file_stream.h>
#include <memory.h>
#include <types.h>

#if defined( HAVE_STDLIB_H ) || defined( WINAPI )
#include <stdlib.h>
#endif

#include "ewf_test_libcerror.h"
#include "ewf_test_libewf.h"
#include "ewf_test_macros.h"
#include "ewf_test_memory.h"
#include "ewf_test_unused.h"

#include "../ewftools/verification_handle.h"

/* Tests the verification_handle_initialize function
 * Returns 1 if successful or 0 if not
 */
int ewf_test_tools_verification_handle_initialize(
     void )
{
	libcerror_error_t *error                   = NULL;
	verification_handle_t *verification_handle = NULL;
	int result                                 = 0;

#if defined( HAVE_EWF_TEST_MEMORY )
	int number_of_malloc_fail_tests            = 1;
	int number_of_memset_fail_tests            = 1;
	int test_number                            = 0;
#endif

	/* Test regular cases
	 */
	result = verification_handle_initialize(
	          &verification_handle,
	          0,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	EWF_TEST_ASSERT_IS_NOT_NULL(
	 "verification_handle",
	 verification_handle );

	EWF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	result = verification_handle_free(
	          &verification_handle,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	EWF_TEST_ASSERT_IS_NULL(
	 "verification_handle",
	 verification_handle );

	EWF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = verification_handle_initialize(
	          NULL,
	          0,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	EWF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	verification_handle = (verification_handle_t *) 0x12345678UL;

	result = verification_handle_initialize(
	          &verification_handle,
	          0,
	          &error );

	verification_handle = NULL;

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	EWF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

#if defined( HAVE_EWF_TEST_MEMORY )

	for( test_number = 0;
	     test_number < number_of_malloc_fail_tests;
	     test_number++ )
	{
		/* Test verification_handle_initialize with malloc failing
		 */
		ewf_test_malloc_attempts_before_fail = test_number;

		result = verification_handle_initialize(
		          &verification_handle,
		          0,
		          &error );

		if( ewf_test_malloc_attempts_before_fail != -1 )
		{
			ewf_test_malloc_attempts_before_fail = -1;

			if( verification_handle != NULL )
			{
				verification_handle_free(
				 &verification_handle,
				 NULL );
			}
		}
		else
		{
			EWF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			EWF_TEST_ASSERT_IS_NULL(
			 "verification_handle",
			 verification_handle );

			EWF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
	for( test_number = 0;
	     test_number < number_of_memset_fail_tests;
	     test_number++ )
	{
		/* Test verification_handle_initialize with memset failing
		 */
		ewf_test_memset_attempts_before_fail = test_number;

		result = verification_handle_initialize(
		          &verification_handle,
		          0,
		          &error );

		if( ewf_test_memset_attempts_before_fail != -1 )
		{
			ewf_test_memset_attempts_before_fail = -1;

			if( verification_handle != NULL )
			{
				verification_handle_free(
				 &verification_handle,
				 NULL );
			}
		}
		else
		{
			EWF_TEST_ASSERT_EQUAL_INT(
			 "result",
			 result,
			 -1 );

			EWF_TEST_ASSERT_IS_NULL(
			 "verification_handle",
			 verification_handle );

			EWF_TEST_ASSERT_IS_NOT_NULL(
			 "error",
			 error );

			libcerror_error_free(
			 &error );
		}
	}
#endif /* defined( HAVE_EWF_TEST_MEMORY ) */

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( verification_handle != NULL )
	{
		verification_handle_free(
		 &verification_handle,
		 NULL );
	}
	return( 0 );
}

/* Tests the verification_handle_free function
 * Returns 1 if successful or 0 if not
 */
int ewf_test_tools_verification_handle_free(
     void )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test error cases
	 */
	result = verification_handle_free(
	          NULL,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	EWF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* Tests the verification_handle_signal_abort function
 * Returns 1 if successful or 0 if not
 */
int ewf_test_tools_verification_handle_signal_abort(
     verification_handle_t *handle )
{
	libcerror_error_t *error = NULL;
	int result               = 0;

	/* Test regular cases
	 */
	result = verification_handle_signal_abort(
	          handle,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	EWF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	/* Test error cases
	 */
	result = verification_handle_signal_abort(
	          NULL,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 -1 );

	EWF_TEST_ASSERT_IS_NOT_NULL(
	 "error",
	 error );

	libcerror_error_free(
	 &error );

	return( 1 );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	return( 0 );
}

/* The main program
 */
#if defined( HAVE_WIDE_SYSTEM_CHARACTER )
int wmain(
     int argc EWF_TEST_ATTRIBUTE_UNUSED,
     wchar_t * const argv[] EWF_TEST_ATTRIBUTE_UNUSED )
#else
int main(
     int argc EWF_TEST_ATTRIBUTE_UNUSED,
     char * const argv[] EWF_TEST_ATTRIBUTE_UNUSED )
#endif
{
	libcerror_error_t *error                   = NULL;
	verification_handle_t *verification_handle = NULL;
	int result                                 = 0;

	EWF_TEST_UNREFERENCED_PARAMETER( argc )
	EWF_TEST_UNREFERENCED_PARAMETER( argv )

	EWF_TEST_RUN(
	 "verification_handle_initialize",
	 ewf_test_tools_verification_handle_initialize );

	EWF_TEST_RUN(
	 "verification_handle_free",
	 ewf_test_tools_verification_handle_free );

#if !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 )
	/* Initialize info handle for tests
	 */
	result = verification_handle_initialize(
	          &verification_handle,
	          0,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	EWF_TEST_ASSERT_IS_NOT_NULL(
	 "verification_handle",
	 verification_handle );

	EWF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

	EWF_TEST_RUN_WITH_ARGS(
	 "verification_handle_signal_abort",
	 ewf_test_tools_verification_handle_signal_abort,
	 verification_handle );

	/* Clean up
	 */
	result = verification_handle_free(
	          &verification_handle,
	          &error );

	EWF_TEST_ASSERT_EQUAL_INT(
	 "result",
	 result,
	 1 );

	EWF_TEST_ASSERT_IS_NULL(
	 "verification_handle",
	 verification_handle );

	EWF_TEST_ASSERT_IS_NULL(
	 "error",
	 error );

#endif /* !defined( __BORLANDC__ ) || ( __BORLANDC__ >= 0x0560 ) */

	return( EXIT_SUCCESS );

on_error:
	if( error != NULL )
	{
		libcerror_error_free(
		 &error );
	}
	if( verification_handle != NULL )
	{
		verification_handle_free(
		 &verification_handle,
		 NULL );
	}
	return( EXIT_FAILURE );
}

