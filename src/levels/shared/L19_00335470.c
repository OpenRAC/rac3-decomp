#include "common.h"
#include "vu0.h"

/* localdecomp:start func_L19_00335470 */
#include "vu0.h"
extern u8 D_1A30B0[];
extern void func_L19_00355F40(s32, void *, s32);
extern void func_L19_003361E0(void *);
extern void func_L19_00336100(void *);
extern void func_L19_00335F58(void);
extern void func_L19_00336330(void *);
extern void func_L19_003357A0(void *);
extern void func_L01_004450F0(void *, s32, s32);
extern s32 func_L01_004561B8(void *);
extern s32 func_0038CAD0(void *);
extern void func_L01_00404A10_003355E8(void *, void *);
extern s32 func_L01_00456250(void *);
extern void *func_L04_00325460(void *, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, void *, f32, f32);
extern void func_003A4F28(s32);
extern s32 func_003A52A0(s32, s32, void *);
extern void func_003C2880(void *);

typedef struct { f32 x, y, z, w; } __attribute__((aligned(16))) Vec_00335470;

void func_L19_00335470(u8 *obj) {
    u8 *pv = *(u8 **)(obj + 0x68);
    s32 flags;
    s32 slot;
    u8 *rec;
    u8 *pos;

    switch (obj[0x20]) {
    case 0:
        pos = obj + 0x10;
        *(Vec_00335470 *)pv = *(Vec_00335470 *)pos;
        if (*(s32 *)(pv + 0x10) != -1 && *(s32 *)(pv + 0x14) != 0) {
            func_L19_00355F40(*(s32 *)(pv + 0x10), pos, 0);
        }
        func_L19_003361E0(obj);
        flags = *(s32 *)(pv + 0x3C);
        if (flags & 1) {
            if (flags & 0x10) {
                func_L19_00336100(obj);
            }
        }
        func_L01_004450F0(obj, 1, -1);
        break;
    case 1:
        if (func_L01_004561B8(obj) != 0) {
            *(Vec_00335470 *)(obj + 0x10) = *(Vec_00335470 *)pv;
        }
        if (func_0038CAD0(pv + 0x24) != 0) {
            *(s32 *)(pv + 0x24) = *(s32 *)(pv + 0x18);
            func_L01_004450F0(obj, 2, -1);
        }
        break;
    case 2:
        if (func_0038CAD0(pv + 0x24) != 0) {
            *(s32 *)(pv + 0x24) = *(s32 *)(pv + 0x1C);
            func_L01_004450F0(obj, 3, -1);
        }
        break;
    case 3:
        if (func_0038CAD0(pv + 0x24) != 0) {
            *(s32 *)(pv + 0x24) = *(s32 *)(pv + 0x20);
            func_L01_004450F0(obj, 1, -1);
        }
        break;
    }
    flags = *(s32 *)(pv + 0x3C);
    if ((flags & 0x20) == 0) {
        if ((flags & 0x40) == 0) {
            func_L19_00335F58();
        }
        func_L19_00336330(obj);
        func_L01_00404A10_003355E8(func_L19_003357A0, obj);
    }
    if (func_L01_00456250(obj) != 0) {
        Vec_00335470 v = { 0.0f, 0.0f, 1.0f, 0.0f };
        vec_add_ba(&v, &v, obj + 0x10);
        func_L04_00325460(&v, 0, 0, 0, 0, 20, 45, 1, 1, 0, 0, 0, 1.0f, 20.0f);
        if (*(s32 *)(pv + 0x10) != -1 && *(s32 *)(pv + 0x14) != 0) {
            func_L19_00355F40(*(s32 *)(pv + 0x10), obj + 0x10, 1);
        }
        slot = *(s32 *)(pv + 0xD8);
        if (slot != -1) {
            rec = D_1A30B0 + (slot << 7);
            if (*(u8 **)(rec + 0xDC) == obj && rec[0xD0] != 0) {
                func_003A4F28(slot);
            }
        }
        *(s32 *)(pv + 0xD8) = -1;
        func_003A52A0(1, 0, obj);
        func_003C2880(obj);
    } else {
        if (*(s32 *)(pv + 0xD8) != -1) {
            rec = D_1A30B0 + (*(s32 *)(pv + 0xD8) << 7);
            if (*(u8 **)(rec + 0xDC) == obj && rec[0xD0] != 0) {
                return;
            }
        }
        *(s32 *)(pv + 0xD8) = func_003A52A0(0, 4, obj);
    }
}
/* localdecomp:end func_L19_00335470 */

/* localdecomp:start func_L19_00335748 */
__asm__(".extern D_L19_001DCD24, 4");
extern f32 D_L19_001DCD24;
extern void func_0038CE20(void *, void *, f32);

void func_L19_00335748(u8 *obj, u8 *out) {
    func_0038CE20(out, obj + 0xC0, D_L19_001DCD24);
    vec_add_ba(out, out, obj + 0x10);
}
/* localdecomp:end func_L19_00335748 */
