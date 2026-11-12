#include "common.h"

/* localdecomp:start func_L21_003B0E90 */
extern u8 D_001A4BE0[];
extern u8 D_001D66B0;
void func_L01_00446A70(s32, s32, s32, s32, s32, f32);

void func_L21_003B0E90(void *arg0) {
    u8 *temp;
    s32 a2 = 1;

    if (*(u8 *)((u8 *)arg0 + 0x20) == 0) {
        *(u16 *)((u8 *)arg0 + 0x34) = (u16) ((*(u16 *)((u8 *)arg0 + 0x34)) | 0x41);
        *(u8 *)((u8 *)arg0 + 0x20) = 1;
    }
    temp = D_001A4BE0;
    if (*(void **)(temp + 0x35C) == arg0) {
        if (*(s32 *)(temp + 0x360) != 0) {
            func_L01_00446A70(*(s32 *)(temp + 0x25C0), (s32) arg0, a2, (s32) (temp + 0x80), (s32) &D_001D66B0, 1.0f);
        }
    }
}
/* localdecomp:end func_L21_003B0E90 */
