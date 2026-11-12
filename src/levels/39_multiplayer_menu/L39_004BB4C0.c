#include "common.h"

INCLUDE_ASM("asm/levels", func_L39_004BB4C0);

INCLUDE_ASM("asm/levels", func_L39_004BB540);

INCLUDE_ASM("asm/levels", func_L39_004BB648);

INCLUDE_ASM("asm/levels", func_L39_004BB880);

/* localdecomp:start func_L39_004BB898 */
extern s32 D_L39_004433B8[];
extern s32 D_L39_004433BC[];
__asm__(".extern D_L39_004433B8, 8");
__asm__(".extern D_L39_004433BC, 8");

s32 func_L39_004BB898(s32 idx, s32 val) {
    s32 ret = 1;

    switch (idx) {
    case 0:
        D_L39_004433B8[0] = val;
        break;
    case 1:
        D_L39_004433BC[0] = val;
        break;
    default:
        ret = 0;
        break;
    }
    return ret;
}
/* localdecomp:end func_L39_004BB898 */

INCLUDE_ASM("asm/levels", func_L39_004BB8C8);

INCLUDE_ASM("asm/levels", func_L39_004BBBA0);

/* localdecomp:start func_L39_004BBBE8 */
__asm__(".extern D_L39_004433C8, 16");
extern s32 (*D_L39_004433C8[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F79E8 */
s32 func_L39_004BBBE8(void) {
    if (D_L39_004433C8[0] != 0) {
        return D_L39_004433C8[0]();
    }
    func_L39_004BC6C8(26, 150, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBBE8 */

/* localdecomp:start func_L39_004BBC30 */
__asm__(".extern D_L39_004433D0, 16");
extern s32 (*D_L39_004433D0[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

s32 func_L39_004BBC30(void) {
    if (D_L39_004433D0[0] != 0) {
        return D_L39_004433D0[0]();
    }
    func_L39_004BC6C8(26, 106, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBC30 */

/* localdecomp:start func_L39_004BBC78 */
__asm__(".extern D_L39_004433D4, 16");
extern s32 (*D_L39_004433D4[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7A78 */
s32 func_L39_004BBC78(void) {
 if (D_L39_004433D4[0] != 0) { return D_L39_004433D4[0](); }
 func_L39_004BC6C8(26, 105, 14, 0, 0);
 return 0;
}
/* localdecomp:end func_L39_004BBC78 */

INCLUDE_ASM("asm/levels", func_L39_004BBCC0);

/* localdecomp:start func_L39_004BBD08 */
__asm__(".extern D_L39_004433DC, 16");
extern s32 (*D_L39_004433DC[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7B08 */
s32 func_L39_004BBD08(void) {
    if (D_L39_004433DC[0] != 0) {
        return D_L39_004433DC[0]();
    }
    func_L39_004BC6C8(26, 119, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBD08 */

/* localdecomp:start func_L39_004BBD50 */
__asm__(".extern D_L39_004433E4, 16");
extern s32 (*D_L39_004433E4[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7B50 */
s32 func_L39_004BBD50(void) {
    if (D_L39_004433E4[0] != 0) {
        return D_L39_004433E4[0]();
    }
    func_L39_004BC6C8(26, 114, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBD50 */

/* localdecomp:start func_L39_004BBD98 */
__asm__(".extern D_L39_004433E8, 16");
extern s32 (*D_L39_004433E8[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7B98 */
s32 func_L39_004BBD98(void) {
    if (D_L39_004433E8[0] != 0) {
        return D_L39_004433E8[0]();
    }
    func_L39_004BC6C8(26, 120, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBD98 */

/* localdecomp:start func_L39_004BBDE0 */
__asm__(".extern D_L39_004433EC, 16");
extern s32 (*D_L39_004433EC[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7BE0 */
s32 func_L39_004BBDE0(void) {
    if (D_L39_004433EC[0] != 0) {
        return D_L39_004433EC[0]();
    }
    func_L39_004BC6C8(26, 117, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBDE0 */

INCLUDE_ASM("asm/levels", func_L39_004BBE28);

/* localdecomp:start func_L39_004BBE70 */
__asm__(".extern D_L39_0044340C, 16");
extern s32 (*D_L39_0044340C[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7C70 */
s32 func_L39_004BBE70(void) {
 if (D_L39_0044340C[0] != 0) { return D_L39_0044340C[0](); }
 func_L39_004BC6C8(26, 121, 14, 0, 0);
 return 0;
}
/* localdecomp:end func_L39_004BBE70 */

INCLUDE_ASM("asm/levels", func_L39_004BBEB8);

/* localdecomp:start func_L39_004BBF08 */
__asm__(".extern D_L39_0044341C, 16");
extern s32 (*D_L39_0044341C[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7D08 */
s32 func_L39_004BBF08(void) {
    if (D_L39_0044341C[0] != 0) {
        return D_L39_0044341C[0]();
    }
    func_L39_004BC6C8(26, 127, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBF08 */

/* localdecomp:start func_L39_004BBF50 */
__asm__(".extern D_L39_00443420, 16");
extern s32 (*D_L39_00443420[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7D50 */
s32 func_L39_004BBF50(void) {
    if (D_L39_00443420[0] != 0) {
        return D_L39_00443420[0]();
    }
    func_L39_004BC6C8(26, 126, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BBF50 */

INCLUDE_ASM("asm/levels", func_L39_004BBF98);

/* localdecomp:start func_L39_004BC090 */
__asm__(".extern D_L39_0044342C, 16");
extern s32 (*D_L39_0044342C[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7E90 */
s32 func_L39_004BC090(void) {
    if (D_L39_0044342C[0] != 0) {
        return D_L39_0044342C[0]();
    }
    func_L39_004BC6C8(26, 148, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC090 */

INCLUDE_ASM("asm/levels", func_L39_004BC0D8);

/* localdecomp:start func_L39_004BC150 */
__asm__(".extern D_L39_00443428, 16");
extern s32 (*D_L39_00443428[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7F50 */
s32 func_L39_004BC150(void) {
    if (D_L39_00443428[0] != 0) {
        return D_L39_00443428[0]();
    }
    func_L39_004BC6C8(26, 147, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC150 */

/* localdecomp:start func_L39_004BC198 */
__asm__(".extern D_L39_00443440, 16");
extern s32 (*D_L39_00443440[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F7F98 */
s32 func_L39_004BC198(void) {
 if (D_L39_00443440[0] != 0) { return D_L39_00443440[0](); }
 func_L39_004BC6C8(26, 153, 14, 0, 0);
 return 0;
}
/* localdecomp:end func_L39_004BC198 */

INCLUDE_ASM("asm/levels", func_L39_004BC1E0);

INCLUDE_ASM("asm/levels", func_L39_004BC228);

INCLUDE_ASM("asm/levels", func_L39_004BC270);

/* localdecomp:start func_L39_004BC2B8 */
__asm__(".extern D_L39_00443450, 16");
extern s32 (*D_L39_00443450[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F80B8 */
s32 func_L39_004BC2B8(void) {
 if (D_L39_00443450[0] != 0) { return D_L39_00443450[0](); }
 func_L39_004BC6C8(26, 102, 14, 0, 0);
 return -1;
}
/* localdecomp:end func_L39_004BC2B8 */

/* localdecomp:start func_L39_004BC300 */
__asm__(".extern D_L39_00443454, 16");
extern s32 (*D_L39_00443454[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F8100 */
s32 func_L39_004BC300(void) {
    if (D_L39_00443454[0] != 0) {
        return D_L39_00443454[0]();
    }
    func_L39_004BC6C8(26, 138, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC300 */

/* localdecomp:start func_L39_004BC348 */
__asm__(".extern D_L39_00443474, 16");
extern s32 (*D_L39_00443474[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F8148 */
s32 func_L39_004BC348(void) {
    if (D_L39_00443474[0] != 0) {
        return D_L39_00443474[0]();
    }
    func_L39_004BC6C8(26, 111, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC348 */

/* localdecomp:start func_L39_004BC390 */
__asm__(".extern D_L39_00443478, 16");
extern s32 (*D_L39_00443478[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F8190 */
s32 func_L39_004BC390(void) {
 if (D_L39_00443478[0] != 0) { return D_L39_00443478[0](); }
 func_L39_004BC6C8(26, 100, 14, 0, 0);
 return 0;
}
/* localdecomp:end func_L39_004BC390 */

/* localdecomp:start func_L39_004BC3D8 */
__asm__(".extern D_L39_0044347C, 16");
extern s32 (*D_L39_0044347C[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F81D8 */
s32 func_L39_004BC3D8(void) {
    if (D_L39_0044347C[0] != 0) {
        return D_L39_0044347C[0]();
    }
    func_L39_004BC6C8(26, 109, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC3D8 */

INCLUDE_ASM("asm/levels", func_L39_004BC420);

/* localdecomp:start func_L39_004BC468 */
__asm__(".extern D_L39_00443494, 16");
extern s32 (*D_L39_00443494[])(void);
extern s32 func_L39_004BC6C8(s32, s32, s32, s32, s32);

/* from rac4-decomp's func_L00_004F8268 */
s32 func_L39_004BC468(void) {
    if (D_L39_00443494[0] != 0) {
        return D_L39_00443494[0]();
    }
    func_L39_004BC6C8(26, 108, 14, 0, 0);
    return 0;
}
/* localdecomp:end func_L39_004BC468 */

INCLUDE_ASM("asm/levels", func_L39_004BC4B0);

INCLUDE_ASM("asm/levels", func_L39_004BC4F8);

INCLUDE_ASM("asm/levels", func_L39_004BC6C8);

INCLUDE_ASM("asm/levels", func_L39_004BC8B0);

INCLUDE_ASM("asm/levels", func_L39_004BCA88);

INCLUDE_ASM("asm/levels", func_L39_004BCBB0);

INCLUDE_ASM("asm/levels", func_L39_004BCC38);
