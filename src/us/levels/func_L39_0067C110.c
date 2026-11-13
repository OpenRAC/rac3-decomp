#include "common.h"

/* NTSC-U counterpart of func_L39_0067EC30 (src/levels/39_multiplayer_menu/L39_0067CE08.c) */
/* localdecomp:start func_L39_0067C110 */
typedef struct S_0067EC30 {
    u8 pad0[2];
    u16 count;
    u8 pad4[0xAC];
} S_0067EC30;

extern int D_001A5E50[];
typedef struct S_0067EC30_D { int a; u8 pad[0x14]; } S_0067EC30_D;
__asm__(".extern D_L39_0024D258_0067C110, 16");
extern int D_L39_0024D258_0067C110;
extern int D_001E19C8_sda;
extern void *func_0011D534(void *, s32, s32);
extern int func_00191788(int, void *);
extern void func_00190FE0(int, int *);
extern int func_00191100(int, S_0067EC30 *);
extern void func_00191348(int, S_0067EC30 *, int *);
extern void func_00191968(int, void *);
extern int func_001918A8(int);

int func_L39_0067C110(void) {
    u8 buf[0x20];
    u8 info[0x10];
    S_0067EC30 st;
    int n;

    func_0011D534(&D_L39_0024D258_0067C110, 0, 0x18);
    if (D_001A5E50[4] == -1) {
        if (func_00191788(0, info) == 0) {
            func_00190FE0(0, &D_001A5E50[4]);
        }
    } else if (func_00191100(D_001A5E50[4], &st) == 0) {
        if (st.count != 0) {
            func_00191348(D_001A5E50[4], &st, &D_L39_0024D258_0067C110);
            for (n = 0; n < st.count; n++) {
            }
            func_00191968(D_001A5E50[4], buf);
        }
    } else {
        func_001918A8(D_001A5E50[4]);
        D_001A5E50[4] = -1;
        return D_L39_0024D258_0067C110;
    }
    return D_001E19C8_sda;
}
/* localdecomp:end func_L39_0067C110 */
