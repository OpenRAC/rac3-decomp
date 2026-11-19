#include "common.h"

/* localdecomp:start func_L39_00607498 */
extern void *func_L01_004CD738(void *);
extern u8 *func_L39_00606D28(u8 *);
extern void func_00128BF0(void *, ...);
extern void func_003A26F0(void *, s32, s32);
extern void func_L39_00602108(s32 *, u32, s32, s32);
extern void func_0011D534(void *, s32, s32);
extern void func_001264E0(s32);
extern s16 func_L39_005C2B10(s32);
extern void func_L39_00602010(s32 *);
extern void func_L39_00606E40(u8 *, s32, s32);
extern void *func_L39_00602240(void);
extern s32 func_003B43B0(s32);
extern s32 func_L39_005DBEE8(s32 *, s32, s32);
extern s32 *func_L39_0059E7C8(void);
typedef struct { s32 offset, size; } E_00607498;
typedef struct { u8 pad0[0x4954]; s32 base; u8 pad1[0x1870]; E_00607498 first; u8 pad2[0x810]; E_00607498 tbl[400]; } G_00607498;
typedef struct { u8 c[8]; } N_00607498;
typedef struct S_00607498 {
    u8 *end;
    s32 zero[0x1C20];
    u8 pad7084[0xC];
    u8 pool[0x18C00];
    u8 sub0[0x18];
    u8 sub1[0x50F0];
    s32 f24D98, f24D9C, f24DA0, f24DA4, f24DA8;
    u8 pad24DAC[8];
    s32 f24DB4, f24DB8, f24DBC;
    u8 buf0[0x20];
    u8 buf1[0x100];
} S_00607498;
extern G_00607498 D_001F0A00;
extern N_00607498 D_L39_00245718[];
extern u8 D_L39_002456F8[];
extern s32 D_L39_002412DC;
extern s32 D_L39_00242CC0;
extern S_00607498 *D_L39_00242A50;

S_00607498 *func_L39_00607498(S_00607498 *obj, void *arg) {
    s32 i;
    s32 *q;
    s32 nmaps;
    s32 h;
    N_00607498 name;
    u32 j;
    s32 p;
    s32 retry;

    q = &obj->zero[0];
    for (i = 0x707; i != -1; i--) {
        q[0] = 0;
        q[1] = 0;
        q[2] = 0;
        q[3] = 0;
        q += 4;
    }
    func_L01_004CD738(obj->sub0);
    func_L39_00606D28(obj->sub1);
    func_00128BF0(D_L39_002456F8, arg);
    D_L39_00242A50 = obj;
    p = (s32)obj + 0x24EE0;
    obj->end = (u8 *)((p + 3) & ~3);
    obj->f24D98 = 0x24EE0;
    func_003A26F0(obj->pool, D_001F0A00.first.offset + D_001F0A00.base, D_001F0A00.first.size);
    func_L39_00602108((s32 *)obj->sub0, 0x10, (s32)obj->zero, 0x7080);
    obj->f24D9C = 0;
    obj->f24DA0 = 0;
    obj->f24DA4 = 0;
    obj->f24DA8 = 0;
    obj->f24DB4 = 0;
    obj->f24DB8 = 0;
    obj->f24DBC = 0;
    func_0011D534(obj->buf0, 0, 0x20);
    func_0011D534(obj->buf1, 0, 0x100);
    func_001264E0(0);
    do {
        retry = 0;
        name = D_L39_00245718[0];
        for (j = 0; j < 8; j++) {
        }
        func_L39_005C2B10(1);
        func_L39_00602010((s32 *)obj->pool);
    } while (retry);
    nmaps = 10;
    func_L39_00606E40(obj->sub1, (s32)obj, (s32)obj->sub0);
    if (D_001F0A00.tbl[D_L39_002412DC % nmaps].size != 0) {
        func_003A26F0(((void *(*)(s32))func_L39_00602240)(D_001F0A00.tbl[D_L39_002412DC % nmaps].size << 11), D_001F0A00.tbl[D_L39_002412DC % nmaps].offset + D_001F0A00.base, D_001F0A00.tbl[D_L39_002412DC % nmaps].size);
        h = func_003B43B0(0);
        func_L39_005DBEE8((s32 *)h, (s32)((void *(*)(s32))func_L39_00602240)(0), 0);
    } else {
        func_L39_005DBEE8((s32 *)func_003B43B0(0), 0, 0);
    }
    if (D_L39_00242CC0 >= 2) {
        func_003A26F0(((s32 *(*)(s32))func_L39_0059E7C8)(D_001F0A00.tbl[312].size << 11), D_001F0A00.tbl[312].offset + D_001F0A00.base, D_001F0A00.tbl[312].size);
        h = func_003B43B0(1);
        func_L39_005DBEE8((s32 *)h, (s32)((s32 *(*)(s32))func_L39_0059E7C8)(0), 0);
        h = func_003B43B0(2);
        func_L39_005DBEE8((s32 *)h, (s32)((s32 *(*)(s32))func_L39_0059E7C8)(0), 0);
    } else {
        func_L39_005DBEE8((s32 *)func_003B43B0(1), 0, 0);
        func_L39_005DBEE8((s32 *)func_003B43B0(2), 0, 0);
    }
    return obj;
}
/* localdecomp:end func_L39_00607498 */

LINKER_REMNANT("asm/levels", func_L39_006077E0);
