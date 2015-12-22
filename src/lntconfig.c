#include "lntconfig.h"

#define LNTCONFIG_ERROR(...)\
    do { \
        fprintf(stderr, "[ERR<%s,%d>]\t", __FILE__, __LINE__);\
        fprintf(stderr, __VA_ARGS__);\
    } while(0)

#define LNTCONFIG_EQUAL_RETURN(arg1, arg2)\
    do {\
        if ((arg1) == (arg2)) {\
            LNTCONFIG_ERROR(#arg1"=="#arg2"\n");\
			return;\
        }\
    } while(0);
	
#define LNTCONFIG_EQUAL_RETURN_VALUE(arg1, arg2, ret)\
    do {\
        if ((arg1) == (arg2)) {\
            LNTCONFIG_ERROR(#arg1"=="#arg2"\n");\
            return (ret);\
        }\
    }while(0);


LNT_S32 LNT_CONFIG_Init(LNT_CONFIG_CTX **ctx, LNT_S8 *config_path) {

	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(config_path, NULL, LNT_FAILED);
	
	*ctx = (LNT_CONFIG_CTX *)malloc(sizeof(LNT_CONFIG_CTX));	
	if (NULL == *ctx) {
		fprintf(stderr, "malloc arg error\n");
		exit(-1);
	}

	(*ctx)->config_path = strdup(config_path);
	
	config_init(&(*ctx)->cfg);
    /* Read the file. If there is an error, report it and exit. */
    if (!config_read_file(&(*ctx)->cfg, config_path)) {
        fprintf(stderr, "%s:%d - %s\n", config_error_file(&(*ctx)->cfg),
                config_error_line(&(*ctx)->cfg), config_error_text(&(*ctx)->cfg));
        config_destroy(&(*ctx)->cfg);
    	return LNT_FAILED;
    }
    (*ctx)->root = config_root_setting(&(*ctx)->cfg);

    return LNT_SUCCESS;
}

LNT_S32 LNT_CONFIG_Update(LNT_CONFIG_CTX *ctx) {

	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	
	if (!config_write_file(&ctx->cfg, ctx->config_path)) {
        fprintf(stderr, "Error while writing file.\n");
        return LNT_FAILED;
     }
	
	 return LNT_SUCCESS;
}

LNT_VOID LNT_CONFIG_Uninit(LNT_CONFIG_CTX **ctx) {

	LNTCONFIG_EQUAL_RETURN(*ctx, NULL);

	LNT_CONFIG_Update(*ctx);
	config_destroy(&(*ctx)->cfg);
	free((*ctx)->config_path);
	free(*ctx);
	*ctx = NULL;
}

LNT_S32 LNT_CONFIG_SetInt(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_S32 value) {
	config_setting_t *setting = NULL;
	LNT_S32 ret = LNT_FALSE;
	
	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(key, NULL, LNT_FAILED);
	
	setting = config_lookup(&ctx->cfg, key);
	if (NULL == setting) {
		setting = config_setting_add(ctx->root, key, CONFIG_TYPE_INT);
	}
	
	ret = config_setting_set_int(setting, value);
	if (ret) {
		return LNT_SUCCESS;
	} else {
		return LNT_FAILED;
	}
}

LNT_S32 LNT_CONFIG_GetInt(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_S32 *value) {
	LNT_S32 ret = LNT_FALSE;

	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(key, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(value, NULL, LNT_FAILED);

	ret = config_setting_lookup_int(ctx->root, key, value);
	if (!ret) {
		fprintf(stderr, "LNT_CONFIG_GetInt not find %s\n", key);
		return LNT_FAILED;
	}	

	return LNT_SUCCESS;
}


LNT_S32 LNT_CONFIG_SetFloat(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_FLOAT value) {
	config_setting_t *setting = NULL;
	LNT_S32 ret = LNT_FALSE;
	
	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(key, NULL, LNT_FAILED);
	
	setting = config_lookup(&ctx->cfg, key);
	if (NULL == setting) {
		setting = config_setting_add(ctx->root, key, CONFIG_TYPE_FLOAT);
	}
	
	ret = config_setting_set_float(setting, value);
	if (ret) {
		return LNT_SUCCESS;
	} else {
		return LNT_FAILED;
	}
}

LNT_S32 LNT_CONFIG_GetFloat(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_FLOAT *value) {
	LNT_S32 ret = LNT_FALSE;

	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(key, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(value, NULL, LNT_FAILED);

	ret = config_setting_lookup_float(ctx->root, key, value);
	if (!ret) {
		fprintf(stderr, "LNT_CONFIG_GetInt not find %s\n", key);
		return LNT_FAILED;
	}	

	return LNT_SUCCESS;
}



LNT_S32 LNT_CONFIG_SetStr(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_S8 *value) {
	config_setting_t *setting = NULL;
	LNT_S32 ret = LNT_FALSE;
	
	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(key, NULL, LNT_FAILED);
	
	setting = config_lookup(&ctx->cfg, key);
	if (NULL == setting) {
		setting = config_setting_add(ctx->root, key, CONFIG_TYPE_STRING);
	}
	
	ret = config_setting_set_string(setting, value);
	if (ret) {
		return LNT_SUCCESS;
	} else {
		return LNT_FAILED;
	}
}

LNT_S32 LNT_CONFIG_GetStr(LNT_CONFIG_CTX *ctx, LNT_S8 *key, LNT_S8 **value) {
	LNT_S32 ret = LNT_FALSE;
	LNT_S32 len = 0;
	
	LNTCONFIG_EQUAL_RETURN_VALUE(ctx, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(key, NULL, LNT_FAILED);
	LNTCONFIG_EQUAL_RETURN_VALUE(value, NULL, LNT_FAILED);

	ret = config_setting_lookup_string(ctx->root, key, value);
	if (!ret) {
		fprintf(stderr, "LNT_CONFIG_GetStr not find %s\n", key);
		return LNT_FAILED;
	}	

	return LNT_SUCCESS;
}





