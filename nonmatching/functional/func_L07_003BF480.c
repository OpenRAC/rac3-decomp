/* functional: high. near-miss (152 words shifted by gp literal hoisting, differences all scheduling/regalloc) */
/* localdecomp:start func_L07_003BF480 */
extern f32 D_001DE520_sda[3] __attribute__((section(".sdata")));
extern s32 D_001DE510_sda[3] __attribute__((section(".sdata")));
extern u8 D_L07_0021EC98[];
void func_L07_003BF480(u8 *m)
{
    extern s32 func_00382468(s32);
    extern s32 func_00382498(s32,s32);
    extern f32 func_003824E0(f32,f32);
    extern void func_L07_003B9C28(void *,s32,s32,s32,s32,f32,f32,f32,f32);
    extern void func_0038D750(void *,s32,f32);
    extern void func_0038D810(void *,void *);
    extern void func_0038CE20(void *,void *,f32);
    extern void func_0038D000(void *,void *,void *);
    extern void func_003C4C18(void *,f32);
    extern u8 *func_L01_00475C60(void *,void *,s32,s32,s32,s32,s32,f32,f32,f32);
    extern u8 *func_L01_004713C8(void *,void *,s32,s32,s32,s32,s32,s32,f32,f32,f32);
    f32 q[4];
    f32 matrix[3][4];
    V_003BF3A8 pos, at, velocity, scratch;
    s32 index;
    s32 i;
    s32 life;
    s32 rotation;
    s32 color;
    f32 size;
    u8 *particle;
    index=(u8)func_00382468(3);
    size=D_001DE520_sda[index];
    color=D_001DE510_sda[index];
    func_L07_003B9C28(m+0x10,8,2,color,color,size*3.0f,size*15.0f,size*3.0f,size*8.0f);
    func_0038D750(q,2,*(f32 *)(m+0xf8));
    func_0038D810(q,matrix);
    func_0038CE20(&pos,matrix,1.25f);
    __asm__("lqc2 $vf1,%1
	lqc2 $vf2,%2
	vadd.xyz $vf1,$vf1,$vf2
	sqc2 $vf1,%0"
      : "=m"(pos) : "m"(*(V_003BF3A8 *)(m+0x10)), "m"(pos) : "vf1","vf2");
    for(i=1;i>=0;i--) {
        *(u128_t *)&at=*(u128_t *)&pos;
        func_003C4C18(&at,1.5f);
        *(u128_t *)&scratch=0;
        if(func_00382468(2)==0) scratch.y=0.060000002f;
        else scratch.y=-0.060000002f;
        scratch.z=0.060000002f;
        *(u128_t *)&velocity=*(u128_t *)&scratch;
        func_0038D000(&velocity,&velocity,matrix);
        func_003C4C18(&velocity,0.0200000014f);
        life=func_00382498(17,33);
        rotation=254;
        if(func_00382468(2)) rotation=2;
        size=func_003824E0(126000.0078125f,189000.0f);
        particle=func_L01_00475C60(&at,&velocity,life,rotation,0x7f5786ae,0x2e475c,0,size,size*1.5f,0.0200000014f);
        if(particle) {
            particle[3]=0x44;
            particle[2]=**(u8 **)(D_L07_0021EC98+0x10);
        }
    }
    if(func_00382468(6)==0) {
        *(u128_t *)&at=*(u128_t *)&pos;
        func_003C4C18(&at,0.15f);
        *(u128_t *)&scratch=0;
        size=0.3f;
        if(func_00382468(2)) size=-0.3f;
        scratch.y=size;
        scratch.z=0.2000000179f;
        *(u128_t *)&velocity=*(u128_t *)&scratch;
        func_0038D000(&velocity,&velocity,matrix);
        func_003C4C18(&velocity,0.100000009f);
        life=func_00382498(50,67);
        color=0x2e475c;
        if(func_00382468(2)) color=0x5786ae;
        rotation=254;
        if(func_00382468(2)) rotation=2;
        size=func_003824E0(42000.0f,63000.00390625f);
        particle=func_L01_004713C8(&at,&velocity,life,color,rotation,127,127,func_00382468(3)+10,size,size,0.0100000007f);
        if(particle) particle[3]=0x44;
    }
}
/* localdecomp:end func_L07_003BF480 */
