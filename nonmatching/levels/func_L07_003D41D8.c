/* PAL near miss (Codex wave 7): near miss: 5 words differ with the file's flags.
 * Worker's note: 5 diff; build/codex/w377/func_L07_003D41D8.best.log; initial constants and byte/halfword store order; 7 ordinary checks, improved from 6 to 5; three reordered forms identical at a worse result, stopped; retained real draft in out/func_L07_003D41D8.near.c
 */
#include "common.h"
/* localdecomp:start func_L07_003D41D8 */
typedef int Quad_003D41D8 __attribute__((mode(TI)));
typedef struct Vec_003D41D8 { f32 x,y,z,w; } __attribute__((aligned(16))) Vec_003D41D8;
typedef struct Extra_003D41D8 { s32 kind; f32 strength, length; u8 mode; u8 pad[3]; Vec_003D41D8 direction; u8 pad20[16]; Vec_003D41D8 data; } Extra_003D41D8;
typedef struct Class_003D41D8 { u8 pad[0x24]; f32 scale; } Class_003D41D8;
typedef struct Moby_003D41D8 {
    u8 pad0[16]; Vec_003D41D8 position; u8 state; u8 pad21[3]; Class_003D41D8 *cls;
    u8 pad28[4]; f32 scale; u8 b30; s8 b31; s16 h32; u16 flags; u8 pad36[0x32]; Extra_003D41D8 *extra;
    u8 pad6C[0x4C]; void *parent; u8 padBC[4]; f32 matrix[12]; f32 rotation[3];
} Moby_003D41D8;
extern s32 D_001DE7B8_sda;
__asm__(".extern D_001DE7B8_sda, 4");
Moby_003D41D8 *func_L07_003D41D8(void *parent, Vec_003D41D8 *pos, Vec_003D41D8 *dir, u8 mode, f32 strength)
{
    extern Moby_003D41D8 *func_003C24B0(s32,s32);
    extern void func_L01_0044A7D0(Moby_003D41D8 *);
    extern f32 func_0038CEA8(void *);
    extern void func_L01_004450F0(Moby_003D41D8 *,s32,s32);
    extern f32 func_00382538(void);
    extern f32 func_0038D160(f32,f32);
    extern f32 func_0038CED8(void *);
    extern void func_0038D308(void *,void *);
    extern void func_0038CC88(void *,void *,s32);
    extern void func_003C7C38(Moby_003D41D8 *);
    Moby_003D41D8 *m=func_003C24B0(0x1c81,128);
    Extra_003D41D8 *e;
    if(m) {
        m->b31=1;
        m->b30=255;
        m->h32=255;
        m->parent=parent;
        m->state=0;
        e=m->extra;
        func_L01_0044A7D0(m);
        *(Quad_003D41D8 *)&m->position=*(Quad_003D41D8 *)pos;
        *(Quad_003D41D8 *)&e->direction=*(Quad_003D41D8 *)dir;
        e->length=func_0038CEA8(dir);
        e->strength=strength;
        e->mode=mode;
        func_L01_004450F0(m,1,-1);
        e->kind=83;
        m->flags |= 0x100;
        m->rotation[0]=func_00382538();
        m->rotation[2]=func_0038D160(dir->x,dir->y);
        m->rotation[1]=-func_0038D160(func_0038CED8(dir),dir->z);
        func_0038D308(m->matrix,m->rotation);
        m->scale=m->cls->scale*1.25f;
        func_0038CC88(&e->data,&D_001DE7B8_sda,16);
        func_003C7C38(m);
    }
    return m;
}
/* localdecomp:end func_L07_003D41D8 */
