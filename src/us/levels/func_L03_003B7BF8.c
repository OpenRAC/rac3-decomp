#include "common.h"
/* localdecomp:start func_L03_003B7BF8 */
extern s32 D_001DF540_sda;
typedef int Pair133 __attribute__((mode(DI)));
extern s32 func_L03_0043BF68(s32,s32,f32);
void func_L03_003B7BF8(u8 *obj) {
    if (*(u8 **)(obj+0xB8)) {
        *(Pair133 *)(obj+0x38)=*(Pair133 *)(*(u8 **)(obj+0xB8)+0x38);
    }
    { s32 time=D_001DF540_sda;
    s32 period=120;
    *(u16 *)(obj+0x34)&=0xFF7F;
    *(s32 *)(obj+0x78)=func_L03_0043BF68(0x55200000,0x55100000,(time%period)*6.2831855f/(f32)period-3.1415927f);
    }
}
/* localdecomp:end func_L03_003B7BF8 */
