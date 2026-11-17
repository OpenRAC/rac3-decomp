#include "common.h"
/* localdecomp:start func_L01_003A6DA8 */
typedef struct { u8 p0[0x318]; s32 f318; u8 p31C[0x44]; s32 arr[10]; } P_A6DA8;
extern u8 *D_L01_001E001C;
extern u16 *D_L01_0021DE20[];
extern s32 D_001E0058_sda;
__asm__(".extern D_001E0058_sda, 4");
void func_L01_003A6DA8(u8 *obj, u8 *parent, s32 group) {
    P_A6DA8 *v = *(P_A6DA8 **)(obj + 0x68);
    v->f318 = parent != 0 ? ((s32)parent - (s32)D_L01_001E001C) >> 8 : -1;
    if (group != 255) {
        u16 *p;
        u8 *m;
        s32 i;
        p = D_L01_0021DE20[group];
        i = 0;
        while ((group & 255) != 255 && group <= D_001E0058_sda && p != 0 &&
               ((s16)p[-1] >= 0 || p == D_L01_0021DE20[group])) {
            m = D_L01_001E001C + ((*p & 0x7FFF) << 8);
            if (m == 0) break;
            v->arr[i] = ((s32)m - (s32)D_L01_001E001C) >> 8;
            i++;
            *(u16 *)(m + 0x34) |= 2;
            p++;
        }
    } else {
        s32 j;
        for (j = 9; j >= 0; j--) {
            *(s32 *)((u8 *)v + 0x360 + j * 4) = -1;
        }
    }
}
/* localdecomp:end func_L01_003A6DA8 */
