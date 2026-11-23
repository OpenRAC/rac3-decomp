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
extern void func_L01_00517748(s32);
extern s32 func_L01_0047EBE0(void);

/* localdecomp:start func_L01_00483DD8 */
typedef struct {
    s32 w0;
    u8 pad4[4];
    u8 on;
    u8 pad9[7];
} Opt_483DD8;
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern u8 D_L01_001D84B0[8];
__asm__(".extern D_L01_001D84B0, 8");
extern s32 D_L01_001D84E0;
extern f32 D_L01_001D8504;
extern s32 D_L01_001D84BC[2];
__asm__(".extern D_L01_001D84BC, 16");
extern void func_L01_0047EC88_00483DD8(void);
extern s32 func_L01_0047EBE0_00483DD8(void);
extern void func_L01_00517748_00483DD8(s32);
extern void func_L01_00516090_00483DD8(void *);
extern s32 func_003A5348(s32, s32, s32);
extern void func_L01_00516470_00483DD8(s32, f32, f32);
extern s32 func_L01_005170B8_00483DD8(s32, u32);

void func_L01_00483DD8(void *self) {
    s32 flags;
    s32 found;
    s32 i;
    Opt_483DD8 *e;
    func_L01_0047EC88_00483DD8();
    flags = *(s32 *)(D_001D52FC + 0x1C4);
    if (flags & 0x4000) {
        found = 0;
        do {
            D_L01_001D84E0++;
            if (D_L01_001D84E0 >= 3) {
                D_L01_001D84E0 = 0;
            }
            if (((Opt_483DD8 *)D_L01_001D84B0)[D_L01_001D84E0].on) {
                found = 1;
            }
        } while (!found);
        func_003A5348(3, 0, 0);
    } else if (flags & 0x1000) {
        found = 0;
        do {
            D_L01_001D84E0--;
            if (D_L01_001D84E0 < 0) {
                D_L01_001D84E0 = 2;
            }
            if (((Opt_483DD8 *)D_L01_001D84B0)[D_L01_001D84E0].on) {
                found = 1;
            }
        } while (!found);
        func_003A5348(3, 0, 0);
    } else if (flags & 0x40) {
        if (((Opt_483DD8 *)D_L01_001D84B0)[D_L01_001D84E0].on) {
            void (*fn)(void) = (void (*)(void))D_L01_001D84BC[D_L01_001D84E0 * 4];
            if (fn != 0) {
                fn();
                func_L01_00516090_00483DD8(self);
                func_003A5348(4, 0, 0);
            }
        }
    } else if (flags & 0x910) {
        func_L01_00517748_00483DD8(func_L01_0047EBE0_00483DD8());
        func_L01_00516090_00483DD8(self);
    }
    func_L01_00516470_00483DD8(0xD0028, 0.5f, 0.5f - D_L01_001D8504 + (f32)D_L01_001D84E0 * D_L01_001D8504);
    e = (Opt_483DD8 *)D_L01_001D84B0;
    for (i = 2; i >= 0; i--) {
        if (e->on) {
            func_L01_005170B8_00483DD8(e->w0, 0x80808080);
        } else {
            func_L01_005170B8_00483DD8(e->w0, 0x80303030);
        }
        e++;
    }
}
/* localdecomp:end func_L01_00483DD8 */
