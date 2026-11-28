/* Cut pass c51 (wave 14c, 2026-11-28), re-measured: under the existing line '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'
 * (L01_0033B530.c's, the next file) with the divs row 'func_L01_0033AC78 0 2 0' this draft is 366 diff by
 * position at level 01 (r67's j-form copy wr67/func_L01_0033AC78.cut.c: 367, 12 aligned rows), so it stays.
 * The whole file L01_0033AC58.c can take that line (func_L01_0033AC58 MATCHes under it); else the cut is
 * 0x0033AC78-0x0033B530 (8-aligned at all 34 places). Left under the line: the jump table's relocation, jump2's
 * cross-jump of case 1's two func_L01_0033C520 + func_L01_0033C030 tails (retail keeps both: 4 words short) and
 * the 8-alignment nop of the while (other) loop label (retail 0x674). */
/* func_L01_0033AC78 (Claude wave 14 r67, 2026-11-28). Replaces the earlier draft of this function (NTSC-U draft of `func_L01_0033A5C0` (Codex wave 3)). */
/* Wave 14 r67: func_L01_0033AC78 (2232 B, PAL) rewritten from the PAL asm (the draft is NTSC-U C of
 * func_L01_0033A5C0 and has no count on PAL). This copy compiles with the file's own line (asm-block VU0 add):
 * wave10 check.py 485 diff (481 with --divs 0,2,0). The file line cannot give retail's split addresses
 * (shared %hi of D_001A4BE0), the Ps2EeAs li.s lui/ori/mtc1 floats or the scheduled VU0 add.
 * Under the existing line '-mvu0-use-vf0-vf2 -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as'
 * (L01_0033B530.c's) the j-form copy wr67/func_L01_0033AC78.cut.c is equal to retail except one spot:
 * jump2 cross-jumps the two func_L01_0033C520+func_L01_0033C030 tails of case 1 (retail keeps both), so it is
 * 4 insns short and the rest is shifted (tools/check.py 368 diff; 367 with divs row 0 2 0).
 * Levers: &hit taken before the first call (gives retail's s0/s1/s2 allocation), hero pointers assigned per
 * use (comma form), .extern size hints, store orders as retail, int-returning list walkers.
 */#include "common.h"

