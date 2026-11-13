#include "common.h"

/* localdecomp:start func_L40_00433F50 */
typedef struct {
    s32 f58;
    s32 f5C;
    s32 pad;
} Slot_00433F50;

typedef struct {
    u8 pad00[0x10];
    s32 f10;
    s32 f14;
    u8 pad18[0x30 - 0x18];
    s32 w30[8];
    u8 b50[8];
    Slot_00433F50 slot[8];
} Rec_00433F50;

typedef struct {
    u8 pad00[0x2558];
    s32 *p2558;
} Obj_00433F50;

typedef struct {
    u8 pad00[8];
    s32 f08;
    u8 pad0C[0x128 - 0x0C];
    s32 f128;
} Glob_00433F50;

extern Glob_00433F50 D_001A5E50;
extern Obj_00433F50 *D_L40_002494B0;
__asm__(".extern D_L40_002494B0, 32");
extern void *func_0011D534(void *, s32, s32);
extern void func_L40_00433888(void *);
extern s32 func_L40_00433680(void *);
extern void func_L40_00433830(void *, u8, s32);

void func_L40_00433F50(u8 *ctx) {
    Rec_00433F50 *rec = *(Rec_00433F50 **)(ctx + 0x68);
    u8 mask[8];
    s32 idx;
    s32 key;
    s32 ok;
    s32 same;
    s32 flag;
    s32 i;
    Obj_00433F50 *o;

    idx = D_001A5E50.f08;
    if (rec->f10 != 0) {
        key = 0;
        ok = 1;
        same = 1;
        flag = 0;
        if (rec->slot[idx].f5C == 0) {
            key = rec->slot[idx].f58;
            func_0011D534(mask, 0, 8);
            for (i = 0; i < 8; i++) {
                o = (&D_L40_002494B0)[i];
                if (o != 0) {
                    if (o->p2558 != 0) {
                        mask[*o->p2558] = 1;
                    }
                }
            }
        } else {
            ok = 0;
        }
        if (ok) {
            for (i = 0; i < 8; i++) {
                if (mask[i] != 0) {
                    if (rec->b50[i] == 0) {
                        ok = 0;
                        break;
                    }
                    if (rec->w30[i] != key) {
                        same = 0;
                    }
                }
            }
            if (ok) {
                flag = 1;
                if (same == 0) {
                    func_L40_00433888(ctx);
                }
            } else if (rec->f14 > 0 && rec->f14 + 30000 < D_001A5E50.f128) {
                func_L40_00433888(ctx);
                flag = 1;
            }
        }
        if (flag) {
            rec->f10 = 0;
            rec->f14 = 0;
            func_0011D534(&rec->slot[idx], 0, 12);
        }
    }
    for (i = 0; i < 8; i++) {
        if (rec->slot[i].f5C != 0) {
            if (func_L40_00433680(&rec->slot[i]) != 0) {
                func_L40_00433830(ctx, i, rec->slot[i].f58);
            }
        }
    }
}
/* localdecomp:end func_L40_00433F50 */
