/* PAL near miss (Codex wave 8): near miss: 132 words differ with the file's flags.
 * Worker's note: 132 diff; best logs w404/func_L07_00353AB0.02.log and .04.log; opaque VU sequences preserve operands/clobbers but pointer duplication, global bases, saved-register allocation and scheduling differ; equivalent for/do/while forms stall; no metadata applies
 */
#include "common.h"
/* localdecomp:start func_L07_00353AB0 */
typedef struct { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_00353AB0;
typedef struct { u8 pad[0x320]; Vec_00353AB0 a[10], b[10]; } Ring_00353AB0;
extern u8 D_L07_001E8C00[];
extern u8 D_001A4BE0[];
extern s32 D_001A71A0[];
extern s32 D_L07_001E8C18[];
void func_L07_00353AB0(u8 *self) {
    extern void func_003C2F58(u8 *, s32, Vec_00353AB0 *);
    extern void func_L01_0044C280(Vec_00353AB0 *, Vec_00353AB0 *, Vec_00353AB0 *, f32, s32);
    extern s32 func_L03_00433C70(u8 *, Vec_00353AB0 *, Vec_00353AB0 *, s32, f32, f32, s32, s32, s32);
    extern s32 func_L01_00446780(u8 *, Vec_00353AB0 *, s32, f32, f32, f32, s32, s32, s32);
    Vec_00353AB0 a,b,c,d,e;
    u8 *o=*(u8 **)(self+0x68);
    f32 t;
    func_003C2F58(self,4,&a);
    func_003C2F58(self,1,&b);
    if(o[0x467]) {
      s32 count=o[0x469];
      if(count) {
        Ring_00353AB0 *p=(Ring_00353AB0 *)o;
        s32 n=(o[0x468]+count-1)%10;
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
          : "=m"(d) : "m"(p->a[n]), "m"(p->b[n]) : "vf1","vf2");
        __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0"
          : "=m"(c) : "m"(b), "m"(a) : "vf1","vf2");
        t=0.65999997f;
        while(0.0f<t) {
            func_L01_0044C280(&e,&d,&c,t,0);
            __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0"
              : "=m"(e) : "m"(a), "m"(e) : "vf1","vf2");
            if(func_L03_00433C70(self,&a,&e,0x10001,(f32)o[0x46],1.0f,0,1,0) &&
               *(s32 *)(D_L07_001E8C00+0x18)==*(s32 *)(D_001A4BE0+0x25C0)) { o[0x466]++; return; }
            t-=0.34f;
        }
      }
    }
    if(func_L03_00433C70(self,&a,&b,0x10001,(f32)o[0x46],1.0f,0,1,0) && D_L07_001E8C18[0]==D_001A71A0[0]) { o[0x466]++; return; }
    if(func_L01_00446780(self,&a,0x10001,0.3f,(f32)o[0x46],1.0f,0,1,0)) {
        o[0x466]++;
    }
}
/* localdecomp:end func_L07_00353AB0 */
