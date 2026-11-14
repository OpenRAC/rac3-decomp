#include "common.h"

/* NTSC-U counterpart of func_L40_003D8FB0 (src/levels/shared/L40_003D88A8.c) */
extern s32 D_L40_00242AB0;
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L39_005F08F8(void *, s32);
extern void func_L39_005F0CE0(s32, s32, void *);

/* localdecomp:start func_L40_003D8DC0 */
typedef struct N_003D8FB0 N_003D8FB0;
extern u8 D_001A5E50[];
extern s32 D_L40_00242AB0;
__asm__(".extern D_L40_00242AB0, 16");
extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L01_0044ED60(void *, s32, u8 *, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, f32, f32, s32, s32);
extern void func_L39_005F0CE0(s32, s32, void *);
extern void func_L40_0053CE30(void *);
extern s32 func_L40_0053B368(s32 id);
extern void func_L39_005F08F8(void *, s32);
extern s32 *func_L39_00669AC0(s32 *n, s32 **head);

void func_L40_003D8DC0(s32 a0, u8 *a1) {
    u8 *r;
    s32 *p;
    s32 *q;

    r = *(u8 **)(a1 + 0x90);
    p = *(s32 **)(r + 0x38);
    while (p != 0) {
        u8 *g = D_001A5E50;
        q = p + 2;
        if (*(s32 *)(g + 0x128) < q[2]) {
            p = (s32 *)p[0x21];
            continue;
        }
        switch (q[0]) {
        case 1:
            if (q[3] != 0) {
                continue;
            }
            func_L01_00441FB8(a1, 2, -1);
            break;
        case 2:
            func_L01_0044ED60(a1, 0xF, (u8 *)&D_L40_00242AB0, 0xFF, 0xB4, 0, 0, 0x23, 3.0f, 7.0f, 4.0f, 7.0f, -1.0f, -1.0f, 1.0f, 1.0f, 0, 3);
            func_L39_005F0CE0(2, 0, a1);
            func_L40_0053CE30(a1);
            func_L40_0053B368(a0);
            *(s32 *)(a1 + 0x98) = 0;
            *(u16 *)(a1 + 0x34) = (*(u16 *)(a1 + 0x34) | 0x41) & 0xEFFF;
            func_L39_005F08F8(a1, 1);
            func_L01_00441FB8(a1, 0x25, -1);
            return;
        }
        p = func_L39_00669AC0(p, (s32 **)(r + 0x38));
    }
}
/* localdecomp:end func_L40_003D8DC0 */
