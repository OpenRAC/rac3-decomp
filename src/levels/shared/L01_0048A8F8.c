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
extern void func_003A2750(s32);
extern void func_003A2750(s32 a0);
extern u8 *D_001D52FC;
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_0048A9F0();
extern void func_L01_0048A8F8();

/* localdecomp:start func_L01_0048A8F8 */
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern s32 D_001D545C;
extern u8 D_L01_001D672C_0048A8F8;
extern void func_L01_0047EC88_0048A8F8(void);
extern s32 func_003B9BD0(s32);
extern void func_003BA4F8(s32, s32);
extern void func_L01_0048B588_0048A8F8(void *);
extern void func_L01_0048B3F0_0048A8F8(void);
extern void func_L01_0048B738_0048A8F8(void);
extern void func_L01_0048BD78_0048A8F8(void);
extern s32 func_L01_0047DAB0_0048A8F8(void);
extern s32 func_003A5348(s32, s32, s32);
extern void *func_L01_00495030_0048A8F8(void);
extern void func_L01_00517748_0048A8F8(s32);
extern void func_L01_00516090_0048A8F8(void *);
extern void func_003BB0E8(s32);
extern s32 func_L01_0047EBE0_0048A8F8(void);
extern void func_L01_0047DAC8_0048A8F8(void);

void func_L01_0048A8F8(void *a0) {
    func_L01_0047EC88_0048A8F8();
    func_003BA4F8(func_003B9BD0(0), *(s32 *)(D_001D52FC + 0x1C4));
    func_L01_0048B588_0048A8F8(a0);
    func_L01_0048B3F0_0048A8F8();
    func_L01_0048B738_0048A8F8();
    func_L01_0048BD78_0048A8F8();
    if (func_L01_0047DAB0_0048A8F8() != 0) {
        if (D_L01_001D672C_0048A8F8 == 0) {
            if (D_001D545C == 12 || D_001D545C == 18) {
                func_003A5348(5, 0, 0);
                func_L01_00517748_0048A8F8((s32)func_L01_00495030_0048A8F8());
                func_L01_00516090_0048A8F8(a0);
            } else {
                func_003BB0E8(D_001D545C);
                func_003A5348(20, 0, 0);
                func_L01_00517748_0048A8F8(func_L01_0047EBE0_0048A8F8());
            }
        }
        func_L01_0047DAC8_0048A8F8();
        func_L01_00516090_0048A8F8(a0);
    }
}
/* localdecomp:end func_L01_0048A8F8 */

/* localdecomp:start func_L01_0048A9F0 */
extern void func_L01_00517918_0048A9F0(s32);
extern void func_L01_0048B338(void);
extern void func_003A2750(s32);

void func_L01_0048A9F0(void) {
    func_L01_00517918_0048A9F0(16);
    func_L01_00517918_0048A9F0(17);
    func_L01_00517918_0048A9F0(20);
    func_L01_0048B338();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0048A9F0 */

/* localdecomp:start func_L01_0048AA30 */
extern void func_L01_0047E4B8_0048AA30();

void func_L01_0048AA30(void) {
    func_L01_0047E4B8_0048AA30();
}
/* localdecomp:end func_L01_0048AA30 */

/* localdecomp:start func_L01_0048AA50 */
extern void func_L01_0047E520_0048AA50();

void func_L01_0048AA50(void) {
    func_L01_0047E520_0048AA50();
}
/* localdecomp:end func_L01_0048AA50 */

/* localdecomp:start func_L01_0048AA70 */
extern void func_L01_00517748_0048AA70(s32);
extern s32 func_L01_0047EBE0_0048AA70(void);
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_003BB0E8(s32);
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_00516090_0048AA70(s32);

void func_L01_0048AA70(s32 a0, s32 a1) {
    if (a1 >= 2 && a1 != D_001D545C && (a1 != 3 || D_001D545C != 6)) {
        func_003BB0E8(a1);
        func_003A5348(0x14, 0, 0);
        func_L01_00517748_0048AA70(func_L01_0047EBE0_0048AA70());
        func_L01_00516090_0048AA70(a0);
    }
}
/* localdecomp:end func_L01_0048AA70 */
