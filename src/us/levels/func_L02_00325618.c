#include "common.h"

/* NTSC-U counterpart of func_L02_00325E90 (src/levels/shared/L02_00325BA0.c) */
typedef int u128_t __attribute__((mode(TI)));
typedef struct { u8 pad[0x24]; s32 i24; u8 pad28[0x6C - 0x28]; s32 i6C; u8 pad70[6]; s16 h76; u8 pad78[0x94 - 0x78]; s32 i94; s16 h98; u8 pad9A[4]; s16 h9E; } G_00325BA0;
#include "vu0.h"
extern u8 D_001A4BE0[];
extern s32 D_L02_001DE35C;
extern G_00325BA0 D_001CCFD0;
extern f32 func_00388978(f32);
extern f32 func_00389380(f32, f32);
extern void func_L01_004F12C0(void *, void *, s32, s32);
extern void func_0039FE80(s32, s32, void *);
extern void func_003BE4F0(void *, s32, s32, s32);
extern void func_L01_0050BB98(s32, s32, f32);
extern void func_0039C710(void);

/* localdecomp:start func_L02_00325618 */
#include "vu0.h"
#include "structs/moby.h"
extern s32 D_001D545C_sda_00325618;
extern u8 D_001BBB18[];
extern f32 D_L02_001DC930_00325618, D_L02_001DC934_00325618, D_L02_001DC938_00325618;
extern f32 D_L02_001DC93C_00325618, D_L02_001DC940_00325618, D_L02_001DC944_00325618, D_L02_001DC948_00325618;
extern s32 D_L02_001DE638, D_L02_001DE738;
extern u16 D_001A8EB0[];
extern s16 D_001A4F4E[];
__asm__(".extern D_L02_001DC930_00325618, 4");
__asm__(".extern D_L02_001DC934_00325618, 4");
__asm__(".extern D_L02_001DC938_00325618, 4");
__asm__(".extern D_L02_001DC93C_00325618, 4");
__asm__(".extern D_L02_001DC940_00325618, 4");
__asm__(".extern D_L02_001DC944_00325618, 4");
__asm__(".extern D_L02_001DC948_00325618, 4");
typedef struct Pvars_00325E90 {
 s32 index; u8 pad4[8]; s16 hC; u8 padE[2];
 f32 pos[4]; u8 pad20[0x40]; f32 f60,f64,f68; s32 timer;
 u8 pad70[8]; s32 i78;
} Pvars_00325E90;
void func_L02_00325618(u8 *p)
{
    extern void func_L02_00325328(u8 *);
    extern f32 func_0037E2A8(void);
    extern void func_L02_00325CA8(u8 *);
    extern void func_L02_00325D78(u8 *);
    extern void func_L02_003261F0(u8 *);
    extern f32 func_00388800(void *, void *);
    extern void func_L01_0044ECE0(s32,s32,s32);
    extern void func_0039CEA8(void);
    extern void func_L01_00417F60(s32,s32);
    extern void func_L02_00326348(void);
    extern void func_00399C90(s32,s32);
    extern void func_003BD360(void *);
    extern void func_L01_00441FB8(void *,s32,s32);
    extern void func_L02_00325FE8(void *);
    extern void func_L02_00325BB8(void *);
    extern s32 func_0037E1D8(s32);
    extern s32 func_00388398(void *);
    extern void func_L01_003E9730(s32,s32);
    struct Moby *m=(struct Moby *)p;
    Pvars_00325E90 *q = m->pvar;
    u8 *h,*tail,*hero_pos,*hero_base;
    s32 i;
    f32 distance;
    switch (((u8 *)m)[0x20]) {
    case 0:
        if (q->index == -1 || D_001BBB18[q->index + D_001D545C_sda_00325618*8]) {
            func_003BD360(p);
            break;
        }
        *(u128_t *)(q->pos) = *(u128_t *)(p+0x10);
        q->pos[3] = m->rotation.z;
        m->rotation.x = func_0037E2A8();
        m->rotation.y = func_0037E2A8();
        m->rotation.z = func_0037E2A8();
        m->rotation.w = func_0037E2A8();
        q->f68=D_L02_001DC93C_00325618*0.017453292f*0.01666666754f;
        q->f64=D_L02_001DC940_00325618*0.017453292f*0.01666666754f;
        q->f60=D_L02_001DC944_00325618*0.017453292f*0.01666666754f;
        if (m->draw_dist < 0x40) m->draw_dist = 0x40;
        ((u8 *)m)[0x20] = 1;
        func_L02_00325CA8(p);
        break;
    case 1:
        m->scale = *(f32 *)(*(u8 **)(p+0x24)+0x24)*D_L02_001DC930_00325618;
        m->position.z = q->pos[2] + D_L02_001DC934_00325618 + D_L02_001DC938_00325618 * func_00388978(m->rotation.w);
        m->rotation.x = func_00389380(m->rotation.x,D_L02_001DC93C_00325618*0.017453292f*0.01666666754f);
        m->rotation.y = func_00389380(m->rotation.y,D_L02_001DC940_00325618*0.017453292f*0.01666666754f);
        m->rotation.z = func_00389380(m->rotation.z,D_L02_001DC944_00325618*0.017453292f*0.01666666754f);
        m->rotation.w = func_00389380(m->rotation.w,D_L02_001DC948_00325618*0.017453292f*0.01666666754f);
        func_L02_00325D78(p);
        func_L02_003261F0(p);
        hero_pos = D_001A4BE0+0x80;
        distance=func_00388800(p+0x10,hero_pos);
        if (distance < 3.0f && (hero_base=hero_pos-0x80, fabs_asm(m->position.z-*(f32 *)(hero_base+0x88)) < 2.0f) && *(s32 *)(hero_base+0x2850) && (hero_base[0x25E4] == 3 || hero_base[0x25E4] == 0)) {
            if (q->hC == 0 && *(s32 *)(hero_base+0x25C4) != 0x31) goto blocked;
                D_L02_001DE638=0xB4;
                func_L01_0044ECE0(0xC93,-1,0);
                if (!D_001A8EB0[0]) {
                    if ((u32)((u16)D_001CCFD0.h76-6)>=2) D_001CCFD0.h76=5;
                    if ((u32)((u16)D_001CCFD0.h9E-6)>=2) D_001CCFD0.h9E=5;
                    func_0039CEA8();
                    func_L01_00417F60(0x1911,0x162);
                }
                D_001BBB18[q->index+D_001D545C_sda_00325618*8]=1;
                func_L02_00326348();
                func_00399C90(0,-1);
                func_0039FE80(1,0,p);
                func_003BD360(p);
            break;
blocked:
            if (q->i78) {
                m->mode_flags |= 0x41;
                func_L01_00441FB8(p,3,-1);
            } else func_L02_00325328(p);
        }
        break;
    case 3:
        if (!D_001A4F4E[0]) func_L02_00325328(p);
        break;
    case 2:
        if (D_001CCFD0.h76 == 0 && D_001CCFD0.h9E == 3 && D_001CCFD0.h98 < 0x1B58) func_0039C710();
        h=D_001A4BE0;
        D_L02_001DE738=1;
        *(s16 *)(h+0x1DC)=3;
        func_L02_00325FE8(p);
        *(u128_t *)(p+0x10)=*(u128_t *)(h+0x80);
        *(u128_t *)(p+0xF0)=*(u128_t *)(h+0x90);
        if (m->prev_seq==1) {
            func_L02_00325BB8(p);
            if (!func_0037E1D8(10)) func_L02_003261F0(p);
            if (m->anim_flags&2) {
                if (m->cur_seq) func_003BE4F0(p,0,0,0);
                p[0x31]=0;
                m->mode_flags|=1;
                for(i=3;i>=0;i--) func_L02_003261F0(p);
            }
        }
        tail=D_001A4BE0;
        if (*(s32 *)(tail+0xC08)&2) func_L01_0050BB98(0,0,30.0f);
        if (m->prev_seq==0 && func_00388398(&q->timer)) {
            D_L02_001DE638=0xB4;
            func_L01_0044ECE0(0xC93,-1,0);
            if (!D_001A8EB0[0]) func_L01_00417F60(0x1911,0x162);
            D_001BBB18[q->index+D_001D545C_sda_00325618*8]=1;
            func_L02_00326348();
            D_L02_001DE35C=0;
            func_L01_004F12C0(tail+0x80,tail+0x90,0,0);
            func_L01_003E9730(0,0);
            func_00399C90(0,-1);
            func_003BD360(p);
        }
        break;
    }
}
/* localdecomp:end func_L02_00325618 */
