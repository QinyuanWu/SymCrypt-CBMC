// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file SymCryptMd2_harness.c
 * @brief Implements the proof harness for SymCryptMd2 function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
#include <stdlib.h>
#include "symcrypt.h"


SYMCRYPT_ENVIRONMENT_LINUX_USERMODE
/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{
    SIZE_T cbData; // unconstrained value
    PBYTE pbData;
    BYTE abResult[SYMCRYPT_MD2_RESULT_SIZE];
    __CPROVER_assume(cbData <= 8);
    pbData = malloc( cbData );

    __CPROVER_assume(pbData != NULL);

    SymCryptMd2( pbData, cbData, abResult );

    free(pbData);
}


VOID
SYMCRYPT_CALL
SymCryptWipeAsm( _Out_writes_bytes_( cbData ) PVOID pbData, SIZE_T cbData )
{
    volatile BYTE * p = (volatile BYTE *) pbData;
    SIZE_T i;

    //__CPROVER_assume( pbData != NULL );
    //__CPROVER_assume( __CPROVER_w_ok( pbData, cbData ));
    

    for( i=0; i<cbData; i++ )
    __CPROVER_assigns( __CPROVER_typed_target(i), __CPROVER_object_upto(p, cbData) )
    __CPROVER_loop_invariant( i <= cbData )
    //__CPROVER_loop_invariant(__CPROVER_forall { size_t j; (0 <= j && j < i) ==> p[j] == 0 } )
    __CPROVER_decreases( cbData - i ) 
    {
        p[i] = 0;
    }

}
