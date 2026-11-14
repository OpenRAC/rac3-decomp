/* NTSC-U draft (2026-11-14, Codex worker): C of func_L01_004832F8, the NTSC-U twin of func_L01_00486B58, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L01_004838A0.c's current line.
 * Worker's note: 563 diff; best log func_L01_004832F8.01.log; complete initializer/5x2 grid draft. Allowed GNU assembler emits lit4 loads (e.g. 0.332655f) where retail has inline lui/ori/mtc1; no flags_alt. Other call scheduling/array-anchor differences remain; no alternate flags tried.
 */
#include "common.h"

/* localdecomp:start func_L01_004832F8 */
extern u8 *D_001D8708_sda, *D_001D870C_sda, *D_001D8710_sda, *D_001D8714_sda;
extern f32 D_001D86F8_sda, D_001D86FC_sda, D_001D8700_sda, D_001D8704_sda;
extern f32 D_001D8770_sda, D_001D8774_sda, D_001D8778_sda, D_001D877C_sda;
extern f32 D_001D8780_sda, D_001D8784_sda, D_001D8788_sda, D_001D878C_sda;
extern f32 D_001D8790_sda, D_001D8794_sda, D_001D8798_sda, D_001D879C_sda;
__asm__(".extern D_001D8708_sda, 4");
__asm__(".extern D_001D870C_sda, 4");
__asm__(".extern D_001D8710_sda, 4");
__asm__(".extern D_001D8714_sda, 4");
__asm__(".extern D_001D86F8_sda, 4");
__asm__(".extern D_001D86FC_sda, 4");
__asm__(".extern D_001D8700_sda, 4");
__asm__(".extern D_001D8704_sda, 4");
__asm__(".extern D_001D8770_sda, 4");
__asm__(".extern D_001D8774_sda, 4");
__asm__(".extern D_001D8778_sda, 4");
__asm__(".extern D_001D877C_sda, 4");
__asm__(".extern D_001D8780_sda, 4");
__asm__(".extern D_001D8784_sda, 4");
__asm__(".extern D_001D8788_sda, 4");
__asm__(".extern D_001D878C_sda, 4");
__asm__(".extern D_001D8790_sda, 4");
__asm__(".extern D_001D8794_sda, 4");
__asm__(".extern D_001D8798_sda, 4");
__asm__(".extern D_001D879C_sda, 4");
extern u8 D_00160C40[];
extern u8 D_L01_002EA868[], D_L01_002EA8E8[];
extern u8 *func_003B5EC8(s32);
extern void func_L01_004831D8(s32, f32 *, f32 *);
extern s32 *func_003AED40(s32);
extern void func_003AEF70(void *, void *, void *, s32, void *);
extern s32 func_0037DF98(s32);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_003E3A80(s32, void *, u32, f32, f32, f32, f32);
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
extern void func_L01_00512D70(s32, s32);
extern s32 func_003E3250(s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern s32 func_003E2DE0(s32, s32);
extern void func_L01_00483CD8(void);
extern void func_L01_00513C08(s32, s32, s32, s32, s32, s32);
extern void func_L01_00513DC8(s32, s32, s32, f32);
extern void func_L01_00513D28(s32);

void func_L01_004832F8(void) {
    f32 scale = 1.0f, zero = 0.0f;
    s32 i, j, index;
    f32 offset;
    s32 a, b, c;
    D_001D8708_sda = func_003B5EC8(0);
    D_001D8710_sda = func_003B5EC8(0);
    D_001D870C_sda = D_001D8708_sda + 0x9600;
    D_001D8714_sda = D_001D8710_sda + 0x9600;
    func_L01_004831D8(0x103, &scale, &zero);
    func_003AEF70(func_003AED40(0), D_001D8708_sda, D_001D870C_sda, *(s32 *)(D_00160C40 + 0x4954), D_00160C40 + 0x6478);
    func_003AEF70(func_003AED40(1), D_001D8710_sda, D_001D8714_sda, *(s32 *)(D_00160C40 + 0x4954), D_00160C40 + 0x5800);
    D_L01_002EA868[0] = 0;
    D_L01_002EA8E8[0] = 0;
    func_003B3DB8(0x10, 0xD000B, 0xD0002, 0xD0003, 0xD0004, 0xD0000, 0xD0001, 0xD0005, 0xD0008,
        func_0037DF98(0x103), 0xD0006, 0x124, 0xD0007, 0xCD5, zero);
    func_003E3A80(0xD0009, (void *)func_0037DF98(0x1B80), 0x8066CCFF, 0.03500000014901161f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD0009, 1);
    func_003E3A80(0xD000A, (void *)func_0037DF98(0x1B81), 0x8066CCFF, 0.9700000286102295f, 0.5f, 1.0f, 1.0f);
    func_003E29B8(0xD000A, 1);
    func_003E34A0(0xD000B, 0xD0009, 0xD000A);
    func_L01_00513548(0xD0005, scale, scale);
    func_003AFAA8(0xF0001);
    func_003AFAA8(0xF000E);
    func_003AFAA8(0xF001A);
    func_003AFAA8(0xF0009);
    func_003AFAA8(0xF0025);
    func_003AFAA8(0xF0003);
    func_003E3D08(0xF0004, 0x332299DE, 0.33265501260757446f, 0.3721410036087036f, 0.48969000577926636f, 0.4684230089187622f, D_001D8798_sda, D_001D879C_sda);
    func_003E3BD0(0xF0005, 0x332299DE, 0.33265501260757446f, 0.21009600162506104f, 0.466854989528656f, 0.004916999954730272f, 0);
    func_003E3BD0(0xF0006, 0x332299DE, 0.33265501260757446f, 0.5787720084190369f, 0.466854989528656f, 0.004916999954730272f, 0);
    func_003E3DF0(0xF0008, D_L01_002EA8E8, 0x8066CCFF, 0.33616599440574646f, 0.3886669874191284f, 0.46099600195884705f, 0.31150001287460327f, 1.0f);
    func_003E3A80(0xF0007, D_L01_002EA868, 0x8066CCFF, 0.32816699147224426f, 0.17925100028514862f, 1.0f, 1.0f);
    func_003E2560(0xF0007, 1);
    func_003E2560(0xF0008, 1);
    func_L01_00514020(0xF0007, 1);
    func_003E3330(0xF0007, 0.46099600195884705f, 0.0f);
    func_003E29B8(0xF0008, 1);
    func_003E3580(0xF0003, 0xF0004, 0xF0005, 0xF0006, 0xF0008, 0xF0007);
    func_003E3D08(0xF000A, 0x332299DE, D_001D8770_sda, D_001D8774_sda, D_001D8778_sda, D_001D877C_sda, D_001D8798_sda, D_001D879C_sda);
    func_003E3D08(0xF000C, 0x332299DE, D_001D8780_sda, D_001D8784_sda, D_001D8788_sda, D_001D878C_sda, D_001D8798_sda, D_001D879C_sda);
    func_003E3BD0(0xF000B, 0x80808080, D_001D8770_sda + 0.00048824999248608947f, D_001D8774_sda + 0.002403999911621213f,
        (D_001D8778_sda - D_001D8798_sda * 2.0f) + 0.0009764999849721789f, D_001D877C_sda - D_001D879C_sda * 2.0f, 0);
    func_003E3BD0(0xF000D, 0x80808080, D_001D8780_sda + 0.00024412499624304473f, D_001D8784_sda + 0.0012019999558106065f,
        (D_001D8788_sda - D_001D8798_sda * 2.0f) + 0.00048824999248608947f, (D_001D878C_sda - D_001D879C_sda * 2.0f) + 0.002403999911621213f, 0);
    func_003E34F0(0xF0003, 0xF000A, 0xF000C, 0xF000B, 0xF000D);
    func_003E31A8(0xF000B, func_003AED40(0));
    func_003E31A8(0xF000D, func_003AED40(1));
    func_L01_00512D70(0xF000B, 0);
    func_003E3250(0xF000B, 1, 10);
    func_L01_00512D70(0xF000D, 0);
    func_003E3250(0xF000D, 1, 10);
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 2; j++) {
            offset = 0.0f;
            if (j > 0) {
                if (i >= 4) continue;
                offset = D_001D8700_sda * 0.5f;
            }
            index = i + j * 5;
            a = index + 0xF000F;
            b = index + 0xF001B;
            c = index + 0xF0026;
            func_003E3D08(a, 0x332299DE, (D_001D86F8_sda + offset) + (f32)i * D_001D8700_sda,
                D_001D86FC_sda + (f32)j * D_001D8704_sda, D_001D8790_sda, D_001D8794_sda, D_001D8798_sda, D_001D879C_sda);
            func_003E3BD0(b, 0x8066CCFF, (D_001D86F8_sda + offset) + (f32)i * D_001D8700_sda,
                D_001D86FC_sda + (f32)j * D_001D8704_sda, D_001D8790_sda - D_001D8798_sda * 6.0f, D_001D8794_sda - D_001D8798_sda * 8.0f, 0);
            func_003E3BD0(c, 0x192299DE, (D_001D86F8_sda + offset) + (f32)i * D_001D8700_sda,
                D_001D86FC_sda + (f32)j * D_001D8704_sda, D_001D8790_sda - D_001D8798_sda * 2.0f, D_001D8794_sda - D_001D879C_sda * 2.0f, 0);
            func_003E30C8(0xF001A, b);
            func_003E30C8(0xF000E, a);
            func_003E30C8(0xF0025, c);
            func_L01_00512D70(c, 0);
        }
    }
    func_003E3BD0(0xF0019, 0x332299DE, 0.3332369923591614f, D_001D86FC_sda + D_001D8704_sda * 0.5f, 0.4873569905757904f, 0.005499999970197678f, 0);
    func_003E3D08(0xF0002, 0x332299DE, D_001D86F8_sda, D_001D86FC_sda, D_001D8790_sda, D_001D8794_sda, D_001D8798_sda, D_001D879C_sda);
    func_003E34A0(0xF000E, 0xF0019, 0xF0002);
    func_003E3580(0xF0001, 0xF0025, 0xF000E, 0xF001A, 0xF0009, 0xF0003);
    func_003E2DE0(19, 0xF0001);
    func_L01_00483CD8();
    func_L01_00513C08(0xF0008, 1, 1, 1, 0, 0);
    func_L01_00513DC8(0xF0008, 120, 0, 0.0005000000237487257f);
    func_003E29B8(0xF0007, 1);
    func_L01_00513D28(0xF0008);
}
/* localdecomp:end func_L01_004832F8 */
