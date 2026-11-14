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

/* localdecomp:start func_L07_003BCCD0 */
typedef int Quad_003BCCD0 __attribute__((mode(TI)));

extern void func_L07_003BB1A8(u8 *);
extern void func_L07_003BCB10(void *, s32);
extern void func_L07_003BCBE8(void *);
extern f32 func_00382538(void);

void func_L07_003BCCD0(u8 *self, s32 idx) {
    u8 *s = *(u8 **)(self + 0x68);

    if ((s + idx)[0x270] != 0) {
        func_L07_003BB1A8(self);
        *(f32 *)(self + 0x2C) = *(f32 *)(*(u8 **)(self + 0x24) + 0x24);
        *(Quad_003BCCD0 *)(self + 0x10) = *(Quad_003BCCD0 *)(s + 0x240);
        *(Quad_003BCCD0 *)(self + 0xF0) = *(Quad_003BCCD0 *)(s + 0x250);
        *(f32 *)(s + 0x2A8) = func_00382538();
        if (*(s32 *)(s + 0x298) != -1) {
            func_L07_003BCB10(self, 2);
        } else {
            *(u16 *)(self + 0x34) = (*(u16 *)(self + 0x34) & 0xFFBE) | 0x1000;
            *(s32 *)(self + 0x98) = *(s32 *)(*(u8 **)(self + 0x24) + 0x10);
            func_L07_003BCBE8(self);
        }
    }
}
/* localdecomp:end func_L07_003BCCD0 */

/* localdecomp:start func_L07_003BCD80 */
void func_L01_004450F0(s32, s32, s32);
void func_L07_003BB038(s32);
void func_L07_003BCD80(s32 arg0) {
    func_L07_003BB1F0((u8 *)arg0);
    func_L07_003BB038(arg0);
    func_L01_004450F0(arg0, 1, -1);
}
/* localdecomp:end func_L07_003BCD80 */
