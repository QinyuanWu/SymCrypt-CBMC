// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file SymCryptMd4_harness.c
 * @brief Implements the proof harness for SymCryptMd4 function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
#include <stdlib.h>
#include <string.h>
#include "symcrypt.h"


SYMCRYPT_ENVIRONMENT_LINUX_USERMODE
/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{
    SIZE_T cbData; // unconstrained value
    SIZE_T cbData1; // unconstrained value
    SIZE_T cbData2;
    PBYTE pbData1;
    PBYTE pbData2;
    BYTE abResult[SYMCRYPT_MD2_RESULT_SIZE];
    pbData1 = malloc( cbData1 );
    pbData2 = malloc( cbData2 );

    __CPROVER_assume(pbData1 != NULL);
    __CPROVER_assume(pbData2 != NULL);

    SYMCRYPT_MD2_STATE state;

    SymCryptMd4Init( &state );
    SymCryptMd4Append( &state, pbData1, cbData1 );
    SymCryptMd4Append( &state, pbData2, cbData2 );
    SymCryptMd4Result( &state, abResult );

    free(pbData1);
    free(pbData2);
}

VOID
SYMCRYPT_CALL
SymCryptWipeAsm( _Out_writes_bytes_( cbData ) PVOID pbData, SIZE_T cbData )
{
    volatile BYTE * p = (volatile BYTE *) pbData;
    memset(p, 0, cbData);
}