#include "common.h"

/* NTSC-U counterpart of func_L30_004E6AD0 (src/levels/shared/L30_004E6AD0.c) */
typedef struct {
    u8 pad0[0x25C0];
    u8 *p25C0;
    s32 w25C4;
} S_004E6988;
extern S_004E6988 D_001A4BE0;
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L30_004E2BD0(s32);

/* localdecomp:start func_L30_004E2BD0 */
typedef struct S_004E6AD0 {
    u8 pad0[0x1B04];
    s32 x1B04;
    u8 pad1[0x1B10 - 0x1B08];
    void *x1B10;
    u8 pad2[0x1B24 - 0x1B14];
    u8 *x1B24;
    u8 pad3[0x25C0 - 0x1B28];
    u8 *x25C0;
    s32 x25C4;
    u8 pad4[0x25E9 - 0x25C8];
    u8 x25E9;
    u8 pad5;
    u8 x25EB;
} S_004E6AD0;

typedef struct V_004E6AD0 {
    f32 v[4];
} V_004E6AD0;

extern f32 func_L30_004E2A88(void);
extern void func_L30_004E2B48(V_004E6AD0 *, f32);
extern void func_L30_004B3EE8(s32, s32, s32, s32);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_L01_004A72A8(s32, s32, u8 *, s32);
extern void func_L30_0034FEA0(V_004E6AD0 *, f32);
extern void func_L30_0034E298(V_004E6AD0 *, f32);
extern void func_L30_003465D8(V_004E6AD0 *, f32);
extern void *func_L30_00350DA0(void *);

void func_L30_004E2BD0(s32 a0) {
    V_004E6AD0 v;
    f32 f;
    u8 *obj;

    ((S_004E6AD0 *)&D_001A4BE0)->x25E9 = 1;
    ((S_004E6AD0 *)&D_001A4BE0)->x25EB = a0;
    f = func_L30_004E2A88();
    func_L30_004E2B48(&v, f);
    if (((S_004E6AD0 *)&D_001A4BE0)->x25C4 == 0x9A) {
        func_L01_0050BB98(((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4 ? 0x3F : 0xF, 0, 4.0f);
    } else if (((S_004E6AD0 *)&D_001A4BE0)->x25C4 == 0xA3) {
        s32 a;

        a = ((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4 ? 0x17 : 0x19;

        if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] != 0x10) {
            s32 off = ((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4;
            if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] % 3 == 2) {
                off = 2;
                if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4) {
                    off = 0;
                }
            }
            if (((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] % 3 == 0) {
                off = 1;
                if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 == 4) {
                    off = 2;
                }
            }
            a = ((S_004E6AD0 *)&D_001A4BE0)->x25C0[0x43] + off;
        }
        func_L01_0050BB98(a, 0, 4.0f);
    } else if (((S_004E6AD0 *)&D_001A4BE0)->x1B04 != 4) {
        func_L30_004B3EE8(1, 0x3E, 0, 0);
    }
    obj = ((S_004E6AD0 *)&D_001A4BE0)->x1B24;
    if (obj != 0 && !((*(u8 **)(obj + 0x24))[0xC] < 2) && obj[0x43] != 1) {
        func_003BE4F0(obj, 1, 0, 5);
    }
    switch (((S_004E6AD0 *)&D_001A4BE0)->x1B04) {
    case 0:
        break;
    case 2:
        func_0039FE80(0x1F, 0, ((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        func_L30_0034FEA0(&v, f);
        break;
    case 3:
        func_L01_004A72A8(0, 0, ((S_004E6AD0 *)&D_001A4BE0)->x1B24, 0x1C7D);
        func_L30_0034E298(&v, f);
        break;
    case 4:
        if (((S_004E6AD0 *)&D_001A4BE0)->x1B10 == 0) {
            ((S_004E6AD0 *)&D_001A4BE0)->x1B10 = func_L30_00350DA0(((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        }
        break;
    case 1:
    case 5:
        func_0039FE80(0, 0, ((S_004E6AD0 *)&D_001A4BE0)->x25C0);
        func_L30_003465D8(&v, f);
        break;
    }
}
/* localdecomp:end func_L30_004E2BD0 */
