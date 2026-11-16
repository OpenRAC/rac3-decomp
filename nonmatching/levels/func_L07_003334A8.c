/* PAL near miss, P01 wave 2 (2026-11-16), reconstructed from retail.
 * File flags: -O2 -G8 -fopt-stack -mno-check-zero-division @ps2as.
 * Stock checker: 90 positional differences. Remaining differences include
 * early-exit and switch-tail layout, weapon-pointer allocation and scheduling.
 * Not a full-program match; retain the source INCLUDE_ASM.
 */
#include "common.h"
typedef struct { s32 v[4]; } Items_3334A8;
typedef struct { u8 pad[0x34]; s32 group; u8 gap[0x7E]; s16 timer; } V_3334A8;
typedef struct { u8 pad; u8 level; u8 gap[0x82]; u16 available; u8 tail[0x6A]; } Weapon_3334A8;
extern u8 D_001425C0[];
extern s32 D_001427F0_003334A8[];
extern Weapon_3334A8 D_L07_002C72C0_003334A8[];
extern Items_3334A8 D_L07_001DD108;
extern u16 *D_L07_0021C020[];
extern s32 D_L07_001DF458_003334A8;
extern u8 *D_L07_001DF41C_003334A8;
extern s32 func_L07_003670F0(void);
extern s32 func_L07_003337A8(void *);
s32 func_L07_003334A8(u8 *self, s32 id) {
    V_3334A8 *v = *(V_3334A8 **)(self + 0x68);
    s32 kind, limit;
    Items_3334A8 items;
    if (!D_L07_002C72C0_003334A8[D_001425C0[id]].available && id != 135) return 0;
    if (D_001427F0_003334A8[id] > 0) goto reset;
    kind = 0;
    items = D_L07_001DD108;
    limit = 100;
    switch (id) {
        case 127: {
            s32 level = D_L07_002C72C0_003334A8[D_001425C0[127]].level;
            limit = 150;
            if (level < 3) kind = 1;
            else {
                items.v[0] = 775;
                kind = 2;
                if (level >= 4) items.v[1] = 7352;
            }
            break;
        }
        case 71: kind = 1; limit = 137; break;
        case 135: {
            u16 *p;
            if (self[0x20] != 6 || func_L07_003670F0()) goto reset;
            for (p = D_L07_0021C020[v->group];
                 (v->group & 255) != 255 && v->group <= D_L07_001DF458_003334A8 && p; p++) {
                u8 *obj;
                if (((s16 *)p)[-1] < 0 && p != D_L07_0021C020[v->group]) break;
                obj = D_L07_001DF41C_003334A8 + ((*p & 0x7FFF) << 8);
                if (!obj) break;
                if (obj[0x20] != 1) goto reset;
            }
            kind = 2;
            if (D_L07_002C72C0_003334A8[D_001425C0[135]].level >= 4) items.v[0] = 6291;
            else items.v[0] = 6258;
            break;
        }
        case 79: kind = 2; items.v[0] = 6247; break;
        case 95: kind = 2; items.v[0] = 6251; break;
        case 143: return 0;
    }
    if (kind == 0) return 1;
    if (kind == 2 && func_L07_003337A8(&items)) return 0;
    if (kind == 1 || kind == 2) {
        v->timer = v->timer + 1;
        return limit < v->timer;
    }
    return 0;
reset:
    v->timer = 0;
    return 0;
}
