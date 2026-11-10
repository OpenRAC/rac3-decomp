#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004DF158);

INCLUDE_ASM("asm/levels", func_L39_004DF260);

INCLUDE_ASM("asm/levels", func_L39_004DF408);

INCLUDE_ASM("asm/levels", func_L39_004DF410);

INCLUDE_ASM("asm/levels", func_L39_004DF668);

INCLUDE_ASM("asm/levels", func_L39_004DF678);

INCLUDE_ASM("asm/levels", func_L39_004DF688);

INCLUDE_ASM("asm/levels", func_L39_004DF698);

INCLUDE_ASM("asm/levels", func_L39_004DF6A8);

INCLUDE_ASM("asm/levels", func_L39_004DF6B8);

INCLUDE_ASM("asm/levels", func_L39_004DF820);

INCLUDE_ASM("asm/levels", func_L39_004DFB38);

INCLUDE_ASM("asm/levels", func_L39_004DFB88);

INCLUDE_ASM("asm/levels", func_L39_004DFD50);

INCLUDE_ASM("asm/levels", func_L39_004E00C8);

INCLUDE_ASM("asm/levels", func_L39_004E0280);

INCLUDE_ASM("asm/levels", func_L39_004E03B8);

INCLUDE_ASM("asm/levels", func_L39_004E0490);

INCLUDE_ASM("asm/levels", func_L39_004E0698);

INCLUDE_ASM("asm/levels", func_L39_004E09E0);

INCLUDE_ASM("asm/levels", func_L39_004E0A58);

INCLUDE_ASM("asm/levels", func_L39_004E0B10);

INCLUDE_ASM("asm/levels", func_L39_004E0BC8);

INCLUDE_ASM("asm/levels", func_L39_004E0C88);

INCLUDE_ASM("asm/levels", func_L39_004E0D60);

INCLUDE_ASM("asm/levels", func_L39_004E0E98);

/* localdecomp:start func_L39_004E0ED0 */
s32 func_L39_004DD858(s32);
s32 func_L39_004EA5A8(s32);

s32 func_L39_004E0ED0(void *arg0) {
    s32 temp_v1;

    if (arg0 != 0) {
        temp_v1 = (*(s32 *)arg0);
        if (temp_v1 == 6) {
            return func_L39_004EA5A8((*(s32 *)((u8 *)arg0 + 0xC)));
        }
        if (temp_v1 == 0x74) {
            return func_L39_004DD858((*(s32 *)((u8 *)arg0 + 0xC)));
        }
        return 0;
    }
    return 0;
}
/* localdecomp:end func_L39_004E0ED0 */

INCLUDE_ASM("asm/levels", func_L39_004E0F28);

INCLUDE_ASM("asm/levels", func_L39_004E1060);

INCLUDE_ASM("asm/levels", func_L39_004E10B0);

INCLUDE_ASM("asm/levels", func_L39_004E1138);

/* localdecomp:start func_L39_004E1160 */
s32 func_L39_004E1160(s32 arg0) {
    switch (arg0) {
    case 6:
    case 0x13:
        return 6;
    case 0x42:
    case 0x43:
    case 0x46:
    case 0x71:
    case 0x74:
        return 0x74;
    case 0x1C:
        return 0x1C;
    default:
        return 0;
    }
}
/* localdecomp:end func_L39_004E1160 */

INCLUDE_ASM("asm/levels", func_L39_004E1200);

INCLUDE_ASM("asm/levels", func_L39_004E1268);

INCLUDE_ASM("asm/levels", func_L39_004E1320);

INCLUDE_ASM("asm/levels", func_L39_004E1478);

/* localdecomp:start func_L39_004E15D8 */
extern char D_L39_004F4540[];
extern char D_L39_00477290[];
extern s32 func_L39_004E1610(char *, char *, s32, s32, s32);

/* from rac4-decomp's func_L00_0051D3D8, renamed */
void func_L39_004E15D8(s32 arg0, s32 arg1, s32 arg2) {
    func_L39_004E1610(D_L39_004F4540, D_L39_00477290, arg0, arg1, arg2);
}
/* localdecomp:end func_L39_004E15D8 */

INCLUDE_ASM("asm/levels", func_L39_004E1610);

INCLUDE_ASM("asm/levels", func_L39_004E18B8);

INCLUDE_ASM("asm/levels", func_L39_004E1A78);

INCLUDE_ASM("asm/levels", func_L39_004E1CB8);

INCLUDE_ASM("asm/levels", func_L39_004E1DC8);

INCLUDE_ASM("asm/levels", func_L39_004E2398);

INCLUDE_ASM("asm/levels", func_L39_004E23D8);

