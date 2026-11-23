#include "common.h"

/* NTSC-U counterpart of func_L01_004948E8 (src/levels/shared/L01_00494540.c): the last call passes 0xA, not 8 */
/* localdecomp:start func_L01_004910F0 */
typedef struct { s32 f0; s32 f4; s32 f8[4]; } S_004910F0;
typedef struct { u8 pad[0x10]; s32 (*isA)(void *, s32); } VT_004910F0;
typedef struct { u8 pad[8]; VT_004910F0 *vt; u8 padC[0x44]; void *f50; } O_004910F0;
extern f32 D_L01_001D9000_004910F0;
__asm__(".extern D_L01_001D9000_004910F0, 4");
extern f32 D_L01_001D9010_004910F0;
__asm__(".extern D_L01_001D9010_004910F0, 4");
extern f32 D_L01_001D9020_004910F0;
__asm__(".extern D_L01_001D9020_004910F0, 4");
extern f32 D_L01_001D9040_004910F0;
__asm__(".extern D_L01_001D9040_004910F0, 4");
extern f32 D_L01_001D9050_004910F0;
__asm__(".extern D_L01_001D9050_004910F0, 4");
extern f32 D_L01_001D9004_004910F0;
extern f32 D_L01_001D900C_004910F0;
extern f32 D_L01_001D9014_004910F0;
extern f32 D_L01_001D9018_004910F0;
extern f32 D_L01_001D901C_004910F0;
extern f32 D_L01_001D9024_004910F0;
extern f32 D_L01_001D9028_004910F0;
extern f32 D_L01_001D902C_004910F0;
extern f32 D_L01_001D9044_004910F0;
extern f32 D_L01_001D9048_004910F0;
extern f32 D_L01_001D904C_004910F0;
extern f32 D_L01_001D9030_004910F0[] __attribute__((section(".sdata")));
__asm__(".extern D_L01_001D9030_004910F0, 8");
extern s32 D_L01_001D8FC0_004910F0;
__asm__(".extern D_L01_001D8FC0_004910F0, 4");
extern s32 D_L01_001D8FC4_004910F0;
__asm__(".extern D_L01_001D8FC4_004910F0, 4");
extern s32 D_L01_001DC1F0_004910F0;
__asm__(".extern D_L01_001DC1F0_004910F0, 4");
typedef struct { u8 pad[0x4954]; s32 f4954; u8 pad4958[0x6878 - 0x4958]; u8 f6878[1]; } S_160C40_004910F0;
extern S_160C40_004910F0 D_00160C40;
extern S_004910F0 D_L01_001E1660_004910F0;
extern s32 func_0037DF98(s32);
extern void func_L01_00494880_004910F0(s32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32);
extern s32 func_003E3A80(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_L01_00512AB0_004910F0(s32, s32, s32);
extern s32 func_003E30C8(s32, s32);
extern void func_L01_00514D50_004910F0(s32);
extern s32 func_003E3988(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E3330(s32, f32, f32);
extern s32 func_L01_00514020_004910F0(s32, s32);
extern s32 func_003E34A0(s32, s32, s32);
extern s32 func_003E3BD0(s32, s32, s32, f32, f32, f32, f32);
extern s32 func_003E3DF0(s32, s32, s32, f32, f32, f32, f32, f32);
extern s32 func_003E29B8(s32, s32);
extern void func_L01_00513C08_004910F0(s32, s32, s32, s32, s32, s32);
extern void func_L01_00513DC8_004910F0(s32, s32, s32, f32);
extern void func_L01_00490DC0_004910F0(s32, f32 *);
extern s32 func_003E2DE0(s32, s32);
extern void func_L01_00490F50_004910F0(void);
extern s32 func_003B5EC8(s32);
extern s32 func_003B6050(s32);
extern void *func_003AED40(s32);
extern s32 func_003AEF70(void *, s32, s32, s32, s32);
extern void *func_003E16B8();
extern s32 func_003E1898(void *);
extern s32 func_003E0E28();
extern s32 func_003E3250(s32, s32, s32);

void func_L01_004910F0(void)
{
    s32 buf;
    s32 size;
    void *base;
    S_004910F0 *q;
    O_004910F0 *o;

    func_L01_00494880_004910F0(0xD, 8.5f, 0x1A0000, 0x1A0001, 0x1A0002, 0x1A0003, 0x1A0004, 0x1A0005,
                      0x1A0006, 0xD0008, func_0037DF98(0x15E1), 0x1A0007, 0x1A0008);
    func_003E3A80(0x1A0009, func_0037DF98(0xC96), 0x8066CCFF, 0.5f, 0.93f, 1.0f, 1.0f);
    func_L01_00512AB0_004910F0(0x1A0009, 0x40, 1);
    func_003E30C8(0x1A0000, 0x1A0009);
    func_L01_00514D50_004910F0(0x1A000A);
    func_L01_00514D50_004910F0(0x1A000B);
    func_003E3988(0x1A000D, 0x3B, 0x332299DE, D_L01_001D9040_004910F0, D_L01_001D9044_004910F0, D_L01_001D9048_004910F0,
                  D_L01_001D904C_004910F0, 0.0f);
    func_003E30C8(0x1A000B, 0x1A000D);
    func_003E30C8(0x1A000A, 0x1A000B);
    func_003E3A80(0x1A000F, 0, 0x8066CCFF, D_L01_001D9000_004910F0, D_L01_001D9004_004910F0 - D_L01_001D900C_004910F0 * 0.25f,
                  1.0f, 1.0f);
    func_L01_00512AB0_004910F0(0x1A000F, 0x40, 1);
    func_003E3A80(0x1A0010, 0, 0x8066CCFF, D_L01_001D9000_004910F0, D_L01_001D9004_004910F0 + D_L01_001D900C_004910F0 * 0.25f,
                  1.0f, 1.0f);
    func_L01_00512AB0_004910F0(0x1A0010, 0x40, 1);
    func_003E3330(0x1A0010, 0.39f, 0.6f);
    func_L01_00514020_004910F0(0x1A0010, 1);
    func_003E34A0(0x1A000A, 0x1A000F, 0x1A0010);
    func_003E3BD0(0x1A0012, 0x332299DE, 0, D_L01_001D9010_004910F0, D_L01_001D9050_004910F0,
                  D_L01_001D9018_004910F0 + 0.0234375f, 0.006667f);
    func_003E3DF0(0x1A0011, 0, 0x8066CCFF, D_L01_001D9010_004910F0, D_L01_001D9014_004910F0, D_L01_001D9018_004910F0,
                  D_L01_001D901C_004910F0, 1.0f);
    func_003E29B8(0x1A0011, 1);
    func_L01_00513C08_004910F0(0x1A0011, 1, 1, 0, 0, 1);
    func_L01_00513DC8_004910F0(0x1A0011, 0x28, 0, 0.0005f);
    func_L01_00512AB0_004910F0(0x1A0011, 0x40, 1);
    func_003E34A0(0x1A000A, 0x1A0012, 0x1A0011);
    func_003E3BD0(0x1A0014, 0x80808080, 0, D_L01_001D9020_004910F0, D_L01_001D9024_004910F0, D_L01_001D9028_004910F0,
                  D_L01_001D902C_004910F0);
    func_003E30C8(0x1A000A, 0x1A0014);
    func_L01_00514D50_004910F0(0x1A0013);
    func_L01_00490DC0_004910F0(0x1A0013, D_L01_001D9030_004910F0);
    func_003E30C8(0x1A000A, 0x1A0013);
    func_003E2DE0(0xE, 0x1A000A);
    func_L01_00490F50_004910F0();
    buf = func_003B5EC8(1);
    size = func_003B6050(buf);
    D_L01_001D8FC0_004910F0 = buf;
    D_L01_001D8FC4_004910F0 = (buf + size / 2 + 0xF) & 0xFFFFFFF0;
    func_003AEF70(func_003AED40(0), D_L01_001D8FC4_004910F0, D_L01_001D8FC0_004910F0,
                  D_00160C40.f4954, (s32)D_00160C40.f6878);
    q = &D_L01_001E1660_004910F0;
    if (q->f4 != 0) {
        base = q;
    } else {
        base = func_003E16B8(q);
    }
    o = (O_004910F0 *)func_003E0E28(func_003E1898(base), 0x1A0014);
    if (o == 0 || o->vt->isA(o, D_L01_001DC1F0_004910F0) == 0) {
        o = 0;
    }
    o->f50 = func_003AED40(0);
    func_003E3250(0x1A0014, 1, 0xA);
}
/* localdecomp:end func_L01_004910F0 */
