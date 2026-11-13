#include "common.h"

/* NTSC-U counterpart of func_L40_00423120 (src/levels/shared/L40_00422A78.c) */
/* localdecomp:start func_L40_00422850 */
typedef struct {
    u8 pad00[0x30];
    s32 f30;
    u8 pad34[0x40];
    s32 f74;
    u8 pad78[8];
    s32 f80;
} S2_423120;

typedef struct {
    u8 pad00[0x20];
    u8 f20;
    u8 pad21[0x13];
    u16 f34;
    u8 pad36[0x32];
    S2_423120 *f68;
    u8 pad6C[0x2C];
    s32 f98;
} Obj_423120;

extern void func_L01_00441FB8(void *, s32, s32);
extern void func_L39_005F08F8(void *, s32);
extern s32 func_L39_00619838(s32);
extern void func_L39_00660240(s32 *, void *, s32);
extern s32 func_L40_00421C10(void *);
extern s32 func_L40_00421C70(void *);
extern s32 func_L40_00421C80(void *);
extern s32 func_L40_00421C90(void *);
extern void func_L40_00421CA0(void *);
extern void func_L40_00421DA8(void *, s32, s32);
extern void func_L40_004233E0(void *);
extern void func_L40_004235C0(void *, s32);
extern void func_L40_00423C70(void *, s32, s32);
extern void func_L40_004C35D0(s32, s32, void *, s32);
extern s32 D_001A5F78[];

/* from rac4-decomp's func_L41_00411D70 */
void func_L40_00422850(Obj_423120 *obj, s32 *msg) {
    u8 b;
    s32 w;
    S2_423120 *s2;
    u32 type;
    s32 r;
    type = *msg & 0xF;
    s2 = obj->f68;
    switch (type) {
    case 0:
        if ((u32)(obj->f20 - 1) < 2) {
            u16 v;
            s2->f30 = 0;
            v = obj->f34 & 0xEFFF;
            obj->f34 = v;
            if (obj->f20 == 1) {
                func_L40_00423C70(obj, 0, 0);
            } else {
                obj->f98 = 0;
                obj->f34 = v | 0x41;
                func_L39_005F08F8(obj, 1);
                func_L01_00441FB8(obj, 4, -1);
            }
            if (func_L40_00421C70(obj) != 0) {
                func_L39_00660240(msg, &b, 1);
                s2->f80 = b;
            }
            if (func_L40_00421C10(obj) != 0 || func_L40_00421C90(obj) != 0 || func_L40_00421C70(obj) != 0) {
                func_L40_004233E0(obj);
            }
        }
        break;
    case 1:
        func_L39_00660240(msg, &w, 4);
        r = func_L39_00619838(w);
        if ((u32)(obj->f20 - 4) < 2) {
            func_L40_004235C0(obj, r);
        }
        obj->f98 = 0;
        obj->f34 = (obj->f34 | 0x41) & 0xEFFF;
        func_L39_005F08F8(obj, 1);
        func_L40_00421CA0(obj);
        s2->f74 = D_001A5F78[0];
        func_L01_00441FB8(obj, 6, -1);
        break;
    case 2:
        func_L40_00421DA8(obj, -1, 0);
        func_L40_004C35D0(0x15, 0, obj, 0);
        if (func_L40_00421C80(obj) != 0) {
            func_L40_004233E0(obj);
        }
        break;
    }
}
/* localdecomp:end func_L40_00422850 */
