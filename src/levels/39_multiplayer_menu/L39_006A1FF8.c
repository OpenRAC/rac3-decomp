#include "common.h"

typedef struct { char pad[0x70]; char *f70; } T;

/* localdecomp:start func_L39_006A1FF8 */
__asm__(".extern D_L39_0024D760, 16");
extern void func_L39_0067F168();
extern void func_L39_0068ADC8(void *p);
extern T *D_L39_0024D760;

void func_L39_006A1FF8(void *owner) {
    D_L39_0024D760->f70[0x10] = 0;
    func_L39_0067F168();
    func_L39_0068ADC8(owner);
}
/* localdecomp:end func_L39_006A1FF8 */

/* localdecomp:start func_L39_006A2038 */
typedef struct O_006A2038 O_006A2038;
typedef struct {
    u8 pad0[0x1C];
    s32 (*f1C)(O_006A2038 *, s32, s32);
    u8 pad20[0xB4 - 0x20];
    void (*fB4)(O_006A2038 *);
    void (*fB8)(O_006A2038 *, s32);
} V_006A2038;
struct O_006A2038 { u8 pad[0x60]; V_006A2038 *vt; };
typedef struct {
    u8 pad0[0x110];
    O_006A2038 *f110[13];
    u8 pad144[0x2B4 - 0x144];
    s32 f2B4;
} S_006A2038;
extern s32 func_00381FF0(s32);

void func_L39_006A2038(S_006A2038 *arg0) {
    s32 i;
    if (arg0->f2B4 > 0) {
        arg0->f110[3]->vt->fB4(arg0->f110[3]);
    } else {
        arg0->f110[3]->vt->fB8(arg0->f110[3], func_00381FF0(0xFBF));
    }
    for (i = 0; i < 4; i++) {
        if (arg0->f2B4 < i + 1) {
            O_006A2038 *o = arg0->f110[i + 9];
            o->vt->f1C(o, 0, 0);
        } else {
            O_006A2038 *o = arg0->f110[i + 9];
            o->vt->f1C(o, 1, 0);
        }
    }
}
/* localdecomp:end func_L39_006A2038 */

/* localdecomp:start func_L39_006A2138 */
void func_L39_006CC8F0(void *, s32, s32, s32);
void func_L39_006A2138(u8 *arg0, long arg1, s32 arg2) {
    void *p;
    if (arg1 == 0) {
        p = arg0 + 0x10C4;
        *(void **)(arg0 + 0x1640) = p;
        *(s32 *)(arg0 + 0x2AC) = arg2;
        func_L39_006CC8F0(p, 0xD, 2, arg2);
    } else if (arg1 == 1) {
        p = arg0 + 0x1298;
        *(void **)(arg0 + 0x1640) = p;
        *(s32 *)(arg0 + 0x2AC) = arg2;
        func_L39_006CC8F0(p, 0xD, 2, arg2);
    } else if (arg1 == 2) {
        p = arg0 + 0x146C;
        *(void **)(arg0 + 0x1640) = p;
        *(s32 *)(arg0 + 0x2AC) = arg2;
        func_L39_006CC8F0(p, 0xD, 2, arg2);
    }
}
/* localdecomp:end func_L39_006A2138 */
