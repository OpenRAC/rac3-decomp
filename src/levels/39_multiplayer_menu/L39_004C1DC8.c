#include "common.h"

/* declared by functions of L39_004C1BE8.c, which this file was cut from */
typedef struct { u8 pad[0x28]; } S_004C1C18;
extern S_004C1C18 D_L39_00464928[];

/* localdecomp:start func_L39_004C1DC8 */
typedef struct SSL_CIPHER_004C1DC8 {
    s32 valid;
    char *name;
    u64 id;
    u8 pad10[0x28 - 0x10];
} SSL_CIPHER_004C1DC8;
extern s32 D_L39_00464AC4 __attribute__((section(".data")));
extern SSL_CIPHER_004C1DC8 *D_L39_004436F0[];
extern s32 func_L39_004C4130(const void *, const void *);
extern void func_0011E788(void *, s32, s32, void *);
extern void *func_L39_004E0D60(void *, void *, s32, s32, void *);

SSL_CIPHER_004C1DC8 *func_L39_004C1DC8(const u8 *p) {
    SSL_CIPHER_004C1DC8 c, *cp = &c, **cpp;
    u64 id;
    s32 i;

    if (D_L39_00464AC4) {
        D_L39_00464AC4 = 0;
        for (i = 0; i < 8; i++) { D_L39_004436F0[i] = (SSL_CIPHER_004C1DC8 *)&D_L39_00464928[i]; }
        func_0011E788(D_L39_004436F0, 8, 4, func_L39_004C4130);
    }
    id = 0x02000000L | ((u64)p[0] << 16) | ((u64)p[1] << 8) | (u64)p[2];
    c.id = id;
    cpp = func_L39_004E0D60(&cp, D_L39_004436F0, 8, 4, func_L39_004C4130);
    if (cpp == 0 || !(*cpp)->valid) {
        return 0;
    }
    return *cpp;
}
/* localdecomp:end func_L39_004C1DC8 */
