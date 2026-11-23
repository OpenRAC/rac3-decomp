/* PAL near miss: ryno_sun_update. 10 words differ with the file's flags (round 13, 2026-11-22;
 * was 162 once its declarations agreed with L01_003D9510.c). Same at level 05.
 * What still differs: only the loop counter's register. Retail puts `i` in $fp and the loop's
 * hoisted constants 3 and 1 in $s7 and $s6; here `i` (refs 7, live 120, priority 0.117) outranks
 * both constants (refs 5, live ~168, priority ~0.06) and takes $s6, so 3 and 1 move to $fp/$s7.
 * What closed the gap (162 -> 10): the twin ryno_seeker_blast's idioms (objects[i] indexed, the
 * D_L01_002C5600 row through an inline, the hero camera as a block-local struct alias
 * D_001A4BE0_003DF1B0 with the field at 0x25C0, the damage record as a struct); the direction
 * copied through a pointer (retail keeps &direction in $s0 across two calls: 181 -> 45); the
 * clear loop as a counting for over 0x50-byte rows with the field at +0x20 (retail clears
 * 0x2A3A60 + n * 0x50, not the row start: 45 -> 17); and func_L01_004501E8's prototype in
 * func_L01_00386B38's order, (void *, void *, s32 *, f32 x4, void *, s32, s32, f32, s32, void *,
 * s32, s32, s32), which fixes the stack-argument and $f16 order (17 -> 10).
 * Same bytes (don't repeat): i = 0 at the top of state 3; for/while/u32 i; i declared first;
 * an inline copy helper instead of the pointer. Worse: s32 i = 0 at the declaration (spills, 115);
 * do/while with a count > 0 guard (44); an explicit cursor pointer (68); reusing i for the clear
 * loop (38).
 * func_00382348 keeps the file's (void) prototype and is called through a cast, as origin/master's
 * ryno_seeker_blast does.
 */
#include "common.h"
/* localdecomp:start func_L01_003DF1B0 */
extern vu0_v4 D_L01_001E29E0;
extern s32 D_L01_001DF54C;
__asm__(".extern D_L01_001DF54C, 4");
extern u8 D_001425C0[];
extern u8 D_L01_002A3A40[];
typedef struct {
    u8 p0[0x25C0];
    u8 *camera;            /* 0x25C0 */
} Game_003DF1B0;
extern Game_003DF1B0 D_001A4BE0_003DF1B0;
typedef struct {
    u128_t velocity;
    u8 pad[0x10];
    s32 flags;
    u8 rest[0xC];
} Damage_003DF1B0;
typedef struct { u8 p0[0x20]; s32 owner; u8 p24[0x2C]; } Spark_003DF1B0;
static __inline__ Row_003DD9C8 *row_003DF1B0(void) {
    return &D_L01_002C5600[D_001425C0[0x97]];
}
void func_L01_003DF1B0(u8 *obj) {
    extern void func_L01_00404808(void (*)(u8 *), void *);
    extern void func_L01_003DF620(u8 *);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_00404A10(void (*)(u8 *), void *);
    extern void func_L01_003DF558(u8 *);
    extern void func_0038CBA0(void *, s32);
    extern void func_L01_004C84D8(void *);
    extern u8 *func_L01_004501E8(void *, void *, s32 *, f32, f32, f32, f32, void *, s32, s32, f32, s32, void *, s32, s32, s32);
    extern u8 *func_00382348(void);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00446748(void *, void *, s32, f32);
    extern void func_L01_00446978(void *, void *);
    extern void func_L01_004AAC98(s32, s32, void *, s32);
    extern void func_L01_00315900(void *, s32, void *);
    extern void func_L01_003DE198(void);
    extern void func_003C2880(u8 *);
    u8 *vars = *(u8 **)(obj + 0x68);
    vu0_v4 direction;
    u8 *objects[32];
    Damage_003DF1B0 damage;
    s32 count;
    s32 i;
    if (obj[0x20] != 1) func_L01_00404808(func_L01_003DF620, obj);
    if (obj[0x20] == 1) {
        if (func_0038CAD0(vars + 0x10)) {
            obj[0x20] = 5;
            *(s32 *)(vars + 4) = (D_L01_001DF54C * 5 + 2) / 6;
        }
    } else if (obj[0x20] == 5) {
        if (func_0038CAD0(vars + 8)) {
            obj[0x20] = 3;
            *(s32 *)(vars + 8) = 53;
        } else func_L01_00404A10(func_L01_003DF558, obj);
    } else if (obj[0x20] == 3) {
        {
            vu0_v4 *d = &direction;
            *d = D_L01_001E29E0;
        }
        func_0038CBA0(objects, 128);
        func_L01_004C84D8(obj);
        func_L01_004501E8(obj + 0x10, &direction, &count, 4.71238899230957f, 1.3962633609771729f, 60.0f, 0.0f, objects, 32, 0, 0.0f, 0, 0, 1, -1, 0);
        for (i = 0; i < count; i++) {
            u8 *state = ((u8 *(*)(void *))func_00382348)(objects[i]);
            if (objects[i] != 0 && *(u8 **)(objects[i] + 0x24) != 0
                && (*(u8 **)(objects[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] != 3) {
                if (*(f32 *)state > row_003DF1B0()->scale) {
                    damage.flags = 1;
                    func_0038CE20(&damage.velocity, obj + 0xD0, -1.0f);
                    ((f32 *)&damage.velocity)[3] = 5627.925f;
                    func_L01_00446748(&damage, objects[i], 0x110000, row_003DF1B0()->scale);
                    func_L01_00446978(objects[i], &damage);
                } else {
                    func_L01_004AAC98(2, 0, D_001A4BE0_003DF1B0.camera, 500);
                    func_L01_00315900(objects[i], 4, func_L01_003DE198);
                }
            } else if (objects[i] != 0 && *(u8 **)(objects[i] + 0x24) != 0
                       && (*(u8 **)(objects[i] + 0x24))[0x46] == 5 && state != 0 && state[0xE] == 3) {
                damage.flags = 1;
                func_0038CE20(&damage.velocity, obj + 0xD0, -1.0f);
                ((f32 *)&damage.velocity)[3] = 5627.925f;
                func_L01_00446748(&damage, objects[i], 0x110000, row_003DF1B0()->scale);
                func_L01_00446978(objects[i], &damage);
            }
        }
        {
            s32 n;
            for (n = 23; n >= 0; n--) {
                ((Spark_003DF1B0 *)D_L01_002A3A40)[n].owner = 0;
            }
        }
        func_003C2880(obj);
    }
}
/* localdecomp:end func_L01_003DF1B0 */
