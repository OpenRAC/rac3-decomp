#include "common.h"

/* localdecomp:start func_L07_004245E8 */
typedef struct { u8 p0[0x20]; void *f20; u8 p24[0xC]; s32 f30; } S_004245E8;
typedef struct { u8 p0[0x30]; u32 f30; s32 f34; } S2_004245E8;
typedef struct { u8 p0[0x40]; s32 f40; } M_004245E8;
typedef struct { u8 p0[0xAA]; s16 fAA; u8 pAC[0x100 - 0xAC]; } Moby_004245E8;
extern f32 D_L07_001D6B44;
__asm__(".extern D_L07_001D6B44, 4");
extern u8 D_L07_001D6AB0;
__asm__(".extern D_L07_001D6AB0, 1");
extern u8 D_L07_001D6AA5;
__asm__(".extern D_L07_001D6AA5, 1");
extern u8 D_L07_001D6B70;
__asm__(".extern D_L07_001D6B70, 1");
extern u8 D_L07_001D6B88;
__asm__(".extern D_L07_001D6B88, 1");
extern s32 D_L07_001D6BA0;
__asm__(".extern D_L07_001D6BA0, 4");
extern s32 D_L07_001D6B74;
__asm__(".extern D_L07_001D6B74, 16");
extern S_004245E8 D_L07_002E85A0;
extern S2_004245E8 D_L07_001E6200;
extern u8 D_L07_002E85F0[];
extern u8 D_L07_002E8660[];
extern u8 D_L07_002E86C0[];
extern u8 D_L07_002E8720[];
extern M_004245E8 D_L07_002E88E0;
extern Moby_004245E8 *D_L07_001DF41C;
extern Moby_004245E8 *D_L07_001DF420;
extern s32 D_001D545C;
__asm__(".extern D_001D545C, 16");
extern void func_L01_00423068(void *, s32, s32, s32, s32, s32, s32);
extern void func_L03_004109D8(void *, void *, void *, s32);

void func_L07_004245E8(void) {
    M_004245E8 *a;
    void *b;
    void *d;
    Moby_004245E8 *m;
    s32 n;

    D_L07_001D6B44 = 1.0f;
    D_L07_002E85A0.f20 = &D_L07_001D6AB0;
    D_L07_002E85A0.f30 = 1;
    a = 0;
    b = 0;
    d = 0;
    D_L07_001D6AA5 = 0;
    if (D_001D545C == 7) {
        switch (D_L07_001E6200.f30) {
        case 0:
            d = D_L07_002E85F0;
            b = &D_L07_001D6B88;
            if ((D_L07_001D6B74 * 5 + 2) / 6 >= D_L07_001E6200.f34) b = &D_L07_001D6B70;
            break;
        case 1:
            a = (M_004245E8 *)D_L07_002E8660;
            break;
        case 2:
            a = (M_004245E8 *)D_L07_002E86C0;
            break;
        case 3:
            if (D_L07_001E6200.f34 >= (D_L07_001D6BA0 * 5 + 2) / 6) {
                b = &D_L07_001D6BA0;
                d = D_L07_002E85F0;
            }
            break;
        case 4:
            D_L07_002E85A0.f20 = D_L07_002E8720;
            a = &D_L07_002E88E0;
            n = 0;
            for (m = D_L07_001DF41C; m < D_L07_001DF420; m++) {
                if (m != 0 && m->fAA == a->f40) {
                    func_L01_00423068(a, 0, 0, 0, (s32)m, 7, n);
                    n++;
                }
            }
            a = 0;
            break;
        }
    }
    if (a != 0) {
        func_L01_00423068(a, (s32)b, 0, 0, 0, 1, 0);
    } else if (d != 0) {
        func_L03_004109D8(d, b, 0, 0);
    }
}
/* localdecomp:end func_L07_004245E8 */
