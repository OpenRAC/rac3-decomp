#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct {
    u8 pad0[0x28];
    s32 w28;
} S_311A18m;
typedef struct {
    u8 pad0[0x10];
    s128 q10;
    u8 b20;
    u8 pad21[0x68 - 0x21];
    S_311A18m *p68;
    u8 pad6C[0xAA - 0x6C];
    s16 hAA;
} S_311A18;


/* localdecomp:start func_L01_003136A0 */
extern void func_0038CE20(f32 *, f32 *, f32);
void func_L01_003136A0(f32 *m, f32 s) {
    func_0038CE20(m, m, s);
    func_0038CE20(m + 4, m + 4, s);
    func_0038CE20(m + 8, m + 8, s);
    func_0038CE20(m + 12, m + 12, s);
}
/* localdecomp:end func_L01_003136A0 */

/* localdecomp:start func_L01_00313708 */
#include "vu0.h"

typedef struct {
    u8 pad0[52];
    f32 f34;
    u8 pad38[72 - 56];
    f32 f48;
    u8 pad4C[96 - 76];
    s32 w60;
    u8 pad64[104 - 100];
    s32 w68;
    u8 pad6C[112 - 108];
    s32 w70;
    u8 pad74[124 - 116];
    s32 w7C;
} S_393258_00313708;

typedef struct {
    f32 m[16];
    u32 c40[4];
    u8 pad50[0x70 - 0x50];
    unsigned long d70;
    unsigned long d78;
    unsigned long d80;
    unsigned long d88;
} S_313708_00313708;

extern f32 D_L01_001E2A40_00313708[];
extern void func_L01_00313618_00313708(S_313708_00313708 *);
extern unsigned long func_00389598(s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038CF38(void *, void *);
extern void func_0038D328(f32 *, f32 *);
extern void func_0038CF68(void *dst, void *src, f32 s);
extern void func_L01_003136A0_00313708(f32 *m, f32 s);
extern void func_003D2DA0(S_313708_00313708 *, f32 *, s32);

void func_L01_00313708(S_393258_00313708 *a0, f32 f12, s32 a1, s32 a2, f32 f13, s32 a3, s32 t0, f32 f14) {
    S_313708_00313708 s;
    f32 m[16];
    f32 r[4];
    vu0_v4 v;
    u32 c;
    f32 *p = (f32 *)a0;

    func_L01_00313618_00313708(&s);
    s.d78 = func_00389598(a3);
    s.d80 = 0xFF9000000260L;
    s.d88 = ((long)t0 << 2) | 0x8000000040L;
    s.d70 = 0;
    c = a1 + (a2 << 24);
    s.c40[3] = c;
    s.c40[2] = c;
    s.c40[1] = c;
    s.c40[0] = c;
    r[3] = 0.0f;
    r[2] = func_0038D160(D_L01_001E2A40_00313708[0] - p[0], D_L01_001E2A40_00313708[1] - p[1]);
    r[1] = -func_0038D160(func_0038CF38(a0, D_L01_001E2A40_00313708), D_L01_001E2A40_00313708[2] - p[2]);
    r[0] = f13;
    func_0038D328(m, r);
    vec_sub_ba(&v, D_L01_001E2A40_00313708, a0);
    func_0038CF68(&v, &v, f14);
    m[12] = p[0] + v.x;
    m[13] = p[1] + v.y;
    m[14] = p[2] + v.z;
    m[15] = 1.0f;
    func_L01_003136A0_00313708(s.m, f12);
    func_003D2DA0(&s, m, 0);
}
/* localdecomp:end func_L01_00313708 */
