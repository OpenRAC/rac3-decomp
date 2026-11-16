/* PAL near miss (Codex wave 8): near miss: 370 words differ with the file's flags.
 * Worker's note: 370 diff; func_L01_0037B6C0.v2-detail.log; complete retail-derived draft; pointer-copy allocation, byte clamp color registers/conversions and call scheduling remain; stopped after ten checker invocations without further improvement
 */
#include "common.h"
/* localdecomp:start func_L01_0037B6C0 */
typedef struct {
    u8 pad0[0x14];
    s32 timer;
    u8 pad18[0x1C];
    f32 a34,a38,a3C,a40,a44,a48,a4C;
} Vars_0037B6C0;
extern f32 D_L01_001E29C0[];
extern f32 D_L01_001DDB14,D_L01_001DDB18,D_L01_001DDB1C,D_L01_001DDB20;
extern s32 D_L01_001DDB44,D_L01_001DDB48,D_L01_001DDB4C,D_L01_001DDB50,D_L01_001DDB54;
__asm__(".extern D_L01_001DDB14, 4");
__asm__(".extern D_L01_001DDB18, 4");
__asm__(".extern D_L01_001DDB1C, 4");
__asm__(".extern D_L01_001DDB20, 4");
__asm__(".extern D_L01_001DDB44, 4");
__asm__(".extern D_L01_001DDB48, 4");
__asm__(".extern D_L01_001DDB4C, 4");
__asm__(".extern D_L01_001DDB50, 4");
__asm__(".extern D_L01_001DDB54, 4");
void func_L01_0037B6C0(u8 *obj) {
    extern f32 func_003824E0(f32,f32);
    extern f32 func_0038DAB8(f32,f32);
    extern f32 func_L01_0040E570(void *,void *);
    extern void func_L01_0037BE80(void *,void *,s32,s32,u32,s32,f32,f32,f32,f32,f32,f32);
    extern void func_L01_0037BCF8(void *,void *,s32,u32,s32,f32,f32,f32);
    Vars_0037B6C0 *v=*(Vars_0037B6C0 **)(obj+0x68);
    u8 *pos;
    f32 distance,t;
    f32 fade,fade2;
    u32 color;
    s32 alpha;
    if(v==0)return;
    pos=obj+0x10;
    v->a44=func_0038DAB8(v->a44,func_003824E0(-0.5f,-1.0f)*0.0174532924f);
    v->a34=func_0038DAB8(v->a34,func_003824E0(-1.0f,-2.0f)*0.0174532924f);
    v->a48=func_0038DAB8(v->a48,func_003824E0(-1.0f,-1.5f)*0.0174532924f);
    v->a38=func_0038DAB8(v->a38,func_003824E0(1.5f,2.5f)*0.0174532924f);
    v->a4C=func_0038DAB8(v->a4C,func_003824E0(-0.5f,-1.5f)*0.0174532924f);
    v->a3C=func_0038DAB8(v->a3C,func_003824E0(0.5f,1.5f)*0.0174532924f);
    distance=func_L01_0040E570(obj+0x10,D_L01_001E29C0);
    if(distance<D_L01_001DDB18) t=(distance-D_L01_001DDB14)/(D_L01_001DDB18-D_L01_001DDB14);
    else t=1.0f;
    fade=t<0.0f ? 0.0f : t;
    if(distance<D_L01_001DDB20) t=(distance-D_L01_001DDB1C)/(D_L01_001DDB20-D_L01_001DDB1C);
    else t=1.0f;
    fade2=t<0.0f ? 0.0f : t;
    if(D_L01_001DDB44) {
        func_L01_0037BE80(obj,pos,0x47,0x48,((143-v->timer*2)<<24)|0xFF0032,0,1.0f,1.0f,1.7f,v->a44,v->a34,0.0f);
    }
    if(fade>0.0f && D_L01_001DDB50) {
        color=0x8F804020;
        if(fade!=1.0f) {
            alpha=(u8)(s32)(fade*143.0f);
            alpha = (alpha >> 7) ? 127 : alpha;
            color=(alpha<<24)|0x804020;
        }
        func_L01_0037BE80(obj,pos,0x47,0x48,((143-v->timer*2)<<24)|(color&0xFFFFFF),0,1.0f,1.0f,1.7f,v->a48,v->a38,0.05f);
        color=0x8F20207F;
        if(fade!=1.0f) {
            alpha=(u8)(s32)(fade*143.0f);
            alpha = (alpha >> 7) ? 127 : alpha;
            color=(alpha<<24)|0x20207F;
        }
        func_L01_0037BE80(obj,pos,0x47,0x48,((143-v->timer*2)<<24)|(color&0xFFFFFF),0,1.0f,1.0f,1.7f,v->a4C,v->a3C,0.1f);
    }
    if(fade>0.0f && D_L01_001DDB48) {
        color=0x2F804020;
        if(fade!=1.0f) {
            alpha=(u8)(s32)(fade*47.0f);
            alpha = (alpha >> 7) ? 127 : alpha;
            color=(alpha<<24)|0x804020;
        }
        func_L01_0037BCF8(obj,pos,0x1B,((47-v->timer*2)<<24)|(color&0xFFFFFF),1,1.15f,0.0f,v->a34);
        func_L01_0037BCF8(obj,pos,0x1B,((47-v->timer*2)<<24)|(color&0xFFFFFF),1,1.15f,0.0f,v->a38);
    }
    if(fade2>0.0f && D_L01_001DDB4C) {
        func_L01_0037BCF8(obj,pos,0x4C,((127-v->timer*2)<<24)|0xFF0032,1,0.5f,0.0f,-v->a38);
        func_L01_0037BCF8(obj,pos,0x4C,((127-v->timer*2)<<24)|0x300505,1,0.2f,0.0f,v->a38);
    }
    if(fade2>0.0f && D_L01_001DDB54) {
        color=0x7F204080;
        if(fade2!=1.0f) {
            alpha=(u8)(s32)(fade2*127.0f);
            alpha = (alpha >> 7) ? 127 : alpha;
            color=(alpha<<24)|0x204080;
        }
        func_L01_0037BCF8(obj,pos,0x4B,((127-v->timer*2)<<24)|(color&0xFFFFFF),0,0.6f,0.0f,v->a34);
    }
    obj[0x23]=21-*(u8 *)&v->timer;
}
/* localdecomp:end func_L01_0037B6C0 */
