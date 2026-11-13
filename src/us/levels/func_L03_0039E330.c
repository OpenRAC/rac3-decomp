#include "common.h"

/* NTSC-U counterpart of func_L03_0039FB18 (src/levels/03_starship_phoenix/L03_0039E470.c): 0.0432 -> 0.03; 0.432 -> 0.3 */
void func_L01_00402498(void *, void *);
void func_L03_0032D708(void *, s32, s32);
void func_L03_0032D850(void *);
void func_003A52A0(s32, s32, void *);
void func_L03_0032F4F8(void *);
void func_003C2F58(void *, s32, void *);
void func_003C2EC0(void *, s32, void *);
void func_0038D590(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_003C7C38(void *);
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
void func_L01_0044B5C8(void *, void *, s32, f32, f32);
f32 func_L01_0040C018(void *, void *);
void func_L01_00444188(void *);
extern u8 D_L03_001E2540[];
void func_003C7C38(void *);
extern void func_003C2EC0(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);

/* localdecomp:start func_L03_0039E330 */
typedef struct {
    u8 pad0[0x30]; f32 f30;
    u8 pad34[0x3E - 0x34]; u8 b3E; u8 pad3F[0x5E - 0x3F]; u8 b5E; u8 pad5F; u8 b60;
    u8 pad61[0x70 - 0x61]; u8 a70[0xC0];
    f32 f130; f32 f134;
    u8 pad138[0x188 - 0x138]; s32 i188;
    u8 pad18C[0x228 - 0x18C]; s32 i228;
    u8 pad22C[0x270 - 0x22C]; u8 a270[0x68];
    f32 f2D8; u8 pad2DC[0x2F0 - 0x2DC]; u8 a2F0[0x450 - 0x2F0];
    u8 *p450; u8 pad454[0x45B - 0x454]; u8 b45B;
} P_0039FB18;
typedef struct {
    u8 pad0[0x10]; f32 x; f32 y; u8 pad18[0x8]; u8 st; u8 pad21[0x10]; u8 f31;
    u8 pad32[0x68 - 0x32]; P_0039FB18 *p; u8 pad6C[3]; u8 b6F; u8 pad70[0x88]; f32 fF8;
} S_0039FB18;
void func_L01_00402498(void *, void *);
s32 func_L01_0044FCD0(void *, void *, s32, s32, s32);
void func_L01_0044B4B8(void *);
void func_L03_0032D348_0039E330(void *);
void func_L03_0032D708(void *, s32, s32);
void func_L03_0032D850(void *);
void func_003A52A0(s32, s32, void *);
void func_L03_0032F4F8(void *);
void func_003C2F58(void *, s32, void *);
void func_003C2EC0(void *, s32, void *);
void func_0038D590(void *, void *);
void func_0038CF68(void *, void *, f32);
void func_003C7C38(void *);
f32 func_0038D160(f32, f32);
f32 func_0038DB00(f32, f32);
void func_L01_0044B5C8(void *, void *, s32, f32, f32);
f32 func_L01_0040C018(void *, void *);
void func_L01_00444188(void *);
void func_L03_0039ECE8(void *);
extern u8 D_L03_001E2540[];
void func_L03_0039E330(S_0039FB18 *s) {
    P_0039FB18 *p;
    char buf[0x40];
    f32 one;
    f32 a;
    p = s->p;
    if (s->st == 1) return;
    if (p->i228 == 1) {
        func_L01_00402498(func_L03_0039ECE8, s);
        if (p->b45B < 15) p->b45B++;
    } else if (p->b45B != 0) {
        func_L01_00402498(func_L03_0039ECE8, s);
        p->b45B--;
    }
    if (func_L01_0044FCD0(s, p->a70, 0, 0, 0)) {
        func_L01_0044B4B8(p->a2F0);
        func_L03_0032D348_0039E330(s);
        p->i188 &= ~0x10;
    }
    if (p->f30 <= 0.0f) {
        func_L03_0032D708(s, 7, 1);
        func_L03_0032D850(s);
        func_003A52A0(7, 0, s);
        return;
    }
    if (p->b5E != 0 || p->b60 != 0 || p->b3E == 2) {
        func_L03_0032D850(s);
        return;
    }
    func_L03_0032F4F8(s);
    if (p->p450 != 0) {
        one = 1.0f;
        func_003C2F58(s, 0, p->p450 + 0x10);
        func_003C2EC0(s, 0, buf);
        func_0038D590(p->p450 + 0xC0, buf);
        func_0038CF68(p->p450 + 0xC0, p->p450 + 0xC0, one);
        func_0038CF68(p->p450 + 0xD0, p->p450 + 0xD0, one);
        func_0038CF68(p->p450 + 0xE0, p->p450 + 0xE0, one);
        func_003C7C38(p->p450);
    }
    if (s->st >= 6) {
        a = func_0038DB00(func_0038D160(p->f130 - s->x, p->f134 - s->y), s->fF8);
        p->f2D8 = a;
        if (a > 1.04719758f) p->f2D8 = 1.04719758f; else if (a < -1.04719758f) p->f2D8 = -1.04719758f;
    }
    func_L01_0044B5C8(s, p->a270, 1, 0.0299999993f, 0.300000012f);
    if (s->f31 != 0) {
        if (func_L01_0040C018(D_L03_001E2540, &s->x) < 576.0f) {
            func_L01_00444188(s);
            s->b6F = 22;
        }
    }
}
/* localdecomp:end func_L03_0039E330 */
