#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x7058 - 0x4958];
    u8 fX[1];
} S_func_00498868;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
    s32 xC;
    s32 x10;
    u8 x14;
    u8 pad[3];
} E_498978;

/* localdecomp:start func_L01_0049BE80 */
extern void func_L01_0047DAD0();
extern s32 func_L01_0047EBE0(void);
extern s32 func_L01_00517748();
extern void *func_L01_0049B550();
extern void func_L01_00516090_0049BE80(void *p);

void func_L01_0049BE80(void) {
    func_L01_0047DAD0(9);
    func_L01_00517748(func_L01_0047EBE0());
    func_L01_00516090_0049BE80(func_L01_0049B550());
}
/* localdecomp:end func_L01_0049BE80 */

INCLUDE_ASM("asm/levels", func_L01_0049BEC0);

/* localdecomp:start func_L01_0049C0C8 */
extern S_func_00498868 D_00160C40[];
extern void *D_L01_001D9410;
extern void *D_L01_001D9414;
extern void *func_003BB3A8(s32);
extern void *func_003B42F8(s32);
extern s32 func_003B4528(void *, s32, s32, s32, s32);
void func_L01_0049C0C8(void) {
    D_L01_001D9410 = func_003BB3A8(0);
    D_L01_001D9414 = func_003BB3A8(0);
    func_003B4528(func_003B42F8(0), (s32)D_L01_001D9410, (s32)D_L01_001D9414, D_00160C40->f4954, (s32)D_00160C40->fX);
}
/* localdecomp:end func_L01_0049C0C8 */

/* localdecomp:start func_L01_0049C120 */
extern void *D_L01_001D9414;
extern void *D_L01_001D9410;
extern void *func_003B42F8(s32);
extern void func_003BB468(s32);
void func_L01_0049C120(void) {
    O_49A988 *o = ((O_49A988 * (*)(s32))func_003B42F8)(0);
    o->vt->fn(o);
    func_003BB468((*(s32 *)&D_L01_001D9410));
    func_003BB468((*(s32 *)&D_L01_001D9414));
}
/* localdecomp:end func_L01_0049C120 */

INCLUDE_ASM("asm/levels", func_L01_0049C160);

/* localdecomp:start func_L01_0049C1D8 */
extern s32 *func_003B9BD0(s32);
extern s32 func_003B9C58(s32 *);
extern s32 func_00381FF0(s32);
extern s32 func_L01_00516FD8(s32, s32);
extern s32 func_L01_00516D60(s32, s32);
extern s32 func_L01_00517190(s32, s32);
extern s32 D_L01_001D940C;
extern s32 D_L01_001D9404;
extern s32 D_L01_001D9454;
extern E_498978 D_L01_002EBED8[];
extern char D_L01_001D9458[];

void func_L01_0049C1D8(void) {
    D_L01_001D940C = func_003B9C58(func_003B9BD0(0));
    if (D_L01_001D940C < 0) {
        return;
    }
    if (D_L01_001D9404 != D_L01_001D940C) {
        if (D_L01_002EBED8[D_L01_001D940C].x14) {
            func_L01_00516FD8(0x4E0005, func_00381FF0(D_L01_002EBED8[D_L01_001D940C].x0));
            func_L01_00516FD8(0x4E0006, func_00381FF0(D_L01_002EBED8[D_L01_001D940C].x4));
        } else {
            func_L01_00516FD8(0x4E0005, func_00381FF0(456));
            func_L01_00516FD8(0x4E0006, (s32)D_L01_001D9458);
        }
        D_L01_001D9454 = 30;
    }
    if (D_L01_001D9454 != 0) {
        if (--D_L01_001D9454 == 0) {
            if (D_L01_002EBED8[D_L01_001D940C].x14) {
                func_L01_00517190(0x4E0009, D_L01_002EBED8[D_L01_001D940C].x8 + 1);
                func_L01_00516D60(0x4E0009, 1);
            } else {
                func_L01_00516D60(0x4E0009, 0);
            }
        }
    }
    D_L01_001D9404 = D_L01_001D940C;
}
/* localdecomp:end func_L01_0049C1D8 */

INCLUDE_ASM("asm/levels", func_L01_0049C338);

/* localdecomp:start func_L01_0049C630 */
extern s32 func_L01_0049C630(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0C10;
extern s32 D_L01_001E0BF8[2];
extern void func_L01_0049C688();
extern void func_L01_0049C9A0();
extern void func_L01_0049C950();
extern void func_L01_0049C9E8_0049C630(void);
extern void func_L01_0049CA08_0049C630();
s32 func_L01_0049C630(void) {
    if (D_L01_001E0C10 == 0) {
        func_003E6FA0(D_L01_001E0BF8, (s32)func_L01_0049C688, (s32)func_L01_0049C9A0, (s32)func_L01_0049C950, (s32)func_L01_0049C9E8_0049C630, (s32)func_L01_0049CA08_0049C630);
        D_L01_001E0C10 = 1;
    }
    return (s32)D_L01_001E0BF8;
}
/* localdecomp:end func_L01_0049C630 */

INCLUDE_ASM("asm/levels", func_L01_0049C688);

INCLUDE_ASM("asm/levels", func_L01_0049C950);

/* localdecomp:start func_L01_0049C9A0 */
extern s32 func_L01_00517918();
extern s32 D_L01_001D946C;
extern void func_L01_0049D150(void);
extern s32 func_003A2750(s32);
void func_L01_0049C9A0(void) {
    func_L01_00517918(0x10);
    func_L01_00517918(0x11);
    if (D_L01_001D946C != 0) {
        func_L01_00517918(0x14);
    }
    func_L01_0049D150();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049C9A0 */

/* localdecomp:start func_L01_0049C9E8 */
extern void func_L01_0047E4B8_0049C9E8();
 
void func_L01_0049C9E8(void) {
    func_L01_0047E4B8_0049C9E8();
}
/* localdecomp:end func_L01_0049C9E8 */

/* localdecomp:start func_L01_0049CA08 */
extern void func_L01_0047E520_0049CA08();
 
void func_L01_0049CA08(void) {
    func_L01_0047E520_0049CA08();
}
/* localdecomp:end func_L01_0049CA08 */

INCLUDE_ASM("asm/levels", func_L01_0049CA28);
