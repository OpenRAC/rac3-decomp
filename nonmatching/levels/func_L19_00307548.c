/* func_L19_00307548 (Claude wave 14 r51, 2026-11-28). First draft kept here. */
/* func_L19_00307548: first draft (wave 14 r51), 281 diff with the file's flags (fresh entry, no metadata
 * injected). Structure from the retail assembly: the level switch (0xC/0x13/0x200), the mode switch
 * (case 1 first, case 0 shares default), the moby state switch (0 / 2 / default with the shared vars+0x30
 * copy), the debris count from D_L19_001DF250/D_L19_001DF24C (plain scalars without .extern: retail reads
 * D_L19_001DF250 gp-relative only in a delay slot and through lui elsewhere), the area record reached as
 * &D_L19_001E1F40 after reading its position (retail derives the base as position - 0x140), the two
 * spawn loops and the two dust loops. Known gaps: (1) the two VU0 differences are raw asm blocks with
 * vf1/vf2 named, because this file's line lacks -mvu0-use-vf0-vf2 and vu0.h's "j" operands need it; retail
 * interleaves other insns between the lqc2/vsub/sqc2, i.e. separate helper statements: the function needs
 * the existing line `-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as -mvu0-use-vf0-vf2`; it starts
 * 8-aligned (0x307548) but ends at 0x307E2C (not 8-aligned) as the last function of L19_00307350.c;
 * (2) retail pads both div.s with 2 nops: NEEDS divs row 'func_L19_00307548 2 2'; (3) register
 * allocation ($fp holds the 'more' flag in retail, mode $s3, count $s2) and the division order. */
#include "common.h"

/* localdecomp:start func_L19_00307548 */
typedef int Q_00307548 __attribute__((mode(TI)));
typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) V_00307548;
typedef struct {
    u8 pad000[0x140];
    V_00307548 pos;
    u8 pad150[4];
    f32 f154;
    f32 f158;
} Area_00307548;
extern s32 D_001D545C;
extern s32 D_L19_001F2380[];
extern s32 D_L19_001D6C40; __asm__(".extern D_L19_001D6C40, 4");
extern f32 D_L19_001DC528; __asm__(".extern D_L19_001DC528, 4");
extern f32 D_L19_001DC52C; __asm__(".extern D_L19_001DC52C, 4");
extern f32 D_L19_001DC530; __asm__(".extern D_L19_001DC530, 4");
extern s32 D_L19_001DC540; __asm__(".extern D_L19_001DC540, 4");
extern f32 D_L19_001DC544; __asm__(".extern D_L19_001DC544, 4");
extern f32 D_L19_001DC53C; __asm__(".extern D_L19_001DC53C, 4");
extern f32 D_L19_001DC548; __asm__(".extern D_L19_001DC548, 4");
extern f32 D_L19_001DC54C; __asm__(".extern D_L19_001DC54C, 4");
extern f32 D_L19_001DC550; __asm__(".extern D_L19_001DC550, 4");
extern f32 D_L19_001DF9B0; __asm__(".extern D_L19_001DF9B0, 4");
__asm__(".extern D_L19_001E0E14, 4");
extern f32 D_L19_001DF24C;
extern f32 D_L19_001DF250;
extern Q_00307548 D_L19_001DF9A0;
extern Area_00307548 D_L19_001E1F40;

