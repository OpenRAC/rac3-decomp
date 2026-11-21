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

/* localdecomp:start func_L01_00499C80 */
extern s32 func_L01_00499C80(void);

extern s32 func_003E6FA0(s32 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);
extern s32 D_L01_001E0BB0;
extern s32 D_L01_001E0B98[2];
extern void func_L01_00499CD8();
extern void func_L01_00499F88();
extern void func_L01_00499F00();
extern void func_L01_00499FD0_00499C80(void);
extern void func_L01_00499FF0_00499C80();
s32 func_L01_00499C80(void) {
    if (D_L01_001E0BB0 == 0) {
        func_003E6FA0(D_L01_001E0B98, (s32)func_L01_00499CD8, (s32)func_L01_00499F88, (s32)func_L01_00499F00, (s32)func_L01_00499FD0_00499C80, (s32)func_L01_00499FF0_00499C80);
        D_L01_001E0BB0 = 1;
    }
    return (s32)D_L01_001E0B98;
}
/* localdecomp:end func_L01_00499C80 */
