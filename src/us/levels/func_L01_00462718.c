#include "common.h"

/* NTSC-U counterpart of func_L01_00465CD0 (src/levels/shared/L01_00465878.c): 5 -> 6; 75 -> 90; 125 -> 150 */
#include "vu0.h"
typedef int s128 __attribute__((mode(TI)));
extern f32 D_L01_001DFBCC;

/* localdecomp:start func_L01_00462718 */
typedef struct { f32 f[4]; } Gravity_00465CD0;
extern Gravity_00465CD0 D_L01_001D7F00_00462718;
extern f32 D_L01_001DFBCC;
extern vu0_v4 D_L01_001E2A40_00462718;
__asm__(".extern D_L01_001DFBCC,4");
void func_L01_00462718(u8 *p)
{
    extern s32 func_003883C8(u8 *);
    extern void func_003C7CE0(u8 *);
    extern s32 func_L01_00444338_00462718(s32,s32,f32);
    extern f32 func_003887C8(void *,void *);
    extern f32 func_0037E250(f32,f32);
    extern s32 func_0037E208(s32,s32);
    extern u8 *func_L01_00462578(s128 *,s128 *,s32,s32,f32,s32,s32);
    struct { vu0_q pos; Gravity_00465CD0 gravity; } temp;
    u8 *s=p+0x20;
    s32 alpha,color,end;
    f32 distance,size;
    temp.gravity=D_L01_001D7F00_00462718;
    if(*(s16 *)(s+0x1a)==3 && D_L01_001DFBCC>0.95f) func_003883C8(p+0xa);
    if(func_003883C8(p+0xa)) goto destroy;
    *(s32 *)(p+4)=func_L01_00444338_00462718(*(s32 *)(s+0x14),*(s32 *)(s+0x10),(f32)*(s16 *)(p+0xa)/(f32)*(s16 *)(s+0x18));
    alpha=*(s32 *)(p+4)>>24;
    distance=func_003887C8(p+0x10,&D_L01_001E2A40_00462718);
    if(*(s16 *)(p+0xa)<6) alpha=alpha**(s16 *)(p+0xa)/6;
    if(distance<4.0f) goto destroy;
    if(distance<8.0f) alpha=(s32)((f32)alpha*(distance-4.0f)*0.25f);
    *(s32 *)(p+4)=(alpha<<24)|(*(s32 *)(p+4)&0xffffff);
    vec_add_ab(p+0x10,p+0x10,s);
    *(f32 *)(s+8)-=temp.gravity.f[*(s16 *)(s+0x1a)];
    temp.pos=*(vu0_q *)(p+0x10);
    if(*(f32 *)(p+0x18)<*(f32 *)(s+0xc)) {
        if(*(s16 *)(s+0x1a)==1) {
            color=func_L01_00444338_00462718(0x7f000000,0x7f182030,func_0037E250(0.25f,1.0f));
            end=func_L01_00444338_00462718(0,0x5f5f5f,func_0037E250(0.5f,1.0f));
            *(f32 *)(s+8)=0.0f;
            size=func_0037E250(200000.0f,300000.0f);
            { s32 life=func_0037E208(90,150);
            func_L01_00462578((s128 *)(p+0x10),(s128 *)s,color,end,size,life,3); }
        }
        goto destroy;
    }
    goto moved;
destroy:
    func_003C7CE0(p);
    goto done;
moved:
    p[8]++;
done:;
}
/* localdecomp:end func_L01_00462718 */
