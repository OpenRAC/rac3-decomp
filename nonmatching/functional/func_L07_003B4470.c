/* functional: high. From the PAL near-miss draft; whole loop re-read against PAL asm (6 iterations, i%3 table at gp+0x1BB8, 0.75 and +-0.25 factors, quaternion renormalise with 1/sqrt). Signature changed to (void*, void*) to match the file's earlier declaration (draft's typed pointers conflicted). Uses vu0.h vec_add_ab/vec_sub_ab/sqrt_asm as the file does. 14 diff = saved-register swap. */
#include "vu0.h"
__asm__(".extern D_001DE468_sda, 4");
extern f32 D_001DE468_sda;
void func_L07_003B4470(void *obj_, void *ref_) {
    u8 *obj = obj_;
    vu0_v4 *ref = ref_;
    extern void func_003CA4A0(void *, s32, s32 *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_0038D000(void *, void *, void *);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038CEA8(void *);
    extern void func_003C4840(void *, void *, f32);
    extern void func_0038D688(void *, void *, void *);
    vu0_v4 sum, diff;
    vu0_v4 matrix[4];
    vu0_v4 quat;
    s32 joint;
    s32 *jointp=&joint;
    vu0_v4 *row3=&matrix[3];
    vu0_v4 *matp=matrix;
    u8 *p = *(u8 **)(obj+0x68);
    u8 *q=p+0x1C0;
    vu0_v4 *out=(vu0_v4 *)(p+0x330);
    s32 i=0;
    f32 angle, length, scale;
    do {
        f32 size=*(f32 *)(obj+0x2C);
        size*=0.0009765625f;
        joint=i;
        func_003CA4A0(obj,1,jointp,matp);
        func_0038CE20(&sum,row3,size);
        func_0038D000(&sum,&sum,obj+0xC0);
        vec_add_ab(&sum,&sum,obj+0x10);
        *out=sum;
        vec_sub_ab(&diff,&sum,ref);
        angle=func_0038CE68(&diff,obj+0xC0)/(&D_001DE468_sda)[i%3]*0.75f;
        length=func_0038CEA8(&diff);
        func_003C4840(&quat,&matrix[1],-(angle+(angle<0.0f ? length * -0.25f : length * 0.25f)));
        func_0038D688(q,q,&quat);
        scale=1.0f/sqrt_asm(func_0038CE68(q,q)+*(f32 *)(q+12)**(f32 *)(q+12));
        func_0038CE20(q,q,scale);
        *(f32 *)(q+12) *= scale;
        i++; ref++; out++; q+=0x40;
    }while(i<6);
}
