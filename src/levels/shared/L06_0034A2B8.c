#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L06_0034A2B8 */
__asm__(".extern D_L24_001DD598, 4");
__asm__(".extern D_L24_001DD59C, 4");
__asm__(".extern D_L24_001DD5A0, 4");
__asm__(".extern D_L24_001DD5A4, 4");
__asm__(".extern D_L24_001DD5A8, 4");
__asm__(".extern D_L24_001DD5AC, 4");
__asm__(".extern D_L24_001DD5B0, 4");
__asm__(".extern D_L24_001DD5B4, 4");
extern u32 D_L24_001DD598;
extern f32 D_L24_001DD59C;
extern f32 D_L24_001DD5A0;
extern u32 D_L24_001DD5A4;
extern f32 D_L24_001DD5A8;
extern f32 D_L24_001DD5AC;
extern u32 D_L24_001DD5B0;
extern f32 D_L24_001DD5B4;
extern void func_L01_0040A8C0(void *, void *, u32, s32, u32, u32, u32, u32, f32, f32, f32);
extern void func_L01_00408C98(void *, s32, void *, void *, s32, s32, f32, s32, s32, s32);
__asm__(".extern D_L06_001DD294, 4");
extern u32 D_L06_001DD294;
extern void func_003C2EC0(void *, s32, void *);
__asm__(".extern D_L06_001DD298, 4");
extern s32 D_L06_001DD298;
extern void func_003C2F58(void *, s32, void *);
extern void func_0038CF68(void *, void *, f32);
__asm__(".extern D_L24_001DF51C, 4");
extern u8 *D_L24_001DF51C;
extern void func_L06_0034A2B8(u8 *);

void func_L06_0034A2B8(u8 *obj) {
    u8 *s = *(u8 **)(obj + 0x68);
    f32 a[4];
    f32 b[4];
    f32 c[4];
    f32 d[4];
    f32 m[16];
    f32 w[4];
    f32 t;
    u8 *q;
    t = *(f32 *)(s + 2276) - 0.1f;
    *(f32 *)(s + 2276) = t;
    if (t <= -8.0f) {
        *(f32 *)(s + 2276) = t + 8.0f;
    }
    func_003C2F58(obj, 0, a);
    func_003C2F58(obj, 2, b);
    func_003C2F58(obj, 1, c);
    func_003C2F58(obj, 3, d);
    q = s + 1728;
    func_003C2EC0(obj, 1, m);
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, -2.25f);
    *(vu0_q *)(s + 1744) = *(vu0_q *)w;
    *(f32 *)(s + 1756) = 1.0f;
    *(vu0_q *)w = *(vu0_q *)m;
    func_0038CF68(w, w, 0.45f);
    *(vu0_q *)(s + 1728) = *(vu0_q *)w;
    *(f32 *)(s + 1740) = 1.0f;
    func_L01_0040A8C0(a, c, D_L06_001DD294, 1, *(u32 *)(s + 2288), *(u32 *)(s + 2288), *(u32 *)(s + 2288), *(u32 *)(s + 2288), 0.08f, 0.75f, *(f32 *)(s + 2276));
    func_L01_0040A8C0(b, d, D_L06_001DD294, 1, *(u32 *)(s + 2288), *(u32 *)(s + 2288), *(u32 *)(s + 2288), *(u32 *)(s + 2288), 0.08f, 0.75f, *(f32 *)(s + 2276));
    func_L01_0040A8C0(a, c, D_L06_001DD294, 1, *(u32 *)(s + 2292), *(u32 *)(s + 2292), *(u32 *)(s + 2292), *(u32 *)(s + 2292), 0.035f, 0.75f, *(f32 *)(s + 2276));
    func_L01_0040A8C0(b, d, D_L06_001DD294, 1, *(u32 *)(s + 2292), *(u32 *)(s + 2292), *(u32 *)(s + 2292), *(u32 *)(s + 2292), 0.035f, 0.75f, *(f32 *)(s + 2276));
    func_L01_00408C98(q, D_L06_001DD298, s + 704, s + 1216, *(s32 *)(s + 2268), *(s32 *)(s + 2284), *(f32 *)(s + 2304), *(s32 *)(s + 2296), *(s32 *)(s + 2300), 5);
}
/* localdecomp:end func_L06_0034A2B8 */

/* localdecomp:start func_L06_0034A538 */
__asm__(".extern D_L24_001DD598, 4");
__asm__(".extern D_L24_001DD59C, 4");
__asm__(".extern D_L24_001DD5A0, 4");
__asm__(".extern D_L24_001DD5A4, 4");
__asm__(".extern D_L24_001DD5A8, 4");
__asm__(".extern D_L24_001DD5AC, 4");
__asm__(".extern D_L24_001DD5B0, 4");
__asm__(".extern D_L24_001DD5B4, 4");
extern u32 D_L24_001DD598;
extern f32 D_L24_001DD59C;
extern f32 D_L24_001DD5A0;
extern u32 D_L24_001DD5A4;
extern f32 D_L24_001DD5A8;
extern f32 D_L24_001DD5AC;
extern u32 D_L24_001DD5B0;
extern f32 D_L24_001DD5B4;
__asm__(".extern D_L24_001DD590, 4");
extern u32 D_L24_001DD590;
extern void func_003C2EC0(void *, s32, void *);
extern void func_L01_0044C280(void *, void *, void *, s32, f32);
extern void func_003C3FC0(void *, void *);
__asm__(".extern D_L06_001DD298, 4");
extern s32 D_L06_001DD298;
extern void func_003C2F58(void *, s32, void *);
__asm__(".extern D_L24_001DF51C, 4");
extern u8 *D_L24_001DF51C;
extern void func_L06_0034A538(void *);

