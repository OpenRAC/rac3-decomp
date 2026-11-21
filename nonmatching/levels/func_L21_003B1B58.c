/* PAL near miss (Codex wave 11): near miss: 195 words differ in its file's context with the file's flags.
 * Replaces the earlier draft (shared-2 worker draft (2026-11-16): does not compile under tools/check.py in its file's context with the file's flags, measured 2026-11-21;
 * this one: 195).
 * Worker's note: 195 diff with the file line (draft 208). Frame now 0xB0 as retail: the hit record (vector + owner/flags/2/3/id/h7C/0x430000) and the four vectors v,w,u,t share one local union at sp+0 (separate block scopes never share slots here). The second part is one-instruction j-operand asms as in L11_003AE290, giving retail's t-copy and double u store; no new helpers. Left: the first loop's register choice (retail list=$s0, m=$s1, n=$s2; ours m=$s0, n=$s1, list=$s2), and the n decrement: gcc hoists it into the first beq delay slot, where retail decrements in each continue's beql/bc1tl slot. Same 195 with a list pointer + do/while(--n) (196), swapped declarations, one big condition (try4-6 in W/func_L21_003B1B58/)
 */
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

    r = s->h70 * s->h7A;
    if (r < 0.75f) r = 0.75f;
    n = func_003D4D00(r, m + 0x10, 0x10, s->owner, 0);
    for (i = 0; i < n; i++) {
        if (D_L21_001EC4C0[i] == s->owner) continue;
        if (s->h7A > 0) {
            if (0.7417649f < func_0038DBA0(func_0038D160(*(f32 *)(D_L21_001EC4C0[i] + 0x10) - *(f32 *)(m + 0x10),
                                                         *(f32 *)(D_L21_001EC4C0[i] + 0x14) - *(f32 *)(m + 0x14)),
                                           *(f32 *)(m + 0xF8))) continue;
            dz = *(f32 *)(D_L21_001EC4C0[i] + 0x18) - *(f32 *)(m + 0x18);
            if (0.2f < dz) continue;
            if (dz < -2.0f) continue;
            lim = r * 0.95f;
            if (func_L01_0040E570(m + 0x10, D_L21_001EC4C0[i] + 0x10) < lim * lim) continue;
        }
        tmp.hit.owner = s->owner;
        tmp.hit.flags = 0x430001;
        tmp.hit.a = 2;
        tmp.hit.b = 3;
        tmp.hit.id = *(u16 *)(m + 0xAA);
        tmp.hit.f = s->h7C;
        tmp.hit.g = 0x430000;
        ang = func_0038D160(*(f32 *)(D_L21_001EC4C0[i] + 0x10) - *(f32 *)(m + 0x10),
                            *(f32 *)(D_L21_001EC4C0[i] + 0x14) - *(f32 *)(m + 0x14));
        tmp.hit.dir.x = func_0038D098(ang);
        tmp.hit.dir.y = func_0038D0B0(ang);
        tmp.hit.dir.z = 1.0f;
        tmp.hit.dir.w = 5627.9248f;
        func_L01_00446978(D_L21_001EC4C0[i], &tmp.hit);
    }
    for (k = 0; k < 2; k++) {
        sgn = (k & 1) ? 1.0f : -1.0f;
        i = 0;
        do {
            vu0_q qp, qv, qw, qt;
            a0 = func_0038DB48(i * sgn * 0.69813168f / 5.0f);
            i++;
            a1 = func_0038DB48(i * sgn * 0.69813168f / 5.0f);
            func_00382760(&tmp.v[0], r, func_0038DAB8(a0, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            func_00382760(&tmp.v[1], r, func_0038DAB8(a1, *(f32 *)(m + 0xF8)), -*(f32 *)(m + 0xF4));
            __asm__("lqc2 %0, %1" : "=j"(qp) : "m"(*(vu0_v4 *)(m + 0x10)));
            __asm__("lqc2 %0, %1" : "=j"(qv) : "m"(tmp.v[0]));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[3]) : "j"(qp));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qv) : "j"(qv), "j"(qp));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[0]) : "j"(qv));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[2]) : "j"(qv));
            __asm__("lqc2 %0, %1" : "=j"(qw) : "m"(tmp.v[1]));
            __asm__("lqc2 %0, %1" : "=j"(qt) : "m"(tmp.v[3]));
            __asm__("vadd.xyz %0, %1, %2" : "=j"(qw) : "j"(qw), "j"(qt));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[1]) : "j"(qw));
            __asm__("sqc2 %1, %0" : "=m"(tmp.v[2]) : "j"(qw));
            if (func_003D3CB0(&tmp.v[0], &tmp.v[1], 0x12, s->owner, 0) != 0) {
                func_00382760(&tmp.v[2], 0.40000004f, *(f32 *)(m + 0xF8), -*(f32 *)(m + 0xF4));
            }
        } while (i < 5);
    }
}
/* localdecomp:end func_L21_003B1B58 */
