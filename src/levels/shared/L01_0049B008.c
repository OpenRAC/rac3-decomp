#include "common.h"

typedef struct {
    u8 pad0[0x4954];
    s32 f4954;
    u8 pad1[0x5628 - 0x4958];
    u8 fX[1];
} S_func_00496AB0;
typedef struct O_49A988 O_49A988;
typedef struct { u8 p0[0xC]; void (*fn)(O_49A988 *); } VT_49A988;
struct O_49A988 { s32 w0; VT_49A988 *vt; };
typedef struct {
    s32 x0;
    s32 x4;
    s32 x8;
} E_496DC0;
typedef struct {
    s32 id;
    s32 pad[3];
} Ent_497BC8;
typedef struct { s32 a; s32 b; s32 c; s32 d; } Ent_00497C30;

/* declared by functions of L01_00499C80.c, which this file was cut from */
extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void *func_003B42F8(s32);
extern void func_003BB468(s32);

/* localdecomp:start func_L01_0049B008 */
extern void *func_003B42F8(s32);
extern void func_L01_00517918(s32);
extern s32 D_L01_001DFB94;
extern s32 D_L01_001D937C;
extern void func_003A2750(s32 a0);
extern void func_003BB468(s32 a0);
void func_L01_0049B008(void) {
    u8 *p;
    ((s32 (*)(s32 a0))func_L01_00517918)(16);
    ((s32 (*)(s32 a0))func_L01_00517918)(17);
    D_L01_001DFB94 = 2;
    p = ((u8 * (*)(s32 a0))func_003B42F8)(0);
    (*(void (**)(u8 *))(*(u8 **)(p + 4) + 12))(p);
    func_003A2750(1);
    func_003BB468(D_L01_001D937C);
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049B008 */

/* localdecomp:start func_L01_0049B068 */
extern void func_L01_0047E4B8_0049B068();
 
void func_L01_0049B068(void) {
    func_L01_0047E4B8_0049B068();
}
/* localdecomp:end func_L01_0049B068 */

INCLUDE_ASM("asm/levels", func_L01_0049B088);

/* localdecomp:start func_L01_0049B428 */

extern u8 D_001426E0[];
extern Ent_497BC8 D_L01_002EBDEC[];

s32 func_L01_0049B428(s32 cur)
{
    s32 j;
    s32 k;

    for (j = 1; j < 15; j++) {
        k = cur - j;
        if (k < 0) {
            k += 15;
        }
        if (D_001426E0[D_L01_002EBDEC[k].id] != 0) {
            return k;
        }
    }
    return cur;
}
/* localdecomp:end func_L01_0049B428 */

/* localdecomp:start func_L01_0049B490 */
extern Ent_497BC8 D_L01_002EBDEC[];
extern u8 D_001426E0[];
s32 func_L01_0049B490(s32 a0) {
    s32 i;
    s32 j;
    for (i = 1; i < 15; i++) {
        j = a0 + i;
        if (j >= 15) j -= 15;
        if (D_001426E0[((Ent_00497C30 *)&D_L01_002EBDEC)[j].a]) return j;
    }
    return a0;
}
/* localdecomp:end func_L01_0049B490 */

/* localdecomp:start func_L01_0049B4F8 */
extern s32 func_L01_0049B4F8(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0BD0;
extern s32 D_L01_001E0BB8[2];
extern void func_L01_0049A868();
extern void func_L01_0049B008();
extern void func_L01_0049AC88();
extern void func_L01_0049B068_0049B4F8(void);
extern void func_L01_0049B088();
s32 func_L01_0049B4F8(void) {
    if (D_L01_001E0BD0 == 0) {
        func_003E6FA0(D_L01_001E0BB8, (s32)func_L01_0049A868, (s32)func_L01_0049B008, (s32)func_L01_0049AC88, (s32)func_L01_0049B068_0049B4F8, (s32)func_L01_0049B088);
        D_L01_001E0BD0 = 1;
    }
    return (s32)D_L01_001E0BB8;
}
/* localdecomp:end func_L01_0049B4F8 */

/* localdecomp:start func_L01_0049B550 */
extern s32 func_L01_0049B550(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0BF0;
extern s32 D_L01_001E0BD8[2];
extern void func_L01_0049B5A8();
extern void func_L01_0049B878_0049B550();
extern void func_L01_0049B7D0();
extern void func_L01_0049B8B8_0049B550(void);
extern void func_L01_0049B8D8_0049B550();
s32 func_L01_0049B550(void) {
    if (D_L01_001E0BF0 == 0) {
        func_003E6FA0(D_L01_001E0BD8, (s32)func_L01_0049B5A8, (s32)func_L01_0049B878_0049B550, (s32)func_L01_0049B7D0, (s32)func_L01_0049B8B8_0049B550, (s32)func_L01_0049B8D8_0049B550);
        D_L01_001E0BF0 = 1;
    }
    return (s32)D_L01_001E0BD8;
}
/* localdecomp:end func_L01_0049B550 */
