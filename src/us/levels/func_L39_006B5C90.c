#include "common.h"

/* NTSC-U counterpart of func_L39_006B8698 (src/levels/39_multiplayer_menu/L39_006B8458.c) */
/* localdecomp:start func_L39_006B5C90 */
typedef struct S_006B8698_W {
    u8 pad[0x60];
    void **vt;
} S_006B8698_W;
typedef struct S_006B8698 {
    u8 pad[0x110];
    S_006B8698_W *w[11];
} S_006B8698;
typedef struct S_006B8698_A {
    f32 x, y, w, h;
    s32 c;
} S_006B8698_A;
typedef struct S_006B8698_B {
    s32 n;
    f32 x, y, w, h;
    s32 c;
} S_006B8698_B;
typedef struct S_006B8698_C {
    f32 x, y, w, h;
    f32 unk10;
    f32 dy;
} S_006B8698_C;
extern S_006B8698_A D_L39_004B1450;
extern S_006B8698_B D_L39_004B1468;
extern S_006B8698_C D_L39_004B1480;
extern S_006B8698_C D_L39_004B14B8;
extern S_006B8698_A D_L39_004B14F0;
extern u8 D_L39_004B1510[];
extern S_006B8698_C D_L39_004B1520;
extern void func_L39_00687B28(void *, s32, f32, f32, f32, f32, s32);
extern void func_L39_00687900(void *, s32, s32, f32, f32, f32, f32, s32);
extern void func_L39_006B5460(void *);
void func_L39_006B5C90(S_006B8698 *p) {
    s32 i;
    f32 y;
    func_L39_00687B28(p, 0, D_L39_004B1450.x, D_L39_004B1450.y, D_L39_004B1450.w, D_L39_004B1450.h, D_L39_004B1450.c);
    func_L39_00687900(p, 0, D_L39_004B1468.n, D_L39_004B1468.x, D_L39_004B1468.y, D_L39_004B1468.w, D_L39_004B1468.h, D_L39_004B1468.c);
    y = D_L39_004B1480.y;
    for (i = 0; i < 7; i++) {
        if (i == 1) {
            ((void (*)(void *, s32, s32))p->w[1]->vt[0x48 / 4])(p->w[1], 1, 3);
            ((void (*)(void *, f32, f32))p->w[1]->vt[0x28 / 4])(p->w[1], D_L39_004B1480.x, y);
            ((void (*)(void *, f32, f32))p->w[1]->vt[0x2C / 4])(p->w[1], D_L39_004B1480.w, D_L39_004B1480.h);
            ((void (*)(void *, s32, s32))p->w[1]->vt[0x4C / 4])(p->w[1], 0x40, 1);
            ((void (*)(void *, s32))p->w[1]->vt[0x40 / 4])(p->w[1], 1);
        } else {
            ((void (*)(void *, f32, f32))p->w[i]->vt[0x28 / 4])(p->w[i], D_L39_004B1480.x, y);
            ((void (*)(void *, f32, f32))p->w[i]->vt[0x2C / 4])(p->w[i], D_L39_004B1480.w, D_L39_004B1480.h);
            ((void (*)(void *, s32))p->w[i]->vt[0x40 / 4])(p->w[i], 1);
            ((void (*)(void *, s32, s32))p->w[i]->vt[0x4C / 4])(p->w[i], 0x40, 1);
        }
        y += D_L39_004B1480.dy;
    }
    ((void (*)(void *, f32, f32))p->w[9]->vt[0x28 / 4])(p->w[9], D_L39_004B14B8.x, D_L39_004B14B8.y);
    ((void (*)(void *, f32, f32))p->w[9]->vt[0x2C / 4])(p->w[9], D_L39_004B14B8.w, D_L39_004B14B8.h);
    ((void (*)(void *, s32, s32))p->w[9]->vt[0x4C / 4])(p->w[9], 0x40, 1);
    ((void (*)(void *, s32))p->w[9]->vt[0x40 / 4])(p->w[9], 1);
    ((void (*)(void *, s32, s32))p->w[9]->vt[0x1C / 4])(p->w[9], 1, 0);
    ((void (*)(void *, f32, f32))p->w[7]->vt[0x28 / 4])(p->w[7], D_L39_004B1480.x, y);
    ((void (*)(void *, f32, f32))p->w[7]->vt[0x2C / 4])(p->w[7], D_L39_004B1480.w, D_L39_004B1480.h);
    ((void (*)(void *, s32))p->w[7]->vt[0x40 / 4])(p->w[7], 1);
    ((void (*)(void *, s32, s32))p->w[7]->vt[0x4C / 4])(p->w[7], 0x40, 1);
    ((void (*)(void *, s32, s32))p->w[7]->vt[0x1C / 4])(p->w[7], 3, 0);
    func_L39_00687B28(p, 1, D_L39_004B14F0.x, D_L39_004B14F0.y, D_L39_004B14F0.w, D_L39_004B14F0.h, D_L39_004B14F0.c);
    func_L39_006B5460(D_L39_004B1510);
    ((void (*)(void *, s32, s32))p->w[8]->vt[0x48 / 4])(p->w[8], 3, 3);
    ((void (*)(void *, f32, f32))p->w[8]->vt[0x28 / 4])(p->w[8], D_L39_004B1520.x, D_L39_004B1520.y);
    ((void (*)(void *, f32, f32))p->w[8]->vt[0x2C / 4])(p->w[8], D_L39_004B1520.w, D_L39_004B1520.h);
    ((void (*)(void *, s32, s32))p->w[8]->vt[0x4C / 4])(p->w[8], 0x40, 1);
    ((void (*)(void *, s32, s32))p->w[8]->vt[0x1C / 4])(p->w[8], 1, 0);
}
/* localdecomp:end func_L39_006B5C90 */
