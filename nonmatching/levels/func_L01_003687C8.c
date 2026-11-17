/* PAL near miss (Codex wave 8): near miss: 197 words differ with the file's flags.
 * Worker's note: 197 diff; best w404/func_L01_003687C8.02.log; stack layout and induction/global-base allocation differ; VU blocks retain all operands and clobbers; pointer/offset/index variants stall at 208 diff; branch-tree case evidence in func_L01_003687C8.asm.txt
 */
#include "common.h"
/* localdecomp:start func_L01_003687C8 */
typedef struct {
    s32 mode;
    f32 width;
    u32 color0,color1;
    s32 count;
    u8 pad[12];
    s128 origin, target;
} Params_003687C8;
extern s32 D_L01_001E1B80[];
extern u32 D_L01_001E1C10[];
extern s128 D_L01_001E1B90[];
extern s128 D_L01_001E1BD0[];
extern f32 D_L01_001E1C28;
extern f32 D_L01_001E1C64;
__asm__(".extern D_L01_001E1C28, 4");
void func_L01_003687C8(s32 unused,s128 *origin) {
    extern u32 func_0038DBD8(u32,s32,f32);
    extern void func_L01_00368478(Params_003687C8 *);
    extern void func_0038CE20(s128 *,s128 *,f32);
    extern void func_L01_00446630(s128 *,s128 *,s128 *,s128 *);
    Params_003687C8 p;
    s128 a,b,c;
    s32 *m=D_L01_001E1B80;
    s32 *color=(s32 *)D_L01_001E1C10;
    s32 off=0;
    p.origin=*origin;
    do {
        if(*m) {
            switch(*m) {
            case 1: case 2: case 3:
                p.mode=23;
                p.width=0.25f;
                if(*color!=-1) {
                    p.color0=*color;
                    p.color1=func_0038DBD8(*color&0xFFFFFF,0,0.25f)+(*color&0xFF000000);
                } else { p.color0=0x306020FF; p.color1=0x304820E0; }
                if(D_L01_001E1C64>0.0f) {
                    p.color0-=(s32)(D_L01_001E1C64*16.0f)<<24;
                    p.color1=(p.color1&0xFFFFFF)+(p.color0&0xFF000000);
                }
                p.count=6;
                break;
            case 4: case 5: case 6:
                p.mode=47;
                p.width=0.3f;
                if(*color!=-1) {
                    p.color0=*color;
                    p.color1=func_0038DBD8(*color&0xFFFFFF,0,0.25f)+(*color&0xFF000000);
                } else { p.color0=0x68F02060; p.color1=0x68802040; }
                if(D_L01_001E1C64>0.0f) {
                    p.color0-=(s32)(D_L01_001E1C64*32.0f)<<24;
                    p.color1=(p.color1&0xFFFFFF)+(p.color0&0xFF000000);
                }
                p.count=4;
                break;
            }
            p.target=*(s128 *)((u8 *)D_L01_001E1B90+off);
            if(*m!=3 && *m!=6) func_L01_00368478(&p);
            switch(*m) {
            case 2: case 3: p.count-=3; goto second;
            case 5: case 6: p.count-=1;
second:
                if(*m!=3 && *m!=6) {
                    s128 *pos=(s128 *)((u8 *)D_L01_001E1B90+off);
                    func_0038CE20(&a,(s128 *)((u8 *)D_L01_001E1BD0+off),D_L01_001E1C28);
                    __asm__("lqc2 $vf1, %1\n\tlqc2 $vf2, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(a) : "m"(*pos), "m"(a) : "vf1","vf2");
                    func_L01_00446630(&b,pos,&a,origin);
                    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvsub.xyz $vf1, $vf1, $vf2\n\tsqc2 $vf1, %0" : "=m"(c) : "m"(*pos), "m"(b) : "vf1","vf2");
                    __asm__("lqc2 $vf2, %1\n\tlqc2 $vf1, %2\n\tvadd.xyz $vf2, $vf2, $vf1\n\tsqc2 $vf2, %0" : "=m"(p.target) : "m"(b), "m"(c) : "vf1","vf2");
                }
                p.width=-p.width;
                p.color0+=0x20000000;
                p.color1+=0x20000000;
                func_L01_00368478(&p);
                break;
            }
        }
        m++; off+=16; color++;
    } while((s32)m<(s32)(D_L01_001E1B80+4));
}
/* localdecomp:end func_L01_003687C8 */
