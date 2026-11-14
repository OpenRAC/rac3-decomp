#include "common.h"

/* localdecomp:start func_L39_005E0328 */
extern s32 D_001D8268_sda;
extern u8 D_001D826C_sda;
__asm__(".extern D_001D8268_sda, 4");
__asm__(".extern D_001D826C_sda, 1");
extern s32 *D_L39_002412A0;
extern s32 D_001A5F78[];
typedef struct { s32 duration, start; } Timer_005E0328;
extern Timer_005E0328 D_L39_00352A40[];
extern char D_L39_00243B08[];
extern char D_L39_00243B18[];
extern char D_L39_00243B00[];
extern char D_L39_0024C6E0;
extern s32 func_L01_00512AB0(s32,s32,s32);
extern void *func_L01_00478C58(s32);
extern s32 func_L39_0060DD90(void *);
extern s32 func_00120048(char *,char *,char *,s32,char *,s32);
extern void func_L01_00512FE8(s32,char *);
void func_L39_005E0328(void) {
    s32 remaining,minutes,seconds,elapsed;
    char *format, *mp, *sp;
    if(D_001D8268_sda) {
        if(2==*D_L39_002412A0) {
            func_L01_00512AB0(0x40002,1,0);
            func_L01_00512AB0(0x40001,1,0);
            func_L01_00512AB0(0x40005,1,1);
            func_L01_00512AB0(0x40006,1,1);
            func_L01_00512AB0(0x40007,1,1);
            func_L01_00512AB0(0x40008,1,1);
            func_L01_00512AB0(0x40009,1,1);
            func_L01_00512AB0(0x40003,1,1);
            func_L01_00512AB0(0x40004,1,1);
        } else {
            func_L01_00512AB0(0x40002,1,1);
            func_L01_00512AB0(0x40001,1,1);
            func_L01_00512AB0(0x40005,1,0);
            func_L01_00512AB0(0x40006,1,0);
            func_L01_00512AB0(0x40007,1,0);
            func_L01_00512AB0(0x40008,1,0);
            func_L01_00512AB0(0x40009,1,0);
            func_L01_00512AB0(0x40003,1,0);
            func_L01_00512AB0(0x40004,1,0);
        }
        D_001D8268_sda--;
    } else {
        func_L01_00512AB0(0x40000,1,0);
        D_001D826C_sda=1;
    }
    if(!D_001D826C_sda && func_L39_0060DD90(func_L01_00478C58(0))==1) {
        elapsed=*D_001A5F78-D_L39_00352A40->start;
        remaining=D_L39_00352A40->duration-elapsed;
        if(remaining<0) remaining=0;
        minutes=remaining/60000;
        seconds=(remaining%60000)/1000;
        format=D_L39_00243B08;
        mp=minutes<10?D_L39_00243B18:D_L39_00243B00;
        sp=seconds<10?D_L39_00243B18:D_L39_00243B00;
        func_00120048(&D_L39_0024C6E0,format,mp,minutes,sp,seconds);
        func_L01_00512FE8(0x4000B,&D_L39_0024C6E0);
    }
}
/* localdecomp:end func_L39_005E0328 */
