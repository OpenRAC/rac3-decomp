/* functional: medium. Same calls/arguments/order as retail; the effect record is one local struct (retail overlaps its UV pairs, the quad corners and a few vector temps in one stack frame). r[3].x/.y are carried from the first block into the second as in retail. Retail forms D_L01_001E16D0/001E29C0 only through lqc2 (opcode 0x36), which tools/fcheck.py ADDRESS_OPS does not count, so the gate lists them as refs not in retail although retail reads them (lines 0030335C-0030336C, 00303570-00303578). */
#include "common.h"
#include "vu0.h"

typedef struct {
    vu0_v4 m[4];
    s32 c40, c44, c48, c4C;
    f32 uv[8];
    long x70, x78, x80, x88;
    f32 r[4][4];
    f32 rot[4];
} S_00303228;

extern vu0_v4 D_L01_001E16D0;
extern f32 D_L01_001E16E4;
extern vu0_v4 D_L01_001E29C0;
extern u8 D_L01_002A7CA0[];
extern u8 D_L01_002A7DA0[];
extern s32 D_L01_001DC580;
__asm__(".extern D_L01_001DC580, 4");
extern s32 D_L01_001DC584;
__asm__(".extern D_L01_001DC584, 4");
extern s32 D_L01_001DC588;
__asm__(".extern D_L01_001DC588, 4");
extern s32 D_L01_001DC58C;
__asm__(".extern D_L01_001DC58C, 4");
extern s32 D_L01_001DC590;
__asm__(".extern D_L01_001DC590, 4");
extern s32 D_L01_001DC594;
__asm__(".extern D_L01_001DC594, 4");
extern s32 D_L01_001DC598;
__asm__(".extern D_L01_001DC598, 4");
extern s32 D_L01_001DC59C;
__asm__(".extern D_L01_001DC59C, 4");
extern s32 D_L01_001DC5AC;
__asm__(".extern D_L01_001DC5AC, 4");
extern f32 D_L01_001DC5B0;
__asm__(".extern D_L01_001DC5B0, 4");
extern s16 D_L01_001DC560[16];
__asm__(".extern D_L01_001DC560, 32");

extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003C5278(void *, void *, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern f32 func_003824E0(f32, f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_003D9508(void *, s32, s32, s32, f32, f32, f32);
extern s32 func_L01_00301788(u8 *);
extern void func_0038D028(void *, void *, void *);
extern void func_0038CFB8(void *, void *, f32);
extern f32 func_L01_0040F518(f32, f32);
extern void func_003D2DA0(void *, void *, s32);

void func_L01_00303228(u8 *self) {
    S_00303228 s;
    vu0_v4 e;
    vu0_v4 d;
    u8 *st;
    u8 *spos;
    u8 *q;
    u8 *tab;
    s32 col;
    s32 i;
    s32 j;
    s16 *ip;
    f32 ang;
    f32 u;
    f32 v;

    st = *(u8 **)(self + 0x68);
    if (st == 0) {
        return;
    }
    spos = st + 0x10;
    s.x78 = func_00389598(D_L01_001DC594);
    s.x88 = (long)D_L01_001DC580 | ((long)D_L01_001DC584 << 2) | ((long)D_L01_001DC588 << 4) |
            ((long)D_L01_001DC58C << 6) | ((long)D_L01_001DC590 << 32);
    s.x80 = 0xFF9000000260L; /* ori 0xFF90; dsll32; ori 0x260 */
    s.x70 = 0;
    func_003A9440(0x47, 0x53001);
    if (self[0x20] == 1) {
        q = *(u8 **)(self + 0xB8);
        *(vu0_q *)(self + 0x10) = *(vu0_q *)(q + 0x10);
        *(vu0_q *)(st + 0x10) = *(vu0_q *)(q + 0x10);
        func_003C5278(self + 0x10, spos, spos, -0.5f);
    }
    s.r[3][0] = *(f32 *)(self + 0x10);
    s.r[3][1] = *(f32 *)(self + 0x14);
    s.r[3][2] = *(f32 *)(self + 0x18);
    func_003C5278(self + 0x10, s.r[3], s.r[3], -0.5f - *(f32 *)st);
    s.r[3][3] = 1.0f;
    s.r[3][0] += D_L01_001E16D0.x;
    s.r[3][1] += D_L01_001E16D0.y;
    s.r[3][2] += D_L01_001E16D0.z;
    e.x = D_L01_001E29C0.x - s.r[3][0];
    e.y = D_L01_001E29C0.y - s.r[3][1];
    e.z = D_L01_001E29C0.z - s.r[3][2];
    e.w = s.r[3][3];
    func_0038CF68(s.r[0], &e, 1.0f);
    func_0038CE90(s.r[1], s.r[0], *(u8 **)(self + 0xB8) + 0xE0);
    func_0038CF68(s.r[1], s.r[1], 1.0f);
    func_0038CE90(s.r[2], s.r[1], s.r[0]);
    if (st[0x57] != 0) {
        col = D_L01_001DC59C;
    } else {
        col = D_L01_001DC598;
    }
    s.c40 = col;
    s.c4C = col;
    s.c48 = col;
    s.c44 = col;
    ang = func_003824E0(-0.15f, -0.3f);
    D_L01_001E16E4 = func_0038DAB8(D_L01_001E16E4, ang * 0.017453292f);
    func_003D9508(spos, 0x59, (st[0x57] != 0) ? 0x4F7F207F : 0x4FFF2020, 1, 0.4f, 0.0f, D_L01_001E16E4);
    if (func_L01_00301788(self) != 0) {
        s.x78 = func_00389598(D_L01_001DC5AC);
        s.c40 = 0x107F7F7F;
        s.c4C = 0x107F7F7F;
        s.c48 = 0x107F7F7F;
        s.c44 = 0x107F7F7F;
        s.x88 = 0x8000000044L;
        q = *(u8 **)(self + 0xB8);
        *(vu0_q *)s.r[0] = *(vu0_q *)(q + 0xC0);
        *(vu0_q *)s.r[1] = *(vu0_q *)(q + 0xD0);
        *(vu0_q *)s.r[2] = *(vu0_q *)(q + 0xE0);
        s.r[3][2] = *(f32 *)(self + 0x18);
        if (*(s16 *)(q + 0xAA) == 0x1F5) {
            tab = D_L01_002A7DA0;
        } else {
            tab = D_L01_002A7CA0;
        }
        for (i = 0; i < 4; i++) {
            ip = &D_L01_001DC560[i * 4];
            for (j = 0; j < 4; j++) {
                func_0038D028(&s.m[j], tab + ip[j] * 16, s.r[0]);
                d.x = s.m[j].x - D_L01_001E29C0.x;
                d.y = s.m[j].z - D_L01_001E29C0.z;
                d.z = s.m[j].z - D_L01_001E29C0.z;
                d.w = s.m[j].w;
                func_0038CFB8(&d, &d, D_L01_001DC5B0);
                u = d.x * 0.5f + 0.5f;
                s.uv[j * 2] = u;
                s.uv[j * 2] = func_L01_0040F518(u, 8.0f);
                v = d.y * 0.5f + 0.5f;
                s.uv[j * 2 + 1] = v;
                s.uv[j * 2 + 1] = func_L01_0040F518(v, 8.0f);
            }
            func_003D2DA0(&s, 0, 0);
        }
    }
    func_003A9440(0x47, 0x5360B);
}
