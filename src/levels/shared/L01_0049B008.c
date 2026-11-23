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
