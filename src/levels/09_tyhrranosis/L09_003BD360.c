#include "common.h"
#include "vu0.h"

typedef int u128_t __attribute__((mode(TI)));

/* localdecomp:start func_L09_003BD360 */
extern u8 *D_L09_0021E640[];
__asm__(".extern D_L09_0021E640, 16");

s32 func_L09_003BD360(s32 a0, s32 a1, s8 *a2, s32 *a3) {
    u8 *p1;
    u8 *p2;
    f32 d;
    p1 = D_L09_0021E640[a3[a0]] + (a1 << 4);
    p2 = D_L09_0021E640[a3[a2[2]]] + (a2[3] << 4);
    d = fabs_asm(*(f32 *)(p1 + 0x10) - *(f32 *)(p2 + 0x10));
    d = d + fabs_asm(*(f32 *)(p1 + 0x14) - *(f32 *)(p2 + 0x14));
    return (s32)d;
}
/* localdecomp:end func_L09_003BD360 */

/* localdecomp:start func_L09_003BD3E8 */
typedef struct {
    s8 b[8];
} S_003BD3E8;

extern S_003BD3E8 D_L09_002A29E0[];

void func_L09_003BD3E8(s8 *a0, S_003BD3E8 *a1, S_003BD3E8 *a2) {
    S_003BD3E8 tmp;
    s32 i;
    s32 j;

    for (i = 0; i < 10; i++) {
        if (a1[i].b[1] == a0[2] && a1[i].b[3] == a0[3]) {
            tmp = a1[i];
            break;
        }
    }
    for (j = 0; j < 10; j++) {
        if (tmp.b[2] == -1 && tmp.b[4] != -1) {
            break;
        }
        D_L09_002A29E0[j] = tmp;
        if (tmp.b[4] == -1) {
            break;
        }
        for (i = 0; i < 10; i++) {
            if (a1[i].b[0] == tmp.b[4]) {
                tmp = a1[i];
                break;
            }
            if (a2[i].b[0] == tmp.b[4]) {
                tmp = a2[i];
                break;
            }
        }
    }
}
/* localdecomp:end func_L09_003BD3E8 */
