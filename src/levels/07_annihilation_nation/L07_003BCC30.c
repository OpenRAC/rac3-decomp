#include "common.h"

typedef struct { f32 f0; s16 h4; } P_003BB1F0;

typedef struct S_003BB7A8 {
    u8 pad[0xA4];
    u16 flags;
} S_003BB7A8;


/* localdecomp:start func_L07_003BCC30 */
void func_L07_003BB038(s32);
void func_L07_003BCB10(void *, s32);
void func_L07_003BCBE8(void *);

void func_L07_003BCC30(void *arg0) {
    void *handle = *(void **)((u8 *)arg0 + 0x68);

    func_L07_003BB038((s32)arg0);
    if (*(s32 *)((u8 *)handle + 0x294) != -1) {
        func_L07_003BCB10(arg0, 6);
    } else {
        func_L07_003BCBE8(arg0);
    }
}
/* localdecomp:end func_L07_003BCC30 */

/* localdecomp:start func_L07_003BCC88 */
void func_L07_003BCB10(void *, s32);

void func_L07_003BCC88(void *arg0) {
    if ((*(s32 *)((u8 *)((*(void **)((u8 *)arg0 + 0x68))) + 0x294)) != -1) {
        func_L07_003BCB10(arg0, 9);
        return;
    }
    func_L07_003BCB10(arg0, 0xA);
}
/* localdecomp:end func_L07_003BCC88 */

INCLUDE_ASM("asm/levels", func_L07_003BCCD0);

/* localdecomp:start func_L07_003BCD80 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003BB038(s32);
void func_L07_003BCD80(s32 arg0) {
    func_L07_003BB1F0((u8 *)arg0);
    func_L07_003BB038(arg0);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003BCD80 */
