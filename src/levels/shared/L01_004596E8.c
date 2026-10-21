#include "common.h"

/* localdecomp:start func_L01_004596E8 */
extern u8 *D_L01_001E0020;
extern u8 *D_L01_001E0024;
extern void func_L01_0035C6B0(u8 *);
extern void func_L01_00385EA0(u8 *);
extern void func_L01_003C38D0(u8 *);
extern void func_L01_0032E2B0(u8 *);
extern void func_L01_00330390(u8 *);
extern void func_L01_00379368(u8 *);
extern void func_L01_003D42D0(u8 *);
extern void func_L01_0039FEB0(u8 *);
extern void func_L01_003DABC8(u8 *);
extern void func_L01_00309B70(u8 *);
extern void func_L01_00371C98(u8 *);
extern void func_L01_003E1550(u8 *);
extern void func_L01_0038FCA8(u8 *);
extern void func_L01_00362600(u8 *);
extern void func_L01_0035FEB8(u8 *);
extern void func_L01_0038C9A0(u8 *);
extern void func_L01_003837A8(u8 *);
extern void func_L01_003968E8(u8 *);
extern void func_L01_00399A40(u8 *);
extern void func_L01_00344A40(u8 *);
extern void func_L01_0030C860(u8 *);
extern void func_L01_0031DB60(u8 *);
extern void func_L01_0031F258(u8 *);
extern void func_003C2880(u8 *);
extern void func_L01_00303658(u8 *);

void func_L01_004596E8(s32 (*filter)(u8 *), void (*deflt)(u8 *))
{
    u8 *m;
    s32 (*f)(u8 *) = filter;
    void (*d)(u8 *) = deflt;

    for (m = D_L01_001E0020; m < D_L01_001E0024; m += 256) {
        if (m == 0) continue;
        if (m[32] == 254) continue;
        if (m[32] == 253) continue;
        if (filter != 0 && f(m) == 0) continue;
        switch (*(s16 *)(m + 170)) {
        case 6225:
            func_L01_0035C6B0(m);
            break;
        case 6273:
            func_L01_00385EA0(m);
            break;
        case 6874:
            func_L01_003C38D0(m);
            break;
        case 4966:
            func_L01_0032E2B0(m);
            break;
        case 4967:
            func_L01_00330390(m);
            break;
        case 6253:
            func_L01_00379368(m);
            break;
        case 7107:
            func_L01_003D42D0(m);
            break;
        case 6299:
            func_L01_0039FEB0(m);
            break;
        case 7486:
            func_L01_003DABC8(m);
            break;
        case 2473:
            func_L01_00309B70(m);
            break;
        case 6247:
            func_L01_00371C98(m);
            break;
        case 7685:
            func_L01_003E1550(m);
            break;
        case 6282:
            func_L01_0038FCA8(m);
            break;
        case 6234:
            func_L01_00362600(m);
            break;
        case 6232:
            func_L01_0035FEB8(m);
            break;
        case 6280:
            func_L01_0038C9A0(m);
            break;
        case 6258:
            func_L01_003837A8(m);
            break;
        case 6291:
            func_L01_003968E8(m);
            break;
        case 6292:
            func_L01_00399A40(m);
            break;
        case 2690:
            func_L01_00344A40(m);
            break;
        case 2715:
            func_L01_0030C860(m);
            break;
        case 3684:
            func_L01_0031DB60(m);
            break;
        case 3790:
        case 6295:
            func_L01_0031F258(m);
            break;
        case 3291:
            func_003C2880(m);
            break;
        case 806:
            if (*(u8 **)(m + 184) == m) func_L01_00303658(m);
            break;
        default:
            if (deflt != 0) d(m);
            break;
        }
    }
}
/* localdecomp:end func_L01_004596E8 */

LINKER_REMNANT("asm/levels", func_L01_00459AF0);

/* localdecomp:start func_L01_00459AF8 */
typedef struct {
    u8 f0;
    u8 f1;
    u8 pad2[130];
    u16 f84;
    u8 pad86[4];
    u16 f8A;
    u8 pad8C[100];
} __attribute__((aligned(16))) Ent_00456808;
extern Ent_00456808 D_L01_002C5600[];
extern u8 D_00142CA0[];
extern u8 D_001425C0[];
extern s32 D_001427F0[];
void func_L01_00459AF8(void) {
    Ent_00456808 e;
    s32 i;
    for (i = 0; i < 156; i++) {
        e = D_L01_002C5600[i];
        if (e.f0 != 0 && e.f1 == 0) {
            if (D_00142CA0[i] != 0) {
                e = D_L01_002C5600[D_001425C0[i]];
                if (e.f84 != 0) {
                    D_001427F0[i] = e.f8A;
                }
            }
        }
    }
}
/* localdecomp:end func_L01_00459AF8 */

INCLUDE_ASM("asm/levels", func_L01_00459BE8);

/* localdecomp:start func_L01_00459C50 */
typedef struct {
    u8 pad[186];
    u8 b186;
} St_00456960;

extern u8 D_001D54B0[1];
extern s32 D_L01_001D6790;
extern St_00456960 D_001426E0;
extern void func_003A5348(s32, s32, s32);
extern void func_L01_00451F60(s32, s32, s32);
extern void func_0039EF28(void);

void func_L01_00459C50(s32 idx) {
    s32 i;

    if (D_001D54B0[idx] == 0) {
        D_001D54B0[idx] = 1;
        func_003A5348(1, 0, 0);
        func_L01_00451F60(1734, -1, 0);
        D_L01_001D6790 = 1;
        if (D_001426E0.b186 == 0) {
            for (i = 0; i < 30; i++) {
                if (D_001D54B0[i] == 0) {
                    return;
                }
            }
            func_L01_00451F60(4785, -1, 0);
            D_001426E0.b186 = 1;
            func_0039EF28();
        }
    }
}
/* localdecomp:end func_L01_00459C50 */

/* localdecomp:start func_L01_00459D18 */
extern Ent_00456808 D_L01_002C5600[];
typedef int s128 __attribute__((mode(TI)));

typedef struct {
    u8 b0;
    u8 b1;
    u8 pad2[14];
    s128 rest[14];
} E_00456A28;

extern u8 D_00142CA0[];
extern u8 D_001425C0[];

s32 func_L01_00459D18(void) {
    E_00456A28 e;
    s32 i;

    for (i = 0; i < 156; i++) {
        e = ((E_00456A28 *)&D_L01_002C5600)[i];
        if (e.b0 != 0 && e.b1 == 0 && D_00142CA0[i] != 0) {
            e = ((E_00456A28 *)&D_L01_002C5600)[D_001425C0[i]];
            if (i == 151) {
                if (e.b1 < 4) {
                    return 0;
                }
            } else if (e.b1 < 7) {
                return 0;
            }
        }
    }
    return 1;
}
/* localdecomp:end func_L01_00459D18 */

LINKER_REMNANT("asm/levels", func_L01_00459E10);

INCLUDE_ASM("asm/levels", func_L01_00459EF0);

INCLUDE_ASM("asm/levels", func_L01_00459F60);

INCLUDE_ASM("asm/levels", func_L01_0045A520);

INCLUDE_ASM("asm/levels", func_L01_0045A530);

INCLUDE_ASM("asm/levels", func_L01_0045A550);

/* localdecomp:start func_L01_0045A570 */
extern s32 D_L01_001D7DBC;

void func_L01_0045A570(s32 a) {
    D_L01_001D7DBC = a;
}
/* localdecomp:end func_L01_0045A570 */
