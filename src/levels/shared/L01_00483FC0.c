#include "common.h"

typedef struct {
    int f0;
    char pad[64];
} S_002EA318;
typedef struct {
    s32 idx;
    u8 pad[0x40];
} S_482AE0;
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
    u8 pad0[56];
    u16 x38;
    u8 pad3A[182];
} Entry_00483CD8;
typedef struct Obj_484598 Obj_484598;
typedef struct {
    u8 pad[12];
    void (*fn)(Obj_484598 *);
} Vt_484598;
struct Obj_484598 {
    u8 pad[4];
    Vt_484598 *vt;
};
typedef struct { u8 pad[0x38]; u16 h38; u8 pad3A[0xF0 - 0x3A]; } E_4848A8;
typedef struct {
    s32 x0;
    s32 x4;
    u8 pad8[0x82];
    u16 x8A;
    u8 pad8C[0x64];
} E_4858E8;
typedef struct {
    u8 pad[56];
    u16 unk38;
    u8 pad2[182];
} S_002C5640;
typedef struct {
    u8 pad0[56];
    u16 f56;
    u8 pad58[182];
} Entry_00485FF8;
typedef struct {
    s32 id;
    u8 flag;
    u8 pad[0xAB];
} Ent4876B0;
typedef struct {
    s32 obj;
    u8 pad[81];
    char name[91];
} Slot_00487740;
typedef struct VObj_487AC0 VObj_487AC0;
typedef struct {
    u8 pad[12];
    void (*fn)(VObj_487AC0 *self);
} VTbl_487AC0;
struct VObj_487AC0 {
    s32 pad;
    VTbl_487AC0 *vtbl;
};

/* localdecomp:start func_L01_00483FC0 */
extern s32 func_L01_00517918_00483FC0();

void func_L01_00483FC0(void) {
    func_L01_00517918_00483FC0(0x10);
    func_L01_00517918_00483FC0(0x11);
}
/* localdecomp:end func_L01_00483FC0 */

/* localdecomp:start func_L01_00483FE8 */
extern void func_L01_0047E4B8_00483FE8();

void func_L01_00483FE8(void) {
    func_L01_0047E4B8_00483FE8();
}
/* localdecomp:end func_L01_00483FE8 */

/* localdecomp:start func_L01_00484008 */
extern void func_L01_0047E520_00484008();

void func_L01_00484008(void) {
    func_L01_0047E520_00484008();
}
/* localdecomp:end func_L01_00484008 */

/* localdecomp:start func_L01_00484028 */
extern s32 func_L01_00484028(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0718;
extern s32 D_L01_001E0700[2];
extern void func_L01_00483928();
extern void func_L01_00483FC0();
extern void func_L01_00483DD8();
extern void func_L01_00483FE8_00484028(void);
extern void func_L01_00484008_00484028();
s32 func_L01_00484028(void) {
    if (D_L01_001E0718 == 0) {
        func_003E6FA0(D_L01_001E0700, (s32)func_L01_00483928, (s32)func_L01_00483FC0, (s32)func_L01_00483DD8, (s32)func_L01_00483FE8_00484028, (s32)func_L01_00484008_00484028);
        D_L01_001E0718 = 1;
    }
    return (s32)D_L01_001E0700;
}
/* localdecomp:end func_L01_00484028 */

INCLUDE_ASM("asm/levels", func_L01_00484080);

INCLUDE_ASM("asm/levels", func_L01_004845E8);

/* localdecomp:start func_L01_00484A38 */
extern s32 func_L01_00517918_00484A38();

void func_L01_00484A38(void) {
    func_L01_00517918_00484A38(0x10);
    func_L01_00517918_00484A38(0x11);
}
/* localdecomp:end func_L01_00484A38 */

/* localdecomp:start func_L01_00484A60 */
extern void func_L01_0047E4B8_00484A60();

void func_L01_00484A60(void) {
    func_L01_0047E4B8_00484A60();
}
/* localdecomp:end func_L01_00484A60 */

/* localdecomp:start func_L01_00484A80 */
extern void func_L01_0047E520_00484A80();

void func_L01_00484A80(void) {
    func_L01_0047E520_00484A80();
}
/* localdecomp:end func_L01_00484A80 */

/* localdecomp:start func_L01_00484AA0 */
extern s32 func_L01_00484AA0(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0750;
extern s32 D_L01_001E0738[2];
extern void func_L01_00484080();
extern void func_L01_00484A38();
extern void func_L01_004845E8();
extern void func_L01_00484A60_00484AA0(void);
extern void func_L01_00484A80_00484AA0();
s32 func_L01_00484AA0(void) {
    if (D_L01_001E0750 == 0) {
        func_003E6FA0(D_L01_001E0738, (s32)func_L01_00484080, (s32)func_L01_00484A38, (s32)func_L01_004845E8, (s32)func_L01_00484A60_00484AA0, (s32)func_L01_00484A80_00484AA0);
        D_L01_001E0750 = 1;
    }
    return (s32)D_L01_001E0738;
}
/* localdecomp:end func_L01_00484AA0 */
