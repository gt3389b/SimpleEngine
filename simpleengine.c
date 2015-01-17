#include <stdio.h>
#include <string.h>

#include <openssl/crypto.h>
#include <openssl/objects.h>
#include <openssl/engine.h>

static const char *engine_id = "simple";
static const char *engine_name = "simple engine";
static char simple_engine_loaded = 0;

static int simple_engine_priv_enc(int len, const unsigned char *from, unsigned char *to,
	     RSA *rsa, int padding)
	{
   return 0;
   }

static EVP_PKEY *simple_engine_load_public_key(ENGINE *e, const char *key_id,
                    UI_METHOD *ui_method, void *callback_data)
   {
   return NULL;
   }

static EVP_PKEY *simple_engine_load_private_key(ENGINE *e, const char *key_id,
                    UI_METHOD *ui_method, void *callback_data)
   {
   return simple_engine_load_public_key(e, key_id, ui_method, callback_data);
   }

//*****************************************************************************
// simple_engine_init
//*****************************************************************************
static int simple_engine_init(ENGINE *e)
   {
   int retVal = 1;

   if(simple_engine_loaded == 0)
      {
#if 0
      initStruct(&gData);

      // create server certificates for https with Abraxas
      createCerts();
   
      // initialize cURL library
      curl_global_init(CURL_GLOBAL_ALL);
#endif

      simple_engine_loaded = 1;
      }
   else
      {
      //ABRAXASerr(ABRAXAS_F_ABRAXAS_INIT,ABRAXAS_R_ALREADY_LOADED);
      retVal = 0;
      }

   return retVal;
   }

//*****************************************************************************
// simple_engine_finish
//*****************************************************************************
static int simple_engine_finish(ENGINE *e)
   {
   if(simple_engine_loaded == 0)
      {
      //ABRAXASerr(ABRAXAS_F_ABRAXAS_FINISH,ABRAXAS_R_NOT_LOADED);
      return 0;
      }

#if 0
   if(gCertFileName)
      {
      remove(gCertFileName);
      gCertFileName = NULL;
      }

   // clean up cURL library
   curl_global_cleanup();
#endif

   simple_engine_loaded = 0;
   return 1;
   }


static int simple_engine_ctrl(ENGINE *e, int cmd, long i, void *p, void(*f) ()) 
{
    printf("Currently: do nothing ;)\n");
    switch (cmd) {
        default:
                break;
    }
    return 0;
}

/* Our internal RSA_METHOD that we provide pointers to */
static RSA_METHOD simple_engine_rsa =
        {
        "Simple RSA method",
        NULL,                                // rsa_pub_enc
        NULL,                                // rsa_pub_dec
        simple_engine_priv_enc,              // rsa_priv_enc
        NULL,                                // rsa_priv_dec
        NULL,                                // rsa_mod_exp
        NULL,                                // rsa_mod_exp_mongomery
        NULL,                                // init
        NULL,                                // finish
        0,                                   // RSA flag
        NULL,                                // app_data
        NULL,                                // openssl sign
        NULL,                                // openssl verify
        NULL                                 // keygen
        };

static int simple_engine_bind(ENGINE *e, const char *id)
{
    printf ("Loading simple engine!\n");
    if (!ENGINE_set_id(e, engine_id) ||
        !ENGINE_set_name(e, engine_name)  ||
#ifndef OPENSSL_NO_RSA
        !ENGINE_set_RSA(e, &simple_engine_rsa) ||
#endif
        !ENGINE_set_load_privkey_function(e, &simple_engine_load_private_key) ||
        !ENGINE_set_load_pubkey_function(e, &simple_engine_load_public_key) ||
        !ENGINE_set_init_function(e, simple_engine_init)  ||
        !ENGINE_set_finish_function(e, simple_engine_finish) ||
	     !ENGINE_set_ctrl_function(e, simple_engine_ctrl)) {
        return 0;
    }
    else {
        return 1;
    }
}

IMPLEMENT_DYNAMIC_CHECK_FN();
IMPLEMENT_DYNAMIC_BIND_FN(simple_engine_bind);
