#include "common.h"

typedef void (*Fn_33CA98)(u8 *);

/* localdecomp:start func_L01_0033D0E8 */
extern void func_L01_004AA7E8(u8 *, s32);
extern void func_L01_00303658(u8 *);

void func_L01_0033D0E8(u8 *p) {
    u8 *q;
    u8 *m;

    *(s32 *)(p + 152) = 0;
    q = *(u8 **)(p + 104);
    *(u16 *)(p + 52) = (*(u16 *)(p + 52) | 0x41) & ~0x1000;
    func_L01_004AA7E8(p, 1);
    p[32] = 6;
    q[248] = 1;
    q[249] = 255;
    m = *(u8 **)(q + 300);
    if (m != 0) {
        if (*(s16 *)(m + 170) == 806) {
            func_L01_00303658(m);
        }
        *(u8 **)(q + 300) = 0;
    }
}
/* localdecomp:end func_L01_0033D0E8 */

LINKER_REMNANT("asm/levels", func_L01_0033D170);

/* localdecomp:start func_L01_0033D178 */
s32 func_L01_0033D178(u8 *obj) {
    return (u32)(obj[32] - 6) < 2;
}
/* localdecomp:end func_L01_0033D178 */

/* localdecomp:start func_L01_0033D188 */

extern Fn_33CA98 *func_L01_0043B548(s32, s32);
extern void func_L01_00303658(u8 *);
extern void func_003C2880(u8 *);

void func_L01_0033D188(u8 *m, s32 flag) {
    u8 *v = *(u8 **)(m + 104);
    Fn_33CA98 *t;
    u8 *o;

    if (*(s32 *)(v + 176) != 0) {
        t = func_L01_0043B548(6625, 108);
        o = *(u8 **)(v + 300);
        if (o != 0) {
            if (flag == 0) {
                if (*(s16 *)(o + 170) == 806) {
                    func_L01_00303658(o);
                }
            } else if (*(s32 *)(v + 176) == -2) {
                *(u8 **)(o + 184) = o;
            }
        }
        *(u8 **)(v + 300) = 0;
        *(f32 *)(v + 224) = 1.0f;
        *(s32 *)(v + 208) = 0;
        *(s32 *)(v + 212) = 0;
        *(s32 *)(v + 220) = 0;
        *(s32 *)(v + 228) = 0;
        v[249] = 0;
        v[250] = 0;
        *(s32 *)(v + 288) = 0;
        *(s32 *)(v + 292) = 0;
        *(s32 *)(v + 304) = 0;
        t[0](m);
        if (flag != 0 && *(s32 *)(v + 176) != -2) {
            t[1](m);
        }
    } else {
        func_003C2880(m);
    }
}
/* localdecomp:end func_L01_0033D188 */

/* localdecomp:start func_L01_0033D290 */
void func_L01_0033D290(void) {

}
/* localdecomp:end func_L01_0033D290 */

/* localdecomp:start func_L01_0033D298 */
extern void func_L01_0033D188_0033D298(u8 *m, s32 flag);
extern void func_L01_0033D298(void *p);
extern void func_L01_0033D298(void *);

 
void func_L01_0033D298(void *p) {
    ((void (*)(void *, s32))func_L01_0033D188_0033D298)(p, 0);
}
/* localdecomp:end func_L01_0033D298 */
