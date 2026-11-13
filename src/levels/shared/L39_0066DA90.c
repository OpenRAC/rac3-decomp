#include "common.h"

/* declared by functions of L39_0066C808.c, which this file was cut from */
extern u8 *D_L39_00246330;
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern void func_L39_00662AA0(void *, void *, s32);

/* localdecomp:start func_L39_0066DA90 */
extern u8 *D_L39_00246330;
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern void func_L39_00662AA0(void *, void *, s32);

void func_L39_0066DA90(s32 *a0, s32 a1, u8 a2, u8 a3) {
    u8 b[2];
    s32 w;
    u32 *s;

    s = func_L39_006625A8((*(s32 *)&D_L39_00246330), 1, 0, 0);
    s[20] = a1;
    w = *a0;
    func_L39_00662AA0(s, &w, 4);
    b[0] = a2;
    func_L39_00662AA0(s, b, 1);
    b[0] = a3;
    func_L39_00662AA0(s, b, 1);
    a0[12] = s[1] + (s[0] >> 13);
}
/* localdecomp:end func_L39_0066DA90 */

/* localdecomp:start func_L39_0066DB50 */
extern u8 *D_L39_00246330;
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern void func_L39_00662AA0(void *, void *, s32);

void func_L39_0066DB50(s32 *a0, u8 a1, u8 a2, u8 a3) {
    u8 b[2];
    s32 w;
    u32 *s;

    s = func_L39_006625A8((*(s32 *)&D_L39_00246330), 3, 0, 0);
    s[20] = a0[18];
    w = *a0;
    func_L39_00662AA0(s, &w, 4);
    b[0] = a1;
    func_L39_00662AA0(s, b, 1);
    b[0] = a2;
    func_L39_00662AA0(s, b, 1);
    b[0] = a3;
    func_L39_00662AA0(s, b, 1);
    a0[12] = s[1] + (s[0] >> 13);
}
/* localdecomp:end func_L39_0066DB50 */

/* localdecomp:start func_L39_0066DC28 */
extern void func_L39_00662AA0(void *, void *, s32);
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern u8 *D_L39_00246330;
void func_L39_0066DC28(s32 *a, u8 b, u8 c) {
    u8 tmp[16];
    s32 w[4];
    s32 m = ((s32 (*)(s32, s32, s32, s32))func_L39_006625A8)((*(s32 *)&D_L39_00246330), 2, 0, 0);
    *(s32 *)(m + 80) = a[18];
    w[0] = a[0];
    ((void (*)(s32, void *, s32))func_L39_00662AA0)(m, w, 4);
    tmp[0] = b;
    ((void (*)(s32, void *, s32))func_L39_00662AA0)(m, tmp, 1);
    tmp[0] = c;
    ((void (*)(s32, void *, s32))func_L39_00662AA0)(m, tmp, 1);
}
/* localdecomp:end func_L39_0066DC28 */

/* localdecomp:start func_L39_0066DCC8 */
extern u32 *func_L39_006625A8(s32, s32, s32, s32);
extern s32 func_L39_0061D7B0(s32);
s32 func_L39_0066DCC8(s32 x, s32 a, s32 b, s32 c) {
    s32 p = func_L39_0061D7B0(x);
    s32 r;
    if (p == 0) {
        r = 0;
    } else {
        r = ((s32 (*)(s32, s32, s32, s32))func_L39_006625A8)(p, a, b, c);
    }
    return r;
}
/* localdecomp:end func_L39_0066DCC8 */
