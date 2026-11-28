/* func_L01_00390358 (Claude wave 14 r62, 2026-11-28). Replaces the earlier draft of this function (k6 agent 2, from its functional C). */
/* PAL near miss (wave 14 r62): func_L01_00390358, 142 differences with p10 check --divs 1 (first placement,
 * the file's line; the k6 draft gives 388 under the same check), 29 rows by difflib alignment, 442 = 442 words.
 * NEEDS divs row 'func_L01_00390358 1' (retail has one nop before its div.s).
 * Changed against the draft: every declaration inside the block (func_L01_00390AB8 with the file's own
 * f32 * prototype); case 0's search as `for (j = 0; j < n; j++)` over D_L01_001EEA80[j] (loop reversal gives
 * retail's s4 counter copied from n in a1, the list giv in s2) with its own n; the hero / stats pointers and
 * the 600.0f factor as locals of the loop body (loop.c hoists them: fp, s5, f20 as retail); the list entry
 * re-read after func_003C4B50 into a local t for the 0xAA chain, and again as t2 in the else branch; the gun
 * row read as the sibling func_L01_003912E0 does, `idx * 0xF0 + (s32)D_L01_002C5600` (mtlo/madd, lwc1 0x6C);
 * D_001D545C read once through a 16-byte alias (lui form) and once as the 4-byte scalar (gp form) as retail
 * does; bt as s32 (sra); the func_L01_004006C8 call written in both arms of the table test (cross-jumping
 * merges the tails); (f32)r converted before the scale is chosen, with the D_001426E0 pointer only on the
 * mm == 7 path; case 1 with its own counters, a hero pointer in the loop, vec_add_ba and a plain 128-bit zero
 * store for b (por/sq).
 * Left: the preheader order of the hoisted hero / list / stats addresses; in the table test retail loads the
 * table's %hi into a0 after the lh a2 in each arm (here v0/v1 first); retail converts the scaled r into v0 and
 * copies it to s0; case 1's sp+0x10 / counter order and the nop before its loop label.
 */
#include "common.h"

/* localdecomp:start func_L01_00390358 */
#include "vu0.h"
typedef struct { f32 f[4]; } __attribute__((aligned(16))) Vec_00390358;
typedef struct { u8 pad[0x25C0]; u8 *moby; } Hero_00390358;
__asm__(".extern D_L01_001D7BE0, 4");
extern s32 D_L01_001D7BE0;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 4");
extern s32 D_001D545C_00390358;
__asm__(".extern D_001D545C_00390358, 16");
__asm__(".extern D_001DAA34, 4");
extern f32 D_001DAA34;
extern u8 D_001A4BE0[];
extern u8 D_001425C0[];
extern u8 D_L01_002C5600[];
typedef struct { u8 pad[0x6C]; f32 gun; u8 rest[240 - 0x70]; } Row_00390358;
extern Row_00390358 D_L01_002C5600_00390358[];

