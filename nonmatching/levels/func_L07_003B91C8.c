/* PAL near miss (Codex wave 8): near miss: 12 words differ with the file's flags.
 * Worker's note: 12 diff: three target-base scratch register pairs and two loop mask/literal ordering triples; 3 C forms identical. Best w443/func_L07_003B91C8.01.log
 */
#include "common.h"

/* localdecomp:start func_L07_003B91C8 */
typedef struct { u8 kind[8], extra[8]; s16 a[8], b[8], c[8], d[8]; s32 params[8]; s32 index1, index3, index2, slot; u8 *target; } Data_003B91C8;
extern u16 *D_L07_0021C020[];
typedef struct { u8 bytes[256]; } Target_003B91C8;
extern Target_003B91C8 *D_L07_001DF41C __attribute__((section(".data")));
extern s32 D_001DF458_sda;
void func_L07_003B91C8(u8 *moby, s32 slot, s32 arg) {
    extern s32 func_L07_003A7178(u8 *, u8 *, s32, u8, s32);
    extern s32 func_L07_003BA000(u8 *, u8 *, u8, s32, u8, s32);
    extern s32 func_L07_003A6C90(u8 *, u8 *, s16, s16, s16, s16, s32, u8, s32);
    extern void func_L01_004450F0(void *, s32, s32);
    Data_003B91C8 *data;
    u16 *p;
    u8 *target;
    s32 index;
    s32 result;
    u16 *p1;
    u8 *target1;
    *(u16 *)(moby + 0x34) &= 0xFFFD;
    data = *(Data_003B91C8 **)(moby + 0x68);
    data->slot = slot;
    switch (data->kind[slot]) {
    case 0: break;
found1:
    data->target = target1;
    goto done;
found:
    data->target = target;
    goto done;
    case 1:
        p1 = D_L07_0021C020[data->index1];
        while ((u8)(index = data->index1) != 255 &&
               index <= D_001DF458_sda && p1 != 0 &&
               ((s16)p1[-1] >= 0 || p1 == D_L07_0021C020[index])) {
            target1 = (u8 *)&D_L07_001DF41C[*p1 & 0x7FFF];
            if (target1 == 0) break;
            result = func_L07_003A7178(target1, moby + 0x10, arg, moby[0x21], data->params[slot]);
            if (result) {
                goto found1;
            }
            p1++;
        }
        break;
    case 2:
        p = D_L07_0021C020[data->index2];
        while ((u8)(index = data->index2) != 255 &&
               index <= D_001DF458_sda && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L07_0021C020[index])) {
            target = (u8 *)&D_L07_001DF41C[*p & 0x7FFF];
            if (target == 0) break;
            result = func_L07_003BA000(target, moby + 0x10, data->extra[slot], arg, moby[0x21], data->params[slot]);
            if (result) {
                goto found;
            }
            p++;
        }
        break;
    case 3:
        p = D_L07_0021C020[data->index3];
        while (((index = data->index3) & 255) != 255 &&
               index <= D_001DF458_sda && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L07_0021C020[index])) {
            target = (u8 *)&D_L07_001DF41C[*p & 0x7FFF];
            if (target == 0) break;
            result = func_L07_003A6C90(target, moby + 0x10, data->d[slot], data->a[slot], data->b[slot], data->c[slot], arg, moby[0x21], data->params[slot]);
            if (result) {
                goto found;
            }
            p++;
        }
        break;
    }
done:
    func_L01_004450F0(moby, 2, -1);
}
/* localdecomp:end func_L07_003B91C8 */
