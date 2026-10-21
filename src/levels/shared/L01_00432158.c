#include "common.h"

typedef struct { 
    u8 pad[0x10]; 
    s32 f10; 
    u8 pad2[0x150]; 
    s32 f164; 
    s32 f168; 
    u8 pad3[0x10]; 
    s32 f17C; 
} S_142430x;

/* localdecomp:start func_L01_00432158 */
extern S_142430x D_00142430;
extern s32 D_001D4CE8_g;

void func_L01_00432158(void) {
    S_142430x *p = &D_00142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_L01_00432158 */

/* localdecomp:start func_L01_00432180 */
extern S_142430x D_00142430;
extern s32 D_001D4CE8_g;

void func_L01_00432180(void) {
    S_142430x *p = &D_00142430;
    p->f164 = -1;
    D_001D4CE8_g = 6;
    p->f168 = -1;
}
/* localdecomp:end func_L01_00432180 */
