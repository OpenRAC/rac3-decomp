#include "common.h"

/* --- declarations from other files (tools/split_text.py --refresh) --- */
extern f32 func_003C3BE8(f32, f32, f32);
extern void (*D_001D9A40[2])(s32);
extern void (*D_001D9A40_00382B20[1])(s32);
typedef int u128_t __attribute__((mode(TI)));
extern void (*D_00226800[])(s32);
extern void (*D_00226C00[])(s32);
extern void (*D_00226E00[])(s32);
extern void (*D_00226A00[])(s32);
extern void func_0038CC88_00391678(void *, void *, s32) __asm__("func_0038CC88");
/* --- end of declarations from other files --- */

LINKER_REMNANT("asm/remnants", func_003C3920);

/* localdecomp:start func_003C3938 */
extern void func_0038CE20(f32 *, void *, f32);
typedef struct { u8 p10[0x10]; u8 n; u8 f11; } T_3BE418;
typedef struct { u8 p0[0x48]; T_3BE418 *e[1]; } Q_3BE418;
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; s32 f44; f32 f48; f32 f4C; u8 p50[8]; f32 *f58; u8 p5c[4]; u8 f60; u8 p61[0xB]; u8 f6C;
} S_3BE418;
extern void func_003C29B0();
void func_003C3938(S_3BE418 *p, s32 idx, s32 lim) {
    s32 v;
    s32 n;
    v = lim;
    if (!(lim < p->f24->e[idx]->n)) v = p->f24->e[idx]->n - 1;
    p->f42 = idx;
    p->f40 = v;
    p->f41 = v + 1;
    n = p->f24->e[idx]->n - 1;
    if (n < p->f41) p->f41 = n;
    p->f43 = idx;
    p->f44 = 0;
    if (!(p->f41 < p->f24->e[idx]->n)) p->f41 = 0;
    func_003C29B0(p);
    p->f4C = *p->f58;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003C3938 */

/* localdecomp:start func_003C3A10 */
/* func_003C3A10: written from the assembly. lim clamped in place (a separate v gave 7 register
   diffs). Only the 2 nops before div.s differ: DIVS, count 2. */
typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_003C3A10;
extern u128_t D_002DA100[];
extern void func_003C6EA0_003C3A10(void *, s32, u16);
extern s32 func_003C2D30();
extern void func_003C8B18();
void func_003C3A10(S_003C3A10 *p, s32 idx, s32 lim, s32 frames) {
    s32 r;
    if (lim >= p->f24->e[idx]->n) lim = p->f24->e[idx]->n - 1;
    if (frames <= 0) {
        func_003C3938((S_3BE418 *)p, idx, lim);
        return;
    }
    if (p->f42 == p->f43) {
        if (p->f60 & 2) p->f44 = 0.0f;
    }
    if (lim >= 1 && lim <= 11) func_003C6EA0_003C3A10(p, idx, lim);
    if (p->f44 > 0.025f || p->f50 != 0 || p->f54 != 0) {
        r = func_003C2D30(p);
        if (r >= 0) {
            func_003C8B18(p, r | 0x300);
            D_002DA100[r] = p->f80;
            if (p->f42 != 0xFF) p->fA9 = p->f42;
            p->f42 = 0xFF;
            p->f40 = r;
        }
    }
    p->f41 = lim;
    p->f43 = idx;
    func_003C29B0(p);
    p->f48 = 1.0f;
    p->f44 = 0.0f;
    p->f4C = 1.0f / (f32)frames;
    p->f60 &= 0xFD;
    p->f6C = p->f24->e[idx]->f11;
}
/* localdecomp:end func_003C3A10 */
TEXT_PADDING(4);

typedef struct {
    u8 p0[0x24]; Q_3BE418 *f24; u8 p28[0x18];
    u8 f40; u8 f41; u8 f42; u8 f43; f32 f44; f32 f48; f32 f4C; void *f50; void *f54; u8 p58[8]; u8 f60; u8 p61[0xB]; u8 f6C;
    u8 p6D[0x13]; u128_t f80; u8 p90[0x19]; u8 fA9;
} S_3BE4F0;
extern u128_t D_002DA100[];
extern void func_003C6EA0_003BE4F0();
extern s32 func_003C2D30();
extern void func_003C8B18();

LINKER_REMNANT("asm/remnants", func_003C3BC8);

extern f32 func_0038D098(f32);
/* localdecomp:start func_003C3BE8 */
extern f32 func_0038D098 (f32);

/* from rac2-decomp's func_002A7C00, renamed */
f32 func_003C3BE8 (f32 a, f32 b, f32 t)
{
  f32 u;
  if (t == 0.0f)
    return a;
  if (t == 1.0f)
    return b;
  u = (1.0f - func_0038D098 (t * 3.1415927f)) * 0.5f;
  return a + (b - a) * u;
}
/* localdecomp:end func_003C3BE8 */

LINKER_REMNANT("asm/remnants", func_003C3C80);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_3BE7F0;
extern V_3BE7F0 D_00227660;
s32 func_003D3CB0(V_3BE7F0 *, V_3BE7F0 *, s32, s32, s32);
/* localdecomp:start func_003C3D30 */
/* the same code as boot_elf's func_003C40E8 */
f32 func_003C3D30(V_3BE7F0 *p, s32 flags, s32 c, f32 dz) {
    V_3BE7F0 a = *p;
    V_3BE7F0 b = *p;
    a.z = 0.01f;
    b.z += dz;
    if (func_003D3CB0(&b, &a, flags | 2, c, 0)) return D_00227660.z;
    return 0.0f;
}
/* localdecomp:end func_003C3D30 */

/* localdecomp:start func_003C3DA0 */
typedef int Q_3BE860 __attribute__((mode(TI)));
extern V_3BE7F0 D_001A4C90;
extern void func_003C5180_003C3DA0();
s32 func_003C3DA0(V_3BE7F0 *out, void *obj, s32 flags, s32 c, f32 scale) {
    V_3BE7F0 a, b, d;
    Q_3BE860 x, y;
    func_003C5180_003C3DA0(obj, &d, 1);
    a = D_001A4C90;
    func_0038CE20((f32 *)&b, &d, scale);

    __asm__("lqc2 %0, %1" : "=j"(y) : "m"(*(V_3BE7F0 *)obj));
    __asm__("lqc2 %0, %1" : "=j"(x) : "m"(b));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(x) : "j"(x), "j"(y));
    __asm__("sqc2 %1, %0" : "=m"(b) : "j"(x));
    if (func_003D3CB0(&b, &a, flags | 2, c, 0)) {
        *out = D_00227660;
        return 1;
    }
    *out = a;
    return 0;
}
/* localdecomp:end func_003C3DA0 */

LINKER_REMNANT("asm/remnants", func_003C3E88);
