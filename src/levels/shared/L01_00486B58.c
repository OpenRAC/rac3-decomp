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
extern Obj *func_003B42F8(s32);

/* localdecomp:start func_L01_00486B58 */
extern s32 D_L01_001D86D8, D_L01_001D86DC, D_L01_001D86E0, D_L01_001D86E4;
typedef struct { u8 pad0[0x4954]; s32 f4954; } S_160C40_00486B58;
extern S_160C40_00486B58 D_00160C40_00486B58;
extern f32 D_L01_001D86C8, D_L01_001D86CC, D_L01_001D86D0, D_L01_001D86D4;
extern f32 D_L01_001D8740, D_L01_001D8744, D_L01_001D8748, D_L01_001D874C;
extern f32 D_L01_001D8750, D_L01_001D8754, D_L01_001D8758, D_L01_001D875C;
extern f32 D_L01_001D8760, D_L01_001D8764, D_L01_001D8768, D_L01_001D876C;
__asm__(".extern D_L01_001D86D8, 4");
__asm__(".extern D_L01_001D86DC, 4");
__asm__(".extern D_L01_001D86E0, 4");
__asm__(".extern D_L01_001D86E4, 4");
__asm__(".extern D_L01_001D86C8, 4");
__asm__(".extern D_L01_001D86CC, 4");
__asm__(".extern D_L01_001D86D0, 4");
__asm__(".extern D_L01_001D86D4, 4");
__asm__(".extern D_L01_001D8740, 4");
__asm__(".extern D_L01_001D8744, 4");
__asm__(".extern D_L01_001D8748, 4");
__asm__(".extern D_L01_001D874C, 4");
__asm__(".extern D_L01_001D8750, 4");
__asm__(".extern D_L01_001D8754, 4");
__asm__(".extern D_L01_001D8758, 4");
__asm__(".extern D_L01_001D875C, 4");
__asm__(".extern D_L01_001D8760, 4");
__asm__(".extern D_L01_001D8764, 4");
__asm__(".extern D_L01_001D8768, 4");
__asm__(".extern D_L01_001D876C, 4");
extern u8 D_L01_002EA828[], D_L01_002EA8A8[];
extern void *func_003BB3A8(s32);
extern void func_L01_00486A38(s32, f32 *, f32 *);
extern Obj *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
extern s32 func_00381FF0(s32);
extern void func_003B9298(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003E8FE8(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E7F20(s32, s32);
extern s32 func_003E8A08(s32, s32, s32);
extern void func_L01_00517538(s32, f32, f32);
extern void func_003B5060(s32);
extern s32 func_003E9270(s32, u32, f32, f32, f32, f32, f32, f32);
extern void func_003E9138(s32, u32, f32, f32, f32, f32, s32);
extern s32 func_003E9358(s32, void *, u32, f32, f32, f32, f32, f32);
extern s32 func_003E7AC8(s32, s32);
extern s32 func_L01_00518010(s32, s32);
extern s32 func_003E8898(s32, f32, f32);
extern s32 func_003E8AE8(s32, s32, s32, s32, s32, s32);
extern s32 func_003E8A58(s32, s32, s32, s32, s32);
extern s32 func_003E8710(s32, void *);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_003E87B8(s32, s32, s32);
extern s32 func_003E8630(s32, s32);
extern s32 func_003E8348(s32, s32);
extern void func_L01_00487538(void);
extern void func_L01_00517BF8(s32, s32, s32, s32, s32, s32);
extern void func_L01_00517DB8(s32, s32, s32, f32);
extern void func_L01_00517D18(s32);

static __inline__ s32 slot_offset_00486B58(s32 i, s32 j, f32 *off) {
    s32 ok = 0;
    *off = 0.0f;
    if (j <= 0 || i < 4) {
        if (j > 0) *off = D_L01_001D86D0 * 0.5f;
        ok = 1;
    }
    return ok;
}

void func_L01_00486B58(void) {
    f32 scale = 1.0f, zero = 0.0f;
    s32 i, j, index;
    f32 offset;
    s32 a, b, c;
    D_L01_001D86D8 = (s32)func_003BB3A8(0);
    D_L01_001D86E0 = (s32)func_003BB3A8(0);
    D_L01_001D86DC = D_L01_001D86D8 + 0x9600;
    D_L01_001D86E4 = D_L01_001D86E0 + 0x9600;
    func_L01_00486A38(0x103, &scale, &zero);
    func_003B4528(func_003B42F8(0), D_L01_001D86D8, D_L01_001D86DC, D_00160C40_00486B58.f4954, (s32)&D_00160C40_00486B58 + 0x6478);
    func_003B4528(func_003B42F8(1), D_L01_001D86E0, D_L01_001D86E4, D_00160C40_00486B58.f4954, (s32)&D_00160C40_00486B58 + 0x5800);
    D_L01_002EA828[0] = 0;
    D_L01_002EA8A8[0] = 0;
    func_003B9298(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 0xD0008,
        func_00381FF0(0x103), 0xD0006, 0x124, 0xD0007, 0xCD5, zero);
    func_003E8FE8(0xD0009, func_00381FF0(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD0009, 1);
    func_003E8FE8(0xD000A, func_00381FF0(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E7F20(0xD000A, 1);
    func_003E8A08(0xD000B, 0xD0009, 0xD000A);
    func_L01_00517538(0xD0005, scale, scale);
    func_003B5060(0xF0001);
    func_003B5060(0xF000E);
    func_003B5060(0xF001A);
    func_003B5060(0xF0009);
    func_003B5060(0xF0025);
    func_003B5060(0xF0003);
    func_003E9270(0xF0004, 0x332299DE, 0.332655f, 0.372141f, 0.48969f, 0.468423f, D_L01_001D8768, D_L01_001D876C);
    func_003E9138(0xF0005, 0x332299DE, 0.332655f, 0.210096f, 0.466855f, 0.004917f, 0);
    func_003E9138(0xF0006, 0x332299DE, 0.332655f, 0.578772f, 0.466855f, 0.004917f, 0);
    func_003E9358(0xF0008, D_L01_002EA8A8, 0x8066CCFF, 0.336166f, 0.388667f, 0.460996f, 0.3115f, 1.0f);
    func_003E8FE8(0xF0007, (s32)D_L01_002EA828, 0x8066CCFF, 0.328167f, 0.179251f, 1.0f, 1.0f);
    func_003E7AC8(0xF0007, 1);
    func_003E7AC8(0xF0008, 1);
    func_L01_00518010(0xF0007, 1);
    func_003E8898(0xF0007, 0.460996f, 0.0f);
    func_003E7F20(0xF0008, 1);
    func_003E8AE8(0xF0003, 0xF0004, 0xF0005, 0xF0006, 0xF0008, 0xF0007);
    func_003E9270(0xF000A, 0x332299DE, D_L01_001D8740, D_L01_001D8744, D_L01_001D8748, D_L01_001D874C, D_L01_001D8768, D_L01_001D876C);
    func_003E9270(0xF000C, 0x332299DE, D_L01_001D8750, D_L01_001D8754, D_L01_001D8758, D_L01_001D875C, D_L01_001D8768, D_L01_001D876C);
    func_003E9138(0xF000B, 0x80808080, D_L01_001D8740 + 0.00048825f, D_L01_001D8744 + 0.002404f,
        (D_L01_001D8748 - D_L01_001D8768 * 2.0f) + 0.0009765f, D_L01_001D874C - D_L01_001D876C * 2.0f, 0);
    func_003E9138(0xF000D, 0x80808080, D_L01_001D8750 + 0.000244125f, D_L01_001D8754 + 0.001202f,
        (D_L01_001D8758 - D_L01_001D8768 * 2.0f) + 0.00048825f, (D_L01_001D875C - D_L01_001D876C * 2.0f) + 0.002404f, 0);
    func_003E8A58(0xF0003, 0xF000A, 0xF000C, 0xF000B, 0xF000D);
    func_003E8710(0xF000B, func_003B42F8(0));
    func_003E8710(0xF000D, func_003B42F8(1));
    func_L01_00516D60(0xF000B, 0);
    func_003E87B8(0xF000B, 1, 8);
    func_L01_00516D60(0xF000D, 0);
    func_003E87B8(0xF000D, 1, 8);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            if (slot_offset_00486B58(i, j, &offset)) {
                index = i + j * 5;
                a = index + 0xF000F;
                func_003E9270(a, 0x332299DE, (D_L01_001D86C8 + offset) + (f32)i * D_L01_001D86D0,
                    D_L01_001D86CC + (f32)j * D_L01_001D86D4, D_L01_001D8760, D_L01_001D8764, D_L01_001D8768, D_L01_001D876C);
                b = index + 0xF001B;
                func_003E9138(b, 0x8066CCFF, (D_L01_001D86C8 + offset) + (f32)i * D_L01_001D86D0,
                    D_L01_001D86CC + (f32)j * D_L01_001D86D4, D_L01_001D8760 - D_L01_001D8768 * 6.0f, D_L01_001D8764 - D_L01_001D8768 * 8.0f, 0);
                c = index + 0xF0026;
                func_003E9138(c, 0x192299DE, (D_L01_001D86C8 + offset) + (f32)i * D_L01_001D86D0,
                    D_L01_001D86CC + (f32)j * D_L01_001D86D4, D_L01_001D8760 - D_L01_001D8768 * 2.0f, D_L01_001D8764 - D_L01_001D876C * 2.0f, 0);
                func_003E8630(0xF001A, b);
                func_003E8630(0xF000E, a);
                func_003E8630(0xF0025, c);
                func_L01_00516D60(c, 0);
            }
        }
    }
    func_003E9138(0xF0019, 0x332299DE, 0.333237f, D_L01_001D86CC + D_L01_001D86D4 * 0.5f, 0.487357f, 0.0055f, 0);
    func_003E9270(0xF0002, 0x332299DE, D_L01_001D86C8, D_L01_001D86CC, D_L01_001D8760, D_L01_001D8764, D_L01_001D8768, D_L01_001D876C);
    func_003E8A08(0xF000E, 0xF0019, 0xF0002);
    func_003E8AE8(0xF0001, 0xF0025, 0xF000E, 0xF001A, 0xF0009, 0xF0003);
    func_003E8348(19, 0xF0001);
    func_L01_00487538();
    func_L01_00517BF8(0xF0008, 1, 1, 1, 0, 0);
    func_L01_00517DB8(0xF0008, 120, 0, 0.0005f);
    func_003E7F20(0xF0007, 1);
    func_L01_00517D18(0xF0008);
}
/* localdecomp:end func_L01_00486B58 */
