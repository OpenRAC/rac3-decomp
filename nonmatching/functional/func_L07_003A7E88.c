/* functional: high. Same values; constants from sdata pool instead of inline. */
#include "common.h"
/* localdecomp:start func_L07_003A7E88 */
typedef int Q_003A7E88 __attribute__((mode(TI)));
extern s32 D_001DE3E8_sda;
extern s32 D_001DE3EC_sda;
void func_L07_003A7E88(u8 *o) {
    extern void func_L07_003A8538(void *,void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern void func_L07_003A80A0(void *,s32,s32,s32,s32,s32,f32,f32);
    Q_003A7E88 a,b;
    Q_003A7E88 *p;
    u8 *s;
    s32 i;
    f32 x,y;
    if (o == 0 || o[0x20] == 0xFE || o[0x20] == 0xFD) return;
    s = *(u8 **)(o+0x68);
    *(f32 *)(s+0x2B0) += 0.1f;
    if (*(f32 *)(s+0x2B0) >= 4.0f) *(f32 *)(s+0x2B0) -= 4.0f;
    p = (Q_003A7E88 *)(s+0x10);
    i=18;
    do {
        a=p[-1];
        b=p[0];
        p++;
        func_L07_003A8538(o,&a,&b);
    } while (--i >= 0);
    x=func_003824E0(0.03f,0.05f);
    y=func_003824E0(3.0f,5.0f);
    if (o[0x95] == 1) {
        x=func_003824E0(0.05f,0.07f);
        y=func_003824E0(3.0f,5.0f);
    }
    func_L07_003A80A0(s,19,79,D_001DE3E8_sda,D_001DE3EC_sda,0,x,y);
}
/* localdecomp:end func_L07_003A7E88 */
