#include "common.h"

typedef struct { u8 p0[8]; s32 w8; } Cfg_0058CE50;

/* localdecomp:start func_L39_0058CC68 */
typedef struct { u8 pad[0x1c]; int flags; short x, y, w, h; u8 tail[8]; } CopyRegion;
extern CopyRegion D_L39_0025D0A0[];
extern int D_L39_0024BA7C;
extern int D_L39_0024BA7C_sda;
extern int D_L39_0024CADC;
__asm__(".extern D_L39_0024BA7C, 16");
__asm__(".extern D_L39_0024CADC, 16");
extern u8 *D_L39_0024CAC8[];
extern void func_L39_005985D0(int, int, int, int, void *);
extern void func_001331A0(int, int);
extern void func_L39_0058CBC8(void *, int);

/* from rac2-decomp's func_00280710 */
void func_L39_0058CC68(void) {
    u8 *buffers[2];
    int current, next, i, index;
    if (D_L39_0024BA7C == 0) return;
    buffers[0] = D_L39_0024CAC8[1 - D_L39_0024CADC];
    buffers[1] = buffers[0] + 0x40000;
    current = 0;
    next = -1;
    for (i = 31; i >= 0; i--) {
        if (D_L39_0025D0A0[i].flags & 4) {
            next = i;
            func_L39_005985D0(D_L39_0025D0A0[i].x, D_L39_0025D0A0[i].y, D_L39_0025D0A0[i].w, D_L39_0025D0A0[i].h,
                          buffers[current]);
            func_001331A0(0, 0);
        }
    }
    if (next == -1) return;
    index = next;
    while (index >= 0) {
        current = 1 - current;
        next = -1;
        for (i = index - 1; i >= 0; i--) {
            if (D_L39_0025D0A0[i].flags & 4) {
                next = i;
                func_L39_005985D0(D_L39_0025D0A0[i].x, D_L39_0025D0A0[i].y, D_L39_0025D0A0[i].w, D_L39_0025D0A0[i].h,
                              buffers[current]);
            }
        }
        func_L39_0058CBC8(buffers[1 - current], index);
        if ((D_L39_0025D0A0 + index)->flags & 1) {
            (D_L39_0025D0A0 + index)->flags &= ~5;
            D_L39_0024BA7C = D_L39_0024BA7C_sda - 1;
        }
        if (next >= 0) func_001331A0(0, 0);
        index = next;
    }
}
/* localdecomp:end func_L39_0058CC68 */

/* localdecomp:start func_L39_0058CE50 */
extern Cfg_0058CE50 D_001FC450;
extern void func_003CE250(void);
extern void func_003CE1B0(void);
extern void func_003CE2C0(void);
extern void func_003A9440(s32, unsigned long);

void func_L39_0058CE50(void) {
    func_003CE250();
    func_003CE1B0();
    func_003CE2C0();
    func_003A9440(0x47, 0x5360B);
    func_003A9440(0x4E, 0x1000000 | (D_001FC450.w8 >> 13));
}
/* localdecomp:end func_L39_0058CE50 */
