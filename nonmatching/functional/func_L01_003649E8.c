/* functional: high. 128 words differ (VU0 scheduling, gp vs lui addressing, vector init); every branch, offset, float constant (0.1, 0.006) and loop count verified against asm; D_001A4BE0 accessed via a per-function alias name as other drafts do */
typedef int Q_003649E8 __attribute__((mode(TI)));
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_003649E8;
extern u8 D_001A4BE0_003649E8[];
extern s16 D_L01_001E1B10;
extern s32 D_L01_001DD774;
extern s32 D_L01_001DD778;
extern f32 D_L01_001DD784;
extern s32 D_L01_001DD788;
extern s32 D_L01_001DD78C;
extern f32 D_L01_001E1AE4[];
extern f32 D_L01_001E1AE0;
extern Q_003649E8 D_L01_001E29E0[3];
extern Q_003649E8 D_L01_0028E3A0[10];
extern Q_003649E8 D_L01_001E1AC0;
extern Q_003649E8 D_L01_001E1AD0;
extern u8 D_L01_0028CAA0[];
void func_L01_003649E8(u8 *obj, Q_003649E8 *pos) {
    extern void func_0038CE20(Q_003649E8 *, Q_003649E8 *, f32);
    extern void func_0038CF68(Q_003649E8 *, Q_003649E8 *, f32);
    extern f32 func_00382538(void);
    extern void func_0038D890(Q_003649E8 *, Q_003649E8 *, Q_003649E8 *, f32);
    Q_003649E8 basis[3];
    V_003649E8 step, forward, a, b;
    f32 r;
    s32 i;
    u8 *state;
    if (!D_L01_001DD774) return;
    state = D_001A4BE0_003649E8;
    D_L01_001E1AE4[0] = 1.0f;
    D_L01_001DD774 = 0;
    if ((*(s32 *)(state+0x25c4)==29 || *(s32 *)(state+0x25c4)==1) &&
        (*(u16 *)(*(u8 **)(state+0x25c0)+0x34) & 1)) {
        basis[0]=D_L01_001E29E0[0];
        basis[1]=D_L01_001E29E0[1];
        basis[2]=D_L01_001E29E0[2];
    } else if (*(s16 *)(state+0x2874)==1) {
        func_0038CE20(basis,(Q_003649E8 *)(obj+0xd0),-1.0f);
        { Q_003649E8 c=*(Q_003649E8 *)(obj+0xe0); Q_003649E8 d=*(Q_003649E8 *)(obj+0xc0); basis[2]=c; basis[1]=d; }
    } else {
        basis[0]=*(Q_003649E8 *)(state+0x6c0);
        basis[1]=*(Q_003649E8 *)(state+0x6d0);
        basis[2]=*(Q_003649E8 *)(state+0x6e0);
    }
    func_0038CF68((Q_003649E8 *)&step,basis,D_L01_001E1AE4[0]);
    func_0038CF68((Q_003649E8 *)&forward,&basis[2],1.0f);
    D_L01_0028E3A0[0]=*pos;
    D_L01_001E1B10=0;
    { Q_003649E8 *p=&D_L01_0028E3A0[1]; s16 *h=&D_L01_001E1B10+1;
    for (i=8;i>=0;i--,p++,h++) {
        *h=0;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
            : "=m"(*p)
            : "m"(p[-1]), "m"(step)
            : "vf1", "vf2");
    }
    }
    *(Q_003649E8 *)&a=0;
    *(Q_003649E8 *)&b=0;
    a.z=0.1f;
    a.w=1.0f;
    b.x=1.0f;
    b.w=1.0f;
    qzero(&D_L01_001E1AC0);
    r=func_00382538();
    func_0038D890(&D_L01_001E1AD0,(Q_003649E8 *)&a,(Q_003649E8 *)&b,r);
    D_L01_001E1AE0=r;
    D_L01_001DD784=0.006f;
    D_L01_001DD788=0;
    D_L01_001DD78C=0;
    if (D_L01_001DD778) {
        D_L01_001DD778=0;
        for(i=0;i<200;i++) {
            *(s32 *)(D_L01_0028CAA0+i*32+28)=0;
            *(s32 *)(D_L01_0028CAA0+i*32+12)=0;
        }
    }
}
