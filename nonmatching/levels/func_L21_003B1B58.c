/* func_L21_003B1B58: 208 diff with the file's flags. Structure and constants match; differs: frame 0xC0 vs 0xB0 (block-scoped locals v/h and v/w/u/t do not share stack slots as retail does: retail has h at sp+0x10 beside v, and w,u,t at 0x10,0x20,0x30), register assignment (retail m=$s1 list=$s0 n=$s2, mine m=$s0 list=$s2 n=$s1), and retail moves the second-part vadd pairs as vadd_st2/vadd_ld2 below (two sqc2 of the sum, one to 0x20) which I wrote as local asm helpers. Tried: continue-style vs one big && condition, h as cast of w vs scoped local. */
#include "common.h"

#include "vu0.h"
typedef struct {
    f32 w[0x1C];
    f32 h70;
    void *owner;
    s16 h78;
    s16 h7A;
    f32 h7C;
} S_003B1A00;
extern s32 func_003D4D00(f32, void *, s32, void *, s32);
extern f32 func_0038D160(f32, f32);
extern f32 func_0038DBA0(f32, f32);
extern f32 func_L01_0040E570(void *, void *);
extern void func_L01_00446978(void *, void *);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern f32 func_0038DB48(f32);
extern f32 func_0038DAB8(f32, f32);
extern void func_00382760(void *, f32, f32, f32);
extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
extern u8 *D_L21_001EC4C0[];

static __inline__ void vadd_st2(void *d, void *e, void *src, void *tmp) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)src));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)d));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)tmp) : "j"(qa));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qb), "j"(qa));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)e) : "j"(qr));
}
static __inline__ void vadd_ld2(void *d, void *e, void *tmp) {
    vu0_q qa, qb, qr;
    __asm__("lqc2 %0, %1" : "=j"(qa) : "m"(*(vu0_v4 *)d));
    __asm__("lqc2 %0, %1" : "=j"(qb) : "m"(*(vu0_v4 *)tmp));
    __asm__("vadd.xyz %0, %1, %2" : "=j"(qr) : "j"(qa), "j"(qb));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)d) : "j"(qr));
    __asm__("sqc2 %1, %0" : "=m"(*(vu0_v4 *)e) : "j"(qr));
}


typedef struct {
    void *owner;
    s32 flags;
    u8 a;
    u8 b;
    u16 id;
    f32 f;
    s32 g;
} L21_Hit;

void func_L21_003B1B58(void *arg0, void *arg1)
{
    u8 *m = arg0;
    S_003B1A00 *s = arg1;
    f32 f23;
    f32 f20;
    f32 sgn;
    f32 a;
    f32 b;
    s32 n;
    s32 i;
    s32 k;
    u8 **list;
    u8 *e;

    f23 = s->h70 * s->h7A;
    if (f23 < 0.75f) f23 = 0.75f;
    n = func_003D4D00(f23, m + 0x10, 0x10, s->owner, 0);
    if (n > 0) {
        vu0_v4 v;
        L21_Hit h;
        list = D_L21_001EC4C0;
        do {
            if (*list != s->owner &&
                (s->h7A <= 0 ||
                 (!(func_0038DBA0(func_0038D160(*(f32 *)(*list + 0x10) - *(f32 *)(m + 0x10),
                                                *(f32 *)(*list + 0x14) - *(f32 *)(m + 0x14)),
                                  *(f32 *)(m + 0xF8)) > 0.7417649f) &&
                  !((a = *(f32 *)(*list + 0x18) - *(f32 *)(m + 0x18)) > 0.2f) &&
                  !(a < -2.0f) &&
                  !(func_L01_0040E570(m + 0x10, *list + 0x10) < (f20 = f23 * 0.95f, f20 * f20))))) {
                h.owner = s->owner;
                h.flags = 0x430001;
                h.a = 2;
                h.b = 3;
                h.id = *(u16 *)(m + 0xAA);
                h.f = s->h7C;
                h.g = 0x430000;
                f20 = func_0038D160(*(f32 *)(*list + 0x10) - *(f32 *)(m + 0x10),
                                    *(f32 *)(*list + 0x14) - *(f32 *)(m + 0x14));
                v.x = func_0038D098(f20);
                v.y = func_0038D0B0(f20);
                v.z = 1.0f;
                v.w = 5627.9248f;
                func_L01_00446978(*list, &v);
            }
            list++;
        } while (--n);
    }
    for (k = 0; k < 2; k++) {
        sgn = (k & 1) ? 1.0f : -1.0f;
        i = 0;
        {
        vu0_v4 v;
        vu0_v4 w;
        vu0_v4 u;
        vu0_v4 t;
        do {
            f20 = func_0038DB48(i * sgn * 0.69813168f / 5.0f);
            i++;
            a = func_0038DB48(i * sgn * 0.69813168f / 5.0f);
            func_00382760(&v, f23, func_0038DAB8(f20, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            func_00382760(&w, f23, func_0038DAB8(a, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            vadd_st2(&v, &u, m + 0x10, &t);
            vadd_ld2(&w, &u, &t);
            if (func_003D3CB0(&v, &w, 0x12, s->owner, 0) != 0)
                func_00382760(&u, 0.40000004f, *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
        } while (i < 5);
        }
    }
}

INCLUDE_ASM("asm/levels", func_L21_003B1B58);
