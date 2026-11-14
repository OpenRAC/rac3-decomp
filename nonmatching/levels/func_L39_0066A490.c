/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_00667BB8, the NTSC-U twin of func_L39_0066A490, with NTSC-U names
 * and addresses. Near miss on NTSC-U: 1 words differ with its file's flags.
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00667BB8 */
typedef int Q96d __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } V96d;
typedef struct { void (*start)(void *); int pad4; void (*update)(void *); char padC[16]; } Row96d;
extern Row96d D_L39_0033AC08[];
extern void *D_001A5F78 __attribute__((section(".data")));
__asm__(".extern D_001A5F78, 0");
extern void func_003886E8(void *,void *,float);
extern void func_L39_0061C568(void *,void *,void *);
extern void func_L39_0061C608(void *,void *,void *);
void func_L39_00667BB8(u8 *s) {
    u8 *p=*(u8 **)(s+0x2D8);
    u8 *m=*(u8 **)(s+0x2D0);
    void *from=0;
    void *owner;
    V96d v __attribute__((aligned(16)));
    if(p && !p[0x1A14] && (*(int *)(p+0x4D84)&1)) return;
    p=*(u8 **)(s+0x2DC);
    if(p && !p[0x1A14] && (*(int *)(p+0x4D84)&1)) return;
    owner=0;
    if(*(u32 *)(s+0x2F8)&1) {
        owner=*(void **)(s+0x2E0);
        from=s+0x1F0;
        *(u32 *)(s+0x2F8)&=~1u;
    }
    if(*(u32 *)(s+0x2F8)&2) {
        func_003886E8(&v,s+0x2C0,1.0f-(float)*(int *)(s+0x318)/30.0f);
        __asm__("lqc2 $vf1, %0\n\tlqc2 $vf2, %1\n\tvadd.xyz $vf1, $vf1, $vf2" : : "m"(*(V96d *)(s+0x2B0)), "m"(v) : "vf1","vf2");
        __asm__("sqc2 $vf1, 0(%1)" : "=m"(*(V96d *)(s+0xB0)) : "r"(s+0xB0) : "vf1");
        if(--*(int *)(s+0x318)<=0) {
            func_L39_0061C568(s+0x20,s+0xB0,D_001A5F78);
            qzero(s+0x270);
            *(int *)(s+0x310)=0;
            *(u32 *)(s+0x2F8)=(*(u32 *)(s+0x2F8)&~0x22u)|8;
        }
    } else func_L39_0061C608(s+0x20,from,&owner);
    if(*(u32 *)(s+0x2F8)&0x10) {
        owner=*(void **)(s+0x2E0);
        *(u32 *)(s+0x2F8)=(*(u32 *)(s+0x2F8)&~0x10u)|8;
        func_L39_0061C568(s+0x20,s+0x290,owner);
        if(D_L39_0033AC08[*(short *)(s+0x2FC)].start) D_L39_0033AC08[*(short *)(s+0x2FC)].start(m);
        *(Q96d *)(m+0x10)=*(Q96d *)(s+0x290);
        *(Q96d *)(m+0xF0)=*(Q96d *)(s+0x2A0);
        *(Q96d *)(s+0x1F0)=*(Q96d *)(m+0x10);
        *(Q96d *)(s+0x200)=*(Q96d *)(m+0xF0);
    }
    { int idx=*(short *)(s+0x2FC);
      if(D_L39_0033AC08[idx].update) ((Row96d *)(idx*28+(int)D_L39_0033AC08))->update(m);
    }
}
/* localdecomp:end func_L39_00667BB8 */
