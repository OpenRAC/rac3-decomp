/* NTSC-U draft (2026-11-14, Codex worker): C of func_L39_00697028, the NTSC-U twin of func_L39_00699838, with NTSC-U names
 * and addresses. Byte-exact on NTSC-U with "-O2 -G8 -fopt-stack -mno-check-zero-division" when tried; not with src/levels/39_multiplayer_menu/L39_00699838.c's current line.
 * Worker's note: 544 diff; best log w52/func_L39_00697028.03.log; incomplete layout draft; retail inline float literals versus compiler lit4 under permitted flags; requires further layout work
 */
#include "common.h"
/* localdecomp:start func_L39_00697028 */
extern void func_L39_006857E0(void *);
extern void func_L39_006C9630(void *);
extern char D_L39_0047D098[];
extern char D_L39_00248290[];
extern char D_001DCA08_sda[8];
extern char *func_0037DF98(int);
extern void func_0019AFA0(void);
extern void func_L39_0068A638(void *, char *, float,float,float,float);
extern void func_L39_00686AC8(void *,void *);
extern void *func_00120D28(void *,void *,int);
typedef struct { int type; char base[0x44]; int x[7]; char pad[12]; } Widget;
void *func_L39_00697028(char *o) {
    func_L39_006857E0(o); *(void **)(o+0x60)=D_L39_0047D098;
    func_L39_006C9630(o+0x384); *(void **)(o+0x2A4)=o+0x62C;
    { char *choices[10] = {func_0037DF98(0xBB1),func_0037DF98(0xBB2),func_0037DF98(0xDA),func_0037DF98(0xBB4),func_0037DF98(0xD8),func_0037DF98(0xD4),func_0037DF98(0x18C4),func_0037DF98(0x18C5),func_0037DF98(0x18C6),func_0037DF98(0x18C7)};
    char *choices2[3]={func_0037DF98(0x1024),func_0037DF98(0x10E2),func_0037DF98(0x1026)};
    char text[0x120]; Widget a,b,c,d,e,f,g,h,i,j,k,l,m,n; void *items[14]; int z;
    func_0019AFA0();
    o[0x2E8]=1; *(int *)(o+0x2F4)=-1; *(int *)(o+0x2E0)=20; *(int *)(o+0x2E4)=3;
    *(int *)(o+0x2C4)=1; *(int *)(o+0x2A8)=0; *(int *)(o+0x2EC)=-1; *(int *)(o+0x2F0)=-1;
    *(int *)(o+0x2AC)=0; *(int *)(o+0x2B0)=0; *(int *)(o+0x2DC)=0; *(int *)(o+0x2B4)=0;
    *(int *)(o+0x2B8)=1; *(int *)(o+0x2BC)=1; *(int *)(o+0x2C0)=0; *(int *)(o+0x2C8)=0;
    *(int *)(o+0x2CC)=0; *(int *)(o+0x2D0)=0;
    for(z=7;z>=0;z--) o[0x2D4+z]=1;
    *(int *)text=0; func_L39_0068A638(text,func_0037DF98(0xFE6),0.108f,0.17267853f,0.37f,0.05f);
    *(int *)text=8; if(!D_L39_00248290) text[0x48]=0; else {func_00120D28(text+0x48,D_L39_00248290,199);text[0x10F]=0;}
    text[0x114]=0; *(int *)(text+0x110)=16;text[0x115]=1;text[0x116]=0;
    a.type=0; func_L39_0068A638(&a,func_0037DF98(0xFE9),0.108f,0.223035693169f,0.37f,0.05f);
    a.type=3;
    b.type=0; func_L39_0068A638(&b,func_0037DF98(0xFBB),0.108f,0.273392856121f,0.37f,0.05f);
    b.type=3;
    c.type=0; func_L39_0068A638(&c,func_0037DF98(0x1005),0.108f,0.323749989271f,0.37f,0.05f);
    c.type=6;
    d.type=0; func_L39_0068A638(&d,func_0037DF98(0x1176),0.108f,0.374107122421f,0.37f,0.05f);
    d.type=6;
    e.type=0; func_L39_0068A638(&e,func_0037DF98(0x1177),0.108f,0.424464285374f,0.37f,0.05f);
    e.type=6;
    f.type=0; func_L39_0068A638(&f,func_0037DF98(0xFE7),0.108f,0.474821418524f,0.37f,0.05f);
    f.type=6;
    g.type=0; func_L39_0068A638(&g,func_0037DF98(0x10E7),0.108f,0.525178551674f,0.37f,0.05f);
    g.type=6;
    h.type=0; func_L39_0068A638(&h,func_0037DF98(0x132A),0.108f,0.575535714626f,0.37f,0.05f);
    h.type=2;
    i.type=0; func_L39_0068A638(&i,D_L39_00248290,0.293f,0.625892877579f,0.37f,0.05f);
    i.type=1;
    j.type=0; func_L39_0068A638(&j,func_0037DF98(0x116D),0.293f,0.676249980927f,0.37f,0.05f);
    j.type=1;
    k.type=0; func_L39_0068A638(&k,func_0037DF98(0x10E3),0.293f,0.726607143879f,0.37f,0.05f);
    k.type=1;
    a.x[0]=10;a.x[1]=(int)choices;a.x[2]=0;b.x[0]=3;b.x[1]=(int)choices2;b.x[2]=0;
    c.x[0]=8;c.x[1]=2;c.x[2]=8;c.x[3]=1;c.x[4]=-1;c.x[5]=-1;c.x[6]=-1;
    d.x[0]=0;d.x[1]=0;d.x[2]=7;d.x[3]=1;d.x[4]=-1;d.x[5]=-1;d.x[6]=-1;
    e.x[0]=0;e.x[1]=0;e.x[2]=7;e.x[3]=1;e.x[4]=-1;e.x[5]=-1;e.x[6]=-1;
    f.x[0]=1;f.x[1]=1;f.x[2]=2;f.x[3]=1;f.x[4]=-1;f.x[5]=-1;f.x[6]=-1;
    g.x[0]=0;g.x[1]=0;g.x[2]=35;g.x[3]=5;g.x[4]=0x102C;g.x[5]=0x116B;g.x[6]=0x116B;
    l.type=0;func_L39_0068A638(&l,D_001DCA08_sda,0.708f,0.266f,0.385f,0.235f);l.type=4;l.x[2]=8;l.x[0]=0;
    m.type=0;func_L39_0068A638(&m,D_001DCA08_sda,0.708f,0.631f,0.385f,0.441f);m.type=4;m.x[2]=18;m.x[0]=0;
    n.type=0;func_L39_0068A638(&n,0,1,1,1,1);n.x[0]=46;*(float *)(n.base+0x3C)=1;*(float *)(n.base+0x38)=1;n.x[4]=0;n.x[5]=0;n.x[6]=14;
    items[0]=text;items[1]=&a;items[2]=&b;items[3]=&c;items[4]=&d;items[5]=&e;items[6]=&f;items[7]=&g;items[8]=&h;items[9]=&i;items[10]=&j;items[11]=&k;items[12]=&l;items[13]=&m;
    func_L39_00686AC8(o,&n);return o; }
}
/* localdecomp:end func_L39_00697028 */