void func_L19_00307548(u8 *self)
{
    extern s32 func_L01_0044C108(void *);
    extern s32 func_L01_0040E050(void *);
    extern void func_L01_0044FB80(void *, void *, f32, f32, f32);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_00382380(void *, s32, s32);
    extern void func_L13_004429F0(void *, s32, void *, f32);
    extern void func_L13_0044DB78(void *, s32, void *, f32);
    extern void func_L19_00445488(void *);
    V_00307548 pos;
    V_00307548 diff;
    V_00307548 tmp;
    V_00307548 dist;
    V_00307548 vel;
    u8 *vars;
    Area_00307548 *area;
    s32 mode;
    s32 more;
    s32 count;
    s32 n;
    s32 kind;
    f32 rate, top, low, spread;
    f32 a, b, m, d, size, h, floor;

    if (func_L01_0044C108(self + 0x10) == 0) {
        return;
    }
    D_L19_001D6C40 = D_L19_001F2380[0];
    switch (D_001D545C) {
    case 0xC:
    case 0x13:
    case 0x200:
        mode = 1;
        break;
    default:
        mode = 0;
        break;
    }
    switch (mode) {
    case 1:
        rate = 0.2f;
        top = 5.0f;
        low = 0.5f;
        spread = 0.020000001f;
        more = 0;
        break;
    case 0:
    default:
        rate = 0.15f;
        more = 1;
        top = 18.0f;
        low = D_L19_001DC528;
        spread = 0.040000003f;
        break;
    }
    if (0.0f <= D_L19_001DC53C) {
        low = D_L19_001DC53C;
    }
    vars = *(u8 **)(self + 0x68);
    switch (self[0x20]) {
    case 0:
        self[0x30] = 0xFF;
        self[0x20] = 2;
        func_L19_00307350(mode);
        break;
    case 2:
        if (func_L01_0040E050(&D_L19_001E0E10) != 0) {
            func_L19_00307350(mode);
        }
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                : "=m"(diff) : "m"(*(V_00307548 *)(vars + 0x30)), "m"(D_L19_001E1F40.pos) : "vf1", "vf2");
        D_L19_001DF9A0 = *(Q_00307548 *)&diff;
        count = D_L19_001E0E14;
        a = D_L19_001DF250 - D_L19_001DC548;
        b = D_L19_001DF24C - D_L19_001DC54C;
        if (a < 0.0f) {
            a = 0.0f;
        }
        if (b < 0.0f) {
            b = 0.0f;
        }
        a = a / (1.0f - D_L19_001DC548);
        b = b / (1.0f - D_L19_001DC54C);
        if (b < a) {
            m = a * D_L19_001DC550;
        } else {
            m = b * D_L19_001DC550;
        }
        count = (s32)((f32)count * (1.0f - m));
        size = (f32)count;
        tmp = *(V_00307548 *)((u8 *)&D_L19_001E1F40 + 0x140);
        area = &D_L19_001E1F40;
        func_L01_0044FB80(&tmp, &tmp, 16.0f, area->f158, area->f154);
        tmp.z = area->pos.z + D_L19_001DC52C;
        for (n = count; n > 0; n--) {
            pos = tmp;
            pos.x += func_0038D098(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, D_L19_001DC530);
            pos.y += func_0038D0B0(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, D_L19_001DC530);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "=m"(vel) : "m"(pos), "m"(D_L19_001E1F40.pos) : "vf1", "vf2");
            dist = vel;
            d = func_0038CED8(&dist);
            if (d <= 8.0f) {
                vel.x = D_L19_001E0E00.x0 + func_003824E0(-spread, spread);
                vel.y = D_L19_001E0E00.x4 + func_003824E0(-spread, spread);
                vel.z = -(top * 0.020000001f);
            } else {
                h = top - (d - 8.0f) * rate;
                if (h < low) {
                    h = low;
                }
                vel.x = D_L19_001E0E00.x0 + func_003824E0(-spread, spread);
                vel.y = D_L19_001E0E00.x4 + func_003824E0(-spread, spread);
                vel.z = -(h * 0.020000001f);
            }
            vel.w = 0.0f;
            if (func_00382380(&pos, *(s32 *)(vars + 0x48), 0) != 0) {
                continue;
            }
            D_L19_001DF9B0 = area->pos.z - D_L19_001DC544;
            h = func_L19_003074D8((V_3074D8 *)&pos);
            if (h < area->pos.z + D_L19_001DC52C) {
                floor = h;
                if (h < D_L19_001DF9B0) {
                    floor = D_L19_001DF9B0;
                }
                kind = 0;
                if (8.0f < d) {
                    kind = D_L19_001DC540;
                }
                if (mode == 0) {
                    func_L13_004429F0(&pos, kind, &vel, floor);
                }
                if (mode == 1) {
                    func_L13_0044DB78(&pos, kind, &vel, floor);
                }
            }
        }
        tmp = *(V_00307548 *)((u8 *)&D_L19_001E1F40 + 0x140);
        area = &D_L19_001E1F40;
        count = (s32)(size * 1.4f);
        tmp.z = area->pos.z + D_L19_001DC52C;
        for (n = count; n > 0; n--) {
            dist.x = D_L19_001E0E00.x0 + func_003824E0(-spread, spread);
            dist.y = D_L19_001E0E00.x4 + func_003824E0(-spread, spread);
            dist.z = -(top * 0.020000001f);
            dist.w = 0.0f;
            pos = tmp;
            pos.x += func_0038D098(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, 8.0f);
            pos.y += func_0038D0B0(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, 8.0f);
            if (func_00382380(&pos, *(s32 *)(vars + 0x48), 0) != 0) {
                continue;
            }
            D_L19_001DF9B0 = area->pos.z - D_L19_001DC544;
            h = func_L19_003074D8((V_3074D8 *)&pos);
            if (h < area->pos.z + D_L19_001DC52C) {
                floor = h;
                if (h < D_L19_001DF9B0) {
                    floor = D_L19_001DF9B0;
                }
                if (mode == 0) {
                    func_L13_004429F0(&pos, 0, &dist, floor);
                }
                if (mode == 1) {
                    func_L13_0044DB78(&pos, 0, &dist, floor);
                }
            }
        }
        if (more) {
            tmp = *(V_00307548 *)((u8 *)&D_L19_001E1F40 + 0x140);
            area = &D_L19_001E1F40;
            func_L01_0044FB80(&tmp, &tmp, 30.0f, area->f158, area->f154);
            tmp.z = area->pos.z + D_L19_001DC52C;
            for (n = count; n > 0;) {
                n--;
                pos = tmp;
                pos.x += func_0038D098(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, 30.0f);
                pos.y += func_0038D0B0(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, 30.0f);
                func_L19_00445488(&pos);
            }
            tmp = *(V_00307548 *)((u8 *)&D_L19_001E1F40 + 0x140);
            area = &D_L19_001E1F40;
            func_L01_0044FB80(&tmp, &tmp, 4.0f, area->f158, area->f154);
            tmp.z = area->pos.z + D_L19_001DC52C;
            for (n = count; n > 0;) {
                n--;
                pos = tmp;
                pos.x += func_0038D098(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, 8.0f);
                pos.y += func_0038D0B0(func_003824E0(0.0f, 6.2831855f)) * func_003824E0(0.0f, 8.0f);
                func_L19_00445488(&pos);
            }
        }
        break;
    }
    *(V_00307548 *)(vars + 0x30) = *(V_00307548 *)((u8 *)&D_L19_001E1F40 + 0x140);
}
/* localdecomp:end func_L19_00307548 */
