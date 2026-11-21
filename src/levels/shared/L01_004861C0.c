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
extern S_002EA318 D_L01_002EA2D8[];
extern s32 func_L01_00485A10(s32, s32, s32);
extern s32 D_L01_001D8560;
extern s32 D_L01_001D855C;

/* localdecomp:start func_L01_004861C0 */
extern s32 D_L01_001D855C;
extern s32 D_L01_001D8560;
extern f32 D_L01_001D857C;
extern f32 D_L01_001D8580;
extern u8 D_00142CA0[];
extern int func_L01_00485A38(int, int);
extern void func_L01_00516AA0(s32, s32, s32);
extern void func_L01_004784C0(s32, s32, f32, f32);

void func_L01_004861C0(void) {
    s32 i;

    i = func_L01_00485A38(D_L01_001D855C, D_L01_001D8560);
    if (D_00142CA0[i] != 0) {
        func_L01_00516AA0(0xE0009, 1, 1);
        func_L01_004784C0(i, 0xE0009, D_L01_001D857C, D_L01_001D8580);
    } else {
        func_L01_00516AA0(0xE0009, 1, 0);
    }
}
/* localdecomp:end func_L01_004861C0 */

/* localdecomp:start func_L01_00486248 */
extern f32 D_L01_001D85A4_00486248;
extern f32 D_L01_001D85A8_00486248;
extern u8 D_00142CA0[];
extern int func_L01_00485A38_00486248(int, int);
extern void func_L01_00516AA0_00486248(s32, s32, s32);
extern void func_L01_004784C0_00486248(s32, s32, f32, f32);

void func_L01_00486248(void) {
    int i;
    int j;
    int a;
    int base;
    int h;

    for (i = 0; i < 2; i++) {
        base = 0xE004E;
        if (i == 0) {
            base = 0xE0043;
        }
        for (j = 0; j < 10; j++) {
            h = base + j;
            a = func_L01_00485A38_00486248(j, i);
            if (D_00142CA0[a] != 0) {
                func_L01_00516AA0_00486248(h, 1, 1);
                func_L01_004784C0_00486248(a, h, D_L01_001D85A4_00486248, D_L01_001D85A8_00486248);
            } else {
                func_L01_00516AA0_00486248(h, 1, 0);
            }
        }
    }
}
/* localdecomp:end func_L01_00486248 */

/* localdecomp:start func_L01_00486340 */
extern S_002EA318 D_L01_002EA2D8[];

extern u8 D_00142CA0[];
extern s32 func_L01_00485A10(s32, s32, s32);
extern void func_L01_00516AA0(s32, s32, s32);

void func_L01_00486340(void) {
    s32 i;
    for (i = 0; i < 20; i++) {
        s32 h = func_L01_00485A10(i, 0xE002D, 0xE0038);
        if (D_00142CA0[((S_482AE0 *)&D_L01_002EA2D8)[i].idx]) {
            func_L01_00516AA0(h, 1, 1);
        } else {
            func_L01_00516AA0(h, 1, 0);
        }
    }
}
/* localdecomp:end func_L01_00486340 */
