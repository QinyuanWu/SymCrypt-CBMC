// Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
// SPDX-License-Identifier: MIT-0

/*
 * Insert copyright notice
 */

/**
 * @file SymCryptAesEcb_harness.c
 * @brief Implements the proof harness for SymCryptAesEcb function.
 */

/*
 * Insert project header files that
 *   - include the declaration of the function
 *   - include the types needed to declare function arguments
 */
#include <stdlib.h>
#include "symcrypt.h"
#define SYMCRYPT_AES_EXPANDED_KEY_SIZE  (176)

SYMCRYPT_ENVIRONMENT_LINUX_USERMODE

/**
 * @brief Starting point for formal analysis
 * 
 */
void harness(void)
{
    // create and expand aes key
    SIZE_T cbKey;
    PCBYTE pbKey;
    __CPROVER_assume(cbKey == SYMCRYPT_AES_BLOCK_SIZE);
    pbKey = malloc( cbKey );
    __CPROVER_assume(pbKey != NULL);
    PSYMCRYPT_AES_EXPANDED_KEY pExpandedKey;
    pExpandedKey = malloc(SYMCRYPT_AES_EXPANDED_KEY_SIZE);
    __CPROVER_assume(pExpandedKey != NULL);
    SymCryptAesExpandKey( pExpandedKey, pbKey, cbKey );
    free(pbKey);
    free(pExpandedKey);
/*    
    //SIZE_T cbData; // unconstrained value
    PCBYTE pbSrc;
    PCBYTE pbDst;
    //BYTE abResult[SYMCRYPT_MD2_RESULT_SIZE];

    //__CPROVER_assume(cbData == SYMCRYPT_AES_BLOCK_SIZE)
    pbSrc = malloc(SYMCRYPT_AES_BLOCK_SIZE);
    pbDst = malloc(SYMCRYPT_AES_BLOCK_SIZE);

    __CPROVER_assume(pbSrc != NULL);
    __CPROVER_assume(pbDst != NULL);

    SymCryptAesEncrypt( pExpandedKey, pbSrc, pbDst );

    free(pbKey);
    free(pbSrc);
    free(pbDst);
*/
}
