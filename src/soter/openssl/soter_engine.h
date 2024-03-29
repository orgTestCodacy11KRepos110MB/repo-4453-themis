/*
 * Copyright (c) 2015 Cossack Labs Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef SOTER_OPENSSL_ENGINE_H
#define SOTER_OPENSSL_ENGINE_H

#include <stdint.h>

#include <openssl/evp.h>

#include "soter/soter_asym_sign.h"

/*
 * For the time being Themis and Soter do not support OpenSSL 3.0.
 * The code seems to build fine but it fails the tests, so we're not sure
 * that it is safe to use Soter with OpenSSL 3.0.
 */
#if OPENSSL_VERSION_NUMBER >= 0x30000000L && !THEMIS_EXPERIMENTAL_OPENSSL_3_SUPPORT
#error OpenSSL 3.0 is currently not supported
#endif

struct soter_hash_ctx_type {
    EVP_MD_CTX* evp_md_ctx;
};

struct soter_sym_ctx_type {
    uint32_t alg;
    EVP_CIPHER_CTX* evp_sym_ctx;
};

struct soter_asym_cipher_type {
    EVP_PKEY_CTX* pkey_ctx;
};

struct soter_rsa_key_pair_gen_type {
    EVP_PKEY_CTX* pkey_ctx;
};

struct soter_asym_ka_type {
    EVP_PKEY* param;
    EVP_PKEY* pkey;
};

struct soter_sign_ctx_type {
    EVP_PKEY* pkey;
    EVP_MD_CTX* md_ctx;
    soter_sign_alg_t alg;
};

#endif /* SOTER_OPENSSL_ENGINE_H */
