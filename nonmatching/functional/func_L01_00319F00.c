/* functional: high. 140 words differ (scheduling/loop layout); compiles in file context after using the context's vu0_v4 D_L01_001E29C0. All four object states, color/fade math, constants, group-list loop and guards verified vs retail. */
/* PAL near miss (Codex wave 10): near miss: 140 words differ with the file's flags.
 * Worker's note: 52 differing words with --divs 1 (still no MATCH); case-2 index-mask reuse and loop-exit layout shift later code by one word. Best logs func_L01_00319F00.a08.log and .a08.diff.log; stopped after three equivalent residuals
 */
#include "common.h"
/* localdecomp:start func_L01_00319F00 */
#include "vu0.h"
extern s32 D_001D545C;
extern s32 D_L01_001D6694;
extern f32 D_L01_001DFB50;
extern f32 D_L01_001DFB4C;
extern s32 D_L01_001D6768;
extern s16 **D_L01_001D6764;
typedef struct { u8 bytes[0x20]; } Instance_00319F00;
typedef struct { u8 bytes[0x30]; vu0_v4 position; } Geometry_00319F00;
extern Instance_00319F00 *D_L01_001E0ED4;
extern Geometry_00319F00 *D_L01_001E0EDC;
void func_L01_00319F00(u8 *obj) {
    extern s32 func_L01_0044C108(void *);
    extern void func_003C2880(u8 *);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038D0B0(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_00404A10(void (*)(u8 *), u8 *);
    extern void func_L01_0031A560(u8 *);
    extern s32 func_00382380(void *, s32, s32);
    extern void func_L01_004B7FE8(void *, s32, s32, s32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern f32 func_0038CE68(f32 *, f32 *);
    u8 *p = *(u8 **)(obj + 0x68);
    vu0_v4 direction;
    if (D_001D545C == 7 && !func_L01_0044C108(obj + 0x10)) return;
    if (*(s32 *)(p + 0x80)) return;
    if (*(s32 *)(p + 0x84) && D_L01_001D6694) return;
    if (obj[0x20] && (D_L01_001DFB50 > 0.98f || D_L01_001DFB4C > 0.98f)) return;
    switch (obj[0x20]) {
    case 0:
        if (*(s32 *)p >= D_L01_001D6768 || !D_L01_001D6764[*(s32 *)p] || *(s32 *)p == -1) {
            func_003C2880(obj);
            return;
        }
        *(f32 *)(p + 8) = func_0038DB48(*(f32 *)(p + 8) * 0.017453292f);
        *(f32 *)(p + 4) = *(f32 *)(p + 4) * 0.017453292f * 0.020000001f;
        *(s32 *)(p + 0x14) = (p[0x22] << 16) | (p[0x21] << 8) | p[0x20];
        *(s32 *)(p + 0x18) = (p[0x25] << 16) | (p[0x24] << 8) | p[0x23];
        if (*(s32 *)(p + 0x68)) obj[0x30] = p[0x68];
        else obj[0x30] = 255;
        if (*(s32 *)(p + 0x1C)) {
            if (*(f32 *)(p + 0x7C) == 0.0f) obj[0x20] = 1;
            else obj[0x20] = 2;
            return;
        }
        *(s32 *)(p + 0x30) = (p[0x29] << 24) | (p[0x28] << 16) | (p[0x27] << 8) | p[0x26];
        *(s32 *)(p + 0x34) = (p[0x2D] << 24) | (p[0x2C] << 16) | (p[0x2B] << 8) | p[0x2A];
        if (*(f32 *)(p + 0x40) == 0.0f && *(f32 *)(p + 0x44) == 0.0f && *(f32 *)(p + 0x48) == 0.0f) {
            *(s32 *)(p + 0x6C) = 1;
        }
        func_L01_00404A10(func_L01_0031A560, obj);
        obj[0x20] = 3;
        return;
    case 1: {
        s16 *item;
        s32 old, red, green, blue;
        Instance_00319F00 *target;
        f32 phase;
        if (*(s32 *)(p + 0x64) != -1 && !func_00382380(&D_L01_001E29C0, *(s32 *)(p + 0x64), 0)) break;
        phase = func_0038DAB8(*(f32 *)(p + 0xC), *(f32 *)(p + 4));
        *(f32 *)(p + 0xC) = phase;
        old = *(s32 *)(p + 0x10);
        if (*(f32 *)(p + 8) != 0.0f) {
            s32 selected = *(s32 *)(p + 0x14);
            if (phase > *(f32 *)(p + 8)) selected = *(s32 *)(p + 0x18);
            *(s32 *)(p + 0x10) = func_0038DBD8(old, selected, 0.120000005f);
        } else {
            *(s32 *)(p + 0x10) = func_0038DBD8(*(s32 *)(p + 0x14), *(s32 *)(p + 0x18), func_0038D0B0(phase) * 0.5f + 0.5f);
        }
        if (*(s32 *)(p + 0x10) != old) {
            red = *(s32 *)(p + 0x10) & 255;
            green = (*(s32 *)(p + 0x10) >> 8) & 255;
            blue = (*(s32 *)(p + 0x10) >> 16) & 255;
            for (item = D_L01_001D6764[*(s32 *)p]; item; item++) {
                if (item[-1] < 0 && item != D_L01_001D6764[*(s32 *)p]) break;
                target = &D_L01_001E0ED4[*item & 0x7FFF];
                if (!target) break;
                func_L01_004B7FE8(target, red, green, blue);
            }
        }
        return;
    }
    case 2: {
        s16 *item;
        Instance_00319F00 *target;
        Geometry_00319F00 *source;
        u16 index;
        f32 angle, blend;
        if (*(s32 *)(p + 0x64) != -1 && !func_00382380(&D_L01_001E29C0, *(s32 *)(p + 0x64), 0)) break;
        *(vu0_q *)&direction = *(vu0_q *)(p + 0x70);
        func_0038CF68(&direction.x, &direction.x, 1.0f / direction.w);
        angle = func_0038DAB8(*(f32 *)(p + 0xC), *(f32 *)(p + 4));
        {
            s32 group = *(s32 *)p;
            s16 **groups = D_L01_001D6764;
            *(f32 *)(p + 0xC) = angle;
            item = groups[group];
        }
        for (; item; item++) {
            if (item[-1] < 0 && item != D_L01_001D6764[*(s32 *)p]) break;
            index = *item;
            target = &D_L01_001E0ED4[index & 0x7FFF];
            if (!target) break;
            source = &D_L01_001E0EDC[index & 0x7FFF];
            if (!source) break;
            angle = func_0038DB48(*(f32 *)(p + 0xC) - func_0038CE68(&source->position.x, &direction.x) * 6.2831855f);
            if (*(f32 *)(p + 8) != 0.0f) {
                blend = angle - *(f32 *)(p + 8) + 1.0f;
                if (angle > 2.1415927f) blend = 3.1415927f - angle;
                if (blend > 1.0f) blend = 1.0f;
                else if (blend < 0.0f) blend = 0.0f;
                *(s32 *)(p + 0x10) = func_0038DBD8(*(s32 *)(p + 0x18), *(s32 *)(p + 0x14), blend);
            } else {
                *(s32 *)(p + 0x10) = func_0038DBD8(*(s32 *)(p + 0x14), *(s32 *)(p + 0x18), func_0038D0B0(angle) * 0.5f + 0.5f);
            }
            func_L01_004B7FE8(target, p[0x10], p[0x11], p[0x12]);
        }
        return;
    }
    case 3:
        if (*(s32 *)(p + 0x64) != -1 && !func_00382380(&D_L01_001E29C0, *(s32 *)(p + 0x64), 0)) break;
        func_L01_00404A10(func_L01_0031A560, obj);
        return;
    }
}
/* localdecomp:end func_L01_00319F00 */
