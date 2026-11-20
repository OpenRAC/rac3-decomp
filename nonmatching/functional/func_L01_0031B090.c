/* functional: high. 37 words differ (eligibility boolean/branch order, color-tail allocation); eligibility checks, slot search, row indexing [mode][weapon] stride 0xCC0/16, color fetch and every stored field verified vs retail. The table uses a private row type and the alias D_L01_00274940_0031B090, so no typedef move is needed. */
/* PAL near miss (Codex wave 10): near miss: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details).
 * Worker's note: Best actual 37 diff (.09.log), eligibility boolean/branch and color-tail allocation; .best09.c copied existing later AcidRow typedef solely to measure; retained near omits duplicate; requires moving existing AcidRow_0031B3A0 typedef before this block; ...
 */
#include "common.h"
/* localdecomp:start func_L01_0031B090 */
typedef struct { u8 active, level; u8 pad2[0x46]; s16 replacement; u8 pad4A[0xA6]; } Weapon_0031B090;
typedef struct { s32 timer, color, amount, zero; f32 speed; u8 *owner; s32 arg, active; } Entry_0031B090;
extern Weapon_0031B090 D_L01_002C5600[];
extern u8 D_00142A60[];
extern u8 D_001425C0[];
extern E_31ABE0 D_L01_00274580[];
/* the later AcidRow_0031B3A0 table, declared here with a private row type and an alias name so it does not clash with the owner's later declaration */
typedef struct { f32 per_second; s32 seconds; u8 pad8[8]; } Row_0031B090;
extern Row_0031B090 D_L01_00274940_0031B090[][204];
static __inline__ u8 check2_0031B090(s32 n) {
    if (D_L01_002C5600[D_001425C0[n]].active) {
        if (D_L01_002C5600[D_001425C0[n]].level == 2) return 1;
        return 0;
    }
    return 0;
}
static __inline__ u8 check3_0031B090(s32 n) {
    s32 result = 0;
    if (D_L01_002C5600[D_001425C0[n]].active) result = D_L01_002C5600[D_001425C0[n]].level == 3;
    return (u8)result;
}
s32 func_L01_0031B090(u8 *m, s32 weapon, s32 arg) {
    extern f32 *func_00382348(u8 *);
    extern s32 func_L01_0031B038(s32);
    extern void func_003C6FB0(u8 *, s32 *, s32 *, s32 *);
    s32 result = 1;
    s32 mode;
    unsigned long flags;
    s32 effective = ((Weapon_0031B090 *)(weapon * 240 + (s32)D_L01_002C5600))->replacement;
    f32 *health;
    s32 i;
    s32 r, g, b;
    Entry_0031B090 *entry;
    if (effective == 0) effective = weapon;
    flags = D_00142A60[effective];
    if (((flags >> 3) & 1) == 0) goto reject;
    mode = 0;
    if (check2_0031B090(effective) || check3_0031B090(effective)) mode = 1;
    if ((*(u8 **)(m + 0x24))[0x46] != 5) return 1;
    if ((*(u16 *)(m + 0x34) & 0x1000) == 0) goto reject;
    goto eligible;
reject:
    return 1;
eligible:
    if (*(s8 *)(m + 0x20) < 0 || *(s32 *)(m + 0x98) == 0) return 1;
    health = func_00382348(m);
    if (health == 0 || *health <= 0.0f) return 1;
    if (func_L01_0031B038((s32)m) == -1) {
    for (i = 0; i < 30; i++) {
        if (D_L01_00274580[i].id == 0) {
            u8 *q;
            s32 got = 0;
            entry = (Entry_0031B090 *)&D_L01_00274580[i];
            entry->owner = m;
            entry->timer = D_L01_00274940_0031B090[mode][weapon].seconds * 50;
            entry->speed = D_L01_00274940_0031B090[mode][weapon].per_second * 0.01666667f;
            if (*(u16 *)(m + 0x34) & 0x20) {
                q = *(u8 **)(*(u8 **)(m + 0x68) + 0x10);
                if (q != 0 && *(s16 *)q != 0) {
                    r = q[4]; g = q[5]; b = q[6];
                    got = 1;
                }
            }
            if (!got) func_003C6FB0(entry->owner, &r, &g, &b);
            entry->active = 1;
            entry->color = (b << 16) + (g << 8) + r;
            entry->amount = 0x8000;
            entry->arg = arg;
            entry->zero = 0;
            result = 0;
            break;
        }
    }
    }
    return result;
}
/* localdecomp:end func_L01_0031B090 */
