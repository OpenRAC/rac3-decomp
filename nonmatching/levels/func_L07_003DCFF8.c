/* PAL near miss (Codex wave 8): near miss: 167 words differ with the file's flags.
 * Worker's note: Best 167 instruction diffs; register allocation and opaque VU scheduling; no VU j-class with fixed flags; 7 attempts with three later formulations unchanged; log build/codex/w419/func_L07_003DCFF8.03.diff.log
 */
#include "common.h"
/* localdecomp:start func_L07_003DCFF8 */
#include "vu0.h"
typedef struct { vu0_v4 p[4]; s32 color[4]; f32 uv[4][2]; unsigned long zero, texture, fixed, flags; } Packet_003DCFF8;
extern s32 D_001DE958_sda,D_001DE948_sda,D_001DE94C_sda;
extern f32 D_001DE950_sda,D_001DE954_sda;
extern vu0_v4 D_L07_001E1E40;
__asm__(".extern D_001DE958_sda, 4");
__asm__(".extern D_001DE948_sda, 4");
__asm__(".extern D_001DE94C_sda, 4");
__asm__(".extern D_001DE950_sda, 4");
__asm__(".extern D_001DE954_sda, 4");
static __inline__ vu0_v4 sub_003DCFF8(vu0_v4 *a,vu0_v4 *b) {
    vu0_v4 result;
    __asm__("lqc2 $vf2, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(result) : "r"(a),"r"(b),"m"(*a),"m"(*b) : "vf1","vf2");
    return result;
}
static __inline__ vu0_v4 add_003DCFF8(vu0_v4 *a,vu0_v4 *b) {
    vu0_v4 result;
    __asm__("lqc2 $vf2, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(result) : "r"(a),"r"(b),"m"(*a),"m"(*b) : "vf1","vf2");
    return result;
}
static __inline__ vu0_v4 *copy_003DCFF8(vu0_v4 *dst,vu0_v4 *src) { *dst=*src; return dst; }
void func_L07_003DCFF8(u8 *m,vu0_v4 *start,vu0_v4 *end) {
    extern void func_003D93B0(void *,s32,s32,s32);
    extern void func_0038CF68(void *,void *,f32);
    extern void func_0038CE90(void *,void *,void *);
    extern void func_003D2DA0(void *,s32,s32);
    vu0_v4 points[2];
    vu0_v4 *p = copy_003DCFF8(&points[0],start);
    vu0_v4 *q = copy_003DCFF8(&points[1],end);
    Packet_003DCFF8 packet;
    vu0_v4 a,b,delta,temp;
    u8 *vars=*(u8 **)(m+0x68);
    s32 i;
    func_003D93B0(&packet,D_001DE958_sda,1,128);
    packet.color[0]=packet.color[1]=packet.color[2]=packet.color[3]=D_001DE948_sda;
    packet.uv[0][0]=0;packet.uv[0][1]=0;packet.uv[1][0]=0;packet.uv[1][1]=1;
    packet.uv[2][0]=1;packet.uv[2][1]=0;packet.uv[3][0]=1;packet.uv[3][1]=1;
    for(i=0;i<4;i++){
        packet.uv[i][0]-=*(f32 *)(vars+0x120);
        if(packet.uv[i][0]<=7.0f)packet.uv[i][0]+=7.0f;
    }
    __asm__("lqc2 $vf2, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "r"(p),"r"(q),"m"(*p),"m"(*q) : "vf1","vf2");
    func_0038CF68(&delta,&delta,1.0f);
    __asm__("lqc2 $vf2, %4\n\tlqc2 $vf1, 0(%2)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf1, 0(%3)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %1" : "=m"(a),"=m"(b) : "r"(p),"r"(q),"m"(D_L07_001E1E40),"m"(*p),"m"(*q) : "vf1","vf2");
    func_0038CE90(&a,&a,&delta);
    func_0038CF68(&a,&a,D_001DE950_sda);
    func_0038CE90(&b,&b,&delta);
    func_0038CF68(&b,&b,D_001DE954_sda);
    temp=sub_003DCFF8(p,&a);packet.p[0]=temp;
    temp=add_003DCFF8(p,&a);packet.p[1]=temp;
    temp=sub_003DCFF8(q,&b);packet.p[2]=temp;
    temp=add_003DCFF8(q,&b);packet.p[3]=temp;
    func_003D2DA0(&packet,0,0);
    func_003D93B0(&packet,14,1,128);
    packet.color[0]=packet.color[1]=packet.color[2]=packet.color[3]=D_001DE94C_sda;
    packet.uv[0][0]=0;packet.uv[0][1]=0;packet.uv[1][0]=0;packet.uv[1][1]=1;
    packet.uv[2][0]=1;packet.uv[2][1]=0;packet.uv[3][0]=1;packet.uv[3][1]=1;
    for(i=0;i<4;i++){
        packet.uv[i][0]-=*(f32 *)(vars+0x120);
        if(packet.uv[i][0]<=7.0f)packet.uv[i][0]+=7.0f;
    }
    __asm__("lqc2 $vf2, 0(%2)\n\tlqc2 $vf1, 0(%1)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(delta) : "r"(p),"r"(q),"m"(*p),"m"(*q) : "vf1","vf2");
    func_0038CF68(&delta,&delta,1.0f);
    __asm__("lqc2 $vf2, %4\n\tlqc2 $vf1, 0(%2)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0\n\tlqc2 $vf1, 0(%3)\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %1" : "=m"(a),"=m"(b) : "r"(p),"r"(q),"m"(D_L07_001E1E40),"m"(*p),"m"(*q) : "vf1","vf2");
    func_0038CE90(&a,&a,&delta);
    func_0038CF68(&a,&a,D_001DE950_sda * 0.5f);
    func_0038CE90(&b,&b,&delta);
    func_0038CF68(&b,&b,D_001DE954_sda * 0.5f);
    temp=sub_003DCFF8(p,&a);packet.p[0]=temp;
    temp=add_003DCFF8(p,&a);packet.p[1]=temp;
    temp=sub_003DCFF8(q,&b);packet.p[2]=temp;
    temp=add_003DCFF8(q,&b);packet.p[3]=temp;
    func_003D2DA0(&packet,0,0);
}
/* localdecomp:end func_L07_003DCFF8 */
