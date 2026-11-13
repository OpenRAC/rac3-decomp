#include "common.h"

typedef struct {
    u8 *base;
    s32 count;
    s32 pad[2];
} E_004AD678;
extern E_004AD678 D_L01_0023B2E0[];

/* localdecomp:start func_L01_004B1160 */
extern int func_0011F1E0(int *dma, int flag);
/* from rac2-decomp's func_002EEE50 */
int func_L01_004B1160(int tag, unsigned int index, int start, int count)
{
    int request[4];
    if (index >= 64 || D_L01_0023B2E0[index].count == 0)
        return -3;
    if (D_L01_0023B2E0[index].count < start + count)
        return -1;
    request[0] = tag;
    request[1] = (int)(D_L01_0023B2E0[index].base + start * 16);
    request[2] = count * 16;
    request[3] = 0;
    func_0011F1E0(request, 1);
    return 0;
}
/* localdecomp:end func_L01_004B1160 */

/* localdecomp:start func_L01_004B11E0 */
extern s32 D_001D4B08;
extern s32 func_L01_004B12F0(u32);
extern s32 func_00122810(void *, s32, s32, u8 **, s32, u8 *, s32, s32, s32);
s32 func_L01_004B11E0(u8 *buf, u32 idx, s32 start, s32 n, s32 arg) {
    u8 *dst;
    s32 c;
    s32 sz;
    if (n == -1) {
        n = func_L01_004B12F0(idx);
    }
    if (idx >= 64 || D_L01_0023B2E0[idx].count == 0) {
        return -3;
    }
    if (D_L01_0023B2E0[idx].count < start + n) {
        return -1;
    }
    dst = D_L01_0023B2E0[idx].base + start * 16;
    while (n != 0) {
        c = n;
        if (c > 0xFFFF) {
            c = 0xFFFF;
        }
        sz = c * 16;
        func_00122810(&D_001D4B08, 1, arg, &dst, 16, buf, sz, 0, 0);
        n -= c;
        buf += sz;
        dst += sz;
    }
    return 0;
}
/* localdecomp:end func_L01_004B11E0 */

/* localdecomp:start func_L01_004B12F0 */
/* from rac2-decomp's func_002EEFE0 */
s32 func_L01_004B12F0(u32 arg0) {
    if (arg0 >= 0x40) {
        return -3;
    }
    return D_L01_0023B2E0[arg0].count;
}
/* localdecomp:end func_L01_004B12F0 */
