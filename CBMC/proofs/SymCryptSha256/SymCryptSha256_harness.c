// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file SymCryptSha256_harness.c
 * @brief Implements the proof harness for SymCryptSha256 function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
#include <stdlib.h>
#include "symcrypt.h"

/**
 * @brief Starting point for formal analysis
 * 
 */
SYMCRYPT_ENVIRONMENT_LINUX_USERMODE

void harness(void)
{
    SIZE_T cbData; // unconstrained value
    PBYTE pbData;
    BYTE abResult[SYMCRYPT_SHA256_RESULT_SIZE];

    __CPROVER_assume(cbData <= 1024);
    pbData = malloc( cbData );

    __CPROVER_assume(pbData != NULL);

    SymCryptSha256( pbData, cbData, abResult );

    free(pbData);
}

VOID
SYMCRYPT_CALL
SymCryptWipeAsm( _Out_writes_bytes_( cbData ) PVOID pbData, SIZE_T cbData )
{
    volatile BYTE * p = (volatile BYTE *) pbData;
    SIZE_T i;

    __CPROVER_assume( pbData != NULL );
    __CPROVER_assume( __CPROVER_w_ok( pbData, cbData ) );
    

    for( i=0; i<cbData; i++ )
    __CPROVER_loop_invariant( 0 <= i && i < cbData )
    __CPROVER_decreases( cbData - i )
    {
        p[i] = 0;
    }

}