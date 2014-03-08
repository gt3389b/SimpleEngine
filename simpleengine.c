#include <stdio.h>
#include <string.h>

#include <openssl/crypto.h>
#include <openssl/objects.h>
#include <openssl/engine.h>

static int simple_engine_ctrl(ENGINE *e, int cmd, long i, void *p, void(*f) ()) 
{
    printf("Currently: do nothing ;)\n");
    switch (cmd) {
        default:
                break;
    }
    return 0;
}

static int simple_engine_bind(ENGINE *e, const char *id)
{
    printf ("Loading simple engine!\n");
    if (!ENGINE_set_id(e, "simple") ||
        !ENGINE_set_name(e, "simple engine")) {
        return 0;
    }
    else {
        return 1;
    }
}

IMPLEMENT_DYNAMIC_CHECK_FN();
IMPLEMENT_DYNAMIC_BIND_FN(simple_engine_bind);
