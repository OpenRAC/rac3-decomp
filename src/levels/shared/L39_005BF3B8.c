#include "common.h"

LINKER_REMNANT("asm/levels", func_L39_005BF3B8);

/* localdecomp:start func_L39_005BF490 */
extern s32 D_L39_00241128;
__asm__(".extern D_L39_00241128, 16");
extern s32 D_L39_00242910;
__asm__(".extern D_L39_00242910, 16");
extern s32 D_L39_0024341C;
__asm__(".extern D_L39_0024341C, 16");
extern s32 D_L39_00243420;
__asm__(".extern D_L39_00243420, 16");
extern s32 D_L39_00243424;
__asm__(".extern D_L39_00243424, 16");
extern u8 *D_L39_0024342C;
__asm__(".extern D_L39_0024342C, 16");
extern s32 D_L39_00243D80;
__asm__(".extern D_L39_00243D80, 16");
extern s32 *D_L39_00241120;
__asm__(".extern D_L39_00241120, 16");
extern s32 D_L39_00242914;
__asm__(".extern D_L39_00242914, 16");
extern s32 D_L39_0024027C;
__asm__(".extern D_L39_0024027C, 16");
extern s32 D_L39_00240280;
__asm__(".extern D_L39_00240280, 16");
extern f32 D_L39_0025D770 __attribute__((section(".data")));
extern s32 D_L39_0025F6EC __attribute__((section(".data")));
extern s32 D_L39_0024290C;
__asm__(".extern D_L39_0024290C, 16");

extern void func_L39_00598720(void);
extern void func_L39_005FB8A8(void);
extern void func_00382810(s32, s32, s32, f32, f32, f32, f32);
extern void func_L39_005872D8(void);
extern void func_L01_004A3548(void);
extern void func_L01_004C97C8(void);
extern void func_L39_0067D658(void);
extern void func_L01_004800B8(void);
extern void func_L39_0067C8E8(void);
extern void func_L01_0047FDE8_005BF490(void);
extern void func_L39_0058A5D0(s32);
extern void func_L39_005F64F8(void);
extern void func_L01_0045A530(s32);
extern void func_L39_00598780(s32, s32);
extern void func_L39_005FB708(s32);
extern void func_L01_004A34A8(s32, s32);
extern void func_L01_0048EB88_005BF490(void);
extern void func_L39_0067CF68(void);
extern void func_L01_00480098(void);
extern void func_0038CBA0(void *, s32);
extern void func_L39_0067C408(void);
extern void func_003B3218();
extern void func_L01_0047E548_005BF490(void);

void func_L39_005BF490(void) {
    s32 state = D_L39_00241128;
    s32 next;
    u8 *p;

    D_L39_0024290C = state;
    if (D_L39_00242910 == -2) {
        return;
    }
    if (D_L39_0024341C > 0) {
        D_L39_0024341C--;
        return;
    }
    switch (state) {
    case 0:
        break;
    case 4:
        func_L39_00598720();
        break;
    case 1:
        func_L39_005FB8A8();
        D_L39_0025D770 = 0.62f;
        func_00382810(0, 0, 3, 1.1100293f, 0.005f, 0.2f, 0.0f);
        func_L39_005872D8();
        break;
    case 7:
        func_L01_004A3548();
        break;
    case 8:
        func_L01_004C97C8();
        break;
    case 11:
        func_L39_0067D658();
        break;
    case 10:
        func_L01_004800B8();
        break;
    case 12:
        func_L39_0067C8E8();
        break;
    case 9:
        func_L01_0047FDE8_005BF490();
        break;
    case 17:
        D_L39_00242914 = *D_L39_00241120 - 1;
        func_L39_0058A5D0(2);
        func_L39_005F64F8();
        break;
    case 18:
        break;
    }
    func_L01_0045A530(10);
    switch (D_L39_00242910) {
    case 0:
        break;
    case 4:
        func_L39_00598780(D_L39_00243420, D_L39_00243424);
        break;
    case 1:
        func_L39_005FB708(D_L39_00243424);
        break;
    case 7:
        {
            s32 d = D_L39_00243D80;
            func_L01_004A34A8(D_L39_00243420 == 0 ? d : D_L39_00243420, D_L39_00243424);
        }
        break;
    case 8:
        func_L01_0048EB88_005BF490();
        break;
    case 11:
        func_L39_0067CF68();
        break;
    case 10:
        func_L01_00480098();
        break;
    case 12:
        D_L39_00240280 = D_L39_0025F6EC;
        D_L39_0024027C = D_L39_0025F6EC - 0x300000;
        func_0038CBA0((void *)(D_L39_0025F6EC - 0x300000), 0x300000);
        func_L39_0067C408();
        break;
    case 18:
        func_003B3218(D_L39_00243420);
        break;
    case 9:
        func_L01_0047E548_005BF490();
        break;
    }
    p = D_L39_0024342C;
    if (p != 0) {
        *p = 1;
    }
    next = D_L39_00242910;
    D_L39_00242910 = -2;
    D_L39_00241128 = next;
    D_L39_0024342C = 0;
}
/* localdecomp:end func_L39_005BF490 */
