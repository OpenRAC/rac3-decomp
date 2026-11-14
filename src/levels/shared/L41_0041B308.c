#include "common.h"

typedef struct {
    u8 pad0[4];
    s32 w4;
    u8 pad8[0x120];
    s32 w128;
    u8 pad12C[0x44];
    s32 w170;
    u8 pad174[0x660];
    u8 b7D4;
} S_0041B870;
typedef struct { s32 f0; f32 f4; s32 f8; s32 fC; } V_0041C328;
typedef struct { u8 p0[0x68]; V_0041C328 *vars; u8 p6C[0x100 - 0x6C]; } M_0041C328;

/* localdecomp:start func_L41_0041B308 */
typedef struct { u8 p0[0x20]; u8 b20; } M_41AA50;
extern void func_L41_0048B8C0(M_41AA50 *, s32);
extern void func_L01_004450F0(M_41AA50 *, s32, s32);

void func_L41_0041B308(M_41AA50 *m) {
    if (m->b20 == 0) {
        func_L41_0048B8C0(m, -1);
        func_L01_004450F0(m, 1, -1);
    }
}
/* localdecomp:end func_L41_0041B308 */
