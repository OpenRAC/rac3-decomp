/* functional: high. VU register lifetime scheduling only. */
#include "common.h"
/* localdecomp:start func_L07_003A7CB8 */
extern float D_001DE3E4_sda;
extern float D_001DE3D4_sda;
__asm__(".extern D_001DE3E4_sda, 4");
__asm__(".extern D_001DE3D4_sda, 4");
extern Moby_003A7C10 *D_001A71A0 __attribute__((section(".data")));
void func_L07_003A7CB8(Moby_003A7C10 *m, void *other, Q_003A7C10 *position, f32 radius) {
    extern f32 func_L01_0040E570(void *, void *);
    extern f32 func_L01_0040E548(void *, void *);
    extern void func_L01_00446630(void *, void *, void *, void *);
    extern void func_0038CE20(void *, void *, f32);
    extern void func_L01_00456230(void *, s32);
    extern void func_L01_00446A70(void *, void *, s32, void *, void *, f32);
    Q_003A7C10 direction, projected, point;
    u8 *vars=m->vars;
    s32 point_address=(s32)&point;
    s32 projected_address;
    s32 direction_address;
    s32 best=0;
    s32 i, neighbor, offset;
    u8 *cur;
    f32 closest, d, prev;
    point=*position;
    closest=func_L01_0040E570((void *)point_address,(u8 *)m+0x10);
    if (radius < closest) return;
    cur=vars+16;
    i=1;
    projected_address=(s32)&projected;
    for (;i<19;i++,cur+=16) {
        d=func_L01_0040E570((void *)point_address,cur);
        if (d<closest) { closest=d; best=i; }
    }
    offset=best*16;
    prev=func_L01_0040E570((void *)point_address,vars+(offset-16));
    neighbor=best+1;
    d=func_L01_0040E570((void *)point_address,vars+(offset+16));
    if (prev<d) neighbor=best-1;
    func_L01_00446630((void *)projected_address,vars+best*16,vars+neighbor*16,(void *)point_address);
    d=func_L01_0040E548((void *)point_address,(void *)projected_address);
    if (D_001DE3E4_sda*D_001DE3E4_sda < d) return;
    __asm__("lqc2 $vf2, %2\n\tlqc2 $vf1, %1\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
        : "=m"(direction) : "m"(*(Q_003A7C10 *)(vars+best*16)), "m"(*(Q_003A7C10 *)(vars+best*16+0x140)) : "vf1", "vf2");
    direction_address=(s32)&direction;
    func_0038CE20((void *)direction_address,(void *)direction_address,D_001DE3D4_sda);
    if (m==D_001A71A0) func_L01_00456230(m->owner,1);
    func_L01_00446A70(other,m,0x10001,(void *)projected_address,(void *)direction_address,(f32)vars[0x2BB]);
}
/* localdecomp:end func_L07_003A7CB8 */
