#include "common.h"

/* NTSC-U counterpart of func_L01_0049B5A8 (src/levels/shared/L01_0049B5A8.c): 8 -> 10 */
extern void *func_003AED40(s32);
extern s32 func_0037DF98(s32);
extern s32 func_L01_00512D70(s32, s32);
extern s32 func_L01_005131A0(s32, s32);
extern void func_L01_00497D48();

/* localdecomp:start func_L01_00497D48 */
typedef struct { s32 f0; s32 p4; s32 f8; s32 pC; s32 p10; u8 flag; u8 pad[3]; } E_0049B5A8;
extern E_0049B5A8 D_L01_002EBF28[];
extern u8 D_L01_002EBF88[];
extern s32 D_L01_001D943C;
__asm__(".extern D_L01_001D943C, 4");
extern s32 D_L01_001D9438;
__asm__(".extern D_L01_001D9438, 4");
extern s32 D_L01_001D9434;
__asm__(".extern D_L01_001D9434, 4");
extern void func_L01_00498868(void);
extern void func_00389920(s32);
extern void func_L01_004962E0(s32, f32 *, f32 *);
extern void func_003B3DB8(s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, f32);
extern void func_L01_00512828(s32, f32);
extern void func_L01_00498098(void *);
extern void func_003E2DE0(s32, s32);
extern s32 func_003E29B8(s32, s32);
extern void func_003E31A8(s32, void *);
extern void func_003E3250(s32, s32, s32);
extern void func_L01_00498378(void);
extern void func_L01_00498AD8(void);
extern void func_L01_00498978(void);

void func_L01_00497D48(void) {
    f32 a;
    f32 b;
    s32 i;
    s32 n;
    E_0049B5A8 *p;

    i = 0;
    b = 0.0f;
    a = 1.2f;
    func_L01_00498868();
    func_00389920(0);
    func_L01_004962E0(0x1C2, &a, &b);
    func_003B3DB8(0x10, 0xD000B, 0xD0000, 0xD0001, 0xD0002, 0xD0003, 0xD0004, 0xD0005, 0xD0008, func_0037DF98(0x1C2), 0xD0006, 0x124, 0xD0007, 0xCD5, b);
    func_L01_00512828(0xD0005, a);
    func_L01_00498098(D_L01_002EBF88);
    func_003E2DE0(0x11, 0x4E0000);
    func_003E29B8(0x4E0005, 1);
    func_003E29B8(0x4E0006, 1);
    func_003E31A8(0x4E0009, func_003AED40(0));
    func_L01_005131A0(0x4E0009, 0);
    func_L01_00512D70(0x4E0009, 0);
    func_003E3250(0x4E0009, 1, 10);
    func_L01_00498378();
    func_L01_00498AD8();
    D_L01_001D943C = -1;
    if (D_L01_002EBF28[0].f0 != 0) {
        n = -1;
        do {
            if (D_L01_002EBF28[i].flag) n = i;
            i++;
        } while (D_L01_002EBF28[i].f0 != 0 && n < 0);
        D_L01_001D943C = n;
    }
    if (D_L01_001D943C < 0) {
        if (D_L01_001D9438 != 0) D_L01_001D943C = 0;
    }
    if (D_L01_001D943C >= 0) {
        func_L01_005131A0(0x4E0009, D_L01_002EBF28[D_L01_001D943C].f8 + 1);
        func_L01_00512D70(0x4E0009, 1);
    }
    func_L01_00512D70(0x4E0009, 0);
    D_L01_001D9434 = -1;
    func_L01_00498978();
}
/* localdecomp:end func_L01_00497D48 */
