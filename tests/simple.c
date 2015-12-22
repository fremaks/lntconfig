#include "lntconfig.h"

int main(int argc, char *argv[]) {
	LNT_CONFIG_CTX *config_ctx = NULL;
	LNT_S32 ret = LNT_FAILED;

	LNT_S32 int_val = 0;
	LNT_FLOAT float_val = 0.0;
	LNT_S8  *str_val = NULL;

	
	ret = LNT_CONFIG_Init(&config_ctx, "simple.cfg");
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_Init error\n");
		return ret;
	}

	ret = LNT_CONFIG_SetInt(config_ctx, "int", 2);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_SetInt error\n");
		return ret;
	}	

	ret = LNT_CONFIG_SetFloat(config_ctx, "float", 2.02);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_SetFloat error\n");
		return ret;
	}		

	ret = LNT_CONFIG_SetStr(config_ctx, "string", "fremaks");
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_SetStr error\n");
		return ret;
	}	

	LNT_CONFIG_GetInt(config_ctx, "int", &int_val);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_GetInt error\n");
		return ret;
	}	

	LNT_CONFIG_GetFloat(config_ctx, "float", &float_val);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_GetFloat error\n");
		return ret;
	}		

	LNT_CONFIG_GetStr(config_ctx, "string", &str_val);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_GetStr error\n");
		return ret;
	}	

	printf("int=%d float=%f str=%s\n", int_val, float_val, str_val);
	LNT_CONFIG_Update(config_ctx);

	ret = LNT_CONFIG_SetInt(config_ctx, "int", 3);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_SetInt error\n");
		return ret;
	}	

	ret = LNT_CONFIG_SetFloat(config_ctx, "float", 3.03);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_SetFloat error\n");
		return ret;
	}		

	ret = LNT_CONFIG_SetStr(config_ctx, "string", "hefeng");
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_SetStr error\n");
		return ret;
	}	

	ret = LNT_CONFIG_GetInt(config_ctx, "int", &int_val);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_GetInt error\n");
		return ret;
	}	

	ret = LNT_CONFIG_GetFloat(config_ctx, "float", &float_val);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_GetFloat error\n");
		return ret;
	}		

	ret = LNT_CONFIG_GetStr(config_ctx, "string", &str_val);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_GetStr error\n");
		return ret;
	}	
	
	ret = LNT_CONFIG_GetFloat(config_ctx, "float2", &float_val);
	if (LNT_FAILED == ret) {
		perror("LNT_CONFIG_GetFloat error\n");
		return ret;
	}	
	printf("int=%d float=%f str=%s\n", int_val, float_val, str_val);


	
	
	LNT_CONFIG_Uninit(&config_ctx);

	return 0;
}
