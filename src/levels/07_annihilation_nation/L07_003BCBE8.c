#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;


/* localdecomp:start func_L07_003BCBE8 */
void func_L07_003BCB10(void *, s32);

void func_L07_003BCBE8(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x290)) != -1) {
        func_L07_003BCB10(arg0, 5);
        return;
    }
    func_L07_003BCB10(arg0, 0x4);
}
/* localdecomp:end func_L07_003BCBE8 */
