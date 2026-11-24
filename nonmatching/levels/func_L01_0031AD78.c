/* PAL near miss: acid_mod_tick. 99 words differ with the file's flags; 27 instructions ignoring
 * registers (round 14, 2026-11-24: the draft compiles in L01_00314158.c's context again, its
 * func_L01_00446760/func_L01_00446978 declarations were removed in favour of the file's).
 * Earlier worker's note: frame and most damage block agree, index strength reduction/64-bit index
 * wording and dead-state conditional allocation remain.
 * Retail tests D_L01_00274580[i].id with an unreduced `sll i,5; addu base` at the loop top while a
 * separate walking pointer ($s2, copied to $s1) serves the rest, and keeps i counting up. Written
 * plainly (`D[i].id` and a row pointer, or every access through &D[i]) gcc reduces the test to a
 * walking pointer and reverses the loop (136-139 words); this draft's 64-bit index arithmetic avoids
 * that but leaves dsll32/dsra32.
 */
#include "common.h"
/* localdecomp:start func_L01_0031AD78 */
typedef struct {
    f32 pos[4]; u8 pad10[8]; u8 kind, flag; u16 target; s32 pad1C; s32 active; u8 pad24[12];
} __attribute__((aligned(16))) Damage_0031AD78;
extern G_00318408 D_001A4BE0;
extern E_31ABE0 D_L01_00274580[];
static __inline__ u8 *entry_0031AD78(u32 base, s32 i) { return (u8 *)((long)i * 32 + (long)base); }
void func_L01_0031AD78(u8 *m) {
    extern f32 func_0038DAB8(f32, f32);
    extern f32 *func_00382348(u8 *);
    extern void func_0038CE20(f32 *, f32 *, f32);
    extern void func_0038CF68(f32 *, f32 *, f32);
    extern s32 func_0038CAD0(void *);
    extern void func_L01_0031AFB8(u8 *);
    extern f32 func_0038D098(f32);
    extern s32 func_0038DBD8(s32, s32, f32);
    extern void func_L01_0043B9E8(u8 *, s32, s32, s32);
    extern void func_L01_00404A10(void *, u8 *);
    extern u8 func_L01_0031B4F8[];
    f32 direction[4] __attribute__((aligned(16)));
    Damage_0031AD78 damage;
    s32 i;
    u8 *row = (u8 *)D_L01_00274580;
    u8 *r;
    u8 *obj;
    f32 *health;
    s32 dead, color;
    *(u128_t *)(m + 0x10) = *(u128_t *)&D_001A4BE0;
    for (i = 0; i < 30; i++, row += 32) {
        if (!*(s32 *)(entry_0031AD78((u32)D_L01_00274580, i) + 20)) continue;
        dead = 1;
        *(f32 *)(row + 0xC) = func_0038DAB8(*(f32 *)(row + 0xC), 0.25132742524147034f);
        obj = *(u8 **)(row + 0x14);
        r = entry_0031AD78((u32)D_L01_00274580, i);
        if (*(s8 *)(obj + 0x20) > -1) dead = 0;
        if (*(s32 *)(obj + 0x98) == 0) dead = 1;
        health = func_00382348(obj);
        if (health) {
            *health -= *(f32 *)(row + 0x10);
            if (*health <= 0.0f) {
                func_0038CE20(direction, (f32 *)(*(u8 **)(row + 0x14) + 0xC0), -1.0f);
                dead = 1;
                func_0038CF68(damage.pos, damage.pos, 0.002f);
                obj = *(u8 **)(row + 0x18);
                *(u8 **)(m + 0xB8) = obj;
                func_L01_00446760(damage.pos, obj, 0x1010000, direction, 0.001f);
                *(u128_t *)damage.pos = *(u128_t *)direction;
                damage.pos[3] = 5627.9248046875f;
                damage.flag = 1;
                damage.kind = 5;
                damage.target = *(u16 *)(*(u8 **)(row + 0x14) + 0xAA);
                damage.active = 1;
                func_L01_00446978(*(u8 **)(row + 0x14), &damage);
            }
        } else dead = 1;
        if (func_0038CAD0(r)) dead = 1;
        if (dead) {
            func_L01_0031AFB8(r);
            *(s32 *)(r + 0x14) = 0;
        } else if (*(s32 *)(r + 0x1C) == 0) {
            color = func_0038DBD8(*(s32 *)(r + 4), *(s32 *)(r + 8), (func_0038D098(*(f32 *)(r + 0xC)) + 1.0f) * 0.5f);
            func_L01_0043B9E8(*(u8 **)(r + 0x14), color & 255, (color >> 8) & 255, (color >> 16) & 255);
        } else {
            --*(s32 *)(r + 0x1C);
        }
    }
    func_L01_00404A10(func_L01_0031B4F8, m);
}
/* localdecomp:end func_L01_0031AD78 */
