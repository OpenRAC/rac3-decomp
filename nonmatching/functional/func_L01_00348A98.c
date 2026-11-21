/* functional: high. Near miss (33 words) in VU0/register scheduling only; same reads, writes, calls. Inline asm is the VU0 vadd.xyz. */
/* localdecomp:start func_L01_00348A98 */
typedef struct { f32 v[4]; } __attribute__((aligned(16))) Vec_00348A98;
extern s32 D_001A71A4;
extern s32 D_L01_001D673C;
extern s32 D_001DD36C_sda;
void func_L01_00348A98(u8 *m) {
    extern char *func_L01_00457480(s32, s32);
    extern Info *func_L01_004574B0(s32, s32);
    extern void func_0038CF68(void *, void *, f32);
    extern void func_003C5180(void *, f32 *, s32);
    extern void func_0038CE90(void *, void *, void *);
    Vec_00348A98 a, b, c;
    u8 *v=*(u8 **)(m+0x68);
    char *base;
    if (D_001A71A4 == 29) return;
    base=func_L01_00457480(0xc04,*(s16 *)(v+0x1a));
    base+=func_L01_004574B0(0xc04,*(s16 *)(v+0x1a))->unk0;
    func_0038CF68(&a,v,1.0f);
    *(s128 *)&b=0;
    b.v[2]=1.0f; b.v[3]=1.0f;
    if (D_L01_001D673C) func_003C5180(m+0x10,b.v,1);
    func_0038CE90(&c,&a,&b);
    func_0038CF68(&c,&c,1.0f);
    func_0038CE90(base+*(s16 *)(v+0x18)*0x60+0x40,&c,&a);
    *(s128 *)(base+*(s16 *)(v+0x18)*0x60+0x30)=*(s128 *)&a;
    *(s128 *)(base+*(s16 *)(v+0x18)*0x60)=*(s128 *)(m+0x10);
    __asm__("lqc2 $vf1,%1\n\tlqc2 $vf2,%2\n\tvadd.xyz $vf1,$vf1,$vf2\n\tsqc2 $vf1,%0"
      : "=m"(*(Vec_00348A98 *)(base+*(s16 *)(v+0x18)*0x60+0x10))
      : "m"(*(Vec_00348A98 *)(m+0x10)), "m"(*(Vec_00348A98 *)v) : "vf1", "vf2");
    *(s128 *)(base+*(s16 *)(v+0x18)*0x60+0x20)=*(s128 *)(base+*(s16 *)(v+0x18)*0x60+0x10);
    *(s16 *)(base+*(s16 *)(v+0x18)*0x60+0x52)=(D_001DD36C_sda*5+2)/6;
    *(f32 *)(base+*(s16 *)(v+0x18)*0x60+0x5c)=1.0f / *(s16 *)(base+*(s16 *)(v+0x18)*0x60+0x52);
    *(s32 *)(base+*(s16 *)(v+0x18)*0x60+0x54)=0;
    *(s32 *)(base+*(s16 *)(v+0x18)*0x60+0x58)=0;
    *(s16 *)(base+*(s16 *)(v+0x18)*0x60+0x50)=1;
}
/* localdecomp:end func_L01_00348A98 */
