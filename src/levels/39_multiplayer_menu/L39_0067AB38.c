#include "common.h"

typedef struct { int a, b, c; } T;

/* declared by functions of L39_0067A788.c, which this file was cut from */
void func_L01_004126A8(s32);

/* localdecomp:start func_L39_0067AB38 */
__asm__(".extern D_L39_0024D0C0, 16");
__asm__(".extern D_L39_0024D0F4, 16");
extern s32 D_L39_0024D0C0;
extern s32 D_L39_0024D0F4;
extern s32 D_001E19B0_sda;
extern int func_00126150(void);
extern int func_001260F0(int arg0, int arg1);
extern void func_L39_004B3B18(void);
extern void func_L01_004126A8(s32);
extern void func_L39_006121B0(s32);
extern s32 func_003B43B0(s32);
extern void func_L39_005DBEE8(s32, s32, s32);
extern void func_L39_00681470(void);
extern void func_L39_005C1A60(s32, s32, s32);

void func_L39_0067AB38(void) {
    s32 v;

    if (D_L39_0024D0C0 > 0) {
        func_L39_004B3B18();
    }
    v = func_00126150();
    func_L01_004126A8(v);
    func_001260F0(v, D_L39_0024D0F4);
    D_001E19B0_sda = 0;
    func_L39_006121B0(1);
    func_L39_005DBEE8(func_003B43B0(1), 0, 0);
    func_L39_00681470();
    func_L39_005C1A60(0, 0, 0x400);
}
/* localdecomp:end func_L39_0067AB38 */

INCLUDE_ASM("asm/levels", func_L39_0067ABC8);
