/* functional: medium. Near-miss draft (compiles under file flags); 39 diff words: frame 0x80 vs retail 0xC0, tail scheduling; description inferred from draft and callee inventory, not every branch re-read */
/* localdecomp:start func_L01_0034D078 */
#include "vu0.h"
extern Entry_0034CC80 D_L01_0027FB20[];
void func_L01_0034D078(s32 a, s32 b, s32 c, s128 *v, s128 *w, s32 d, s32 e, s32 f, s32 g, f32 scale) {
    s32 i;
    u8 *base = (u8 *)D_L01_0027FB20;
    u8 *p;
    for (i=0; i<48; i++) {
        p = base + i * 0xD0;
        if (*(s32 *)(p+0xAC)==0) {
            *(s32 *)(p+0xAC)=a;
            *(s128 *)(p+0x40)=*v;
            *(s128 *)(p+0x50)=*w;
            *(f32 *)(p+0x60)=func_003824E0(-3.1415927f,3.1415927f);
            *(f32 *)(p+0x64)=func_003824E0(-3.1415927f,3.1415927f);
            *(f32 *)(p+0x68)=func_003824E0(-3.1415927f,3.1415927f);
            *(f32 *)(p+0x84)=func_003824E0(-3.1415927f,3.1415927f);
            *(f32 *)(p+0x88)=func_003824E0(-3.1415927f,3.1415927f);
            *(f32 *)(p+0x8C)=func_003824E0(-3.1415927f,3.1415927f);
            *(f32 *)(p+0x6C)=func_L01_00443A18(0.001f,0.005f);
            *(f32 *)(p+0x70)=func_L01_00443A18(0.001f,0.005f);
            *(f32 *)(p+0x74)=func_L01_00443A18(0.001f,0.005f);
            *(f32 *)(p+0x90)=func_L01_00443A18(0.001f,0.005f);
            *(f32 *)(p+0x94)=func_L01_00443A18(0.001f,0.005f);
            *(f32 *)(p+0x98)=func_L01_00443A18(0.001f,0.005f);
            *(f32 *)(p+0x78)=func_003824E0(3.25f,4.75f);
            *(f32 *)(p+0x7C)=func_003824E0(3.25f,4.75f);
            *(f32 *)(p+0x80)=func_003824E0(3.25f,4.75f);
            *(f32 *)(p+0x9C)=func_003824E0(3.25f,4.75f);
            *(f32 *)(p+0xA0)=func_003824E0(3.25f,4.75f);
            *(f32 *)(p+0xA4)=func_003824E0(3.25f,4.75f);
            *(s32 *)(p+0xCC)=g;
            qzero(p);
            qzero(p+0x10);
            *(s32 *)(p+0xB0)=c;
            *(s32 *)(p+0xB4)=b;
            *(s32 *)(p+0xC4)=d;
            *(f32 *)(p+0xC8)=scale;
            *(s32 *)(p+0xA8)=f;
            *(s32 *)(p+0xBC)=e;
            *(s32 *)(p+0xB8)=e;
            *(s32 *)(p+0xC0)=0;
            break;
        }
    }
}
/* localdecomp:end func_L01_0034D078 */