/* localdecomp:start func_L01_0033AC78 */
typedef unsigned long U64_0033AC78;
typedef int Q_0033AC78 __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x28C];
    u8 *p28c;
    u8 *p290;
    u8 p294[0x35C - 0x294];
    u8 *p35c;
    u8 p360[0x36E - 0x360];
    s16 s36e;
    u8 p370[0x538 - 0x370];
    u8 *p538;
    u8 p53c[0x25C0 - 0x53C];
    u8 *p25c0;
    u8 p25c4[8];
    s32 i25cc;
} Hero_0033AC78;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern Hero_0033AC78 D_001A4BE0;
extern s32 D_001A5E08[];
extern s32 D_001A71AC[];
extern u8 D_L01_001EEA80[];
extern void func_003C2880(void *);
extern void func_L01_0033B530(void *);
extern s32 func_L01_0044C108(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_0033CBC0(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0033C520(void *, s32, void *);
extern void func_L01_0033C030(void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0033D188(void *, s32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_L01_0040E020(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00445C48(void *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00445D30(void *, void *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);

typedef struct { Q_0033AC78 v; u8 *m; s32 flags; s32 unused; f32 f; s32 zero; } Hit_0033AC78;

void func_L01_0033AC78(u8 *m) {
    Hit_0033AC78 hit;
    Hit_0033AC78 *ph;
    Q_0033AC78 pos;
    u8 *other;
    u8 *op;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *h;
    s32 special;
    s32 ok;
    s32 effect;
    f32 f;
    Hero_0033AC78 *hero;
    Hero_0033AC78 *hero2;
    Hero_0033AC78 *hero3;

    if (*(s16 *)(m + 0xAA) == 0x1FA) {
        func_003C2880(m);
        return;
    }
    if ((*(u16 *)(m + 0x34) & 0x80) && D_001D545C_sda == 4) return;
    if (!m[0x20]) func_L01_0033B530(m);
    if (!func_L01_0044C108(m + 0x10)) return;
    h = p + 0x30;
    if (((*(s32 *)(p + 0xDC) & 12) && *(s32 *)(p + 0xE4) != D_L01_001DFB40) || func_0038CE68(p + 0xC0, p + 0xC0) > 0.0f)
        func_L01_0033CBC0(m);
    if (!*(u8 **)(p + 0xD0)) *(u16 *)(h + 0x1E) |= 1;
    h = func_L01_00447490(m, 0xB030001, 0);
    special = 0;
    if (h && *(s32 *)(h + 0x24) == 0x2000000) {
        h = 0;
        special = 1;
    }
    switch (m[0x20]) {
    case 1:
        if (func_L01_004561B8(m)) *(s32 *)(p + 0x130) = 0;
        if (*(s16 *)(m + 0xAA) == 0x1F9 && ((hero = &D_001A4BE0, hero->p290 == m) || hero->p28c == m ||
                                           (hero->p35c == m && !hero->s36e) || hero->p538 == m || special)) {
            hero2 = &D_001A4BE0;
            if (hero2->i25cc == 15) {
                func_L01_0033C520(m, 1, 0);
                func_L01_0033C030(m);
                return;
            }
            m[0xBC] = 0;
            m[0x20] = 5;
            return;
        }
        if (!h || !(*(f32 *)(h + 0x2C) > 0.0f)) return;
        ok = 1;
        if (*(s16 *)(m + 0xAA) == 0x1F6 && !(*(s32 *)(h + 0x24) & 0x20000) &&
            *(s16 *)(*(u8 **)(h + 0x20) + 0xAA) != 0x1F9)
            ok = 0;
        if (*(s16 *)(m + 0xAA) == 0x1F9) {
            m[0x20] = 5;
            if (*(s32 *)(h + 0x24) & 0x20000) m[0xBC] = 1;
            else m[0xBC] = (s32)((func_003824E0(5.0f, 15.0f) * 5.0f + 2.0f) / 6.0f);
            *(U64_0033AC78 *)(p + 0xE8) = *(U64_0033AC78 *)(m + 0x38);
            ok = 0;
        }
        if (ok) {
            if (*(s16 *)(m + 0xAA) == 0x1F8) {
                if (!*(u8 **)(h + 0x20) ||
                    (*(s16 *)(*(u8 **)(h + 0x20) + 0xAA) != 71 && *(s16 *)(*(u8 **)(h + 0x20) + 0xAA) != 0) ||
                    D_001A5E08[0] != 9)
                    break;
                func_L01_0033C520(m, 0, h);
                func_L01_0033C030(m);
            } else {
                func_L01_0033C520(m, *(s16 *)(m + 0xAA) == 0x1F9, h);
                func_L01_0033C030(m);
            }
        }
        break;
    case 2:
        if (--m[0xBC] == 255) {
            m[0xA8] = 255;
            m[0x20] = 1;
        }
        return;
    case 3:
        if (*(s16 *)(m + 0xAA) == 0x1F9 && p[0xFA] < 18) {
            ph = &hit;
            hit.f = 2.0f;
            hit.v = *(Q_0033AC78 *)(m + 0xC0);
            hit.m = m;
            hit.zero = 0;
            func_0038CF68(&pos, m + 0xE0, 0.5f);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(pos) : "m"(pos), "m"(*(Q_0033AC78 *)(m + 0x10)) : "vf1", "vf2");
            f = (f32)p[0xFA] / 17.0f;
            hit.flags = 0x30001;
            func_003D4D00(&pos, 16, m, ph, f + f);
            hit.flags = 0x30000;
            hero3 = &D_001A4BE0;
            effect = func_003D4D00(&pos, 16, hero3->p25c0, 0, f * 3.0f);
            if (effect)
                func_L01_00447718(m, &pos, D_L01_001EEA80, effect, (s32)hero3->p25c0, 0x10000, 0, 0x30000, -1,
                                  4.0f, 1.0f, 1.0f);
            ++p[0xFA];
            break;
        }
        if (p[0xF8]) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            if (*(s16 *)(m + 0xB4) >= 2) *(s16 *)(m + 0xB4) = 1;
            m[0x20] = 6;
            if (p[0xF9] != 255) p[0xF9] = func_00382498(30, 60);
        } else {
            func_L01_0033D188(m, 1);
            return;
        }
        break;
    case 6:
        ++*(s32 *)(p + 0x130);
        if (p[0xF9] == 255) return;
        hit.v = *(Q_0033AC78 *)(m + 0x10);
        *(f32 *)((u8 *)&hit + 8) += 0.5f;
        *(f32 *)((u8 *)&hit + 12) = 1.0f;
        if (func_0038DC20(&hit, (f32)*(s16 *)(m + 0x32)) != -1 || !func_L01_0040E020(p + 0xF9)) break;
        m[0x7F] = 0;
        if (m[0x21] == 255) {
            func_L01_004450F0(m, 1, -1);
            *(u16 *)(m + 0x34) &= 0xFFBE;
            *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
            return;
        }
        func_L01_00445C48(&other, m[0x21], 0, 0);
        while (other) {
            if (m != other && !(func_0038CF38(m + 0x10, other + 0x10) > 0.1f) && other[0x20] == 1 &&
                !*(u8 **)((op = *(u8 **)(other + 0x68)) + 0xD0)) {
                *(Q_0033AC78 *)(m + 0x10) = *(Q_0033AC78 *)(other + 0x10);
                *(f32 *)(m + 0x18) += 1.0f;
                *(u8 **)(op + 0xD0) = m;
                *(u8 **)(p + 0xD4) = other;
                *(u8 **)(p + 0xD0) = 0;
                m[0x20] = 1;
                m[0x31] = 1;
                *(u16 *)(m + 0x34) &= 0xFFFE;
                *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
                *(u16 *)(m + 0x34) |= 0x1000;
                break;
            }
            func_L01_00445D30(&other, other, 0, 0);
        }
        if (m[0x20] != 1) {
            *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
            m[0x20] = 1;
            *(s32 *)(p + 0xD0) = 0;
            *(s32 *)(p + 0xD4) = 0;
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= 0xFFFE;
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
        break;
    case 5:
        if (!m[0xBC]) {
            m[0xBC] = 149;
            *(U64_0033AC78 *)(p + 0xE8) = *(U64_0033AC78 *)(m + 0x38);
        } else if (m[0xBC] >= 13 && h) {
            m[0xBC] = (s32)((func_003824E0(5.0f, 15.0f) * 5.0f + 2.0f) / 6.0f);
        }
        if (m[0xBC] % 50 == 47 || m[0xBC] == 11) func_003A52A0(1, 32, m);
        if (m[0xBC] % 50 >= 34 || m[0xBC] < 12) func_L01_0043B9E8(m, 200, 64, 64);
        else *(U64_0033AC78 *)(m + 0x38) = *(U64_0033AC78 *)(p + 0xE8);
        if (m[0xBC] == 1 || D_001A71AC[0] == 22) {
            *(U64_0033AC78 *)(m + 0x38) = *(U64_0033AC78 *)(p + 0xE8);
            func_L01_0033C520(m, 1, 0);
            func_L01_0033C030(m);
        }
        m[0xA8] = 255;
        --m[0xBC];
        return;
    case 4:
        if (func_L01_0040E020(m + 0xBC)) {
            m[0x20] = 1;
            *(u16 *)(m + 0x34) &= 0xFFFE;
        }
        break;
    default:
        return;
    }
    m[0xA8] = 255;
}
/* localdecomp:end func_L01_0033AC78 */

/* The other form the notes name (Claude wave 14 r67, func_L01_0033AC78.cut.c): the draft for the line or declaration it needs, not compiled here. */
#if 0
#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L01_0033AC78 */
typedef unsigned long U64_0033AC78;
typedef int Q_0033AC78 __attribute__((mode(TI)));
typedef struct {
    u8 pad[0x28C];
    u8 *p28c;
    u8 *p290;
    u8 p294[0x35C - 0x294];
    u8 *p35c;
    u8 p360[0x36E - 0x360];
    s16 s36e;
    u8 p370[0x538 - 0x370];
    u8 *p538;
    u8 p53c[0x25C0 - 0x53C];
    u8 *p25c0;
    u8 p25c4[8];
    s32 i25cc;
} Hero_0033AC78;
extern s32 D_001D545C_sda;
__asm__(".extern D_001D545C_sda, 4");
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 16");
extern Hero_0033AC78 D_001A4BE0;
extern s32 D_001A5E08[];
extern s32 D_001A71AC[];
extern u8 D_L01_001EEA80[];
extern void func_003C2880(void *);
extern void func_L01_0033B530(void *);
extern s32 func_L01_0044C108(void *);
extern f32 func_0038CE68(void *, void *);
extern void func_L01_0033CBC0(void *);
extern u8 *func_L01_00447490(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern void func_L01_0033C520(void *, s32, void *);
extern void func_L01_0033C030(void *);
extern f32 func_003824E0(f32, f32);
extern void func_0038CF68(void *, void *, f32);
extern s32 func_003D4D00(void *, s32, void *, void *, f32);
extern void func_L01_00447718(void *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32);
extern void func_L01_004AA7E8(void *, s32);
extern s32 func_00382498(s32, s32);
extern void func_L01_0033D188(void *, s32);
extern s32 func_0038DC20(void *, f32);
extern s32 func_L01_0040E020(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_00445C48(void *, s32, s32, s32);
extern f32 func_0038CF38(void *, void *);
extern s32 func_L01_00445D30(void *, void *, s32, s32);
extern f32 func_003C3D30(void *, s32, s32, f32);
extern void func_003A52A0(s32, s32, void *);
extern void func_L01_0043B9E8(void *, s32, s32, s32);

typedef struct { Q_0033AC78 v; u8 *m; s32 flags; s32 unused; f32 f; s32 zero; } Hit_0033AC78;

void func_L01_0033AC78(u8 *m) {
    Hit_0033AC78 hit;
    Hit_0033AC78 *ph;
    Q_0033AC78 pos;
    u8 *other;
    u8 *op;
    u8 *p = *(u8 **)(m + 0x68);
    u8 *h;
    s32 special;
    s32 ok;
    s32 effect;
    f32 f;
    Hero_0033AC78 *hero;
    Hero_0033AC78 *hero2;
    Hero_0033AC78 *hero3;

    if (*(s16 *)(m + 0xAA) == 0x1FA) {
        func_003C2880(m);
        return;
    }
    if ((*(u16 *)(m + 0x34) & 0x80) && D_001D545C_sda == 4) return;
    if (!m[0x20]) func_L01_0033B530(m);
    if (!func_L01_0044C108(m + 0x10)) return;
    h = p + 0x30;
    if (((*(s32 *)(p + 0xDC) & 12) && *(s32 *)(p + 0xE4) != D_L01_001DFB40) || func_0038CE68(p + 0xC0, p + 0xC0) > 0.0f)
        func_L01_0033CBC0(m);
    if (!*(u8 **)(p + 0xD0)) *(u16 *)(h + 0x1E) |= 1;
    h = func_L01_00447490(m, 0xB030001, 0);
    special = 0;
    if (h && *(s32 *)(h + 0x24) == 0x2000000) {
        h = 0;
        special = 1;
    }
    switch (m[0x20]) {
    case 1:
        if (func_L01_004561B8(m)) *(s32 *)(p + 0x130) = 0;
        if (*(s16 *)(m + 0xAA) == 0x1F9 && ((hero = &D_001A4BE0, hero->p290 == m) || hero->p28c == m ||
                                           (hero->p35c == m && !hero->s36e) || hero->p538 == m || special)) {
            hero2 = &D_001A4BE0;
            if (hero2->i25cc == 15) {
                func_L01_0033C520(m, 1, 0);
                func_L01_0033C030(m);
                return;
            }
            m[0xBC] = 0;
            m[0x20] = 5;
            return;
        }
        if (!h || !(*(f32 *)(h + 0x2C) > 0.0f)) return;
        ok = 1;
        if (*(s16 *)(m + 0xAA) == 0x1F6 && !(*(s32 *)(h + 0x24) & 0x20000) &&
            *(s16 *)(*(u8 **)(h + 0x20) + 0xAA) != 0x1F9)
            ok = 0;
        if (*(s16 *)(m + 0xAA) == 0x1F9) {
            m[0x20] = 5;
            if (*(s32 *)(h + 0x24) & 0x20000) m[0xBC] = 1;
            else m[0xBC] = (s32)((func_003824E0(5.0f, 15.0f) * 5.0f + 2.0f) / 6.0f);
            *(U64_0033AC78 *)(p + 0xE8) = *(U64_0033AC78 *)(m + 0x38);
            ok = 0;
        }
        if (ok) {
            if (*(s16 *)(m + 0xAA) == 0x1F8) {
                if (!*(u8 **)(h + 0x20) ||
                    (*(s16 *)(*(u8 **)(h + 0x20) + 0xAA) != 71 && *(s16 *)(*(u8 **)(h + 0x20) + 0xAA) != 0) ||
                    D_001A5E08[0] != 9)
                    break;
                func_L01_0033C520(m, 0, h);
                func_L01_0033C030(m);
            } else {
                func_L01_0033C520(m, *(s16 *)(m + 0xAA) == 0x1F9, h);
                func_L01_0033C030(m);
            }
        }
        break;
    case 2:
        if (--m[0xBC] == 255) {
            m[0xA8] = 255;
            m[0x20] = 1;
        }
        return;
    case 3:
        if (*(s16 *)(m + 0xAA) == 0x1F9 && p[0xFA] < 18) {
            ph = &hit;
            hit.f = 2.0f;
            hit.v = *(Q_0033AC78 *)(m + 0xC0);
            hit.m = m;
            hit.zero = 0;
            func_0038CF68(&pos, m + 0xE0, 0.5f);
            vec_add_ab(&pos, &pos, m + 0x10);
            f = (f32)p[0xFA] / 17.0f;
            hit.flags = 0x30001;
            func_003D4D00(&pos, 16, m, ph, f + f);
            hit.flags = 0x30000;
            hero3 = &D_001A4BE0;
            effect = func_003D4D00(&pos, 16, hero3->p25c0, 0, f * 3.0f);
            if (effect)
                func_L01_00447718(m, &pos, D_L01_001EEA80, effect, (s32)hero3->p25c0, 0x10000, 0, 0x30000, -1,
                                  4.0f, 1.0f, 1.0f);
            ++p[0xFA];
            break;
        }
        if (p[0xF8]) {
            *(s32 *)(m + 0x98) = 0;
            *(u16 *)(m + 0x34) = (*(u16 *)(m + 0x34) | 0x41) & 0xEFFF;
            func_L01_004AA7E8(m, 1);
            if (*(s16 *)(m + 0xB4) >= 2) *(s16 *)(m + 0xB4) = 1;
            m[0x20] = 6;
            if (p[0xF9] != 255) p[0xF9] = func_00382498(30, 60);
        } else {
            func_L01_0033D188(m, 1);
            return;
        }
        break;
    case 6:
        ++*(s32 *)(p + 0x130);
        if (p[0xF9] == 255) return;
        hit.v = *(Q_0033AC78 *)(m + 0x10);
        *(f32 *)((u8 *)&hit + 8) += 0.5f;
        *(f32 *)((u8 *)&hit + 12) = 1.0f;
        if (func_0038DC20(&hit, (f32)*(s16 *)(m + 0x32)) != -1 || !func_L01_0040E020(p + 0xF9)) break;
        m[0x7F] = 0;
        if (m[0x21] == 255) {
            func_L01_004450F0(m, 1, -1);
            *(u16 *)(m + 0x34) &= 0xFFBE;
            *(u16 *)(m + 0x34) |= *(u16 *)(*(u8 **)(m + 0x24) + 0x44) & 0x1000;
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
            return;
        }
        func_L01_00445C48(&other, m[0x21], 0, 0);
        while (other) {
            if (m != other && !(func_0038CF38(m + 0x10, other + 0x10) > 0.1f) && other[0x20] == 1 &&
                !*(u8 **)((op = *(u8 **)(other + 0x68)) + 0xD0)) {
                *(Q_0033AC78 *)(m + 0x10) = *(Q_0033AC78 *)(other + 0x10);
                *(f32 *)(m + 0x18) += 1.0f;
                *(u8 **)(op + 0xD0) = m;
                *(u8 **)(p + 0xD4) = other;
                *(u8 **)(p + 0xD0) = 0;
                m[0x20] = 1;
                m[0x31] = 1;
                *(u16 *)(m + 0x34) &= 0xFFFE;
                *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
                *(u16 *)(m + 0x34) |= 0x1000;
                break;
            }
            func_L01_00445D30(&other, other, 0, 0);
        }
        if (m[0x20] != 1) {
            *(f32 *)(m + 0x18) = func_003C3D30(m + 0x10, 0, 0, 0.5f);
            m[0x20] = 1;
            *(s32 *)(p + 0xD0) = 0;
            *(s32 *)(p + 0xD4) = 0;
            m[0x31] = 1;
            *(u16 *)(m + 0x34) &= 0xFFFE;
            *(s32 *)(m + 0x98) = *(s32 *)(*(u8 **)(m + 0x24) + 0x10);
        }
        break;
    case 5:
        if (!m[0xBC]) {
            m[0xBC] = 149;
            *(U64_0033AC78 *)(p + 0xE8) = *(U64_0033AC78 *)(m + 0x38);
        } else if (m[0xBC] >= 13 && h) {
            m[0xBC] = (s32)((func_003824E0(5.0f, 15.0f) * 5.0f + 2.0f) / 6.0f);
        }
        if (m[0xBC] % 50 == 47 || m[0xBC] == 11) func_003A52A0(1, 32, m);
        if (m[0xBC] % 50 >= 34 || m[0xBC] < 12) func_L01_0043B9E8(m, 200, 64, 64);
        else *(U64_0033AC78 *)(m + 0x38) = *(U64_0033AC78 *)(p + 0xE8);
        if (m[0xBC] == 1 || D_001A71AC[0] == 22) {
            *(U64_0033AC78 *)(m + 0x38) = *(U64_0033AC78 *)(p + 0xE8);
            func_L01_0033C520(m, 1, 0);
            func_L01_0033C030(m);
        }
        m[0xA8] = 255;
        --m[0xBC];
        return;
    case 4:
        if (func_L01_0040E020(m + 0xBC)) {
            m[0x20] = 1;
            *(u16 *)(m + 0x34) &= 0xFFFE;
        }
        break;
    default:
        return;
    }
    m[0xA8] = 255;
}
/* localdecomp:end func_L01_0033AC78 */
#endif
