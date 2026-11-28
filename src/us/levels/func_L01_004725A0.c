#include "common.h"
/* localdecomp:start func_L01_004725A0 */
#include "vu0.h"
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00475DC8;
extern s32 D_L01_001D673C;
void func_L01_004725A0(u8 *p)
{
    extern s32 func_003883C8(void *);
    extern void func_003C7CE0(u8 *);
    extern s32 func_003894A0(s32,s32,f32);
    extern void func_L01_004C6EC8(void *,void *);
    extern void func_L01_004C41E8(void *,void *);
    extern void func_00388830(void *,void *,f32);
    u8 *s;
    u8 *pos;
    V_00475DC8 v;
    if (func_003883C8(p+10)) {
        func_003C7CE0(p);
        return;
    }
    s=p+32;
    pos=p+16;
    *(s32 *)(p+4)=func_003894A0(*(s32 *)(s+28),*(s32 *)(s+24),(f32)*(s16 *)(p+10)**(f32 *)(s+12));
    vec_add_ab(p+16, p+16, s);
    func_L01_004C6EC8(pos,pos);
    if (!D_L01_001D673C) {
        *(f32 *)(s+8)-=(f32)*(s16 *)(s+22)*0.0078125f*0.000277777785f;
    } else {
        func_L01_004C41E8(pos,&v);
        func_00388830(&v,&v,-((f32)*(s16 *)(s+22)*0.0078125f*0.000277777785f));
        vec_add_ab(p+16, p+16, &v);
    }
    p[8]+=s[20];
    *(f32 *)(p+12)+=*(f32 *)(s+16);
}
/* localdecomp:end func_L01_004725A0 */
