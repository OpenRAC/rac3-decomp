/* PAL near miss (Codex wave 7): near miss: 204 words differ with the file's flags.
 * Worker's note: 207 diff; retained stack layout matches 0x580, remaining loop rotation/strength reduction, saved-register allocation and constant materialization. Three equivalent first-loop forms retain the wrong loop. Log build/codex/w371/8A90-retained.log; detailed ...
 */
#include "common.h"
/* localdecomp:start func_00388A90 */
typedef int Q_00388A90 __attribute__((mode(TI)));
typedef struct { u8 p[0x34]; u16 flags; u8 tail[0xCA]; } M_00388A90;
typedef struct { Q_00388A90 pos; f32 rot[4]; Q_00388A90 *verts; f32 sx,sy; s32 count; s32 overlay; u8 p34[0xC]; M_00388A90 *mobys[4]; } O_00388A90;
typedef struct { u8 p[0x50]; O_00388A90 *obj; } C_00388A90;
typedef struct { Q_00388A90 pos[4]; s32 color[4]; f32 uv[4][2]; unsigned long a,tex,c,d; } P_00388A90;
extern C_00388A90 D_225700;
extern u8 D_222420[];
extern f32 D_225900[];
extern Q_00388A90 D_2FF580[];
extern Q_00388A90 D_001D5970_00388A90[] __attribute__((section(".sdata")));
__asm__(".extern D_001D5970_00388A90, 4");
extern Q_00388A90 D_001D5980_00388A90[] __attribute__((section(".sdata")));
__asm__(".extern D_001D5980_00388A90, 4");
extern Q_00388A90 D_001D5990_00388A90[] __attribute__((section(".sdata")));
__asm__(".extern D_001D5990_00388A90, 4");
extern Q_00388A90 D_001D59A0_00388A90[] __attribute__((section(".sdata")));
__asm__(".extern D_001D59A0_00388A90, 4");
extern s32 D_1DA49C[];
extern unsigned long D_1D4C30[];
extern f32 D_001D5948_00388A90[] __attribute__((section(".sdata")));
extern f32 D_001D5958_00388A90[] __attribute__((section(".sdata")));
__asm__(".extern D_001D5948_00388A90, 4");
__asm__(".extern D_001D5958_00388A90, 4");
void func_00388A90(void) {
    extern void func_00381BA8(void);
    extern void func_00381BB0(void);
    extern void func_003C3A78(void);
    extern void func_003C39F0(void);
    extern void func_003C3A18(void);
    extern void func_003C3A48(void);
    extern void func_003C3BB8(void);
    extern void func_003C7348(void *,s32,s32,s32,s32);
    extern void func_003C3B38(void *,s32);
    extern void func_00388590(s32,s32,f32);
    extern void func_0012FF40(f32 *);
    extern void func_00130088(f32 *,f32 *,f32);
    extern void func_00130130(f32 *,f32 *,f32);
    extern void func_0012FFE0(f32 *,f32 *,f32);
    extern void func_00388618(void);
    extern void func_00388638(void *,void *,unsigned long);
    extern void func_003D3158(void *,s32,s32);
    extern void func_003A99D0(void);
    extern void func_003C3C18(void);
    extern void func_003865D0(void);
    extern s32 D_001D59C0_00388A90;
    M_00388A90 copies[4] __attribute__((aligned(16)));
    f32 saved[16] __attribute__((aligned(16)));
    f32 pos[4] __attribute__((aligned(16)));
    f32 mat[16] __attribute__((aligned(16)));
    P_00388A90 packet;
    O_00388A90 *o;
    M_00388A90 *m;
    M_00388A90 *dst;
    s32 i,n,j,k;
    f32 old;
    func_00381BA8();
    o=D_225700.obj;
    if(o) {
        func_003C3A78(); n=0;
        func_003C39F0();
        func_003C3A18();
        i=0;
        while(i<4) {
            m=o->mobys[i];
            if(!m)break;
            func_003C7348(m,0x404040,14,0,0);
            n++;
            m->flags |= 1;
            i++;
        }
        func_003C3B38((void *)D_1DA49C[0],-1);
        for(i=0;i<4;i++) { m=o->mobys[i]; if(!m)break; m->flags &= ~1; }
        func_0038D108(saved,D_222420,0x40);
        *(Q_00388A90 *)pos=*(Q_00388A90 *)(D_222420-0x20);
        old=D_225900[0xB0/4];
        func_00388590(8,8,1.0f);
        func_0012FF40(mat);
        func_00130088(mat,mat,o->rot[0]);
        func_00130130(mat,mat,o->rot[1]);
        func_0012FFE0(mat,mat,o->rot[2]);
        func_0038D108(D_222420,mat,0x40);
        *(Q_00388A90 *)(D_222420-0x20)=o->pos;
        func_003865D0();
        D_2FF580[0]=D_001D5970_00388A90[0];
        D_2FF580[3]=D_001D59A0_00388A90[0];
        D_2FF580[2]=D_001D5980_00388A90[0];
        D_2FF580[1]=D_001D5990_00388A90[0];
        if(n==1) func_003C3B38(o->mobys[0],1);
        else {
            dst=copies;
            for(i=3;i>=0;i--) {
                m=o->mobys[3-i];
                if(m) {func_0038D108(dst,m,0x100);dst++;}
            }
            func_003C3B38(copies,n);
        }
        func_00388618();
        D_225900[0xB0/4]=old;
        func_003877A0();
        func_0038D108(D_222420,saved,0x40);
        *(Q_00388A90 *)(D_222420-0x20)=*(Q_00388A90 *)pos;
        func_003865D0();
        func_003A97F8(0x42,0x8000000044ULL);
        func_003A97F8(8,5);
        func_003A99D0();
        func_003C3A48();
        func_003C3BB8();
        j=0;k=0;
        while(k<D_225700.obj->count) {
            packet.a=5;
            packet.d=0x8000000044ULL;
            packet.c=0xFF9000000260UL;
            packet.color[0]=D_001D59C0_00388A90;
            packet.color[3]=D_001D59C0_00388A90;
            packet.color[2]=D_001D59C0_00388A90;
            packet.color[1]=D_001D59C0_00388A90;
            packet.tex=D_1D4C30[0];
            for(i=0;i<4;i++) {
                packet.uv[i][0]=o->sx*D_001D5948_00388A90[i]+0.5f;
                packet.uv[i][1]=o->sy*D_001D5958_00388A90[i]+0.5f;
                packet.pos[i]=o->verts[j+i];
            }
            func_003D3158(&packet,0,0);
            if(o->overlay)func_00388638(o,o->verts+j,D_1D4C30[0]);
            k++;j+=4;
        }
    }else func_003C3C18();
    func_00381BB0();
}
/* localdecomp:end func_00388A90 */
