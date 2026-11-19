/* functional: high. control flow checked by reading asm; register allocation differs only */
#include "common.h"
/* localdecomp:start func_L01_004C4E60 */
extern T_4C1638 D_L01_002F1C20[];
extern char D_L01_001DAE40[];
extern s32 D_001DABD0_sda,D_001DABCC_sda;
extern u8 D_001DABC9_sda;
__asm__(".extern D_001DABD0_sda, 4");
__asm__(".extern D_001DABCC_sda, 4");
__asm__(".extern D_001DABC9_sda, 1");
void func_L01_004C4E60(void) {
    /* The current four-argument formatter prototype requires an unused zero.
       Retail passes three arguments; integration needs the variadic contract corrected. */
    extern char *func_003B9E30(s32,s32,s32);
    extern s32 func_L01_004BB0F0(s32);
    extern void func_L01_00498948(s32,s32,s32);
    s32 n=0,offset=0;
    u8 *base=(u8 *)D_L01_002F1C20;
    u8 *p=base;
    do {
        if (*(s32 *)(base+offset+8)!=255) {
            char *text=func_003B9E30(func_003B9BD0(0),0,n);
            func_0011B2E8(text,D_L01_001DAE40,func_00381FF0(*(s32 *)p),0);
            if(func_L01_004BB0F0(*(s32 *)(p+12)))func_L01_00498948(func_003B9BD0(0),n,0);
            else func_L01_00498948(func_003B9BD0(0),n,2);
            if(D_001DABD0_sda<5 && *(s32 *)(p+12)==-1) {
                D_001DABC9_sda=0;D_001DABCC_sda=0;
                func_L01_00498948(func_003B9BD0(0),n,3);
            }else if(*(s32 *)(p+12)==D_001DABD0_sda) {
                D_001DABCC_sda=*(s32 *)(p+12);D_001DABC9_sda=1;
                func_L01_00498948(func_003B9BD0(0),n,3);
            }
            n++;
        }
        p+=16;offset+=16;
    }while(p<base+0xA0);
}
/* localdecomp:end func_L01_004C4E60 */
