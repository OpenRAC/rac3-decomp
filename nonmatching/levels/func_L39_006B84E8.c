/* NTSC-U draft (Codex wave 3): C of func_L39_006B5AE0, the NTSC-U twin of func_L39_006B84E8, with NTSC-U names and addresses (the two versions' code differs).
 * near miss: 67 words differ on NTSC-U with the file's flags (NTSC-U twin "func_L39_006B5AE0", whose code is not the PAL one).
 * Worker's note: 67 diff retained; nine compiles; nested formatting, split-label, inverted and branch-local format variants 83-92 diff; format lifetime/allocation and call merging remain; best log first-01.log
 */
#include "common.h"
/* localdecomp:start func_L39_006B5AE0 */
typedef struct UI UI;
typedef struct { u8 p0[0x1c]; void (*mode)(UI *,int,int); u8 p20[0x30]; void (*color)(UI *,u32); u8 p54[0x10]; int (*enabled)(UI *); u8 p68[0x24]; int (*value)(UI *); } VT;
struct UI { u8 pad[0x60]; VT *vt; };
typedef struct { u8 pad[0x110]; UI *a,*b,*c,*d,*e,*f,*g,*h,*i; u8 p134[0x174]; int active; } Menu;
extern int D_001DDA10_sda,D_001DDA04_sda;
extern u8 D_L39_0037C948[],D_L39_001FC830[],D_L39_00249450[];
extern int D_001A4568[];
extern void func_L39_006B6010(Menu *,int);
extern int func_0011D2EC(void *,void *,int);
extern char *func_0037DF98(int);
extern int func_00120048(char *,void *,char *);
extern void func_L39_006872B0(Menu *,char *,u32,float,float),func_L39_00687210(Menu *,char *);
extern void func_L39_006B5488(int,int,int,int,int);
void func_L39_006B5AE0(Menu *m) {
 char text[32]; char *label; void *format; int different;
 D_001DDA10_sda=m->g->vt->value(m->g);
 func_L39_006B6010(m,1);
 if(func_0011D2EC(D_L39_0037C948+D_001DDA04_sda*496,D_L39_001FC830+D_001DDA04_sda*496,496))label=func_0037DF98(0x1256);
 else label=func_0037DF98(0x100);
 func_00120048(text,D_L39_00249450,label);
 m->active=1;
 label=func_0037DF98(0x1cab);
 if(D_001A4568[0]!=2)func_L39_006872B0(m,label,0x80404040,1.0f,1.0f);
 else func_L39_006872B0(m,label,0x706ec8ff,1.0f,1.0f);
 func_L39_00687210(m,func_0037DF98(0x100));
 m->a->vt->mode(m->a,3,0);
 if(m->c->vt->enabled(m->c))m->d->vt->mode(m->d,3,0);
 else m->d->vt->mode(m->d,2,0);
 func_L39_006B5488(1,0x123,0x1cc,0,0x1a0);
 m->i->vt->color(m->i,0x80cccccc);
}
/* localdecomp:end func_L39_006B5AE0 */
