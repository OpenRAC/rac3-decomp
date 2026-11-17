#include "common.h"

/* declared by functions of L39_00677D08.c, which this file was cut from */
extern void func_L39_00589538(s32);
extern void func_00389370(void);

/* localdecomp:start func_L39_0067A4E0 */
/* log: */
typedef int u128_t __attribute__((mode(TI)));
__asm__(".extern D_00240300, 16");
extern s32 D_00240300;
__asm__(".extern D_00240304, 16");
extern s32 D_00240304;
extern s32 D_L39_0024D018;
extern s32 D_L39_0024D01C;
extern s32 D_L39_0024D020;
extern s32 D_L39_0024D024;
extern s32 D_L39_002466E8;
extern f32 D_L39_002466E4;
extern u8 D_L39_00352D10[];
extern u8 D_L39_0024DE20[];
extern void func_0038D308(void *, void *);
extern void func_003861F0(void);
extern void func_L39_00589538(s32);
extern void func_L39_006793D8(s32);
extern void func_L39_0058B1B8(s32, s32, s32, s32);
extern long func_L39_00589890(s32);
extern void func_0038B4D0(s32, s32, s32, s32, s32, s32, s32, s32, long, long);
extern void func_L39_00679B88(s32);
extern void func_L39_00679F08(void);
extern void func_L39_00679AE0(s32 *, s32 *);
extern void func_L39_006792F8(void);
extern void func_L39_00678A50(void);
extern void func_00389370(void);

void func_L39_0067A4E0(void) {
    func_0038D308(D_L39_0024DE20, D_L39_00352D10);
    *(u128_t *)(D_L39_0024DE20 - 0x20) = *(u128_t *)(D_L39_00352D10 - 0x10);
    func_003861F0();
    if (D_L39_0024D01C == 0) {
        D_L39_0024D01C = 1;
        D_L39_0024D018 = D_00240300 >> 1;
    }
    if (D_L39_0024D024 == 0) {
        D_L39_0024D024 = 1;
        D_L39_0024D020 = D_00240304 >> 1;
    }
    func_L39_00589538(1);
    func_L39_006793D8(*(s32 *)(D_L39_00352D10 - 0x24) + 0x1A);
    func_L39_0058B1B8(0, 0, 0, (s32)(D_L39_002466E4 * 128.0f));
    func_0038B4D0(0, 0, D_L39_0024D018, D_L39_0024D020, 0, D_L39_002466E8, 0x100, 0x100 - D_L39_002466E8, (s32)0x80808080, func_L39_00589890(0x18));
    func_0038B4D0(D_L39_0024D018, 0, D_L39_0024D018, D_L39_0024D020, 0, D_L39_002466E8, 0x100, 0x100 - D_L39_002466E8, (s32)0x80808080, func_L39_00589890(0x19));
    func_0038B4D0(0, D_L39_0024D020, D_L39_0024D018, D_L39_0024D020, 0, 0, 0x100, 0x100 - D_L39_002466E8, (s32)0x80808080, func_L39_00589890(0x16));
    func_0038B4D0(D_L39_0024D018, D_L39_0024D020, D_L39_0024D018, D_L39_0024D020, 0, 0, 0x100, 0x100 - D_L39_002466E8, (s32)0x80808080, func_L39_00589890(0x17));
    func_L39_00679B88(10);
    func_L39_00679F08();
    func_L39_00679AE0(&D_L39_0024D018, &D_L39_0024D020);
    func_L39_006792F8();
    func_L39_00678A50();
    func_00389370();
}
/* localdecomp:end func_L39_0067A4E0 */

/* localdecomp:start func_L39_0067A6D0 */
s32 func_L39_0067A6D0(s32 value) {
    s32 result = -1;
    switch (value) {
    case 3:
        result = 0;
        break;
    case 1:
        result = 1;
        break;
    case 2:
        result = 2;
        break;
    case 4:
        result = 3;
        break;
    case 5:
        result = 4;
        break;
    case 6:
        result = 5;
        break;
    case 9:
        result = 6;
        break;
    case 7:
        result = 7;
        break;
    case 10:
        result = 8;
        break;
    }
    return result;
}
/* localdecomp:end func_L39_0067A6D0 */
