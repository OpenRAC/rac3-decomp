#include "common.h"

/* localdecomp:start func_L07_0049AA38 */
typedef struct {
    s32 id, word4, word8;
    u32 value;
    s32 type;
    u8 enabled, pad[3];
} Entry_0049AA38;
extern Entry_0049AA38 D_L07_002EDE28[];
extern u32 D_00142BA0[];
extern u8 D_00142693[];
__asm__(".extern D_00142693, 16");
void func_L07_0049AA38(void) {
    extern s32 func_L01_0041A4F0(void);
    s32 i=0, j;
    u32 bit;
    while (D_L07_002EDE28[i].id) {
        switch (D_L07_002EDE28[i].type) {
        case 0: {
            Entry_0049AA38 *entry=&D_L07_002EDE28[i];
            s32 result=0;
            if (func_L01_0041A4F0() || (D_00142BA0[D_L07_002EDE28[i].value>>2] & (1 << (D_L07_002EDE28[i].value & 31)))) result=1;
            entry->enabled=result;
            break;
        }
        case 1: {
            D_L07_002EDE28[i].enabled=1;
            for (j=0; ((u32 *)D_L07_002EDE28[i].value)[j];j++) {
                Entry_0049AA38 *entry=&D_L07_002EDE28[i];
                u32 **list=(u32 **)&D_L07_002EDE28[i].value;
                s32 result=0;
                if (func_L01_0041A4F0() || (entry->enabled && (D_00142BA0[(*list)[j]>>2] & (1 << ((*list)[j] & 31))))) result=1;
                entry->enabled=result;
            }
            break;
        }
        case 2:
            bit=D_L07_002EDE28[i].value;
            D_L07_002EDE28[i].enabled=(D_00142BA0[bit>>2] & (1 << (bit & 31)))!=0;
            break;
        case 3:
            D_L07_002EDE28[i].enabled=D_00142693[0]!=0;
            D_L07_002EDE28[i].enabled=func_L01_0041A4F0();
            break;
        case 4:
        default:
            if (D_L07_002EDE28[i].id==0x1c3) D_L07_002EDE28[i].enabled=1;
            else {
                D_L07_002EDE28[i].enabled=D_00142693[0]!=0;
                D_L07_002EDE28[i].enabled=func_L01_0041A4F0();
            }
            break;
        }
        i++;
    }
}
/* localdecomp:end func_L07_0049AA38 */
