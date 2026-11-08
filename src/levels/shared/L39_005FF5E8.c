#include "common.h"

typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 b0; u8 b1; u8 pad[0x3E]; s32 f40; s32 f44; s32 f48; s32 f4c; } T50;
typedef struct { s32 f0; s32 f4; s32 f8; s32 fc; } T10;
typedef struct { s32 pad[7]; s32 f1c; } T20;

/* localdecomp:start func_L39_005FF5E8 */
extern T50 D_L39_002C28C0[64];
extern T10 D_L39_002C3CC0[32];
extern T20 D_L39_002C43E0[128];
extern s32 D_L39_002C42D0[65];
extern s32 D_L39_002C3EC0[];
extern u8 *D_L39_0024CB78;
extern s32 D_L39_0024CB80;
extern s32 D_L39_0024CB84;
__asm__(".extern D_L39_0024CB84, 4");
extern u8 *func_L01_00303D30(void *, s32);
extern void func_L01_004CB068(void);
void func_L39_005FF5E8(void) {
    f32 v[4];
    s32 i;
    u8 *r;
    s32 m;
    T50 *p;
    for (i = 0; i < 64; i++) {
        T50 *e = &D_L39_002C28C0[i];
        e->b1 = 0;
        e->f40 = 0;
    }
    for (i = 31; i >= 0; i--) D_L39_002C3CC0[i].f4 = 0;
    for (i = 127; i >= 0; i--) D_L39_002C43E0[i].f1c = 0;
    m = -1;
    for (i = 63; i >= 0; i--) D_L39_002C42D0[i] = m;
    *(u128_t *)v = 0;
    D_L39_002C42D0[64] = 0;
    D_L39_002C3EC0[0x100] = 0;
    v[0] = 5.0f;
    v[1] = 5.0f;
    v[2] = 5.0f;
    v[3] = 1.0f;
    r = func_L01_00303D30(v, 0);
    D_L39_0024CB78 = r;
    *(s32 *)(r + 0x98) = 0;
    *(u16 *)(r + 0x34) |= 2;
    D_L39_0024CB80 = 0;
    D_L39_0024CB84 = 0;
    func_L01_004CB068();
}
/* localdecomp:end func_L39_005FF5E8 */
