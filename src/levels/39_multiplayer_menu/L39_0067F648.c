#include "common.h"

typedef struct S_0067EF00 {
    s32 f0;
    s32 f4;
    s32 f8;
} S_0067EF00;

/* localdecomp:start func_L39_0067F648 */
typedef struct E_0067F648 { char b[0x70]; } E_0067F648;
extern s32 D_L39_0024D770;
extern s32 D_L39_0024D7A8;
extern void *D_L39_0024D778;
extern E_0067F648 D_L39_003D2140[12];
char *func_00120D28(char *, const char *, s32);

void func_L39_0067F648(void *arg0, const char *arg1) {
    if (D_L39_0024D770 < 12) {
        (&D_L39_0024D778)[D_L39_0024D770] = arg0;
        func_00120D28(D_L39_003D2140[D_L39_0024D770].b, arg1, 0x6F);
        D_L39_003D2140[D_L39_0024D770].b[0x6F] = 0;
        D_L39_0024D770++;
        D_L39_0024D7A8++;
    }
}
/* localdecomp:end func_L39_0067F648 */

/* localdecomp:start func_L39_0067F6E8 */
/* reuses the file's E_0067F648 / D_L39_003D2140 / func_00120D28 declarations */
extern s32 D_L39_0024D770;
extern void *D_L39_0024D778;
extern s32 D_L39_0024D7A8;
extern s32 D_001E205C_sda;

void func_L39_0067F6E8(void **arg0, E_0067F648 *arg1) {
    s32 i;

    if (D_L39_0024D770 > 0) {
        D_L39_0024D7A8 = 0;
        D_L39_0024D770 = D_L39_0024D770 - 1;
        D_001E205C_sda = 0;
        if (arg0 != 0) {
            *arg0 = D_L39_0024D778;
        }
        func_00120D28(arg1->b, D_L39_003D2140[0].b, 0x6F);
        arg1->b[0x6F] = 0;
        for (i = 0; i < 11; i++) {
            func_00120D28(D_L39_003D2140[i].b, D_L39_003D2140[i + 1].b, 0x6F);
            D_L39_003D2140[i].b[0x6F] = 0;
        }
    }
}
/* localdecomp:end func_L39_0067F6E8 */

/* localdecomp:start func_L39_0067F7B0 */
/* reuses the file's E_0067F648 / D_L39_003D2140 / func_00120D28 declarations */
extern s32 D_L39_0024D770;
extern u8 D_L39_002473A8 __attribute__((section(".data")));

void func_L39_0067F7B0(void) {
    s32 i;

    for (i = 0; i < D_L39_0024D770; i++) {
        if ((u8)D_L39_003D2140[i].b[0] == 0x56) {
            if (i < D_L39_0024D770 - 1) {
                func_00120D28(D_L39_003D2140[i].b, D_L39_003D2140[i + 1].b, 0x6F);
                D_L39_003D2140[i].b[0x6F] = 0;
            } else {
                D_L39_003D2140[i].b[0] = D_L39_002473A8;
            }
            D_L39_0024D770--;
            i--;
        }
    }
}
/* localdecomp:end func_L39_0067F7B0 */
