/*
 * Copyright (c) 2010 .SE (The Internet Infrastructure Foundation)
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
 * GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
 * IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
 * IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*****************************************************************************
 softhsm-util-cryptopp.h

 Header file for Crypto++ implemented
 *****************************************************************************/

#ifndef _SOFTHSM_V2_SOFTHSM_UTIL_CRYPTOPP_H
#define _SOFTHSM_V2_SOFTHSM_UTIL_CRYPTOPP_H

#include <cryptopp/rsa.h>
#include <cryptopp/dsa.h>

typedef struct rsa_key_material_t {
	CK_ULONG sizeE;
	CK_ULONG sizeN;
	CK_ULONG sizeD;
	CK_ULONG sizeP;
	CK_ULONG sizeQ;
	CK_ULONG sizeDMP1;
	CK_ULONG sizeDMQ1;
	CK_ULONG sizeIQMP;
	CK_VOID_PTR bigE;
	CK_VOID_PTR bigN;
	CK_VOID_PTR bigD;
	CK_VOID_PTR bigP;
	CK_VOID_PTR bigQ;
	CK_VOID_PTR bigDMP1;
	CK_VOID_PTR bigDMQ1;
	CK_VOID_PTR bigIQMP;
	rsa_key_material_t() {
		sizeE = 0;
		sizeN = 0;
		sizeD = 0;
		sizeP = 0;
		sizeQ = 0;
		sizeDMP1 = 0;
		sizeDMQ1 = 0;
		sizeIQMP = 0;
		bigE = NULL_PTR;
		bigN = NULL_PTR;
		bigD = NULL_PTR;
		bigP = NULL_PTR;
		bigQ = NULL_PTR;
		bigDMP1 = NULL_PTR;
		bigDMQ1 = NULL_PTR;
		bigIQMP = NULL_PTR;
	}
} rsa_key_material_t;

typedef struct dsa_key_material_t {
	CK_ULONG sizeP;
	CK_ULONG sizeQ;
	CK_ULONG sizeG;
	CK_ULONG sizeX;
	CK_ULONG sizeY;
	CK_VOID_PTR bigP;
	CK_VOID_PTR bigQ;
	CK_VOID_PTR bigG;
	CK_VOID_PTR bigX;
	CK_VOID_PTR bigY;
	dsa_key_material_t() {
		sizeP = 0;
		sizeQ = 0;
		sizeG = 0;
		sizeX = 0;
		sizeY = 0;
		bigP = NULL_PTR;
		bigQ = NULL_PTR;
		bigG = NULL_PTR;
		bigX = NULL_PTR;
		bigY = NULL_PTR;
	}
} dsa_key_material_t;

CryptoPP::PKCS8PrivateKey* crypto_read_file(char* filePath);

// RSA
int crypto_save_rsa(CK_SESSION_HANDLE hSession, char* label, char* objID, size_t objIDLen, int noPublicKey, CryptoPP::RSA::PrivateKey* rsa);
rsa_key_material_t* crypto_malloc_rsa(CryptoPP::RSA::PrivateKey* rsa);
void crypto_free_rsa(rsa_key_material_t* keyMat);

// DSA
int crypto_save_dsa(CK_SESSION_HANDLE hSession, char* label, char* objID, size_t objIDLen, int noPublicKey, CryptoPP::DL_Keys_DSA::PrivateKey* dsa);
dsa_key_material_t* crypto_malloc_dsa(CryptoPP::DL_Keys_DSA::PrivateKey* dsa);
void crypto_free_dsa(dsa_key_material_t* keyMat);

#endif // !_SOFTHSM_V2_SOFTHSM_UTIL_CRYPTOPP_H
