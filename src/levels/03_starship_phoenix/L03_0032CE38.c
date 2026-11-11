#include "common.h"

typedef struct S_Foo_0032D228 {
    u8 pad0[0xF2];
    u16 f2;
    u8 f4;
    u8 pad1[0x108 - 0xF5];
    s32 f108;
} S_Foo_0032D228;

typedef struct S_0032D598 {
    u8 pad[0xB4];
    s32 cnt[16];
} S_0032D598;

typedef struct { u8 pad0[0x30]; u8 b30[0x40]; u8 b70[0x10]; } Ent_32CF78;
typedef struct { u8 pad0[0x68]; struct { u8 pad[0xD0]; s32 idx; } *p68; } Obj_32CF78;


/* localdecomp:start func_L03_0032CE38 */
/* m2c3 */
void *func_L01_003F2A50(s32, s32);              /* extern */
s32 func_L01_003F2AF8(s32, void *);             /* extern */

void func_L03_0032CE38(void *arg0) {
    void *temp_16;
    void *temp_2;
    void *temp_5;

    temp_16 = (*(void **)((u8 *)(arg0) + 0x68));
    if ((u32) ((*(u8 *)((u8 *)(arg0) + 0x20)) - 5) < 4U) {
        temp_2 = (*(void **)((u8 *)(temp_16) + 0xE8));
        if (temp_2 == 0) {
            (*(void **)((u8 *)(temp_16) + 0xE8)) = func_L01_003F2A50(0, 5);
            return;
        }
        (*(f32 *)((u8 *)(temp_2) + 0)) = 8.0f;
        (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_16) + 0xE8))) + 4)) = 4.0f;
        (*(f32 *)((u8 *)((*(void **)((u8 *)(temp_16) + 0xE8))) + 8)) = 1.0f;
        return;
    }
    temp_5 = (*(void **)((u8 *)(temp_16) + 0xE8));
    if (temp_5 != 0) {
        func_L01_003F2AF8(0, temp_5);
        (*(void **)((u8 *)(temp_16) + 0xE8)) = 0;
    }
}
/* localdecomp:end func_L03_0032CE38 */
