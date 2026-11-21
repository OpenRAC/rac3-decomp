/* functional: high. Same ops as retail under ps2as (67 diff, scheduling only); uses VU0 lqc2/vsub/sqc2 inline asm for the position delta. */
typedef int Q_003AADB0 __attribute__((mode(TI)));
typedef union { Q_003AADB0 q; f32 f[4]; } V_003AADB0;
extern s32 D_L07_001DEF40;
__asm__(".extern D_L07_001DEF40, 16");
void func_L07_003AADB0(u8 *obj, f32 speed)
{
    extern void func_L03_0032FAF0(void *, void *, f32, f32);
    extern void func_L07_00333DB8(s32, void *, s32, s32, f32);
    extern f32 func_0038DB00(f32, f32);
    extern f32 func_L07_00332CF0(s32, void *, void *, f32);
    extern void func_L01_0045A7A8(void *, void *, f32);
    extern f32 func_0038CE68(void *, void *);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DBA0(f32, f32);
    extern void func_L01_00448890(void *, void *, s32, f32, f32, f32, f32);
    V_003AADB0 v,old,delta;
    u8 *s=*(u8 **)(obj+0x68);
    f32 angle;
    u8 *pos;
    func_L03_0032FAF0(&v,s+0x130,*(f32 *)(s+0x254),speed);
    if((D_L07_001DEF40&7)==(((s32)obj>>8)&7)) {
        func_L07_00333DB8(*(s32 *)(s+0x240),obj,0,0,speed);
        *(f32 *)(s+0x258)=func_L07_00332CF0(*(s32 *)(s+0x240),obj,&v,func_0038DB00(*(f32 *)(s+0x250),*(f32 *)(s+0x254))*0.15f);
    }
    pos=obj+0x10;
    old.q=*(Q_003AADB0 *)(obj+0x10);
    func_L01_0045A7A8(obj,&v,*(f32 *)(s+0x258));
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(delta) : "m"(*(V_003AADB0 *)(obj+0x10)), "m"(old) : "vf1", "vf2");
    *(f32 *)(s+0x53C)=func_0038DAB8(*(f32 *)(s+0x53C),func_0038CE68(&delta,obj+0xC0)/0.3f);
    if((*(s32 *)(s+0x188)&0x10) && func_L01_0040E570(&old,pos)>0.0001f) {
        angle=func_0038D160(*(f32 *)(obj+0x10)-old.f[0],*(f32 *)(obj+0x14)-old.f[1]);
        if(func_0038DBA0(func_0038D160(*(f32 *)(s+0x130)-*(f32 *)(obj+0x10),*(f32 *)(s+0x134)-*(f32 *)(obj+0x14)),angle)>1.5707964f)
            angle=func_0038DAB8(angle,3.1415927f);
        func_L01_00448890(obj+0xF8,s+0x204,0,angle,*(f32 *)(s+0x164),*(f32 *)(s+0x168),*(f32 *)(s+0x16C));
    }
}
