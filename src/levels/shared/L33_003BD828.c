#include "common.h"

/* declared by functions of L33_003BD2E8.c, which this file was cut from */
extern void func_L33_003BD798();
extern void func_L33_003BD7C8(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

/* declared by functions of L33_003BD6C8.c, which this file was cut from */
extern void func_L01_004450F0(u8 *, s32, s32);
extern s32 func_L01_004561B8(void);
extern s32 func_0038CAD0(u8 *);

/* localdecomp:start func_L33_003BD828 */
__asm__(".extern D_L33_001DF174, 4");
__asm__(".extern D_L33_001DF168, 4");
__asm__(".extern D_L33_001DF164_3BD828, 4");
__asm__(".extern D_L33_001DF178, 4");
__asm__(".extern D_L33_001E2130, 16");
__asm__(".extern D_L33_001DEDC8, 16");
__asm__(".extern D_L33_001E2288, 16");
typedef struct {
    u8 p0[0x10];
    f32 x, y, z;
    u8 p1c[0x23 - 0x1C];
    u8 alpha;
    u8 *cls;
    u8 p28[4];
    f32 scale;
    u8 p30[4];
    u16 flags;
    u8 p36[0x48 - 0x36];
    s32 f48;
    u8 p4c[0x68 - 0x4C];
    s32 *v;
} M_003BD828;
extern s32 D_L33_001DF174;
extern f32 D_L33_001DF168;
extern s32 D_L33_001DF164_3BD828;
extern s32 D_L33_001DF178;
extern u8 D_L33_001DEDC8;
extern u8 D_L33_001E2130;
extern u8 D_L33_001E2288;
extern u8 D_L33_002A3FF0[];
extern u8 D_001A4BE0[];
extern s32 func_L01_004561B8(void);
extern void func_L30_0034C8A8(void *, void *);
extern void func_L30_0034CF28(void *, void *, s32, f32, f32);
extern void func_L02_003BAAB0(void *, void *);
extern s32 func_0038CAD0(u8 *);
extern void func_L01_004450F0(u8 *, s32, s32);

void func_L33_003BD828(u8 *a0) {
    M_003BD828 *m = (M_003BD828 *)a0;
    s32 *v = m->v;
    f32 t;
    s32 alpha;
    M_003BD828 *o;
    u8 *h;
    if (((s32 (*)(u8 *))func_L01_004561B8)(a0)) {
        v[5] = D_L33_001DF174;
        m->f48 = 0;
    }
    if (D_L33_001DEDC8) {
        func_L30_0034C8A8(&D_L33_001E2130, a0);
    }
    t = (f32)v[5] / (f32)D_L33_001DF174;
    h = D_001A4BE0;
    alpha = (s32)(t * 128.0f);
    (*(M_003BD828 **)(h + 0x25C0))->alpha = alpha;
    (*(M_003BD828 **)(h + 0x25C0))->flags |= 8;
    m->alpha = alpha;
    m->flags |= 8;
    o = *(M_003BD828 **)(h + 0x1B24);
    if (o) {
        o->alpha = alpha;
        (*(M_003BD828 **)(h + 0x1B24))->flags |= 8;
    }
    func_L30_0034CF28(a0 + 0x10, v + 2, D_L33_001DF164_3BD828, t * D_L33_001DF168, 0.0f);
    if (v[5] == D_L33_001DF178) {
        func_L02_003BAAB0(*(void **)(h + 0x25C0), D_L33_002A3FF0);
        func_L30_0034C8A8(&D_L33_001E2288, a0);
    }
    if (func_0038CAD0((u8 *)(v + 5))) {
        func_L01_004450F0(a0, 3, -1);
    }
}
/* localdecomp:end func_L33_003BD828 */
