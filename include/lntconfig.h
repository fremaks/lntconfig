#ifndef __liblntconfig_h
#define __liblntconfig_h
#include <stdio.h>
#include <stdlib.h>
#include "libconfig.h"
#include "lnt_porting_type.h"

#define CONFIG_VALUE_MAX_LEN  512

typedef struct _LNT_CONFIG_CTX {
	config_t cfg;
	config_setting_t *root;
	LNT_S8 *config_path;
} LNT_CONFIG_CTX;

LNT_S32 LNT_CONFIG_Init(LNT_CONFIG_CTX **ctx, LNT_S8 *config_path);
LNT_S32 LNT_CONFIG_Update(LNT_CONFIG_CTX *ctx);
LNT_VOID LNT_CONFIG_Uninit(LNT_CONFIG_CTX **ctx);
LNT_S32 LNT_CONFIG_SetInt(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_S32 value);
LNT_S32 LNT_CONFIG_GetInt(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_S32 *value);
LNT_S32 LNT_CONFIG_SetFloat(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_FLOAT value);
LNT_S32 LNT_CONFIG_GetFloat(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_FLOAT *value);
LNT_S32 LNT_CONFIG_SetStr(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_S8 *value);

#endif
