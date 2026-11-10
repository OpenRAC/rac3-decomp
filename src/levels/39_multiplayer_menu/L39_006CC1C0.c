#include "common.h"

typedef struct S_006CC458 {
    u8 pad_000[0x164];
    s32 f164;
    s32 f168;
    s32 f16C;
    s32 f170;
    s32 f174;
    s32 f178;
    s32 f17C;
    s32 f180;
} S_006CC458;
typedef struct E_0047F0C0 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} E_0047F0C0;

INCLUDE_ASM("asm/levels", func_L39_006CC1C0);

/* localdecomp:start func_L39_006CC238 */
/* from rac2-decomp's func_002B0A18, renamed */
void func_L39_006CC238(int first, int second)
{
    extern int func_L01_004DFE80(int);
    extern void func_L39_006CC268(int, int);
    func_L39_006CC268(func_L01_004DFE80(first), second);
}
/* localdecomp:end func_L39_006CC238 */

/* localdecomp:start func_L39_006CC268 */
extern void func_L39_006CC1C0(s32 arg0, s32 *arg1, s32 *arg2);

/* from rac4-decomp's func_L00_0070C490, renamed */
s32 func_L39_006CC268(s32 arg0, s32 arg1) {
    s32 f[2];
    func_L39_006CC1C0(arg0, &f[0], &f[1]);
    return (arg1 & f[0]) >> f[1];
}
/* localdecomp:end func_L39_006CC268 */

/* localdecomp:start func_L39_006CC2A8 */
extern s32 func_L01_004DFE80(s32);
extern s32 func_L39_006CC2E8(s32, s32, s32);

s32 func_L39_006CC2A8(s32 a0, s32 a1, s32 a2)
{
    s32 r = func_L01_004DFE80(a0);
    return func_L39_006CC2E8(r, a1, a2);
}
/* localdecomp:end func_L39_006CC2A8 */

/* localdecomp:start func_L39_006CC2E8 */
s32 func_L39_006CC2E8(s32 a0, s32 a1, s32 a2)
{
    s32 f[2];
    s32 *p = (s32 *)a1;
    func_L39_006CC1C0(a0, &f[0], &f[1]);
    *p = (*p & ~f[0]) | (a2 << f[1]);
}
/* localdecomp:end func_L39_006CC2E8 */

/* localdecomp:start func_L39_006CC340 */
/* from rac4-decomp's func_L00_0070C528, renamed */
void func_L39_006CC340(s32 *a0, s32 a1, s32 a2) {
    a0 += a1;
    *a0 = a2;
}
/* localdecomp:end func_L39_006CC340 */

/* localdecomp:start func_L39_006CC350 */
/* from rac4-decomp's func_L00_0070C538, renamed */
s32 func_L39_006CC350(s32 *a0, s32 a1) {
    a0 += a1;
    return *a0;
}
/* localdecomp:end func_L39_006CC350 */

/* localdecomp:start func_L39_006CC360 */
extern s32 func_L39_006CC2E8(s32, s32, s32);
extern E_0047F0C0 D_L39_0047F0C0[];

void func_L39_006CC360(s32 *arg0, S_006CC458 *arg1) {
    s32 i;
    s32 *p;
    s32 k;

    for (i = 0; i < 0x1D; i++) {
        k = D_L39_0047F0C0[i].f0;
        p = 0;
        switch (D_L39_0047F0C0[i].f4) {
        case 1: break;
        case 2: p = &arg1->f168; break;
        case 3: p = &arg1->f164; break;
        case 4: p = &arg1->f16C; break;
        case 5: p = &arg1->f170; break;
        case 6: p = &arg1->f174; break;
        case 7: p = &arg1->f178; break;
        case 8: p = &arg1->f17C; break;
        case 9: p = &arg1->f180; break;
        }
        if (p != 0) {
            func_L39_006CC2E8(i, (s32)p, *(s32 *)((u8 *)arg0 + (k << 2)));
        }
    }
}
/* localdecomp:end func_L39_006CC360 */

/* localdecomp:start func_L39_006CC458 */
extern E_0047F0C0 D_L39_0047F0C0[];

void func_L39_006CC458(int first, S_006CC458 *second)
{
    s32 v = 0;

    switch (D_L39_0047F0C0[first].f4) {
    case 1: break;
    case 2: v = second->f168; break;
    case 3: v = second->f164; break;
    case 4: v = second->f16C; break;
    case 5: v = second->f170; break;
    case 6: v = second->f174; break;
    case 7: v = second->f178; break;
    case 8: v = second->f17C; break;
    case 9: v = second->f180; break;
    }
    func_L39_006CC238(first, v);
}
/* localdecomp:end func_L39_006CC458 */

INCLUDE_ASM("asm/levels", func_L39_006CC4F8);

INCLUDE_ASM("asm/levels", func_L39_006CC648);

INCLUDE_ASM("asm/levels", func_L39_006CC798);