INCLUDE_ASM("asm/levels", func_L39_004E2440);

INCLUDE_ASM("asm/levels", func_L39_004E2450);

INCLUDE_ASM("asm/levels", func_L39_004E2D20);

INCLUDE_ASM("asm/levels", func_L39_004E2D68);

/* localdecomp:start func_L39_004E2DD0 */
typedef struct Type1 Type1;
typedef struct Type2 {
    s32 (*f0)(Type1 *arg0, s32 arg1, s32 arg2, s32 arg3);
} Type2;
struct Type1 {
    Type2 *f0;
};

/* from rac4-decomp's func_L00_0051EBD0, renamed */
s32 func_L39_004E2DD0(Type1 *arg0, Type2 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    arg0->f0 = arg1;
    return arg1->f0(arg0, arg2, arg3, arg4);
}
/* localdecomp:end func_L39_004E2DD0 */

INCLUDE_ASM("asm/levels", func_L39_004E2E00);

INCLUDE_ASM("asm/levels", func_L39_004E2E50);

INCLUDE_ASM("asm/levels", func_L39_004E2EA0);

INCLUDE_ASM("asm/levels", func_L39_004E2EF0);

INCLUDE_ASM("asm/levels", func_L39_004E2F40);

INCLUDE_ASM("asm/levels", func_L39_004E2F70);

INCLUDE_ASM("asm/levels", func_L39_004E2FC0);

/* localdecomp:start func_L39_004E3000 */
void func_L39_004E3000(void *arg0, s32 arg1, s32 arg2) {
    ((void (*)(void *, s32, s32, s32))(*(s32 *)(*(s32 *)arg0 + 0x18)))(arg0, 0x101, arg2, arg1);
}
/* localdecomp:end func_L39_004E3000 */

INCLUDE_ASM("asm/levels", func_L39_004E3028);

INCLUDE_ASM("asm/levels", func_L39_004E3050);

INCLUDE_ASM("asm/levels", func_L39_004E3060);

INCLUDE_ASM("asm/levels", func_L39_004E3748);

INCLUDE_ASM("asm/levels", func_L39_004E38F0);

INCLUDE_ASM("asm/levels", func_L39_004E3B68);

INCLUDE_ASM("asm/levels", func_L39_004E3CB8);

INCLUDE_ASM("asm/levels", func_L39_004E3EB8);

INCLUDE_ASM("asm/levels", func_L39_004E3FC0);

INCLUDE_ASM("asm/levels", func_L39_004E42D8);

INCLUDE_ASM("asm/levels", func_L39_004E43F0);

INCLUDE_ASM("asm/levels", func_L39_004E4568);

INCLUDE_ASM("asm/levels", func_L39_004E4578);

INCLUDE_ASM("asm/levels", func_L39_004E4688);

INCLUDE_ASM("asm/levels", func_L39_004E4748);

INCLUDE_ASM("asm/levels", func_L39_004E47A8);

INCLUDE_ASM("asm/levels", func_L39_004E47F8);

INCLUDE_ASM("asm/levels", func_L39_004E48A8);

INCLUDE_ASM("asm/levels", func_L39_004E48E8);

INCLUDE_ASM("asm/levels", func_L39_004E4970);

INCLUDE_ASM("asm/levels", func_L39_004E4A50);

INCLUDE_ASM("asm/levels", func_L39_004E4AE8);

INCLUDE_ASM("asm/levels", func_L39_004E4BE0);

INCLUDE_ASM("asm/levels", func_L39_004E4C68);

INCLUDE_ASM("asm/levels", func_L39_004E4CA8);

INCLUDE_ASM("asm/levels", func_L39_004E4F28);

INCLUDE_ASM("asm/levels", func_L39_004E4F90);

INCLUDE_ASM("asm/levels", func_L39_004E4FC8);

INCLUDE_ASM("asm/levels", func_L39_004E5008);

/* localdecomp:start func_L39_004E5058 */
typedef struct S_004E5058 {
    char _p0[8];
    s32 (*f8)(struct S_004E5058 *, s32, s32 *);
} S_004E5058;

s32 func_L39_004E5058(S_004E5058 *arg0, s32 arg1) {
    if (arg0 == 0 || arg0->f8 == 0) {
        return 0;
    }
    return arg0->f8(arg0, 0x10, &arg1);
}
/* localdecomp:end func_L39_004E5058 */

INCLUDE_ASM("asm/levels", func_L39_004E5090);

INCLUDE_ASM("asm/levels", func_L39_004E5108);

INCLUDE_ASM("asm/levels", func_L39_004E5168);

INCLUDE_ASM("asm/levels", func_L39_004E5170);
