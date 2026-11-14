/* NTSC-U draft (2026-11-14, Codex worker): C of func_L08_003A7CE8, the NTSC-U twin of func_L08_003A9B08, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/shared/L08_003A9B08.c's current line.
 * Worker's note: 296 diff; best log func_L08_003A7CE8.1.log; allowed flags emit lit4 rather than retail inline float constants; full two-state draft retained; gp relocation resolution also differs
 */
#include "common.h"
/* localdecomp:start func_L08_003A7CE8 */
typedef int Q87 __attribute__((mode(TI)));
typedef struct { float x,y,z,w; } V87;
typedef struct { char pad[16]; V87 pos; u8 state; char pad21[71]; void *vars; char pad6c[132]; float rot0,rot1; } M87;
extern void func_L08_003A8420(M87 *);
extern void func_L08_003A8330(M87 *);
extern float func_00389380(float,float);
extern void func_003886E8(void *,void *,float);
extern float func_0037E2A8(void);
extern void *func_L01_00466F98(void *,void *,int,int,int,int,float,float,float,float,float);
extern char D_L08_001D66B0[];
extern u8 *D_L08_0021ECBC[];
extern int func_0037E1D8(int);
extern float func_0037E250(float,float);
extern int func_0037E208(int,int);
extern void func_00388830(void *,void *,float);
extern void func_L01_00470258(void *,void *,int,int,int,int,float);
extern void func_L01_00443648(void *,void *,int,int,int,int,float,float,float);
extern void func_003BF6A8(void *,float);
extern float func_00388960(float);
extern float func_00388978(float);
extern int func_003894A0(int,int,float);
extern void *func_L01_0045FEC8(void *,void *,void *,int,int,int,int,int,int);
extern void func_003BD360(void *);
extern float D_001DE2EC_sda;
extern int D_001DE2F4_sda,D_001DE2F8_sda;
extern float D_001DE2FC_sda,D_001DE300_sda,D_001DE304_sda,D_001DE308_sda,D_001DE30C_sda,D_001DE310_sda,D_001DE314_sda,D_001DE318_sda,D_001DE31C_sda,D_001DE320_sda;
extern int D_001DE324_sda,D_001DE328_sda,D_001DE32C_sda,D_001DE330_sda,D_001DE334_sda,D_001DE338_sda,D_001DE33C_sda,D_001DE340_sda;
extern float D_001DE344_sda;
void func_L08_003A7CE8(M87 *m) {
    V87 pos __attribute__((aligned(16))), vel __attribute__((aligned(16))), end __attribute__((aligned(16)));
    void *vars=m->vars;
    u8 *p;
    int i,j,c1,c2;
    float angle,speed,z;
    switch(m->state) {
    case 0:
        func_L08_003A8420(m);
        m->rot0=func_00389380(m->rot0,0.20989443361759186f);
        m->rot1=func_00389380(m->rot1,0.24725498259067535f);
        func_L08_003A8330(m);
        func_003886E8(&pos,vars,-0.75f);
        p=func_L01_00466F98(&m->pos,D_L08_001D66B0,6,47,0xff90,(int)func_0037E2A8(),157500.0f,-1000.0f,0.95f,0,0);
        if(p)p[2]=D_L08_0021ECBC[0][0];
        p=func_L01_00466F98(&m->pos,D_L08_001D66B0,6,47,0x10a182,(int)func_0037E2A8(),126000.0078125f,-1000.0f,0.95f,0,0);
        if(p)p[2]=D_L08_0021ECBC[0][0];
        if(!func_0037E1D8(3)) {
            __asm__("vmr32.xyzw $vf1, $vf0\n\tsqc2 $vf1, 0(%0)" : : "r"(&vel) : "vf1","memory");
            func_00388830(&vel,&vel,-func_0037E250(0.1f,0.2f));
            speed=func_0037E250(0.75f,0.8f)*210000.0f;
            func_L01_00470258(&m->pos,&vel,0x6412a182,0x12a178,(short)func_0037E208(120,240),0,speed);
        }
        break;
    case 1:
        if(*(float *)((char *)vars+32)>0.0f)
            func_L01_00443648(m,&m->pos,1,0,1,0,D_001DE2EC_sda,*(float *)((char *)vars+32),1.0f);
        for(i=0;i<D_001DE2F4_sda;i++) {
            *(Q87 *)&pos=*(Q87 *)&m->pos;
            func_003BF6A8(&pos,D_001DE2FC_sda);
            angle=func_0037E2A8();
            speed=func_0037E250(D_001DE308_sda,D_001DE30C_sda)*(1.0f/60.0f);
            z=func_0037E250(D_001DE310_sda,D_001DE314_sda);
            func_003886E8(&vel,D_L08_001D66B0,func_0037E250(0,D_001DE344_sda)*(1.0f/60.0f));
            vel.x+=func_00388960(angle)*speed;
            vel.y+=func_00388978(angle)*speed;
            vel.z+=z*(1.0f/60.0f);
            *(Q87 *)&end=*(Q87 *)&vel;
            end.z-=D_001DE318_sda*0.00027777778450399637f*(float)D_001DE338_sda;
            for(j=0;j<D_001DE2F8_sda;j++) {
                float r=func_0037E250(0.5f,1.5f);
                vel.w=r*D_001DE31C_sda;
                end.w=r*D_001DE320_sda;
                func_003BF6A8(&pos,D_001DE300_sda);
                func_003BF6A8(&end,D_001DE304_sda*(1.0f/60.0f));
                c1=func_003894A0(D_001DE324_sda,D_001DE32C_sda,func_0037E250(0,1));
                c2=func_003894A0(D_001DE328_sda,D_001DE330_sda,func_0037E250(0,1));
                p=func_L01_0045FEC8(&pos,&vel,&end,c1,c2,D_001DE334_sda,D_001DE338_sda,(int)func_0037E250((float)D_001DE33C_sda,(float)D_001DE340_sda),-1);
                if(p && func_0037E1D8(2))p[3]=72;
            }
        }
        func_003BD360(m);
        break;
    }
}
/* localdecomp:end func_L08_003A7CE8 */
