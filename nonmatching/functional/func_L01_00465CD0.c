/* functional: high. 2 diff at default flags (mov.s f12,f20 vs move t0,v0 order before func_L01_00465B30); logic re-verified against PAL asm */
/* localdecomp:start func_L01_00465CD0 */
typedef struct { f32 f[4]; } Gravity_00465CD0;
extern Gravity_00465CD0 D_L01_001D7F00;
extern f32 D_001DFB4C_sda;
extern vu0_v4 D_L01_001E29C0;
__asm__(".extern D_001DFB4C_sda,4");
void func_L01_00465CD0(u8 *p)
{
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern s32 func_L01_00447470(s32,s32,f32);
    extern f32 func_0038CF00(void *,void *);
    extern f32 func_003824E0(f32,f32);
    extern s32 func_00382498(s32,s32);
    extern u8 *func_L01_00465B30(s128 *,s128 *,s32,s32,s32,s32,f32);
    struct { vu0_q pos; Gravity_00465CD0 gravity; } temp;
    u8 *s=p+0x20;
    s32 alpha,color,end;
    f32 distance,size;
    temp.gravity=D_L01_001D7F00;
    if(*(s16 *)(s+0x1a)==3 && D_001DFB4C_sda>0.95f) func_0038CB00(p+0xa);
    if(func_0038CB00(p+0xa)) goto destroy;
    *(s32 *)(p+4)=func_L01_00447470(*(s32 *)(s+0x14),*(s32 *)(s+0x10),(f32)*(s16 *)(p+0xa)/(f32)*(s16 *)(s+0x18));
    alpha=*(s32 *)(p+4)>>24;
    distance=func_0038CF00(p+0x10,&D_L01_001E29C0);
    if(*(s16 *)(p+0xa)<5) alpha=alpha**(s16 *)(p+0xa)/5;
    if(distance<4.0f) goto destroy;
    if(distance<8.0f) alpha=(s32)((f32)alpha*(distance-4.0f)*0.25f);
    *(s32 *)(p+4)=(alpha<<24)|(*(s32 *)(p+4)&0xffffff);
    vec_add_ab(p+0x10,p+0x10,s);
    *(f32 *)(s+8)-=temp.gravity.f[*(s16 *)(s+0x1a)];
    temp.pos=*(vu0_q *)(p+0x10);
    if(*(f32 *)(p+0x18)<*(f32 *)(s+0xc)) {
        if(*(s16 *)(s+0x1a)==1) {
            color=func_L01_00447470(0x7f000000,0x7f182030,func_003824E0(0.25f,1.0f));
            end=func_L01_00447470(0,0x5f5f5f,func_003824E0(0.5f,1.0f));
            *(f32 *)(s+8)=0.0f;
            size=func_003824E0(200000.0f,300000.0f);
            { s32 life=func_00382498(75,125);
            func_L01_00465B30((s128 *)(p+0x10),(s128 *)s,color,end,life,3,size); }
        }
        goto destroy;
    }
    goto moved;
destroy:
    func_003CD250(p);
    goto done;
moved:
    p[8]++;
done:;
}
/* localdecomp:end func_L01_00465CD0 */
