#include "common.h"

/* localdecomp:start func_L39_004C1BE8 */
void func_L39_004C1BA8();
extern u8 D_L39_00464A68[];

void *func_L39_004C1BE8(void) {
    func_L39_004C1BA8();
    return D_L39_00464A68;
}
/* localdecomp:end func_L39_004C1BE8 */

/* localdecomp:start func_L39_004C1C10 */
s32 func_L39_004C1C10(void) {
    return 8;
}
/* localdecomp:end func_L39_004C1C10 */

/* localdecomp:start func_L39_004C1C18 */
typedef struct { u8 pad[0x28]; } S_004C1C18;
extern S_004C1C18 D_L39_00464928[];

S_004C1C18 *func_L39_004C1C18(u32 arg0) {
    if (arg0 >= 8) {
        return 0;
    }
    return &D_L39_00464928[7 - arg0];
}
/* localdecomp:end func_L39_004C1C18 */

/* localdecomp:start func_L39_004C1C50 */
typedef struct {
    u8 _p0[0x48];
    s32 f48;
} I_004C1C50;

typedef struct {
    u8 _p0[0x50];
    I_004C1C50 *f50;
} S_004C1C50;

s32 func_L39_004C1C50(S_004C1C50 *a0) {
    return a0->f50->f48;
}
/* localdecomp:end func_L39_004C1C50 */

INCLUDE_ASM("asm/levels", func_L39_004C1C60);

INCLUDE_ASM("asm/levels", func_L39_004C1CC8);

INCLUDE_ASM("asm/levels", func_L39_004C1D38);

/* localdecomp:start func_L39_004C1DB8 */
s32 func_L39_004C1DB8(void) {
    return 0;
}
/* localdecomp:end func_L39_004C1DB8 */

/* localdecomp:start func_L39_004C1DC0 */
s32 func_L39_004C1DC0(void) {
    return 0;
}
/* localdecomp:end func_L39_004C1DC0 */

INCLUDE_ASM("asm/levels", func_L39_004C1DC8);

/* localdecomp:start func_L39_004C1EE0 */
/* OpenSSL 0.9.6 ssl2_put_cipher_by_char (s2_lib.c) */
typedef struct {
    s32 valid;
    const char *name;
    long id;
} CIPHER_004C1EE0;

s32 func_L39_004C1EE0(CIPHER_004C1EE0 *c, u8 *p) {
    long l;

    if (p != 0) {
        l = c->id;
        if ((l & 0xff000000) != 0x02000000) return 0;
        p[0] = ((u8)(l >> 16L)) & 0xFF;
        p[1] = ((u8)(l >> 8L)) & 0xFF;
        p[2] = ((u8)(l)) & 0xFF;
    }
    return 3;
}
/* localdecomp:end func_L39_004C1EE0 */

/* localdecomp:start func_L39_004C1F30 */
s32 func_L39_004C1F30(s32 *arg0) {
    arg0[11] = 3;
    return 1;
}
/* localdecomp:end func_L39_004C1F30 */