void func_L06_0034A538(void *arg) {
    u8 *obj = arg;
    u8 *s = *(u8 **)(obj + 0x68);
    f32 a[4];
    f32 m[16];
    s32 z[4];
    f32 d1[4];
    f32 d2[4];
    f32 out[4];
    s32 i;
    s32 n;
    s32 t;
    *(f32 *)(s + 2304) = 0.0f;
    func_003C2F58(obj, 1, a);
    func_003C2EC0(obj, 1, m);
    if (*(f32 *)(s + 2304) == 0.0f) {
        s32 n = D_L06_001DD298;
        *(s32 *)(s + 2268) = (*(s32 *)(s + 2268) + 1) % n;
        if (*(s32 *)(s + 2284) < n) {
            *(s32 *)(s + 2284) = *(s32 *)(s + 2284) + 1;
        }
    }
    z[0] = 0;
    z[1] = 0;
    z[2] = 0;
    z[3] = 0;
    if (*(s32 *)(s + 2280) >= 2) {
        n = D_L06_001DD298;
        t = n - 1;
        i = (*(s32 *)(s + 2268) + t) % n;
        vec_sub_ab(d1, a, obj + 0x10);
        vec_sub_ba(d2, s + 704 + i * 16, obj + 0x10);
        func_L01_0044C280(out, d2, d1, 0, 0.5f);
        func_003C3FC0(s + 1216 + *(s32 *)(s + 2268) * 16, z);
        vec_add_ba(s + 704 + *(s32 *)(s + 2268) * 16, out, obj + 0x10);
        *(s32 *)(s + 2268) = (*(s32 *)(s + 2268) + 1) % D_L06_001DD298;
    }
    func_003C3FC0(s + 1216 + *(s32 *)(s + 2268) * 16, z);
    *(vu0_q *)(s + 704 + *(s32 *)(s + 2268) * 16) = *(vu0_q *)a;
}
/* localdecomp:end func_L06_0034A538 */

INCLUDE_ASM("asm/levels", func_L06_0034A6C8);

INCLUDE_ASM("asm/levels", func_L06_0034A7A8);

INCLUDE_ASM("asm/levels", func_L06_0034F670);

INCLUDE_ASM("asm/levels", func_L06_0034F9B8);

INCLUDE_ASM("asm/levels", func_L06_0034FCC8);

/* localdecomp:start func_L06_0034FDA8 */
typedef struct {
    char pad0[0x10];
    char pos[0x31 - 0x10];
    u8 unk31;
    char pad32[0x68 - 0x32];
    char *vars;
    char pad6C[0x6F - 0x6C];
    u8 state;
    char pad70[0x96 - 0x70];
    u16 timer;
} Moby;

extern char D_L06_001E1700[];
extern void func_0038CAD0(void *);
extern void func_0038CB00(void *);
extern void func_L01_00451DF8(Moby *, void *, s32, s32, f32);
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(Moby *);

void func_L06_0034FDA8(Moby *m) {
    char *v = m->vars;

    func_0038CAD0(v + 2256);
    func_0038CB00(v + 2260);
    if (m->timer < 0xFFFF) {
        m->timer++;
    }
    func_L01_00451DF8(m, v + 576, 10, 1, 2.5f);
    if (m->unk31 != 0 && func_L01_0040E548(D_L06_001E1700, m->pos) < 576.0f) {
        func_L01_004472C0(m);
        m->state = 22;
    }
}
/* localdecomp:end func_L06_0034FDA8 */

/* localdecomp:start func_L06_0034FE60 */
extern u16 *D_L06_0021B860[];
extern u8 *D_L06_001DED9C;
__asm__(".extern D_L06_001DED9C, 16");
extern s32 D_L06_001DEDD8;

void func_L06_0034FE60(u8 *a0) {
    u16 *p;
    u8 *e;
    u8 *s;
    if (a0[0x21] == 0xFF) return;
    p = D_L06_0021B860[a0[0x21]];
    while (a0[0x21] != 0xFF && a0[0x21] <= D_L06_001DEDD8 && p != 0 &&
           ((s16)p[-1] >= 0 || p == D_L06_0021B860[a0[0x21]])) {
        e = D_L06_001DED9C + ((*p & 0x7FFF) << 8);
        if (e == 0) break;
        if (*(s16 *)(e + 0xAA) == *(s16 *)(a0 + 0xAA)) {
            s = *(u8 **)(e + 0x68);
            if (s != 0) *(s32 *)(s + 0x8D8) = 1;
        }
        if (*(s16 *)(e + 0xAA) == 0x1625) {
            s = *(u8 **)(e + 0x68);
            if (s != 0) *(s16 *)(s + 0x3D8) = 1;
        }
        p++;
    }
}
/* localdecomp:end func_L06_0034FE60 */
