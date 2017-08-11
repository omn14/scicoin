// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef SCICOIN_SCICOINCONSENSUS_H
#define SCICOIN_SCICOINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_SCICOIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/scicoin-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBSCICOINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define SCICOINCONSENSUS_API_VER 1

typedef enum scicoinconsensus_error_t
{
    scicoinconsensus_ERR_OK = 0,
    scicoinconsensus_ERR_TX_INDEX,
    scicoinconsensus_ERR_TX_SIZE_MISMATCH,
    scicoinconsensus_ERR_TX_DESERIALIZE,
    scicoinconsensus_ERR_AMOUNT_REQUIRED,
    scicoinconsensus_ERR_INVALID_FLAGS,
} scicoinconsensus_error;

/** Script verification flags */
enum
{
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    scicoinconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = scicoinconsensus_SCRIPT_FLAGS_VERIFY_P2SH | scicoinconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               scicoinconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | scicoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               scicoinconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | scicoinconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not NULL, err will contain an error/success code for the operation
EXPORT_SYMBOL int scicoinconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, scicoinconsensus_error* err);

EXPORT_SYMBOL int scicoinconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, scicoinconsensus_error* err);

EXPORT_SYMBOL unsigned int scicoinconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // SCICOIN_SCICOINCONSENSUS_H
