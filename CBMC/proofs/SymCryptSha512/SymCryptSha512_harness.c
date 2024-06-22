// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file SymCryptSha512_harness.c
 * @brief Implements the proof harness for SymCryptSha512 function.
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
    BYTE abResult[SYMCRYPT_SHA512_RESULT_SIZE];

    _CPOVER_assume(cbData <= 8192);
    pbData = malloc( cbData );

    _CPROVER_assume(pbData != NULL);

    SymCryptSha512( pbData, cbData, abResult );

    free(pbData);
}
