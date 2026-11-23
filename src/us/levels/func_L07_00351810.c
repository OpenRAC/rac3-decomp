#include "common.h"

/* localdecomp:start func_L07_00351810 */
typedef struct {
    u8 pad0[48];
    f32 hp;
    s16 life;
    u8 pad36[14];
    u8 d0;
    u8 d1;
    u8 d2;
    u8 pad47[57];
    u8 b80;
    u8 pad81[31];
    f32 a0;
    f32 a4;
    u8 padA8[4];
    f32 ac;
    u8 padB0[8];
    u8 b8;
    u8 padB9[103];
    f32 f120;
    s32 flags;
    u8 pad128[40];
    f32 f150;
    f32 f154;
    f32 f158;
    f32 f15c;
    f32 f160;
    u8 pad164[24];
    f32 f17c;
    f32 f180;
    f32 f184;
    u8 pad188[188];
    void (*cb244)(s32);
    void (*cb248)(s32);
    s16 h24c;
    u8 pad24E[15];
    u8 b25d;
    u8 pad25E[1];
    u8 b25f;
    u8 pad260[512];
    s32 f460;
} Vars_00351810;
void func_L07_00351810(u8 *self) {
    extern s32 func_L07_003C01A8(void);
    extern f32 func_L07_003C01F0(s32);
    extern void func_L01_00442F20(void *, s32, s32);
    extern void func_L01_00458A70(void *, f32, f32, f32, f32);
    extern void func_L07_00351D88(s32);
    extern void func_L07_00351D58(s32);
    Vars_00351810 *v = *(Vars_00351810 **)(self + 0x68);
    s32 mode = func_L07_003C01A8();
    u8 *p = (u8 *)v + 0x30;
    f32 factor = func_L07_003C01F0(mode);
    *(s16 *)(p + 4) = v->life * factor;
    v->hp = *(s16 *)(p + 4);
    p[0x14] = v->d0 * factor;
    p[0x15] = v->d1 * factor;
    p[0x16] = v->d2 * factor;
    if (mode == 1 || mode == 3) {
        func_L01_00442F20(self, 0x1D8B, 0x1769);
    }
    p[0x28] = 20;
    p[0x2A] = 14;
    *(f32 *)(p + 0x10) = 1.25f;
    p[0xF] = 0;
    p[9] = 0;
    v->b8 = 255;
    v->b80 = 5;
    v->f120 = 1.0f;
    v->flags |= 1;
    v->f150 = 0.65f;
    v->a4 = v->a0 = 0.5f;
    v->f154 = v->ac = 0.15f;
    v->f15c = v->f158 = 0.5f;
    v->f160 = 3.1415927f;
    v->f180 = 0.7853982f;
    v->f17c = 0.0027222224f;
    v->f184 = 0.2f;
    func_L01_00458A70(self, 0.0022222223f, 0.041666668f, 0.0034906587f, 0.104719765f);
    {
        void (*cb244)(s32) = func_L07_00351D88;
        void (*cb248)(s32) = func_L07_00351D58;
        v->f460 = 0;
        v->cb248 = cb248;
        v->b25d = 2;
        v->h24c = -1;
        v->b25f = 7;
        v->cb244 = cb244;
    }
    func_L07_00351D58((s32)self);
}
/* localdecomp:end func_L07_00351810 */
