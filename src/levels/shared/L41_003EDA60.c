#include "common.h"

/* localdecomp:start func_L41_003EDA60 */
extern s32 func_L40_0053F2D8(u8 *msg);
extern u8 *func_L40_0053F570(s32 cls, s32 uid, s32 sender, s32 a3, s32 index);
extern void func_0038CB78(void *dst, s32 val, s32 size);
extern void func_L40_003ED980(u8 *m, s32 a1);
extern f32 func_003C3D30(void *pos, s32 a1, s32 a2, f32 f);
extern void func_L40_0053DAE8(s32 a0, s32 team);
extern s32 func_L39_005B4398(s32 n);
extern void func_003C7C38(u8 *m);
extern s32 *D_00241120;
__asm__(".extern D_00241120, 16");
/* what D_L41_003575AC points to: a table of s32 at +0x88 */
typedef struct {
    s32 pad[0x22];
    s32 x[1];
} T_003EDA60;
extern T_003EDA60 *D_L41_003575AC[];

u8 *func_L41_003EDA60(s32 a0, s32 a1, u8 *msg) {
    s32 *h = (s32 *)(msg + 8);
    s32 *p = (s32 *)(msg + 0x28);
    f32 *pos = (f32 *)(msg + 0x18);
    u8 *m;
    u8 *v;
    u8 *c;

    m = func_L40_0053F570(0x109D, h[1], *(s32 *)(msg + 4), func_L40_0053F2D8(msg), p[6]);
    if (m != 0) {
        *(u16 *)(m + 0x34) |= 0x20;
        func_0038CB78(*(u8 **)(m + 0x68), 0, 0x3E0);
        func_L40_003ED980(m, -1);
        if (*D_00241120 >= 2) {
            *(u8 *)(m + 0x62) = 1;
        }
        *(f32 *)(m + 0x10) = pos[0];
        *(f32 *)(m + 0x14) = pos[1];
        *(f32 *)(m + 0x18) = pos[2];
        *(f32 *)(m + 0x1C) = pos[3];
        *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
        v = *(u8 **)(m + 0x68);
        *(s32 *)(v + 0x2A8) = p[0];
        *(s32 *)(v + 0x2AC) = p[1];
        *(u8 **)(v + 0x1C) = v + 0x70;
        *(u8 **)(v + 0xC) = v + 0x220;
        *(u8 **)(v + 0x0) = v + 0x30;
        *(u8 **)(v + 0x10) = v + 0x160;
        *(s32 *)(v + 0x264) = p[2];
        *(u8 *)(v + 0x33D) = *(u8 *)(p + 3);
        *(s32 *)(v + 0x2C0) = p[4];
        if (*(u8 *)(v + 0x33D) == 1) {
            *(s32 *)(v + 0x2B8) = p[5];
            *(s32 *)(v + 0x30C) = 0;
            *(s32 *)(v + 0x280) = 0;
            func_L40_003ED980(m, *(s32 *)(v + 0x2C0));
        } else {
            if (*(s32 *)(v + 0x2A8) != -1) {
                *(s32 *)(v + 0x2C0) = D_L41_003575AC[0]->x[*(s32 *)(v + 0x2A8)];
            }
            *(s32 *)(v + 0x2B8) = -1;
            *(u8 *)(v + 0x33D) = 1;
            *(s32 *)(v + 0x2C4) = p[5];
            func_L40_003ED980(m, *(s32 *)(v + 0x2C0));
        }
        if (*(s32 *)(v + 0x2A8) != -1) {
            *(s32 *)(v + 0x2C0) = D_L41_003575AC[0]->x[*(s32 *)(v + 0x2A8)];
        }
        if (*(s32 *)(v + 0x2C0) != -1) {
            func_L40_0053DAE8(a0, *(s32 *)(v + 0x2C0));
        }
        if (func_L39_005B4398(4000) > 3000) {
            *(u16 *)(m + 0x34) |= 0x8000;
        }
        if (*(s32 *)(v + 0x264) != 0x539) {
            c = *(u8 **)(m + 0x24);
            *(u16 *)(m + 0x34) &= ~0x41;
            *(u16 *)(m + 0x34) |= *(u16 *)(c + 0x44) & 0x1000;
            *(s32 *)(m + 0x98) = *(s32 *)(c + 0x10);
        }
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L41_003EDA60 */
