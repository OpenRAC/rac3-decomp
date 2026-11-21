/* PAL near miss (sol-2): 226 words differ with the file's flags; literal-pool float loads shift the body, and the frame allocation and VU0 scheduling still differ. */
#include "common.h"
/* localdecomp:start func_L07_00310160 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) V_00310160;
typedef struct { V_00310160 dir; void *source; u32 flags; u8 type,mode; u16 id; f32 damage; u32 kind; } Hit_00310160;
extern void *D_L07_001ECC80[];
extern u8 D_001A4BE0[];
void func_L07_00310160(void *arg0, void *arg1) {
    extern s32 func_003D4D00(void *,s32,void *,s32,f32);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038DBA0(f32,f32);
    extern f32 func_L01_0040E570(void *,void *);
    extern f32 func_0038D098(f32);
    extern f32 func_0038D0B0(f32);
    extern void func_L01_00456230(void *,s32);
    extern void func_L01_00446978(void *,void *);
    extern f32 func_0038DB48(f32);
    extern f32 func_0038DAB8(f32,f32);
    extern void func_00382760(void *,f32,f32,f32);
    extern s32 func_003D3CB0(void *,void *,s32,void *,s32);
    union { Hit_00310160 hit; struct { V_00310160 v0,v1,v2,v3; } v; } u;
    u8 *m, *state=arg1;
    u8 *position;
    u8 *hero;
    f32 radius=*(f32 *)(state+0x70)* *(f32 *)(state+0x78);
    void **p;
    s32 count,i,j;
    f32 a,b,sign,limit;
    if (radius<0.75f) radius=0.75f;
    m = arg0;
    position = m + 0x10;
    count=func_003D4D00(position,16,*(void **)(m+0xB8),0,radius);
    if (count > 0) {
        p=D_L07_001ECC80;
        hero=D_001A4BE0;
        do {
            Hit_00310160 *hit=&u.hit;
            if (*p==*(void **)(m+0xB8)) goto next;
            if (*(f32 *)(state+0x78)>0.0f) {
                f32 angle=func_0038D160(*(f32 *)((u8 *)*p+0x10)-*(f32 *)(m+0x10),*(f32 *)((u8 *)*p+0x14)-*(f32 *)(m+0x14));
                f32 dz;
                if (func_0038DBA0(angle,*(f32 *)(m+0xF8))>0.7417649030685425f) goto next;
                dz=*(f32 *)((u8 *)*p+0x18)-*(f32 *)(m+0x18);
                if (dz>0.2f || dz< -2.0f) goto next;
                limit=radius*0.95f;
                if (func_L01_0040E570(position,(u8 *)*p+0x10)<limit*limit) goto next;
            }
            hit->kind=0x430000;
            hit->source=*(void **)(m+0xB8);
            hit->damage=(f32)state[0x7C];
            hit->type=2;hit->mode=3;hit->id=*(u16 *)(m+0xAA);
            hit->flags=0x430001;
            a=func_0038D160(*(f32 *)((u8 *)*p+0x10)-*(f32 *)(m+0x10),*(f32 *)((u8 *)*p+0x14)-*(f32 *)(m+0x14));
            hit->dir.x=func_0038D098(a);hit->dir.y=func_0038D0B0(a);hit->dir.z=1.0f;hit->dir.w=5627.9248046875f;
            if (*p==*(void **)(hero+0x25C0)) func_L01_00456230(*(void **)(m+0xB8),1);
            func_L01_00446978(*p,hit);
    next:
            count--;p++;
        } while(count);
    }
    for(i=0;i<2;i++) {
        sign=-1.0f;if(i&1) sign=1.0f;
        for(j=0;j<5;) {
            a=func_0038DB48((f32)j*sign*0.6981317f/5.0f);
            j++;
            b=func_0038DB48((f32)j*sign*0.6981317f/5.0f);
            func_00382760(&u.v.v0,radius,func_0038DAB8(a,*(f32 *)(m+0xF8)),-*(f32 *)(m+0xF4));
            func_00382760(&u.v.v1,radius,func_0038DAB8(b,*(f32 *)(m+0xF8)),-*(f32 *)(m+0xF4));
            __asm__("lqc2 $vf1, %4\n\tlqc2 $vf2, %0\n\tsqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0\n\tsqc2 $vf2, %3\n\tlqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %1\n\tsqc2 $vf1, %3"
              : "+m"(u.v.v0), "+m"(u.v.v1), "=m"(u.v.v3), "=m"(u.v.v2)
              : "m"(*(V_00310160 *)(m+0x10)) : "vf1", "vf2");
            if(func_003D3CB0(&u.v.v0,&u.v.v1,18,*(void **)(m+0xB8),0))
                func_00382760(&u.v.v2,0.40000004f,*(f32 *)(m+0xF8),-*(f32 *)(m+0xF4));
        }
    }
}
/* localdecomp:end func_L07_00310160 */
