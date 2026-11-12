#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L11_003A6B78 */
__asm__(".extern D_L11_001DEA54, 16");
extern f32 D_L11_001DEA54;
extern void func_L01_004AA7E8(void *, s32);

void func_L11_003A6B78(u8 *a0)
{
    u8 *p;

    if (D_L11_001DEA54 != 200.0f) {
        *(s32 *)(a0 + 0x98) = 0;
        *(u16 *)(a0 + 0x34) = (*(u16 *)(a0 + 0x34) | 0x41) & 0xEFFF;
        func_L01_004AA7E8(a0, 1);
    } else {
        p = *(u8 **)(a0 + 0x24);
        *(u16 *)(a0 + 0x34) &= 0xFFBE;
        *(u16 *)(a0 + 0x34) |= *(u16 *)(p + 0x44) & 0x1000;
        *(s32 *)(a0 + 0x98) = *(s32 *)(p + 0x10);
    }
}
/* localdecomp:end func_L11_003A6B78 */

/* localdecomp:start func_L11_003A6BF8 */
typedef int q_3A6BF8 __attribute__((mode(TI)));
typedef struct { u8 pad0[0x35C]; u8 *f35C; s32 f360; } G_3A6BF8;
extern G_3A6BF8 D_001A4BE0;
extern void func_L01_004450F0(u8 *, s32, s32);
extern void func_003C48A8(void *, void *);
extern void func_003C4DA8(void *, void *, void *, void *);
extern void func_L01_00459C50(s32);

void func_L11_003A6BF8(u8 *a0)
{
    u8 *v = *(u8 **)(a0 + 0x68);
    vu0_v4 d;
    G_3A6BF8 *g;

    if (a0[0x20] == 0) {
        *(s32 *)(v + 0x6C) |= 1;
        func_L01_004450F0(a0, 1, -1);
        *(q_3A6BF8 *)(v + 0x70) = *(q_3A6BF8 *)(a0 + 0x10);
        *(q_3A6BF8 *)(v + 0x80) = *(q_3A6BF8 *)(a0 + 0x10);
        return;
    }
    vec_sub_ba(&d, a0 + 0x10, v + 0x70);
    func_003C48A8(a0 + 0xC0, a0 + 0xF0);
    func_003C4DA8(v + 0x30, &d, v + 0x80, a0 + 0xF0);
    *(q_3A6BF8 *)(v + 0x70) = *(q_3A6BF8 *)(a0 + 0x10);
    *(q_3A6BF8 *)(v + 0x80) = *(q_3A6BF8 *)(a0 + 0xF0);
    g = &D_001A4BE0;
    if (g->f360 != 0 && g->f35C != 0 && *(s16 *)(g->f35C + 0xAA) == 0x1B93) {
        func_L01_00459C50(0xE);
    }
}
/* localdecomp:end func_L11_003A6BF8 */

/* localdecomp:start func_L11_003A6CE0 */
__asm__(".extern D_L11_001D66B0, 16");
extern u8 D_L11_001D66B0;
extern u8 D_001A30B0[];
extern u16 D_001A8C40[];
extern s32 func_L01_004AA710(void *, s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_00382580(void *, f32, f32);
extern u8 *func_L01_0046B458(void *, s32, f32, f32, s32, s32, s32, void *, f32, s32);
extern s32 func_L01_00456250(void *);

void func_L11_003A6CE0(u8 *a0)
{
    s32 *v = *(s32 **)(a0 + 0x68);
    vu0_v4 p;
    s32 idx;
    u8 *e;
    s32 t;

    if (func_L01_004AA710(a0, v[1]) == 0) {
        idx = v[1];
        if (idx == -1) {
            goto spawn;
        }
        e = D_001A30B0 + (idx << 7);
        if (*(u8 **)(e + 0xDC) != a0 || e[0xD0] == 0) {
spawn:
            v[1] = func_003A52A0(0, 4, a0);
        }
    }
    t = *(u16 *)(a0 + 0x96) + 1;
    *(u16 *)(a0 + 0x96) = t;
    if ((u16)t >= 8) {
        func_00382580(&p, 3.0f, 3.0f);
        vec_add_ba(&p, a0 + 0x10, &p);
        func_L01_0046B458(&p, 0x21, 6.0f, 0.0f, 0xFFFF0707, 0, 3, &D_L11_001D66B0, 0.0f, 0);
        func_L01_0046B458(&p, 0x21, 3.0f, 0.0f, 0x9F7F7F7F, 0, -3, &D_L11_001D66B0, 0.0f, 0);
        *(u16 *)(a0 + 0x96) = 0;
    }
    if (func_L01_00456250(a0) != 0) {
        D_001A8C40[0] = 0xFFFF;
    }
}
/* localdecomp:end func_L11_003A6CE0 */
