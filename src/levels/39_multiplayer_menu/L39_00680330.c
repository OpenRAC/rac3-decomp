#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
s32 func_L01_00516C78(s32, s32, s32);

/* localdecomp:start func_L39_00680330 */
s32 func_L01_00516C78(s32, s32, s32);

void func_L39_00680330(void *arg0, s32 arg1) {
    s32 var_a1;

    var_a1 = arg1;
    switch (var_a1) {                               /* irregular */
    case -1:
        var_a1 = 1;
        break;
    case 1:
        var_a1 = 2;
        break;
    case 0:
        var_a1 = 3;
        break;
    }
    if ((*(s32 *)((u8 *)arg0 + 0x70)) != -1) {
        func_L01_00516C78((*(s32 *)((u8 *)arg0 + 0x70)), var_a1, 3);
    }
}
/* localdecomp:end func_L39_00680330 */

/* localdecomp:start func_L39_00680390 */
typedef struct {
    char _p0[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_680390;

/* from rac4-decomp's func_L00_0053BEF0 */
void func_L39_00680390(S_680390 *arg0) {
    arg0->f68 = -1;
    arg0->f6C = -1;
    arg0->f70 = -1;
}
/* localdecomp:end func_L39_00680390 */
