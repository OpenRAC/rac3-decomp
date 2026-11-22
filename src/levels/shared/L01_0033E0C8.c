#include "common.h"
#include "vu0.h"

typedef struct {
    u8 pad0[0x18];
    f32 f18;
} S_33BDC8;
typedef void (*Fn_33CA98)(u8 *);


INCLUDE_ASM("asm/levels", func_L01_0033E0C8);

/* localdecomp:start func_L01_0033E290 */
void func_L01_0033E290(vu0_v4 *a0, s32 a1) {
    vu0_v4 t;

    vec_sub_ab(&t, &a0[a1 - 2], &a0[a1 - 3]);
    vec_add_ab(&a0[a1 - 1], &a0[a1 - 2], &t);
}
/* localdecomp:end func_L01_0033E290 */


/* localdecomp:start func_L01_0033E2D0 */
extern f32 D_L01_001E29C0_0033E2D0[];
void func_L01_0033E2D0(s32 unused, s32 colour, f32 (*pts)[4], s32 count) {
    extern unsigned long func_00389598(s32);
    extern void func_L01_0033E040_0033E2D0(f32 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern void func_0038CE90(f32 *, f32 *, f32 *);
    extern void func_0038D028(f32 *, f32 *, f32 *);
    extern void func_003D2DA0(f32 *, s32, s32);
    f32 a[36] __attribute__((aligned(16)));
    f32 b[36] __attribute__((aligned(16)));
    f32 axis[4] __attribute__((aligned(16)));
    f32 eye[4] __attribute__((aligned(16)));
    f32 side[4] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 inner[4] __attribute__((aligned(16)));
    f32 outer[4] __attribute__((aligned(16)));
    s32 i;
    s32 edgeColour = 0x8000FF00;
    unsigned long texture;
    f32 step, u, v;
    texture = func_00389598(43);
    *(unsigned long *)(a + 28) = 0;
    *(unsigned long *)(a + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(a + 34) = ((unsigned long)(u32)colour << 32) | 104;
    *(s32 *)(a + 17) = 0x7FFFFFFF;
    *(s32 *)(a + 16) = 0x7FFFFFFF;
    *(unsigned long *)(a + 30) = texture;
    texture = func_00389598(43);
    *(unsigned long *)(b + 28) = 0;
    *(unsigned long *)(b + 32) = 0x0000FF9000000260UL;
    *(unsigned long *)(b + 34) = ((unsigned long)(u32)(colour / 3) << 32) | 104;
    *(unsigned long *)(b + 30) = texture;
    *(vu0_q *)inner = 0;
    *(vu0_q *)outer = 0;
    inner[2] = 0.05f;
    outer[2] = 0.2f;
    *(s32 *)(a + 17) = edgeColour;
    *(s32 *)(b + 16) = edgeColour;
    inner[3] = 1.0f; outer[3] = 1.0f;
    func_L01_0033E290((vu0_v4 *)pts, count);
    func_L01_0033E040_0033E2D0(a);
    func_L01_0033E040_0033E2D0(b);
    a[20]=0.0f; a[21]=0.0f; a[22]=0.0f; a[23]=1.0f;
    a[24]=1.0f; a[25]=0.0f; a[26]=1.0f; a[27]=1.0f;
    b[20]=0.0f; b[21]=0.0f; b[22]=0.0f; b[23]=1.0f;
    b[24]=0.33f; b[25]=0.0f; b[26]=0.33f; b[27]=1.0f;
    vec_sub_ba(axis, pts[1], pts[0]);
    func_0038CF68(axis, axis, 1.0f);
    vec_sub_ab(eye, D_L01_001E29C0_0033E2D0, pts[0]);
    func_0038CE90(side, eye, axis);
    func_0038CF68(side, side, 1.0f);
    func_0038CE90(eye, axis, side);
    *(vu0_q *)pos = *(vu0_q *)pts[0];
    *(vu0_q *)a = *(vu0_q *)inner;
    func_0038CE20(a + 4, a, -1.0f);
    func_0038D028(a, a, axis);
    func_0038D028(a + 4, a + 4, axis);
    *(vu0_q *)b = *(vu0_q *)outer;
    func_0038CE20(b + 4, b, -1.0f);
    func_0038D028(b, b, axis);
    func_0038D028(b + 4, b + 4, axis);
    for (i = 1; i < count - 1; i++) {
        *(vu0_q *)(a + 8) = *(vu0_q *)inner;
        func_0038CE20(a + 12, a + 8, -1.0f);
        *(vu0_q *)(b + 8) = *(vu0_q *)outer;
        func_0038CE20(b + 12, b + 8, -1.0f);
        vec_sub_ab(axis, pts[i + 1], pts[i]);
        func_0038CF68(axis, axis, 1.0f);
        vec_sub_ab(eye, D_L01_001E29C0_0033E2D0, pts[i]);
        func_0038CE90(side, eye, axis);
        func_0038CF68(side, side, 1.0f);
        func_0038CE90(eye, axis, side);
        *(vu0_q *)pos = *(vu0_q *)pts[i];
        func_0038D028(a + 8, a + 8, axis);
        func_0038D028(a + 12, a + 12, axis);
        func_0038D028(b + 8, b + 8, axis);
        func_0038D028(b + 12, b + 12, axis);
        step = 0.33f;
        *(s32 *)(a + 19) = 0x7F7F7F7F;
        *(s32 *)(a + 18) = 0x7F7F7F7F;
        *(s32 *)(b + 19) = edgeColour;
        *(s32 *)(b + 18) = edgeColour;
        func_003D2DA0(a, 0, 0);
        func_003D2DA0(b, 0, 0);
        u = i * step;
        v = u + step;
        if (u >= 1.0f) { u -= 1.0f; v -= 1.0f; }
        b[20] = u; b[24] = v; b[22] = u; b[26] = v;
        *(vu0_q *)a = *(vu0_q *)(a + 8);
        *(vu0_q *)(a + 4) = *(vu0_q *)(a + 12);
        *(vu0_q *)b = *(vu0_q *)(b + 8);
        *(vu0_q *)(b + 4) = *(vu0_q *)(b + 12);
    }
}
/* localdecomp:end func_L01_0033E2D0 */

LINKER_REMNANT("asm/levels", func_L01_0033E758);

INCLUDE_ASM("asm/levels", func_L01_0033E760);

LINKER_REMNANT("asm/levels", func_L01_0033ED28);

/* localdecomp:start func_L01_0033ED30 */
typedef struct {
    u8 pad0[0xB0];
    vu0_v4 vB0;
    u8 padC0[0x25C0 - 0xC0];
    u8 *x25C0;
} H_33ED30;
typedef struct {
    u8 pad0[0x30];
    vu0_v4 v30;
} M_33ED30;
typedef struct {
    u8 pad0[0x10];
    vu0_v4 v10;
    u8 pad20[0x68 - 0x20];
    M_33ED30 *p68;
} O_33ED30;
extern H_33ED30 D_001A4BE0;
extern vu0_v4 D_L01_001EAA30[];
extern s32 D_L01_001D673C;
extern s32 func_L01_003FB640(void *, s32, void *, f32);
extern void func_0038CF68(void *, void *, f32);
extern f32 func_0038CE68(void *, void *);
extern void func_0038CE20(void *, void *, f32);
extern void func_L01_0040E790(void *, void *, void *);

void func_L01_0033ED30(O_33ED30 *a0) {
    vu0_v4 t;
    vu0_v4 d;
    vu0_v4 u;
    M_33ED30 *m;
    f32 save;
    f32 f;

    m = a0->p68;
    if (func_L01_003FB640(&a0->v10, 0, D_001A4BE0.x25C0, 0.25f) != 0) {
        *(vu0_q *)&a0->v10 = *(vu0_q *)&D_L01_001EAA30[0];
        if (D_L01_001D673C != 0) {
            vec_sub_ab(&t, &D_001A4BE0.vB0, &a0->v10);
            func_0038CF68(&t, &t, 1.0f);
            f = func_0038CE68(&t, &m->v30);
            func_0038CE20(&d, &t, f);
            vec_sub_ab(&u, &m->v30, &d);
            func_L01_0040E790(&m->v30, &u, &D_L01_001EAA30[1]);
            vec_add_ab(&m->v30, &m->v30, &d);
        } else {
            save = m->v30.z;
            m->v30.z = 0.0f;
            func_L01_0040E790(&m->v30, &m->v30, &D_L01_001EAA30[1]);
            m->v30.z = save;
        }
    }
}
/* localdecomp:end func_L01_0033ED30 */

/* localdecomp:start func_L01_0033EE50 */
#include "vu0.h"

typedef struct {
    vu0_v4 v;
    u8 *owner;
    s32 flags;
    u8 b18;
    u8 b19;
    u16 h1A;
    s32 w1C;
    s32 w20;
} S_33EE50_0033EE50;

extern s32 D_L01_001DFB40_0033EE50;
extern s32 D_001A71A0[];
extern f32 D_L01_001DD020_0033EE50;
__asm__(".extern D_L01_001DD020_0033EE50, 4");
extern u8 *D_L01_001E0028_0033EE50;
__asm__(".extern D_L01_001E0028_0033EE50, 4");
extern s32 func_003D4D00(void *, s32, f32, s32, S_33EE50_0033EE50 *);
extern f32 func_0038CF00(void *, void *);
extern void func_L01_002F8F10_0033EE50(u8 *, u8 *);

void func_L01_0033EE50(u8 *a0) {
    S_33EE50_0033EE50 s;
    u8 *m;

    if (!(D_L01_001DFB40_0033EE50 & 1)) return;
    qzero(&s.v);
    s.flags = 0x10000;
    s.b18 = 8;
    s.h1A = *(u16 *)(a0 + 0xAA);
    s.v.w = 5627.9248f;
    s.owner = a0;
    s.b19 = 0;
    s.w1C = 0;
    s.w20 = 0;
    func_003D4D00(a0 + 0x10, 0, D_L01_001DD020_0033EE50, D_001A71A0[0], &s);
    if (!(D_L01_001DFB40_0033EE50 & 1)) return;
    for (m = D_L01_001E0028_0033EE50; m != 0; m = *(u8 **)(m + 0x28)) {
        if (m[0x20] == 0xFE) return;
        if (m[0x20] == 0xFD) return;
        if (m != 0 && *(u8 **)(m + 0x24) != 0 && (*(u8 **)(m + 0x24))[0x46] == 0x13) {
            if (func_0038CF00(m + 0x10, a0 + 0x10) < D_L01_001DD020_0033EE50) {
                func_L01_002F8F10_0033EE50(m, a0);
            }
        }
    }
}
/* localdecomp:end func_L01_0033EE50 */

INCLUDE_ASM("asm/levels", func_L01_0033EF90);
