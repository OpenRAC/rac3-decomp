/* functional: high. Written from the PAL assembly (the NTSC-U twin draft differs in constants and ranges); 346 words differ with the file's flags (same jal list and order, same instruction mix). Needs -mvu0-use-vf0-vf2 for the vec_* helpers (the file's flag line lacks it). The hit record is scaled once before being filled, as retail does. */
#include "vu0.h"
extern s32 D_L01_001DDB8C;
extern s32 D_L01_001DAFEC;
__asm__(".extern D_L01_001DDB8C, 4");
__asm__(".extern D_L01_001DAFEC, 4");
extern u8 D_L01_001E2880[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
extern u8 *D_L01_001EEA80[];
extern void func_003A52A0(s32, s32, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_00382538(void);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_00382498(s32, s32);
extern void func_L01_004668A0(void *, void *, s32, s32, f32, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_L01_00443A18(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_L01_004749C8(void *, void *, s32);
extern void func_L01_003D6158(void *, s32, s32, s32, s32, f32, f32);
extern void func_L01_003002A8(void *, void *, void *);
extern u8 *func_L01_003303B8(void *, s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                             s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003D4D00(void *, s32, void *, s32, f32);
extern void func_0038CF68(f32 *, f32 *, f32);
extern void func_L01_00446760(void *, void *, s32, void *, f32);
extern void func_L01_00446978(void *, void *);
extern void func_L01_003D4750(void *);
extern void func_003C2880(void *);
void func_L01_0039FEB0(u8 *m) {
    vu0_v4 v90, va0;
    struct { vu0_v4 v; u8 pad10[8]; u8 b18, b19; u16 h1a; u8 pad1c[4]; s32 w20; } hit;
    s32 i, n;
    u8 *spawn;
    u8 **items;
    f32 a, b, c, angle, speed;
    if (m) func_003A52A0(1, 0, m);
    for (i = 0; i < 25 - D_L01_001DDB8C; i++) {
        a = func_003824E0(0.0f, 0.37f); b = func_00382538(); c = func_00382538();
        func_00382760(&va0, a, b, c);
        va0.z += func_003824E0(0.35f, 0.6f);
        vec_add_ba(&va0, &va0, m + 0x10);
        a = func_003824E0(0.003f, 0.024f); b = func_00382538(); c = func_00382538();
        func_00382760(&v90, a, b, c);
        func_L01_004668A0(&va0, &v90, 0x4F7F7F7F, 0x202020, 150000.0f, func_00382498(25, 47));
    }
    for (i = 0; i < 30 - D_L01_001DDB8C; i++) {
        angle = func_0038D160(*(f32 *)(D_L01_001E2880 + 0x140) - *(f32 *)(m + 0x10), *(f32 *)(D_L01_001E2880 + 0x144) - *(f32 *)(m + 0x14));
        func_L01_00443A18(1.0f, 2.0f);
        v90.x = *(f32 *)(m + 0x10) + func_L01_00443A18(0.0f, 0.15f);
        v90.y = *(f32 *)(m + 0x14) + func_L01_00443A18(0.0f, 0.15f);
        v90.z = *(f32 *)(m + 0x18) + func_L01_00443A18(0.0f, 0.15f);
        speed = func_003824E0(3.0f, 7.0f) * 0.02f;
        angle = func_0038DAB8(angle, func_L01_00443A18(0.0f, 2.61799383f));
        va0.x = func_0038D098(angle) * speed;
        va0.y = func_0038D0B0(angle) * speed;
        va0.z = 0.0f;
        va0.z = func_003824E0(5.0f, 10.0f) * 0.02f;
        func_L01_004749C8(&v90, &va0, 142);
    }
    func_L01_003D6158(m, 78, 79, 10, 1, 1.5f, 1.2f);
    for (i = 9; i >= 0; i--) {
        a = func_003824E0(0.0f, 0.35f); b = func_00382538(); c = func_00382538();
        func_00382760(&va0, a, b, c);
        va0.z += 0.25f;
        vec_add_ba(&va0, &va0, m + 0x10);
        a = func_003824E0(0.06f, 0.12f); b = func_00382538();
        func_00382760(&v90, a, b, 1.22173047f);
        v90.z = func_003824E0(3.0f, 5.0f) * 0.02f;
        func_L01_003002A8(m, &va0, &v90);
    }
    spawn = func_L01_003303B8(m + 0x10, 1, 25, 20, 20, 20, 45, 2, 0.8f, 0.0f, 0.0f, 0.0f,
                              0, 1, 1, 0, 0, 0, 0x10000, D_L01_001DAFEC, 0x388EF7, 0x63F7, 0x407FFF,
                              0x20FF, 0x8FFF, 0x3064FF, 0x7F60A0FF, 0x280000FF, 0x3064FF, 0);
    if (spawn) *(s32 *)(spawn + 0xB8) = *(s32 *)(m + 0xB8);
    n = func_003D4D00(m + 0x10, 0, m, 0, 3.0f);
    items = D_L01_001EEA80;
    while (n > 0) {
        u8 *o = *items;
        if ((*(u8 **)(o + 0x24))[0x46] == 5 || (*(u16 *)(o + 0x34) & 0x4000)) {
            vec_sub_ba(&v90, o + 0x10, m + 0x10);
            func_0038CF68((f32 *)&v90, (f32 *)&v90, 1.0f);
            func_0038CF68((f32 *)&hit, (f32 *)&hit, 1.0f); /* retail scales the not yet written hit record here */
            func_L01_00446760(&hit, m, 0x1010000, &v90, *(f32 *)(D_L01_002C5600 + D_001425C0[0x8F] * 240 + 0x6C) * 0.2f);
            hit.v = v90;
            hit.v.w = 5627.9248f;
            hit.w20 = 1;
            hit.b18 = 5;
            hit.b19 = 3;
            hit.h1a = *(u16 *)(o + 0xAA);
            func_L01_00446978(o, &hit);
        }
        n--;
        items++;
    }
    D_L01_001DDB8C--;
    func_L01_003D4750(m);
    func_003C2880(m);
}
