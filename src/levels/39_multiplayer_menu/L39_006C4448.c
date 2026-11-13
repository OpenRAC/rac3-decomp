#include "common.h"

/* localdecomp:start func_L39_006C4448 */
__asm__(".extern D_L39_00241640, 16");
__asm__(".extern D_L39_00241120, 16");


typedef struct {
    u8 pad[0xF0];
    void (*fF0)(void *);
} VT_006C4448;

extern u8 *D_L39_00241640;
extern s32 *D_L39_00241120;
extern s32 D_L39_002404C0;

extern s32 func_L39_006C45C8(void *, s32, void **);
extern void func_L39_0059A638(void *);
extern void func_L39_00689A70(void);
extern void func_L39_006C4148(void *);
extern void func_0019BF20(void);
extern void func_0019BEB8(s32);
extern void func_0019CA28(s32);
extern void func_L39_0059A578(s32, s32);

void func_L39_006C4448(u8 *obj) {
    void *buf;
    s32 i;
    s32 n;

    if (D_L39_00241640 == 0) {
        return;
    }
    for (i = 0; i < 8; i++) {
        if (func_L39_006C45C8(obj, i, &buf) != 0) {
            func_L39_0059A638(buf);
        }
    }
    (*(VT_006C4448 **)(obj + 0x60))->fF0(obj);
    func_L39_00689A70();
    func_L39_006C4148(obj);
    n = *(s16 *)(D_L39_00241640 + 0x17C);
    if (*D_L39_00241120 >= 2 && n <= 0x2D) {
        n += 10;
    }
    func_0019BF20();
    func_0019BEB8(0);
    if (*(s32 *)(D_L39_00241640 + 0x180) != 2) {
        func_0019CA28(0);
    }
    func_L39_0059A578(n, 0);
    D_L39_002404C0 = -1;
    {
        s32 j;
        s32 k;
        for (j = 0; j < 32 && D_L39_00241640 != 0; j++) {
            D_L39_002404C0 ^= D_L39_00241640[j];
            for (k = 7; k >= 0; k--) {
                if (D_L39_002404C0 & 1) {
                    D_L39_002404C0 = (D_L39_002404C0 >> 1) ^ 0xEDB88320;
                } else {
                    D_L39_002404C0 = D_L39_002404C0 >> 1;
                }
            }
        }
    }
}
/* localdecomp:end func_L39_006C4448 */
