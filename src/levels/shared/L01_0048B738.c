#include "common.h"

typedef struct {
    s32 w0;
    s32 w4;
    s32 w8;
    s32 w12;
} E_488750;
typedef struct VT_00489FA8 { u8 p0[12]; void (*f12)(void *); } VT_00489FA8;
typedef struct O_00489FA8 { u8 p0[4]; VT_00489FA8 *vt; } O_00489FA8;
typedef struct Obj_0048B530 Obj_0048B530;
typedef struct {
    void *pad0[3];
    void (*fn)(Obj_0048B530 *);
} ObjVtbl_0048B530;
struct Obj_0048B530 {
    s32 pad0;
    ObjVtbl_0048B530 *vtbl;
};
typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x6F30 - 0x4958];
    u8 f6F30[1];
} S_48D030;
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
typedef struct {
    s32 w0;
    void (*fn)(u32);
    s32 w8;
} E_0048D0C8;
typedef struct { u8 b[16]; } V16_48DCD8;

/* localdecomp:start func_L01_0048B738 */
typedef struct {
    s32 w0;
    s32 w4;
} P_0048B738;
typedef struct {
    u8 pad0[0xA8];
    P_0048B738 *pA8;
    u8 padAC[4];
} S_0048B738;

extern S_0048B738 D_L01_00233DD8_0048B738[];
extern f32 D_L01_001E0890[] __attribute__((section(".sdata")));
extern f32 D_L01_001E08A0_0048B738[] __attribute__((section(".sdata")));
extern s32 D_L01_001E08D0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D8A5C, 4");
__asm__(".extern D_L01_001D8A60_0048B738, 4");
__asm__(".extern D_L01_001D8A58, 4");
__asm__(".extern D_L01_001D8A14, 4");
__asm__(".extern D_L01_001D8A1C, 4");
__asm__(".extern D_L01_001D8A20, 4");
__asm__(".extern D_L01_001D8A24, 4");
__asm__(".extern D_L01_001D8A2C, 4");
__asm__(".extern D_L01_001D8A34, 4");
__asm__(".extern D_L01_001D8A38, 4");
__asm__(".extern D_L01_001D8A6C, 4");
extern f32 D_L01_001D8A5C;
extern f32 D_L01_001D8A60_0048B738;
extern f32 D_L01_001D8A58;
extern s32 D_L01_001D8A14;
extern s32 D_L01_001D8A1C;
extern s32 D_L01_001D8A20;
extern s32 D_L01_001D8A24;
extern s32 D_L01_001D8A2C;
extern s32 D_L01_001D8A34;
extern s32 D_L01_001D8A38;
extern s32 D_L01_001D8A6C;
extern s32 func_L01_00516D60_0048B738(s32, s32);
extern void func_L01_00517190(s32 id, s32 v);
extern s32 func_003A5348(s32, s32, s32);
extern void func_003A4F28(s32);
extern O_00489FA8 *func_003B42F8(s32);
extern void func_L01_0048BA38(s32);

void func_L01_0048B738(void) {
    D_L01_001D8A5C += D_L01_001D8A60_0048B738;
    D_L01_001E0890[0] += D_L01_001E08A0_0048B738[0];
    D_L01_001E0890[1] += D_L01_001E08A0_0048B738[1];
    switch (D_L01_001E08D0[0]) {
    case 0:
        if (D_L01_001D8A1C <= 0) {
            D_L01_001D8A1C = 0;
            if (D_L01_00233DD8_0048B738[D_L01_001D8A2C].pA8->w4) {
                func_L01_00516D60_0048B738(0x130027, 1);
                func_L01_00517190(0x130027, D_L01_00233DD8_0048B738[D_L01_001D8A2C].pA8->w4 + 1);
            } else {
                func_L01_00516D60_0048B738(0x130027, 0);
            }
        } else {
            D_L01_001D8A1C--;
        }
        if (D_L01_001D8A2C != D_L01_001D8A34) {
            D_L01_001D8A6C = func_003A5348(0x16, 4, 0);
            func_L01_0048BA38(1);
        }
        break;
    case 1:
        if (D_L01_001D8A34 == D_L01_001D8A2C && D_L01_001D8A38 == D_L01_001D8A34) {
            func_L01_0048BA38(4);
        } else if (D_L01_001D8A5C <= D_L01_001D8A58) {
            D_L01_001D8A5C = D_L01_001D8A58;
            func_L01_0048BA38(2);
        }
        break;
    case 2:
        if (D_L01_001D8A38 != D_L01_001D8A34) {
            func_L01_0048BA38(2);
        } else if (--D_L01_001D8A24 <= 0) {
            func_L01_0048BA38(3);
        }
        break;
    case 3:
        if (D_L01_001D8A38 != D_L01_001D8A34) {
            func_L01_0048BA38(2);
        } else if (D_L01_001D8A14 == D_L01_001D8A20) {
            if (D_L01_00233DD8_0048B738[D_L01_001D8A34].pA8->w0) {
                func_L01_00516D60_0048B738(0x13000F, 1);
                func_L01_00517190(0x13000F, D_L01_00233DD8_0048B738[D_L01_001D8A34].pA8->w0);
            } else {
                func_L01_00516D60_0048B738(0x13000F, 0);
            }
        } else if (D_L01_001D8A14 == 0) {
            s32 done = *(s32 *)func_003B42F8(1) == 2;
            if (done) {
                if (D_L01_001D8A6C != -1) {
                    func_003A4F28(D_L01_001D8A6C);
                    D_L01_001D8A6C = -1;
                }
                func_L01_0048BA38(4);
            }
        }
        if (D_L01_001D8A14 != 0) {
            D_L01_001D8A14--;
        }
        break;
    case 4:
        if (D_L01_001D8A38 != D_L01_001D8A34) {
            func_L01_0048BA38(1);
        } else if (D_L01_001D8A5C >= D_L01_001D8A58) {
            D_L01_001D8A5C = D_L01_001D8A58;
            func_L01_0048BA38(0);
        }
        break;
    }
}
/* localdecomp:end func_L01_0048B738 */

INCLUDE_ASM("asm/levels", func_L01_0048BA38);

INCLUDE_ASM("asm/levels", func_L01_0048BD78);
