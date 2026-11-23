/* PAL near miss (haiku-w1): 92 words differ with the file's flags (-O2 -G8 -fopt-stack -mno-check-zero-division @ps2as); pure C, no VU0 block; the residual is the parity hoisting and fill-loop registers, and the extern size hints of the level data (the 4- and 16-byte forms) were the only lever that moved it. */
#include "common.h"
/* localdecomp:start func_L01_004C70A8 */
#include "vu0.h"
typedef int Q_004C70A8 __attribute__((mode(TI)));
typedef struct {
    Vec4_004C4AD8 v[4];
    u32 color[4];
    f32 uv[4][2];
    unsigned long zero, texture, tag, prim;
} Work_004C70A8;
extern s32 D_001A71A4[];
__asm__(".extern D_001A71A4, 16");
extern s32 D_L01_001D6694;
__asm__(".extern D_L01_001D6694, 16");
extern s32 D_L01_001DFB40;
__asm__(".extern D_L01_001DFB40, 4");
extern u32 D_L01_001DAFF8[];
__asm__(".extern D_L01_001DAFF8, 8");
void func_L01_004C70A8(u8 *position, u8 *direction, s32 colors, s32 mode, f32 scale) {
    extern s32 func_L01_00511A98(void);
    extern f32 func_0038D160(f32, f32);
    extern f32 func_0038DAB8(f32, f32);
    extern f32 func_0038DB48(f32);
    extern void func_0038D328(void *, void *);
    extern void func_0038D640(void *, void *, void *);
    extern u32 func_00389598(s32);
    extern void func_0038CE20(Vec4_004C4AD8 *, Vec4_004C4AD8 *, f32);
    extern void func_003D2DA0(void *, void *, s32);
    Work_004C70A8 w;
    Vec4_004C4AD8 matrix[4], spinmatrix[4];
    Vec4_004C4AD8 angles, spin;
    Vec4_004C4AD8 *dir=(Vec4_004C4AD8 *)direction;
    s32 i, j, level;
    s32 parity;
    f32 angle;
    u32 color;
    level=D_001A71A4[0];
    if ((u32)(level-23)<2 || level==27 || level==25 || level==26 || level==116) return;
    if (func_L01_00511A98()) return;
    if (D_L01_001D6694==2) return;
    for (i=0;i<2;i++) {
        angles.x=func_0038DAB8(-func_0038D160(sqrt_asm(dir->x*dir->x+dir->z*dir->z),dir->y),1.5707963705062866f);
        angles.y=func_0038D160(dir->z,dir->x);
        angles.z=0;
        angles.w=0;
        spin.x=0;
        angle=func_0038DB48((f32)(D_L01_001DFB40%150)*6.2831854820251465f/150.3333282470703f);
        parity=(u8)i&1;
        if ((u8)parity) angle=-angle;
        spin.y=angle;
        spin.z=0;
        spin.w=0;
        func_0038D328(spinmatrix,&spin);
        func_0038D328(matrix,&angles);
        func_0038D640(matrix,matrix,spinmatrix);
        *(Q_004C70A8 *)&matrix[3]=*(Q_004C70A8 *)position;
        if (!colors) {
            color=D_L01_001DAFF8[i];
            for (j=3;j>=0;j--) w.color[j]=color;
        } else {
            color=((u32 *)colors)[i];
            { u32 *p=w.color; j=3; do { *p++=color; } while (--j>=0); }
        }
        { s32 texture;
        if(mode) { if(parity) texture=87; else texture=88; }
        else { if(parity) texture=18; else texture=17; }
        w.texture=func_00389598(texture); }
        w.zero=0;
        w.tag=0xFF9000000260;
        w.prim=0x8000000044;
        w.v[0].x=-1; w.v[0].y=0; w.v[0].z=1; w.v[0].w=1;
        w.v[1].x=1; w.v[1].y=0; w.v[1].z=1; w.v[1].w=1;
        w.v[2].x=-1; w.v[2].y=0; w.v[2].z=-1; w.v[2].w=1;
        w.v[3].x=1; w.v[3].y=0; w.v[3].z=-1; w.v[3].w=1;
        func_0038CE20(&w.v[0],&w.v[0],scale);
        func_0038CE20(&w.v[1],&w.v[1],scale);
        func_0038CE20(&w.v[2],&w.v[2],scale);
        func_0038CE20(&w.v[3],&w.v[3],scale);
        w.uv[0][0]=0; w.uv[0][1]=1;
        w.uv[1][0]=1; w.uv[1][1]=1;
        w.uv[2][0]=0; w.uv[2][1]=0;
        w.uv[3][0]=1; w.uv[3][1]=0;
        func_003D2DA0(&w,matrix,1);
    }
}
