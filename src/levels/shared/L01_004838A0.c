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

/* localdecomp:start func_L01_004838A0 */
extern s32 func_L01_0047EBE0_004838A0(void);
extern void func_L01_00517748(s32);

void func_L01_004838A0(void) {
    func_L01_00517748(func_L01_0047EBE0_004838A0());
}
/* localdecomp:end func_L01_004838A0 */

/* localdecomp:start func_L01_004838C8 */
extern u8 D_00142732[];
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);

void func_L01_004838C8(void) {
    D_00142732[0] = 2;
    func_L01_00517748(func_L01_0047EBE0());
}
/* localdecomp:end func_L01_004838C8 */

/* localdecomp:start func_L01_004838F8 */
extern u8 D_00142732[];
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(s32);

void func_L01_004838F8(void) {
    D_00142732[0] = 3;
    func_L01_00517748(func_L01_0047EBE0());
}
/* localdecomp:end func_L01_004838F8 */
