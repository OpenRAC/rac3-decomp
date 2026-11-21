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
typedef struct { u8 pad0[0x1C4]; s32 w1C4; } S_00499F00;
extern S_00499F00 *D_001D52FC[] __attribute__((section(".sdata")));
extern u8 D_L01_001D672C[] __attribute__((section(".sdata")));
extern s32 func_L01_00498610(s32);
extern void func_L01_004990A8(s32 a, s32 b);
extern u8 func_L01_0047DAB0(void);
extern void func_L01_0047DAC8(void);
extern s32 func_L01_0047EBE0(void);
extern void func_L01_00517748(int);
extern void func_L01_00517918(s32);
extern void func_003A2750(s32);
extern void func_003A2750(s32 a0);
extern void func_L01_0049B7D0();

/* localdecomp:start func_L01_0049B7D0 */
extern s32 D_L01_001D9400;
extern void func_L01_0049C1D8(void);
extern void func_L01_0049C160(void *a0);
extern void func_L01_00516090_0049B7D0(void *);

void func_L01_0049B7D0(void *a) {
    s32 w = D_001D52FC[0]->w1C4;

    if (D_L01_001D9400 != 0) {
        w &= ~0x5000;
    }
    func_L01_004990A8(func_L01_00498610(0), w);
    func_L01_0049C1D8();
    func_L01_0049C160(a);
    if (func_L01_0047DAB0() != 0) {
        func_L01_0047DAC8();
        func_L01_00516090_0049B7D0(a);
        if (D_L01_001D672C[0] == 0) {
            func_L01_00517748(func_L01_0047EBE0());
        }
    }
}
/* localdecomp:end func_L01_0049B7D0 */

/* localdecomp:start func_L01_0049B878 */
extern void func_L01_00517918(s32);
extern void func_L01_0049C120_0049B878(void);
extern void func_003A2750(s32);

void func_L01_0049B878(void) {
    func_L01_00517918(16);
    func_L01_00517918(17);
    func_L01_00517918(20);
    func_L01_0049C120_0049B878();
    func_003A2750(1);
}
/* localdecomp:end func_L01_0049B878 */

/* localdecomp:start func_L01_0049B8B8 */
extern void func_L01_0047E4B8_0049B8B8();
 
void func_L01_0049B8B8(void) {
    func_L01_0047E4B8_0049B8B8();
}
/* localdecomp:end func_L01_0049B8B8 */

/* localdecomp:start func_L01_0049B8D8 */
extern void func_L01_0047E520_0049B8D8();
 
void func_L01_0049B8D8(void) {
    func_L01_0047E520_0049B8D8();
}
/* localdecomp:end func_L01_0049B8D8 */

INCLUDE_ASM("asm/levels", func_L01_0049B8F8);
