#include "common.h"

/* localdecomp:start func_L09_003C5DB0 */
extern f32 func_L01_0040E548(void *, void *);
extern void func_L01_004472C0(void *);
extern u8 D_L09_001E2B80[];

void func_L09_003C5DB0(void *arg0) {
    void *temp_s0;

    temp_s0 = *(void **)((u8 *)arg0 + 0x68);
    *(s8 *)((u8 *)temp_s0 + 0x3E) = 3;
    *(f32 *)((u8 *)temp_s0 + 0x30) = 1.0f;
    *(s16 *)((u8 *)temp_s0 + 0x34) = 1;
    *(s32 *)((u8 *)temp_s0 + 0x40) = 0;
    *(s8 *)((u8 *)temp_s0 + 0x3F) = 0;
    *(s8 *)((u8 *)temp_s0 + 0x64) = 0;
    if (*(u8 *)((u8 *)arg0 + 0x31) != 0) {
        if (func_L01_0040E548(D_L09_001E2B80, (u8 *)arg0 + 0x10) < 1024.0f) {
            func_L01_004472C0(arg0);
            *(s8 *)((u8 *)arg0 + 0x6F) = 0x1E;
        }
    }
    *(s8 *)((u8 *)temp_s0 + 0x58) = 0x28;
    *(s8 *)((u8 *)temp_s0 + 0x5A) = 0x60;
}
/* localdecomp:end func_L09_003C5DB0 */
