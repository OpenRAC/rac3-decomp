#include "common.h"
/* localdecomp:start func_L19_003CBDA8 */
typedef unsigned int u128 __attribute__((mode(TI)));
typedef struct V4 {float x,y,z,w;} V4;
typedef float Vec[4] __attribute__((aligned(16)));
typedef struct NData {char pad[136]; float angle; int x; int index; float timer; float factor; int y; int status;} NData;
typedef struct Obj { char p0[16]; Vec pos; u8 state; char p21[19]; u16 flags; char p36[50]; int *data; char p6c[42]; u16 timer; char p98[36]; u8 started; } Obj;
extern int D_001D66D4_sda;
extern int D_L19_001D66D0_003CBDA8;
__asm__(".extern D_L19_001D66D0_003CBDA8, 16");
extern int D_001D545C;
__asm__(".extern D_001D545C, 16");
extern u8 D_001BBC40[];
extern Obj *D_L19_001DF71C_003CBDA8;
__asm__(".extern D_L19_001DF71C_003CBDA8, 16");
extern u8 *D_L19_001DF800_003CBDA8;
__asm__(".extern D_L19_001DF800_003CBDA8, 16");
extern u8 *D_001DF800_sda;
extern u8 D_001A4C60[];
typedef struct Hero { char pad[128]; float x,y,z,w; char pad2[8]; float angle; } Hero;
extern Hero D_001A4BE0;
extern s16 D_001A7464[];
extern int D_L19_002D3FF0[];
extern u8 *D_001D52FC;
__asm__(".extern D_001D52FC, 16");
extern float D_001DF050_sda;
extern Vec D_L19_001E2080_003CBDA8[];
typedef struct Cam { char pad[32]; float strength; int unk; int duration; int value; } Cam;
extern Cam D_L19_001E2100_003CBDA8;
extern int func_L01_00448E90(void *);
extern void func_L01_00452F40(Obj *,int);
extern void func_L01_00441FB8(Obj *,int,int);
extern int func_L01_00442998(int,int,int);
extern int func_0037E0F0(void *,int,int);
extern int func_L01_0044F2E8(int,int,int,int,int,int,int);
extern void func_00385B60(int);
extern void func_L01_004282C0(int,int);
extern void func_L01_004F12C0(void *,void *,int,int);
extern int func_L01_00452EC8(Obj *);
extern void func_L01_003E9588(int,void *,void *,int,int,int);
extern void func_L19_004EECE0(int,int);
extern float func_00388800(void *,void *);
extern float func_00388A28(float,float);
extern void func_L01_003E94A0(int,void *);
extern void func_L01_003E9510(int,void *);
extern int func_0039FE80(int,int,Obj *);
extern void func_003BEB58(void *,void *,void *,float);
extern void func_L19_003CBCF8(void *,void *,void *,void *,void *,float);
extern void func_003886E8(void *,void *,float);
extern void func_L01_003E9730(int,int);
void func_L19_003CBDA8(Obj *o) {
    Vec a,b,c,d,e; u128 v1,v2,vr;
    int *p; NData *q; Obj *m; Obj *n; float t;
    if (!func_L01_00448E90(&o->pos)) return;
    if ((unsigned)(D_001D66D4_sda-1)<2) return;
    if (D_L19_001D66D0_003CBDA8==1) return;
    if (D_L19_001D66D0_003CBDA8==2) return;
    p=o->data;
    if(o->state==0) {
        if(D_001BBC40[p[2]+D_001D545C*16]&0x80) {
            func_L01_00452F40((Obj *)((u8 *)D_L19_001DF71C_003CBDA8+p[5]*256),1);
            func_L01_00441FB8(o,3,-1);
        } else { p[3]=0; func_L01_00441FB8(o,1,-1); }
    }
    if(o->state==1) {
        if(!(D_001BBC40[p[2]+D_001D545C*16]&0x80)) {
            if(!func_L01_00442998(p[1],-1,0)) {
                if(func_0037E0F0(D_001A4C60,p[8],0) && !o->started) func_L01_00441FB8(o,5,-1);
                else if(func_0037E0F0(D_001A4C60,p[0],0)) {
                    func_L01_0044F2E8(0,9,0x1420,1,0,0,0);
                    if(D_L19_002D3FF0[0]==9) if(*(int *)(D_001D52FC+0x1a4)==16) {
                        func_00385B60(30); D_001DF050_sda=1.0f;
                        func_L01_004282C0(1,0);
                        func_L01_004F12C0(D_L19_001DF800_003CBDA8+p[4]*128+0x30,D_L19_001DF800_003CBDA8+p[4]*128+0x70,0,1);
                    }
                }
            }
        } else { D_001A7464[0]=0; func_L01_00452F40((Obj *)((u8 *)D_L19_001DF71C_003CBDA8+p[5]*256),1); func_L01_00441FB8(o,3,-1); }
    }
    if(o->state==5) {
        if(func_L01_00452EC8(o)) { func_L01_003E9588(0,D_L19_001E2080_003CBDA8,D_L19_001E2080_003CBDA8+1,0,0,0); func_L19_004EECE0(116,1); }
        *(u128 *)&b=*(u128 *)&(((Obj *)((u8 *)D_L19_001DF71C_003CBDA8+p[10]*256))->pos);
        *(u128 *)&a=*(u128 *)&(*(Vec *)(D_L19_001DF800_003CBDA8+p[17]*128+0x30));
        if(o->timer>=61) {func_L01_00441FB8(o,4,-1);func_L19_004EECE0(0,1);}
        c[0]=0;
        c[1]=-func_00388A28(func_00388800(&a,&b),b[2]-a[2]);
        c[2]=func_00388A28(b[0]-a[0],b[1]-a[1]);
        func_L01_003E94A0(0,&a);func_L01_003E9510(0,&c);
    }
    if(o->state==4) {
        m=(Obj *)((u8 *)D_L19_001DF71C_003CBDA8+p[16]*256);
        if(func_L01_00452EC8(o)) {
            n=(Obj *)((u8 *)D_L19_001DF71C_003CBDA8+p[16]*256);
            q=(NData *)n->data;
            q->angle+=3.141592741f;
            q->status=-1;
            q->timer=60.0f;
            *(float *)(D_L19_001DF800_003CBDA8+q->index*128+0x78)+=3.141592741f;
            q->factor=1.0f;
            func_L01_00441FB8(n,4,-1);n->flags&=~2;
        }
        *(u128 *)&a=*(u128 *)&(*(Vec *)(D_L19_001DF800_003CBDA8+p[9]*128+0x30));*(u128 *)&b=*(u128 *)&(m->pos);b[2]+=8.0f;
        if(!o->started && o->timer>=61) {
            D_L19_001E2100_003CBDA8.strength=0.4f;
            D_L19_001E2100_003CBDA8.duration=90;
            D_L19_001E2100_003CBDA8.value=0;
            func_0039FE80(1,0,(Obj *)((u8 *)D_L19_001DF71C_003CBDA8+p[16]*256));o->started=1;
        }
        c[0]=0;c[1]=-func_00388A28(func_00388800(&a,&b),b[2]-a[2]);c[2]=func_00388A28(b[0]-a[0],b[1]-a[1]);
        func_L01_003E94A0(0,&a);func_L01_003E9510(0,&c);
        if(o->timer>=151)func_L01_00441FB8(o,6,-1);
    }
    if(o->state==6) {
        t=o->timer;
        if(t<90.0f) {
            t/=90.0f;
            *(u128 *)&d=*(u128 *)&(*(Vec *)(D_001DF800_sda+p[9]*128+0x30));*(u128 *)&e=*(u128 *)&(*(Vec *)(D_001DF800_sda+p[17]*128+0x30));
            func_003BEB58(&a,&d,&e,t);
            *(u128 *)&b=*(u128 *)&(((Obj *)((u8 *)D_L19_001DF71C_003CBDA8+p[16]*256))->pos);b[2]+=8.0f;
            d[0]=0;d[1]=-func_00388A28(func_00388800(&a,&b),b[2]-a[2]);d[2]=func_00388A28(b[0]-a[0],b[1]-a[1]);
            *(u128 *)&b=*(u128 *)&(*(Vec *)(D_L19_001DF800_003CBDA8+p[21]*128+0x30));
            c[0]=0;c[1]=-func_00388A28(func_00388800(&a,&b),b[2]-a[2]);c[2]=func_00388A28(b[0]-a[0],b[1]-a[1])+6.283185482f;
            func_003BEB58(&c,&d,&c,t);
        } else {
            t-=90.0f; t*=0.0125f;
            if(t<1.0f)func_L19_003CBCF8(&a,D_L19_001DF800_003CBDA8+p[17]*128+0x30,D_L19_001DF800_003CBDA8+p[17]*128+0x30,D_L19_001DF800_003CBDA8+p[18]*128+0x30,D_L19_001DF800_003CBDA8+p[19]*128+0x30,t);
            else if(t<2.0f)func_L19_003CBCF8(&a,D_001DF800_sda+p[17]*128+0x30,D_001DF800_sda+p[18]*128+0x30,D_001DF800_sda+p[19]*128+0x30,D_001DF800_sda+p[20]*128+0x30,t-1.0f);
            else if(t<3.0f)func_L19_003CBCF8(&a,D_L19_001DF800_003CBDA8+p[18]*128+0x30,D_L19_001DF800_003CBDA8+p[19]*128+0x30,D_L19_001DF800_003CBDA8+p[20]*128+0x30,D_L19_001DF800_003CBDA8+p[20]*128+0x30,t-2.0f);
            else *(u128 *)&a=*(u128 *)&(*(Vec *)(D_L19_001DF800_003CBDA8+p[20]*128+0x30));
            t*=0.333333343f;
            if(t<1.0f) {
                
                __asm__("lqc2 %0,%1":"=j"(v1):"m"(*(V4 *)(D_L19_001DF800_003CBDA8+p[22]*128+0x30)));
                __asm__("lqc2 %0,%1":"=j"(v2):"m"(*(V4 *)(D_L19_001DF800_003CBDA8+p[21]*128+0x30)));
                __asm__("vsub.xyz %0,%0,%1":"+j"(v1):"j"(v2));
                __asm__("sqc2 %1,%0":"=m"(*(V4 *)b):"j"(v1));
                func_003886E8(&b,&b,t);
                
                __asm__("lqc2 %0,%1":"=j"(v2):"m"(*(V4 *)b));
                __asm__("lqc2 %0,%1":"=j"(v1):"m"(*(V4 *)(D_L19_001DF800_003CBDA8+p[21]*128+0x30)));
                __asm__("vadd.xyz %0,%0,%1":"+j"(v2):"j"(v1));
                __asm__("sqc2 %1,%0":"=m"(*(V4 *)b):"j"(v2));
            } else *(u128 *)&b=*(u128 *)&(*(Vec *)(D_L19_001DF800_003CBDA8+p[22]*128+0x30));
            c[0]=0;c[1]=-func_00388A28(func_00388800(&a,&b),b[2]-a[2]);c[2]=func_00388A28(b[0]-a[0],b[1]-a[1]);
        }
        func_L01_003E94A0(0,&a);func_L01_003E9510(0,&c);
        if(o->timer>=361) {
            func_L01_004F12C0(D_L19_001DF800_003CBDA8+p[23]*128+0x30,D_L19_001DF800_003CBDA8+p[23]*128+0x70,0,0);
            D_001A4BE0.angle=func_00388A28(b[0]-D_001A4BE0.x,b[1]-D_001A4BE0.y);
            func_L01_003E9730(0,2);func_L01_00441FB8(o,1,-1);
        }
    }
    switch(o->state) {case 5:if(o->timer<12)break;case 4:case 6:
        *(u128 *)&c=*(u128 *)&(*(Vec *)(D_L19_001DF800_003CBDA8+p[23]*128+0x30));c[2]+=300.0f;
        func_L01_004F12C0(&c,D_L19_001DF800_003CBDA8+p[23]*128+0x70,116,0);break;
    }
    if(o->state==3)o->flags|=2;
    if(o->timer<65535)o->timer++;
}
/* localdecomp:end func_L19_003CBDA8 */