extern u8 *D_L01_001EEA80[];
extern u8 D_00142DE0[0x100];
extern u8 D_00142660[0x80];
extern u8 D_001426E0[0x80];
extern u8 D_001BBE90[];
extern u8 D_001D60E0[];
extern u8 D_001D60D8[];
extern f32 D_L01_002F1600[];
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
extern s32 func_L01_004CB2D8(void);
void func_L01_00390358(u8 *obj) {
    extern void func_L01_004C7D98(void *, void *);
    extern void func_L01_0040E790(void *, void *, void *);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_L01_00390AB8(u8 *obj, f32 *dir1, f32 *dir2);
    extern s32 func_003D4D00(void *, s32, f32, void *, void *);
    extern u8 *func_00382348(void *);
    extern s32 func_003C4B50(void *);
    extern s32 func_L01_00444350(void);
    extern s32 func_L01_004006C8(u8 *, s32, s32);
    extern s32 func_L01_0041A4F0(void);
    extern void func_L01_00446780(void *, void *, s32, s32, s32, s32, f32, f32, f32);
    extern void func_L01_004450F0(void *, s32, s32);
    extern f32 func_003824E0(f32, f32);
    extern f32 func_00382538(void);
    extern s32 func_00382498(s32, s32);
    extern s32 func_00382468(s32);
    extern u8 *func_L01_003016B0(void *, s32, f32, f32);
    extern void func_L01_0043B9E8(void *, s32, s32, s32);
    extern u8 *func_L01_00468678(void *, void *, f32, f32, s32);
    extern u8 *func_L01_0046B288(void *, u32, u32, f32, f32, s32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038CAD0(void *);
    extern void func_003C2880(u8 *);
    Vec_00390358 a, c, b;
    u8 *vars = *(u8 **)(obj + 0x68);
    s32 i;
    u8 *p;
    switch (obj[0x20]) {
    case 0: {
        s32 n;
        func_L01_004C7D98(obj + 0x10, &a);
        func_L01_0040E790(&c, vars, &a);
        func_0038CF68(&c, &c, 0.040000002f);
        func_L01_00390AB8(obj, (f32 *)&c, (f32 *)&a);
        n = func_003D4D00(obj + 0x10, 0, 5.0f, obj, 0);
        {
            s32 j;
            for (j = 0; j < n; j++) {
                u8 *t;
                u8 *hero = D_001A4BE0;
                u8 *stats = D_00142DE0;
                f32 k600 = 600.0f;
                u8 *info = func_00382348(D_L01_001EEA80[j]);
                s32 h;
                if (info == 0) continue;
                if (D_L01_001EEA80[j] == 0) continue;
                if (*(u8 **)(D_L01_001EEA80[j] + 0x24) == 0) continue;
                if ((*(u8 **)(D_L01_001EEA80[j] + 0x24))[0x46] != 5) continue;
                if (D_L01_001EEA80[j] == *(u8 **)(hero + 0x25C0)) continue;
                h = *(s16 *)(D_L01_001EEA80[j] + 0xAA);
                if (h == 0x188A) continue;
                if (h == 0x1886) continue;
                if (func_003C4B50(D_L01_001EEA80[j]) != 0) continue;
                t = D_L01_001EEA80[j];
                info[0x2F] = 1;
                {
                    u8 *w = D_001425C0;
                    f32 gun = ((Row_00390358 *)(w[0x37] * 0xF0 + (s32)D_L01_002C5600))->gun;
                    *(s32 *)(info + 0x38) = (s32)(gun / *(f32 *)info * k600);
                }
                if (info[0x35] != 0) continue;
                h = *(s16 *)(t + 0xAA);
                if (h == 0x19DF || h == 0x19F1 || h == 0x1BC5 || h == 0x1A18 || h == 0x1A1C ||
                    h == 0x1A1F || h == 0x1A13 || h == 0x1666 || h == 0x1AFD || h == 0x1A0A ||
                    h == 0x16CB || h == 0x1BD9) continue;
                if ((u32)D_L01_001D7BE0 < 0x29) {
                    if (D_L01_001D7BE0 == 9) continue;
                    *(s32 *)(stats + 0xDC) += func_L01_00444350();
                } else {
                    s32 q, idx2, r, bt;
                    u8 *t2;
                    if (D_L01_001D7BE0 == 9) continue;
                    { u8 *g = D_00142660; q = (*(s32 *)(g + 0x38) + 0x31) / 0x32; }
                    t2 = D_L01_001EEA80[j];
                    idx2 = (((s32)(*(u16 *)(t2 + 0xB2) << 16)) >> 17) + (D_001D545C_00390358 << 10);
                    bt = D_001BBE90[idx2];
                    if ((*(u16 *)(t2 + 0xB2) & 1) ? ((bt >> 4) & 8) : (bt & 8))
                        r = func_L01_004006C8(D_001D60E0, *(u16 *)(t2 + 0xB6), *(s16 *)(t2 + 0xB2));
                    else
                        r = func_L01_004006C8(D_001D60D8, *(u16 *)(t2 + 0xB6), *(s16 *)(t2 + 0xB2));
                    r <<= hero[0x28C8];
                    if (func_L01_0041A4F0() != 0) {
                        u8 *e;
                        s32 mm = D_001D545C;
                        r = (s32)((f32)r * ((mm == 7 && (e = D_001426E0, e[0x7B] != 0)) ? D_001DAA34 : D_L01_002F1600[mm]));
                    }
                    *(s32 *)(stats + 0xDC) += r + q;
                }
            }
        }
        func_L01_00446780(obj, obj + 0x10, 0x8000000, 0, 1, 0, 2.5f, 1.0f, 1.0f);
        func_L01_004450F0(obj, 1, -1);
        break;
    }
    case 1: {
        s32 k;
        s32 type = *(s32 *)(vars + 0x18);
        if (type == 0x39 || type == 0x36 || type == 0x32) {
            f32 r = func_003824E0(3.5f, 4.5f);
            u8 *q = func_L01_003016B0(obj + 0x10, 5, r, 1.05f);
            if (q != 0) func_L01_0043B9E8(q, 0x52, 0xD1, 5);
        }
        k = 1;
        do {
            f32 sp;
            u8 *hero = D_001A4BE0;
            func_L01_004C7D98(obj + 0x10, &a);
            func_0038CF68(&a, &a, -1.0f);
            vec_add_ba(&a, obj + 0x10, &a);
            *(s128 *)&b = 0;
            b.f[0] = func_003824E0(-1.1f, 1.1f);
            b.f[1] = func_003824E0(-1.1f, 1.1f);
            b.f[2] = func_003824E0(0.5f, 1.0f);
            c = b;
            func_0038CF68(&c, &c, func_003824E0(0.004f, 0.012000001f));
            sp = func_003824E0(0.05f, 0.15f);
            p = func_L01_00468678(&a, &c, sp * 210000.0f, *(f32 *)(hero + 0x88) + 1.0f, (s32)0x8810D162);
            if (p != 0) p[3] = func_00382468(3) ? 0x48 : 0x44;
            k--;
        } while (k >= 0);
        if (D_L01_001D673C == 0 && func_L01_004CB2D8() == 0) {
            i = 0;
            do {
                f32 angle = func_00382538();
                f32 radius = func_003824E0(0.0f, 2.5f);
                f32 size = func_003824E0(0.0f, 1.5f);
                f32 life = func_003824E0(3.0f, 5.0f);
                s32 alpha = func_00382498(100, 160);
                a.f[0] = func_0038D098(angle) * radius;
                a.f[1] = func_0038D0B0(angle) * radius;
                a.f[2] = 0.0f;
                vec_add_ba(&a, &a, obj + 0x10);
                p = func_L01_0046B288(&a, 0x5005D152, 0x5D152, size, life, alpha);
                if (p != 0) p[3] = func_00382468(3) ? 0x48 : 0x44;
                i--;
            } while (i >= 0);
        }
        if (func_0038CAD0(vars + 0x18) != 0) func_003C2880(obj);
        break;
    }
    }
}
/* localdecomp:end func_L01_00390358 */
