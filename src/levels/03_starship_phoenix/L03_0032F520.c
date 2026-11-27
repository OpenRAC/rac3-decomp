#include "common.h"

/* localdecomp:start func_L03_0032F520 */
typedef struct { char pad[0x84]; unsigned short v; char pad2[0xF0-0x86]; } S_0032F520;
extern unsigned char D_001426E0[];
extern unsigned char D_00142CA0[];
extern unsigned char D_00142D40[];
extern unsigned char D_001425C0[];
extern int D_001427F0[];
extern S_0032F520 D_L03_002C49C0[1];
void func_0039EF28(void);
void func_L03_0040F9E8(int a);
void func_L03_004F54E0(int a);
void func_L03_0035AD98(void);
s32 func_L01_0044CD60(int a);
s32 func_L01_00419248(int a);
void func_L03_0032F520(void) {
    int i = D_001426E0[0xD6];
    if (i != 0) {
        D_00142CA0[i] = 0;
        D_00142D40[i] = 0;
        func_0039EF28();
        func_L03_0040F9E8(i);
        func_L03_004F54E0(i);
        if (((S_0032F520 *)D_L03_002C49C0)[D_001425C0[i]].v != 0) {
            D_001427F0[i] = 0;
        } else if (i == 0x87) {
            func_L03_0035AD98();
        }
        func_L01_0044CD60(9);
        func_L01_00419248(i);
    }
    D_001426E0[0xD6] = 0;
}
/* localdecomp:end func_L03_0032F520 */
