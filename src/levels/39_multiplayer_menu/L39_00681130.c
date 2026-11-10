#include "common.h"

typedef struct S_00680198 {
    u8 pad[0x68];
    s32 f68;
    s32 f6C;
    s32 f70;
} S_00680198;

/* declared by functions of L39_0067FAE8.c, which this file was cut from */
s32 func_L01_00516AA0(s32, s32, s32);
s32 func_L01_005170B8(s32, s32);
extern s32 func_L01_00516AA0(s32, s32, s32);

/* localdecomp:start func_L39_00681130 */
void func_L39_00681330(void *);

void func_L39_00681130(void *arg0) {
    *(s32 *)((u8 *)arg0 + 0x64) = -1;
    *(s32 *)((u8 *)arg0 + 0x68) = -1;
    func_L39_00681330(arg0);
}
/* localdecomp:end func_L39_00681130 */

INCLUDE_ASM("asm/levels", func_L39_00681158);

INCLUDE_ASM("asm/levels", func_L39_00681330);

/* localdecomp:start func_L39_006813F8 */
__asm__(".extern D_L39_0024B9C8, 16");
__asm__(".extern D_L39_00247514, 16");
__asm__(".extern D_L39_0024CAD8, 16");
extern s32 D_L39_0025F680[];
extern s32 D_L39_0024B9C8;
extern s32 D_L39_00247514;
extern s32 D_L39_0024CAD8;
extern s32 D_001DBE00_sda;
extern s32 D_001DBE10_sda;
void func_003A92F0(s32);
void func_003A9108(void);
s32 func_00139E08(s32);

void func_L39_006813F8(void) {
    func_003A92F0(1);
    func_00139E08(0);
    D_L39_0024B9C8++;
    D_001DBE00_sda = D_L39_0025F680[3] + 0x80000;
    D_L39_00247514 = D_001DBE00_sda + 0x40000;
    D_001DBE10_sda = D_L39_0025F680[4] + 0x80000;
    D_L39_0024CAD8 = 0x80000;
    func_003A9108();
}
/* localdecomp:end func_L39_006813F8 */

INCLUDE_ASM("asm/levels", func_L39_00681470);

INCLUDE_ASM("asm/levels", func_L39_006814B0);

/* localdecomp:start func_L39_00681598 */
s32 func_L01_005170B8(s32, s32);

s32 func_L39_00681598(void *arg0, s32 arg1) {
    s32 *p;
    s32 *base;

    base = (s32 *)((u8 *)arg0 + 0x64);
    p = base + *(s32 *)((u8 *)arg0 + 0x74);
    if (*p == -1) {
        return 0;
    }
    *(s32 *)((u8 *)arg0 + 0x80) = arg1;
    return func_L01_005170B8(*p, arg1);
}
/* localdecomp:end func_L39_00681598 */

INCLUDE_ASM("asm/levels", func_L39_006815F0);

INCLUDE_ASM("asm/levels", func_L39_0068168C);
