/* functional: high. Same calls, table math and GS register writes as retail; register allocation differs. The frame mirrors retail's (off 0x00, q 0x10, r2 0x20, view/side/up/pos 0x30-0x6F as the matrix func_0038D028 reads, roll 0x70, rollm 0x80-0xBF): the earlier draft gave rollm only 0x20 bytes, so func_0038D830's 3-row matrix overran the frame's locals. Vector ops are plain C (xyz only, w from the first operand, as retail's destination register keeps it); f14 (callers pass 1.4f) is never read by retail. */
#include "vu0.h"
/* plain-C stand-ins for the vector library's vsub.xyz/vadd.xyz: x/y/z of a op b, w kept from a */
static void fvsub3_L01(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x - ((vu0_v4 *)b)->x;
    r.y = r.y - ((vu0_v4 *)b)->y;
    r.z = r.z - ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
static void fvadd3_L01(void *d, void *a, void *b) {
    vu0_v4 r = *(vu0_v4 *)a;
    r.x = r.x + ((vu0_v4 *)b)->x;
    r.y = r.y + ((vu0_v4 *)b)->y;
    r.z = r.z + ((vu0_v4 *)b)->z;
    *(vu0_v4 *)d = r;
}
typedef struct {
    vu0_v4 off;
    vu0_v4 q;
    vu0_v4 r2;
    vu0_v4 view;
    vu0_v4 side;
    vu0_v4 up;
    vu0_v4 pos;
    vu0_v4 roll;
    vu0_v4 rollm[4]; /* sp+0x80..0xBF in retail: func_0038D830 writes a 3-row matrix here */
} Frame_0040AAC8;
extern vu0_v4 D_L01_001E29C0;
extern f32 D_L01_001E9080[];
extern u32 D_L01_001DFA20[];
extern f32 D_L01_001E9140[];
extern f32 D_L01_002C5200[];
extern f32 D_L01_002C5308[];
extern void func_0038CF68(void *, void *, f32);
extern void func_0038CE90(void *, void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_0038D028(void *, void *, void *);
extern void func_0038D5F0(void *, void *, void *);
extern void func_0038D750(void *, s32, f32);
extern void func_0038D830(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_0038C750(void);
extern long func_00389598(s32);
extern void func_003A9440(s32, unsigned long);
extern void func_003D3A24(s32, void *, void *, void *, s32);
void func_L01_0040AAC8(vu0_v4 *pos, s32 tex0, s32 tex1, s32 col, s32 flag, f32 sz, f32 div, f32 unused, f32 roll, f32 ang, f32 push) {
    Frame_0040AAC8 f;
    f32 one, half, sn, cs, tA, tB;
    s32 i, j;
    one = 1.0f;
    f.pos = *pos;
    fvsub3_L01(&f.view, &D_L01_001E29C0, &f.pos);
    func_0038CF68(&f.view, &f.view, one);
    func_0038CE90(&f.side, &f.view, (u8 *)&D_L01_001E29C0 + 0x40);
    func_0038CF68(&f.side, &f.side, one);
    func_0038CE90(&f.up, &f.side, &f.view);
    if (roll != 0.0f) {
        func_0038D750(&f.roll, 0, roll);
        func_0038D830(&f.roll, &f.rollm[0]);
        func_0038D5F0(&f.view, &f.view, &f.rollm[0]);
    }
    div = one / div;
    func_0038CE20(&f.off, &f.view, push);
    fvadd3_L01(&f.pos, &f.pos, &f.off);
    func_0038CE20(&f.side, &f.side, sz);
    func_0038CE20(&f.up, &f.up, sz);
    half = 0.5f;
    qzero(&f.q);
    for (i = 0; i < 16; i++) {
        j = (i * ((((i & 1) << 1) - 1) << 2)) & 0x3C;
        tA = D_L01_002C5200[j];
        tB = D_L01_002C5308[j];
        f.q.z = tA;
        f.q.y = tB;
        func_0038D028(&f.r2, &f.q, &f.view);
        D_L01_001E9080[i * 3] = f.r2.x;
        D_L01_001E9080[i * 3 + 1] = f.r2.y;
        D_L01_001E9080[i * 3 + 2] = f.r2.z;
        D_L01_001DFA20[i] = 0x80808080;
        D_L01_001E9140[i * 2] = f.q.y * half * div + half;
        D_L01_001E9140[i * 2 + 1] = f.q.z * half * div + half;
    }
    func_003A9440(8, 5);
    func_003A9440(0x14, 0xFF9000000260UL);
    func_003A9440(0x47, 0x513F1UL);
    func_0038C750();
    func_003A9440(6, func_00389598(tex0));
    func_003A9440(0x42, 0x800000006AUL);
    func_003D3A24(16, D_L01_001E9080, D_L01_001DFA20, D_L01_001E9140, 1);
    sn = func_0038D098(ang);
    cs = func_0038D0B0(ang);
    for (i = 0; i < 16; i++) {
        j = (i * ((((i & 1) << 1) - 1) << 2)) & 0x3C;
        D_L01_001DFA20[i] = col;
        tA = D_L01_002C5200[j];
        tB = D_L01_002C5308[j];
        f.q.z = tA;
        f.q.y = tB;
        D_L01_001E9140[i * 2 + 1] = (tA * sn + tB * cs) * half * div + half;
        D_L01_001E9140[i * 2] = (tB * sn - tA * cs) * half * div + half;
    }
    func_003A9440(6, func_00389598(tex1));
    if (flag != 0) {
        func_003A9440(0x42, 0x8000000054UL);
    } else {
        func_003A9440(0x42, 0x8000000058UL);
    }
    func_003D3A24(16, D_L01_001E9080, D_L01_001DFA20, D_L01_001E9140, 1);
    func_003A9440(0x47, 0x5360BUL);
}
