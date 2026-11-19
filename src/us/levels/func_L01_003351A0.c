#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef int u128_t __attribute__((mode(TI)));
typedef struct {
    u8 pad[148];
    u8 *(*fn)(u8 *);
} Vt00335B98;
typedef void (*Fn_335C70)(u8 *);
typedef struct {
    u8 pad[0x1E];
    u16 flags;
} Obj_003378A0;


/* localdecomp:start func_L01_003351A0 */
s32 func_L01_003351A0(u8 *a, u8 *b, u8 *m, u8 *d, s32 value, u8 *cfg, u8 *vt)
{
    extern void func_L01_00334198(u8 *, u8 *);
    extern f32 func_L01_0040BFE8(void *, void *);
    extern void func_L01_00333D30(void *, void *, f32);
    extern s32 func_L01_00457440(u8 *, void *);
    u128_t target;
    func_L01_00334198(m,d);
    target=*(u128_t *)(*(u8 **)(d+0x440)+0x10);
    if (func_L01_0040BFE8(d+0x410,&target)>1.0f ||
        func_L01_0040BFE8(m+0x10,d+0x3f0)<0.75f ||
        func_L01_0040BFE8(m+0x10,b+0x80)>4.0f) {
        u8 *t=*(u8 **)(d+0x440);
        *(u128_t *)(d+0x3f0)=*(u128_t *)(t+0x10);
        *(u128_t *)(d+0x410)=*(u128_t *)(t+0x10);
        func_L01_00333D30(m,d,12.0f);
        *(u128_t *)(b+0x80)=*(u128_t *)(m+0x10);
        *(s32 *)(d+0x430)=0;
    }
    func_L01_00457440(m,d+0x3f0);
    *(u128_t *)(d+0x400)=*(u128_t *)(*(u8 **)(d+0x440)+0x10);
    if (cfg[0x97]==0) (*(void (**)(u8 *,s32,s32))(vt+0x24))(m,0,10);
    else (*(void (**)(u8 *,s32,s32))(vt+0x20))(m,0,10);
    return 0;
}
/* localdecomp:end func_L01_003351A0 */
