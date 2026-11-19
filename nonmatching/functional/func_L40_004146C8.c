/* functional: medium. PAL near miss (195 diff: spills, UV table address form, loop induction); call list and frame size equal to retail; builds four GS billboard quads (a fading ring effect) and hands them to the draw routine. */
/* localdecomp:start func_L40_004146C8 */
#include "vu0.h"
typedef struct {vu0_v4 v[4];u32 color[4];f32 uv[4][2];unsigned long u70,u78,u80,u88;} Q_004146C8;
extern s32 D_L40_002474D0;
extern s32 D_L40_002474C0;
extern s32 D_L40_002474C4;
extern s32 D_L40_002474C8;
extern s32 D_L40_002474CC;
extern u32 D_L40_002474D8[2];
extern f32 D_L40_002474E0[] __attribute__((section(".sdata")));
extern f32 D_L40_002474E4[];
extern f32 D_L40_00247500;
extern f32 D_L40_00247508;
extern f32 D_L40_00247ED8[];
__asm__(".extern D_L40_002474E0, 32");
__asm__(".extern D_L40_002474D8, 8");
__asm__(".extern D_L40_002474C0, 4");
__asm__(".extern D_L40_002474C4, 4");
__asm__(".extern D_L40_002474C8, 4");
__asm__(".extern D_L40_002474CC, 4");
__asm__(".extern D_L40_00247500, 4");
__asm__(".extern D_L40_00247508, 4");
void func_L40_004146C8(u8 *m) {
    extern void func_0038D570(void *,void *);
    extern unsigned long func_L39_00589890(s32);
    extern u32 func_0038DBD8(u32,u32,f32);
    extern void func_0038D308(void *,void *);
    extern void func_L04_0041AE18(void *,s32,void *,s32,void *);
    struct { Q_004146C8 q[4]; vu0_v4 matrix[3],position,rotationMatrix[3],rotation; } buf;
    Vars_004142A8 *s=*(Vars_004142A8 **)(m+0x68);
    Q_004146C8 *p;
    f32 fade,radius,t,ratio;
    s32 i,j;
    {
    Q_004146C8 *end;
    func_0038D570(buf.matrix,m+0xC0);
    end=(Q_004146C8 *)buf.matrix;
    *(vu0_q *)&buf.position=*(vu0_q *)(m+0x10);
    p=buf.q;
    do {
        p->u78=func_L39_00589890(D_L40_002474D0);
        p->u80=(0xFF90L<<32)|0x260;
        p->u70=0;
        p->u88=(unsigned long)D_L40_002474C0|((unsigned long)D_L40_002474C4<<2)|((unsigned long)D_L40_002474C8<<4)|((unsigned long)D_L40_002474CC<<6)|(0x8000L<<24);
        p++;
    } while((s32)p<(s32)end);
    }
    fade=(0.85f-s->f0)*2.0f;
    radius=0.15f;
    if(fade>1.0f) fade=1.0f;else if(fade<0.0f) fade=0.0f;
    if(s->f0<1.15f) {
        t=1.15f-s->f0;
        if(t<0.0f) t=0.0f;
        ratio=(0.2f-s->f0)/0.2f;
        if(ratio<0.0f) ratio=0.0f;
        D_L40_00247ED8[0]=ratio;
        radius=t+0.15f;
    }
    for(i=0;i<4;i++) {
        f32 *uvy=D_L40_002474E4;
        for(j=0;j<4;j++) {
            u32 c;
            buf.q[i].uv[j][0]=D_L40_002474E0[j*2];
            buf.q[i].uv[j][1]=uvy[0];
            c=D_L40_002474D8[i?1:0];
            buf.q[i].color[j]=c;
            buf.q[i].color[j]=func_0038DBD8(c&0xFFFFFF,c,fade);
            __asm__("sqc2 $vf0, %0" : "=m"(*(vu0_v4 *)((u8 *)buf.q+i*sizeof(Q_004146C8)+j*sizeof(vu0_v4))));
            buf.q[i].v[j].x=s->f0+(i?0.01f:0.0f);
            if(j&1) {
                switch(i) {
                case 0:buf.q[0].v[j].z+=D_L40_00247500+radius;break;
                case 1:buf.q[1].v[j].z+=D_L40_00247500+D_L40_00247508;break;
                case 2:buf.q[2].v[j].z+=D_L40_00247500-radius*0.8f+D_L40_00247508;break;
                case 3:buf.q[3].v[j].z+=D_L40_00247500+radius*0.8f+D_L40_00247508;break;
                }
            } else {
                switch(i) {
                case 0:buf.q[0].v[j].z+=D_L40_00247500-radius;break;
                case 1:buf.q[1].v[j].z+=D_L40_00247500-D_L40_00247508;break;
                case 2:buf.q[2].v[j].z+=D_L40_00247500-radius*0.8f-D_L40_00247508;break;
                case 3:buf.q[3].v[j].z+=D_L40_00247500+radius*0.8f-D_L40_00247508;break;
                }
            }
            uvy+=2;
        }
    }
    *(vu0_q *)&buf.rotation=0;
    buf.rotation.z=0.19634955f;
    func_0038D308(buf.rotationMatrix,&buf.rotation);
    func_L04_0041AE18(buf.q,4,buf.rotationMatrix,0x20,buf.matrix);
}
/* localdecomp:end func_L40_004146C8 */
