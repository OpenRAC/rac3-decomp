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

/* localdecomp:start func_L01_00485A10 */
s32 func_L01_00485A10(s32 i, s32 a, s32 b) {
    s32 r = i % 2;
    if (r) {
        a = b;
    }
    return a + i / 2;
}
/* localdecomp:end func_L01_00485A10 */

/* localdecomp:start func_L01_00485A38 */
extern S_002EA318 D_L01_002EA2D8[];

int func_L01_00485A38(int a0, int a1)
{
    return D_L01_002EA2D8[a0 * 2 + a1].f0;
}
/* localdecomp:end func_L01_00485A38 */

/* localdecomp:start func_L01_00485A60 */
s32 func_L01_00485A60(s32 a0, s32 a1) {
    return a0 * 2 + a1;
}
/* localdecomp:end func_L01_00485A60 */

/* localdecomp:start func_L01_00485A70 */
extern S_002EA318 D_L01_002EA2D8[];
extern u8 D_001425C0[];
extern Entry_00483CD8 D_L01_002C5600[];
extern s32 func_L01_00485A10(s32, s32, s32);
extern s32 func_L01_00517190(s32, s32);

void func_L01_00485A70(void) {
    s32 i;
    S_002EA318 *p = D_L01_002EA2D8;
    for (i = 0; i < 20; i++) {
        s32 h = func_L01_00485A10(i, 0xE002D, 0xE0038);
        func_L01_00517190(h, (&D_L01_002C5600[D_001425C0[p->f0]])->x38);
        p++;
    }
}
/* localdecomp:end func_L01_00485A70 */

/* localdecomp:start func_L01_00485B18 */
extern s32 D_L01_001D8560;
extern s32 D_L01_001D855C;
extern f32 D_L01_001D8584;
extern f32 D_L01_001D8588;
extern f32 D_L01_001D858C;
extern f32 D_L01_001D8590;
extern void func_L01_00516470(s32 a0, f32 a1, f32 a2);
void func_L01_00485B18(void) {
    f32 b;
    if (D_L01_001D8560 == 0) b = D_L01_001D858C; else b = D_L01_001D8590;
    func_L01_00516470(0xE000B, D_L01_001D8584 + (f32)D_L01_001D855C * D_L01_001D8588, b);
}
/* localdecomp:end func_L01_00485B18 */

/* localdecomp:start func_L01_00485B68 */
typedef struct {
    u8 x0;
    u8 x1;
    u8 pad2[0x6A];
    f32 x6C;
    u8 pad70[0x80];
} E_00485B68;
extern u8 D_001425C0[];
extern E_00485B68 D_L01_002C5600_00485B68[];

s32 func_L01_00485B68(s32 a0) {
    E_00485B68 *e = &D_L01_002C5600_00485B68[D_001425C0[a0]];
    f32 f = e->x6C * 20.0f;
    s32 k = e->x1;

    switch (a0) {
    case 0x57:
        switch (k) {
        case 0:
            break;
        case 1:
            f *= 1.25f;
            break;
        case 2:
            f *= 1.5f;
            break;
        case 3:
            f *= 4.0f;
            break;
        case 4: case 5: case 6: case 7:
            f *= 10.0f;
            break;
        }
        break;
    case 0x15:
        switch (k) {
        case 0: case 1: case 2: case 3:
            f *= 20.0f;
            break;
        case 4: case 5: case 6: case 7:
            f *= 13.0f;
            break;
        }
        break;
    case 0x4F:
        switch (k) {
        case 0: case 1:
            break;
        case 2:
            f += f;
            break;
        case 3:
            f *= 3.0f;
            break;
        case 4: case 5: case 6: case 7:
            f *= 4.0f;
            break;
        }
        break;
    case 0x2F:
        f *= 5.0f;
        break;
    case 0x10:
        switch (k) {
        case 4: case 5: case 6: case 7:
            f += f;
            break;
        }
        break;
    case 0x13:
        f += f;
        break;
    }
    return f;
}
/* localdecomp:end func_L01_00485B68 */
