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

/* declared by functions of L01_004838A0.c, which this file was cut from */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern u8 D_001425C0[];
extern int func_L01_00485A38(int, int);

/* localdecomp:start func_L01_004868D8 */

extern s32 D_L01_001D8554;
extern Obj *func_003B42F8(s32);
extern void func_003BB468(s32);
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);

void func_L01_004868D8(void) {
    Obj *o;
    func_003BB468(D_L01_001D8554);
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(19);
    o = func_003B42F8(0);
    o->vt->fn(o);
    func_003A2750(1);
    func_003A2750(1);
}
/* localdecomp:end func_L01_004868D8 */

/* localdecomp:start func_L01_00486940 */
extern void func_L01_0047E4B8_00486940();

void func_L01_00486940(void) {
    func_L01_0047E4B8_00486940();
}
/* localdecomp:end func_L01_00486940 */

/* localdecomp:start func_L01_00486960 */
extern void func_L01_0047E520_00486960();

void func_L01_00486960(void) {
    func_L01_0047E520_00486960();
}
/* localdecomp:end func_L01_00486960 */

/* localdecomp:start func_L01_00486980 */
extern s32 func_L01_00486980(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E07C8;
extern s32 D_L01_001E07B0[2];
extern void func_L01_00484AF8();
extern void func_L01_004868D8();
extern void func_L01_004863D8();
extern void func_L01_00486940_00486980(void);
extern void func_L01_00486960_00486980();
s32 func_L01_00486980(void) {
    if (D_L01_001E07C8 == 0) {
        func_003E6FA0(D_L01_001E07B0, (s32)func_L01_00484AF8, (s32)func_L01_004868D8, (s32)func_L01_004863D8, (s32)func_L01_00486940_00486980, (s32)func_L01_00486960_00486980);
        D_L01_001E07C8 = 1;
    }
    return (s32)D_L01_001E07B0;
}
/* localdecomp:end func_L01_00486980 */

/* localdecomp:start func_L01_004869D8 */
typedef struct {
    u8 pad0[8];
    s32 x8;
    u8 padC[0xF0 - 0xC];
} E_004869D8;
extern E_004869D8 D_L01_002C5600_004869D8[];
extern int func_L01_0047DB70(int);

s32 func_L01_004869D8(int a0, int a1) {
    int r = func_L01_00485A38(a0, a1);

    return func_L01_0047DB70(((E_004869D8 *)((u8 *)D_L01_002C5600_004869D8 + D_001425C0[r] * 0xF0))->x8) == r;
}
/* localdecomp:end func_L01_004869D8 */
