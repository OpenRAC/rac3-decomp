/* functional: high. Needs the file's vu0.h/S_3A9AC0m context */
__asm__(".extern D_L01_001E001C, 16");
__asm__(".extern D_001D545C, 4");
extern u8 *D_L01_001E001C;
extern s32 D_001D545C;
extern u8 D_001BBC40[];
extern u8 D_001BBB18[];
void func_L01_003A7DC0(u8 *m, u8 *p)
{
    extern void func_0038D328(void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern void func_0038D308(void *, void *);
    extern void func_003C7C38(u8 *);
    extern void func_L01_004450F0(S_3A9AC0m *, int, int);
    vu0_v4 t, v, origin;
    u8 *target;
    s32 group;
    *(s32 *)(p+0x50)=-1;
    *(s32 *)(p+0x54)=-1;
    *(s32 *)(p+0x68)=0;
    *(s32 *)(p+0x6C)=0;
    *(s32 *)(p+0x60)=0;
    *(s32 *)(p+0x64)=0;
    func_0038D328(p+0x90,m+0xF0);
    target=D_L01_001E001C+(*(s32 *)(p+8)<<8);
    *(vu0_q *)(p+0x70)=*(vu0_q *)(target+0x10);
    *(vu0_q *)(p+0x80)=*(vu0_q *)(target+0xF0);
    *(vu0_q *)(m+0x10)=*(vu0_q *)(target+0x10);
    *(vu0_q *)(m+0xF0)=*(vu0_q *)(target+0xF0);
    if(*(s32 *)(p+0xC)) {
        group=m[0xB0];
        if ((group!=255 && (*(u8 *)((group+(D_001D545C<<4))+(s32)D_001BBC40) & 0x80)) ||
            (*(s32 *)(p+0x5C)!=-1 && D_001BBB18[*(s32 *)(p+0x5C)+(D_001D545C<<3)])) {
            *(s32 *)(p+0x68)=1;
            *(s32 *)(p+0)=-1;
            *(s32 *)(p+4)=-1;
            if(*(f32 *)(p+0x10)!=0 || *(f32 *)(p+0x14)!=0 || *(f32 *)(p+0x18)!=0) {
                func_0038CE20(&v,p+0x90,*(f32 *)(p+0x10));
                func_0038CE20(&t,p+0xA0,*(f32 *)(p+0x14));
                __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %0\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
                    : "+m"(v) : "m"(t) : "vf1", "vf2");
                func_0038CE20(&t,p+0xB0,*(f32 *)(p+0x18));
                __asm__("lqc2 $vf1, %3\n\tlqc2 $vf2, %0\n\tvadd.xyz $vf2, $vf2, $vf1\n\t"
                    "lqc2 $vf1, %4\n\tsqc2 $vf1, %1\n\tsqc2 $vf2, %0\n\t"
                    "lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %2"
                    : "+m"(v), "=m"(origin), "=m"(*(vu0_v4 *)(m+0x10))
                    : "m"(t), "m"(*(vu0_v4 *)(p+0x70)) : "vf1", "vf2");
                *(vu0_q *)(target+0x10)=*(vu0_q *)(m+0x10);
            }
            if(*(f32 *)(p+0x28)!=0 || *(f32 *)(p+0x2C)!=0 || *(f32 *)(p+0x30)!=0) {
                *(f32 *)(m+0xF0)=func_0038DAB8(*(f32 *)(p+0x80),*(f32 *)(p+0x28)*0.0174532924f);
                *(f32 *)(m+0xF4)=func_0038DAB8(*(f32 *)(p+0x84),*(f32 *)(p+0x2C)*0.0174532924f);
                *(f32 *)(m+0xF8)=func_0038DAB8(*(f32 *)(p+0x88),*(f32 *)(p+0x30)*0.0174532924f);
                func_0038D308(m+0xC0,m+0xF0);
                *(vu0_q *)(target+0xF0)=*(vu0_q *)(m+0xF0);
                func_0038D308(target+0xC0,target+0xF0);
            }
            func_003C7C38(target);
        }
    }
    func_L01_004450F0((S_3A9AC0m *)m,1,-1);
}
