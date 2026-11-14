#include "common.h"

/* NTSC-U counterpart of func_L30_004E58F8 (src/levels/shared/L30_004E5370.c) */
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
#include "vu0.h"
extern u8 *D_001D52FC;
#include "vu0.h"
extern u8 *D_001D52FC;

/* localdecomp:start func_L30_004E19F8 */
typedef struct S_004E58F8 {
    u8 pad0[0x1B04];
    s32 x1B04;
    s32 x1B08;
    u8 pad1[0x1B10 - 0x1B0C];
    s32 x1B10;
    u8 pad2[0x1B24 - 0x1B14];
    u8 *x1B24;
    u8 pad3[0x1B34 - 0x1B28];
    s32 x1B34;
    u8 pad4[0x25C0 - 0x1B38];
    u8 *x25C0;
    u8 pad5[0x25CC - 0x25C4];
    s32 x25CC;
} S_004E58F8;

extern s32 D_L30_001DBE78[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DBE78, 8");
extern s32 D_L30_001DBE90[] __attribute__((section(".sdata")));
__asm__(".extern D_L30_001DBE90, 8");
extern s32 D_L30_001DBEA8;
__asm__(".extern D_L30_001DBEA8, 4");
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern s32 D_L30_001DF2C0_004E19F8;
__asm__(".extern D_L30_001DF2C0_004E19F8, 16");
extern s32 D_L30_001DF2C0_004E19F8;
__asm__(".extern D_L30_001DF2C0_004E19F8, 4");
extern u8 *D_001D52FC;
extern void func_003BD360(void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0044CB08(void *, s32, s32, s32);
extern s32 func_L01_0045D358(s32, s32, s32, s32);
extern s32 func_L01_004F1068(s32, s32);
extern void func_L30_003505C8(s32);
extern void func_L30_004E17D0(void);
extern void func_L30_004E2BD0(s32);

void func_L30_004E19F8(void) {
    u8 *obj;
    s32 v;

    if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B08 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B24 == 0) {
        func_L30_004E17D0();
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x1B04 == 0) {
        if (((S_004E58F8 *)&D_001A4BE0)->x1B24 != 0) {
            func_003BD360(((S_004E58F8 *)&D_001A4BE0)->x1B24);
        }
        ((S_004E58F8 *)&D_001A4BE0)->x1B24 = 0;
    }
    obj = ((S_004E58F8 *)&D_001A4BE0)->x1B24;
    if (obj != 0) {
        if (!((*(u8 **)(obj + 0x24))[0xC] < 2) && obj[0x43] != 0) {
            if (obj[0x60] & 2) {
                func_003BE4F0(obj, 0, 0, 5);
            }
        }
        if (((S_004E58F8 *)&D_001A4BE0)->x1B24 != 0) {
            func_L01_0044CB08(((S_004E58F8 *)&D_001A4BE0)->x25C0, (s32)((S_004E58F8 *)&D_001A4BE0)->x1B24, 4, 0);
        }
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0) {
        v = D_L30_001DBE78[((S_004E58F8 *)&D_001A4BE0)->x1B04];
        if (D_001D545C == 0x22) {
            v = 0x32;
        }
        if (v < ((S_004E58F8 *)&D_001A4BE0)->x1B08) {
            ((S_004E58F8 *)&D_001A4BE0)->x1B08 = v;
        }
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x25CC != 0x14 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 6 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 9 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 0x24 && ((S_004E58F8 *)&D_001A4BE0)->x25CC != 3) {
        if (func_L01_0045D358(0x20, 4, 0, 0) != 0) {
            if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B08 > 0
                && (((S_004E58F8 *)&D_001A4BE0)->x1B34 == -1 || ((S_004E58F8 *)&D_001A4BE0)->x1B34 + D_L30_001DBE90[((S_004E58F8 *)&D_001A4BE0)->x1B04] < D_L30_001DF2C0_004E19F8)) {
                if (((S_004E58F8 *)&D_001A4BE0)->x1B24 == 0) {
                    func_L30_004E17D0();
                }
                func_L30_004E2BD0(0);
                ((S_004E58F8 *)&D_001A4BE0)->x1B08 = ((S_004E58F8 *)&D_001A4BE0)->x1B08 - 1;
                ((S_004E58F8 *)&D_001A4BE0)->x1B34 = D_L30_001DF2C0_004E19F8;
            } else if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 0 && ((S_004E58F8 *)&D_001A4BE0)->x1B08 <= 0
                       && (((S_004E58F8 *)&D_001A4BE0)->x1B34 == -1 || ((S_004E58F8 *)&D_001A4BE0)->x1B34 + D_L30_001DBE90[((S_004E58F8 *)&D_001A4BE0)->x1B04] < D_L30_001DF2C0_004E19F8)) {
                func_L01_004F1068(0xD, 0);
            }
        }
    }
    if (((S_004E58F8 *)&D_001A4BE0)->x1B10 != 0) {
        if (((S_004E58F8 *)&D_001A4BE0)->x1B04 != 4 || ((S_004E58F8 *)&D_001A4BE0)->x1B08 <= 0 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 0x14 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 6 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 9
            || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 0x24 || ((S_004E58F8 *)&D_001A4BE0)->x25CC == 3 || ((S_004E58F8 *)&D_001A4BE0)->x1B34 < 0
            || !(*(s32 *)(D_001D52FC + 0x1A0) & 0x20)) {
            func_L30_003505C8(((S_004E58F8 *)&D_001A4BE0)->x1B10);
            ((S_004E58F8 *)&D_001A4BE0)->x1B10 = 0;
            ((S_004E58F8 *)&D_001A4BE0)->x1B34 = -1;
        } else if (D_L30_001DF2C0_004E19F8 % D_L30_001DBEA8 == 0) {
            ((S_004E58F8 *)&D_001A4BE0)->x1B08 = ((S_004E58F8 *)&D_001A4BE0)->x1B08 - 1;
        }
    }
}
/* localdecomp:end func_L30_004E19F8 */
