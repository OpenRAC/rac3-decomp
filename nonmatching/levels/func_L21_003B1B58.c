/* P02 retry: 44 diff with the owning file's flags after loading tmp.v[3]
   before tmp.v[1] for the second VU add. Both inputs remain unchanged.
   No candidate promotion. The original wave-12 draft is backed up in
   build/reserved50/P02/l21-original.c.
   r04 wave 12 retry: 47 diff (the earlier draft: 195). Changed against the draft:
   - the target-angle expression as a static inline helper (Angle_003B1B58, used by the cone test and the hit record):
     with it the first loop is no longer one haifa scheduling region, so n-- stays at the continue point (retail's
     beql/bc1tl decrements, s->owner in the blezl slot) and the loop has retail's length (the draft was 6 words short);
   - the hit record stored in the order owner, flags, f, g, a, b, id (retail's store schedule);
   - the second loop counts with its own j (retail keeps the first loop's down-counter in s2 apart from it);
   - the last u copy is a plain store of the VU0 value (*(vu0_q *)&tmp.v[2] = qw), so it fills the jal delay slot.
    Still differs: m in s0 and the list pointer / j in s1 (retail s1 / s0), the
   func_003D3CB0 argument setup order around the VU0 sequence, and the 0.4f load hoisted above the beqz. */
#include "common.h"

/* localdecomp:start func_L21_003B1B58 */
typedef struct {
    vu0_v4 dir;
    void *owner;
    s32 flags;
    u8 a;
    u8 b;
    u16 id;
    f32 f;
    s32 g;
} Hit_003B1B58;
typedef union {
    Hit_003B1B58 hit;
    vu0_v4 v[4];
} U_003B1B58;
extern u8 *D_L21_001EC4C0[];
extern f32 func_0038DB48(f32);
extern f32 func_0038D098(f32);
extern f32 func_0038D0B0(f32);
extern void func_00382760(void *, f32, f32, f32);

static inline f32 Angle_003B1B58(u8 *e, u8 *m) {
    extern f32 func_0038D160(f32, f32);
    return func_0038D160(*(f32 *)(e + 0x10) - *(f32 *)(m + 0x10), *(f32 *)(e + 0x14) - *(f32 *)(m + 0x14));
}

void func_L21_003B1B58(void *arg0, void *arg1) {
    extern s32 func_003D4D00(f32, void *, s32, void *, s32);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern void func_L01_00446978(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    U_003B1B58 tmp;
    u8 *m = arg0;
    S_003B1A00 *s = arg1;
    f32 r;
    f32 dz;
    f32 lim;
    f32 ang;
    f32 sgn;
    f32 a0;
    f32 a1;
    s32 n;
    s32 i;
    s32 k;
    s32 j;

    r = s->h70 * s->h7A;
    if (r < 0.75f) r = 0.75f;
    n = func_003D4D00(r, m + 0x10, 0x10, s->owner, 0);
    for (i = 0; i < n; i++) {
        if (D_L21_001EC4C0[i] == s->owner) continue;
        if (s->h7A > 0) {
            if (0.7417649f < func_0038DBA0(Angle_003B1B58(D_L21_001EC4C0[i], m),
                                           *(f32 *)(m + 0xF8))) continue;
            dz = *(f32 *)(D_L21_001EC4C0[i] + 0x18) - *(f32 *)(m + 0x18);
            if (0.2f < dz) continue;
            if (dz < -2.0f) continue;
            lim = r * 0.95f;
            if (func_L01_0040E570(m + 0x10, D_L21_001EC4C0[i] + 0x10) < lim * lim) continue;
        }
        tmp.hit.owner = s->owner;
        tmp.hit.flags = 0x430001;
        tmp.hit.f = s->h7C;
        tmp.hit.g = 0x430000;
        tmp.hit.a = 2;
        tmp.hit.b = 3;
        tmp.hit.id = *(u16 *)(m + 0xAA);
        ang = Angle_003B1B58(D_L21_001EC4C0[i], m);
        tmp.hit.dir.x = func_0038D098(ang);
        tmp.hit.dir.y = func_0038D0B0(ang);
        tmp.hit.dir.z = 1.0f;
        tmp.hit.dir.w = 5627.9248f;
        func_L01_00446978(D_L21_001EC4C0[i], &tmp.hit);
    }
    for (k = 0; k < 2; k++) {
        sgn = (k & 1) ? 1.0f : -1.0f;
        j = 0;
        do {
            vu0_q qp, qv, qw, qt;
            a0 = func_0038DB48(j * sgn * 0.69813168f / 5.0f);
            j++;
            a1 = func_0038DB48(j * sgn * 0.69813168f / 5.0f);
            func_00382760(&tmp.v[0], r, func_0038DAB8(a0, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            func_00382760(&tmp.v[1], r, func_0038DAB8(a1, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(tmp.v[0]));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[3]) : "j"(qp));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[0]) : "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[2]) : "j"(qv));
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(tmp.v[3]));
            __asm__("lqc2 %0, %1" : "=j"(qw) : "m"(tmp.v[1]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qw) : "j"(qw), "j"(qt));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[1]) : "j"(qw));
            *(vu0_q *)&tmp.v[2] = qw;
            if (func_003D3CB0(&tmp.v[0], &tmp.v[1], 0x12, s->owner, 0) != 0) {
                func_00382760(&tmp.v[2], 0.40000004f, *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            }
        } while (j < 5);
    }
}
/* localdecomp:end func_L21_003B1B58 */
