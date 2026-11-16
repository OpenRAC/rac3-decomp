/* NTSC-U draft (Claude wave C3): C of func_L07_00332D68, the NTSC-U twin of func_L07_003334A8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss on NTSC-U: does not compile in its file's context yet (declaration conflicts; the worker's note at the top has the details) (NTSC-U twin "func_L07_00332D68", whose code is not the PAL one).
 * Worker's note: 134 words differ (200 vs 192 words), one compile iteration only: usability check (can item/weapon id be used): rec = &D_L07_002C7280[D_001425C0[id]] (0xF0-byte records, h84 / b1), D_001427F0[id] cooldown, a 16-byte copy of D_L07_001DD148 on the stack (patched ...
 */
#include "common.h"

/* localdecomp:start func_L07_00332D68 */
typedef struct { u8 pad0; u8 b1; u8 pad2[0x82]; u16 h84; u8 pad86[0x6A]; } S_Rec_332D68;
typedef struct { u8 b[16]; } S16_332D68;
extern u8 D_001425C0[];
extern s32 D_001427F0[];
extern S_Rec_332D68 D_L07_002C7280[];
extern S16_332D68 D_L07_001DD148;
extern u16 *D_L07_0021C020[];
extern u8 *D_L07_001DF41C[];
extern s32 D_001DF458_sda;
__asm__(".extern D_001DF458_sda, 4");
extern s32 func_L07_003661D8(void);
extern s32 func_L07_00333068(void *);

s32 func_L07_00332D68(u8 *a0, s32 id) {
    S_Rec_332D68 *rec;
    S_Rec_332D68 *r2;
    u8 *p;
    S16_332D68 tmp;
    s32 k;
    s32 mode;
    s32 idx;
    u16 *l;
    u8 *ent;

    rec = &D_L07_002C7280[D_001425C0[id]];
    if (rec->h84 == 0 && id != 0x87) {
        return 0;
    }
    p = *(u8 **)(a0 + 0x68);
    if (D_001427F0[id] > 0) {
        *(s16 *)(p + 0xB6) = 0;
        return 0;
    }
    tmp = D_L07_001DD148;
    k = 0x78;
    mode = 0;
    switch (id) {
    case 0x5F:
        *(s32 *)&tmp = 0x186B;
        mode = 2;
        break;
    case 0x47:
        mode = 1;
        k = 0xA5;
        break;
    case 0x4F:
        *(s32 *)&tmp = 0x1867;
        mode = 2;
        break;
    case 0x7F:
        r2 = &D_L07_002C7280[D_001425C0[0x7F]];
        k = 0xB4;
        if (r2->b1 < 3) {
            mode = 1;
        } else {
            *(s32 *)&tmp = 0x307;
            mode = 2;
            if (r2->b1 >= 4) {
                *(s32 *)(tmp.b + 4) = 0x1CB8;
            }
        }
        break;
    case 0x87:
        if (a0[0x20] != 6) {
            *(s16 *)(p + 0xB6) = 0;
            return 0;
        }
        if (func_L07_003661D8() != 0) {
            *(s16 *)(p + 0xB6) = 0;
            return 0;
        }
        idx = *(s32 *)(p + 0x34);
        l = D_L07_0021C020[idx];
        while ((u8)idx != 0xFF && D_001DF458_sda >= idx && l != 0 && (((s16 *)l)[-1] >= 0 || l == D_L07_0021C020[idx])) {
            ent = D_L07_001DF41C[0] + ((*l & 0x7FFF) << 8);
            l++;
            if (ent == 0) {
                break;
            }
            if (ent[0x20] != 1) {
                *(s16 *)(p + 0xB6) = 0;
                return 0;
            }
        }
        r2 = &D_L07_002C7280[D_001425C0[0x87]];
        *(s32 *)&tmp = r2->b1 < 4 ? 0x1872 : 0x1893;
        mode = 2;
        break;
    case 0x8F:
        return 0;
    }
    switch (mode) {
    case 0:
        return 1;
    case 1:
        break;
    case 2:
        if (func_L07_00333068(&tmp) != 0) {
            return 0;
        }
        break;
    default:
        return 0;
    }
    *(u16 *)(p + 0xB6) = *(u16 *)(p + 0xB6) + 1;
    return k < *(s16 *)(p + 0xB6);
}
/* localdecomp:end func_L07_00332D68 */
