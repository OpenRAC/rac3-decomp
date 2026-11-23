/* functional: high. 23 diff at default flags (r/g saved FPU register swap only); draft re-read against PAL asm */
/* localdecomp:start func_L01_004670C8 */
extern u8 *D_001A71A0[];
extern vu0_q D_L01_001EAA20[];
extern s32 D_L01_001D673C;
__asm__(".extern D_L01_001D673C, 16");
void func_L01_004670C8(u8 *self) {
    extern void func_L01_004CAB30(void *, void *);
    extern s32 func_003D3CB0(void *, void *, s32, void *, s32);
    extern void func_003C5180(void *, void *, s32);
    extern void func_0038CE20(void *, void *, f32);
    extern s32 func_0038CB00(u8 *);
    extern void func_003CD250(u8 *);
    extern u32 func_L01_00448CC0(f32, f32, f32, f32);
    vu0_v4 next, normal;
    Spark_466F50 *spark;
    f32 g,r,b;
    s32 negative;
    if(self==0) return;
    spark=(Spark_466F50 *)(self+0x20);
    r=spark->red_fade; g=spark->green_fade; b=spark->blue_fade;
    negative=0;
    if(r<0.0f || g<0.0f || b<0.0f) {
        g=-g; negative=1; r=-r; b=-b;
    }
    func_L01_004CAB30(self+0x10,self+0x10);
    *(f32 *)(self+0x18)-=spark->velocity.w;
    spark->alpha+=0.0f;
    *(f32 *)(self+0xC)+=-120.00000762939453f;
    vec_add_ab(&next,self+0x10,&spark->velocity);
    if(spark->velocity.x!=0.0f || spark->velocity.y!=0.0f || spark->velocity.z!=0.0f) {
        if(func_003D3CB0(self+0x10,&next,6,D_001A71A0[0],0)) {
            *(vu0_q *)(self+0x10)=D_L01_001EAA20[0];
            qzero(&spark->velocity);
            *(f32 *)(self+0xC)=*(f32 *)(self+0xC)+*(f32 *)(self+0xC);
        } else {
            *(Vec_466F50 *)(self+0x10)=*(Vec_466F50 *)&next;
            if(D_L01_001D673C) {
                f32 gravity;
                vu0_v4 *n=&normal;
                func_003C5180(self+0x10,n,0);
                gravity=spark->velocity.w;
                if(gravity!=0.0f) gravity=-gravity;
                else gravity=0.00907200016f;
                func_0038CE20(&normal,n,gravity);
                vec_add_ab(&spark->velocity,&spark->velocity,&normal);
            } else {
                if(spark->velocity.w!=0.0f) spark->velocity.z=spark->velocity.z+spark->velocity.w;
                else spark->velocity.z=spark->velocity.z+-0.00907200016f;
            }
        }
    }
    if(spark->alpha<=0.0f || func_0038CB00(self+0xA) || *(f32 *)(self+0xC)<0.0f || next.x<0.01f || next.y<0.01f || next.z<0.01f) {
        func_003CD250(self);
        return;
    }
    if(!negative) {
        r+=-0.012f;
        if(r<0.0f) r=0.0f;
        g+=-0.0360120013f;
        if(g<0.0f) g=0.0f;
    } else {
        g+=-0.012f;
        if(g<0.0f) g=0.0f;
        r+=-0.0360120013f;
        if(r<0.0f) r=0.0f;
    }
    b+=-0.0600000024f;
    if(b<0.0f) b=0.0f;
    spark->alpha+=0.0f;
    if(spark->alpha<0.0f) spark->alpha=0.0f;
    *(u32 *)(self+4)=func_L01_00448CC0(r,g,b,spark->alpha);
    if(negative>0) {
        spark->red_fade=-r; spark->green_fade=-g; spark->blue_fade=-b;
    } else {
        spark->red_fade=r; spark->green_fade=g; spark->blue_fade=b;
    }
    self[8]--;
}
/* localdecomp:end func_L01_004670C8 */
