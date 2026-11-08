#include "common.h"

/* localdecomp:start func_L39_005A6020 */
extern unsigned char D_L39_002411E0[];
extern unsigned char D_L39_002411F8[];
extern unsigned char D_L39_00241210[];
extern unsigned char D_L39_00241228[];
extern unsigned char D_L39_00241248[];
extern unsigned char D_L39_00241268[];
extern unsigned char D_L39_00241298[];
extern unsigned char D_L39_002412B8[];
void func_00120D28(void *, void *, int);
void func_L39_005A6020(unsigned char *a) {
    int i;
    int v;
    func_00120D28(D_L39_002411E0, a + 8, 0x15);
    v = a[0x12];
    if (v == 0x45) {
        D_L39_002411F8[2] = v;
    } else if (v == 0x50) {
        D_L39_002411F8[2] = 0x49;
    } else if (v == 0x4B) {
        D_L39_002411F8[2] = v;
    }
    for (i = 3; i < 7; i++) D_L39_002411F8[i] = a[i + 0xD];
    for (i = 8; i < 11; i++) D_L39_002411F8[i] = a[i + 0xD];
    for (i = 11; i < 13; i++) D_L39_002411F8[i] = a[i + 0xE];
    func_00120D28(D_L39_00241210, D_L39_002411F8, 0xD);
    func_00120D28(D_L39_00241228, D_L39_002411F8, 0xD);
    func_00120D28(D_L39_00241248, D_L39_002411F8, 0xD);
    func_00120D28(D_L39_00241268, D_L39_002411F8, 0xD);
    func_00120D28(D_L39_00241268 + 0x14, D_L39_002411F8, 0xD);
    func_00120D28(D_L39_00241298, D_L39_002411F8, 0xD);
    func_00120D28(D_L39_002412B8, D_L39_002411F8, 0xD);
}
/* localdecomp:end func_L39_005A6020 */

LINKER_REMNANT("asm/levels", func_L39_005A61B0);
