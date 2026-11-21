#include "common.h"

/* NTSC-U counterpart of func_L01_00486B58 (src/levels/shared/L01_00486B58.c): 8 -> 10 */
typedef struct Obj Obj;
typedef struct {
    s32 pad[3];
    void (*fn)(Obj *);
} ObjVt;
struct Obj {
    s32 pad;
    ObjVt *vt;
};
extern Obj *func_003AED40(s32);

/* localdecomp:start func_L01_004832F8 */
extern s32 D_L01_001D8708, D_L01_001D870C, D_L01_001D8710, D_L01_001D8714;
typedef struct { u8 pad0[0x4954]; s32 f4954; } S_160C40_00486B58;
extern S_160C40_00486B58 D_00160C40_004832F8;
extern f32 D_L01_001D86F8, D_L01_001D86FC, D_L01_001D8700, D_L01_001D8704;
extern f32 D_L01_001D8770, D_L01_001D8774, D_L01_001D8778, D_L01_001D877C;
extern f32 D_L01_001D8780, D_L01_001D8784, D_L01_001D8788, D_L01_001D878C;
extern f32 D_L01_001D8790_004832F8, D_L01_001D8794, D_L01_001D8798, D_L01_001D879C;
__asm__(".extern D_L01_001D8708, 4");
__asm__(".extern D_L01_001D870C, 4");
__asm__(".extern D_L01_001D8710, 4");
__asm__(".extern D_L01_001D8714, 4");
__asm__(".extern D_L01_001D86F8, 4");
__asm__(".extern D_L01_001D86FC, 4");
__asm__(".extern D_L01_001D8700, 4");
__asm__(".extern D_L01_001D8704, 4");
__asm__(".extern D_L01_001D8770, 4");
__asm__(".extern D_L01_001D8774, 4");
__asm__(".extern D_L01_001D8778, 4");
__asm__(".extern D_L01_001D877C, 4");
__asm__(".extern D_L01_001D8780, 4");
__asm__(".extern D_L01_001D8784, 4");
__asm__(".extern D_L01_001D8788, 4");
__asm__(".extern D_L01_001D878C, 4");
__asm__(".extern D_L01_001D8790_004832F8, 4");
__asm__(".extern D_L01_001D8794, 4");
__asm__(".extern D_L01_001D8798, 4");
__asm__(".extern D_L01_001D879C, 4");
extern u8 D_L01_002EA868[], D_L01_002EA8E8[];
extern void *func_003B5EC8(s32);
extern void func_L01_004831D8(s32, f32 *, f32 *);
extern Obj *func_003AED40(s32);
extern s32 func_003AEF70(void *, s32, s32, s32, s32);
extern s32 func_0037DF98(s32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern s32 func_003E34A0(s32, s32, s32);
extern void func_L01_00513548(s32, f32, f32);
extern void func_003AFAA8(s32);
extern s32 func_003E3D08(s32, u32, f32, f32, f32, f32, f32, f32);
extern void func_003E3BD0(s32, u32, f32, f32, f32, f32, s32);
extern s32 func_003E3DF0(s32, void *, u32, f32, f32, f32, f32, f32);
extern s32 func_003E2560(s32, s32);
extern s32 func_L01_00514020(s32, s32);
extern s32 func_003E3330(s32, f32, f32);
extern s32 func_003E3580(s32, s32, s32, s32, s32, s32);
extern s32 func_003E34F0(s32, s32, s32, s32, s32);
extern s32 func_003E31A8(s32, void *);
extern s32 func_L01_00512D70(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003E2DE0(s32, s32);
extern void func_L01_00483CD8(void);
extern void func_L01_00513C08(s32, s32, s32, s32, s32, s32);
extern void func_L01_00513DC8(s32, s32, s32, f32);
extern void func_L01_00513D28(s32);

static __inline__ s32 slot_offset_00486B58(s32 i, s32 j, f32 *off) {
    s32 ok = 0;
    *off = 0.0f;
    if (j <= 0 || i < 4) {
        if (j > 0) *off = D_L01_001D8700 * 0.5f;
        ok = 1;
    }
    return ok;
}

void func_L01_004832F8(void) {
    f32 scale = 1.0f, zero = 0.0f;
    s32 i, j, index;
    f32 offset;
    s32 a, b, c;
    D_L01_001D8708 = (s32)func_003B5EC8(0);
    D_L01_001D8710 = (s32)func_003B5EC8(0);
    D_L01_001D870C = D_L01_001D8708 + 0x9600;
    D_L01_001D8714 = D_L01_001D8710 + 0x9600;
    func_L01_004831D8(0x103, &scale, &zero);
    func_003AEF70(func_003AED40(0), D_L01_001D8708, D_L01_001D870C, D_00160C40_004832F8.f4954, (s32)&D_00160C40_004832F8 + 0x6478);
    func_003AEF70(func_003AED40(1), D_L01_001D8710, D_L01_001D8714, D_00160C40_004832F8.f4954, (s32)&D_00160C40_004832F8 + 0x5800);
    D_L01_002EA868[0] = 0;
    D_L01_002EA8E8[0] = 0;
    func_003B3DB8(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 0xD0008,
        func_0037DF98(0x103), 0xD0006, 0x124, 0xD0007, 0xCD5, zero);
    func_003E3A80(0xD0009, func_0037DF98(0x1B80), 0x8066CCFF, 0.035f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD0009, 1);
    func_003E3A80(0xD000A, func_0037DF98(0x1B81), 0x8066CCFF, 0.97f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD000A, 1);
    func_003E34A0(0xD000B, 0xD0009, 0xD000A);
    func_L01_00513548(0xD0005, scale, scale);
    func_003AFAA8(0xF0001);
    func_003AFAA8(0xF000E);
    func_003AFAA8(0xF001A);
    func_003AFAA8(0xF0009);
    func_003AFAA8(0xF0025);
    func_003AFAA8(0xF0003);
    func_003E3D08(0xF0004, 0x332299DE, 0.332655f, 0.372141f, 0.48969f, 0.468423f, D_L01_001D8798, D_L01_001D879C);
    func_003E3BD0(0xF0005, 0x332299DE, 0.332655f, 0.210096f, 0.466855f, 0.004917f, 0);
    func_003E3BD0(0xF0006, 0x332299DE, 0.332655f, 0.578772f, 0.466855f, 0.004917f, 0);
    func_003E3DF0(0xF0008, D_L01_002EA8E8, 0x8066CCFF, 0.336166f, 0.388667f, 0.460996f, 0.3115f, 1.0f);
    func_003E3A80(0xF0007, (s32)D_L01_002EA868, 0x8066CCFF, 0.328167f, 0.179251f, 1.0f, 1.0f);
    func_003E2560(0xF0007, 1);
    func_003E2560(0xF0008, 1);
    func_L01_00514020(0xF0007, 1);
    func_003E3330(0xF0007, 0.460996f, 0.0f);
    func_003E29B8(0xF0008, 1);
    func_003E3580(0xF0003, 0xF0004, 0xF0005, 0xF0006, 0xF0008, 0xF0007);
    func_003E3D08(0xF000A, 0x332299DE, D_L01_001D8770, D_L01_001D8774, D_L01_001D8778, D_L01_001D877C, D_L01_001D8798, D_L01_001D879C);
    func_003E3D08(0xF000C, 0x332299DE, D_L01_001D8780, D_L01_001D8784, D_L01_001D8788, D_L01_001D878C, D_L01_001D8798, D_L01_001D879C);
    func_003E3BD0(0xF000B, 0x80808080, D_L01_001D8770 + 0.00048825f, D_L01_001D8774 + 0.002404f,
        (D_L01_001D8778 - D_L01_001D8798 * 2.0f) + 0.0009765f, D_L01_001D877C - D_L01_001D879C * 2.0f, 0);
    func_003E3BD0(0xF000D, 0x80808080, D_L01_001D8780 + 0.000244125f, D_L01_001D8784 + 0.001202f,
        (D_L01_001D8788 - D_L01_001D8798 * 2.0f) + 0.00048825f, (D_L01_001D878C - D_L01_001D879C * 2.0f) + 0.002404f, 0);
    func_003E34F0(0xF0003, 0xF000A, 0xF000C, 0xF000B, 0xF000D);
    func_003E31A8(0xF000B, func_003AED40(0));
    func_003E31A8(0xF000D, func_003AED40(1));
    func_L01_00512D70(0xF000B, 0);
    func_003E3250(0xF000B, 1, 10);
    func_L01_00512D70(0xF000D, 0);
    func_003E3250(0xF000D, 1, 10);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            if (slot_offset_00486B58(i, j, &offset)) {
                index = i + j * 5;
                a = index + 0xF000F;
                func_003E3D08(a, 0x332299DE, (D_L01_001D86F8 + offset) + (f32)i * D_L01_001D8700,
                    D_L01_001D86FC + (f32)j * D_L01_001D8704, D_L01_001D8790_004832F8, D_L01_001D8794, D_L01_001D8798, D_L01_001D879C);
                b = index + 0xF001B;
                func_003E3BD0(b, 0x8066CCFF, (D_L01_001D86F8 + offset) + (f32)i * D_L01_001D8700,
                    D_L01_001D86FC + (f32)j * D_L01_001D8704, D_L01_001D8790_004832F8 - D_L01_001D8798 * 6.0f, D_L01_001D8794 - D_L01_001D8798 * 8.0f, 0);
                c = index + 0xF0026;
                func_003E3BD0(c, 0x192299DE, (D_L01_001D86F8 + offset) + (f32)i * D_L01_001D8700,
                    D_L01_001D86FC + (f32)j * D_L01_001D8704, D_L01_001D8790_004832F8 - D_L01_001D8798 * 2.0f, D_L01_001D8794 - D_L01_001D879C * 2.0f, 0);
                func_003E30C8(0xF001A, b);
                func_003E30C8(0xF000E, a);
                func_003E30C8(0xF0025, c);
                func_L01_00512D70(c, 0);
            }
        }
    }
    func_003E3BD0(0xF0019, 0x332299DE, 0.333237f, D_L01_001D86FC + D_L01_001D8704 * 0.5f, 0.487357f, 0.0055f, 0);
    func_003E3D08(0xF0002, 0x332299DE, D_L01_001D86F8, D_L01_001D86FC, D_L01_001D8790_004832F8, D_L01_001D8794, D_L01_001D8798, D_L01_001D879C);
    func_003E34A0(0xF000E, 0xF0019, 0xF0002);
    func_003E3580(0xF0001, 0xF0025, 0xF000E, 0xF001A, 0xF0009, 0xF0003);
    func_003E2DE0(19, 0xF0001);
    func_L01_00483CD8();
    func_L01_00513C08(0xF0008, 1, 1, 1, 0, 0);
    func_L01_00513DC8(0xF0008, 120, 0, 0.0005f);
    func_003E29B8(0xF0007, 1);
    func_L01_00513D28(0xF0008);
}
/* localdecomp:end func_L01_004832F8 */
