#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L39_00533EB0 */
typedef struct { u8 pad0[0x10]; vu0_v4 pos; u8 state; u8 pad21[0x47]; u8 *vars; } M_533EB0;
typedef struct { u8 pad0[0x184]; u8 *texture; } G_533EB0;
extern G_533EB0 D_L39_00296918;
extern u8 *D_L39_002969EC[];
extern f32 func_00388770(void *);
extern void func_00388830(void *,void *,f32);
extern f32 func_L39_005B2568(f32,f32);
extern f32 func_L39_005B2510(f32,f32);
extern void func_003886E8(void *,void *,f32);
extern s32 func_L39_005B24C8(s32,s32);
extern s32 func_0019D650(void);
extern u8 *func_L01_0046DCB8(void *,void *,s32,s32,s32,s32,s32,s32,f32,f32,f32);
extern s32 func_L39_005B2498(s32);
extern void func_003BF6A8(void *,f32);
extern u8 *func_L39_005C5838(void *,void *,s32,s32,s32,s32,s32,s32,s32,f32);
void func_L39_00533EB0(M_533EB0 *m, vu0_v4 *pa, vu0_v4 *pb) {
    vu0_v4 a,b,v30,c,d,v60;
    u8 *vel,*other;
    void *pos;
    f32 len;
    s32 n,i;
    f32 scale;
    a=*pa;
    b=*pb;
    if (m && m->state!=0xFE && m->state!=0xFD) {
        vel=m->vars;
        other=*(u8 **)(vel+0x28);
        scale=63000.004f;
        len=func_00388770(vel);
        n=(s32)(len/0.1f);
        c=b;
        vec_sub_ab(&d,&a,&b);
        func_00388830(&d,&d,len/(f32)n);
        for(i=9;i>=0;i--) {
            s32 life=(s32)func_L39_005B2568(1.0f,3.0f);
            s32 r,size,color;
            u8 *p;
            f32 s=func_L39_005B2510(0.1f,0.3f)*0.0166666675f;
            func_003886E8(&v30,other+0x250,-s);
            r=func_L39_005B24C8(6,12);
            if(func_0019D650()&2) {size=0x40;color=0x306FFF;}
            else {size=0x60;color=0x2020FF;}
            p=func_L01_0046DCB8(&c,&v30,r,color,life,size,0,0,63000.004f,scale*0.05f,0.0f);
            vec_add_ab(&c,&c,&d);
            if(p) {
                if(func_L39_005B2498(2)) p[2]=D_L39_00296918.texture[4];
                else p[2]=D_L39_00296918.texture[5];
                p[3]=(size==0x40)?0x48:0x44;
            }
        }
        func_003886E8(&v60,vel,-0.0333333351f);
        {
            s32 color=0x7F80DFFF;
            s32 x;
            u8 *p;
            func_003BF6A8(&v60,0.10000000894f);
            v60.z+=0.05000000447f;
            if(func_L39_005B2498(2))color=0x7F407FFF;
            x=func_L39_005B24C8(10,20);
            p=func_L39_005C5838(&m->pos,&v60,color,0xFF,x,0,-1,-1,0,94500.0f);
            if(p) {
                *(f32 *)(p+0x2C)=0.00166666671f;
                p[2]=D_L39_002969EC[0][0];
            }
        }
    }
}
/* localdecomp:end func_L39_00533EB0 */
