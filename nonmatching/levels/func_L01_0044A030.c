/* NTSC-U draft (Codex wave 3): C of func_L01_00446E68, the NTSC-U twin of func_L01_0044A030, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 281 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L01_00446E68", whose code is not the PAL one).
 * Worker's note: 281 diff; reverified documented inline literal assembler mismatch under allowed flags: pooled constants versus retail inline lui ori mtc1; sd versus sq saves; no unlisted flags tried; best log func_L01_00446E68.01.log
 */
#include "common.h"
#include "vu0.h"
/* localdecomp:start func_L01_00446E68 */
extern int func_003BD668(void *,int);
extern void func_0037E2F0(void *,float,float);
extern float func_0037E2A8(void);
extern void func_0037E4B8(void *,float,float,float);
extern int func_0037E208(int,int);
extern float func_0037E250(float,float);
extern int func_0037E1D8(int);
extern void func_003886C0(void *,void *,void *,float);
extern u8 *func_L01_0046DCB8(void *,void *,int,float,float,float,int,int,int,int,int);
extern int func_L01_00444800(void *,int,void *,int,float);
extern u8 *D_L01_00221118[];
extern vu0_v4 D_L01_70000000[];
void func_L01_00446E68(void *owner,void *velocity,int arg2,int arg3,int lo,int hi,int index,int offset,float strength,int type) {
    vu0_v4 a,b,c,d,points[8];
    int count=func_003BD668(owner,0);
    vu0_v4 *p;
    u8 *part;
    float x,y;
    if(count) {
        p=D_L01_70000000;
        if(count>0) do {
            if(p[1].w==0.0f) {
                *(vu0_q *)&a=*(vu0_q *)p;
                a.w=1.0f;
                func_0037E2F0(&b,0.0f,p->w);
                vec_add_ba(&a,&a,&b);
                x=func_0037E2A8(); y=func_0037E2A8();
                func_0037E4B8(&c,strength*0.0166666675f,x,y);
                vec_add_ab(&c,&c,velocity);
                c.z+=0.0033333334f;
                part=func_L01_0046DCB8(&a,&c,func_0037E208(lo,hi),84000.0f,168000.0f,0.0f,arg3,1,47,0,1);
                if(part) {
                    if(type) part[3]=type;
                    else part[3]=func_0037E1D8(2)?0x48:0x44;
                    part[2]=D_L01_00221118[index][offset];
                }
            } else {
                *(vu0_q *)&a=*(vu0_q *)p; a.w=1.0f;
                *(vu0_q *)&b=*(vu0_q *)(p+1); b.w=1.0f;
                func_003886C0(&c,&a,&b,func_0037E250(0.0f,1.0f));
                c.x+=func_0037E250(-p->w*0.4f,p->w*0.4f);
                c.y+=func_0037E250(-p->w*0.4f,p->w*0.4f);
                c.z+=func_0037E250(-p->w*0.4f,p->w*0.4f);
                x=func_0037E2A8(); y=func_0037E2A8();
                func_0037E4B8(&d,strength*0.0166666675f,x,y);
                vec_add_ab(&d,&d,velocity);
                d.z+=0.0033333334f;
                part=func_L01_0046DCB8(&c,&d,func_0037E208(lo,hi),63000.00390625f,126000.0078125f,0.0f,arg3,1,47,0,1);
                if(part) {
                    if(type) part[3]=type;
                    else part[3]=func_0037E1D8(3)?0x48:0x44;
                    part[2]=D_L01_00221118[index][offset];
                }
            }
            p+=2;
        } while(--count);
    } else {
        count=func_L01_00444800(owner,8,points,arg2,6.0f);
        p=points;
        if(count>0) do {
            x=func_0037E2A8(); y=func_0037E2A8();
            func_0037E4B8(&a,0.03f,x,y);
            vec_add_ab(&a,&a,velocity);
            a.z+=0.006666667f;
            part=func_L01_0046DCB8(p,&a,func_0037E208(12,18),84000.0f,168000.0f,0.0f,arg3,1,47,0,1);
            if(part) {
                if(type) part[3]=type;
                else part[3]=func_0037E1D8(2)?0x48:0x44;
                part[2]=D_L01_00221118[index][offset];
            }
            p++;
        } while(--count);
    }
}
/* localdecomp:end func_L01_00446E68 */
