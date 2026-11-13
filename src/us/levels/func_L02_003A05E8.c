#include "common.h"

/* NTSC-U counterpart of func_L02_003A23C8 (src/levels/02_florana/L02_003A0EE8.c): 0.0314159 -> 0.0261799; 0.125664 -> 0.10472; 100 -> 120; 0.00392 -> 0.00272222; 50 -> 60 */
/* localdecomp:start func_L02_003A05E8 */
typedef struct V4_3A23C8 { float x, y, z, w; } __attribute__((aligned(16))) V4_3A23C8;
typedef struct P_3A23C8 {
    u8 pad0[4]; u8 f4; u8 pad5; s16 f6; float f8; u8 padC[0x14];
    s32 f20; float f24; float f28; s16 f2C; s16 f2E;
} P_3A23C8;
typedef struct O_3A23C8 {
    u8 pad0[0x10]; V4_3A23C8 v; u8 f20; u8 pad21[0xB]; float f2C; u8 f30; u8 f31; s16 f32;
    u8 pad34[0x34]; P_3A23C8 *p;
} O_3A23C8;
extern O_3A23C8 *func_003C24B0(int a, int b);
extern float func_003824E0(float a, float b);
extern void func_003C7C38(O_3A23C8 *o);

void func_L02_003A05E8(int arg0, int arg1) {
    O_3A23C8 *o;
    P_3A23C8 *p;
    V4_3A23C8 t;
    o = func_003C24B0(0x1976, 0x80);
    if (o != 0) {
        p = o->p;
        p->f28 = func_003824E0(0.0261799414f, 0.104719765f);
        p->f20 = 120;
        p->f24 = (arg1 == 0) ? 0.65f : 0.98f;
        p->f2C = 0x3C;
        p->f2E = 7;
        p->f8 = 0.00272222236f;
        p->f4 = arg1;
        p->f6 = arg1;
        if (arg1 == 1) o->f2C *= 1.5f;
        o->f30 = 0xFF;
        o->f32 = 0xFF;
        o->f20 = 2;
        o->f31 = 1;
        switch (arg0) {
        case 0:
            if (arg1 == 0) { t.x = 139.304f; t.y = 288.992f; t.z = 42.556f; t.w = 0; }
            else { t.x = 225.54f; t.y = 211.71f; t.z = 54.05f; t.w = 0; }
            break;
        case 1:
            if (arg1 == 0) { t.x = 141.0f; t.y = 289.023f; t.z = 42.592f; t.w = 0; }
            else { t.x = 223.19f; t.y = 213.85f; t.z = 54.05f; t.w = 0; }
            break;
        case 2:
            if (arg1 == 0) { t.x = 142.685f; t.y = 288.919f; t.z = 42.61f; t.w = 0; }
            else { t.x = 221.01f; t.y = 215.79f; t.z = 54.05f; t.w = 0; }
            break;
        }
        o->v = t;
        func_003C7C38(o);
    }
}
/* localdecomp:end func_L02_003A05E8 */
